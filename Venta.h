#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include "ConexionBD.h"
using namespace std;


class venta {
private: string NoFactura,serie,idCliente, idEmpleado;
	   // constructor
public:
	venta() {
	}
	venta (string nf, string ser, string ic, string ie) {
		NoFactura = nf;
		serie = ser;
		idCliente = ic;
		idEmpleado = ie;

	}

	// METODOS
	//set (modificar)
	void setNoFactura(string nf) { NoFactura = nf; }
	void setidEmpleado(string ie) { idEmpleado = ie; }
	void setserie(string ser) { serie = ser; }
	void setidCliente(string ic) { idCliente = ic; }

		//get (mostrar)
	string getNoFactura() { return NoFactura; }
	string getidEmpleado() { return idEmpleado; }
	string getserie() { return serie; }
	string getidCliente() { return idCliente; }
	
	//CREAR
	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cout << "ingrese No. Factura:";
		cin >> NoFactura;
		cout << "Ingrese idEmpleado: ";
		cin >> idEmpleado;
		cout << "ingrese el idCliente:";
		cin >> idCliente;

		
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string  insertar = "INSERT INTO Ventas(nofactura,idcliente,idempleado) VALUES ('" + NoFactura + "','" + idEmpleado +"','" + idCliente + "')";
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
	//// ACTUALIZAR

	void Actualizar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		string id,NoFactura1, serie1, idCliente1, idEmpleado1;
		cout << "numero de idVenta a modificar :";
		cin >> id;
		cout << "ingrese NoFactura :";
		cin >> NoFactura1;
		cout << "Ingrese Serie :";
		cin >> serie1;
		cout << "Ingrese id Cliente :";
		cin >> idCliente1;
	/*	cout << "Ingrese id Empleado: ";
		cin >> idEmpleado1;*/
		cn.abrir_conexion();
		if (cn.getConectar()) {

			string actualizar = "UPDATE `db_punto_venta`.`ventas` SET  `nofactura` = '" + NoFactura1 + "',`serie` = '" + serie1 + "',`idclien` = '" + idCliente1 + "'  WHERE (`idVenta` ='" + id + "')";
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

			string eliminar = "DELETE FROM ventas WHERE (idVenta = '" + id + "')";
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

	// CREACION DE FACTURA
	void fac() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		string nitc, idemp, idp;
		cn.abrir_conexion();
		cout << "ingrese  id empleado:";
		cin >> idemp;
		cout << "ingrese NIT para Factura  (xxxxxx sin guion)  :";
		cin >> nitc;
		if (cn.getConectar()) {

			cout << "\n------------ Datos del cliente------------" << endl;
			string consulta = "select nombres, apellidos, NIT, telefono from clientes where (NIT = '" + nitc + "')";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "," << fila[1] << "," << fila[2] << "," << fila[3] << "," << endl;

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

	
	
		//cn.abrir_conexion();
		//if (cn.getConectar()) {
		//	string  insertar = "INSERT INTO Ventas(nofactura,serie,idcliente,idempleado) VALUES ('" + NoFactura + "','" + idEmpleado + "','" + serie + "','" + idCliente + "')";
		//	const char* i = insertar.c_str();
		//	// executar el query
		//	q_estado = mysql_query(cn.getConectar(), i);
		//	if (!q_estado) {
		//		cout << "\n Ingreso Exitoso ..." << endl;
		//	}
		//	else {
		//		cout << " xxx Error al Ingresar  xxx" << endl;
		//	}
		//}
		//else {
		//	cout << " xxx Error en la Conexion xxxx" << endl;
		//}
		//cn.cerrar_conexion();
	}
	// LEER
	void datosfac() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		string idv;
		cout << "ingrese  id venta :";
		cin >> idv;
		cn.abrir_conexion();

		if (cn.getConectar()) {

			cout << "\n------------ Datos de las ventas------------" << endl;
			string consulta3 = "select T1.nofactura , T1.fechafactura , T4.NIT , T4.nombres, T4.apellidos, T3.producto,T2.cantidad, T3.precio_venta from ventas as T1 join ventas_detalle as T2 on T1.idVenta = T2.idVenta join productos as T3 on T2.idProducto = T3.idProducto join clientes as T4 on T1.idCliente = T4.idCliente where ( T1.idVenta = '" + idv + "')";
			const char * c3 = consulta3.c_str();
			q_estado = mysql_query(cn.getConectar(), c3);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout <<fila[0] << "," << fila[1] << "," << fila[2] << "," << fila[3] << "," << fila[4] << "," << fila[5] << "," << fila[6] << "," << fila[7] << "," << endl;
					cout << "TOTAL:					5.00";
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


};




