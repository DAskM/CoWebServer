#include <iostream>
#include <mysql/mysql.h>
using namespace std;

int main()
{

    MYSQL *_conn;
    string server = "127.0.0.1";
    string user = "root";
    string password = "123456";
    string dbname = "chat";

    MYSQL *p = mysql_real_connect(_conn, server.c_str(), user.c_str(),
                                  password.c_str(), dbname.c_str(), 3306, nullptr, 0);
    if (p != nullptr)
    {
        mysql_query(_conn, "set names gbk");
        cout << "连接成功" << endl;
    }
    else
    {
        cout << "=-= !" << endl;
    }
    return 0;
}