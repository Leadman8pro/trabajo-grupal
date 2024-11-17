#include <iostream>
#include <string>
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

public:
    bool agregarEstante(const Estante& estante) {
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
};
