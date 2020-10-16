#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct student
{
	string name;
	string lastname;
	int order_original;
};

void load_data(struct student students[100], int &count); 
//lee el txt y carga los datos si este no esta vacio

void order_view_data(struct student students[100], int ji, int &count); 
//despliega menu de ordenamiento

void order_for_name(struct student students[100], int ji, int pos, int &count, struct student students_aux[1], bool &a, bool &b);
//ordena por nombre acendente o decendente

void oirder_for_lastname(struct student students[100], int ji, int pos, int &count, struct student students_aux[1], bool &a, bool &b);
//ordena por apellido acendente o decendente

void order_for_origin(struct student students[100], int ji, int pos, int &count, struct student students_aux[1]);
//ordena en orden de entrada

void search_student(struct student students[100], int menu1); 
//despliega menu de busqueda

void search_for_name(int count, int ji, string sname);
//buscar por nombre especifico

void search_for_lastname( int count, int ji, string sname);
//busca por apellido especifico

void request_data(struct student students[100], int &count);
//ingresa nuevo alumno en la lista y archivo

void delate_student(struct student students[100], int ji, int &count, int menu1);
//elimina alumno de la lista y archivo

void view_array(struct student students[100], int ji, int &count);
//muestra el arreglo

void remplace_data(struct student students[100], int &count); 
//reemplaza el txt en cada momento que se precisa - codigo en el final

#endif// STUDENT_H