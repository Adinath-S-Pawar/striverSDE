#include<bits/stdc++.h>
using namespace std;

/*
You have been given two integers ‘N’ and ‘K’. Your task is to find the K-th permutation sequence of numbers from 1 to ‘N’.
 The K-th permutation is the K-th permutation in the set of all sorted permutations of string 1 to ‘N’.
For example :
If ‘N’ = 3 and ‘K’ = 4. Then all permutations for ‘N’ = 3 are “123”, “132”, “213”, “231”, “312”, “321”. So the 4-th 
permutation is “231”.
*/

/*
In a vector, erasing an element requires shifting all elements after it one position left.
First erase: O(n)
Second erase: O(n-1)
Third erase: O(n-2)
Time Complexity: O(N2), We are placing N numbers in N positions, and for every number, we reduce the search space by removing an element already placed in the previous step, which takes another O(N) time.

Space Complexity: O(N), We are storing the numbers in a data structure (here, vector).


*/
string kthPermutation(int n, int k) {
    int fact = 1;
    vector<int> numbers; //1 to n

    //fill 1 to n in nos and find n-1 fact
    for(int i = 1; i<n; i++)
    {
        fact = fact * i;
        numbers.push_back(i);
    }
    numbers.push_back(n);   //nth 

    string ans = "";
    k = k-1; // for 0 based indexing

    while(true)
    {   //add num at index to ans
        int index = k/fact;
        ans += to_string(numbers[index]);

        //remove added num from arr
        numbers.erase(numbers.begin()+ k/fact);

        if (numbers.size() == 0) {
                break;  // Exit when all numbers are used
            }
        
        //new k 
        k = k%fact;
        //new fact
        fact = fact/numbers.size();

    }
    return ans;
}

int main()
{
    return 0;
}