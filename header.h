#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#ifndef HEADER_H
#define HEADER_H

struct student
{
	string name;
	string lastname;
	int order_original;
};

student students[100];
int menu, menu1, count1, ji, pos, aux_order_o;
string sname;
student students_aux[1];
bool a = true;
bool b = true;

void load_data(struct student students[100], int &count1);
//lee el txt y carga los datos si este no esta vacio

void order_view_data(struct student students[100], int ji, int &count1);
//despliega menu de ordenamiento

void order_for_name(struct student students[100], int ji, int pos, int &count1, struct student students_aux[1], bool &a, bool &b);
//ordena lista por nombre acendente o decendente

void oirder_for_lastname(struct student students[100], int ji, int pos, int &count1, struct student students_aux[1], bool &a, bool &b);
//ordena lista por apellido acendente o decendente

void order_for_origin(struct student students[100], int ji, int pos, int &count1, struct student students_aux[1], bool &a, bool &b);
//ordena por orden de entrada

void search_student(struct student students[100], int menu1);
//despliega menu de busqueda de estudiante especifico

void search_for_name(int count1, int ji, string sname);
//busca estudiante por nombre

void search_for_lastname(int count1, int ji, string sname);
//busca estudiante por apellido

void request_data(struct student students[100], int &count1);
//agrega un estudiante nuevo a la lista y al archivo

void delate_student(struct student students[100], int ji, int &count1, int menu1);
//elimina un estudiante de la lista y del archivo

void view_array(struct student students[100], int ji, int &count1);
//recorre y muestra todo el array

void remplace_data(struct student students[100], int &count1);
//reemplaza el txt en cada momento que se precisa

#endif