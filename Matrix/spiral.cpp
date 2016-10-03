#include<iostream>
using namespace std;
#define R 3
#define C 6
void spiralPrint(int a[R][C]){
    int dir = 0;
    int left = 0;
    int right = C-1;
    int top = 0;
    int bottom = R-1;
    while(left <= right && top <= bottom)
    {
        if(dir == 0)
        {
            for(int i = left;i<=right;i++) {
                cout<<a[top][i]<<"      ";
            }
            top++;
            dir = 1;
        } else if(dir == 1){
            for(int i = top;i<=bottom;i++) {
                cout<<a[i][right]<<"      ";
            }
            right--;
            dir = 2;
        } else if(dir == 2){
            for(int i = right;i>=left;i--) {
                cout<<a[bottom][i]<<"      ";
            }
            bottom--;
            dir = 3;
        } else if(dir == 3){
            for(int i = bottom;i>=top;i--) {
                cout<<a[i][left]<<"      ";
            }
            left++;
            dir = 0;
        }
    }
}
int main()
{
    int a[R][C] = { {1,  2,  3,  4,  5,  6},
        {7,  8,  9,  10, 11, 12},
        {13, 14, 15, 16, 17, 18}
    };

    spiralPrint(a);
    return 0;
}
