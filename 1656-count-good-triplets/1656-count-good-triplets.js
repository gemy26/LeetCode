/**
 * @param {number[]} arr
 * @param {number} a
 * @param {number} b
 * @param {number} c
 * @return {number}
 */
var countGoodTriplets = function(arr, a, b, c) {
    let ans = 0, n = arr.length;
    for(let i = 0; i < n; i ++){
        for(let j = i + 1; j < n; j ++){
            for(let k = j + 1; k < n; k ++){
                if(
                    Math.abs(arr[i] - arr[j]) <= a &&
                    Math.abs(arr[i] - arr[k]) <= c &&
                    Math.abs(arr[j] - arr[k]) <= b
                ){
                    ans ++;
                }
            }
        }
    }
    return ans;
};