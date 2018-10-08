cmake_minimum_required(VERSION 3.4.1)

add_library( native-lib # 库的名称
             SHARED # 库的类型 动态 ，如果是静态库 STATIC
             src/main/cpp/native-lib.cpp ) # c++ 文件的路径

#    # 使用系统集成的动态库
#    find_library( log-lib # 动态库别名
#                  log ) # 实际动态库名称
#
#    # 连接动态库
#    target_link_libraries( native-lib
#                          ${log-lib} ) # 动态库别名

# 也可以写成：

   # 连接动态库
   target_link_libraries( native-lib
                        log )
