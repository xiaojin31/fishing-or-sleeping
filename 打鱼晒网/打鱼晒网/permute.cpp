#include<iostream>
void f(int &x,int &y);
void g(int &x,int &y);
int main(){
	std::cout<<"Input two numbers:"<<std::endl;
	int a,b;
	std::cin>>a>>b;
	f(a,b);
	std::cout<<"Fist permute:"<<a<<" "<<b<<std::endl;
	g(a,b);
	std::cout<<"Second permute:"<<a<<" "<<b<<std::endl;
}
void f(int &x,int &y)
{
	int t = x;
	x = y;
	y = t;
}
void g(int &x,int &y)
{
	int t = x;
	int *p = &x;
	*p = y;
	int *q = &y;
	*q = t;
}