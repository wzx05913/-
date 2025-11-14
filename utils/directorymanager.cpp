#include "directorymanager.h"
#include <QDir>
#include <QDebug>

QString DirectoryManager::lastError = "";

bool DirectoryManager::createDirectory(const QString &path)
{
    lastError.clear();
    
    if (path.isEmpty()) {
        lastError = "目录路径不能为空";
        qDebug() << lastError;
        return false;
    }

    QDir dir;
    if (dir.exists(path)) {
        lastError = "目录已存在";
        qDebug() << lastError << ":" << path;
        return true; // 目录已存在，视为成功
    }

    if (dir.mkdir(path)) {
        qDebug() << "目录创建成功:" << path;
        return true;
    } else {
        lastError = "创建目录失败";
        qDebug() << lastError << ":" << path;
        return false;
    }
}

bool DirectoryManager::createDirectoryRecursively(const QString &path)
{
    lastError.clear();
    
    if (path.isEmpty()) {
        lastError = "目录路径不能为空";
        qDebug() << lastError;
        return false;
    }

    QDir dir;
    if (dir.exists(path)) {
        lastError = "目录已存在";
        qDebug() << lastError << ":" << path;
        return true; // 目录已存在，视为成功
    }

    if (dir.mkpath(path)) {
        qDebug() << "目录创建成功（递归）:" << path;
        return true;
    } else {
        lastError = "创建目录失败（递归）";
        qDebug() << lastError << ":" << path;
        return false;
    }
}

bool DirectoryManager::directoryExists(const QString &path)
{
    if (path.isEmpty()) {
        return false;
    }

    QDir dir(path);
    return dir.exists();
}

QString DirectoryManager::getLastError()
{
    return lastError;
}
