# Utils - 工具类

## DirectoryManager - 目录管理器

目录管理工具类，提供创建和管理目录的功能。

### 功能

1. **创建目录** - `createDirectory()`
2. **递归创建目录** - `createDirectoryRecursively()`
3. **检查目录是否存在** - `directoryExists()`
4. **获取错误信息** - `getLastError()`

### 使用示例

```cpp
#include "utils/directorymanager.h"

// 创建单层目录
if (DirectoryManager::createDirectory("data")) {
    qDebug() << "目录创建成功";
} else {
    qDebug() << "错误:" << DirectoryManager::getLastError();
}

// 递归创建多层目录
if (DirectoryManager::createDirectoryRecursively("data/users/exports")) {
    qDebug() << "多层目录创建成功";
}

// 检查目录是否存在
if (DirectoryManager::directoryExists("data")) {
    qDebug() << "目录存在";
}
```

### 说明

- 使用 Qt 的 `QDir` 类实现，跨平台兼容
- 所有方法都是静态方法，无需实例化
- 支持相对路径和绝对路径
- 如果目录已存在，创建操作会返回成功（true）
- 错误信息通过 `getLastError()` 获取

### 实际应用场景

1. **应用程序初始化时创建数据目录**（见 main.cpp）
2. **导出功能需要创建临时目录**
3. **日志系统需要创建日志目录**
4. **用户数据按日期组织时创建日期目录**

### 方法区别

- `createDirectory()` - 只创建单层目录，父目录必须存在
- `createDirectoryRecursively()` - 递归创建目录，会自动创建所有不存在的父目录（推荐使用）
