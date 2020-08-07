/*
Given a string S with repeated characters (only lowercase). The task is to rearrange characters in a string such that no two adjacent characters are same.

Note : It may be assumed that the string has only lowercase English alphabets.

Example 1:

Input:
S = geeksforgeeks
Output: 1
Explanation: All the repeated characters
of the given string can be rearranged so
that no adjacent characters in the
string is equal.
Example 2:

Input:
S = bbbabaaacd
Output: 1
Explanation: Repeated characters in the
string cannot be rearranged such that
there should not be any adjacent repeated
character.
Your Task:
You are required to complete the method rearrangeString() which takes 1 argument and returns the string without any same adjacent character.

Expected Time Complexity : O(nlogn)
Expected Auxilliary Space : O(n)

Constraints:
1 <= length of string <= 104

#################################################################################Solution###########################################################################################
*/

class solve{
    static boolean rearrangeCharacters(String str) {
		HashMap<Character,Integer> hm = new HashMap<>();
		for(char ch : str.toCharArray())
		    hm.put(ch,hm.getOrDefault(ch,0)+1);
		    
		Queue<Character> pq = new PriorityQueue<>((a,b)->(hm.get(b)-hm.get(a)));
		pq.addAll(hm.keySet());
		
		StringBuilder sb = new StringBuilder();
		while(pq.size()>1){
		    char ch1 = pq.poll();
		    char ch2 = pq.poll();
		    
		    sb.append(ch1);
		    sb.append(ch2);
		    
		    hm.put(ch1,hm.get(ch1)-1);
		    hm.put(ch2,hm.get(ch2)-1);
		    
		    if(hm.get(ch1)>0)
		        pq.add(ch1);
		       
		    if(hm.get(ch2)>0)
		        pq.add(ch2);
		    
		}
		
		if(!pq.isEmpty()){
		    char ch = pq.poll();
		    if(hm.get(ch)>1)
		        return false;
		    sb.append(ch);
		}
		
// 		System.out.println(sb.toString());
		return true;
	}
}
