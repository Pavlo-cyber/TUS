//
// Created by ivan on 19.10.21.
//

#include "tus/dss/core/DataBase.h"

tus::dss::core::DataBase::DataBase()
{
    const std::string hostname = "localhost";
    const std::string userName = "pavlo";
    const std::string password = "1111";
    const std::string database = "TUS_DB";

    m_driver = get_driver_instance();
    m_connection.reset(m_driver->connect(hostname,userName,password));
    if(m_connection)
    {
        if (!database.empty())
            m_connection->setSchema(database);
        m_stm.reset(m_connection->createStatement());
        if (!m_stm)
            throw std::runtime_error("Statement is not created.");
    }
    else
        throw std::runtime_error("Connection is not established.");
}
