# CodeCounter

C++20实现的代码统计器，代码量小于100行，可以统计目录下所有代码文件的行数

## 编译

```powershell
g++ -I./include -o counter main.cpp
```

## 使用

统计某个目录

```shell
.\counter.exe C:\Users\Yezi\Desktop\working\tiktok
```

跳过某些目录下的文件

```powershell
.\counter.exe C:\Users\Yezi\Desktop\working\tiktok -exclude C:\Users\Yezi\Desktop\working\tiktok\kitex\kitex_gen
```
