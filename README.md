#injectDll
##说明
一个可以被注入执行的DLL文件
使用进程注入工具注入宿主进程后，可以显示宿主进程的内存信息
注入工具可以使用这个：[injector工具下载](http://down.uzzf.com//jxl/DllInjector_Installer.zip)
##缺陷
目前只能搜索从0x0040A000开始，长度为1FF0的内存信息
如果要修改地址范围，只能从代码中修改在重新编译使用