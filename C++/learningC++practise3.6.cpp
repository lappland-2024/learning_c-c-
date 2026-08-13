#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;
using std::vector;
using std::string;

int main()
{
    int ia[3][4] = {0,1,2,3,4,5,6,7,8,9,10,11};
    //使用范围for
    for(const int(&row)[4] : ia)
        for(const int &col : row)
            cout << col << " "; 
    //使用普通for下标
    for(int row = 0; row != 3; ++row)
        for(int col = 0; col != 4; ++col)
            cout << ia[row][col] << " ";
    //使用普通for指针
    for(int (*row)[4] = ia; row != ia + 3; ++row)
        for(int *col = *row; col != *row + 4; ++col)
            cout << *col << " ";
        cout << endl;
    //3.44使用类型别名
    using int_array = int[4];
    for(int_array *row = ia; row != ia + 3; ++row)
        for(int *col = *row; col != *row + 4; ++col)
            cout << *col << " ";
    //3.45使用auto
    for(auto row = ia; row != ia + 3; ++row)
        for(auto col = *row; col != *row + 4; ++col)
            cout << *col << " ";
    return 0;
}
