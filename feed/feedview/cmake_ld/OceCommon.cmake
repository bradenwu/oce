
FILE( GLOB BUILD_SRC_CPP_SOURCE "${XNS_ROOT_DIR}/OceCommon/src/*.cpp" )

GENERATE_ARCHIVE_EACH( OceCommon "${BUILD_SRC_CPP_SOURCE}")

