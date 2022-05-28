#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include "ConexionBD.h"
using namespace std;

class Compras_detalle {
private: string idcompra, idproducto, cantidad, precio_costo_unitario;
	   // constructor
public:
	Compras_detalle() {
	}
	Compras_detalle(string idc, string idp, string cn, string pcu) {
		idcompra = idc;
		idproducto = idp;
		cantidad = cn;
		precio_costo_unitario = pcu;

	}

	// METODOS
	//set (modificar)
	void setIdcompra(string idc) { idcompra = idc; }
	void setIdproducto(string idp) { idproducto = idp; }
	void setCantidad(string cn) { cantidad = cn; }
	void setPrecio_costo_unitario(string pcu) { precio_costo_unitario = pcu; }

	//get (mostrar)
	string getIdcompra() { return idcompra; }
	string getIdproducto() { return idproducto; }
	string getCantidad() { return cantidad; }
	string getPrecio_costo_unitario() { return precio_costo_unitario; }

	// CREAR
	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cout << "ingrese Idcompra:";
		cin >> idcompra;
		cout << "ingrese Idproducto:";
		cin >> idproducto;
		cout << "ingrese Cantidad:";
		cin >> cantidad;
		cout << "ingrese Precio costo unitario:";
		cin >> precio_costo_unitario;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string  insertar = "INSERT INTO Compras_detalles(compra_detalle) VALUES ('" + idcompra + "','" + idproducto + "', '" + cantidad + "','" + precio_costo_unitario + "')";
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

			cout << "\n------------ Datos de las compras_detalle ------------" << endl;
			string consulta = "select * from compras_detalle";
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
		string id, idcompra1, idproducto1, cantidad1, precio_costo_unitario1;
		cout << "ingrese nuevo Idcompra:";
		cin >> idcompra1;
		cout << "\ningrese Idproducto  a modificar:";
		cin >> idproducto1;
		cout << "ingrese nuevo Idproducto:";
		cin >> idproducto1;
		cout << "\ningrese Cantidad a modificar:";
		cin >> cantidad1;
		cout << "ingrese nueva Cantidad:";
		cin >> cantidad1;
		cout << "\ningrese Precio_costo_unitario a modificar:";
		cin >> precio_costo_unitario1;
		cout << "ingrese nuevo Precio_costo_unitario:";
		cin >> precio_costo_unitario1;
		cn.abrir_conexion();
		if (cn.getConectar()) {

			string actualizar = "UPDATE `db_punto_venta`.`idcompras` SET  `idcompra` = '" + idcompra1 + "' WHERE (`idProveedor` ='" + id + "')";
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
		cout << "\ningrese Id de Compras_detalle a eliminar:";
		cin >> id;
		cn.abrir_conexion();
		if (cn.getConectar()) {

			string eliminar = "DELETE FROM Compras_detalle WHERE (idCompras_detalle = '" + id + "')";
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