#include <string>
#include <muduo/base/Logging.h>
using namespace std;

#include "offlinemessagemodel.hpp"
#include "db.h"

void OfflineMessageModel::insert(int userId, string message)
{
    char sql[1024] = {0};

    sprintf(sql, "insert into offlineMessage (userid, message) values (%d, '%s')", userId, message.c_str());

    MySQL mysql;
    if (mysql.connect())
    {
        mysql.update(sql);
        return;
    }
}

void OfflineMessageModel::remove(int userId)
{
    char sql[1024] = {0};

    sprintf(sql, "delete from offlineMessage where userid=%d", userId);

    MySQL mysql;
    if (mysql.connect())
    {
        mysql.update(sql);
        return;
    }
}

vector<string> OfflineMessageModel::query(int userId)
{
    char sql[1024] = {0};
    vector<string> msg;

    sprintf(sql, "select message from offlineMessage where userid=%d", userId);

    MySQL mysql;
    if (mysql.connect())
    {
        MYSQL_RES *res = mysql.query(sql);
        if (res != nullptr)
        {
            MYSQL_ROW row;
            while ((row = mysql_fetch_row(res)) != nullptr)
            {
                msg.push_back(row[0]);
            }
            mysql_free_result(res);
            return msg;
        }
    }
    return msg;
}
