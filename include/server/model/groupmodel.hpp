#ifndef GROUPMODEL_H
#define GROUPMODEL_H

#include <vector>
#include <string>
using namespace std;

#include "group.hpp"

class GroupModel
{
public:
    bool createGroup(Group &group);
    // 查询用户所在的所有群组
    vector<Group> queryGroups(int userid);
    // 用户加入指定群组
    void addGroup(int userid, int groupid, string role);
    // 根据给定的groupid查询群组中其他成员，用于群组聊天时发送消息
    vector<int> queryGroupUsers(int userid, int groupid);
};

#endif