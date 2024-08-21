#include <iostream>
#include <string>

using namespace std;

const double PLUS = 30000;

class Empleado {
protected:
    string nombre;
    int edad;
    double salario;

public:
    Empleado(string nombre, int edad, double salario)
        : nombre(nombre), edad(edad), salario(salario) {}

    virtual ~Empleado() {}

    string getNombre() const { return nombre; }
    int getEdad() const { return edad; }
    double getSalario() const { return salario; }

    void setNombre(string nombre) { this->nombre = nombre; }
    void setEdad(int edad) { this->edad = edad; }
    void setSalario(double salario) { this->salario = salario; }

    virtual void plus() = 0; // Función virtual pura, haciendo Empleado abstracta

    virtual string toString() const {
        return "Nombre: " + nombre + ", Edad: " + to_string(edad) + ", Salario: " + to_string(salario);
    }
};

class Comercial : public Empleado {
private:
    double comision;

public:
    Comercial(string nombre, int edad, double salario, double comision)
        : Empleado(nombre, edad, salario), comision(comision) {}

    double getComision() const { return comision; }
    void setComision(double comision) { this->comision = comision; }

    void plus() override {
        if (edad > 30 && comision > 200) {
            salario += PLUS;
        }
    }

    string toString() const override {
        return Empleado::toString() + ", Comision: " + to_string(comision);
    }
};

class Repartidor : public Empleado {
private:
    string zona;

public:
    Repartidor(string nombre, int edad, double salario, string zona)
        : Empleado(nombre, edad, salario), zona(zona) {}

    string getZona() const { return zona; }
    void setZona(string zona) { this->zona = zona; }

    void plus() override {
        if (edad < 25 && zona == "zona 3") {
            salario += PLUS;
        }
    }

    string toString() const override {
        return Empleado::toString() + ", Zona: " + zona;
    }
};
int main() {
    Comercial comercial1("Carlos", 35, 50000, 250);
    Repartidor repartidor1("Juan", 22, 30000, "zona 3");

    cout << "Antes del plus:" << endl;
    cout << comercial1.toString() << endl;
    cout << repartidor1.toString() << endl;

    comercial1.plus();
    repartidor1.plus();

    cout << "Después del plus:" << endl;
    cout << comercial1.toString() << endl;
    cout << repartidor1.toString() << endl;

    return 0;
}
