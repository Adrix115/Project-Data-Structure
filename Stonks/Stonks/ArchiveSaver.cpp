#include "ArchiveSaver.h"

// Constructor
ArchiveSaver::ArchiveSaver(String^ filePath) : direccion(filePath), inicio(nullptr), fin(nullptr) {
    Cargar();
}

// Destructor
ArchiveSaver::~ArchiveSaver() {
    Guardar();
    Nodo^ actual = inicio;
    while (actual != nullptr) {
        Nodo^ siguiente = actual->siguiente;
        delete actual;
        actual = siguiente;
    }
}

// Método para alta de usuario
void ArchiveSaver::Alta(Usuario^ user) {
    // Asignar ID único
    int maxID = 0;
    Nodo^ aux = inicio;
    while (aux != nullptr) {
        if (aux->usuario->ID > maxID) {
            maxID = aux->usuario->ID;
        }
        aux = aux->siguiente;
    }
    user->ID = maxID + 1;

    Nodo^ nuevoNodo = gcnew Nodo(user);
    if (fin == nullptr) {
        inicio = fin = nuevoNodo;
    }
    else {
        fin->siguiente = nuevoNodo;
        fin = nuevoNodo;
    }
    Guardar();
}

// Métodos para alta de recordatorio
void ArchiveSaver::AltaRecordatorio(Recordatorio^ recordatorio) {
    // Asignar ID único
    int maxID = 0;
    Nodo^ aux = inicio;
    while (aux != nullptr) {
        if (aux->recordatorio->ID > maxID) {
            maxID = aux->recordatorio->ID;
        }
        aux = aux->siguiente;
    }
    recordatorio->ID = maxID + 1;

    Nodo^ nuevoNodo = gcnew Nodo(recordatorio);
    if (fin == nullptr) {
        inicio = fin = nuevoNodo;
    }
    else {
        fin->siguiente = nuevoNodo;
        fin = nuevoNodo;
    }
    Guardar();
}

// Métodos para alta de seguimiento
void ArchiveSaver::AltaSeguimiento(Seguimiento^ seguimiento) {
    // Asignar ID único
    int maxID = 0;
    Nodo^ aux = inicio;
    while (aux != nullptr) {
        if (aux->seguimiento->contadorId > maxID) {
            maxID = aux->seguimiento->contadorId;
        }
        aux = aux->siguiente;
    }
    seguimiento->contadorId = maxID + 1;

    Nodo^ nuevoNodo = gcnew Nodo(seguimiento);
    if (fin == nullptr) {
        inicio = fin = nuevoNodo;
    }
    else {
        fin->siguiente = nuevoNodo;
        fin = nuevoNodo;
    }
    Guardar();
}

// Métodos para alta de registro
void ArchiveSaver::AltaRegistro(Registro^ registro) {
    // Asignar ID único
    int maxID = 0;
    Nodo^ aux = inicio;
    while (aux != nullptr) {
        if (aux->registro->id > maxID) {
            maxID = aux->registro->id;
        }
        aux = aux->siguiente;
    }
    registro->id = maxID + 1;

    Nodo^ nuevoNodo = gcnew Nodo(registro);
    if (fin == nullptr) {
        inicio = fin = nuevoNodo;
    }
    else {
        fin->siguiente = nuevoNodo;
        fin = nuevoNodo;
    }
    Guardar();
}

// Método para baja de usuario (borrado lógico)
void ArchiveSaver::Baja(int id) {
    Nodo^ aux = inicio;
    while (aux != nullptr) {
        if (aux->usuario->ID == id) {
            aux->usuario->Visible = false;  // Borrado lógico
            break;
        }
        aux = aux->siguiente;
    }
    Guardar();
}

// Método para baja de recordatorio (borrado lógico)
void ArchiveSaver::BajaRecordatorio(int id) {
    Nodo^ aux = inicio;
    while (aux != nullptr) {
        if (aux->recordatorio->ID == id) {
            aux->recordatorio->completado = true;  // Borrado lógico
            break;
        }
        aux = aux->siguiente;
    }
    Guardar();
}

// Método para baja de seguimiento (borrado lógico)
void ArchiveSaver::BajaSeguimiento(int id) {
    Nodo^ aux = inicio;
    while (aux != nullptr) {
        if (aux->seguimiento->contadorId == id) {
            aux->seguimiento->visible = false;  // Borrado lógico
            break;
        }
        aux = aux->siguiente;
    }
    Guardar();
}

// Método para baja de registro (borrado lógico)
void ArchiveSaver::BajaRegistro(int id) {
    Nodo^ aux = inicio;
    while (aux != nullptr) {
        if (aux->registro->id == id) {
            aux->registro->visible = false;  // Borrado lógico
            break;
        }
        aux = aux->siguiente;
    }
    Guardar();
}

// Método para modificar usuario
void ArchiveSaver::Modificar(Usuario^ user, int id) {
    Nodo^ aux = inicio;
    while (aux != nullptr) {
        if (aux->usuario->ID == id) {
            aux->usuario->Username = user->Username;
            aux->usuario->Email = user->Email;
            aux->usuario->Password = user->Password;
            aux->usuario->Visible = user->Visible;
            break;
        }
        aux = aux->siguiente;
    }
    Guardar();
}

// Método para modificar recordatorio
void ArchiveSaver::ModificarRecordatorio(Recordatorio^ recordatorio, int id) {
    Nodo^ aux = inicio;
    while (aux != nullptr) {
        if (aux->recordatorio->ID == id) {
            aux->recordatorio->nombre = recordatorio->nombre;
            aux->recordatorio->descripcion = recordatorio->descripcion;
            aux->recordatorio->fecha = recordatorio->fecha;
            aux->recordatorio->completado = recordatorio->completado;
            break;
        }
        aux = aux->siguiente;
    }
    Guardar();
}

// Método para modificar seguimiento
void ArchiveSaver::ModificarSeguimiento(Seguimiento^ seguimiento, int id) {
    Nodo^ aux = inicio;
    while (aux != nullptr) {
        if (aux->seguimiento->contadorId == id) {
            aux->seguimiento->fecha = seguimiento->fecha;
            aux->seguimiento->descripcion = seguimiento->descripcion;
            aux->seguimiento->visible = seguimiento->visible;
            break;
        }
        aux = aux->siguiente;
    }
    Guardar();
}

// Método para modificar registro
void ArchiveSaver::ModificarRegistro(Registro^ registro, int id) {
    Nodo^ aux = inicio;
    while (aux != nullptr) {
        if (aux->registro->id == id) {
            aux->registro->fecha = registro->fecha;
            aux->registro->doctor = registro->doctor;
            aux->registro->especialidad = registro->especialidad;
            aux->registro->descripcion = registro->descripcion;
            aux->registro->visible = registro->visible;
            break;
        }
        aux = aux->siguiente;
    }
    Guardar();
}

// Método para consultar un usuario
void ArchiveSaver::Consultar(int id) {
    Nodo^ aux = inicio;
    while (aux != nullptr) {
        if (aux->usuario->ID == id && aux->usuario->Visible) {
            Console::WriteLine("ID: " + aux->usuario->ID);
            Console::WriteLine("Username: " + aux->usuario->Username);
            Console::WriteLine("Email: " + aux->usuario->Email);
            Console::WriteLine("Password: " + aux->usuario->Password);
            Console::WriteLine("Visible: " + aux->usuario->Visible);
            return;
        }
        aux = aux->siguiente;
    }
    Console::WriteLine("Usuario no encontrado.");
}

// Método para consultar un recordatorio
void ArchiveSaver::ConsultarRecordatorio(int id) {
    Nodo^ aux = inicio;
    while (aux != nullptr) {
        if (aux->recordatorio->ID == id && !aux->recordatorio->completado) {
            Console::WriteLine("ID: " + aux->recordatorio->ID);
            Console::WriteLine("Nombre: " + aux->recordatorio->nombre);
            Console::WriteLine("Descripción: " + aux->recordatorio->descripcion);
            Console::WriteLine("Fecha: " + aux->recordatorio->fecha);
            Console::WriteLine("Completado: " + aux->recordatorio->completado);
            return;
        }
        aux = aux->siguiente;
    }
    Console::WriteLine("Recordatorio no encontrado.");
}

// Método para consultar un seguimiento
void ArchiveSaver::ConsultarSeguimiento(int id) {
    Nodo^ aux = inicio;
    while (aux != nullptr) {
        if (aux->seguimiento->contadorId == id && aux->seguimiento->visible) {
            Console::WriteLine("ID: " + aux->seguimiento->contadorId);
            Console::WriteLine("Fecha: " + aux->seguimiento->fecha);
            Console::WriteLine("Descripción: " + aux->seguimiento->descripcion);
            Console::WriteLine("Visible: " + aux->seguimiento->visible);
            return;
        }
        aux = aux->siguiente;
    }
    Console::WriteLine("Seguimiento no encontrado.");
}

// Método para consultar un registro
void ArchiveSaver::ConsultarRegistro(int id) {
    Nodo^ aux = inicio;
    while (aux != nullptr) {
        if (aux->registro->id == id && aux->registro->visible) {
            Console::WriteLine("ID: " + aux->registro->id);
            Console::WriteLine("Fecha: " + aux->registro->fecha);
            Console::WriteLine("Doctor: " + aux->registro->doctor);
            Console::WriteLine("Especialidad: " + aux->registro->especialidad);
            Console::WriteLine("Descripción: " + aux->registro->descripcion);
            Console::WriteLine("Visible: " + aux->registro->visible);
            return;
        }
        aux = aux->siguiente;
    }
    Console::WriteLine("Registro no encontrado.");
}

// Método para listar todos los usuarios
void ArchiveSaver::Listar() {
    Nodo^ aux = inicio;
    while (aux != nullptr) {
        if (aux->usuario->Visible) {
            Console::WriteLine("ID: " + aux->usuario->ID);
            Console::WriteLine("Username: " + aux->usuario->Username);
            Console::WriteLine("Email: " + aux->usuario->Email);
            Console::WriteLine("Password: " + aux->usuario->Password);
            Console::WriteLine("Visible: " + aux->usuario->Visible);
            Console::WriteLine("---------------------------");
        }
        aux = aux->siguiente;
    }
}

// Método para listar todos los recordatorios
void ArchiveSaver::ListarRecordatorios() {
    Nodo^ aux = inicio;
    while (aux != nullptr) {
        if (!aux->recordatorio->completado) {
            Console::WriteLine("ID: " + aux->recordatorio->ID);
            Console::WriteLine("Nombre: " + aux->recordatorio->nombre);
            Console::WriteLine("Descripción: " + aux->recordatorio->descripcion);
            Console::WriteLine("Fecha: " + aux->recordatorio->fecha);
            Console::WriteLine("Completado: " + aux->recordatorio->completado);
            Console::WriteLine("---------------------------");
        }
        aux = aux->siguiente;
    }
}

// Método para listar todos los seguimientos
void ArchiveSaver::ListarSeguimientos() {
    Nodo^ aux = inicio;
    while (aux != nullptr) {
        if (aux->seguimiento->visible) {
            Console::WriteLine("ID: " + aux->seguimiento->contadorId);
            Console::WriteLine("Fecha: " + aux->seguimiento->fecha);
            Console::WriteLine("Descripción: " + aux->seguimiento->descripcion);
            Console::WriteLine("Visible: " + aux->seguimiento->visible);
            Console::WriteLine("---------------------------");
        }
        aux = aux->siguiente;
    }
}

// Método para listar todos los registros
void ArchiveSaver::ListarRegistros() {
    Nodo^ aux = inicio;
    while (aux != nullptr) {
        if (aux->registro->visible) {
            Console::WriteLine("ID: " + aux->registro->id);
            Console::WriteLine("Fecha: " + aux->registro->fecha);
            Console::WriteLine("Doctor: " + aux->registro->doctor);
            Console::WriteLine("Especialidad: " + aux->registro->especialidad);
            Console::WriteLine("Descripción: " + aux->registro->descripcion);
            Console::WriteLine("Visible: " + aux->registro->visible);
            Console::WriteLine("---------------------------");
        }
        aux = aux->siguiente;
    }
}

// Método para cargar los datos desde el archivo
void ArchiveSaver::Cargar() {
    if (!File::Exists(direccion)) {
        return;
    }

    FileStream^ fileStream = nullptr;
    StreamReader^ reader = nullptr;

    try {
        fileStream = gcnew FileStream(direccion, FileMode::Open);
        reader = gcnew StreamReader(fileStream);

        while (!reader->EndOfStream) {
            String^ tipo = reader->ReadLine();
            if (tipo == "Usuario") {
                Usuario^ user = gcnew Usuario();
                user->ID = Int32::Parse(reader->ReadLine());
                user->Username = reader->ReadLine();
                user->Email = reader->ReadLine();
                user->Password = reader->ReadLine();
                user->Visible = Boolean::Parse(reader->ReadLine());

                Nodo^ nuevoNodo = gcnew Nodo(user);
                if (fin == nullptr) {
                    inicio = fin = nuevoNodo;
                }
                else {
                    fin->siguiente = nuevoNodo;
                    fin = nuevoNodo;
                }
            }
            else if (tipo == "Recordatorio") {
                Recordatorio^ recordatorio = gcnew Recordatorio("", "", "", false);
                recordatorio->ID = Int32::Parse(reader->ReadLine());
                recordatorio->nombre = reader->ReadLine();
                recordatorio->descripcion = reader->ReadLine();
                recordatorio->fecha = reader->ReadLine();
                recordatorio->completado = Boolean::Parse(reader->ReadLine());

                Nodo^ nuevoNodo = gcnew Nodo(recordatorio);
                if (fin == nullptr) {
                    inicio = fin = nuevoNodo;
                }
                else {
                    fin->siguiente = nuevoNodo;
                    fin = nuevoNodo;
                }
            }
            else if (tipo == "Seguimiento") {
                Seguimiento^ seguimiento = gcnew Seguimiento("", "");
                seguimiento->contadorId = Int32::Parse(reader->ReadLine());
                seguimiento->fecha = reader->ReadLine();
                seguimiento->descripcion = reader->ReadLine();
                seguimiento->visible = Boolean::Parse(reader->ReadLine());

                Nodo^ nuevoNodo = gcnew Nodo(seguimiento);
                if (fin == nullptr) {
                    inicio = fin = nuevoNodo;
                }
                else {
                    fin->siguiente = nuevoNodo;
                    fin = nuevoNodo;
                }
            }
            else if (tipo == "Registro") {
                Registro^ registro = gcnew Registro("", "", "", "");
                registro->id = Int32::Parse(reader->ReadLine());
                registro->fecha = reader->ReadLine();
                registro->doctor = reader->ReadLine();
                registro->especialidad = reader->ReadLine();
                registro->descripcion = reader->ReadLine();
                registro->visible = Boolean::Parse(reader->ReadLine());

                Nodo^ nuevoNodo = gcnew Nodo(registro);
                if (fin == nullptr) {
                    inicio = fin = nuevoNodo;
                }
                else {
                    fin->siguiente = nuevoNodo;
                    fin = nuevoNodo;
                }
            }
        }
    }
    finally {
        if (reader != nullptr) {
            reader->Close();
        }
        if (fileStream != nullptr) {
            fileStream->Close();
        }
    }
}

// Método para guardar los datos en el archivo
void ArchiveSaver::Guardar() {
    FileStream^ fileStream = nullptr;
    StreamWriter^ writer = nullptr;

    try {
        fileStream = gcnew FileStream(direccion, FileMode::Create);
        writer = gcnew StreamWriter(fileStream);

        Nodo^ aux = inicio;
        while (aux != nullptr) {
            if (aux->usuario != nullptr) {
                writer->WriteLine("Usuario");
                writer->WriteLine(aux->usuario->ID);
                writer->WriteLine(aux->usuario->Username);
                writer->WriteLine(aux->usuario->Email);
                writer->WriteLine(aux->usuario->Password);
                writer->WriteLine(aux->usuario->Visible);
            }
            else if (aux->recordatorio != nullptr) {
                writer->WriteLine("Recordatorio");
                writer->WriteLine(aux->recordatorio->ID);
                writer->WriteLine(aux->recordatorio->nombre);
                writer->WriteLine(aux->recordatorio->descripcion);
                writer->WriteLine(aux->recordatorio->fecha);
                writer->WriteLine(aux->recordatorio->completado);
            }
            else if (aux->seguimiento != nullptr) {
                writer->WriteLine("Seguimiento");
                writer->WriteLine(aux->seguimiento->contadorId);
                writer->WriteLine(aux->seguimiento->fecha);
                writer->WriteLine(aux->seguimiento->descripcion);
                writer->WriteLine(aux->seguimiento->visible);
            }
            else if (aux->registro != nullptr) {
                writer->WriteLine("Registro");
                writer->WriteLine(aux->registro->id);
                writer->WriteLine(aux->registro->fecha);
                writer->WriteLine(aux->registro->doctor);
                writer->WriteLine(aux->registro->especialidad);
                writer->WriteLine(aux->registro->descripcion);
                writer->WriteLine(aux->registro->visible);
            }
            aux = aux->siguiente;
        }
    }
    finally {
        if (writer != nullptr) {
            writer->Close();
        }
        if (fileStream != nullptr) {
            fileStream->Close();
        }
    }
}
