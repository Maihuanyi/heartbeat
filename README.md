# Heartbeat(心跳灯)软件包
## 1.简介

基于软件定时器实现的heartbeat(心跳灯)。

### 1.1目录结构

`Heartbeat` 软件包目录结构如下所示：

``` 
heartbeat
├───src                         // 源码目录
│   │───SConscript              // RT-Thread 默认的构建脚本
│   └───heartbeat.c             // 主模块
│   license                     // 软件包许可证
│   README.md                   // 软件包使用说明
└───SConscript                  // RT-Thread 默认的构建脚本
```

### 1.2许可证

 Heartbeat package 遵循 LGPLv2.1 许可，详见 `LICENSE` 文件。

### 1.3依赖

- RT_Thread 3.0+

## 2.如何使用
使用 Heartbeat package 需要在 RT-Thread 的包管理器中选择它，具体路径如下：
```
RT-Thread online packages
    peripheral libraries and drivers --->
        [*] heartbeat: A heartbeat led package
```

### 2.3配置参数说明

| 参数宏 | 说明 |
| ---- | ---- |
| PKG_HEARTBEAT_LED_PIN 		 | 配置heartbeat的引脚
| PKG_USING_HEARTBEAT 	       	 | 使能heartbeat
| PKG_HEARTBEAT_LED_ACTIVE_LOGIC | led的有效电平

## 3. 联系方式

* 维护：Chasel
* 主页：https://github.com/Maihuanyi/heartberat.git
* 邮箱：m19825309307@163.com