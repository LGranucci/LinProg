cmake_minimum_required(VERSION 3.10)
project(LinProg)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        Origine.cpp
        Matrix.cpp
        )

set(HEADER_FILES
        Matrix.h
        )

# Specify the executable and its source files
add_executable(Origine.exe ${SOURCE_FILES} ${HEADER_FILES})

# Add debug flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

# If you want to include additional flags for debugging, you can customize them
# For example, include debugging symbols and enable optimization
 set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0")

# Specify any additional libraries or dependencies if needed
# target_link_libraries(YourExecutableName YourAdditionalLibraries)

# Optionally, set the output directory for the compiled executable
# set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

# Optionally, set the output directory for compiled object files
# set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)

# Optionally, set the output directory for compiled shared libraries
# set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)

# As you can see, this is gently offered by chatgpt
