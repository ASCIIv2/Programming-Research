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

#define VOCUC 1000

int ChuaXet[MAX];
int LuuVet[MAX];
int DuongDiNganNhat[MAX];

int TimDuongDiNganNhat(DoThi g)
{
	int li = -1;
	int p = VOCUC;
	for(int i=0;i<g.n;i++)
	{
		if(ChuaXet[i] == 0 && DuongDiNganNhat[i] < p)
		{
			p = DuongDiNganNhat[i];
			li =i;
		}
	}
	return li;
}

void CapNhatDuongDi(int u, DoThi g)
{
	ChuaXet[u] =1;
	
	for(int v=0;v<g.n;v++)
	{
		if(ChuaXet[v] == 0 && g.a[u][v] >0)
		{
			if(DuongDiNganNhat[v] > DuongDiNganNhat[u] + g.a[u][v])
			{
				DuongDiNganNhat[v] = DuongDiNganNhat[u] + g.a[u][v];
				LuuVet[v] = u;
			}
		}
	}
	
}




void Dijkstra(DoThi g)
{
	int S,F;
	
	for(int i=0;i<g.n;i++)
	{
		DuongDiNganNhat[i] = VOCUC;
		ChuaXet[i] =0;
		LuuVet[i] = -1;
	}
	
	cout << "\nNhap dinh bat dau: ";
	cin >> S;
	cout << "\nNhap dinh ket thuc: ";
	cin >> F;
	
	DuongDiNganNhat[S] =0;
	
	while(ChuaXet[F] == 0)
	{
		int u= TimDuongDiNganNhat(g);
		
		if(u == -1)
		{
			break;
		}
		
		CapNhatDuongDi(u,g);
	}
	
	cout << "Dijkstra(Duong Di Ngan Nhat): ";
	cout << "\n" <<F;
	
	int i=F;
	
	while(LuuVet[i] != S)
	{
		cout << " <- " << LuuVet[i];
		i = LuuVet[i]; 
		
	}
	
	cout << " <- " << LuuVet[i];
	
}

int main()
{
	DoThi g;
	InputText(g);
	KtraHopLe(g);
	Dijkstra(g);
	
	for(int i=0; i<g.n;i++)
	{
		delete[] g.a[i];
	}
	
	delete[] g.a;
	
	cin.get();
}