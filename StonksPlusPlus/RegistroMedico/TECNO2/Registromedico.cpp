#include "Registromedico.h"
#include <iostream>
Registromedico::Registromedico(){
    inicio = NULL;
    final = NULL;
}
Registromedico::~Registromedico(){}
bool Registromedico::esFechaValida(string& fecha) {

    if (fecha.size() != 8) {
        return false;
    }


    string diaStr = fecha.substr(0, 2);
    string mesStr = fecha.substr(3, 2);
    string anioStr = fecha.substr(7, 2);

    int dia = stoi(diaStr);
    int mes = stoi(mesStr);
    int anio = stoi(anioStr);

    bool esBisiesto = (anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0;



    return ((dia <= 30 && (mes == 4 || mes == 9 || mes == 6 || mes == 11)) ||
        (esBisiesto && dia <= 29 && mes == 2) ||
        (!esBisiesto && dia <= 28 && mes == 2) ||
        (((mes == 1) || (mes == 3) || (mes == 5) || (mes == 7) || (mes == 8) || (mes == 10) || (mes == 12)) && (dia <= 31) || mes > 12 || mes < 1 || dia < 1));

}
void Registromedico::Registromedico::agregarcita(){
 
        
        string f, t, d;
        w.changealignedment("center");
        w.write("AGREGAR CITA");
        cout << endl;
        w.changealignedment("left");
        w.write("Ingrese la fecha de la cita (DD/MM/AA): ");
        cin >> f;
        if (!esFechaValida(f)) {
            w.write("La fecha ingresada no es válida.");
            cout << endl;
            return;
        }
        w.changealignedment("center");
        w.write("Ingrese el tipo de cita: ");
        cin >> t;
        cin.ignore();
        w.changealignedment("right");
        w.write("Ingrese la descripción de la cita: ");
        getline(cin, d);

        Registro cita(f, t, d);

        NodoReg* nuevo = new NodoReg;
        nuevo->dato = cita;
        nuevo->sig = nullptr;

        if (inicio == nullptr) {
            final = inicio = nuevo;
        }
        else {
           
            int diaN = stoi(f.substr(0, 2));
            int mesN = stoi(f.substr(3, 2));
            int anioN = stoi(f.substr(6, 2));

        
            NodoReg* actual = inicio;
            NodoReg* anterior = nullptr;
            while (actual) {
                int diaA = stoi(actual->dato.fecha.substr(0, 2));
                int mesA = stoi(actual->dato.fecha.substr(3, 2));
                int anioA = stoi(actual->dato.fecha.substr(6, 2));

                if (anioA > anioN || (anioA == anioN && (mesA > mesN || (mesA == mesN && diaA > diaN)))) {
                    break; 
                }
                anterior = actual;
                actual = actual->sig;
            }

            if (anterior == nullptr) {
                nuevo->sig = inicio;
                inicio = nuevo;
            }
            else {
                nuevo->sig = actual;
                anterior->sig = nuevo;
                if (actual == nullptr) {
                    final = nuevo; 
                }
            }
        }

        w.write("La cita ha sido agregada.");
        cout << endl;
    }

void Registromedico::vercitas() 
    {
        w.changealignedment("center");
        w.write("VER CITAS");
        cout << endl;
        w.changealignedment("left");

        NodoReg* actual = inicio;
        int num = 1;
        while (actual) {
            w.changealignedment("center");
            w.write("CITA"); cout << num;
            w.changealignedment("left");
            w.write("Fecha: ");
            cout << actual->dato.fecha <<
                w.changealignedment("center");
            w.write("Tipo: ");
            cout << actual->dato.tipo;
            w.write("Descripcion: ");
            cout << actual->dato.descripcion << endl;
            cout <<" "<< endl; 
            actual = actual->sig;
            num++;
        }

        if (inicio == nullptr) {
            w.write("No hay citas registradas.");
        }
        cout << endl;
    }

void Registromedico::buscarcita() 
  
    {
        w.changealignedment("center");
        w.write("BUSCAR CITA");
        cout << endl;
        w.changealignedment("left");
        w.write("¿Desea buscar por fecha (F) o por tipo de cita (T)? ");
        char opcion;
        cin >> opcion;
        opcion = toupper(opcion);

        string terminoBusqueda;
        if (opcion == 'F') {
            w.write("Ingrese la fecha de la cita a buscar (DD/MM/AA): ");
            cin >> terminoBusqueda;
        }
        else if (opcion == 'T') {
            w.write("Ingrese el tipo de cita a buscar: ");
            cin >> terminoBusqueda;
        }
        else {
            w.write("Opción no válida.");
            cout << endl;
            return;
        }

        NodoReg* actual = inicio;
        bool encontrado = false;
        while (actual) {
            if ((opcion == 'F' && actual->dato.fecha == terminoBusqueda) ||
                (opcion == 'T' && actual->dato.tipo == terminoBusqueda)) {
                w.changealignedment("left");
                w.write("Fecha: ");
                cout << actual->dato.fecha;
                w.changealignedment("center");
                w.write("Tipo: ");
                cout << actual->dato.tipo;
                w.changealignedment("right");
                w.write("Descripción: ");
                cout << actual->dato.descripcion;
                w.write(""); 
                encontrado = true;
            }
            actual = actual->sig;
        }

        if (!encontrado) {
            w.changealignedment("center");
            w.write("No se encontraron citas que coincidan con la búsqueda.");
        }
        cout << endl;
    }