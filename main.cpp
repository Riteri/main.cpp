#include <iostream>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n,m;
    int liczbaLewa;
    int liczbaSrednia;
    int liczbaPrawa;
    int index = 0;


    cin>>n>>m;


    int **arr = new int *[2];

    for(int i=0; i<2; i++)
    {
        arr[i] = new int [m];
    }


    for (int j = 0; j < m; j++)
    {
        cin >> arr[0][j];
    }


    for (int i = 0; i <n-1; i++)
    {
        for (int j = 0; j<m;j++)
        {

            cin>>arr[1][j];

            if(m >1)
            {
                liczbaLewa = arr[0][j-1];
                liczbaSrednia = arr[0][j];
                liczbaPrawa = arr[0][j+1];

                if (j == 0)
                {
                    if(liczbaSrednia > liczbaPrawa)
                    {
                        arr[1][j] += liczbaSrednia;
                    }
                    else arr[1][j] += liczbaPrawa;
                }
                else if(j == m - 1)
                {
                    if(liczbaSrednia > liczbaLewa)
                    {
                        arr[1][j] += liczbaSrednia;
                    }
                    else arr[1][j] += liczbaLewa;
                }
                else
                {
                    int temp = 0;
                    for(int k = j - 1 ; k < j + 2; k++)
                    {
                        if (temp < arr[0][k])
                        {
                            temp = arr[0][k];
                        }
                    }
                    arr[1][j] += temp;
                }
            }


            if (m == 1)
            {
                arr[1][0] += arr[0][0];

            }



        }
        for (int zamiana=0; zamiana<m; zamiana++)
        {
            arr[0][zamiana] = arr[1][zamiana];

        }


    }



    int maxel = arr[0][0];

    for ( int ind = 0; ind<m; ++ind)
    {

        if(arr[0][ind] > maxel)
        {

            maxel = arr[0][ind];
            index = ind;

        }

    }


    cout<<index<<" "<<maxel;


    for (int del = 0; del<2; del++)
    {
        delete[]arr[del];


    }

    return 0;
}