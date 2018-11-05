using namespace std;

template <class T>
class Nodo{	
public:
	T valor;
	Nodo<T> *sig;
	Nodo();
	Nodo(T);
};

template <class T>
Nodo<T>::Nodo()
{
	
}

template <class T>
Nodo<T>::Nodo(T n)
{
	valor = n;
	sig = 0;
}


template <class T>
class Lista : public Nodo<T>
{
public:

	Nodo<T> *primero;
	Nodo<T> *Ultimo;
	Nodo<T> *actual;
	Nodo<T> *nuevo(T);
	
	Lista();
	bool vacio();
	void ingresarultimo(T);
	void ingresarinicio(T, Nodo<T>*);
	Nodo<T>* getRef();
	void mostrar();
	void borrarprimero();
	void borrarultimo();
	void borrarcualquiera();
};

template <class T>
Lista<T>::Lista()
{
	this->primero=0;
	this->Ultimo=0;
}

template <class T>
bool Lista<T>::vacio()
{
	return(primero == 0);
}

template <class T>
Nodo<T>* Lista<T>::nuevo(T n)
{
	Nodo<T> *pun = new Nodo<T> (n);
	return pun;
}

template <class T>
Nodo<T>* Lista<T>::getRef()
{
	return actual;
}

template <class T>
void Lista<T>::ingresarultimo(T n)
{
	Nodo<T> *temporal = nuevo(n);
	if(vacio())
	{
		primero = Ultimo = temporal;
	}
	else
	{
		Ultimo->sig = temporal;
		Ultimo = temporal;
		actual = primero;
	}
}

template <class T>
void Lista<T>::ingresarinicio(T n,Nodo<T> *head)
{
	Nodo<T> *temporal = nuevo(n);
	if(vacio())
	{
		primero = Ultimo = temporal;
	}
	else
	{
		primero = temporal;
		primero->sig = head;
	}
}

template <class T>
void Lista<T>::mostrar()
{
	if(vacio())
	{
		cout<<"la Lista esta vacia"<<"\n";
	}
	else
	{
		Nodo<T> *aux = primero;
		int i = 1;
		cout << "Datos \n";
		do
		{
			cout<<"Numero"<<i<<" "<<aux->valor<<"\n";
			i++;
			aux = aux->sig;
		}
		while(aux!=0);
	}
}

template <class T>
void Lista<T>::borrarprimero()
{
	if(this->vacio())
	{
		cout<<"La Lista esta Vacia \n";
	}
	else
	{
		Nodo<T> *ayuda = primero;
		primero = primero->sig;
		delete(ayuda);
	}
}

template <class T>
void Lista<T>::borrarultimo()
{
	if(vacio())
	{
		cout<<"La Lista esta Vacia \n";
	}
	else
	{
		Nodo<T> *ayuda = primero;
		Nodo<T> *ant;
		ant->sig = 0;
		this->Ultimo = ant;
		delete(ayuda);
	}
}

template <class T>
void Lista<T>::borrarcualquiera()
{
	if(vacio())
	{
		cout<<"La Lista esta Vacia \n";
	}
	else
	{
		Nodo<T> *ayuda = primero;
		Nodo<T> *ant;
		ant->sig = 0;
		Ultimo = ant;
		delete(ayuda);
	}
}

template <class T>
class Cola : public Lista<T>
{
public:
	Cola(void);
	void insertar(T n);
	void MostrarValor();
};

template <class T>
Cola<T>::Cola(void)
{
}

template <class T>
void Cola<T>::insertar(T n)
{
	Nodo<T> *temporal = nuevo(n);
	Nodo<T> *ayuda = this->Ultimo;

	if(this->vacio())
	{
		this->primero = this->Ultimo = temporal;
	}
	else
	{
		this->Ultimo->sig = temporal;
		this->Ultimo = temporal;
		this->actual = this->primero;
		
		Nodo<T> *ant;
		ant->sig = 0;
		this->Ultimo = ant;
		delete(ayuda);
	}
}

template <class T>
void Cola<T>::MostrarValor()
{
	if(this->vacio())
	{
		cout<<"la Lista esta vacia"<<"\n";
	}
	else
	{
		Nodo<T> *aux = this->primero;
		cout << "Dato cima \n";
		cout<<"Numero"<<" "<<aux->valor<<"\n";
	}
}

