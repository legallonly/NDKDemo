
#设置在编译本地库时我们需要的最小的cmake版本
cmake_minimum_required(VERSION 3.4.1)

#设置编译生成的本地库的名字为native-lib，SHARED表示编译生成的是动态链接库(这个概念前面已经提到过了)，src/main/cpp/native-lib.cpp表示参与编译的文件的路径，这里面可以写多个文件的路径。
add_library( native-lib #so文件名
             SHARED     #SHARED表示编译生成的是动态链接库
             src/main/cpp/native-lib.cpp #要编译的c\c++文件,有多个就往下添加
             src/main/cpp/myNdk.cpp
             )

#find_library 是用来添加一些我们在编译我们的本地库的时候需要依赖的一些库，
#由于cmake已经知道系统库的路径，所以我们这里只是指定使用log库，
#然后给log库起别名为log-lib便于我们后面引用，此处的log库是我们后面调试时需要用来打log日志的库，是NDK为我们提供的。
find_library( log-lib
              log )

#target_link_libraries 是为了关联我们自己的库和一些第三方库或者系统库，这里把我们把自己的库native-lib库和log库关联起来。
target_link_libraries( native-lib
                       ${log-lib} )
