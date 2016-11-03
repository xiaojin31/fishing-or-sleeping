#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
using namespace std;
void mycopy();
int countLinesNum(char *filename);
int main()
{
	mycopy();
	return 0;
}
void mycopy()
{
    cout<<"Input file you want copy to:"<<endl;
	fstream f1;
	char filename[50];
	cin.getline(filename,100,'\n');
	f1.open(filename,ios::app|ios::out);
	cout<<"Input file's number you want copy:"<<endl;
	fstream f2;
	int n;
	char a[20];
	cin>>n;
	cin.getline(a,20);
	cout<<"Input file you want copy:"<<endl;
	while(n--){
	char fname[50];
    cin.getline(fname,100,'\n');
    f2.open(fname);
    f1<<endl;
    f1<<f2.rdbuf();
    f2.close();
    }
    f1.close();
}

