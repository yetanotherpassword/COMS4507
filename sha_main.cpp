// g++ sha256.cpp --std=c++11 sha_main.cpp -o sha256_example

#include <iostream>
#include <stdlib.h>
#include "sha256.h"
 
using std::string;
using std::cout;
using std::endl;
 
int main(int argc, char *argv[])
{
    string ID = "46049016";
    //string ID = "43745091";
    //string n = "06GH9BYYZ5";
    int target = 2^228;
    string exp_Hash = "0000000505562365dc9268454f4644a925e1e1bd435be40ce9a63dfd889f8258";
    string input;
    string output1;
    const char * ptr = output1.c_str();
    char start=0x20;
    char fin = 0x7f;
    char app[256];
    char cur= start;
    int not_yet = 0;
    int i=0;
    int end = 0;
    string n = " ";
    char buf[1024];
    int noz_bin[10]={0,0,0,0,0,0,0,0,0,0};
    long int lap=0;
    while (not_yet == 0) 
    {
	double frac = (double) rand() / ((double) (RAND_MAX+1.0));
	double num = frac * 40.0;
	int len = (int) num;
	for (i=0; i<len; i++)
        {
	   double frac2 = (double) rand() / ((double) (RAND_MAX+1.0));
	   double num2 = frac2 * 96.0;
	   buf[i]=(char) (int) (num2+32.0);
	}
	buf[i]='\0';
	string b2=string(buf);
	input = ID + b2;
        output1 = sha256(input);
//    cout << "sha256('"<< input.length()<< "'):" << output1.length() << endl;
        string n1 = output1.substr(0,5);
        string n2 = output1.substr(5,5);
//	cout << "n1="<<n1 <<":"<< endl;
//	cout << "n2="<<n2 <<":"<< endl;
	int noz=0;
        int n = stoi(n1,0,16);
        int n3 = stoi(n2,0,16);
	if (n == 0)
	{
		if (n3 == 0)
		{
			not_yet = 1;
	            cout << "First 10 digits are 0="<<n1  << n2<< " lap# " << lap <<endl;
		}
                else
	        {
	            cout << "First 5 digits are 0="<<n1  << n2<< " lap# " << lap <<endl;
		    if (n3 <= 15)
			noz=9;
		    else if (n3 <= 255)
			noz=8;
   		    else if (n3 <= 4095)
			noz=7;
		    else if (n3 <= 65535)
			noz=6;
		    else if (n3 <= 1048575)
			noz=5;
	       }
	}
	else
	{
//		cout << "N=" << std::hex << n << std::dec << endl;
		if (n <= 15)
			noz=4;
		else if (n <= 255)
			noz=3;
		else if (n <= 4095)
			noz=2;
		else if (n <= 65535)
			noz=1;
		else if (n <= 1048575)
			noz=0;
	}
	noz_bin[noz]++;
	lap++;
//	cout << "Noz = " << noz << " lap=" << lap++ << endl;
	if (lap % 10000000 == 0)
	{
		cout << "******************************************" << endl;
		cout << "On lap # " << lap << " we have cnts :" << endl;
		for (int z =0; z< 10; z++)
			cout << "noz_bin[" << z << "]=" << noz_bin[z] << endl;
    cout << "sha256('"<< input<< "'):" << output1 << endl;
	cout << "For   len=" << len << "and buf=" << buf << " and b2=" << b2 << endl;
	}
    }


	     
    return 0;
}
