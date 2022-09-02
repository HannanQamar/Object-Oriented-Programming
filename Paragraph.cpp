#include "Paragraph.h"
#include<iostream>
#include<fstream>
#include <ctype.h>
using namespace std;



Paragraph::Paragraph()
{
	arr = nullptr;
	
	s1 = 0;
	s2 = 0;
	s3 = 0;
    s4 = 0;
    
}

void Paragraph:: setARR(char**** array1)
{
	arr=array1;

}

char**** Paragraph::getarr()
{
	return arr;
}
Paragraph::Paragraph(Paragraph &ref)
{
	int i,j,k,l;
	
	s1 = ref.s1;
	s2 = ref.s2;
	s3 = ref.s3;
	s4 =ref.s4;
	
	arr = new char***[s1];
	
    for(i=0 ; i < s1; i++) 
	{
	   arr[i] = new char** [s2];
      for (j=0; j < s2; j++) 
	  {
	  	arr[i][j] = new char* [s3];
         for(k=0; k < s3; k++ ) 
		 {
		 	arr[i][j][k] = new char[s4];
            
         }
      }
   }
   
   i=0;j=0;k=0;l=0;
	
	 for(k=0; k < s3; k++ ) 
		 {
           arr[2][2][k][l] = ref.arr[2][2][k][l];
         }
		
}
void Paragraph::setSize1(int s)
{
	s1 = s;
}
void Paragraph::setSize2(int s)
{
	s2=s;
}
void Paragraph::setSize3(int s)
{
	s3=s;
}
void Paragraph::setSize4(int s)
{
	s4=s;
}
int Paragraph::getSize1()
{
	return s1;
}
int Paragraph::getSize2()
{
	return s2;
}
int Paragraph::getSize3()
{
	return s3;
}
int Paragraph::getSize4()
{
	return s4;
}
int Paragraph::getTotalsize()
{
	 return s1*s2*s3*s4;
}
// Functions 
bool Paragraph::ConvertUP()
{
	  bool flag;
	  int i=0,j=0,k=0,l=0;

         for(k=0; k < s3; k++ ) 
		 {
              if(isupper(arr[2][2][k][l]))
              {
              	  flag = false;
			  }
			  else
			  {
			  	arr[2][2][k][l] = toupper(arr[2][2][k][l]);
			  	  flag = true;
			  }
            
         }
	  
	 return flag; 
}
bool Paragraph::ConvertLow()
{
	bool flag;
	  int i=0,j=0,k=0,l=0;

         for(k=0; k < s3; k++ ) 
		 {
              if(islower(arr[2][2][k][l]))
              {
              	  flag = false;
			  }
			  else
			  {
			  	arr[2][2][k][l] = tolower(arr[2][2][k][l]);
			  	  flag = true;
			  }
            
         }
	  
	 return flag; 
}
// Operators
Paragraph& Paragraph::operator=(const Paragraph& ref)
{
  if (this != &ref)		// self-assignment check
  {
	int i,j,k,l;
	
	if(arr != nullptr)
	{
		delete []arr;
	}
	
	s1 = ref.s1;
	s2 = ref.s2;
	s3 = ref.s3;
	s4 =ref.s4;
	
	arr = new char***[s1];
	
    for(i=0 ; i < s1; i++) 
	{
	   arr[i] = new char** [s2];
      for (j=0; j < s2; j++) 
	  {
	  	arr[i][j] = new char* [s3];
         for(k=0; k < s3; k++ ) 
		 {
		 	arr[i][j][k] = new char[s4];
            
         }
      }
   }
   
   i=0;j=0;k=0;l=0;
	
	 for(k=0; k < s3; k++ ) 
		 {
           arr[2][2][k][l] = ref.arr[2][2][k][l];
         }
  }
  
	return *this;
}
bool Paragraph::operator==(const Paragraph& ref) const
{
	bool flag =0;
	
	int i=0,j=0,k=0,l=0;
	
	if(s3 == ref.s3)
	{
		 for(k=0; k < s3; k++ ) 
		 {
            if (arr[2][2][k][l] == ref.arr[2][2][k][l] )
            {
            	flag = true;
			}
			else
			{
				flag = false;
				break;
			}
         }
		
	}
	else
	{
		flag = false;
	}
	
	return flag;	
	
}
bool Paragraph::operator!=(const Paragraph& ref) const
{
	return !(*this == ref);
}
Paragraph& Paragraph::operator++() // pre increment
{
	
	int i=0,j=0,k=0,l=0;
	bool flag;
	
         for(k=0; k < s3; k++ ) 
		 {
              if(isupper(arr[2][2][k][l]))
              {
              	  flag = true; 
              	  //cout<<"if"<<endl;
			  }
			  else if(arr[2][2][k][l] !=',' && arr[2][2][k][l] != '.' && arr[2][2][k][l] != ' ' && arr[2][2][k][l] != '(' &&arr[2][2][k][l] != ')')
			  {
			  	 flag = false;
			  	 //cout<<arr[2][2][k][l]<<endl;
			  	 //cout<<"else"<<endl;
			  	 break;
			  }
			  
         }

	
	 if(flag)
	 {
	 	for(k=0; k < s3; k++ ) 
	   {
	 	if(arr[2][2][k][l] != ' ' && arr[2][2][k][l] != '.')
        arr[2][2][k][l] = arr[2][2][k][l] +1 ;
       }
       cout<<"  Paragraph is  incremented  !"<<endl;
	 }
     else
     {
     	 cout<<" \n Paragraph was in lower case so incremant operator doesnt works !"<<endl;
	 }
	
	
	return *this;
}					
Paragraph Paragraph::operator++(int)
{
	Paragraph answer = *this;		// invloking copy constructor
	++(*this);
	return answer;
	
}						
Paragraph& Paragraph::operator--()  // pre decrement
{
	int i=0,j=0,k=0,l=0;
	bool flag;
	
         for(k=0; k < s3; k++ ) 
		 {
              if(islower(arr[2][2][k][l]))
              {
              	  flag = true; 
              	  //cout<<"if"<<endl;
			  }
			  else if(arr[2][2][k][l] !=',' && arr[2][2][k][l] != '.' && arr[2][2][k][l] != ' ' && arr[2][2][k][l] != '(' &&arr[2][2][k][l] != ')')
			  {
			  	 flag = false;
			  	 //cout<<arr[2][2][k][l]<<endl;
			  	 //cout<<"else"<<endl;
			  	 break;
			  }
			  
         }

	
	 if(flag)
	 {
	 	for(k=0; k < s3; k++ ) 
	   {
	 	if(arr[2][2][k][l] != ' ' && arr[2][2][k][l] != '.')
        arr[2][2][k][l] = arr[2][2][k][l] - 1 ;
       }
       cout<<"  Paragraph is  decremented  !"<<endl;
	 }
     else
     {
     	 cout<<" \n Paragraph is in Upper case so decrement operator doesnt works !"<<endl;
	 }
	
	
	return *this;
	
}	
Paragraph Paragraph::operator--(int)
{
	Paragraph answer = *this;
	--(*this);
	return answer;
}	
//void Paragraph::Display()
//{
//	int i=0,j=0,k=0,l=0;
//	
//	cout<<"\n  Paragraph is : "<<endl<<endl;
//	 
//         for(k=0; k < s3; k++ ) 
//		 {
//               cout<<arr[2][2][k][l] ;
//         }
//      	
//}
Paragraph::~Paragraph()
{
	int i,j,k,l;
	
	for(i=0 ; i < s1; i++) 
	{
      for (j=0; j < s2; j++) 
	  {
         for(k=0; k < s3; k++ ) 
		 {
            delete [] arr[i][j][k];
         }
         delete [] arr[i][j];
      }
      delete []arr[i];
   }
    delete [] arr;
    arr = nullptr;
    
    
    
	
}

