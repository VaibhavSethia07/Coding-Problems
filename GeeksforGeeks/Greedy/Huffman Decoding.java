/*
Given a binary encoded string and a Huffman MinHeap tree, your task is to complete the function decodeHuffmanData(), which decodes the binary encoded string and return the original string. 


Example:

Input Data : AAAAAABCCCCCCDDEEEEE
Frequencies : A: 6, B: 1, C: 6, D: 2, E: 5
Encoded Data : 
0000000000001100101010101011111111010101010
Huffman Tree: '$' is the special character used for 
               internal nodes as character field is 
               not needed for internal nodes. 
               #(20)
             /       \
        #(12)         #(8)
     /      \        /     \
    A(6)     C(6) E(5)     #(3)
                         /     \
                       B(1)    D(2)  
Code of 'A' is '00', code of 'C' is '01', ..
Decoded Data : AAAAAABCCCCCCDDEEEEE
Input:
The function takes two arguments as input, the reference pointer to the root of the Huffman minheap tree and an binary encoded string.
There will be T test cases and for each test case the function will be called separately.

Note: Input test cases contains English alphabetical string of size N, that will be encoded using Huffman Encoding and the encoded string will be provided to you.

Output:
For each test case print the decoded string from the provided encoded string.

Your Task : Complete the function decodeHuffmanData() that returns the encoded string.

Constraints:
1<=T<=200
1<=N<=103

Expected Time Complexity : O(NlogN)

Example:
Input:
2
01110100011111000101101011101000111
1011010011100101101110111
Output:
geeksforgeeks
India

###############################################################################Solution##########################################################################################
*/

class Decode
{
    static String decodeHuffmanData(MinHeapNode root, String binaryString)
    {
        MinHeapNode curr = root;
        StringBuffer sb = new StringBuffer();
        for(int i=0;i<binaryString.length();i++){
            if(curr.data=='$'){
                if(binaryString.charAt(i)=='0')
                    curr = curr.left;
                else
                    curr = curr.right;
            }
            if(curr.data!='$'){
                sb.append(curr.data);
                curr = root;
            }
        }
        
        return sb.toString();
    }
}
