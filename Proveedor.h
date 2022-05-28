#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include "ConexionBD.h"

using namespace std;
class Proveedor {
private: string proveedor, nit, direccion, telefono;
	   // constructor
public: 
	Proveedor() {
	}
	Proveedor(string pr, string nt, string  dr, string  tel) {
		proveedor = pr;
		nit = nt;
		direccion = dr;
		telefono = tel;

	}

	// METODOS
	//set (modificar)
	void setPuesto(string pr) { proveedor = pr; }
	void setNit(string nt) { nit = nt; }
	void setDireccion(string dr) { direccion = dr; }
	void setTelefono(string tel) { telefono = tel; }

	//get (mostrar)
	string getProveedor() { return proveedor; }
	string getNit() { return nit; }
	string getDireccion() { return direccion; }
	string getTelefono() { return telefono; }

	// CREAR
	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cout << "ingrese Proveedor:";
		cin >> proveedor;
		cout << "ingrese nit:";
		cin >> nit;
		cout << "ingrese direccion:";
		cin >> direccion;
		cout << "ingrese telefono:";
		cin >> telefono;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string  insertar = "INSERT INTO proveedores(proveedor,nit,direccion,telefono) VALUES ('" + proveedor + "','" + nit + "', '" + direccion + "','" + telefono + "')";
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

			cout << "\n------------ Datos de los Proveedores ------------" << endl;
			string consulta = "select * from proveedores";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "," << fila[1] << "," << endl;
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
		string id, proveedor1, nit1, direccion1, telefono1;
		cout << "ingrese nuevo Proveedor:";
		cin >> proveedor1;
		cout << "ingrese nuevo nit del Proveedor:";
		cin >> nit1;
		cout << "ingrese nueva direccion del  Proveedor:";
		cin >> direccion1;
		cout << "ingrese nuevo telefono del  Proveedor:";
		cin >> telefono1;
		cn.abrir_conexion();
		if (cn.getConectar()) {

			string actualizar = "UPDATE `db_punto_venta`.`proveedores` SET  `proveedor` = '" + proveedor1 + "', `nit` = '" + nit1 + "', `direccion` = '" + direccion1 + "', `telefono` = '" + telefono1 + "' WHERE (`idProveedor` ='" + id + "')";
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
		cout << "\ningrese Id del proveedor a eliminar:";
		cin >> id;
		cn.abrir_conexion();
		if (cn.getConectar()) {

			string eliminar = "DELETE FROM proveedores WHERE (idProveedor = '" + id + "')";
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

