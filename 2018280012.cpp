#include <bits/stdc++.h> 
#include <sstream> 
#include<iostream>

using namespace std; 
  
string Romana(int sayi)  
{    
     string m[] = {"", "M", "MM", "MMM"}; 
     string c[] = {"", "C", "CC", "CCC", "CD", "D",  
                        "DC", "DCC", "DCCC", "CM"}; 
     string x[] = {"", "X", "XX", "XXX", "XL", "L",  
                        "LX", "LXX", "LXXX", "XC"}; 
     string i[] = {"", "I", "II", "III", "IV", "V",  
                        "VI", "VII", "VIII", "IX"}; 
          
     
     string bin = m[sayi/1000]; 
     string yuz = c[(sayi%1000)/100]; 
     string on =  x[(sayi%100)/10]; 
     string bir = i[sayi%10]; 
          
     string cevap = bin + yuz + on + bir; 
          
     return cevap; 
} 
  
int deger(char a) 
{ 
    if (a == 'I') 
        return 1; 
    if (a == 'V') 
        return 5; 
    if (a == 'X') 
        return 10; 
    if (a == 'L') 
        return 50; 
    if (a == 'C') 
        return 100; 
    if (a == 'D') 
        return 500; 
    if (a == 'M') 
        return 1000; 
  
    return -1; 
} 
  

int Romandan(string &str) 
{ 
    
    int sonuc = 0; 
    for (int i=0; i<str.length(); i++) 
    { 
         
        int s1 = deger(str[i]); 
  
        if (i+1 < str.length()) 
        { 
             
            int s2 = deger(str[i+1]);  
            if (s1 >= s2) 
            { 
                sonuc = sonuc + s1; 
            } 
            else
            { 
                sonuc = sonuc + s2 - s1; 
                i++; 
            } 
        } 
        else
        { 
            sonuc = sonuc + s1; 
             
        } 
    } 
    return sonuc; 
} 
bool sifirmi(string giris)
{
	int i=0;
	bool flag=1;
	while(i<giris.length())
	{
		if(giris[i] == '0')
		i++;
		else
		{
		flag=0; 
		break;
		}
	}return flag;
}

bool sayimi(string giris) 
{ 
	int i=0;
	bool flag=1;
	while(i<giris.length())
	{ 
		if(isdigit(giris[i]) == true)
		i++;
		else
		{
			flag=0; 
			return flag; 
			break;
		}
	}return flag;
} 

bool Roma_mi(string giris)
{
	int i=0;
	bool flag=1;
	while(i<giris.length())
	{
		if(isalpha(giris[i]) == false)
		{
			flag=0; 
			return flag; 
			break;
		}
		else i++;
	}return flag;
}
int main() 
{ 
    	cout << "Sayi veya Roma rakami giriniz" << endl;
	string inp; 
	cin >> inp;
	
	if(sifirmi(inp))
		cout << "Roma rakamlarinda sifir yoktur.";
	else if(sayimi(inp))
	{
		string a = inp;
		stringstream conv(a);
		int b = 0;
		conv >> b;
		if(b>=1 && b<4000)
		Romana(b);
		else
		cout << "Belirlenen sayi araliginda girmediniz.";
	}
	else if(Roma_mi(inp))
	{
		int c = Romandan(inp);
		if(c>=1 && c<4000)
		cout << Romandan(inp);
		else
		cout << "Belirlenen Roma rakami araliginda girmediniz.";
	}
	else
		cout << "Yanlis girdiniz.";
  
    return 0; 
} //Source:geeksforgeeks.org-stackoverflow.com-cppreference.com