#ifndef PARAGRAPH_H
#define PARAGRAPH_H
#include<fstream>

using namespace std;

class Paragraph
{
	private:
		
		char**** arr;
		int s1 ;
		int s2 ;
		int s3 ;
		int s4 ;

		
	public:
	
	Paragraph();
	Paragraph(Paragraph &ref);
    void setSize1(int s);
    void setSize2(int s);
    void setSize3(int s);
    void setSize4(int s);
    char**** getarr();
	void setARR(char**** array1);
	int getSize1() ;
    int getSize2();
    int getSize3();
    int getSize4();
    int getTotalsize();
    //void Display();
    
    
    // Functions 
    bool ConvertUP();
    bool ConvertLow();
    
    
	
	// Assignment Operator
	Paragraph& operator=(const Paragraph&);
	
		// Some unary operators
	Paragraph& operator++();			// pre-increment				
	Paragraph operator++(int);		//post-increment				
	Paragraph& operator--();			// pre-decrement 
	Paragraph operator--(int);		//post-decrement 

		// Comparison Operator
	bool operator==(const Paragraph&) const;
	bool operator!=(const Paragraph&) const;
	
	//Stream Insertion/Extraction Operaotrs for file
    friend ofstream& operator<<(ofstream&, const Paragraph& obj );
	friend istream& operator>>(fstream&, Paragraph& obj);
	
	// Stream Extraction Operator for Screen
	friend ostream& operator<<(ostream&, const Paragraph& obj);
	
	
	
	~Paragraph();
	
	
};

#endif

