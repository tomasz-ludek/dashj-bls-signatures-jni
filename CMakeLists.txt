cmake_minimum_required(VERSION 3.4.1)

add_library( # Sets the name of the library.
        dashjbls

        # Sets the library as a shared library.
        SHARED

        # Provides a relative path to your source file(s).
        src/org_dash_bls_BlsJni.cpp
)

message(STATUS "CMAKE_SOURCE_DIR=${CMAKE_SOURCE_DIR}")

find_package(JNI)
if (JNI_FOUND)
    message (STATUS "JNI_INCLUDE_DIRS=${JNI_INCLUDE_DIRS}")
    message (STATUS "JNI_LIBRARIES=${JNI_LIBRARIES}")
endif()

include_directories(${JNI_INCLUDE_DIRS}
					${CMAKE_SOURCE_DIR}/src
					${CMAKE_SOURCE_DIR}/src/bls-signatures/src
					${CMAKE_SOURCE_DIR}/src/bls-signatures/build/contrib/relic/include
					${CMAKE_SOURCE_DIR}/src/bls-signatures/contrib/relic/include
)

target_link_libraries( # Specifies the target library.
        dashjbls

        # Links the target library to the log library
        # included in the NDK.
        ${CMAKE_SOURCE_DIR}/src/bls-signatures/build/libbls.a
)
					
#project(libblsjni_project)
#add_library(blsjni SHARED blsjni.cpp)
#target_link_libraries(myapp ${CMAKE_SOURCE_DIR}/libbls.a)

#install(TARGETS blsjni DESTINATION lib)
#install(FILES blsjni.h DESTINATION include)