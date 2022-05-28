#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include "ConexionBD.h"
using namespace std;


class venta {
private: string ventas;
	   // constructor
public:
	venta() {
	}
	venta (string v) {
		ventas = v;

	}

	// METODOS
	//set (modificar)
	void setVentas(string v) { ventas = v; }

	//get (mostrar)
	string getVentas() { return ventas; }

	// CREAR
	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cout << "ingrese ventas:";
		cin >> ventas;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string  insertar = "INSERT INTO ventas(ventas) VALUES ('" + ventas + "')";
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

			cout << "\n------------ Datos de las ventas------------" << endl;
			string consulta = "select * from ventas";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "," << fila[1] << "," << fila[2] << "," << fila[3] << "," << fila[4] << "," << fila[5] << "," << fila[6] << "," << endl;
				
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
		string se1, no1, fe1, id1, idem1, fech1;
		cout << "\ningrese Numero de factura a modificar:";
		cin >> se1;
		cout << "numero de factura :";
		cin >> no1;
		cout << "fecha de la factura :";
		cin >> fe1;
		cout << "Id cliente :";
		cin >> id1;
		cout << "id empleado :";
		cin >> idem1;
		cout << "fecha de ingreso:";
		cin >> fech1;
		cn.abrir_conexion();
		if (cn.getConectar()) {

			string actualizar = "UPDATE `db_punto_venta`.`ventas` SET  `ventas` = '" + se1 + "' WHERE (`idventas` ='" + no1 + "')";
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
		cout << "\ningrese Id de ventas a eliminar:";
		cin >> id;
		cn.abrir_conexion();
		if (cn.getConectar()) {

			string eliminar = "DELETE FROM ventas WHERE (idventas = '" + id + "')";
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
