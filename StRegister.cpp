#define x
#ifndef x

#include <iostream>
using namespace std;

#include "interfaz.h"

#endif

int main()
{
	do
	{
		load_data(students, count); //cargar datos de nuestro txt...

		cout << "1. Mostrar listado de los alumnos en pantalla." << endl;
	    cout << "2. Mostrar un alumno determinado." << endl;
	    cout << "3. Insertar un alumno a la lista." << endl;
	    cout << "4. Eliminar un alumno de la lista." << endl;
	    cout << endl;
	    cout << "0. Salir." << endl;
	    cout << endl;
	    cout << " -> ";
	    cin >> menu;
	    cin.ignore();
	    cout << endl;

	    switch(menu)
	    {
	    	case 1:

	    	order_view_data(students, ji, count); // despliega menu de ordenamiento

	    	break;
	    	case 2:

	    	search_student(students, menu1); //despliega menu de busqueda

	    	break;
		    case 3:

		    if(count < 100) //si contador es menor al maximo de alumnos...
		    {
		    	request_data(students, count); //pedir y guardar los datos.
		    }

		    break;
		    case 4:

		    delate_student(students, ji,count, menu1); //elimina un alumno de la lista.

		    break;
		    case 0:

		    cout << "El programa se esta cerrando..." << endl;

		    break;
		    default:

		    cout << "No se ingreso una opcion valida. Vuelva a intentar" << endl;
	    }
	}while(menu!=0);

	cin.get();

	return 0;
}
