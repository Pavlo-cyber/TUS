# Tutor service

### Requirements:
- C++ VERSION 17
- Cmake VERSION 3.19
- Boost VERSION 1.76.0
- libprotoc 3.17.3
- grpc 1.41
- mysqlcppconn 9.8.0.26

### System components:
- DOM : domain objects
``Main purpose of DOM is to define classes that are used in given system and their behaviour(interactions between each other)``
- DSS : data storage service
``Provides API for managing database``
- CMS
``Communication service. Provides serivces for talking with back-end``
- Doc
``Exists for documentation and UML diagrams``
- Front
`` Front end to interact with system``