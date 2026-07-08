#include<algorithm>
using namespace std;
/*
You have been given two arrays, 'AT' and 'DT', representing the arrival and departure times of all trains that reach a railway station.
Your task is to find the minimum number of platforms required for the railway station so that no train needs to wait.

Note :
1. Every train will depart on the same day and the departure time will always be greater than the arrival time. 
For example, A train with arrival time 2240 and departure time 1930 is not possible.
2. Time will be given in 24H format and colons will be omitted for convenience. For example, 9:05AM will be given as 
"905", or 9:10PM will be given as "2110".
3. Also, there will be no leading zeroes in the given times. For example, 12:10AM will be given as “10” and not as “0010”.
*/

/*
Time Complexity: O(N*logN), we sort both the arrival and departure arrays.
Space Complexity: O(1), constant additional space is used.
*/

int calculateMinPatforms(int at[], int dt[], int n) {
    
    //sort arrival and departure time
    sort(at, at + n);
    sort(dt, dt + n);

    int platforms = 1;
    int res = 1;
    int i = 1;  //for at, 1st train included
    int j = 0;  // for dt
    
    while(i < n && j < n)
    {
        //platform needed if train arrive before other departs
        if(at[i] <= dt[j])
        {
            platforms++;
            i++;
        }
        else
        {
            platforms--;
            j++;
        }

        res = max(res,platforms);
    }
    
    return res;
}