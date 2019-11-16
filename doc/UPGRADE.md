#升级指南
#更新日志
修复：
	ctrl-c无法关闭服务器
    KillActor适配问题
删除：
    shop功能
增加：
    Form GUI支持
    opti指定红石限制，生物生成限制
    json配置文件，热重载配置文件
优化：
    领地性能
    API逻辑
#新文件
config文件夹为插件加载必须
新插件cdk.so gui.so cmdhelp.so transfer.so等
对于面板提供商：
请在服务器模板文件增加config文件夹，更新a.so
对于个人用户：
请从git repo目录复制config文件夹至服务器目录
