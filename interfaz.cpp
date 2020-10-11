#define x
#ifndef x

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "interfaz.h"

#endif

void load_data(struct student students[100], int &count)
{
	count = 0;

	ifstream imp_file;
	imp_file.open("students.txt", ios::in);
	if(imp_file.is_open())
	{
		while(!imp_file.eof())
		{
			getline(imp_file, students[count].name);

			getline(imp_file, students[count].lastname);

			imp_file >> students[count].order_original;
			imp_file.ignore();

			if( (!students[count].name.empty()) && (!students[count].lastname.empty()) ) //si ambos campos no estan vacios...
			{
				count++; //cambiar de posicion.
			}
		}
	}
	imp_file.close();
}

void order_view_data(struct student students[100], int ji, int &count)
{
	view_array(students, ji, count); //muestra el arreglo en formato nombre - apellido, esta sobre el final del cpp

	do
	{
		cout << "1. Ordenar por nombre. 2. Ordenar por apellido. 0. Volver al menu principal." << endl;
		cout << endl;
		cout << "3. Orden de entrada." << endl;
		cout << endl;
		cout << " -> ";
		cin >> menu1;
		cin.ignore();
		cout << endl;

		switch(menu1)
	    {
	    	case 1:

	    	order_for_name(students, ji, pos, count, students_aux, a, b);

	    	break;
	    	case 2:

	    	oirder_for_lastname(students, ji, pos, count, students_aux, a, b);

		    break;
		    case 3:

		    order_for_origin(students, ji, pos, count, students_aux);

		    break;
		    case 0:
		    break;
		    default:

		    cout << "No se ingreso una opcion valida. Vuelva a intentar" << endl;
	    }
	}while(menu1!=0);
}

void order_for_name(struct student students[100], int ji, int pos, int &count, struct student students_aux[1], bool &a, bool &b)
{
	b = true;

	if(a == true)
	{
		cout << "---------" << endl;
		cout << "Acendente" << endl;
		cout << "---------" << endl;
		cout << endl;

		for(ji=1; ji <count; ji++)
		{
			pos = ji;

		    while((pos > 0) && (students[pos-1].name > students[pos].name))
		    {
			    students_aux[1] = students[pos];

			    students[pos] = students[pos-1];

			    students[pos-1] = students_aux[1];

			    pos--;
		    }
	    }

	    remplace_data(students, count); //reemplaza txt, funcion al final del cpp

	    view_array(students, ji, count); //muestra el arreglo, sobre el final del cpp

	    a = false;
	    cout << endl;
	}
	else
	{
		cout << "----------" << endl;
		cout << "Decendente" << endl;
		cout << "----------" << endl;
		cout << endl;

		for(ji=1; ji <count; ji++)
		{
			pos = ji;

		    while((pos > 0) && (students[pos-1].name < students[pos].name))
		    {
			    students_aux[1] = students[pos];

			    students[pos] = students[pos-1];

			    students[pos-1] = students_aux[1];

			    pos--;
		    }
	    }

	    remplace_data(students, count); //reemplaza txt, funcion al final del cpp

	    view_array(students, ji, count);

	    a = true;
	    cout << endl;
	}
}

void oirder_for_lastname(struct student students[100], int ji, int pos, int &count, struct student students_aux[1], bool &a, bool &b)
{
	a = true;

	if(b == true)
	{
		cout << "---------" << endl;
		cout << "Acendente" << endl;
		cout << "---------" << endl;
		cout << endl;

		for(ji=1; ji <count; ji++)
	    {
		    pos = ji;

		    while((pos > 0) && (students[pos-1].lastname > students[pos].lastname))
		    {
			    students_aux[1] = students[pos];

			    students[pos] = students[pos-1];

			    students[pos-1] = students_aux[1];

			    pos--;
		    }
	    }

	    remplace_data(students, count);

	    view_array(students, ji, count);

	    b = false;
	    cout << endl;
	}
	else
	{
		cout << "----------" << endl;
		cout << "Decendente" << endl;
		cout << "----------" << endl;
		cout << endl;

		for(ji=1; ji <count; ji++)
	    {
		    pos = ji;

		    while((pos > 0) && (students[pos-1].lastname < students[pos].lastname))
		    {
			    students_aux[1] = students[pos];

			    students[pos] = students[pos-1];

			    students[pos-1] = students_aux[1];

			    pos--;
		    }
	    }

	    remplace_data(students, count);

	    view_array(students, ji, count);

	    b = true;
	    cout << endl;
	}
}

void order_for_origin(struct student students[100], int ji, int pos, int &count, struct student students_aux[1])
{
	for(ji=1; ji <count; ji++)
	{
		pos = ji;

		while((pos > 0) && (students[pos-1].order_original > students[pos].order_original))
		{
			students_aux[1] = students[pos];

			students[pos] = students[pos-1];

			students[pos-1] = students_aux[1];

			pos--;
		}
	}

	remplace_data(students, count);

	view_array(students, ji, count);

	cout << endl;
}

void search_student(struct student students[100], int menu1)
{
	do
	{
		cout << "1. Buscar por nombre." << endl;
		cout << "2. Buscar por apellido." << endl;
		cout << endl;
		cout << "0. volver al menu principal." << endl;
		cout << endl;
		cout << " -> ";
		cin >> menu1;
		cin.ignore();

		switch(menu1)
		{
			case 1:

			search_for_name( count, ji, sname);

			break;
			case 2:

			search_for_lastname( count, ji, sname);

			break;
			case 0:

			break;
			default:

			cout << "No se ingreso una opcion valida. Vuelva a intentar" << endl;
			cout << endl;
		}

	}while(menu1!=0);
}

void search_for_name(int count, int ji, string sname)
{
	cout << "Ingrese el/los nombre/s del estudiante: ";
	getline(cin, sname);
	cout << endl;

	ji = 0;

	while((sname!=students[ji].name) && (ji < count))
	{
		ji++;
	}

	if(sname == students[ji].name)
	{
		cout << "Encontrado! -> " << students[ji].name << " " << students[ji].lastname << endl;
		cout << endl;
	}
	else
	{
		cout << "No se encontro el alumno en la lista." << endl;
		cout << endl;
	}
}

void search_for_lastname( int count, int ji, string sname)
{
	cout << "Ingrese el/los apellido/s del estudiante: ";
	getline(cin, sname);
	cout << endl;

	ji = 0;

	while((sname!=students[ji].lastname) && (ji < count))
	{
		ji++;
	}

	if(sname == students[ji].lastname)
	{
		cout << "Encontrado! -> " << students[ji].lastname << " " << students[ji].name << endl;
		cout << endl;
	}
	else
	{
		cout << "No se encontro el alumno en la lista." << endl;
		cout << endl;
	}
}

void request_data(struct student students[100], int &count)
{
	cout << "Ingrese el/los nombre/s del alumno: ";
	getline(cin, students[count].name);
	cout << "Ingrese el/los apellido/s del alumno: ";
	getline(cin, students[count].lastname);
	students[count].order_original = count;

	ofstream oup_file;
	oup_file.open("students.txt", ios::app);
	if(oup_file.is_open())
	{
		oup_file << students[count].name << endl;
		oup_file << students[count].lastname << endl;
		oup_file << students[count].order_original << endl;
	}
	oup_file.close();

	count++;
	cout << endl;
}

void delate_student(struct student students[100], int ji, int &count, int menu1)
{
	for (ji = 0; ji<count; ji++)
	{
		cout << ji << ". " << students[ji].name << " " << students[ji].lastname << endl;
	}

	cout << endl;
	cout << "Seleccione el alumno a eliminar: ";
	cin >> menu1;
	cin.ignore();

	for(ji = 0; ji < count; ji++)
	{
		if(students[ji].order_original > students[menu1].order_original)
		{
			--students[ji].order_original;
		}
	}

	for(ji = menu1; ji < count; ji++)
	{
		students[ji].name = students[ji+1].name;
		students[ji].lastname = students[ji+1].lastname;
		students[ji].order_original = students[ji+1].order_original;
	}
	count--;
	cout << endl;

	remplace_data(students, count);
	
	view_array(students, ji, count);

	cout << endl;
	cout << "El alumno se elimino exitosamente..." << endl;
	cout << endl;
	cin.get();
}

void view_array(struct student students[100], int ji, int &count)
{
	for (ji = 0; ji<count; ji++)
	{
		cout << students[ji].name << " " << students[ji].lastname << endl;
	}
	cout << endl;
}

void remplace_data(struct student students[100], int &count)
{
	ofstream oup_file;
	oup_file.open("students.txt", ios::out);
	if(oup_file.is_open())
	{
		for(ji=0; ji<count ; ji++)
		{
			oup_file << students[ji].name << endl;
			oup_file << students[ji].lastname << endl;
			oup_file << students[ji].order_original << endl;
		}
	}
	oup_file.close();
}