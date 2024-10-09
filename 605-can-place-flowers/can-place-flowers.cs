public class Solution {
    public bool CanPlaceFlowers(int[] flowerbed, int n) {
        int count = 0;
        int size = flowerbed.Length;
        if(size == 1) {
            count  = flowerbed[0] == 0 ? 1 : 0;
        }
        for(int i = 0; i < size; i++){
            if(i == 0 && i + 1 < size && flowerbed[i] == 0 &&  flowerbed[i + 1] == 0){
                flowerbed[i] = 1;
                count ++;
            }
            else if(i == size - 1 && i - 1 >= 0 && flowerbed[i - 1] == 0 && flowerbed[i] == 0){
                count ++;
                flowerbed[i] = 1;
            }
            else if(i > 0 && i < size   && flowerbed[i - 1] == 0 && flowerbed[i] == 0 && flowerbed[i + 1] == 0){
                count ++;
                flowerbed[i] = 1;
            }
        }
        return count >= n;
    }
}