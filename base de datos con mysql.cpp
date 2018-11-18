//programa hecho por Jesus Steven Medrano Carballo
//Carnet: MC18055

#include <cstdlib>// archivo de cabecera de la biblioteca
#include <iostream> // para operaciones de entrada y salida
#include <winsock2.h> // archivo cabecera de windows y tiene las funciones de windows api
#include <mysql.h> // nos permite hacer el uso de las conexiones y consultas con mysql
#include <mysqld_error.h>
using namespace std;

int main(int argc, char *argv[])
{  
    MYSQL *conn;// variable de conexion
    MYSQL  mysql;
    MYSQL_RES *res;// variable que contendra el resultado
    MYSQL_ROW row;// variable que contendra los campos por cada registro consultado
    mysql_init(&mysql);
    conn=mysql_real_connect(&mysql,"localhost","root","","practica2",0,0,0);//direccion del servidor
    
    if(conn==NULL)
    {  cout<<mysql_error(&mysql)<<endl;//si hay error definir dicho error
       system("pause"); //hacemos una pausa
        
    }
    cout<<"consultas sobre la base de datos"<<endl<<endl;
    
    cout<<"\t clientes"<<endl<<endl;//muestra en pantalla el titulo de la funcion que se desarrolla
    
     mysql_query(conn,"select * from clientes");
    res=mysql_store_result(conn);
    
    while((row=mysql_fetch_row(res))!=NULL)// recorrer la variable con todos los registros
    
    {//la variable row se convierte en un arreglo por el numero de campos en la tabla
        cout<<row[0]<<"\n nombre: ";
        cout<<row[1]<<"\t apellido: ";
        cout<<row[2]<<"\n tel: ";
        cout<<row[3]<<endl<<endl;
    }
    cout<<"\t productos"<<endl<<endl;//muestra en pantalla el titulo de la funcion que se desarrolla
    
    mysql_query(conn,"select * from productos");
    res=mysql_store_result(conn);
    
    while((row=mysql_fetch_row(res))!=NULL)
    {
    	//la variable row se convierte en un arreglo por el numero de campos en la tabla
        cout<<row[0]<<"\t";
        cout<<row[1]<<"\t";
        cout<<row[2]<<"\t";
        cout<<row[3]<<"\t";
        cout<<row[4]<<endl;
    }
    cout<<"\t ventas"<<endl<<endl;//muestra en pantalla el titulo de la funcion que se desarrolla
    
    mysql_query(conn,"select * from ventas");
    res=mysql_store_result(conn);
    
    while((row=mysql_fetch_row(res))!=NULL)
    {
    	//la variable row se convierte en un arreglo por el numero de campos en la tabla
        cout<<row[0]<<"\t";
        cout<<row[1]<<"\t";
        cout<<row[2]<<"\t";
        cout<<row[3]<<"\t";
        cout<<row[4]<<endl;
    }
    
   mysql_close(conn);
    cout<<"se conecto"<<endl;// declaramos que los usuarios se conectaron
    system("pause");// hacemos una pausa
    return 0;// no retorna ningun valor
}

