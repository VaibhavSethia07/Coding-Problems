/*
Farmer John, in his old age, has unfortunately become increasingly grumpy and paranoid. Forgetting the extent to which bovine diversity helped his farm truly flourish over the years, he has recently decided to build a huge fence around the farm, discouraging cows from neighboring farms from visiting, and completely prohibiting entry from a handful of neighboring farms. The cows are quite upset by this state of affairs, not only since they can no longer visit with their friends, but since it has caused them to cancel participation in the International Milking Olympiad, an event to which they look forward all year.
Neighboring cows that still have the ability to enter Farmer John's property find the process has become more arduous, as they can enter only through a single gate where each cow is subject to intense questioning, often causing the cows to queue up in a long line.

For each of the N cows visiting the farm, you are told the time she arrives at the gate and the duration of time required for her to answer her entry questions. Only one cow can be undergoing questioning at any given time, so if many cows arrive near the same time, they will likely need to wait in line to be processed one by one. For example, if a cow arrives at time 5 and answers questions for 7 units of time, another cow arriving at time 8 would need to wait until time 12 to start answering questions herself.

Please determine the earliest possible time by which all cows are able to enter the farm.

INPUT FORMAT (file cowqueue.in):
The first line of input contains N, a positive integer at most 100. Each of the next N lines describes one cow, giving the time it arrives and the time it requires for questioning; each of these numbers are positive integers at most 1,000,000.
OUTPUT FORMAT (file cowqueue.out):
Please determine the minimum possible time at which all the cows could have completed processing.
SAMPLE INPUT:
3
2 1
8 3
5 7
SAMPLE OUTPUT:
15
Here, first cow arrives at time 2 and is quickly processed. The gate remains briefly idle until the third cow arrives at time 5, and begins processing. The second cow then arrives at time 8 and waits until time 5+7=12 to start answering questions, finishing at time 12+3 = 15.

Problem credits: Brian Dean

####################################################################################Solution#######################################################################################
*/

/*
ID: VaibhavSethia07 
LANG: C++11 
PROB: Why Did the Cow Cross the Road 3 
*/
#include <bits/stdc++.h>

using namespace std;

int main(){
freopen("cowqueue.in","r",stdin); 
freopen("cowqueue.out","w",stdout);

    int N;
    cin>>N;
    int delay=0;
    map<int,int> cows;
    
    for(int a=0;a<N;a++){
        int arrival;
        int question_time;
        cin>>arrival>>question_time;
        if(cows.count(arrival)==1)
            cows[arrival] = cows[arrival]+question_time;
        else
            cows[arrival] = question_time;
    }
    
    for(auto cow:cows){
        if(delay<=cow.first)
            delay = cow.first+cow.second;
        else
            delay+=cow.second;
    }
    cout<<delay<<"\n";
}
