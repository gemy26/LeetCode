class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights,
                                        vector<vector<int>>& queries) {
        vector<int> res;
        res.reserve(queries.size());
        SegmentTree seg(heights, [](int a, int b) { return max(a, b); });

        for (auto q : queries) {
            res.push_back(seg.get(q[0] + 1, q[1] + 1));
        }

        return res;
    }

    template <class T, class F> class SegmentTree {
    private:
        struct node {
            int mx;
            node *left, *right;
        }* root;

        vector<T> nums;
        F f;
        int size;

        void build(node* seg, int l, int r) {

            if (l == r) {
                seg->mx = nums[l - 1];
                return;
            }

            int md = (l + r) >> 1;
            seg->left = new node;
            seg->right = new node;

            build(seg->left, l, md);
            build(seg->right, md + 1, r);

            seg->mx = f(seg->left->mx, seg->right->mx);
        }

        int get(node* seg, int l, int r, int _l, int _r, int val) {

            if ((_l > r) || (_r < l)) {
                return 1e9;
            }

            //            cerr << l << ' ' << r << ' ' << _l << ' ' << _r << ' '
            //            << seg->mx << ' ' << val << '\n';
            if (l == r) {
                if (seg->mx > val)
                    return l - 1;
                else
                    return 1e9;
            }

            if ((l >= _l) && (r <= _r)) {

                int md = (l + r) >> 1;
                int mn_idx = 1e9;
                if (seg->left->mx > val) {
                    mn_idx = min(mn_idx, get(seg->left, l, md, _l, _r, val));
                } else if (seg->right->mx > val) {
                    mn_idx =
                        min(mn_idx, get(seg->right, md + 1, r, _l, _r, val));
                }

                return mn_idx;
            }

            int md = (l + r) >> 1;
            int mn_idx = 1e9;
            mn_idx = min(mn_idx, get(seg->left, l, md, _l, _r, val));
            mn_idx = min(mn_idx, get(seg->right, md + 1, r, _l, _r, val));

            return mn_idx;
        }

    public:
        explicit SegmentTree(const vector<T>& nums, const F& f)
            : f(f), nums(nums), size(nums.size()), root(new node) {
            build(root, 1, size);
        }
        int get(int l, int r) {
            if (l > r)
                swap(l, r);

            if (l == r)
                return l - 1;

            if (nums[r - 1] > nums[l - 1])
                return r - 1;

            int val = nums[l - 1];
            int res = get(root, 1, size, r + 1, size, val);

            return (res == 1e9) ? -1 : res;
        }
    };
};
