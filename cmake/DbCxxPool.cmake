
FILE( GLOB BUILD_SRC_CPP_SOURCE "${XNS_ROOT_DIR}/DbCxxPool/src/*.cpp" )

ADD_LIBRARY( DbCxxPool ${BUILD_SRC_CPP_SOURCE})

