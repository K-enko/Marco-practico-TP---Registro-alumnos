#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct student
{
	string name;
	string lastname;
};

student students[100];
int menu, menu1, count, ji;
string sname;

//enum alfabeto{a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z};

void load_data(struct student students[100], int &count);
void order_view_data(struct student students[100], int ji, int &count);
void search_student(struct student students[100], int menu1);
void search_for_name(int count, int ji, string sname);
void search_for_lastname( int count, int ji, string sname);
//void order_name(struct student students[100], int &count);
void request_data(struct student students[100], int &count);
void delate_student(struct student students[100], int ji, int &count, int menu1);

int main()
{
	do
	{
		load_data(students, count); //cargar datos de nuestro txt...

		cout << "1. Mostrar listado de los alumnos en pantalla." << endl;
	    cout << "2. Mostrar un alumno determinado." << endl;
	    cout << "3. Insertar un alumno a la lista." << endl;
	    cout << "4. Eliminar un alumno de la lista." << endl;
	    cout << "5. Buscar un alumno." << endl;
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

	    	order_view_data(students, ji, count);

	    	break;
	    	case 2:

	    	search_student(students, menu1);

	    	break;
		    case 3:

		    if(count < 100) //si contador es menor al maximo de alumnos...
		    {
		    	request_data(students, count); //pedir y guardar los datos.
		    }

		    break;
		    case 4:

		    delate_student(students, ji,count, menu1);

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
	for (ji = 0; ji<count; ji++)
	{
		cout << students[ji].name << " " << students[ji].lastname << endl;
	}

	cout << endl;

	/*cout << "1. Ordenar por nombre. 2. Ordenar por apellido. 0. Volver al menu principal." << endl;

	switch(menu1)
	{
		case 1:

		break;
		case 2:
		break;
		case 0:
		break;
		default:

		cout << "No se ingreso una opcion valida. Vuelva a intentar" << endl;
	}*/
}

/*void order_name(struct student students[100], enum alfabeto, int &count)
{
	for(int ji=0; ji <=count; ji++)
	{

	}
}*/

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

	ofstream oup_file;
	oup_file.open("students.txt", ios::app);
	if(oup_file.is_open())
	{
		oup_file << students[count].name << endl;
		oup_file << students[count].lastname << endl;
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

	for(ji = menu1; ji < count; ji++)
	{
		students[ji].name = students[ji+1].name;
		students[ji].lastname = students[ji+1].lastname;
	}
	count--;

	ofstream oup_file2;
	oup_file2.open("students.txt", ios::out);
	if(oup_file2.is_open())
	{
		for(ji=0; ji<count ; ji++)
		{
			oup_file2 << students[ji].name << endl;
			oup_file2 << students[ji].lastname << endl;
		}
	}
	oup_file2.close();

	for (ji = 0; ji<count; ji++)
	{
		cout << ji << ". " << students[ji].name << " " << students[ji].lastname << endl;
	}

	cout << endl;
	cout << "El alumno se elimino exitosamente..." << endl;
	cout << endl;
	cin.get();
}