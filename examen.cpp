#include <iostream>
#include <stdlib.h>
#include <string>
#include <windows.h> //cambiar color :D
#define color SetConsoleTextAttribute
using namespace std;
class Estudiante{
	private:
		int codigo;
		string nombres,apellidos,curso,aprobacion;
		int nota1,nota2,nota3,nota4;
		float promedio;	
	public:
		Estudiante(){
			this->codigo=0;
			this->nombres="";
			this->apellidos="";
			this->curso="";
			this->nota1=0;
			this->nota2=0;
			this->nota3=0;
			this->nota4=0;
			this->promedio=0;
			this->aprobacion="";
		}
		void getEstudiante(int _codigo,string _nombres,string _apellidos,string _curso,int _nota1,int _nota2,int _nota3,int _nota4,float _promedio,string _aprobacion){
			this->codigo=_codigo;
			this->nombres=_nombres;
			this->apellidos=_apellidos;
			this->curso=_curso;
			this->nota1=_nota1;
			this->nota2=_nota2;
			this->nota3=_nota3;
			this->nota4=_nota4;
			this->promedio=_promedio;
			this->aprobacion=_aprobacion;
		}
		
		string setEstudiante (){
			return " " + to_string (this->codigo) + "    " + this->nombres + "    " + this->apellidos + "    " + this->curso + "    " + to_string (this->nota1) + "    " + to_string (this->nota2) + "    " + to_string (this->nota3)+"    " + to_string (this->nota4) + "    " + to_string (this->promedio) + "    " + this->aprobacion;
		}

};


int main(){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int ne;
	int contador=0;
	char continuar;
	//registrar datos
	int codigo;
	string nombres,apellidos,curso,aprobacion;
	int nota1,nota2,nota3,nota4;
	float promedio;	
	color(hConsole,3);
	
	do{
		system("cls");
		//Mensaje Inserción estudiantees
		cout<<"----------------------- Bienvenido al registro de notas :D-----------------------\n \n";
		cout<<"¿Las notas de cuantos estudiantes piensa ingresar?: ";
		cin>>ne;	
		Estudiante estudiante[ne] = Estudiante();
		do{
			system("cls");
			cout<<"-------------Insercion de datos alumno------------- \n";
			cout<<"Codigo:(N.) ";//Código numero
			cin>>codigo;
			cout<<"Nombres:";
			cin>>nombres;
			cout<<"Apellidos: ";
			cin>>apellidos;
			cout<<"Curso: ";
			cin>>curso;
			cout<<"Nota I: ";
			cin>>nota1;
			cout<<"Nota II: ";
			cin>>nota2;
			cout<<"Nota III: ";
			cin>>nota3;
			cout<<"Nota IV: ";
			cin>>nota4;
			promedio=(nota1+nota2+nota3+nota4)/4;
			if (promedio>=60){
				aprobacion="Aprobrado";
			}else{
				aprobacion="Reprobado";
			}
			estudiante[contador].getEstudiante(codigo,nombres,apellidos,curso,nota1,nota2,nota3,nota4,promedio,aprobacion);
			contador++;
			
		}while(contador<ne);
		
		system("cls");
		color(hConsole,14);
		cout<<"------Reporte de Notas-------\n";
		cout<<"Codigo    Nombres	Apellidos	Curso  Nota I NotaII NotaIII NotaIV Promedio Aprobacion\n";
		for(int i=0; i<ne;i++){
			cout<<estudiante[i].setEstudiante()<<endl;
		}
		cout<<" \n";
		cout<<"¿Desea repetir la operación? S/N: ";
		cin>>continuar;

	}while(continuar=='S');
	
}
