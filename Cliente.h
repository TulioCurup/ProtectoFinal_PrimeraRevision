#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include "ConexionBD.h"
#include "Persona.h"
using namespace std;
class Clientes : Persona {
private: string nit, correo_electronico, fecha_ingreso;
	   // constructor
public:
	Clientes() {
	}
	Clientes(string nom, string ape, string nt, string tel, string gm, string gn, string fi) {
		nit = nt;
		correo_electronico = gm;
		fecha_ingreso = fi;	
	}
	// METODOS
	//set (modificar)
	void setNombres(string nom) { nombres = nom; }
	void setApellidos(string ape) { apellidos = ape; }
	void setNit(string nt) { nit = nt; }
	void setTelefono(string tel) { telefono = tel; }
	void setGenero(string gn) { genero = gn; }
	void setGmail(string gm) { correo_electronico = gm; }
	void setFecha_ingreso(string  fi) { fecha_ingreso = fi; }
	//get (mostrar)
	string getNombres() { return nombres; }
	string getApellidos() { return apellidos; }
	string getNit() { return nit; }
	string getTelefono() { return telefono; }
	string getGenero() { return genero; }
	string getGmail() { return correo_electronico; }
	string getFecha_ingreso() { return fecha_ingreso; }

	// CREAR
	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cout << "ingrese nombre:";
		cin >> nombres;
		cout << "ingrese apellido:";
		cin >> apellidos;
		cout << "ingrese nit:";
		cin >> nit;
		cout << "ingrese telefono:";
		cin >> telefono;
		cout << "ingrese genero:";
		cin >> genero;
		cout << "ingrese correo electronico:";
		cin >> correo_electronico;
		cout << "ingrese fecha de ingreso:";
		cin >> fecha_ingreso;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string  insertar = "INSERT INTO clientes(nombres, apellidos, NIT , genero, telefono, correo_electronico, fechaingreso) VALUES ('" + nombres + "','" + apellidos + "','" + nit + "','" + telefono + "','" + genero + "','" + correo_electronico + "','" + fecha_ingreso + "')";
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

			cout << "\n------------ Datos del Cliente ------------" << endl;
			string consulta = "select * from clientes";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "," << fila[1] << "," << fila[2] << "," << fila[3] << "," << fila[4] << "," << fila[5] << "," << fila[6] << "," << fila[7] << "," << fila[8] << endl;
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
		string id, nombres1, apellidos1, nit1, telefono1, genero1, correo_electronico1, fecha_ingreso1;
		cout << "\ningrese Id de cliente a modificar:";
		cin >> id;
		cout << "ingrese nuevo nombre:";
		cin >> nombres1;
		cout << "ingrese nuevo apellido:";
		cin >> apellidos1;
		cout << "ingrese nuevo nit:";
		cin >> nit1;
		cout << "ingrese nuevo telefono";
		cin >> telefono1;
		cout << "ingrese genero:";
		cin >> genero1;
		cout << "ingrese nuevo correo electronico:";
		cin >> correo_electronico1;
		cout << "ingrese nueva fecha de ingreso:";
		cin >> fecha_ingreso1;
		cn.abrir_conexion();
		if (cn.getConectar()){

			string actualizar = "UPDATE `db_punto_venta`.`clientes` SET  `nombres` = '" + nombres1 + "', `apellidos` = '" + apellidos1 + "', `NIT` = '" + nit1 + "', `genero` = '" + genero1 + "', `telefono` = '" + telefono1 + "',`correo_electronico` = '" + correo_electronico1 + "', `fechaingreso` = '" + fecha_ingreso1 + "' WHERE (`idCliente` ='" + id + "')";
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
		cout << "\ningrese Id de cliente a eliminar:";
		cin >> id;
		cn.abrir_conexion();
		if (cn.getConectar()) {

			string eliminar = "DELETE FROM clientes WHERE (idCliente = '" + id + "')";
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




