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

void pai(const char *filename,const char *fname);
int cou(const char *filename);
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

int string2int(string s) {
    stringstream ss(s);
    int result(0);
    ss >> result;
    return result;
}

void pai(const char *filename,const char *fname)
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

        // Stunum  Math    Ch  Eng
        // 1       50      60  70  
        
        // 2. stringstream
        // string line;
        // getline(f1, line);
        // stringstream ss(line);      // stringstream 自动识别类型，并转换，忽略任意数量空白
        // ss >> stu[i].stunum >> stu[i].math >> stu[i].yuwen >> stu[i].eng;

        // 3. std  
        // c++11 string to int, double, ....
        // int, double ... to string.

        getline(f1,str[0],'\t');
        // stu[i].stunum = atoi(str[0].c_str());
        stu[i].stunum = stoi(str[0]);

        // stu[i].stunum = string2int(str[0]);

        //stu.stunum = stoi(str[0]);
        /*ss<<str[0];
        ss.clear();
        ss>>Sg.stunum;
        ss.clear();*/
        //stu.math = (int)malloc(sizeof(int));
        getline(f1,str[1],'\t');
        // stu[i].math = atoi(str[1].c_str());
        stu[i].math = stoi(str[1]);
        //stu.yuwen = (int)malloc(sizeof(int));
        getline(f1,str[2],'\t');
        stu[i].yuwen = stoi(str[2]);
        //stu.eng = (int)malloc(sizeof(int));
        getline(f1,str[3],'\n');
        stu[i].eng = stoi(str[3]);
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
int cou(const char *filename)
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
/*文件1格式实例
Stunum  Math    Ch  Eng
1       50      60  70  
2       60      50  70
3       80      80  80
4       40      60  80
5       60      60  90
6       40      80  70
7       50      50  50
8       80      90  80
数据间用退格键输入
*/
