#ifndef CONNECTION_H
#define CONNECTION_H
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>

static QSqlDatabase createConnection()
{
    QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("word.db");
    if(!db.open())
    {
        QMessageBox::critical(0,"Cannot open database",
                "Unable to establish a database connection",QMessageBox::Cancel);
        return db;
    }
    return db;
}
#endif // CONNECTION_H
