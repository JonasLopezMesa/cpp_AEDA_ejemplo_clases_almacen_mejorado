
#include "otras_funciones.h"



int main () {
	
	TWarehouse almacen;
	unsigned a;
	unsigned op;
	int c;
	
	while(a == 0){
		
		menu();
		cin >> op;	
		switch(op){
			case 1:
				almacen.newProduct();
				break;
			case 2:
				almacen.newProduct_o();
				break;
			case 3: 
				cout << "introduce el código del almacén que quieras modificar" << endl;
				cin >> c;
				almacen.print(c);
				break;
			case 4: 

				cout << "introduce el código del almacén que quieras modificar" << endl;
				cin >> c;

				almacen.update(c);
				break;
			case 5: 

				almacen.print_all();				
				break;	
			case 6:	

				cout << "introduce el código del producto que deseas borrar de la lista" << endl;
				cin >> c;

				almacen.removeProduct(c);			
				break;
			case 7: cout << "adios!!!" << endl;
				a = 1;
				break;	
			default: 

				cout << "ERROR vuelva a escribir una opcion correcta" << endl;
				
				
		}
	}
    
}
