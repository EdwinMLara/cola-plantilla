#include <iostream>
#include "Cola.h"

using namespace std;
int main()
{
	Lista<int> l1;
	Cola<int> c1;
	cout<<"-----------------Listas------------------"<<endl;
	l1.ingresarultimo(2);
	l1.ingresarultimo(6);
	l1.ingresarultimo(1);
	l1.ingresarultimo(9);
	l1.ingresarinicio(11,l1.getRef());
	c1.insertar(8);
	l1.mostrar();
	c1.MostrarValor();
	
	system("pause");
	return 0;
}