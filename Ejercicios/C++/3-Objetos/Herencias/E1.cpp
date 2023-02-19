#include <iostream>
#include <string>
#include <cmath>
#include <cassert>

/*
Implementar la clase Persona. Implementar las clases Estudiante, Profesor y Staff.
Todas las personas tienen nombre y apellido como atributos y un método que devuelve su nombre como string (se puede sobrecargar el operador << —friend ostream& operator<<(ostream& os, const Persona& p);—para enviar una persona a stdout).
Todos los estudiantes tienen una carrera asociada y un año de ingreso a dicha carrera.
Todos los profesores tienen al menos departamento asociado y al menos una materia que dictar.
*/

class Persona{
    private:
        std::string nombre_;
        std::string apellido_;

    public:
        Persona(std::string nombre, std::string apellido): nombre_(nombre), apellido_(apellido) {}
        ~Persona() {}
        std::string nombre() {return nombre_;}
        std::string apellido() {return apellido_;}
};

class Estudiante: public Persona {
    private:
        std::string carrera_;
        int anio_ingreso_;

    public:
        Estudiante(std::string nombre, std::string apellido, std::string carrera, int anio_ingreso): Persona(nombre, apellido), carrera_(carrera), anio_ingreso_(anio_ingreso) {}
        ~Estudiante() {}
        std::string carrera() {return carrera_;}
        int anio_ingreso() {return anio_ingreso_;}
};

class Profesor: public Persona {
    private:
        std::string departamento_;
        std::string materia_;

    public:
        Profesor(std::string nombre, std::string apellido, std::string departamento, std::string materia): Persona(nombre, apellido), departamento_(departamento), materia_(materia) {}
        ~Profesor() {}
        std::string departamento() {return departamento_;}
        std::string materia() {return materia_;}
};

class Staff: public Persona {
    private:
        std::string departamento_;

    public:
        Staff(std::string nombre, std::string apellido, std::string departamento): Persona(nombre, apellido), departamento_(departamento) {}
        ~Staff() {}
        std::string departamento() {return departamento_;}
};

int main() {
    Estudiante e("Juan", "Perez", "Ingenieria", 2018);
    Profesor p("Pedro", "Gomez", "Matematica", "Algebra");
    Staff s("Maria", "Lopez", "Administracion");
    std::cout << e.nombre() << " " << e.apellido() << " " << e.carrera() << " " << e.anio_ingreso() << std::endl;
    std::cout << p.nombre() << " " << p.apellido() << " " << p.departamento() << " " << p.materia() << std::endl;
    std::cout << s.nombre() << " " << s.apellido() << " " << s.departamento() << std::endl;
    return 0;
}