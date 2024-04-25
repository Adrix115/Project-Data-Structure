#include "Listarec.h"

void Listarec:: set_usuario(Users usuario) {
	this->usuario = usuario;
}
Listarec::Listarec() {
	inicio = final = NULL;
}
Listarec::~Listarec() {
	NodoR* aux = inicio;
	while (aux)
	{
		NodoR* temp = aux;
		aux = aux->sig;
		delete temp;
	}
}
bool Listarec::esFechaValida(string& fecha) {
	
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
void Listarec::nuevorecordatorio() {
	Recordatorio rec;
	string f;
	w.changealignedment("center");
	w.write("NUEVO RECORDATORIO");
	cout << endl;
	w.changealignedment("left");
	w.write("Ingrese la fecha del nuevo recordatorio  (En formato DD/MM/AA): ");
	cin >> f;
	if (esFechaValida(f)) {
		rec.fecha = f;
		w.write("Ingrese el nombre del nuevo recordatorio: ");
		cin.ignore();
		getline(cin, rec.nombre);
		string d;
		
		do {
			w.write("Ingrese la descripción del nuevo recordatorio: ");
			getline(cin, d);
			if (d.length() > 50 && usuario.userType == 0) {
				w.changealignedment("center");
				w.write("SUSCRIBASE PARA TENER MAS DE 50 CARACTERES");
				cout << endl;
			}
		} while (d.length() > 50 && usuario.userType == 0);
		rec.descripcion = d;
		
		rec.completado = false;
		NodoR* nuevo = new NodoR;
		nuevo->dato = rec;
		if (inicio == NULL) {
			final = inicio = nuevo;
		}
		else {
			final->sig = nuevo;
			final = nuevo;
		}
		w.write("El recodatorio ha sido guardado");
		cout << endl;
	}
	else {
		w.changealignedment("center");
		w.write("LA FECHA NO ES VALIDA O NO SIGUE EL FORMATO");
		cout << endl;
	}


}
void Listarec::mostrarrecordatorios() {
	NodoR* aux = inicio;
	if (aux == nullptr) {
		w.write("No hay recordatorios para mostrar.");
		return;
	}
	int c = 0;
	while (aux ){
		if (aux->dato.completado == false) {
			w.changealignedment("center");
			w.write("RECORDATORIOS"); cout << endl;
			w.write("RECORDATORIO N"); cout << c + 1;
			w.changealignedment("left");
			w.write("Fecha: ");

			cout << aux->dato.fecha << endl;
			w.write("Nombre: ");
			cout << aux->dato.nombre << endl;
			w.write("Descripcion: ");
			cout << aux->dato.descripcion << endl;
			cout << endl;
			c++;
		}
		aux = aux->sig;
		
	}
}

void Listarec::modificarrecordatorios() {
	mostrarrecordatorios();
	int n;
	w.write("Ingrese el numero de recordatorio que desea modificar: ");
	cin >> n;
	NodoR* aux = inicio;
	for (int i = 0; i < n-1  && aux != NULL; i++) {
		aux = aux->sig;
	}
	string f;
	w.write("Ingrese la fecha modificada del recordatorio  (En formato DD/MM/AA): ");
	cin >> f;
	if (esFechaValida(f)) {
		aux->dato.fecha = f;
		w.write("Ingrese el nombre modificado del  recordatorio: ");
		cin.ignore();
		getline(cin, aux->dato.nombre);
		w.write("Ingrese la descripcion modificada del recordatorio: ");
		getline(cin, aux->dato.descripcion);
		w.write("Las modificaciones han sido guardadas"); 
		cout << endl;
	}
	else {
		w.write("La fecha no es valida o no cumple el formato");
		cout << endl;
	}


}
void Listarec::eliminarrecdordatorio() {
	mostrarrecordatorios();

	int n;
	w.write("Ingrese el numero de recordatorio que desea eliminar: ");
	cin >> n;

	if (inicio == nullptr) {
		w.write("La lista de recordatorios está vacía.");
		return;
	}

	if (n == 1) {
		NodoR* temp = inicio;
		inicio = inicio->sig;
		delete temp;
		w.write("El recordatorio ha sido eliminado.");
		return;
	}

	NodoR* anterior = inicio;
	for (int i = 1; i < n - 1 && anterior != nullptr; i++) {
		anterior = anterior->sig;
	}

	if (anterior == nullptr || anterior->sig == nullptr) {
		w.write("El número de recordatorio ingresado es inválido.");
		return;
	}

	NodoR* temp = anterior->sig;
	anterior->sig = temp->sig;
	delete temp;
	w.write("El recordatorio ha sido eliminado.");

}
void Listarec::marcarcompletado() {
	mostrarrecordatorios();
	int n;
	w.write("Ingrese el numero de recordatorio que desea marcar como completado: ");
	cin >> n;
	NodoR* aux = inicio;
	for (int i = 0; i < n - 1&& aux != NULL; i++) {
		aux = aux->sig;
	}
	if (aux != nullptr) {
		aux->dato.completado = true;
		w.write("El recordatorio ha sido marcado como completado.");
	}
	else {
		w.write("El número de recordatorio ingresado es inválido.");
	}
}
void Listarec::priorizar() {
	if (usuario.userType == 0) {
		w.changealignedment("center");
		w.write(" PARA ESTA FUNCION, DEBES SER UN USUARIO PREMIUM, SUSCRIBETE! :)");
		cout << endl;
		return;
	}
	else {
		mostrarrecordatorios();

		int n;
		w.write("Ingrese el numero de recordatorio que desea priorizar: ");
		cin >> n;

		if (n < 1) {
			w.write("El número de recordatorio ingresado es inválido.");
			return;
		}

		NodoR* actual = inicio;
		NodoR* anterior = nullptr;
		for (int i = 1; i < n && actual != nullptr; i++) {
			anterior = actual;
			actual = actual->sig;
		}

		if (actual == nullptr) {
			w.write("El número de recordatorio ingresado es inválido.");
			return;
		}

		if (anterior == nullptr) {
			w.write("El recordatorio ya está al principio de la lista.");
			return;
		}

		anterior->sig = actual->sig;
		actual->sig = inicio;
		inicio = actual;

		if (actual->sig == nullptr) {
			final = anterior;
		}

		w.write("El recordatorio ha sido priorizado.");

	}
}