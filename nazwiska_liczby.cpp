#include <stdio.h>
#include <string.h>
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
  FILE *plik;
  char strtmp[ 501 ];
  char nazwisko[ 501 ];
  int res;
  int index;
  char Nazwiska[100][501];
  int i,j;

  plik = fopen("nazwiska.txt", "rt");
  if(plik==NULL)
  {
    printf("B³¹d odczytu pliku\n");
    return 0;
  }
  index=0;
  while((!feof(plik))&&(index<100))
  {
   
    res=fscanf(plik,"%s",nazwisko);
    if(res!=1)
    {
      printf("B³¹d odczytu");
      break;
    }
    strcpy(Nazwiska[index],nazwisko);
    index++;
  }
  fclose( plik);
  for(i=0;i<index;i++)
  {
    for(j=0;j<index-i-1;j++)
    {
      if(strcmp(Nazwiska[j],Nazwiska[j+1])>0)
      {
    
        strcpy(strtmp,Nazwiska[j]);
        strcpy(Nazwiska[j],Nazwiska[j+1]);
        strcpy(Nazwiska[j+1],strtmp);
      }
    }
  }

  plik = fopen("nazwiska_leksyko.txt", "w+t");
  if(plik==NULL)
  {
    printf("B³¹d otwarcia pliku\n");
    return 0;
  }
  for(i=0;i<index;i++)
  {
    fprintf(plik,"%s ",Nazwiska[i]);
    fprintf(plik,"\n");
  }
  fclose( plik );

  return 0;
}
