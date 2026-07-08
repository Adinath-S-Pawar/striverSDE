#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>

/*
Problem Statement: There is one meeting room in a firm. You are given two arrays, start and end each of size N. 
For an index ‘i’, start[i] denotes the starting time of the ith meeting while end[i] will denote the ending time 
of the ith meeting. Find the maximum number of meetings that can be accommodated if only one meeting can happen 
in the room at a particular time. Print the order in which these meetings will be performed.*/

//TC - O(n) + O(n log n) + O(n)
//SC - O(n)
int maximumMeetings(vector<int> &start, vector<int> &end)
{
    //create vector pair of meetings
    vector<pair<int,int>> meetings;
    //first->endtime second->start time
    int n = start.size();

    for(int i = 0; i < n; i++)
    {
        meetings.push_back({end[i],start[i]});
    }

    //sort by end time
    sort(meetings.begin(), meetings.end());

    //initialise count and lastEnd
    int count = 1;  //1st meeting
    int lastEnd = meetings[0].first;

    //find count   
    for(int i = 1; i < n; i++)
    {
        //add meeting if its start time is more than  lastend meet
        if(meetings[i].second > lastEnd)
        {
            count++;
            //update lastend to new meetings end time
            lastEnd = meetings[i].first;
        }
    }

    return count;
}

int main()
{
    return 0;
}