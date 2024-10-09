public class Solution {
    public IList<bool> KidsWithCandies(int[] candies, int extraCandies) {
        int maxValue  = 0;
        int size = candies.Length;
        List <bool> result = new List<bool>(new bool[size]);
        for(int i = 0; i < size; i++){
            maxValue = Math.Max(maxValue, candies[i]);
        }
        for(int i = 0; i < size; i++){
            if(candies[i] + extraCandies >= maxValue){
                result[i] = true;
            }
            else{
                result[i] = false;
            }
        }
        return result;
    }
}