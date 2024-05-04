# 配置头文件搜索路径
# include_directories()
# 配置库文件搜索路径
# link_directories()

set(SRC_LIST ./muduo_server.cpp)

# 设置可执行文件的存储位置
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# 把指定路径下的所有源文件名字加入变量名
# aux_source_directory(. SRC_LIST)

add_executable(server ${SRC_LIST})

target_link_libraries(server muduo_net muduo_base pthread)