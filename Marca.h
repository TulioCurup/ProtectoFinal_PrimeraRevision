#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include "ConexionBD.h"
using namespace std;

class Marca {
private: string marca;
	   // constructor
public:
	Marca() {
	}
	Marca(string mr) {
		marca = mr;

	}

	// METODOS
	//set (modificar)
	void setPuesto(string mr) { marca = mr; }

	//get (mostrar)
	string getPuesto() { return marca; }

	// CREAR
	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cout << "ingrese Marca:";
		cin >> marca;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string  insertar = "INSERT INTO marcas(marca) VALUES ('" + marca + "')";
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

			cout << "\n------------ Datos de los Puestos ------------" << endl;
			string consulta = "select * from marcas";
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
		string id, marca1;
		cout << "\ningrese Id de la Marca a modificar:";
		cin >> id;
		cout << "ingrese nueva Marca:";
		cin >> marca1;
		cn.abrir_conexion();
		if (cn.getConectar()) {

			string actualizar = "UPDATE `db_punto_venta`.`marcas` SET  `marca` = '" + marca1 + "' WHERE (`idMarca` ='" + id + "')";
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
		cout << "\ningrese Id de la marca a eliminar:";
		cin >> id;
		cn.abrir_conexion();
		if (cn.getConectar()) {

			string eliminar = "DELETE FROM marcas WHERE (idMarca = '" + id + "')";
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
