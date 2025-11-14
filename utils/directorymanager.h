#ifndef DIRECTORYMANAGER_H
#define DIRECTORYMANAGER_H

#include <QString>

/**
 * @brief DirectoryManager - 目录管理工具类
 * 
 * 提供创建和管理目录的功能
 */
class DirectoryManager
{
public:
    /**
     * @brief 创建目录
     * @param path 目录路径
     * @return true 创建成功，false 创建失败
     */
    static bool createDirectory(const QString &path);

    /**
     * @brief 创建多级目录（如果父目录不存在则自动创建）
     * @param path 目录路径
     * @return true 创建成功，false 创建失败
     */
    static bool createDirectoryRecursively(const QString &path);

    /**
     * @brief 检查目录是否存在
     * @param path 目录路径
     * @return true 存在，false 不存在
     */
    static bool directoryExists(const QString &path);

    /**
     * @brief 获取最后的错误信息
     * @return 错误信息字符串
     */
    static QString getLastError();

private:
    static QString lastError;
};

#endif // DIRECTORYMANAGER_H
