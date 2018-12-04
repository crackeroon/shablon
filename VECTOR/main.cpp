#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <iostream>

using namespace std;

int check(int a, int b, int c)
{
    int aa = (a + b > c) && (b + c > a) && (c + a > b) && ((a==b) || (b==c) || (c==a));
    return aa;
}


void print(int a, int b, int c)
{
    if (check(a, b, c)) {

        printf("\n%d %d %d => yes", a, b, c);

    }
    else
        printf("\n%d %d %d => no", a, b, c);
}

int main()
{
    int t, a, b, c, n,k=0;
    int i, j = 1;
    std::vector<int> ivector = {1, 8, 10, 3, 4, 4, 7, 20, 21, 21, 54, 45, 15, -18, 0};
    if(ivector.empty())
        cout << "Vector is empty" << endl;
    else
        cout << "Vector has size " << ivector.size() << endl;

    for (i = 0; i < ivector.size(); ++i)
    {
        // тут свой ввод

        t = ivector[i];
        if (j == 1)
        {
            a = t;
        }
        else if (j == 2)
        {
            b = t;
        }
        else if (j == 3)
        {
            c = t;
        }
        j++;
        if (i >= 2)
        {
            print(a, b, c);

            j = j <= 3 ? j : 1;

         }


     }
       return 0;
}
