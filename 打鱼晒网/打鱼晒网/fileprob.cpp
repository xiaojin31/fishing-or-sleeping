# include <iostream>
#include <string>
#include <fstream>
#include <string.h>

using namespace std;

int countLinesNum(const char *filename);  // note1: 函数不修改形参的话，把形参声明为const
void printLongAndShortLine(char *filename);

/*int countLinesNum2(const char *filename) {
    // filename[0] = 'u';
}*/

int main()
{

    //ifstream is;
    //ofstream os;

    // char name[] = "hello";
    // countLinesNum2(name);
    // cout << name << endl;

    // const -> non-const
    // non-const -> const

    //const char *fileName = "t.txt";
    //countLinesNum(fileName);

	 printLongAndShortLine("D:\\test\\file1.txt");
     printLongAndShortLine("file1.txt");
}

void printLongAndShortLine(char *filename)
{
	int k = 0,p = 0;
	char a[20][100];
	int b[20];
	// fstream f1;  // note2
    ifstream f1; 
	f1.open(filename);
    /*
     * 
     * 
     * void open( const char *filename, ios_base::openmode mode = ios_base::in );
     * 
     */
	int s = countLinesNum(filename);
	for(int i =0 ; i<s; ++i)
	{
		f1.getline(a[i],100,'\n');
		b[i] = strlen(a[i]);
	}
	for(int i = 1; i < s; ++i) // error1
	{
		if( b[k] > b[i] )
		{
			k = i;
		}
	}
	cout << "short:" << a[k] << endl;
	for(int i = 1; i < s; ++i) // error1
	{
		if( b[p] < b[i])
		{
			p = i;
		}
	}
	cout << "long:" << a[p] << endl;
	f1.close();
}

int countLinesNum(const char *filename)
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
