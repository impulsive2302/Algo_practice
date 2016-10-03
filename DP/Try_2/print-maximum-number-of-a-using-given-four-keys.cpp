/* A Dynamic Programming based C program to find maximum number of A's
   that can be printed using four keys */
#include<stdio.h>
#include<iostream>
using namespace std;
// this function returns the optimal length string for N keystrokes
int findoptimal(int N)
{
    // The optimal string length is N when N is smaller than 7
    if (N <= 6)
        return N;

    // An array to store result of subproblems
    int screen[N+1];

    int b;  // To pick a breakpoint

    // Initializing the optimal lengths array for uptil 6 input
    // strokes.
    int n;
    for (n=1; n<=6; n++)
        screen[n] = n;

    // Solve all subproblems in bottom manner
    for (n=7; n<=N; n++)
    {
        // Initialize length of optimal string for n keystrokes
        screen[n] = 0;

        // For any keystroke n, we need to loop from n-3 keystrokes
        // back to 1 keystroke to find a breakpoint 'b' after which we
        // will have ctrl-a, ctrl-c and then only ctrl-v all the way.
        for (b=n-3; b>=1; b--)
        {
            //cout<<"processing for b = "<<b<<endl;
            // if the breakpoint is at b'th keystroke then
            // the optimal string would have length
            // (n-b-1)*screen[b-1];
            int curr = (n-b-1)*screen[b];
            //cout<<"n-b-1  "<<n-b-1<<endl;
            //cout<<"screen[b-1]        "<<screen[b-1]<<endl;
            //cout<<"current "<<curr<<endl;
            if (curr > screen[n])
                screen[n] = curr;
        }
    }

    return screen[N];
}

// Driver program
int main()
{
    int N;

    // for the rest of the array we will rely on the previous
    // entries to compute new ones
    for (N=1; N<=20; N++)
        printf("Maximum Number of A's with %d keystrokes is %d\n",
               N, findoptimal(N));
}