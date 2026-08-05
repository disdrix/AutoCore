// Twin of PalToolHost_ChannelGeomUpload_Inferred.cpp (Ghidra name stable id path).
// See: docs/reconstruction/reconstructed-exact/PalToolHost_ChannelGeomUpload_Inferred.cpp
// Stable ID: aa_00730b50  VA: 0x00730b50

#include <cstdint>

uint32_t __stdcall FUN_00730b50(uint8_t* host, int channelIndex);

// Implementation lives in named clean; this twin keeps FUN_* path for tooling.
uint32_t __stdcall FUN_00730b50(uint8_t* host, int channelIndex)
{
  extern uint32_t __stdcall PalToolHost_ChannelGeomUpload_Inferred(uint8_t*, int);
  return PalToolHost_ChannelGeomUpload_Inferred(host, channelIndex);
}
