#ifndef DATATABLE_H
#define DATATABLE_H

#include <unordered_map>
#include <string>
#include <cstdio> // for sprintf
#include <cstring> // memset
#include <cerrno> // error for sprintf

#include "mysql_connection.h"
#include "mysql_driver.h"
#include "cppconn/driver.h"
#include "cppconn/exception.h"
#include "cppconn/resultset.h"
#include "cppconn/statement.h" // MySQL stuff

using namespace sql::mysql;

class DataTable {
    private:

    MySQL_Driver *driver; // do not free
    std::unordered_map<int, sql::Connection *> connections; // free all of them
    std::string table;

    int newConnection(sql::ConnectOptionsMap);

    bool query(int key, std::string first, std::string& str);

    template<typename... Args>
    void converge(std::string &str, Args... arg) {
        int sz = std::snprintf(nullptr, 0, str, arg);
        char b[sz + 1];
        memset(b, '\0', sizeof(b));
        if (sz != std::sprintf(b, str, arg)) {
            perror("You messed up " + errno + ": \n");
            str = "Invalid";
        } else {
            str = b;
        }
    }

    public:

    DataTable(std::string tab = "BANK");

    ~DataTable();

    int newConnection();

    void disconnect(int& key);

    bool insert(int key, std::string &);

    template<typename... Args>
    bool insert(int key, std::string &str, Args... arg) {
        converge(str, arg);
        if (str == "Invalid") {
            return false;
        }
        return insert(key, str);
    } // overloaded insert

    bool deleteFunc(int key, std::string& str);

    template<typename... Args>
    bool deleteFunc(int key, std::string& str, Args... arg) {
        converge(str, arg);
        if (str == "Invalid") {
            return false;
        }
        return deleteFunc(key, str);
    } // overloaded deleteFunc

    bool update(int key, std::string& str);

    template<typename... Args>
    bool update(int key, std::string& str, Args... arg) {
        converge(str, arg);
        if (str == "Invalid") {
            return false;
        }
        return update(key, str);
    } // overloaded update

    std::string getTable();

    void setTable(std::string newTable);
};

#endif