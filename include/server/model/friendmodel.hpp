#ifndef FRIENDMODEL_H
#define FRIENDMODEL_H

#include <vector>
using namespace std;

#include "user.hpp"

class FriendModel
{
public:
    void insert(int userid, int friendid);

    // 返回好友列表
    vector<User> query(int userid);
};

#endif