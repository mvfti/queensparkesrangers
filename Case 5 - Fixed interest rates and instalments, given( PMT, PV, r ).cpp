#include <iostream>

#include <fstream>

#include <ctime>

#include <cstring>

#include <cmath>

#include <cstdlib>



using namespace std;



int main()

{

    srand (( unsigned ) time (0)); 

    
	double  N, PVi, PMTi,r,freq, monthi, yeari;
	

    

cout<<"Input the present value: ";


cin>>PVi;cout<<endl;


cout<<" Input the Interest rate: ";

cin>>r;cout<<endl;

cout<<"Input the Installment: ";

cin>> PMTi; cout<<endl;

cout<<"Input frequency (1=annually, 2=semi-anually,4=quarterly,12=monthly): ";

cin>>freq;cout<<endl;


cout<<"Input your starting month: ";

cin>>monthi;cout<<endl;

cout<<"Input your starting year: ";

cin>>yeari;cout<<endl;





	double rate, A, P;
	int n;
	
	A= PMTi;
	
	P= PVi;
	
	rate= (r/freq)/100;
	
	N= log(A/(A-P*rate))/log1p(rate);
	
	
    n= round(N);
	    
	double PMT[n] , PV[n+1],  closingbal[n], interest[n], principal[n], periodic, per_year[n], per_month[n];


	
periodic= (r/freq);


PV[1]= PVi;


PMT[1]= PMTi;

per_month[1]=monthi;

per_year[1]=yeari;





	for (int i=1;i<=n;i++)

  {

  
  interest[i]=(periodic/100)*PV[i];

  principal[i]= PMTi-interest[i];

  closingbal[i]=PV[i]-principal[i];

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

  myfile3.open ("iheartyassaminCase5.csv");

  myfile3 << "Period#, Date, Opening Balance, Principal, Periodic Interest Rate, Interest, Installment, Closing Balance \n";

  

  for (int i=1; i<=n;i++)

  {

  

  	myfile3<<i<<","<<per_month[i]<<"/"<<per_year[i]<<","<<PV[i]<<","<<principal[i]<<","<<periodic<<"%"<<","<<interest[i]<<","<<PMTi<<","<<closingbal[i]<<endl;

  	

  }

  myfile3.close();

}

