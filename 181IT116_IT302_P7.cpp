#include<iostream>
#include<bits/stdc++.h>
#include<fstream>
using namespace std;


 int fact1(int n) 
{   if(n==0)return 1;
     int temp = 1; 
    for (int i = 2; i <= n; i++) 
       { temp = temp * i;} 
       
    return temp; 
} 

int main()
{
  double p1,p2,p3;
  int n ,run1,run2,run3;
 
  cout<<"Enter the value of N:"<<endl;
  cin>>n;

  cout<<"Enter the value of p1:"<<endl;
  cin>>p1;

  cout<<"Enter the value of p2:"<<endl;
  cin>>p2;

  cout<<"Enter the value of p3:"<<endl;
  cin>>p3;

  cout<<"Enter number of airplanes on Runway 1:"<<endl;
  cin>>run1;

  cout<<"Enter number of airplanes on Runway 2:"<<endl;
  cin>>run2;

  cout<<"Enter number of airplanes on Runway 3:"<<endl;
  cin>>run3;
  
     if(n<0 || (ceil(n)!=floor(n)))
    {
        cout<<"Input Invalid"<<endl;
        return 0;
    }
 
    if(p1<0 || p1>1 || p2<0 || p2>1 || p3<0 || p3>1 || run1<0 || run2<0 || run3<0)
    {
        cout<<"Input Invalid"<<endl;
        return 0;
    }

double n_fact = fact1(n);
double fact = fact1(run1) * fact1(run2) * fact1(run3);
double x = pow(p1,run1) * pow(p2,run2) * pow(p3,run3);
double ans = (n_fact/fact) * x;

cout<<"The Probability that "<<n<<" randomly arriving airplanes are distributed in the required manner ="<<ans<<endl;


}