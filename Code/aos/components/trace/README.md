@page trace trace
# 1. 案例简介

SystemView 是一个用于分析嵌入式系统性能的工具。SystemView可以分析系统中有哪些中断、任务执行了，以及它们的先后关系。 可以完整的深入观察一个应用程序运行时的行为，它揭示了在任务运行中发生了什么，哪个中断触发了任务切换，中断和任务调用了哪个底层系统的API函数。
SystemView 可以实时分析和展示数据，帮助用户进行系统调试和问题诊断，尤其是在开发和处理具有多个任务的复杂系统时。

SystemView效果展示：

![undefined](https://img.alicdn.com/imgextra/i3/O1CN01YKD6fE1Pg2uvaaGmx_!!6000000001869-2-tps-2826-1754.png)

## 版权信息
> Apache license v2.0

# 2. 基础知识

SystemView 工作原理：

SystemView 由两个部分组成：

SystemView 的PC端程序，用于收集目标板上传的数据信息，并在不同的窗口中显示这些信息。这些记录可以保存到文件中，用于以后的分析。

SystemView 嵌入式端程序可以分析嵌入式系统的行为。它记录嵌入式系统产生的监视数据，它包含了SYSTEMVIEW和RTT。SYSTEMVIEW模块用于收集和格式化监视数据，并将数据传送给RTT。RTT模块可以将数据保存在目标板的buffer中，使用J-Link可以实现连续的记录数据。


如果想用SystemView分析我们OS的性能，我们需要把SystemView相关的代码加到我们的代码工程中一起编译。
在我们的OS代码需要记录的地方添加hook函数，用SystemView的 API代码实现这些hook函数。
当这些函数被运行时SystemView相关的代码会把数据通过Jlink发送到PC机上，PC机上的SystemView 软件会解析这些数据并通过图形化的方式展示出来。

下图展示的是SystemView的工作原理：

![undefined](https://img.alicdn.com/imgextra/i3/O1CN01zOdgDv1QHbOPuGVKY_!!6000000001951-2-tps-1991-1434.png)




#  3. 物料清单 硬件链接

## 3.1 HaaS100 硬件

[HaaS100 硬件简介](https://help.aliyun.com/document_detail/184426.html)

<img src="https://img.alicdn.com/imgextra/i4/O1CN01XxD6Xo217CB3FZnEU_!!6000000006937-2-tps-746-497.png" style="zoom:80%;" />

## 3.2 J-Link 仿真器

J-Link是德国SEGGER公司推出基于JTAG的仿真器。操作方便、连接方便、简单易学，是学习开发嵌入式开发最好最实用的开发工具。
<img src="https://img.alicdn.com/imgextra/i2/O1CN01xj35251YMCIIXuzdy_!!6000000003044-0-tps-2048-1536.jpg" alt="undefined" style="zoom:47%;" />



# 4. 案例实现

## 4.1 硬件连接

将HaaS100 SWDIO、SWCLK和地GND共3根线与J-Link仿真器连接。

| HaaS引脚编号 | HaaS引脚说明 | J-link引脚说明 |J-link引脚编号 |
| -------- | -------- | -------- |-------- |
| 41     | SWCLK     | CLK     | 9     |
| 42     | SWDIO     | TMS     | 7     |
| 40     | GND     | GND     | 8     |


硬件连接图：

<img src="https://img.alicdn.com/imgextra/i4/O1CN01RD9QyS1zD1zYKLKxv_!!6000000006679-2-tps-976-671.png" alt="undefined" style="zoom:70%;" />



## 4.2  编译AliOS Things

AliOS Things最新代码中默认集成了SystemView的功能，默认是关闭的，只需要打开Trace工具配置开关就可以使用。

打开方式：

3.3分支:
在应用package.yaml 文件 depends下添加一行- trace: master。

<img src="https://img.alicdn.com/imgextra/i3/O1CN01UiooSJ2A67n9U3FiW_!!6000000008153-2-tps-1480-1242.png" alt="undefined" style="zoom:47%;" />

编译helloworld_demo应用

cd solutions/helloworld_demo && aos make

下载镜像：aos  burn

3.1分支：
core/trace/Config.in  第10行改为default y

![undefined](https://img.alicdn.com/imgextra/i4/O1CN01SEhrdI1dRlBPNIHWU_!!6000000003733-2-tps-741-397.png)

编译helloworld_demo应用

aos make helloworld_demo@haas100 -c config && aos make

下载AliOS Things镜像。
下载步骤参考[HaaS100快速开始](https://blog.csdn.net/HaaSTech/article/details/109719850)



# 5 使用SystemView

## 5.1 下载安装SystemView
[下载地址](www.segger.com/downloads/systemview)

根据你所用的操作系统下载对应版本的SystemView，然后进行安装。

## 5.2 配置SystemView

拷贝SYSVIEW_AliOSThings.txt 文件到PC机SystemView软件安装目录 C:\Program Files\SEGGER\SystemView\Description下。

SYSVIEW_AliOSThings.txt 文件路径：

3.3 分支路径：
components/trace/Config/SYSVIEW_AliOSThings.txt
3.1分支路径：
core/trace/Config/SYSVIEW_AliOSThings.txt

## 5.3 打开SystemView PC软件
点击菜单栏Target打开 Recorder Configuration。
![undefined](https://img.alicdn.com/imgextra/i2/O1CN01szknPD1ogNbBQBZEU_!!6000000005254-2-tps-488-266.png)

参考下图配置参数信息，其中 Address 信息可以从开机串口log 中获取：
例如开机串口log中显示：_SEGGER_RTT:0x34683a1c。

![undefined](https://img.alicdn.com/imgextra/i3/O1CN01aiPYrd1Ij4DVZLR9h_!!6000000000928-2-tps-640-762.png)



## 5.4 开始采集
点击菜单栏Target打开 Start Recording
![undefined](https://img.alicdn.com/imgextra/i2/O1CN01E4UIcZ24f2Hwl6Hco_!!6000000007417-2-tps-452-258.png)

界面显示效果如下：
![undefined](https://img.alicdn.com/imgextra/i3/O1CN01YKD6fE1Pg2uvaaGmx_!!6000000001869-2-tps-2826-1754.png)

# 6 总结

通过上面的操作，相信你已经学会了使用AliOS Things上的SystemView分析工具了。我们可以通过SystemView看到OS内部的运行情况。无论是对于学习操作系统知识，还是对操作系统进行性能分析，使用SystemView分析工具都是最好的选择。借助SystemView 这款工具能够缩短调试时间，提高开发效率。

