#include "iostream"
#include "stdlib.h"

using namespace std;

#define MAX 100
#define VOCUC 1000
int Nhan[MAX];
int T[MAX];

typedef struct GRAPH
{
	int a[MAX][MAX];
	int n;
}DoThi;

typedef struct EDGE
{
	int u,v,value;
}Canh;

void InputText(DoThi &g)
{
	
	freopen("test.txt", "r", stdin);
	cin >> g.n;
	
	for(int i=0; i< g.n;i++)
	{
		for( int j=0; j< g.n; j++)
		{
			cin >> g.a[i][j];
		}
	}
	
	for(int i=0; i< g.n;i++)
	{
		for( int j=0; j< g.n; j++)
		{
			cout << " " <<  g.a[i][j] << " ";
		}
		cout << endl;
	}
}

void Sort(Canh A[MAX],int TongSoCanh)
{
	Canh CanhTam;
	for(int i=0; i< TongSoCanh -1; i++)
	{
		for(int j=i+1; j< TongSoCanh; j++)
		{
			if(A[i].value > A[j].value)
			{
				CanhTam = A[i];
				A[i] = A[j];
				A[j] = CanhTam;
			}
		}
	}
}


void Kruskal(DoThi g)
{
	for(int i=0; i< g.n; i++)
	{
		Nhan[i] = i;
	}
	
	int TongSoCanh =0;
	int CanhDangXet = 0;
	Canh ListCanh[MAX];
	int nT =0;
	Canh T[MAX];
	
	
	for(int i=0; i< g.n; i++)
	{
		for(int j=0; j< g.n ;j++)
		{
			if(g.a[i][j] > 0)
			{
				ListCanh[TongSoCanh].u = i;
				ListCanh[TongSoCanh].v = j;
				ListCanh[TongSoCanh].value = g.a[i][j];
				TongSoCanh++;
			}
		}
	}
	
	Sort(ListCanh, TongSoCanh);
	
	while(nT < g.n && CanhDangXet < TongSoCanh)
	{
		
		if(Nhan[ListCanh[CanhDangXet].u] != Nhan[ListCanh[CanhDangXet].v])
		{
			T[nT] = ListCanh[CanhDangXet];
			nT++;
			
			int GiaTri = Nhan[ListCanh[CanhDangXet].v];
			for(int i=0; i< g.n; i++)
			{
				if(Nhan[i] == GiaTri)
				{
					Nhan[i] = Nhan[ListCanh[CanhDangXet].u];
				}
			}
		}
		CanhDangXet++;
	}
	
	cout << "Kruskal(Cay Khung Nho Nhat): ";
	
	for(int i=0; i< nT; i++)
	{
		cout << " (" << T[i].u << "," << T[i].v << ") ";
	}
	
	
}


int main()
{
	DoThi g;
	InputText(g);
	Kruskal(g);
	cin.get();
	return 0;
}