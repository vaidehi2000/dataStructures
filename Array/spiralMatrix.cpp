#include<iostream>
#include<conio.h>

using namespace std;

void spiralmat(int a[3][3], int m, int n){
    int  l = 0, k = 0;
    while (l < m && k < n){
        for (int i = k; i < n; i++)
            cout << a[l][i];
        l++;
        for(int i = l; i < m; i++)
            cout << a[i][n-1];
        n--;
        if (l < m){
            for(int i = n-1; i >= k; i--)
                cout << a[m-1][i];
            m--;
        }
        if (k < n){
            for (int i = m-1; i >= l; i--)
                cout << a[i][k];
            k++;
        }
    }
}

int main(){
    int a[3][3] = {{1, 2, 3},
                   {4, 5, 6},
                   {7, 8, 9}};
    spiralmat(a, 3, 3);
    return 0;
}
