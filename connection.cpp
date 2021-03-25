#include "connection.h"
#include "client.h"
Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("ProjetQT");//inserer le nom de la source de données ODBC
db.setUserName("amine");//inserer nom de l'utilisateur
db.setPassword("amine");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
