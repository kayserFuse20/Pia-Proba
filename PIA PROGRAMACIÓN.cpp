#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <iostream>
using namespace std;

struct TRATAMIENTO
{
	int ID;
	string NOMBRE, DESCRIPCION;
	double COSTO;
};

struct CITA
{
	int ID, CANTIDAD, ID_TRATAMIENTO;
	char USUARIO[100], HORA[9];
	double PRECIO;
};

struct CITA CITA[100];
struct TRATAMIENTO TRATAMIENTO[100];
int get_ID(int);
void create(struct CITA CITA[100]);
void modify(struct CITA CITA[100]);
void del(struct CITA CITA[100]);
void list(struct CITA CITA[100]);
//void insert_data(struct CITA CITA[100]);

main()
{
	//CREACION DE TRATAMIENTOS
	TRATAMIENTO[1].ID = 1;
	TRATAMIENTO[1].NOMBRE = "Brackets";
	TRATAMIENTO[1].DESCRIPCION = "Tratamiento médico para implantar brackets";
	TRATAMIENTO[1].COSTO = 1500.00;
	
	TRATAMIENTO[2].ID = 2;
	TRATAMIENTO[2].NOMBRE = "Limpieza";
	TRATAMIENTO[2].DESCRIPCION = "Limpieza Dental";
	TRATAMIENTO[2].COSTO = 250.00;
	
	TRATAMIENTO[3].ID = 3;
	TRATAMIENTO[3].NOMBRE = "Coronas";
	TRATAMIENTO[3].DESCRIPCION = "Aplicacion de coronas dentales";
	TRATAMIENTO[3].COSTO = 200.00;
	
	TRATAMIENTO[4].ID = 4;
	TRATAMIENTO[4].NOMBRE = "Empaste";
	TRATAMIENTO[4].DESCRIPCION = "Recuperacion de placa dental por empaste";
	TRATAMIENTO[4].COSTO = 300.00;
	//FIN CREACION TRATAMIENTOS
	
	int menu_select = 0;
	
	do
	{
		
		printf("\n\t MENU PRINCIPAL\n");
		printf("\t --------------\n");
		printf("1. Agendar cita\n");
		printf("2. Modificar cita\n");
		printf("3. Eliminar cita\n");
		printf("4. Listar Citas\n");
		printf("5. Salir\n");
		printf("Digitar respuesta: ");
		fflush(stdin);
		scanf("%d",&menu_select);
		
		switch(menu_select)
		{
			case 1:
				//LLAMADA A FUNCION CREATE() CON PARAMETRO DE TIPO STRUCT PARA CREAR CITA
				create(CITA);
			break;
			
			case 2:
				//LLAMADA A FUNCION MODIFY() CON PARAMETRO DE TIPO STRUCT PARA MODIFICAR CITA
				modify(CITA);
			break;
			
			case 3:
				//LLAMADA A FUNCION DEL() CON PARAMETRO DE TIPO STRUCT PARA ELIMINAR CITA
				del(CITA);
			break;
			
			case 4:
				//LLAMADA A FUNCION MODIFY() CON PARAMETRO DE TIPO STRUCT PARA LISTAR CITAS
				list(CITA);
			break;
			
			case 5:
				menu_select = 5;
				printf("PROCCESING_SYSTEM_EXIT\n");
				Sleep(4500);
				//insert_data(CITA);
			break;
		}
	}
	while (menu_select != 5);
}

void create(struct CITA[100])
{
	int ID = 1, compare = 1, compare2 = 1, set_on = 1, INNER = 1;
	
	system("cls");
	
	//COMPARACION DEL VALOR DE ID PARA OBTENER ULTIMO INDICE REGISTRADO
	
	do
	{
		if(CITA[ID].ID == ID)
		{
			ID++;
		}
		else
		{
			CITA[ID].ID = ID;
			compare = 0;	
		}
	}
	while (compare == 1);
	
	printf("Ingresar nombre de usuario [%d]: ", CITA[ID].ID);
	fflush(stdin);
	gets(CITA[ID].USUARIO);
	
	printf("Ingresar hora de tratamiento para usuario [%d]: ", CITA[ID].ID);
	fflush(stdin);
	gets(CITA[ID].HORA);
	
	printf("\n\t LISTADO DE TRATAMIENTOS DISPONIBLES \n");
	printf("\t ----------------------------------- \n\n");
	
	compare = 1;
	
	do
	{
		do
		{
			if(TRATAMIENTO[INNER].ID != INNER)
			{
				compare = 0;
			}
			else
			{
				cout << "----------------------------------------------------------------------------" << endl;;
				cout << " ID:" << TRATAMIENTO[INNER].ID << " | Tratamiento: " << TRATAMIENTO[INNER].NOMBRE << endl;
				cout << " Costo Unitario: " << TRATAMIENTO[INNER].COSTO << endl;
				cout << "----------------------------------------------------------------------------" << endl;
				INNER++;
			}
			
		}
		while (compare == 1);
	
		printf("\nIngrese tratamiento a elegir (Seleccionar segun por ID): ");
		fflush(stdin);
		scanf("%d",&CITA[ID].ID_TRATAMIENTO);
		
		INNER = 0;
		
		do
		{
			if(CITA[ID].ID_TRATAMIENTO != TRATAMIENTO[INNER].ID)
			{
				compare2 = 1;
				INNER++;
				if(INNER > 20)
				{
					compare2 = 0;
					printf("ERROR_INDEX_NOT_FOUND\n");
					system("pause");
					Sleep(2520);
				}
			}
			else
			{
				compare2 = 0;
			}
		}
		while (compare2 == 1);
		
		if(CITA[ID].ID_TRATAMIENTO == TRATAMIENTO[INNER].ID && INNER < 20)
		{
			set_on = 0;
		}
		else
		{
			set_on = 1;
			printf("Indice no encontrado, verifique ID e intente nuevamente\n");
			system("pause");
			system("cls");
		}
		
		do
		{
			if(INNER < 20)
			{
				compare = 1;
				fflush(stdout);
				
				cout << "Seleccione la cantidad de " << TRATAMIENTO[CITA[ID].ID_TRATAMIENTO].NOMBRE << ": ";
				fflush(stdin);
				scanf("%d",&CITA[ID].CANTIDAD);	
				
				if(CITA[ID].CANTIDAD <= 0)
				{
					printf("\n Valor Invalido, intente nuevamente\n");
					compare = 1;
				}
				else
				{
					printf("Valor guardado correctamente\n");
					system("pause");
					compare = 0;
				}
			}
			else
			{
				compare = 0;
			}
		}
		while (compare == 1);
		
		if(INNER < 20)
		{
			CITA[ID].PRECIO = CITA[ID].CANTIDAD * TRATAMIENTO[CITA[ID].ID_TRATAMIENTO].COSTO;
			fflush(stdout);
			
			cout << "Total a pagar: " << CITA[ID].PRECIO;
			printf("\nRegistrado correctamente...\n");
			system("pause");	
			set_on = 0;
		}
		else
		{
			system("cls");
			printf("INDICE O CODIGO NO ENCONTRADO EN EL REGISTRO");
			Sleep(2500);
			system("cls");
		}		
	}
	while (set_on == 1);
	
	printf("Volviendo al menu principal...\n");
	Sleep(2500);
	
	system("pause");
	system("cls");
}

void modify(struct CITA[100])
{
	int ID = 0, getter = 0, compare = 1, set_on = 1, INNER = 1, compare2 = 0, exit = 0;
	
	system("cls");
	
	printf("\t EDICION DE CITAS\n");
	printf("\t ----------------\n");
	printf("\t LISTADO DE CITAS REGISTRADAS\n");
	
	do
	{
		if(CITA[INNER].ID == INNER)
		{
			fflush(stdout);
			cout << "ID: " << CITA[INNER].ID << endl;
			INNER++;
		}
		else
		{
			compare = 0;
		}
		
	}
	while(compare == 1);
	
	printf("Elegir ID de Cita: ");
	fflush(stdin);
	scanf("%d",&ID);
	
	INNER = 1;
	
	do
	{
		if(CITA[INNER].ID == ID)
		{
			compare2 = 0;
			printf("\nIndice encontrado con exito...");
			Sleep(2500);
		}
		else
		{
			INNER++;
			
			if(INNER > 20)
			{
				compare2 = 0;
				printf("INDEX_NOT_FOUND\n");
				Sleep(1250);
				system("pause");
			}
		}
	}
	while (compare2 == 1);
	
	do
	{
		if(CITA[INNER].ID == ID)
		{
			system("cls");
			printf("\n1. Nombre de Usuario\n");
			printf("2. Hora de Cita\n");
			printf("3. Tratamiento\n");
			printf("4. Salir de modificacion\n");
			printf("Digite su respuesta: ");
			fflush(stdin);
			scanf("%d", &getter);
			
			switch(getter)
			{
				case 1:
					system("cls");
					printf("Inserte nuevo nombre de usuario: ");
					fflush(stdin);
					gets(CITA[INNER].USUARIO);
					printf("\nProcesado Correctamente...");
					Sleep(1500);
					system("pause");
					exit = 0;
				break;
				
				case 2:
					system("cls");
					printf("Inserte nueva hora de cita: ");
					fflush(stdin);
					gets(CITA[INNER].HORA);
					printf("\nProcesado Correctamente...");
					Sleep(1500);
					system("pause");
					exit = 0;
				break;
				
				case 3:
					
					INNER = 1;
					
					do
					{
						if(TRATAMIENTO[INNER].ID != INNER)
						{
							compare = 0;
						}
						else
						{
							cout << "----------------------------------------------------------------------------" << endl;;
							cout << " ID:" << TRATAMIENTO[INNER].ID << " | Tratamiento: " << TRATAMIENTO[INNER].NOMBRE << endl;
							cout << " Costo Unitario: " << TRATAMIENTO[INNER].COSTO << endl;
							cout << "----------------------------------------------------------------------------" << endl;
							INNER++;
						}
						
					}
					while (compare == 1);
					
					
					
					printf("Seleccione nuevo tratamiento: ");
					fflush(stdin);
					scanf("%d",&CITA[INNER].ID_TRATAMIENTO);
					printf("\nProcesado Correctamente...");
					Sleep(1500);
					printf("\nRecalculando Precio...");
					Sleep(2500);
					system("cls");
					
					CITA[INNER].PRECIO = TRATAMIENTO[CITA[INNER].ID_TRATAMIENTO].COSTO * CITA[INNER].CANTIDAD;
					
					printf("-------------------------------------------------------\n");
					cout << "Tratamiento: " << TRATAMIENTO[CITA[INNER].ID_TRATAMIENTO].NOMBRE << endl;
					printf("-------------------------------------------------------\n");
					cout << "Costo: " << TRATAMIENTO[CITA[INNER].ID_TRATAMIENTO].COSTO << endl;
					printf("-------------------------------------------------------\n");
					cout << "Cantidad: " << CITA[INNER].CANTIDAD << endl;
					printf("-------------------------------------------------------\n");
					cout << "Monto total a Pagar: " << CITA[INNER].PRECIO << endl;
					printf("-----------------------------------------\n");
					
					Sleep(1000);
					
					system("pause");
					exit = 1;
				break;
				
				case 4:
					exit = 1;
				break;
			}
		}
		else
		{
			system("cls");
			printf("INDEX_NOT_FOUND\n");
			system("pause");
			exit = 1;
		}
	}
	while(exit != 1);
	
}

void del(struct CITA[100])
{
	int ID = 0, getter = 0, compare = 1, set_on = 1, INNER = 1;
	
	system("cls");
	
	printf("\t ELIMINAR CITA\n");
	printf("\t ----------------\n");
	printf("\t LISTADO DE CITAS REGISTRADAS\n");
	
	do
	{
		if(CITA[INNER].ID == INNER)
		{
			fflush(stdout);
			cout << "ID: " << CITA[INNER].ID;
			INNER++;
		}
		else
		{
			compare = 0;
		}
		
	}
	while(compare == 1);
	
	printf("Elegir ID de Cita: ");
	fflush(stdin);
	scanf("%d",&ID);
	
	system("cls");
	printf("Esta seguro que desea eliminar la cita %d? S/N: ", CITA[INNER].ID);
	fflush(stdin);
	scanf("%d",&getter);
	
	if (getter == 'S' || getter == 's')
	{
		CITA[INNER].CANTIDAD = 0;
		CITA[INNER].HORA == 0;
		CITA[INNER].ID_TRATAMIENTO = 0;
		CITA[INNER].PRECIO = 0;
		CITA[INNER].USUARIO == "";
		CITA[INNER].ID = 1;
	}
	else if (getter == 'N' || getter == 'n')
	{
		printf("\nProceso Cancelado");
		Sleep(4500);
		system("cls");
	}
	else
	{
		system("cls");
		printf("INDEX_NOT_FOUND\n");
		Sleep(3500);
	}
}

void list(struct CITA[100])
{
	int INNER = 1, compare = 1;
	system("cls");
	
	printf("\t LISTADO DE CITAS REGISTRADAS\n");
	
	do
	{
		if(CITA[INNER].ID == INNER)
		{
			fflush(stdout);
			cout << "ID: " << CITA[INNER].ID << " | Hora: " << CITA[INNER].HORA << endl;
			cout << "Usuario: " << CITA[INNER].USUARIO << " | Total Pagado: " << CITA[INNER].PRECIO << endl;
			INNER++;
		}
		else
		{
			compare = 0;
		}
		
	}
	while(compare == 1);
	
	system("\npause");
}

/*
void insert_data(struct CITA[100])
{
	int INNER = 1, compare = 1;
	
	const char* rute = "data.txt";
	
	FILE* file = fopen(rute, "w+");
	
	const char* info;
	
	size_t lenght = strlen(info);
	
	do
	{
		if(CITA[INNER].ID == INNER)
		{
			fflush(stdout);
			info = cout << "ID: " << CITA[INNER].ID << " | Hora: " << CITA[INNER].HORA << endl << "Usuario: " << CITA[INNER].USUARIO << "| Total Pagado: " << CITA[INNER].PRECIO;
			fwrite(info, lenght, 1, file);
			INNER++;
		}
		else
		{
			compare = 0;
		}
		
	}
	while(compare == 1);
	
	
	
	fclose(file);
	
	system("exit");
}
*/

