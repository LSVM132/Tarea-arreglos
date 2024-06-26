#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const double PORCENTAJE_CCSS = 0.0917;
const int MAX_EMPLEADOS = 100;

struct Empleado {
    int cedula;
    string nombre;
    int tipo;
    double precioHora;
    double horasLaboradas;
    double salarioOrdinario;
    double aumento;
    double salarioBruto;
    double deduccionCCSS;
    double salarioNeto;
};

// Arreglos paralelos para almacenar los datos de los empleados
int cedulas[MAX_EMPLEADOS];
string nombres[MAX_EMPLEADOS];
int tipos[MAX_EMPLEADOS];
double preciosHora[MAX_EMPLEADOS];
double horasLaboradas[MAX_EMPLEADOS];
double salariosOrdinarios[MAX_EMPLEADOS];
double aumentos[MAX_EMPLEADOS];
double salariosBrutos[MAX_EMPLEADOS];
double deduccionesCCSS[MAX_EMPLEADOS];
double salariosNetos[MAX_EMPLEADOS];

int numEmpleados = 0;

// Función para mostrar los datos de un empleado en particular
void mostrarEmpleado(int indice) {
    cout << "\n---Datos del empleado---\n";
    cout << "Cedula: " << cedulas[indice] << endl;
    cout << "Nombre Empleado: " << nombres[indice] << endl;
    cout << "Tipo Empleado: " << tipos[indice] << endl;
    cout << "Salario por Hora: " << fixed << setprecision(2) << preciosHora[indice] << endl;
    cout << "Cantidad de Horas: " << horasLaboradas[indice] << endl;
    cout << "Salario Ordinario: " << salariosOrdinarios[indice] << endl;
    cout << "Aumento: " << aumentos[indice] << endl;
    cout << "Salario Bruto: " << salariosBrutos[indice] << endl;
    cout << "Deducción CCSS: " << deduccionesCCSS[indice] << endl;
    cout << "Salario Neto: " << salariosNetos[indice] << endl;
}

// Función para agregar un nuevo empleado
void agregarEmpleado() {
    cout << "Ingrese el numero de cedula: ";
    cin >> cedulas[numEmpleados];
    cout << "Ingrese el nombre del empleado: ";
    cin.ignore(); // Limpiar el buffer del teclado
    getline(cin, nombres[numEmpleados]);
    cout << "Ingrese el tipo de empleado (1-Operario, 2-Tecnico, 3-Profesional): ";
    cin >> tipos[numEmpleados];
    cout << "Ingrese la cantidad de horas laboradas: ";
    cin >> horasLaboradas[numEmpleados];
    cout << "Ingrese el precio por hora: ";
    cin >> preciosHora[numEmpleados];

    // Calcular salario ordinario
    salariosOrdinarios[numEmpleados] = horasLaboradas[numEmpleados] * preciosHora[numEmpleados];

    // Calcular aumento
    switch (tipos[numEmpleados]) {
        case 1:
            aumentos[numEmpleados] = salariosOrdinarios[numEmpleados] * 0.15;
            break;
        case 2:
            aumentos[numEmpleados] = salariosOrdinarios[numEmpleados] * 0.10;
            break;
        case 3:
            aumentos[numEmpleados] = salariosOrdinarios[numEmpleados] * 0.05;
            break;
        default:
            aumentos[numEmpleados] = 0;
    }

    // Calcular salario bruto
    salariosBrutos[numEmpleados] = salariosOrdinarios[numEmpleados] + aumentos[numEmpleados];

    // Calcular deducción CCSS
    deduccionesCCSS[numEmpleados] = salariosBrutos[numEmpleados] * PORCENTAJE_CCSS;

    // Calcular salario neto
    salariosNetos[numEmpleados] = salariosBrutos[numEmpleados] - deduccionesCCSS[numEmpleados];

    // Mostrar los datos del empleado recién agregado
    mostrarEmpleado(numEmpleados);

    numEmpleados++;
}

// Función para consultar datos de un empleado
void consultarEmpleado() {
    int cedulaConsulta;
    cout << "Ingrese la cedula del empleado a consultar: ";
    cin >> cedulaConsulta;

    int indice = -1;
    for (int i = 0; i < numEmpleados; i++) {
        if (cedulas[i] == cedulaConsulta) {
            indice = i;
            break;
        }
    }

    if (indice != -1) {
        mostrarEmpleado(indice);
    } else {
        cout << "Empleado no encontrado." << endl;
    }
}

// Función principal
int main() {
    char deseaContinuar;

    do {
        agregarEmpleado();

        cout << "\nDesea registrar otro empleado? (s/n): ";
        cin >> deseaContinuar;
    } while (deseaContinuar == 's' || deseaContinuar == 'S');

    // Mostrar estadísticas
    return 0;
}

