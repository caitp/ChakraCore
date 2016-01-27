set (SOURCES
  Api.cpp
  cfglogger.cpp
  CommonCommonPch.cpp
  DateUtilities.cpp
  DaylightTimeHelper.cpp
  Event.cpp
  Int32Math.cpp
  Int64Math.cpp
  Jobs.cpp
  MathUtil.cpp
  NumberUtilities.cpp
  RejitReason.cpp
  SmartFPUControl.cpp
  Tick.cpp
  unicode.cpp
  vtinfo.cpp
)

add_library (Chakra.Common.common
  ${SOURCES}
)

set_property(TARGET Chakra.Common.common PROPERTY CXX_STANDARD 11)

target_include_directories (Chakra.Common.common PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
