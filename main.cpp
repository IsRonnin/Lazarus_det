#include "det.h"
#include <iostream>


using std::cin;
using std::cout;
using std::endl;

int main(){
    setlocale(LC_ALL, ".UTF8");
    int n{0};
    int det_m{0};
    cout << "Введите размер вектора: ";
    cin >> n;

    if (n <= 0){
        cout << "Очертенели?";
        system("pause");
        return 0;
    }

    vector<vector<int>> iV(n, vector<int>(n));

    for(int k = 0; k<n; ++k)
        for(int i = 0; i<n; ++i)
            cin >> iV.at(k).at(i);
    
    det_m = det(iV, n);

    cout << det_m << endl;


    system("pause");


    return 0;
}