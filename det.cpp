#include "det.h"

#ifdef view
#include <iostream>

using std::cout;
#endif
vector<vector<int>> shave(const vector<vector<int>>& arr,int ignore){
    const int N = arr.size();
    vector<vector<int>> nV(N, vector<int>(N-1));
    for(int k = 1; k<N; ++k){
        for (int i = 0, j=0; i<N; ++i){
            if(i != ignore){
                nV[k-1][j] = arr.at(k).at(i);
                ++j;
            }

        }
    }
    #ifdef view
    for(int k = 1; k<N; ++k){
        cout << "| ";
        for (int i = 0, j=0; i<N-1; ++i){
            cout << nV[k-1][i] << ' ';
        }
        cout << "|\n";
    }
    cout << "\n";
    #endif
    return nV;
}

int det(const vector<vector<int>>& arr, int N){
    int res{0};
    if (N == 2){
        return (arr[0][0] * arr[1][1]) - (arr[0][1] * arr[1][0]);
    }
    
    for(int i=0; i<N; ++i){

        #ifdef view
        cout << "\n" << (-1 + 2*(i%2)) * arr[0][i] * det(shave(arr, i), N-1) << "\n";
        #endif

        res += (-1 + 2*(i%2)) * arr[0][i] * det(shave(arr, i), N-1);
    }
    
    #ifdef view
    cout << "\n";
    #endif

    return res;
}

