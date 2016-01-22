add_library (Chakra.Common.codex Utf8Codex.cpp)

set_property(TARGET Chakra.Common.codex PROPERTY CXX_STANDARD 11)

target_include_directories (Chakra.Common.codex PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
