#include "DataTable.h"
#include <iostream>

using namespace sql::mysql;
using std::cout, std::endl;

DataTable::DataTable(): driver(get_mysql_driver_instance()) {} // Constructor

DataTable::~DataTable() {
    for (auto t = connections.begin(); t != connections.end(); t++) {
        if (t->second == nullptr) continue;
        delete t->second;
    } // for all of the connections
} // Destructor

int DataTable::newConnection(sql::ConnectOptionsMap options) {
    int t;
    try {
        sql::Connection* con = driver->connect(options);
        do {
            t = rand();
        } while (connections.count(t) == 1); // while t is a key to another connection
        connections[t] = con;
    } catch (sql::SQLException &e) {
        cout << "# ERR: SQLException in " << __FILE__
             << "(" << __FUNCTION__ << ") on line " 
             << __LINE__ << endl
             << "# ERR: " << e.what()
             << " (MySQL error code: " << e.getErrorCode()
             << ", SQLState: " << e.getSQLState() << " )" << endl;
    } // catch
    return t;
} // newConnection

void DataTable::disconnect(int& key) {
    if (connections.count(key) == 1 && connections[key] != nullptr) {
        delete connections[key];
    } else if (connections.count(key) == 0) {
        key = -1;
    } else {
        key = -2;
    }
} // disconnect

bool DataTable::simpleQuery(int key, std::string& str) {
    try {
        if (connections.count(key) == 0) {
            str = "There is no connection in this key";
            return false;
        }
        sql::Statement* st = connections[key]->createStatement();
        bool b = st->execute(str);
        delete st;
        return b;
    } catch (sql::SQLException &e) {
        cout << "# ERR: SQLException in " << __FILE__ 
             << "(" << __FUNCTION__ << ") on line " 
             << __LINE__ << endl
             << "# ERR: " << e.what()
             << " (MySQL error code: " << e.getErrorCode()
             << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
    return false;
} // simpleQuery

sql::ResultSet* DataTable::query(int key, std::string& str) {
    try {
        if (connections.count(key) == 0) {
            str = "There is no connection in this key";
            return nullptr;
        }
        sql::ResultSet* res;
        sql::Statement* st = connections[key]->createStatement();
        res = st->executeQuery(str);
        delete st;
        return res;
    } catch (sql::SQLException &e) {
        cout << "# ERR: SQLException in " << __FILE__
             << "(" << __FUNCTION__ << ") on line " 
             << __LINE__ << endl
             << "# ERR: " << e.what()
             << " (MySQL error code: " << e.getErrorCode()
             << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
    return nullptr;
} // query

