/*
Given an array A[] of integers, sort the array according to frequency of elements. That is elements that have higher frequency come first. If frequencies of two elements are same, then smaller number comes first.

Input:
The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows. The first line of each test case contains a single integer N denoting the size of array. The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.

Output:
For each testcase, in a new line, print each sorted array in a seperate line. For each array its numbers should be seperated by space.

Your Task:
This is a function problem. You only need to complete the function sortByFreq that takes arr, and n as parameters and prints the sorted elements. Endline is provided by the driver code.

Constraints:
1 ≤ T ≤ 300
1 ≤ N ≤ 105
1 ≤ Ai ≤ 105 

Example:
Input:
2
5
5 5 4 6 4
5
9 9 9 2 5
Output:
4 4 5 5 6
9 9 9 2 5

Explanation:
Testcase1: The highest frequency here is 2. Both 5 and 4 have that frequency. Now since the frequencies are same then smaller element comes first. So 4 4 comes first then comes 5 5. Finally comes 6.
The output is 4 4 5 5 6.
Testcase2: The highest frequency here is 3. The element 9 has the highest frequency. So 9 9 9 comes first. Now both 2 and 5 have same frequency. So we print smaller element first.
The output is 9 9 9 2 5.

#############################################################Solution###################################################################
*/

//Method 1
class Sorting
{
    static ArrayList<Integer> sortByFreq(int arr[], int n)
    {
        HashMap<Integer,Integer> hm = new HashMap<>();
        
        for(int i=0;i<n;i++){
            if(!hm.containsKey(arr[i]))
                hm.put(arr[i],1);
            else
                hm.put(arr[i],hm.get(arr[i])+1);
        }
         
        Iterator<Map.Entry<Integer,Integer>> itr = hm.entrySet().iterator();
        
        List<SortArrayByFreq> al = new ArrayList<>();
        
        while(itr.hasNext()){
            Map.Entry<Integer,Integer> entry = itr.next();
            al.add(new SortArrayByFreq(entry.getKey(),entry.getValue()));
        }
        
       Collections.sort(al); 
       
       ArrayList<Integer> solution = new ArrayList<>();
       for(int i=0;i<al.size();i++){
           int freq = al.get(i).getFrequency();
           for(int j=0;j<freq;j++)
            solution.add(al.get(i).getElement());
       }
       
       return solution;
    }
}

class SortArrayByFreq implements Comparable<SortArrayByFreq> {
    int element;
    int frequency;
    
    SortArrayByFreq(int element,int frequency){
        this.element = element;
        this.frequency = frequency;
    }
    
    @Override
    public int compareTo(SortArrayByFreq obj){
        if(this.frequency<obj.frequency)
            return 1;
        else if(this.frequency>obj.frequency)
            return -1;
        else{
            if(this.element>obj.element)
                return 1;
            else if(this.element<obj.element)
                return -1;
            return 0;
                
        }
    }
    
    public int getElement(){
        return this.element;
    }
    
    public int getFrequency(){
        return this.frequency;
    } 
}

//Method2
class Sorting
{
    static ArrayList<Integer> sortByFreq(int arr[], int n)
    {
        HashMap<Integer,Integer> hm = new HashMap<>();
        
        for(int i=0;i<n;i++){
            if(!hm.containsKey(arr[i]))
                hm.put(arr[i],1);
            else
                hm.put(arr[i],hm.get(arr[i])+1);
        }
         
        Iterator<Map.Entry<Integer,Integer>> itr = hm.entrySet().iterator();
        
        List<SortArrayByFreq> al = new ArrayList<>();
        
        while(itr.hasNext()){
            Map.Entry<Integer,Integer> entry = itr.next();
            al.add(new SortArrayByFreq(entry.getKey(),entry.getValue()));
        }
        
       Collections.sort(al, new SortByFreq()); 
       
       ArrayList<Integer> solution = new ArrayList<>();
       for(int i=0;i<al.size();i++){
           int freq = al.get(i).getFrequency();
           for(int j=0;j<freq;j++)
            solution.add(al.get(i).getElement());
       }
       
       return solution;
    }
}

class SortArrayByFreq {
    int element;
    int frequency;
    
    SortArrayByFreq(int element,int frequency){
        this.element = element;
        this.frequency = frequency;
    }
    
    public int getElement(){
        return this.element;
    }
    
    public int getFrequency(){
        return this.frequency;
    }
}

class SortByFreq implements Comparator<SortArrayByFreq>{
    public int compare(SortArrayByFreq obj1,SortArrayByFreq obj2){
        
        if(obj1.frequency == obj2.frequency){
            return obj1.element-obj2.element;
        }
        else{
            return obj2.frequency-obj1.frequency;
        }
    }
}
