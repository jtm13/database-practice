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
#include "cppconn/statement.h"
#include "cppconn/prepared_statement.h" // MySQL stuff

using namespace sql::mysql;

class DataTable {
    private:

    MySQL_Driver *driver; // do not free
    std::unordered_map<int, sql::Connection *> connections; // free all of them

    protected:

    int newConnection(sql::ConnectOptionsMap);

    bool simpleQuery(int key, std::string& str);

    sql::ResultSet* query(int key, std::string& str);

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
    } // converge (not going to be used, but nice to have)

    public:

    DataTable();

    ~DataTable();

    int newConnection();

    void disconnect(int& key);
};

#endif