#include <iostream>
#include <string>
using namespace std;

const int MAX_VENTAS = 100;

// Variables para estadísticas
int entradasSol = 0, entradasSombra = 0, entradasPreferencial = 0;
int acumuladoSol = 0, acumuladoSombra = 0, acumuladoPreferencial = 0;

// Arreglos paralelos para almacenar datos de ventas
int numeroFactura[MAX_VENTAS];
int cedula[MAX_VENTAS];
string nombre[MAX_VENTAS];
int localidad[MAX_VENTAS];
int cantidad[MAX_VENTAS];
int totalPagar[MAX_VENTAS];
int numVentas = 0;

void registrarVenta() {
    if (numVentas >= MAX_VENTAS) {
        cout << "No se pueden registrar más ventas." << endl;
        return;
    }

    // Variables para cada venta
    int precioEntrada, cargosServicios;
    string nombreLocalidad;

    // Ingreso de datos de la venta
    cout << "Numero de factura: ";
    cin >> numeroFactura[numVentas];
    cout << "Cedula: ";
    cin >> cedula[numVentas];
    cout << "Nombre del comprador: ";
    cin.ignore();
    getline(cin, nombre[numVentas]);
    cout << "Localidad (1-Sol Norte/Sur, 2-Sombra Este/Oeste, 3-Preferencial): ";
    cin >> localidad[numVentas];
    cout << "Cantidad de entradas (máximo 4): ";
    cin >> cantidad[numVentas];

    // Validar cantidad de entradas
    if (cantidad[numVentas] <= 0 || cantidad[numVentas] > 4) {
        cout << "La cantidad de entradas debe ser entre 1 y 4." << endl;
        return;
    }

    // Procesar datos de la venta
    switch (localidad[numVentas]) {
        case 1:
            precioEntrada = 10500;
            nombreLocalidad = "Sol Norte/Sur";
            entradasSol += cantidad[numVentas];
            acumuladoSol += cantidad[numVentas] * precioEntrada;
            break;
        case 2:
            precioEntrada = 20500;
            nombreLocalidad = "Sombra Este/Oeste";
            entradasSombra += cantidad[numVentas];
            acumuladoSombra += cantidad[numVentas] * precioEntrada;
            break;
        case 3:
            precioEntrada = 25500;
            nombreLocalidad = "Preferencial";
            entradasPreferencial += cantidad[numVentas];
            acumuladoPreferencial += cantidad[numVentas] * precioEntrada;
            break;
        default:
            cout << "Localidad invalida." << endl;
            return;
    }

    // El subtotal y total a pagar
    int subtotal = cantidad[numVentas] * precioEntrada;
    cargosServicios = cantidad[numVentas] * 1000;
    totalPagar[numVentas] = subtotal + cargosServicios;

    // Mostrar información de la venta
    cout << "---------------------------" << endl;
    cout << "Numero de Factura: " << numeroFactura[numVentas] << endl;
    cout << "Cedula: " << cedula[numVentas] << endl;
    cout << "Nombre del comprador: " << nombre[numVentas] << endl;
    cout << "Localidad: " << nombreLocalidad << endl;
    cout << "Cantidad de Entradas: " << cantidad[numVentas] << endl;
    cout << "Subtotal: " << subtotal << " colones" << endl;
    cout << "Cargos por Servicios: " << cargosServicios << " colones" << endl;
    cout << "Total a pagar: " << totalPagar[numVentas] << " colones" << endl;

    numVentas++;
}

void consultarVenta() {
    int numFacturaConsulta;
    cout << "Ingrese el numero de factura a consultar: ";
    cin >> numFacturaConsulta;
    for (int i = 0; i < numVentas; ++i) {
        if (numeroFactura[i] == numFacturaConsulta) {
            cout << "Numero de Factura: " << numeroFactura[i] << endl;
            cout << "Cedula: " << cedula[i] << endl;
            cout << "Nombre del comprador: " << nombre[i] << endl;
            cout << "Localidad: " << localidad[i] << endl;
            cout << "Cantidad de Entradas: " << cantidad[i] << endl;
            cout << "Total a pagar: " << totalPagar[i] << " colones" << endl;
            return;
        }
    }
    cout << "Factura no encontrada." << endl;
}

void modificarVenta() {
    int numFacturaModificar;
    cout << "Ingrese el numero de factura a modificar: ";
    cin >> numFacturaModificar;
    for (int i = 0; i < numVentas; ++i) {
        if (numeroFactura[i] == numFacturaModificar) {
            cout << "Ingrese los nuevos datos:" << endl;
            cout << "Cedula: ";
            cin >> cedula[i];
            cout << "Nombre del comprador: ";
            cin.ignore();
            getline(cin, nombre[i]);
            cout << "Localidad (1-Sol Norte/Sur, 2-Sombra Este/Oeste, 3-Preferencial): ";
            cin >> localidad[i];
            cout << "Cantidad de entradas (máximo 4): ";
            cin >> cantidad[i];

            // Recalcular el total a pagar
            int precioEntrada, cargosServicios;
            switch (localidad[i]) {
                case 1:
                    precioEntrada = 10500;
                    break;
                case 2:
                    precioEntrada = 20500;
                    break;
                case 3:
                    precioEntrada = 25500;
                    break;
                default:
                    cout << "Localidad invalida." << endl;
                    return;
            }

            int subtotal = cantidad[i] * precioEntrada;
            cargosServicios = cantidad[i] * 1000;
            totalPagar[i] = subtotal + cargosServicios;

            cout << "Venta modificada exitosamente." << endl;
            return;
        }
    }
    cout << "Factura no encontrada." << endl;
}

void borrarVenta() {
    int numFacturaBorrar;
    cout << "Ingrese el numero de factura a borrar: ";
    cin >> numFacturaBorrar;
    for (int i = 0; i < numVentas; ++i) {
        if (numeroFactura[i] == numFacturaBorrar) {
            // Borrar venta moviendo las ventas posteriores una posición hacia arriba
            for (int j = i; j < numVentas - 1; ++j) {
                numeroFactura[j] = numeroFactura[j + 1];
                cedula[j] = cedula[j + 1];
                nombre[j] = nombre[j + 1];
                localidad[j] = localidad[j + 1];
                cantidad[j] = cantidad[j + 1];
                totalPagar[j] = totalPagar[j + 1];
            }
            numVentas--;
            cout << "Venta borrada exitosamente." << endl;
            return;
        }
    }
    cout << "Factura no encontrada." << endl;
}

void mostrarEstadisticas() {
    cout << "Estadisticas:" << endl;
    cout << "Cantidad Entradas Localidad Sol Norte/Sur: " << entradasSol << endl;
    cout << "Acumulado Dinero Localidad Sol Norte/Sur: " << acumuladoSol << " colones" << endl;
    cout << "Cantidad Entradas Localidad Sombra Este/Oeste: " << entradasSombra << endl;
    cout << "Acumulado Dinero Localidad Sombra Este/Oeste: " << acumuladoSombra << " colones" << endl;
    cout << "Cantidad Entradas Localidad Preferencial: " << entradasPreferencial << endl;
    cout << "Acumulado Dinero Localidad Preferencial: " << acumuladoPreferencial << " colones" << endl;
}

int main() {
    char opcion;
    do {
        cout << "1. Registrar venta" << endl;
        cout << "2. Consultar venta" << endl;
        cout << "3. Modificar venta" << endl;
        cout << "4. Borrar venta" << endl;
        cout << "5. Mostrar estadisticas" << endl;
        cout << "6. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case '1':
                registrarVenta();
                break;
            case '2':
                consultarVenta();
                break;
            case '3':
                modificarVenta();
                break;
            case '4':
                borrarVenta();
                break;
            case '5':
                mostrarEstadisticas();
                break;
            case '6':
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opcion invalida." << endl;
        }
    } while (opcion != '6');

    return 0;
}

