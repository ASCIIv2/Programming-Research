#include "iostream"
#include "stdlib.h"
#include "fstream"

using namespace std;

typedef struct GRAPH
{
	int **a;
	int n;
	
}DoThi;

typedef struct EDGE
{
	int u, v;
	int value;
		
}Canh;



void InputText(DoThi &g)
{
	ifstream MyFile ("test.txt");
	
	if(MyFile.is_open())
	{
		cout << "Ma tran: " << endl;
		MyFile >> g.n;
		g.a = new int*[g.n];
		for(int i=0;i<g.n;i++)
		{
		g.	a[i] = new int[g.n];
		}	
	}	
	else
	{
		cout << "Khong the mo File!" << endl;
		return;
	}
	
	
	
	for(int i=0;i<g.n;i++)
	{
		for(int j=0;j<g.n;j++)
		{
			MyFile >> g.a[i][j];
		}
	}
	
	for(int i=0;i<g.n;i++)
	{
		for(int j=0;j<g.n;j++)
		{
			cout << " " << g.a[i][j] << " ";
		}
		cout << endl;
	}
	
	MyFile.close();	
}


void KtraHopLe(DoThi g)
{
	for(int i=0; i<g.n;i++)
	{
		if(g.a[i][i] != 0)
		{
			cout << "Ma tran trong hop le" << endl;
			return;
		}
	}
	
	for(int i=0;i<g.n;i++)
	{
		for(int j=0;j<g.n;j++)
		{
			if(g.a[i][j] != g.a[j][i])
			{
				cout << "Ma tran trong hop le" << endl;
				return;
			}
		}
	}
	
	cout << "\nMa tran hop le !" << endl;
}

void KiemTraLienThong(DoThi g, int Nhan[], int i)
{
	for(int j=0; j<g.n;j++)
	{
		if(g.a[i][j] !=0 && Nhan[j] != Nhan[i])
		{
			Nhan[j] = Nhan[i];
			KiemTraLienThong(g,Nhan,j);
		}
	}
}


int XetLienThong(DoThi g)
{
	int* Nhan = new int[g.n];
	int SoThanhPhanLienThong =0;
	
	for(int i=0; i<g.n;i++)
	{
		Nhan[i] = 0;
	}
	
	for(int i=0; i< g.n;i++)
	{
		if(Nhan[i] == 0)
		{
			SoThanhPhanLienThong++;
			Nhan[i] = SoThanhPhanLienThong;
			KiemTraLienThong(g,Nhan,i);
		}
	}
	
	
	cout << "Co " << SoThanhPhanLienThong << " thanh phan lien thong" << endl;
	
	for(int i=1; i <= SoThanhPhanLienThong;i++)
	{
		cout << "\nThanh phan lien thong thu " << i << " : ";
		for(int j=0;j<g.n;j++)
		{
			if(Nhan[j] == i)
			{
				cout << " " << (j+1) << " ";
			}
		}
		cout << endl;
	}
	
	delete[] Nhan;
	
	return SoThanhPhanLienThong;
}

#define MAX 100

Canh T[MAX];

void Prim(DoThi g)
{
	
	if(XetLienThong(g) != 1)
	{
		cout << "\nDo thi khong lien thong!" << endl;
		return;
	}
	
	int nT=0;
	int* ChuaXet = new int[g.n];
	
	for(int i=0;i<g.n;i++)
	{
		ChuaXet[i] =0;
	}
	
	ChuaXet[0] = 1;
	
	while(nT < g.n-1)
	{
		Canh CanhTam;
		int CanhNhoNhat = 100;
		
		for(int i=0;i< g.n;i++)
		{
			if(ChuaXet[i] == 1)
			{
				for(int j=0;j<g.n;j++)
				{
					if(g.a[i][j] !=0 and ChuaXet[j] == 0 and g.a[i][j] < CanhNhoNhat)
					{
						CanhTam.u = i;
						CanhTam.v = j;
						CanhTam.value = g.a[i][j];
						CanhNhoNhat = g.a[i][j];
					}
				}
			}
		}
		T[nT] = CanhTam;
		nT++;
		ChuaXet[CanhTam.v] = 1;	
	}
	
	
	cout << "Prim(Cay khung nho nhat) : " ;
	for(int i=0;i<g.n-1;i++)
	{
		cout << " (" << T[i].u << "," << T[i].v << ") ";
	}
}


int main()
{
	DoThi g;
	InputText(g);
	KtraHopLe(g);
	Prim(g);
	
	for(int i=0; i<g.n;i++)
	{
		delete[] g.a[i];
	}
	
	delete[] g.a;
	
	cin.get();
}