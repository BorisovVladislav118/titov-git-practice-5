#include <iostream>
#include <pqxx/pqxx>

int main()
{
    try
    {
        pqxx::connection conn{"dbname=titov_pr1_db"};
        pqxx::work transaction{conn};

        auto result = transaction.exec(
            "SELECT current_database(), 5"
        );

        std::cout << "Database: "
                  << result[0][0].c_str() << std::endl;

        std::cout << "Variant: "
                  << result[0][1].as<int>() << std::endl;

        transaction.commit();
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
