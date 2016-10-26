#include <iostream>
using namespace std;
int findMax(int n,long *pMaxNum);
int main()
{
	cout<<"Input students number:"<<endl;
	long k;
	long *pMaxNum = &k;
	int n;
	cin>>n;
	int m = findMax(n,pMaxNum);
	cout<<"\nmaxScore = "<<m<<" , maxNum = "<<*pMaxNum<<endl;
	return 0;
}
int findMax(int n,long *pMaxNum)
{
    int score[40];
    long num[40];
	cout<<"Input students number and grade:"<<endl;
    while(n--)
    {
    	cin>>num[n]>>score[n];
    }
	for(int i=n-1;i>0;--i)
	{
		if(score[i]>score[i-1])
			{int t = score[i];
			score[i] = score[i-1];
			score[i-1] = t;
			long s = num[i];
			num[i] = num[i-1];
			num[i-1] = s;
			}
	}
	*pMaxNum = num[0];
    return score[0];
}
