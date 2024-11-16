#include<iostream>
#include<string>
using namespace std;

//hoal prueba 2

class Libro{
private:

public:


};

class Estante{
private:

public:



    //Metodo, agrega un libro al estante
    bool agregarLibro(Libro libro) {
        if (contadorLibros == 0) {
            libro1 = libro; //Asigna un libro a la 1ra posicion
            contadorLibros++; 
            return true;
        } else if (contadorLibros == 1) {
            libro2 = libro; //Asigna un libro a la 2da posicion
            contadorLibros++;
            return true;
        } else {
            cout << "Estante lleno se puede agregar mas libros." << endl;
            return false;
        }
    }

    //Metodo, modifica un libro existente
    bool modificarLibro(int id, string nuevoTitulo, string nuevoAutor) {
        if (libro1.getId() == id) {
            libro1.setTitulo(nuevoTitulo); //Modifica titulo de libro1
            libro1.setAutor(nuevoAutor); //Modifica autor de libro1
            return true;
        } else if (libro2.getId() == id) {
            libro2.setTitulo(nuevoTitulo); //Modifica titulo de libro2
            libro2.setAutor(nuevoAutor); //Modifica autor de libro2
            return true;
        } else {
            cout << "No se encuentra el libro." << endl;
            return false; 
        }
    }

    //Metodo, remueve un libro del estante
    bool removerLibro(int id) {
        if (libro1.getId() == id) {
            libro1 = Libro(); //Elimina los datos del libro1 y lo deja vacio
            contadorLibros--;
            return true;
        } else if (libro2.getId() == id) {
            libro2 = Libro(); //Elimina los datos del libro2 y lo deja vacio
            contadorLibros--;
            return true;
        } else {
            cout << "No hay libros registrados." << endl;
            return false;
        }
    }



};

class Biblioteca{
private:

public:

    //Metodo, agrega un estante en biblioteca
    bool agregarEstante(Estante estante) {
        if (contadorEstantes == 0) {
            estante1 = estante; //Asigna un estante a la 1ra posicion
            contadorEstantes++;
            return true;
        } else if (contadorEstantes == 1) {
            estante2 = estante; //Asigna un estante a la 2da posicion
            contadorEstantes++;
            return true;
        } else {
            cout << "No se pueden agregar mas estantes." << endl;
            return false;
        }
    }

    //Metodo, agrega/registra u bibliotecario en biblioteca
    bool agregarBibliotecario(Bibliotecario bibliotecario) {
        if (contadorBibliotecarios == 0) {
            bibliotecario1 = bibliotecario; //Asigna un bibliotecario a la 1ra posicion
            contadorBibliotecarios++;
            return true;
        } else if (contadorBibliotecarios == 1) {
            bibliotecario2 = bibliotecario; //Asigna un bibliotecario a la 2da posicion
            contadorBibliotecarios++;
            return true;
        } else {
            cout << "No se pueden registras mas bibliotecarios." << endl;
            return false;
        }
    }

    //Metodo, remueve bibliotecario de biblioteca
    bool removerBibliotecario(int id) {
    if (bibliotecario1.getIdEmpleado() == id) {
            bibliotecario1 = Bibliotecario(); //Elimina los datos de bibliotecario1 y lo deja vacio
            contadorBibliotecarios--;
            return true;
        } else if (bibliotecario2.getIdEmpleado() == id) {
            bibliotecario2 = Bibliotecario(); //Elimina los datos de bibliotecario2 y lo deja vacio
            contadorBibliotecarios--;
            return true;
        } else {
            cout << "No hay bibliotecarios registrados." << endl;
            return false;
        }
    }

    //Metodo, modifica la data de bibliotecario
    bool modificarBibliotecario(int id, string nuevoNombre) {
        if (bibliotecario1.getIdEmpleado() == id) {
            bibliotecario1.setNombre(nuevoNombre); //Modifica nombre de bibliotecario1
            return true;
        } else if (bibliotecario2.getIdEmpleado() == id) {
            bibliotecario2.setNombre(nuevoNombre); //Modifica nombre de bibliotecario2
            return true;
        } else {
            cout << "No hay bibliotecario registrados." << endl;
            return false;
        }



};

class Bibliotecario{
private:

public:


};



int main(){



    return 0;
}
