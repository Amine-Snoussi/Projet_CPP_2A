#include "client.h"
#include "connection.h"
Client::Client()
{
    id_client=0;
    nom="";
    prenom="";
    Email="nom@domaine.com";
    adresse="";
    ville="";
    codePostal=0;
    numTel="";

}

Client::Client(int id,QString Nom,QString Prenom,QString mail,QString ad,QString ville,int cp,QString tel)
{
    id_client=id;
    Nom=nom;
    Prenom=prenom;
    Email=mail;
    adresse=ad;
    this->ville=ville;
    codePostal=cp;
    numTel=tel;

}




QSqlQueryModel * Client::afficher(){

    QSqlQueryModel * modal=new QSqlQueryModel();
    modal->setQuery("SELECT *FROM CLIENT");

    return modal;

}



bool Client::ajouter(){

    QSqlQuery query;


    query.prepare("INSERT INTO CLIENT (ID_CLIENT,NOM,PRENOM,NUMERO,EMAIL,ADRESSE,VILLE,CODE_POSTAL,TEL) "
                        "VALUES (:nom,:prenom,:email,:adresse,:ville,:code_postale,:tel)");
    query.bindValue(":nom",nom );
    query.bindValue(":prenom",prenom); //remplir la valeur d'une maniere securisée
    query.bindValue(":email", Email);
    query.bindValue(":adresse",adresse);
    query.bindValue(":ville",ville);
    query.bindValue(":code_postale",codePostal);
    query.bindValue(":tel",numTel);


    return    query.exec();

}


bool Client::modifier(){

    QSqlQuery query;


    query.prepare("UPDATE CLIENT SET ID_CLIENT= :id_client , NOM= :nom , PRENOM= :prenom "
                  ",EMAIL= :email , ADRESSE= :adresse , VILLE= :ville , CODE_POSTAL= :code_postale ,TEL= :tel , FAX= :fax"
                  "where id_Client= :id_Client"); //remplir la valeur d'une maniere securisée
    query.bindValue(":id_Client",id_client );
    query.bindValue(":nom",nom );
    query.bindValue(":prenom",prenom);
    query.bindValue(":email", Email);
    query.bindValue(":adresse",adresse);
    query.bindValue(":ville",ville);
    query.bindValue(":code_postale",codePostal);
    query.bindValue(":tel",numTel);

    return    query.exec();


}




bool Client::supprimer (QString id_clientSelectionne)
{
    QSqlQuery query;
    query.prepare("Delete from Client where id_Client = :id_Client");
    query.bindValue(":id_Client",id_clientSelectionne);
    return    query.exec();


}
