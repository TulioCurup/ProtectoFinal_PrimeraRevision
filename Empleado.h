#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include "ConexionBD.h"
#include "Persona.h"
using namespace std;

	class Empleado : Persona {
	private: string  DPI, idPuesto, fecha_inicio_labores, fechaingreso;
		   // constructor
	public:
		Empleado() {
		}
		Empleado(string nom, string ape, string dir, string tel, string fn, string dp, string gn, string idp, string fchI, string fchig) : Persona(nom, ape, dir, tel, gn, fn) {
			DPI = dp;
			idPuesto = idp;
			fecha_inicio_labores = fchI;
			fechaingreso = fchig;

		}

		// METODOS
		//set (modificar)
		void setNombres(string nom) { nombres = nom; }
		void setApellidos(string ape) { apellidos = ape; }
		void setDireccion(string dir) { direccion = dir; }
		void setTelefono(string tel) { telefono = tel; }
		void setGenero(string gn) { genero = gn; }
		void setDPI(string dp) { DPI = dp; }
		void setFecha_Nacimiento(int fn) { fecha_nacimiento = fn; }
		void setidPuesto(string idp) { idPuesto = idp; }
		void setfecha_inicio_labores(string fchI) { fecha_inicio_labores = fchI; }
		void setfechaingreso(string fchig) { fechaingreso = fchig; }

		//get (mostrar)
		string getNombres() { return nombres; }
		string getApellidos() { return apellidos; }
		string getDireccion() { return direccion; }
		string getTelefono() { return telefono; }
		string getGenero() { return genero; }
		string getFecha_Nacimiento() { return fecha_nacimiento; }
		string getDPI() { return DPI; }
		string getidPuesto() { return idPuesto; }
		string getfecha_inicio_labores() { return fecha_inicio_labores; }
		string getfechaingreso() { return fechaingreso; }

		// CREAR
		void crear() {
			int q_estado;
			ConexionBD cn = ConexionBD();
			cout << "ingrese nombre:";
			cin >> nombres;
			cout << "ingrese apellido:";
			cin >> apellidos;
			cout << "ingrese direccion:";
			cin >> direccion;
			cout << "ingrese telefono:";
			cin >> telefono;
			cout << "ingrese dpi:";
			cin >> DPI;
			cout << "ingrese genero:";
			cin >> genero;
			cout << "ingrese fecha de nacimiento:";
			cin >> fecha_nacimiento;
			cout << "ingrese id del puesto:";
			cin >> idPuesto;
			cout << "ingrese fecha de inicio de labores:";
			cin >> fecha_inicio_labores;
			cout << "ingrese fecha de ingreso:";
			cin >> fechaingreso;
			cn.abrir_conexion();
			if (cn.getConectar()) {
				string  insertar = "INSERT INTO empleados( nombres, apellidos, direccion, telefono, DPI, genero, fecha_nacimiento, idPuesto, fecha_inicio_labores, fechaingreso) VALUES ('" + nombres + "','" + apellidos + "','" + direccion + "','" + telefono + "','" + DPI + "','" + genero + "','" + fecha_nacimiento + "','" + idPuesto + "','" + fecha_inicio_labores + "','" + fechaingreso + "')";
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
	//LEER
	void leer() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {

			cout << "\n------------ Datos de los Empleados ------------" << endl;
			string consulta = "select * from empleados";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "," << fila[1] << "," << fila[2] << "," << fila[3] << "," << fila[4] << "," << fila[5] << "," << fila[6] <<"," << fila[7] << "," << fila[8] << "," << fila[9] << endl;
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
		string  id, nombres1, apellidos1, direccion1, telefono1, DPI1, genero1, fecha_nacimiento1, idPuesto1, fecha_inicio_labores1, fechaingreso1;
		cout << "\ningrese Id de empleado a modificar:";
		cin >> id;
		cout << "ingrese nombre:";
		cin >> nombres1;
		cout << "ingrese apellido:";
		cin >> apellidos1;
		cout << "ingrese direccion:";
		cin >> direccion1;
		cout << "ingrese telefono:";
		cin >> telefono1;
		cout << "ingrese dpi:";
		cin >> DPI1;
		cout << "ingrese genero:";
		cin >> genero1;
		cout << "ingrese fecha de nacimiento:";
		cin >> fecha_nacimiento1;
		cout << "ingrese id del puesto:";
		cin >> idPuesto1;
		cout << "ingrese fecha de inicio de labores:";
		cin >> fecha_inicio_labores1;
		cout << "ingrese fecha de ingreso:";
		cin >> fechaingreso;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string actualizar = "UPDATE `db_punto_venta`.`empleados` SET `nombres` = '" + nombres1 + "', `apellidos` = '" + apellidos1 + "', `direccion` = '" + direccion1 + "', `telefono` = '" + telefono1 + "',`DPI` = '" + DPI1 + "' ,`genero` = '" + genero1 + "', `fecha_nacimiento` = '" + fecha_nacimiento1 + "', `fecha_inicio_labores` = '" + fecha_inicio_labores1 + "' WHERE (`idEmpleado` ='" + id + "')";
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
			cout << "\ningrese Id del Empleado a eliminar:";
			cin >> id;
			cn.abrir_conexion();		
			if (cn.getConectar()) {
				
				string eliminar = "DELETE FROM empleados WHERE (idEmpleado = '" + id + "')";
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

