#ifndef OFFLINEMODEL_H
#define OFFLINEMODEL_H

#include <string>
#include <vector>
using namespace std;

class OfflineMessageModel
{
public:
    // 存储用户的离线消息
    void insert(int userId, string message);
    // 删除用户的离线消息
    void remove(int userId);
    // 查询指定用户是否存在离线消息
    vector<string> query(int userId);
};

#endif