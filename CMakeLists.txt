CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(test
        op.cpp
        rand.cpp
        pow.cpp
        mult.cpp
        div.cpp
        add.cpp
        sub.cpp
        binary_iterator.cpp
	countvisitor.cpp
	preorder_iterator.cpp
	unit_test.cpp
)

ADD_EXECUTABLE(main
        op.cpp
        rand.cpp
        pow.cpp
        mult.cpp
        div.cpp
        add.cpp
        sub.cpp
        binary_iterator.cpp
        countvisitor.cpp
        preorder_iterator.cpp
        main.cpp
)



TARGET_LINK_LIBRARIES(test  gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
