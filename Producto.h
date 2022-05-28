#pragma once
#include <mysql.h>
#include <iostream>
#include <conio.h>
#include <string>
#include "ConexionBD.h"
using namespace std;

class Producto {
private: string producto, idMarca, Descripcion, Imagen, precio_costo, precio_venta, existencia, fecha_ingreso;
	   // constructor
public:
	Producto() {
	}
	Producto(string pr, string im, string desc, string ig, string pc, string pve, string ex, string fin) {
		producto = pr;
		idMarca = im;
		Descripcion = desc;
		Imagen = ig;
		precio_costo = pc;
		precio_venta = pve;
		existencia = ex;
		fecha_ingreso = fin;

	}

	// METODOS
	//set (modificar)
	void setproducto(string pr) { producto = pr; }
	void setidMarca(string im) { idMarca = im; }
	void setDescripcion(string desc) { Descripcion = desc; }
	void setImagen(string ig) { Imagen = ig; }
	void setprecio_costo(string pc) { precio_costo = pc; }
	void setprecio_venta(string pve) { precio_venta = pve; }
	void setexistencia(string ex) { existencia = ex;}
	void setfecha_ingreso(string fin) { fecha_ingreso = fin; }

	//get (mostrar)
	string getproducto() { return producto; }
	string getidMarca() { return idMarca; }
	string getDescripcion() { return Descripcion; }
	string getImagen() { return Imagen; }
	string getprecio_costo() { return precio_costo; }
	string getprecio_venta() { return precio_venta; }
	string getexistencia() { return existencia; }
	string getfecha_ingreso() { return fecha_ingreso; }


	// CREAR
	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cout << "ingrese producto:";
		cin >> producto;
		cout << "ingrese id de la Marca:";
		cin >> idMarca;
		cout << "ingrese Descripcion:";
		cin >> Descripcion;
		cout << "ingrese precio costo:";
		cin >> precio_costo;
		cout << "ingrese precio venta:";
		cin >> precio_venta;
		cout << "ingrese existencia:";
		cin >> existencia;
		cout << "ingrese fecha ingreso:";
		cin >> fecha_ingreso;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string  insertar = "INSERT INTO productos( producto, idMarca, Descripcion,precio_costo,precio_venta,existencia,fecha_ingreso) VALUES ('" + producto + "','" + idMarca + "','" + Descripcion + "','" + precio_costo + "'," + precio_venta + ", '" + existencia + "', '" + fecha_ingreso + "')";
			const char* i = insertar.c_str();
			// executar el query
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "\n Ingreso Exitoso ..." << endl;
			}
			else {
				cout << " xxx Error al Ingresar  xxx" << endl;
			}
		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}
	// LEER
	void leer() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {

			cout << "\n------------ Datos de los Productos ------------" << endl;
			string consulta = "select * from productos";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "," << fila[1] << "," << fila[2] << "," << fila[3] << "," << fila[4] << "," << fila[5] << "," << fila[6] << "," << fila[7] << "," << fila[8] << "," << fila[9] << endl;
				}

			}
			else {
				cout << "\n xxx Error al Consultar  xxx" << endl;
			}

		}
		else {
			cout << "\n xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}
	//ACTUALIZAR
	void Actualizar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		string  id, producto1, idMarca1, Descripcion1, Imagen1, precio_costo1, precio_venta1, existencia1, fecha_ingreso1;
		cout << "\ningrese Id de producto a modificar:";
		cin >> id;
		cout << "ingrese producto:";
		cin >> producto1;
		cout << "ingrese id Marca:";
		cin >> idMarca1;
		cout << "ingrese Descripcion:";
		cin >> Descripcion1;
		cout << "ingrese Imagen:";
		cin >> Imagen1;
		cout << "ingrese precio costo:";
		cin >> precio_costo1;
		cout << "ingrese precio venta:";
		cin >> precio_venta1;
		cout << "ingrese existencia:";
		cin >> existencia1;
		cout << "ingrese fecha ingreso:";
		cin >> fecha_ingreso1;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string actualizar = "UPDATE `db_punto_venta`.`productos` SET `producto` = '" + producto1 + "', `idMarca` = '" + idMarca1 + "', `Imagen` = '" + Imagen1 + "', `precio_costo` = '" + precio_costo1 + "',`precio_venta` = '" + precio_venta1 + "' ,`existencia` = '" + existencia1 + "', `fecha_ingreso` = '" + fecha_ingreso1 + "')";
			const char* i = actualizar.c_str();
			// executar el query
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "\nActualizacion exitosa ..." << endl;
			}
			else {
				cout << "\n xxx Error al actualizar  xxx" << endl;
			}
		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();

	}
	// ELIMINAR
	void Eliminar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		string id;
		cout << "\ningrese Id del Producto a eliminar:";
		cin >> id;
		cn.abrir_conexion();
		if (cn.getConectar()) {

			string eliminar = "DELETE FROM productos WHERE (idProducto = '" + id + "')";
			const char* i = eliminar.c_str();
			// executar el query
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "\nSe elimino la fila ..." << endl;
			}
			else {
				cout << " xxx Error   xxx" << endl;
			}
		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}


};
