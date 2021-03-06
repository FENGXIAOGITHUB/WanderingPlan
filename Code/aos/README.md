<br/>
<div align="center">
  <img src="https://img.alicdn.com/tfs/TB1e1U7vyAnBKNjSZFvXXaTKXXa-973-200.png" height="60">
</div>
<br/>
<div align="center">

[![Join the chat at https://gitter.im/aliosthings/Lobby](https://img.shields.io/gitter/room/aliosthings/Lobby.svg?style=flat-square)](https://gitter.im/aliosthings/Lobby?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge)

</div>
<br/>

**AliOS Things**发布于[2017年杭州云栖大会](https://yunqi.aliyun.com)， 是 AliOS 家族旗下的、面向IoT领域的、高可伸缩的物联网操作系统，于2017年10月20号宣布在[github](https://github.com/alibaba/AliOS-Things)上开源，当前最新的版本是 **AliOS Things  3.3**。

## 架构总览

**AliOS Things** 支持多种CPU架构，包括：ARM，C-Sky，MIPS，RISCV，rl78，rx600，xtensa等。

**AliOS Things** 适配了分层架构和组件架构。包括以下部分：

- BSP: 板级支持包
- HAL: 硬件适配层，包括WiFi，蓝牙，I2C, SPI, UART，Flash 等
- Kernel: 包括Rhino RTOS 内核，VFS，KV Storage，CLI，C++ 等
- Network: 包括LwIP 轻量级TCP/IP协议栈，uMesh 自组网协议栈，BLE 低功耗蓝牙协议栈，LoRaWAN 协议栈，AT Commands Module 等
- Security: 包括TLS(mbedTLS and cutomized iTLS)，ID2，SST(Trusted Storage)，Crypto，TEE(Trusted Execution Environment) 等
- AOS API: AliOS Things 提供给应用软件和组件的API
- VFS驱动框架：设备驱动提供给组件和应用的服务接口
- Component: 阿里巴巴增值和常用的物联网组件，包括LinkSDK，OTA(安全差分升级)，ulog(日志服务)，uData(传感器框架)，uLocation(定位框架)，WiFi配网 等
- Application: 丰富的示例代码

所有的模块都作为组件的形式存在，通过yaml进行配置，应用程序可以很方便的选择需要的组件。

## AliOS Things 3.3新功能介绍
- 统一的VFS接入方式，更标准的应用开发模式
- 更小的系统，yaml构建方式更直观
- 更全面的JavaScript轻应用接口支持
- 全面完善的组件、解决方案和系统文档。格式更规范与开发者友好
- 升级了LinkSDK，新增设备引导服务、设备诊断、日志上报功能；移除CoAP、Http2、Wi-Fi配网及设备绑定的支持
- 新增蓝牙配网、Wi-Fi Camera、OLED等组件，解决方案能直接调用

## AliOS Things 3.3支持硬件
**AliOS Things 3.3**版本支持官方已适配如下硬件

- HaaS100
- HaaS EDU K1


## 文档

### 快速上手


[HaaS100 快速开始](./HaaS100_Quick_Start.md)

[HaaS EDU K1 快速开始](./HaaS_EDU_K1_Quick_Start.md)

### 文档中心
请到HaaS官方网站 [文档中心](https://haas.iot.aliyun.com/)查看。

### 贡献代码

请参考：[Contributing Guideline](https://github.com/alibaba/AliOS-Things/wiki/contributing)。

### 物联网平台

AliOS Things 能帮助你更加快速地接入[阿里云物联网平台](https://iot.console.aliyun.com/quick_start)。

## 社区

* [技术交流群(钉钉)](https://img.alicdn.com/imgextra/i3/O1CN017fYxQq1qXL0gLsnGg_!!6000000005505-2-tps-1658-682.png)
* [HaaS技术社区](https://blog.csdn.net/HaaSTech)

## License

  AliOS Things 开源源码遵循 [Apache 2.0 license](LICENSE) 开源协议。

