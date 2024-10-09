public class Solution {
    public IList<bool> KidsWithCandies(int[] candies, int extraCandies) {
        int maxValue  = 0;
        int size = candies.Length;
        List <bool> result = new List<bool>();
        for(int i = 0; i < size; i++){
            maxValue = Math.Max(maxValue, candies[i]);
        }
        for(int i = 0; i < size; i++){
            if(candies[i] + extraCandies >= maxValue){
                result.Add(true);
            }
            else{
                result.Add(false);
            }
        }
        return result;
    }
}