//
// Created by ivan on 19.10.21.
//

#ifndef TUS_DATABASE_H
#define TUS_DATABASE_H
/// mysqlcppconn
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include <mysql_driver.h>

namespace tus::dss::core
{
    class DataBase
    {
    public:
        DataBase();
    private:
        sql::Driver*  m_driver = nullptr;
        std::unique_ptr<sql::Connection> m_connection;
        std::unique_ptr<sql::Statement> m_stm;
        std::unique_ptr<sql::ResultSet> m_sqlRes;
        std::unique_ptr<sql::PreparedStatement> m_prepStm;
    };
}

#endif //TUS_DATABASE_H
