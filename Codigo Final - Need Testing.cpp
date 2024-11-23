

#include <iostream>
#include <string>
#include <limits> // Para numeric_limits
using namespace std;

// Clases del código base (simplificadas)
class Libro {
private:
    string titulo;
    int id;

public:
    Libro(const string& titulo = "", int id = 0) : titulo(titulo), id(id) {
        if (!titulo.empty()) {
            cout << "Libro '" << titulo << "' creado.\n";
        }
    }

    int getId() const { return id; }
    string getTitulo() const { return titulo; }
    void setTitulo(const string& nuevoTitulo) { titulo = nuevoTitulo; }
};

// Clase Bibliotecario
class Bibliotecario {
private:
    string nombre;
    int idEmpleado;

public:
    Bibliotecario(const string& nombre = "", int idEmpleado = 0)
        : nombre(nombre), idEmpleado(idEmpleado) {}

    string getNombre() const { return nombre; }
    int getIdEmpleado() const { return idEmpleado; }
    void setNombre(const string& nuevoNombre) { nombre = nuevoNombre; }
};

class Estante {
private:
    int id;
    Libro libro1, libro2; // Máximo 2 libros
    int contadorLibros = 0;

public:
    Estante(int id = 0) : id(id) {
        cout << "Estante " << id << " creado.\n";
    }

    bool agregarLibro(const Libro& libro) {
        if (contadorLibros == 0) {
            libro1 = libro;
            contadorLibros++;
            return true;
        } else if (contadorLibros == 1) {
            libro2 = libro;
            contadorLibros++;
            return true;
        }
        cout << "Estante lleno. No se pueden agregar más libros.\n";
        return false;
    }
    bool modificarLibro(int id, const string& nuevoTitulo) {
        if (libro1.getId() == id) {
            libro1.setTitulo(nuevoTitulo);
            return true;
        } else if (libro2.getId() == id) {
            libro2.setTitulo(nuevoTitulo);
            return true;
        }
        cout << "No se encontró el libro.\n";
        return false;
    }

    bool eliminarLibro(int id) {
        if (libro1.getId() == id) {
            libro1 = Libro();
            contadorLibros--;
            return true;
        } else if (libro2.getId() == id) {
            libro2 = Libro();
            contadorLibros--;
            return true;
        }
        cout << "No se encontró el libro.\n";
        return false;
    }

    void mostrarLibros() const {
        if (contadorLibros > 0) cout << "Libro 1: " << libro1.getTitulo() << "\n";
        if (contadorLibros > 1) cout << "Libro 2: " << libro2.getTitulo() << "\n";
        if (contadorLibros == 0) cout << "No hay libros en este estante.\n";
    }

    int getId() const { return id; }
};

class Biblioteca {
private:
    Estante estante1, estante2; // Solo dos estantes para simplificar
    Bibliotecario bibliotecario;

public:
    bool agregarEstante(Estante& estante) {
        if (estante1.getId() == 0) {
            estante1 = estante;
            return true;
        } else if (estante2.getId() == 0) {
            estante2 = estante;
            return true;
        }
        cout << "No se pueden agregar más estantes.\n";
        return false;
    }

    bool registrarBibliotecario(const Bibliotecario& nuevoBibliotecario) {
        bibliotecario = nuevoBibliotecario;
        cout << "Bibliotecario registrado con éxito: " << bibliotecario.getNombre() << "\n";
        return true;
    }

    bool modificarBibliotecario(int id, const string& nuevoNombre) {
        if (bibliotecario.getIdEmpleado() == id) {
            bibliotecario.setNombre(nuevoNombre);
            cout << "Bibliotecario modificado con éxito.\n";
            return true;
        }
        cout << "No se encontró el bibliotecario con ID: " << id << ".\n";
        return false;
    }

    bool eliminarBibliotecario(int id) {
        if (bibliotecario.getIdEmpleado() == id) {
            bibliotecario = Bibliotecario();
            cout << "Bibliotecario eliminado con éxito.\n";
            return true;
        }
        cout << "No se encontró el bibliotecario con ID: " << id << ".\n";
        return false;
    }

    Estante& obtenerEstante(int id) {
        if (id == 1) return estante1;
        else if (id == 2) return estante2;
        else throw invalid_argument("ID de estante inválido.");
    }

    void mostrarEstantes() const {
        if (estante1.getId() != 0) {
            cout << "Estante 1 ID: " << estante1.getId() << "\n";
            estante1.mostrarLibros();
        }
        if (estante2.getId() != 0) {
            cout << "Estante 2 ID: " << estante2.getId() << "\n";
            estante2.mostrarLibros();
        }
        if (estante1.getId() == 0 && estante2.getId() == 0) {
            cout << "No hay estantes en la biblioteca.\n";
        }
    }

    void mostrarBibliotecario() const {
        if (!bibliotecario.getNombre().empty()) {
            cout << "Bibliotecario actual: " << bibliotecario.getNombre() << " (ID: " << bibliotecario.getIdEmpleado() << ")\n";
        } else {
            cout << "No hay un bibliotecario registrado.\n";
        }
    }

};

//Funciones del menu
void agregarLibro(Biblioteca& biblioteca) {
    string titulo;
    int idEstante;

    cout << "Ingrese el título del libro: ";
    cin.ignore();
    getline(cin, titulo);

    cout << "Ingrese el ID del estante (1 o 2): ";
    cin >> idEstante;

    if (cin.fail() || (idEstante != 1 && idEstante != 2)) {
        cout << "Entrada inválida. Intente nuevamente.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    Libro nuevoLibro(titulo);
    try {
        Estante& estante = biblioteca.obtenerEstante(idEstante);
        if (!estante.agregarLibro(nuevoLibro)) {
            cout << "No se pudo agregar el libro al estante " << idEstante << ". Está lleno.\n";
        }
    } catch (const exception& e) {
        cout << e.what() << endl;
    }
}

void modificarLibro(Biblioteca& biblioteca) {
    int idEstante, idLibro;
    string nuevoTitulo;
    cout << "Ingrese el ID del estante (1 o 2): ";
    cin >> idEstante;
    cout << "Ingrese el ID del libro a modificar: ";
    cin >> idLibro;
    cin.ignore();
    cout << "Ingrese el nuevo título del libro: ";
    getline(cin, nuevoTitulo);

    biblioteca.obtenerEstante(idEstante).modificarLibro(idLibro, nuevoTitulo);
}

void eliminarLibro(Biblioteca& biblioteca) {
    int idEstante, idLibro;
    cout << "Ingrese el ID del estante (1 o 2): ";
    cin >> idEstante;
    cout << "Ingrese el ID del libro a eliminar: ";
    cin >> idLibro;

    biblioteca.obtenerEstante(idEstante).eliminarLibro(idLibro);
}

void registrarBibliotecario(Biblioteca& biblioteca) {
    string nombre;
    int idEmpleado;
    cout << "Ingrese el nombre del bibliotecario: ";
    cin.ignore();
    getline(cin, nombre);
    cout << "Ingrese el ID del bibliotecario: ";
    cin >> idEmpleado;

    biblioteca.registrarBibliotecario(Bibliotecario(nombre, idEmpleado));
}

void modificarBibliotecario(Biblioteca& biblioteca) {
    int id;
    string nuevoNombre;
    cout << "Ingrese el ID del bibliotecario: ";
    cin >> id;
    cin.ignore();
    cout << "Ingrese el nuevo nombre del bibliotecario: ";
    getline(cin, nuevoNombre);

    biblioteca.modificarBibliotecario(id, nuevoNombre);
}

void eliminarBibliotecario(Biblioteca& biblioteca) {
    int id;
    cout << "Ingrese el ID del bibliotecario: ";
    cin >> id;

    biblioteca.eliminarBibliotecario(id);
}

void mostrarBibliotecario(Biblioteca& biblioteca) {
    cout << "--- Contenido de la Biblioteca ---\n";
    biblioteca.mostrarBibliotecario();
    return;
}

void mostrarEstantes(Biblioteca& biblioteca) {
    cout << "--- Contenido de la Biblioteca ---\n";
    biblioteca.mostrarEstantes();
    return;
}

// Menú principal
void menu(Biblioteca& biblioteca) {
    int opcion;

    do {
        cout << "\n--- Menú de Biblioteca ---\n";
        cout << "1. Agregar Libro\n";
        cout << "2. Modificar Libro\n";
        cout << "3. Eliminar Libro\n";
        cout << "4. Mostrar Estantes\n";
        cout << "5. Registrar Bibliotecario\n";
        cout << "6. Modificar Bibliotecario\n";
        cout << "7. Eliminar Bibliotecario\n";
        cout << "8. Mostrar Bibliotecario\n";
        cout << "9. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        if (cin.fail()) { // Si la entrada no es un número
            cout << "Entrada invalida. Intente nuevamente.\n";
            cin.clear(); // Limpiar el estado de error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descartar entrada inválida
            continue;
        }

        switch (opcion) {
case 1:
            agregarLibro(biblioteca);
            break;
        case 2:
            modificarLibro(biblioteca);
            break;
        case 3:
            eliminarLibro(biblioteca);
            break;
        case 4:
            mostrarEstantes(biblioteca);
            break;
        case 5:
            registrarBibliotecario(biblioteca);
            break;
        case 6:
            modificarBibliotecario(biblioteca);
            break;
        case 7:
            eliminarBibliotecario(biblioteca);
            break;
        case 8:
            cout << "Saliendo del sistema...\n";
            break;
        default:
            cout << "Opción inválida. Intente nuevamente.\n";
        }
    } while (opcion != 8);
}

// Función principal
int main() {
    Biblioteca biblioteca;
    Estante estante1(1), estante2(2);

    // Agregar estantes a la biblioteca
    biblioteca.agregarEstante(estante1);
    biblioteca.agregarEstante(estante2);

    // Llamar al menú
    menu(biblioteca);

    return 0;
}
