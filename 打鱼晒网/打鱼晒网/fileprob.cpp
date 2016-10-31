# include <iostream>
#include <string>
#include <fstream>
#include <string.h>

using namespace std;

int countLinesNum(char *filename);
void printLongAndShortLine(char *filename);

int main()
{
	printLongAndShortLine("D:\\test\\file1.txt");
}

void printLongAndShortLine(char *filename)
{
	int k = 0,p = 0;
	char a[20][100];
	int b[20];
	fstream f1;
	f1.open(filename);
	int s = countLinesNum(filename);
	for(int i =0 ; i<s; ++i)
	{
		f1.getline(a[i],100,'\n');
		b[i] = strlen(a[i]);
	}
	for(int i = 1; i < s-1; ++i)
	{
		if( b[k] > b[i] )
		{
			k = i;
		}
	}
	cout << "short:" << a[k] << endl;
	for(int i = 1; i < s-1; ++i)
	{
		if( b[p] < b[i])
		{
			p = i;
		}
	}
	cout << "long:" << a[p] << endl;
	f1.close();
}

int countLinesNum(char *filename)
{
	ifstream file1;
	file1.open(filename);
	string temp;
	int n = 0;
	while( getline(file1,temp,'\n') )
	{
		++n;
	}
	file1.close();
	return n;
}
