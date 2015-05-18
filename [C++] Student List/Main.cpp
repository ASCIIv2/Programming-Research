#include "iostream"
#include "stdlib.h"
#include "string"

using namespace std;

typedef struct STUDENT
{
	string Name;
	long int ID;
	
}SV;

typedef struct ARRAY_STUDENT
{
	SV a[100];
	int n;
}ArrSV;

void Input_1_SV(SV &k)
{
	fflush(stdin);
	cout << "Student Name: ";
	getline(cin,k.Name);
	cout <<"\nStudent ID: ";
	cin >> k.ID;
}

void OutPut_1_SV(SV k)
{
	cout << "\nStudent Name: " << k.Name << "\nStudent ID: " << k.ID;
}

void Input_Arr_SV(ArrSV &k)
{
	for(int i=0; i< k.n;i++)
	{
		Input_1_SV(k.a[i]);
	}	
}

void Output_Arr_SV(ArrSV k)
{
	for(int i=0; i< k.n;i++)
	{
		OutPut_1_SV(k.a[i]);
	}	
}

void Swap(SV &Element1, SV &Element2)
{
	SV Temp = Element1;
	Element1 = Element2;
	Element2 = Temp;
}



void Student_Sort(ArrSV &k)
{
	for(int i=0; i< k.n; i++)
	{
		for(int j=0; j< k.n; j++)
		{
			if(k.a[i].ID > k.a[j].ID)
			{
				Swap(k.a[i],k.a[j]);
			}
		}
	}
	
}

int main()
{
	
	ArrSV s;
	cout << "Nhap so luong: " ;
	cin >> s.n;
	
	Input_Arr_SV(s);
	//Output the array
	cout << "\nStudent Array are: ";
	Output_Arr_SV(s);
	
	cout << "\n\nStudent sort with id hightest:" << endl;
	Student_Sort(s);
	cout << "Student Array become: ";
	Output_Arr_SV(s);
	
	cin.get();
	return 0;
}
