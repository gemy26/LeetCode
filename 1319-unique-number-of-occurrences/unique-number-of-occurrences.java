class Solution {
    public boolean uniqueOccurrences(int[] arr) {
        Map<Integer,Integer>mp = new HashMap<Integer,Integer>();
        
        for(int i : arr){
            mp.putIfAbsent(i, 0);
            mp.put(i,mp.get(i)+1);
        }
        Set<Integer> s = new HashSet<Integer>();
        for(int i : mp.values()){
            
                if(s.contains(i))
                   return false;
                
                else
                  s.add(i);
            
        }
        return true;
        
    }
}