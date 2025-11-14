#ifndef GLOBAL_H
#define GLOBAL_H
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include "user.h"
#include "company.h"
extern User *curUser;
extern std::vector<Company*> companies;
#endif // GLOBAL_H
