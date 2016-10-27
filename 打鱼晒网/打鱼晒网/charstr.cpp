#include <iostream>
#include <string.h>
using namespace std;
void revstr(char *a);
int main(){
	cout<<"Input Character String:"<<endl;
	char str[100];
	//gets(str);
	cin.getline(str,100);
	revstr(str);
	return 0;
}
void revstr(char *a)
{
	int s = strlen(a);
	for(int i = s-1;i >= 0;--i)
	{
		cout<<a[i];
	}
	cout<<endl;
}
