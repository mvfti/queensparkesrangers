#include <iostream>
#include <fstream>
#include <ctime>
#include <cstring>
#include <cmath>
#include<cstdlib>

using namespace std;

int main()
{
    srand (( unsigned ) time (0)); 
    double PVi,rate,freq,monthi,yeari;
    int n;
    
cout<<"Input the Present Value:  ";
cin>>PVi;cout<<endl;
cout<<" Input the Interest rate: ";
cin>>rate;cout<<endl;
cout<<"Input frequency (1=annually, 2=semi-anually,4=quarterly,12=monthly): ";
cin>>freq;cout<<endl;
cout<<"Input number of Periods: ";
cin>>n;cout<<endl; 
cout<<"Input your starting month: ";
cin>>monthi;cout<<endl;
cout<<"Input your starting year: ";
cin>>yeari;cout<<endl;
	
	double PV[n+1], closingbal[n], install[n], interest[n], principal, periodic, per_year[n], per_month[n];
	PV[1]=PVi;
	per_month[1]=monthi;
	per_year[1]=yeari;
	principal=PVi/n;
	
	
	
	for (int i=1;i<=n;i++)
  {
  
  
  periodic=rate/freq;
  interest[i]=(periodic/100)*PV[i];
  install[i]=interest[i]+principal;
  closingbal[i]=PV[i]-principal;
	PV[i+1]=closingbal[i];
	
	per_year[i+1]=per_year[i];
	per_month[i+1]=per_month[i]+(12/freq);
	
	if (per_month[i+1]>12)
	{
		per_month[i+1]=per_month[i+1]-12;
		per_year[i+1]=per_year[i+1]+1;
	}
}


  ofstream myfile3;
  myfile3.open ("iheartyassaminCase1.csv");
  myfile3 << "Period#, Date, Opening Balance, Principal, Periodic Interest Rate, Interest, Instalment, Closing Balance \n";
  
  for (int i=1; i<=n;i++)
  {
  
  	myfile3<<i<<","<<per_month[i]<<"/"<<per_year[i]<<","<<PV[i]<<","<<principal<<","<<periodic<<"%"<<","<<interest[i]<<","<<install[i]<<","<<closingbal[i]<<endl;
  	
  }
  myfile3.close();
}
