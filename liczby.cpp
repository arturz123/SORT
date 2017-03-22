#include <fstream>
#include <iostream>

using namespace std;

int znajdzNaj( int poprzednia )
{
   ifstream liczby("liczby.txt");

   int liczba;
    int najwieksza = 0;
   while( !liczby.eof() )
   {
       liczby >> liczba;
       //cout << liczba << endl;
       if( liczba > najwieksza && liczba < poprzednia )
{
            najwieksza = liczba;
        //cout << najwieksza << endl;
}
   }
    cout << najwieksza << endl;

    return najwieksza;
}

void sortujMal()
{
    ofstream liczby_mal("liczby_mal.txt");

    int poprzednia = 9999;

    for(int i = 0; i < 28; ++i )
    {
       poprzednia = znajdzNaj(poprzednia);
       liczby_mal << poprzednia << endl;
    }
}

int main()
{
    sortujMal();
    return 0;
}
