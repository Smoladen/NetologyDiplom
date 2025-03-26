#include <pqxx/pqxx>
#include <iostream>

int main() {
    try {
        pqxx::connection conn("dbname=search_engine user=postgres password=Smolkin@2 host=localhost");
        if (conn.is_open()) {
            std::cout << "Connected to database: " << conn.dbname() << std::endl;
        }
        else {
            std::cout << "Failed to connect" << std::endl;
        }
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
