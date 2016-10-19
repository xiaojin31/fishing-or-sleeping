#include<iostream>
int date_count(int year,int month,int day);
int leap_year(int year1);
int month_num(int year2,int month2);
int main(){
	std::cout<<"Input year month day:"<<std::endl;
    int year3,month3,day3;
    std::cin>>year3>>month3>>day3;
	if(month3>12||day3>31||year3<1990)
		{
			std::cout<<"Input is Wrong!"<<std::endl;
            return 1;
		 }
	int days=date_count(year3,month3,day3);
	/*/测试
	int monthday=month_num(year3,month3);
	std::cout<<days<<std::endl;
	std::cout<<monthday<<std::endl;
    */
	if(days%5==1||days%5==2||days%5==3)
		std::cout<<"fishing"<<std::endl;
	else
		std::cout<<"sleeping"<<std::endl;
}
//计算1990-1-1至输入日期的天数
int date_count(int year,int month,int day)
{

	int t=leap_year(year);
	int m=month_num(year,month);
	int days_num=365*(year-1990)+ t + m + day;
	return days_num;
}
//计算1990至输入年份之间有多少闰年
int leap_year(int year1)
{
    int count=0;
	for(int i=1990;i<year1;i++)
	{
		if((i%4==0&&i%100!=0)||(i%400==0))
			count++;
	}
	return count;
}
//计算输入月份之前的天数
int month_num(int year2,int month2)
{
	int day2;
	switch(month2){
	case 1:day2=0;
           return day2;
           break;
	case 2:day2=31;
           return day2;
           break;
	case 3:if((year2%4==0&&year2%100!=0)||(year2%400==0))
			   {day2=60;
			   return day2;
               break;}
		   else
			   {day2=59;
               return day2;
               break;}
	case 4:if((year2%4==0&&year2%100!=0)||(year2%400==0))
			   {day2=91;
			   return day2;
               break;}
		   else
			   {day2=90;
               return day2;
               break;}
	case 5:if((year2%4==0&&year2%100!=0)||(year2%400==0))
			   {day2=121;
			   return day2;
               break;}
		   else
			   {day2=120;
               return day2;
               break;}
	case 6:if((year2%4==0&&year2%100!=0)||(year2%400==0))
			   {day2=152;
			   return day2;
               break;}
		   else
			   {day2=151;
               return day2;
               break;}
	case 7:if((year2%4==0&&year2%100!=0)||(year2%400==0))
			   {day2=182;
			   return day2;
               break;}
		   else
			   {day2=181;
               return day2;
               break;}
	case 8:if((year2%4==0&&year2%100!=0)||(year2%400==0))
			   {day2=213;
			   return day2;
               break;}
		   else
			   {day2=212;
               return day2;
               break;}
	case 9:if((year2%4==0&&year2%100!=0)||(year2%400==0))
			   {day2=244;
			   return day2;
               break;}
		   else
			   {day2=243;
               return day2;
               break;}
	case 10:if((year2%4==0&&year2%100!=0)||(year2%400==0))
			   {day2=274;
			   return day2;
               break;}
		   else
			   {day2=273;
               return day2;
               break;}
	case 11:if((year2%4==0&&year2%100!=0)||(year2%400==0))
			   {day2=305;
			   return day2;
               break;}
		   else
			   {day2=304;
               return day2;
               break;}
	case 12:if((year2%4==0&&year2%100!=0)||(year2%400==0))
			   {day2=335;
			   return day2;
               break;}
		   else
			   {day2=334;
               return day2;
               break;}
	}
}

