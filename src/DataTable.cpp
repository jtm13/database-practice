#include "DataTable.h"
#include "private/info.h" // personal info

using namespace sql::mysql;

DataTable::DataTable(std::string tab = "BANK"): driver(get_mysql_driver_instance()), table(tab){} // Constructor

DataTable::~DataTable() {
    for (auto t = connections.begin(); t != connections.end(); t++) {
        if (t->second == nullptr) continue;
        delete t->second;
    } // for all of the connections
} // Destructor

int DataTable::newConnection(sql::ConnectOptionsMap options) {
    sql::Connection* con = driver->connect(options);
    int t;
    do {
        t = rand();
    } while (connections.count(t) == 1); // while t is a key to another connection
    connections[t] = con;
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

bool DataTable::query(int key, std::string first, std::string& str) {
    if (connections.count(key) == 0) {
        str = "There is no connection in this key";
        return false;
    }
    sql::Statement* st = connections[key]->createStatement();
    bool b = st->execute(first + str);
    delete st;
    return b;
} // query

bool DataTable::insert(int key, std::string& str) {
    return query(key, "INSERT INTO " + table + " ", str);
} // insert

bool DataTable::update(int key, std::string& str) {
    return query(key, "UPDATE " + table + " SET ", str);
} // update

bool DataTable::deleteFunc(int key, std::string& str) {
    return query(key, "DELETE FROM " + table + " WHERE ", str);
} // deleteFunc

std::string DataTable::getTable() {
    return table;
} // getTable

void DataTable::setTable(std::string newTable) {
    table = newTable;
} // setTable
