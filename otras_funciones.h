/*
 *  SLL.h
 *  Práctica V
 *
 *  Created by Jonás López Mesa on 04/04/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */
using namespace std;
#include <iostream>
#include <string>

//CLASE DATO.......................................................................................................
//.................................................................................................................

class TDato{
private:
	int code_;
	string description_;
	int units_;
public:
	TDato();
	~TDato();
	void read();
	void write();
	void setcode(int c);
	int getcode();
};
TDato::TDato() : code_(0), description_(), units_(0) {}
TDato::~TDato() {}
void TDato::read()
{
	
	cout << "Introduce el código" << endl;
	cin >> code_;
	cout << "Introduce la descripción" << endl;
	cin >> description_;
	cout << "Introduce el número de unidades" << endl;
	cin >> units_;

}

void TDato::write (void)
{
	cout << "codigo:      " << code_ << endl;
	cout << "descripción: " << description_ << endl;
	cout << "unidades:    " << units_ << endl;
}

void TDato::setcode(int c)
{
	code_ = c;
}

int TDato::getcode()
{
	return code_;
}

	
	
//CLASE ELEMENTO LISTA.............................................................................................
//.................................................................................................................

class sll_item {
private:
	sll_item* next_;
	TDato dato_;
	//int key_;
public:
	sll_item();
	sll_item(TDato dato);
	~sll_item();
	void setnext(sll_item* n);
	sll_item* getnext();
	void setDato(TDato d);
	TDato& getDato();

};


sll_item::sll_item() : next_ (NULL), dato_ () {}
sll_item::sll_item (TDato dato) : next_ (NULL), dato_ (dato) {}
sll_item::~sll_item()
{
	next_ = NULL;	
}

void sll_item::setnext(sll_item* n)
{
	next_ = n;	
}

sll_item* sll_item::getnext()
{
	return next_;
}

void sll_item::setDato(TDato d)
{
	dato_ = d;
}

TDato& sll_item::getDato()
{
	return dato_;
}



	
	
//CLASE LISTA......................................................................................................
//.................................................................................................................

class sll {
private:
	sll_item* inicio_;
	//puntero ultimo
public:
	sll();
	~sll();
	bool empty();											//si esta vacio 0 o no 1
	void insert_b(sll_item* i);								//insertar por el principio
	void insert_e(sll_item* i);								//insertar por el final
	void insert(sll_item* P, sll_item* i);					//insertar por un lugar específico
	sll_item* remove(sll_item* p);
	sll_item* remove_b();
	sll_item* remove_e();
	void insert_o(sll_item* i);								//insertar de forma ordenada
	void imprimir();
	sll_item* search(int c);
	sll_item* search_prev(int c);
	
};


sll::sll(void) : inicio_(NULL) {}				//inicializar la lista
sll::~sll()										//Destructor
{
	sll_item* aux = NULL;
	while (inicio_ != NULL) {
		aux = inicio_;
		inicio_ = inicio_->getnext();
		delete aux;
	}
}

bool sll::empty()								//ver si la lista está vacía
{
	if (inicio_ == NULL) {	//esta vacío
		return 1;
	}
	else {					//no está vacío
		return 0;
	}
	
}

void sll::insert_b(sll_item* i)					//insertar por el principio
{
	i->setnext(inicio_);
	inicio_ = i;
}

void sll::insert_e(sll_item* i)					//insertar por el final
{
	
	i->setnext(NULL);
	if (empty() == 1) {
		inicio_ = i;
	}
	else { sll_item* aux = inicio_;
		while (aux->getnext() != NULL) {
			aux = aux->getnext();
		}
		aux->setnext(i);
	}
}

void sll::insert(sll_item* P, sll_item* i)		//insertar por un lugar específico
{
	i->setnext(P->getnext());
	P->setnext(i);
}

sll_item* sll::remove_b()						//borrar por el principio
{
	//si la lista está vacía no extraemos nada
	if (inicio_ == NULL) {
		cout << "la lista está vacía" << endl;
		return NULL;
	}
	else {
	sll_item* aux = inicio_;
	inicio_ = inicio_->getnext();
	return aux;
	}
}

sll_item* sll::remove(sll_item* prev)			//borrar un item en un lugar seleccionado
{
	sll_item* aux = prev->getnext();
	prev->setnext(aux->getnext());
	delete aux;

}

sll_item* sll::remove_e()						//borrar por el final
{
	if (inicio_->getnext() == NULL) {
		sll_item* aux = inicio_;
		inicio_ = NULL;
		return aux;
	}
	else {
		sll_item* prev = inicio_;
		while (prev->getnext()->getnext() != NULL) {
			prev = prev->getnext();
		}
		return remove(prev);
	}
}

void sll::insert_o(sll_item* e)					//insertar de forma ordenada
{
	
	sll_item* aux = inicio_;
	sll_item* aux2 = inicio_;
	unsigned r = 0;
	if (inicio_ == NULL) {
		insert_b(e);
	}
	else if ((e->getDato().getcode()) < (inicio_->getDato().getcode()))
		insert_b(e);
	else {
		while ((aux != NULL) && (r == 0)) {
		aux = aux->getnext();
			if (e->getDato().getcode() <= aux->getDato().getcode()) {
				e->setnext(aux->getnext());
				aux2->setnext(e);
				r = 1;
			}
		aux2 = aux;
		}		
	}	
}

void sll::imprimir()							//mostrar por pantalla
{
	int i = 1;
	sll_item* aux = inicio_;
	while (aux != NULL) {
		cout << "__________________" << endl;
		cout << "Elemento número:  " << i << endl;
		cout << "------------------" << endl;
		aux->getDato().write();
		aux = aux->getnext();
		
		i++;
	}
	
}

sll_item* sll::search(int c)					//buscar por el código
{
	
	sll_item* aux = inicio_;
	while ((aux != NULL) && (aux->getDato().getcode() != c)) {
		aux = aux-> getnext();
		
	}
	return aux;
}

sll_item* sll::search_prev(int c)				//buscar por el código un elemento previo
{
	
	sll_item* aux = inicio_;
	while ((aux != NULL) && (aux->getnext()->getDato().getcode() != c)) {
		aux = aux->getnext();
	}
	return aux;
}
	


//CLASE ALMACEN....................................................................................................
//.................................................................................................................

class TWarehouse{
private:
	sll lista_;
public:
	TWarehouse();
	~TWarehouse();
	void newProduct();
	void print(int c);
	void removeProduct(int c);
	void update(int c);
	void print_all();
	void newProduct_o();
};

TWarehouse::TWarehouse() : lista_() {}
TWarehouse::~TWarehouse() {}


void TWarehouse::newProduct()
{

	TDato D;
	D.read();
	sll_item* aux;
	aux = new sll_item(D);
	lista_.insert_e(aux);
	
}

void TWarehouse::newProduct_o()
{
	
	TDato R;
	R.read();
	sll_item* aux;
	aux = new sll_item(R);
	lista_.insert_o(aux);
	
}

void TWarehouse::print_all()
{
	lista_.imprimir();
}

void TWarehouse::removeProduct(int c)
{
	lista_.remove(lista_.search_prev(c));
}
	
void TWarehouse::update(int c)
{
	
	sll_item* aux;
	aux = lista_.search(c);		
	aux->getDato().read();
	
}

void TWarehouse::print(int c)
{
	sll_item* aux;
	aux = lista_.search(c);
	aux->getDato().write();
}

//OTRAS FUNCIONES..................................................................................................
//.................................................................................................................
void menu(){

	cout << "MENÚ:__________________________________________" << endl;
	cout << "1:    Alta de productos por el final de la lista." << endl;
	cout << "2:    Alta de productos de forma ordenada." << endl;
	cout << "3:    Visualizar los datos de un producto." << endl;
	cout << "4:    Modificar los datos de un producto." << endl;
	cout << "5:    Obtener una lista de todos los productos." << endl;
	cout << "6:    Dar de baja a un producto." << endl;
	cout << "7:    Salir." << endl;
	cout << "-----------------------------------------------" << endl;

}
	

