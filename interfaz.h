#ifndef INTERFAZ
#define INTERFAZ

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct student
{
	string name;
	string lastname;
	int order_original;
};

student students[100];
int menu, menu1, count, ji, pos, aux_order_o;
string sname;
student students_aux[1];
bool a = true;
bool b = true;

void load_data(struct student students[100], int &count);
//lee el txt y carga los datos si este no esta vacio

void order_view_data(struct student students[100], int ji, int &count);
//despliega menu de ordenamiento

void order_for_name(struct student students[100], int ji, int pos, int &count, struct student students_aux[1], bool &a, bool &b);
//ordena lista por nombre acendente o decendente

void oirder_for_lastname(struct student students[100], int ji, int pos, int &count, struct student students_aux[1], bool &a, bool &b);
//ordena lista por apellido acendente o decendente

void order_for_origin(struct student students[100], int ji, int pos, int &count, struct student students_aux[1], bool &a, bool &b);
//ordena por orden de entrada

void search_student(struct student students[100], int menu1);
//despliega menu de busqueda de estudiante especifico

void search_for_name(int count, int ji, string sname);
//busca estudiante por nombre

void search_for_lastname( int count, int ji, string sname);
//busca estudiante por apellido

void request_data(struct student students[100], int &count);
//agrega un estudiante nuevo a la lista y al archivo

void delate_student(struct student students[100], int ji, int &count, int menu1);
//elimina un estudiante de la lista y del archivo

void view_array(struct student students[100], int ji, int &count);
//recorre y muestra todo el array

void remplace_data(struct student students[100], int &count); 
//reemplaza el txt en cada momento que se precisa

#endif