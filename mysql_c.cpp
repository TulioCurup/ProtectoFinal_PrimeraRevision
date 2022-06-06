// mysql_c.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <iostream>
#include <conio.h>
#include "Empleado.h"  
#include "Cliente.h"  
#include "Puestos.h" 
#include "Marca.h" 
#include "Producto.h" 
#include "Proveedor.h"
#include "Venta.h"
#include "Venta_detalle.h"
#include "Compra.h"
#include "Compra_detalle.h"
using namespace std;
int q_estado;
int main()
{
    string nombres, apellidos, direccion, telefono, genero, DPI, fecha_nacimiento, idPuesto, fecha_inicio_labores, fechaingreso;
    string nit, correo_electronico, fecha_ingreso;
    string puesto, nitc;
    string marca,proveedor, venta_detalle, NoFactura, serie, idCliente, idEmpleado,idVenta, idProducto, cantidad;
    string producto, idMarca, Descripcion, precio_costo, precio_venta, existencia, imagen, ventas, compra, idcompra, idproducto, precio_costo_unitario;
    Empleado c = Empleado(nombres, apellidos, direccion, telefono, genero, DPI, fecha_nacimiento, idPuesto, fecha_inicio_labores, fechaingreso);
    Clientes d = Clientes(nombres, apellidos,nit, telefono, genero, correo_electronico, fecha_ingreso);
    Puestos p = Puestos(puesto);
    Marca e = Marca(marca);
    Producto p2 = Producto(producto, idMarca, Descripcion,imagen, precio_costo,precio_venta, existencia, fecha_ingreso);
    Proveedor prv = Proveedor(proveedor, nit, direccion, telefono);
    venta vn = venta(NoFactura, serie, idCliente, idEmpleado);
    Ventas_detalle vd = Ventas_detalle(idVenta, idProducto, cantidad);
    Compras cp = Compras(compra);
    Compras_detalle cd = Compras_detalle(idcompra, idproducto, cantidad, precio_costo_unitario);
    cout << "Bienvenido";
    cout << "\n Ingrese su estacion de trabajo";
    cout << "\n 1. Administracion        /            2. Caja";
    cout << "\n Opcion:   ";
    int menu = 0;
    cin >> menu;
    int prueba = 0;
    int opcion = 0;
    int opcion1 = 0;
    int opcion2 = 0;
    int opcion3 = 0;
    int opcion4 = 0;
    int opcion5 = 0;
    int opcion6 = 0;
    int opcion7 = 0;
    int opcion8 = 0;
    int opcion9 = 0; 
    int opcion10 = 0;
    
    switch (menu)

    {
    case 1: cout << "\n-----------------------------------------ADMINISTRACION----------------------------------------";
        
        cout << "\n Ingrese la Opcion a ejecutar: 1. Empleado   2. Clientes   3. Puestos   4. Marcas  5. Productos 6. Proveedores";
        cout << "\n 7. Ventas 8. Ventas Detalle 9. Compras 10. Compras Detalle";
        cout << "\n Opcion:  ";
        cin >> prueba;
        switch (prueba)
        
        {
        case 1: cout << "\nUsted ha seleccionado la opcion Empleados";
            cout << "\n Ingrese la Opcion a ejecutar: 1. Crear   2. Leer   3. Actualizar   4. Eliminar --- Opcion:  ";
            cin >> opcion;
            switch (opcion)

            {
            case 1: cout << "\nUsted ha seleccionado la opcion 1 crear";
                c.crear();
                break;
            case 2: cout << "\nUsted ha seleccionado la opcion 2 leer";
                c.leer();
                break;
            case 3: cout << "\nUsted ha seleccionado la opcion 3 actualizar";
                c.Actualizar();
                break;
            case 4: cout << "\nUsted ha seleccionado la opcion 4 eliminar";
                c.Eliminar();
                break;

            }
            break;
        case 2: cout << "\nUsted ha seleccionado la opcion Clientes";
            cout << "\n Ingrese la Opcion a ejecutar: 1. Crear   2. Leer   3. Actualizar   4. Eliminar --- Opcion:  ";
            cin >> opcion1;
            switch (opcion1)

            {
            case 1: cout << "\nUsted ha seleccionado la opcion 1 crear";
                d.crear();
                break;
            case 2: cout << "\nUsted ha seleccionado la opcion 2 leer";
                d.leer();
                break;
            case 3: cout << "\nUsted ha seleccionado la opcion 3 actualizar";
                d.Actualizar();
                break;
            case 4: cout << "\nUsted ha seleccionado la opcion 4 eliminar";
                d.Eliminar();
                break;
            }
            break;
        case 3: cout << "\nUsted ha seleccionado la opcion Puestos";
            cout << "\n Ingrese la Opcion a ejecutar: 1. Crear   2. Leer   3. Actualizar   4. Eliminar --- Opcion:  ";
            cin >> opcion2;
            switch (opcion2)

            {
            case 1: cout << "\nUsted ha seleccionado la opcion 1 crear";
                p.crear();
                break;
            case 2: cout << "\nUsted ha seleccionado la opcion 2 leer";
                p.leer();
                break;
            case 3: cout << "\nUsted ha seleccionado la opcion 3 actualizar";
                p.Actualizar();
                break;
            case 4: cout << "\nUsted ha seleccionado la opcion 4 eliminar";
                p.Eliminar();
                break;

            }
            break;
        case 4: cout << "\nUsted ha seleccionado la opcion Marcas";
            cout << "\n Ingrese la Opcion a ejecutar: 1. Crear   2. Leer   3. Actualizar   4. Eliminar --- Opcion:  ";
            cin >> opcion3;
            switch (opcion3)

            {
            case 1: cout << "\nUsted ha seleccionado la opcion 1 crear";
                e.crear();
                break;
            case 2: cout << "\nUsted ha seleccionado la opcion 2 leer";
                e.leer();
                break;
            case 3: cout << "\nUsted ha seleccionado la opcion 3 actualizar";
                e.Actualizar();
                break;
            case 4: cout << "\nUsted ha seleccionado la opcion 4 eliminar";
                e.Eliminar();
                break;

            }
        case 5: cout << "\nUsted ha seleccionado la opcion Productos";
            cout << "\n Ingrese la Opcion a ejecutar: 1. Crear   2. Leer   3. Actualizar   4. Eliminar --- Opcion:  ";
            cin >> opcion4;
            switch (opcion4)

            {
            case 1: cout << "\nUsted ha seleccionado la opcion 1 crear";
                p2.crear();
                break;
            case 2: cout << "\nUsted ha seleccionado la opcion 2 leer";
                p2.leer();
                break;
            case 3: cout << "\nUsted ha seleccionado la opcion 3 actualizar";
                p2.Actualizar();
                break;
            case 4: cout << "\nUsted ha seleccionado la opcion 4 eliminar";
                p2.Eliminar();
                break;

            }
        case 6: cout << "\nUsted ha seleccionado la opcion Proveedor";
            cout << "\n Ingrese la Opcion a ejecutar: 1. Crear   2. Leer   3. Actualizar   4. Eliminar --- Opcion:  ";
            cin >> opcion5;
            switch (opcion5)

            {
            case 1: cout << "\nUsted ha seleccionado la opcion 1 crear";
                prv.crear();
                break;
            case 2: cout << "\nUsted ha seleccionado la opcion 2 leer";
                prv.leer();
                break;
            case 3: cout << "\nUsted ha seleccionado la opcion 3 actualizar";
                prv.Actualizar();
                break;
            case 4: cout << "\nUsted ha seleccionado la opcion 4 eliminar";
                prv.Eliminar();
                break;

            }

        case 7: cout << "\nUsted ha seleccionado la opcion Venta";
            cout << "\n Ingrese la Opcion a ejecutar: 1. Crear   2. Leer   3. Actualizar   4. Eliminar --- Opcion:  ";
            cin >> opcion6;
            switch (opcion6)

            {
            case 1: cout << "\nUsted ha seleccionado la opcion 1 crear";
                vn.crear();
                break;
            case 2: cout << "\nUsted ha seleccionado la opcion 2 leer";
                vn.leer();
                break;
            case 3: cout << "\nUsted ha seleccionado la opcion 3 actualizar";
                vn.Actualizar();
                break;
            case 4: cout << "\nUsted ha seleccionado la opcion 4 eliminar";
                vn.Eliminar();
                break;

            }
        case 8: cout << "\nUsted ha seleccionado la opcion Venta";
            cout << "\n Ingrese la Opcion a ejecutar: 1. Crear   2. Leer   3. Actualizar   4. Eliminar --- Opcion:  ";
            cin >> opcion7;
            switch (opcion7)

            {
            case 1: cout << "\nUsted ha seleccionado la opcion 1 crear";
                vd.crear();
                break;
            case 2: cout << "\nUsted ha seleccionado la opcion 2 leer";
                vd.leer();
                break;
            case 3: cout << "\nUsted ha seleccionado la opcion 3 actualizar";
                vd.Actualizar();
                break;
            case 4: cout << "\nUsted ha seleccionado la opcion 4 eliminar";
                vd.Eliminar();
                break;

            }
        case 9: cout << "\nUsted ha seleccionado la opcion Venta";
            cout << "\n Ingrese la Opcion a ejecutar: 1. Crear   2. Leer   3. Actualizar   4. Eliminar --- Opcion:  ";
            cin >> opcion8;
            switch (opcion8)

            {
            case 1: cout << "\nUsted ha seleccionado la opcion 1 crear";
                cp.crear();
                break;
            case 2: cout << "\nUsted ha seleccionado la opcion 2 leer";
                cp.leer();
                break;
            case 3: cout << "\nUsted ha seleccionado la opcion 3 actualizar";
                cp.Actualizar();
                break;
            case 4: cout << "\nUsted ha seleccionado la opcion 4 eliminar";
                cp.Eliminar();
                break;

            }
        case 10: cout << "\nUsted ha seleccionado la opcion Compra detalle";
            cout << "\n Ingrese la Opcion a ejecutar: 1. Crear   2. Leer   3. Actualizar   4. Eliminar --- Opcion:  ";
            cin >> opcion9;
            switch (opcion9)

            {
            case 1: cout << "\nUsted ha seleccionado la opcion 1 crear";
                cd.crear();
                break;
            case 2: cout << "\nUsted ha seleccionado la opcion 2 leer";
                cd.leer();
                break;
            case 3: cout << "\nUsted ha seleccionado la opcion 3 actualizar";
                cd.Actualizar();
                break;
            case 4: cout << "\nUsted ha seleccionado la opcion 4 eliminar";
                cd.Eliminar();
                break;

            }

            /* final switch de prueba*/
        }
        break;
    case 2: cout << "\n-----------------------------------------CAJA--------------------------------------------------";
        cout << "\n Ingrese la Opcion a ejecutar: 1. Realizar venta";
        cout << "\n Opcion:  ";
        cin >> opcion10;
        switch (opcion10)

        {
        case 1: cout << "\nUsted ha seleccionado la opcion 1 facturacion";
            vn.fac();
            vn.crear();
            vd.crear();
            vn.datosfac();
            break;
        case 2: cout << "\nUsted ha seleccionado la opcion 2 ver datos de factura";
            vn.datosfac();
            break;
  /*      case 3: cout << "\nUsted ha seleccionado la opcion 3 actualizar";
            cd.Actualizar();
            break;
        case 4: cout << "\nUsted ha seleccionado la opcion 4 eliminar";
            cd.Eliminar();
            break;*/

        }

    return 0;
    }

    };






