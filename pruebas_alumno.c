#include "cola.h"
#include "testing.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>


/* ******************************************************************
 *                   PRUEBAS UNITARIAS ALUMNO
 * *****************************************************************/
 
 void prueba_cola_vacia() {
	printf("\t\tINICIO DE PRUEBAS COLA VACIA\n");
	//Declaro la variable a usar
	cola_t* cola= cola_crear();
	 
	//Inicio las pruebas
	print_test("La cola se creo correctamente", cola != NULL);
	print_test("La cola esta vacia", cola_esta_vacia(cola));
	print_test("Desencolar en una cola vacia", cola_desencolar(cola) == NULL);
	 
	//Destruyo la cola
	cola_destruir(cola, NULL);
	print_test("La cola fue destruida", true);
	printf("\n");
}
 
 void prueba_cola_con_un_elemento() {
	 printf("\t\tINICIO DE PRUEBAS COLA CON UN ELEMENTO\n");
	 //Declaro la variable a usar
	 cola_t* cola= cola_crear();
	 int numero= 130;
	 
	 //Inicio las pruebas
	 print_test("La cola se creo correctamente", cola != NULL);
	 print_test("La cola está vacia", cola_esta_vacia(cola));
	 print_test("Se encolo correctamente", cola_encolar(cola, &numero));
	 print_test("Se desencolo correctamente", cola_desencolar(cola) == &numero);
	 
	 //Destruyo la cola
	 cola_destruir(cola, NULL);
	 print_test("La cola fue destruida", true);
	 printf("\n");
}

void prueba_cola_encolar_NULL() {
	printf("\t\tINICIO DE PRUEBAS COLA ENCOLAR NULL\n");
	//Declaro variables a usar
	cola_t* cola= cola_crear();
	
	//Inicio de pruebas
	print_test("La cola se creo correctamente", cola != NULL);
	print_test("La cola está vacia", cola_esta_vacia(cola));
	print_test("Encolo NULL", cola_encolar(cola, NULL));
	print_test("El primer elemento es NULL", cola_ver_primero(cola) == NULL);
	
	//Destruyo la cola
	cola_destruir(cola, NULL);
	print_test("La cola se destruyo correctamente", true);
	printf("\n");
}
 
void prueba_cola_un_elemento_usando_destruir_datos() {
	printf("\t\tINICIO DE PRUEBAS COLA USANDO DESTRUIR DATOS\n");
	//Declaro variables a usar
	cola_t* cola= cola_crear();
	int* numero= malloc(sizeof(int));
	*numero= 130;
	
	//Inicio pruebas
	print_test("La cola se creo correctamente", cola != NULL);
	print_test("La cola está vacia", cola_esta_vacia(cola));
	print_test("Se encolo correctamente", cola_encolar(cola, numero));
	print_test("El primer elemento es el correcto", cola_ver_primero(cola) == numero);
	
	//Destruyo la cola
	cola_destruir(cola, free);
	print_test("La cola se destruyo correctamente", true);
	printf("\n");
}

void pruebas_cola_varios_elementos() {
	printf("\t\tINICIO DE PRUEBAS CON VARIOS ELEMENTOS\n");
	//Declaro las variables a usar
	cola_t* cola= cola_crear();
	int numeros[10]= {1,2,3,4,5,6,7,8,9,10};
	bool ok= true;
	
	//Inicio de pruebas
	print_test("La cola se creo correctamente", cola != NULL);
	print_test("La cola está vacia", cola_esta_vacia(cola));
	
	for(int i= 0; i < 10; i++) {
		ok &= cola_encolar(cola, numeros+i);
	} 
	
	print_test("Los elementos del vector se encolaron correctamente", ok);
	print_test("El primero es correcto", cola_ver_primero(cola) == numeros);
	
	ok= true;
	for(int i= 0; i < 10; i++) {
		ok &= (cola_desencolar(cola) == numeros+i);
	} 
	
	print_test("Todos los elementos se desencolaron correctamente", ok);
	
	//Destruyo la cola
	cola_destruir(cola, NULL);
	print_test("La cola se destruyo correctamente", true);
	printf("\n");
}

void pruebas_cola_volumen(int tope) {
	printf("\t\tINICIO DE PRUEBAS COLA VOLUMEN\n");
	//Declaro variables a usar
	cola_t* cola= cola_crear();
	int* vector= malloc(sizeof(int)*tope);
	bool ok= true;	
	
	//Inicio pruebas
	print_test("La cola se creo correctamente", cola != NULL);
	print_test("La cola está vacia", cola_esta_vacia(cola));
	
	for(int i= 0; i < tope; i++) {
		vector[i]= i;
		ok &= cola_encolar(cola, &vector[i]);
	}
	
	print_test("Se encolaron correctamente", ok);
	
	ok= true;
	for(int i= 0; i < tope; i++) {
		ok &= (cola_desencolar(cola)== &vector[i]);
	} 
	
	print_test("Se descencolaron 10000 elementos correctamente", ok);
	
	//Destruyo la cola
	free(vector);
	cola_destruir(cola, NULL);
	print_test("La cola se destruyo correctamente", true);
	printf("\n");
}

void pruebas_cola_destruir_datos() {
	printf("\t\tINICIO DE PRUEBAS COLA DESTRUIR DATOS\n");
	//Declaro variables a usar
	cola_t* cola= cola_crear();
	char* abecedario= malloc(sizeof(char)*26);
	int* numeros= malloc(sizeof(int)*10);
	
	//Inicio pruebas
	print_test("La cola se creo correctamente", cola != NULL);
	print_test("La cola esta vacia", cola_esta_vacia(cola));
	print_test("El vector abecedario se encolo correctamente", cola_encolar(cola, abecedario));
	print_test("El vector numeros se encolo correctamente", cola_encolar(cola, numeros));
	
	//Destruyo la cola
	cola_destruir(cola, free);
	print_test("La cola se destruyo correctamente", true);
	printf("\n");
}
 
 void pruebas_cola_alumno() {
	prueba_cola_vacia();
	prueba_cola_con_un_elemento();
	prueba_cola_encolar_NULL();
	prueba_cola_un_elemento_usando_destruir_datos();
	pruebas_cola_varios_elementos();
	pruebas_cola_volumen(10000);
	pruebas_cola_destruir_datos();
}
 
