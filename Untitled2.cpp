#include "Paragraph.h"
#include<iostream>
#include<fstream>

using namespace std;

// For Screen
ostream& operator<<(ostream& os , Paragraph& obj)
{
	int i=0,j=0,k=0,l=0;
	
	 os<<"\n  Paragraph is : "<<endl<<endl;
	 char****ar1=obj.getarr();
	 for(k=0; k < obj.getSize3(); k++ ) 
		 {
               cout<<ar1[2][2][k][l] ;
         }
         
            return os;
}
// For File
fstream& operator<<(fstream& object, Paragraph& obj )
{
	
	object.open("Output2.txt",ios::out);
    
    
     int i=0,j=0,k=0,l=0;
	 char**** newarr=obj.getarr();
     int Tp=1,Tsentences = 0,Tword =0,Tchar=0;
	
	 for(k=0; k < obj.getSize3(); k++ ) 
		 {
               if(newarr[2][2][k][l] == 10)
			   {
			   	  Tp ++;
			   }
			   if(newarr[2][2][k][l] == '.')
			   {
			   	  Tsentences++;
			   }
         }
    
    i=0,j=0,k=0,l=0;
    int pnext= 0,pnow=0;
    int n=0;
    
     object <<"Total Parapragh ="<<Tp<<endl;
     //cout<<"Total Parapragh ="<<Tp<<endl;
     object <<"Total sentenses in Paragraph "<<Tp<<" : "<<Tsentences<<endl;
     //cout<<"Total sentenses = "<<Tsentences<<endl;
    
    for(i=0;i<Tp;i++)
    {
    	//cout<<"Paragraph no "<<i+1<<endl;
    	for(j=0;j<Tsentences;j++)
    	{
    		object <<"Paragraph No "<<i+1<<" Sentence No "<<j+1<<endl;
    		//cout<<"Paragraph No "<<i+1<<" Sentence No "<<j+1<<endl;
    		pnow = k;
    		pnext = n;
    		
			for(k; k < obj.getSize3(); k++ ) 
		    {
		    	if(newarr[2][2][k][l] == '.')
			   {
			   	   for(n;n<=k;n++)
			   	   	if(newarr[2][2][n][l] == ' ')
			   	    	{
			   	    		 Tword++;
						}
					
				  Tword++;	
				  break;		
			   }
			 
            }
            
            object <<"Total Words in Sentence no "<<j+1<<" : "<<Tword<<endl; 
            //cout<<"Total Words in Sentence no "<<j+1<<" : "<<Tword<<endl;  
		    
			int x=pnow;
			if(x!=0)
			x++;
			
			for(int w=0;w<Tword;w++)
			{
				for(x;x<=k;x++ ) 
		        {
		            if(newarr[2][2][x][l] != ' ' && newarr[2][2][x][l] != '.')
		            {
		            	Tchar++;
					}
				    else
				    {
				    	break;
					}
			        
                }
                
                x++;
                object <<"Total Characters in Word no "<<w+1<<" Sentence no "<<j+1<<" : "<<Tchar<<endl; 
				//cout<<"Total Characters in Word no "<<w+1<<" Sentence no "<<j+1<<" : "<<Tchar<<endl;
			        Tchar = 0;   
		    }
			
				
			k=k+1;
            n=n+1;
			Tword =0;
		    Tchar = 0; 
		}
		
	}
    
    
    
    object.close();
    
    cout<<"\n \n Writing to the File done Successfully !"<<endl;
    obj.setARR(newarr);
   
   return object;
}
istream& operator>>(fstream& A, Paragraph& obj)
{
	fstream fin;
	
    fin.open("Input.txt", ios::in);
    
    char ch;
    int Tchar = 0;
    int Twords=0;
    int Tsentence = 0;
    
    // to determine the size of 4D array 
    while (!fin.eof())
    {
       fin.get(ch);
       if (ch == '.')
       {
         Tsentence++;
       }
       else if( ch == ' ')
       {
       	  Twords ++;
	   }
	   	 Tchar ++;
    }
    fin.close();
    
    int size1,size2,size3,size4;
    int i,j,k,l;
    
    size1 = Tsentence-1;
    size2 = Twords;
	size3 = Tchar-1;
	size4 = 1; 
	   
    
//    cout<<"\n Total Sentences = "<<Tsentence-1<<endl;
//    cout<<"\n Total Words = "<<Twords<<endl;
//    cout<<"\n Total Characters = "<<Tchar-1<<endl;
    
    // allocation size to 4D array;
    obj.arr = new char***[size1];
	
    for(i=0 ; i < size1; i++) 
	{
	   obj.arr[i] = new char** [size2];
      for (j=0; j < size2; j++) 
	  {
	  	obj.arr[i][j] = new char* [size3];
         for(k=0; k < size3; k++ ) 
		 {
		 	obj.arr[i][j][k] = new char[size4];  
         }
      }
    }
    
    obj.setSize1( size1);
    obj.setSize2( size2);
    obj.setSize3( size3);
    obj.setSize4( size4);

    
    // Entering data to 4D array
    fin.open("Input.txt", ios::in);
    
    i=0;j=0;k=0;l=0;
    
    // storing charcters
    while (!fin.eof())
    {
      // cout<<"File data "<<endl;
      
       fin.get(ch);
       
       if(k<size3)
	   obj.arr[2][2][k][l] = ch;
	   k++;
    }
    
    
    fin.close();
   
   return A;
	
}

int main()
{    
    Paragraph obj,obj2;
    fstream f;
    
    f>>obj;
    cout<<obj<<endl;
    
    obj2=obj;
    cout<<obj2<<endl;
    
    if(obj == obj2)
    {
    	cout<<"\n \n Equal"<<endl;
	}
	else
	{
		cout<<"\n  \n Not Equal"<<endl;
	}
    
    obj2++;
    cout<<obj2<<endl;
    
    if(obj == obj2)
    {
    	cout<<"\n \n Equal"<<endl;
	}
	else
	{
		cout<<"\n  \n Not Equal"<<endl;
	}
    
    
//    --obj;
//    cout<<obj<<endl;
//    
//    cout<<endl;
    
    Paragraph obj3(obj);
    cout<<obj3<<endl;



      obj2.ConvertUP();
      cout<<"\n  After converting to uppercase :"<<endl;
      cout<<obj2<<endl;
       
        
       
      obj2.ConvertLow();
      cout<<"\n  After converting to lower :"<<endl;
      cout<<obj2<<endl;
      
     cout<<endl;
      --obj2;
      cout<<obj2<<endl;
     
     
	     
    cout<<"\n \n Writing to the File !"<<endl;
    
    f<<obj;
    
   // system("pause");
    return 0;
}


