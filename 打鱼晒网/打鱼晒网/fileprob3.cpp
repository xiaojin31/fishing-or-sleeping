#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
using namespace std;

struct Sg{
    int stunum;
    int math;
    int yuwen;
    int eng;
    int total;
    int nu;
};

void pai(char *filename,char *fname);
int cou(char *filename);
int main()
{
    char fname[20],ffname[20];
    cout<<"Input file's name you want rank:"<<endl;
    cin.getline(fname,20,'\n');
    cout<<"Input file's name you want save to:"<<endl;
    cin.getline(ffname,20,'\n');
    pai(fname,ffname);
    return 0;
}
void pai(char *filename,char *fname)
{
    //stringstream ss;
    fstream f1,f2;
    f1.open(filename);
    f2.open(fname);
    int n = cou(filename) - 1;
    //int n = m-1;
    Sg stu[n];
    string s;
    getline(f1,s);
    for(int i = 0; i < n; ++i)
    {
        string str[4];
        //stu.stunum = (int)malloc(sizeof(int));
        getline(f1,str[0],'\t');
        stu[i].stunum = atoi(str[0].c_str());
        //stu.stunum = stoi(str[0]);
        /*ss<<str[0];
        ss.clear();
        ss>>Sg.stunum;
        ss.clear();*/
        //stu.math = (int)malloc(sizeof(int));
        getline(f1,str[1],'\t');
        stu[i].math = atoi(str[1].c_str());
        //stu.yuwen = (int)malloc(sizeof(int));
        getline(f1,str[2],'\t');
        stu[i].yuwen = atoi(str[2].c_str());
        //stu.eng = (int)malloc(sizeof(int));
        getline(f1,str[3],'\n');
        stu[i].eng = atoi(str[3].c_str());
        stu[i].total = stu[i].math + stu[i].yuwen + stu[i].eng;
    }
    //*********
    for(int i = 0; i < n-1; ++i)
    {
        for(int j =0; j < n-i; ++j)
        {
            if(stu[j].total<stu[j+1].total)
            {
                Sg sg = stu[j];
                stu[j] = stu[j+1];
                stu[j+1] = sg;
            }
        }
    }
    //**********
    for(int i = 0; i < n; ++i)
    {
        stu[i].nu = i+1;
    }
    //**************
    for(int i = 0; i < n; ++i)
    {
        if(stu[i].total==stu[i-1].total)
        {
            stu[i].nu = stu[i-1].nu;
        }
    }
    //***********
    cout<<"Stunum\t"<<"Math\t"<<"Ch\t"<<"Eng\t"<<"Total\t"<<"Rank\t"<<endl;
    for(int i = 0; i < n; ++i)
    {
        cout<<stu[i].stunum<<"\t"<<stu[i].math<<"\t"<<stu[i].yuwen<<"\t"<<stu[i].eng<<"\t"<<stu[i].total<<"\t"<<stu[i].nu<<endl;
    }
     //************
    f2<<"Stunum\t"<<"Math\t"<<"Ch\t"<<"Eng\t"<<"Total\t"<<"Rank\t"<<endl;
    for(int i = 0; i < n; ++i)
    {
        f2<<stu[i].stunum<<"\t"<<stu[i].math<<"\t"<<stu[i].yuwen<<"\t"<<stu[i].eng<<"\t"<<stu[i].total<<"\t"<<stu[i].nu<<endl;
    }
    f1.close();
    f2.close();
}
int cou(char *filename)
{
    fstream f1;
    f1.open(filename);
    string str;
    int n = 0;
    while(getline(f1,str,'\n'))
    {
        ++n;
    }
    return n;
    f1.close();
}
