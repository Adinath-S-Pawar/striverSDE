#include <bits/stdc++.h> 
#include<string>
using namespace std;
/*
You are given two versions numbers A and B as a string. Your task is to compare them and find out which one of 
them is a newer version.
Note:
There are no leading zeros in any of the strings except in the case of zero itself. Note that, the leading zeroes 
are not allowed even after a '.' ie: 121.005 is an invalid version, while 121.5 is an valid version.
*/

/*
Time: O(n + m)
Space: O(1)
*/
int compareVersions(string a, string b) 
{
    int i = 0, j = 0;
    int n = a.size(), m = b.size();

    while(i < n || j < m)
    {
        long long num1 = 0, num2 = 0;

        while(i < n && a[i] != '.')
        {
            num1 = num1 * 10 + (a[i] - '0');
            i++;
        }

        while(j < m && b[j] != '.')
        {
            num2 = num2 * 10 + (b[j] - '0');
            j++;
        }

        if (num1 > num2) return 1;
        if (num1 < num2) return -1;

        i++; // skip '.'
        j++; // skip '.'
    }
    return 0;
}