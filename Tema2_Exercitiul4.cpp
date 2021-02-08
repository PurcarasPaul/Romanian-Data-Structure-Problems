#include <stdio.h>

struct Pozitii
{
	int linie, coloana;
};

void Tiparire(int** A,int linii,int coloane,Pozitii *Locatii_Puncte_Sa,int puncte_sa)
{
	printf_s("\n");

	for (int i = 0;i < linii;i++)
	{
		for (int j = 0;j < coloane;j++)
		{
			printf_s("%d ",A[i][j]);
		}
		
		printf_s("\n");
	}

	if (!puncte_sa)
	{
		printf_s("\nNu exista puncte sa.\n");
		return;
	}

	printf_s("\nLocatiile punctelor sa:\n");
	for (int i = 0;i < puncte_sa;i++)
	{
		printf_s("Punct sa %d,linia %d,coloana %d.\n", i + 1, Locatii_Puncte_Sa[i].linie + 1, Locatii_Puncte_Sa[i].coloana + 1);
	}
}

bool Este_Punct_Sa(int **A,int Elem,int j,int linii)
{
	for (int i = 0;i < linii;i++)
	{
		if (A[i][j]>Elem)
		{
			return false;
		}
	}
	
	return true;
}

int Determinare_Min_Linie(int** A,int i, int coloane)
{
	int min_lin = A[i][0];

	for (int j = 1;j < coloane;j++)
	{
		if (A[i][j] < min_lin)
		{
			min_lin = A[i][j];
		}

	}

	return min_lin;
}

void Determinare_Puncte_Sa(int** A, int linii, int coloane,Pozitii *Locatii_Puncte_Sa,int &puncte_sa)
{
	for (int i = 0;i < linii;i++)
	{
		int elem = 0;
		int min_lin = Determinare_Min_Linie(A,i,coloane);
		Pozitii *elem_posibile=new Pozitii[coloane];

		for (int j = 0;j < coloane;j++)
		{
			if (A[i][j] == min_lin)
			{
				elem_posibile[elem].linie = i;
				elem_posibile[elem++].coloana = j;
			}
		}

		for (int k = 0;k < elem;k++)
		{
			if (Este_Punct_Sa(A,A[elem_posibile[k].linie][elem_posibile[k].coloana],elem_posibile[k].coloana,linii))
			{
				Locatii_Puncte_Sa[puncte_sa].linie = elem_posibile[k].linie;
				Locatii_Puncte_Sa[puncte_sa++].coloana = elem_posibile[k].coloana;
			}
		}
	}
}

int main()
{
	int linii, coloane,puncte_sa=0;
	int** A;
	Pozitii* Locatii_Puncte_Sa;

	printf_s("Introduceti numarul de linii: ");
	scanf_s("%d", &linii);

	printf_s("Introduceti numarul de coloane: ");
	scanf_s("%d", &coloane);

	printf_s("\n");

	A = new int* [linii];
	Locatii_Puncte_Sa = new Pozitii[linii * coloane];

	for (int i = 0;i < linii;i++)
	{
		A[i] = new int[coloane];

		for (int j = 0;j < coloane;j++)
		{
			printf_s("A[%d][%d]=", i+1, j+1);
			scanf_s("%d", &A[i][j]);
		}
	}

	Determinare_Puncte_Sa(A, linii, coloane, Locatii_Puncte_Sa, puncte_sa);
	Tiparire(A,linii,coloane,Locatii_Puncte_Sa,puncte_sa);

	printf_s("\n");

	for (int i = 0; i < linii; i++)
	{
		delete[] A[i];
	}
	delete[] A;

	return 0;
}