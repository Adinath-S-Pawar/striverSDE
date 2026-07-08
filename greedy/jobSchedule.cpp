#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>

/*
You are given a 'Nx3' 2-D array 'Jobs' describing 'N' jobs where 'Jobs[i][0]' denotes the id of 'i-th' job, 
'Jobs[i][1]' denotes the deadline of 'i-th' job, and 'Jobs[i][2]' denotes the profit associated with 'i-th job'.

You will make a particular profit if you complete the job within the deadline associated with it. 
Each job takes 1 unit of time to be completed, and you can schedule only one job at a particular time.

Return the number of jobs to be done to get maximum profit.
Note :
If a particular job has a deadline 'x', it means that it needs to be completed at any time before 'x'.
Assume that the start time is 0.
*/
bool comparator(const vector<int>&a,const vector<int>&b)
{
    return(a[2] > b[2]);
}

/*
TC - O(N log N + N × D)
N = number of jobs
D = maximum deadline
Sort jobs by profit: O(N log N)
For each job, search for a free slot before its deadline: O(N × D)
SC - O(D) for slot
*/
vector<int> jobScheduling(vector<vector<int>> &jobs)
{
    int n = jobs.size();

    //max to min profit
    sort(jobs.begin(), jobs.end(), comparator);

    int maxDeadline = 0;
    for(auto &currjob : jobs)
    {
        if(currjob[1] > maxDeadline)
        {
            maxDeadline = currjob[1];
        }
    }

    //size n+1 because we will use slot number as index
    vector<int>slot(maxDeadline + 1 ,-1);
    int jobcount = 0;
    int maxprofit = 0;

    for(int i = 0; i < n; i++)  // for each job sorted by profit
    {
        int id = jobs[i][0];
        int deadline = jobs[i][1];
        int profit = jobs[i][2];

        //find free slot
        for(int j = deadline; j>=1; j--)
        {
            if(slot[j] == -1)
            {
                slot[j] = id;
                jobcount++;
                maxprofit += profit;
                break;
            }
        }
    }
    return{jobcount,maxprofit};
}
int main()
{
    return 0;
}