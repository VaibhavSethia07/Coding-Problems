/*
Given weights and values of N items, we need to put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
Note: Unlike 0/1 knapsack, you are allowed to bread the item.

Example 1:

Input:
N = 3, W = 50
values[] = {60,10,100,20,120,30}
Output: 240.00
Explanation: Total maximum value of item
we can have is 240.00 from the given
capacity of sack.
Example 2:

Input:
N = 2, W = 50
values[] = {60,10,100,20}
Output: 160.00
Explanation: Total maximum value of item
we can have is 160.00 from the given
capacity of sack.
Your Task :
Complete the function fractionalKnapsack() that receives maximum capacity , array ar and size n and returns te maximum value in knapsack.

Constraints:
1 <= N <= 100
1 <= W <= 100

Expected Time Complexity : O(NlogN)
Expected Auxilliary Space: O(1)

#############################################################################Solution###############################################################################################
*/

// Method 1
class solve{
    double fractionalKnapsack(int W, Item arr[], int n) {
        Comparator<Item> myComp = new Comparator<>(){
            public int compare(Item i1,Item i2){
                return i2.value*i1.weight-i1.value*i2.weight;
            }
        };
        
        Arrays.sort(arr,myComp);
        double res = 0.0;
        
        for(int i=0;i<n;i++){
            if(arr[i].weight<=W){
                res+=arr[i].value;
                W-=arr[i].weight;
            }else{
                res+=(W/(arr[i].weight*1.0))*arr[i].value;
                break;
            }
        }
        
        return res;
    }
}

// Method 2
class solve{
    double fractionalKnapsack(int W, Item arr[], int n) {
        Comparator<Item> myComp = (i1,i2)->(i2.value*i1.weight-i1.value*i2.weight);
        
        Arrays.sort(arr,myComp);
        double res = 0.0;
        
        for(int i=0;i<n;i++){
            if(arr[i].weight<=W){
                res+=arr[i].value;
                W-=arr[i].weight;
            }else{
                res+=(W/(arr[i].weight*1.0))*arr[i].value;
                break;
            }
        }
        
        return res; 
    }
}

// Method 3
class solve{
    double fractionalKnapsack(int W, Item arr[], int n) {
        
        Arrays.sort(arr,(i1,i2)->(i2.value*i1.weight-i1.value*i2.weight));
        double res = 0.0;
        
        for(int i=0;i<n;i++){
            if(arr[i].weight<=W){
                res+=arr[i].value;
                W-=arr[i].weight;
            }else{
                res+=(W/(arr[i].weight*1.0))*arr[i].value;
                break;
            }
        }
        return res;
    }
}
