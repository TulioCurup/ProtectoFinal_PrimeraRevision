#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include "ConexionBD.h"
using namespace std;

class Ventas_detalle {
private: string idVenta, idProducto, cantidad;
	   // constructor
public:
	Ventas_detalle() {
	}
	Ventas_detalle(string idve, string idpr, string ct) {
		idVenta = idve;
		idProducto = idpr;
		cantidad = ct;

	}

	// METODOS
	//set (modificar)
	void setVentas_detalle(string idve) { idVenta = idve; }
	void setidProducto(string idpr) { idProducto = idpr; }
	void setCantidad(string ct) { cantidad = ct; }
	//get (mostrar)
	string getidVentae() { return idVenta; }

	// CREAR
	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cout << "ingrese id venta:";
		cin >> idVenta;
		cout << "ingrese id Producto:";
		cin >> idProducto;
		cout << "ingrese cantidad:";
		cin >> cantidad;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string  insertar = "INSERT INTO ventas_detalle(idVenta,idProducto,cantidad) VALUES ('" + idVenta + "','" + idProducto + "','" + cantidad + "')";
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

			cout << "\n------------ Detalle de Ventas ------------" << endl;
			string consulta = "select * from ventas_detalle";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "," << fila[1] << "," << fila[2] << "," << fila[3] << "," << fila[4] << "," << endl;
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
	// ACTUALIZAR

	void Actualizar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		string id, venta_detalle1;
		cout << "\ningrese Id de la Venta detalle:";
		cin >> id;
		cout << "ingrese nueva Venta detalle:";
		cin >> venta_detalle1;
		cn.abrir_conexion();
		if (cn.getConectar()) {

			string actualizar = "UPDATE `db_Ventas_detalle`.`venta_detalle` SET  `venta_detalle` = '" + venta_detalle1 + "' WHERE (`idventa_detalle` ='" + id + "')";
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
		cout << "\ningrese Id de la Venta detalle a eliminar:";
		cin >> id;
		cn.abrir_conexion();
		if (cn.getConectar()) {

			string eliminar = "DELETE FROM ventas_detalle WHERE (idventa_detalle = '" + id + "')";
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
