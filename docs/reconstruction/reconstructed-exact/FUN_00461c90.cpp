// =============================================================================
// FUN_00461c90  — twin of StdUninitFillN_RcElem28
// -----------------------------------------------------------------------------
// Stable ID: aa_00461c90
// Address:   0x00461c90  (autoassault.exe, image base 0x400000)
// Body:      0x00461c90 – 0x00461d74 exclusive (228 B / 0xE4)
// Wave:      W35-O OWN-ONLY dual 2026-07-29
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

struct RcShared28 {
  void** vtbl;
  int32_t refcount;
};

struct RcElem28 {
  uint32_t dw0;
  uint32_t dw1;
  uint32_t dw2;
  uint32_t dw3;
  RcShared28* shared;
  uint8_t b14;
  uint8_t b15;
  uint8_t b16;
  uint32_t dw18;
};

// Canonical implementation lives in StdUninitFillN_RcElem28.cpp
extern "C" void __fastcall StdUninitFillN_RcElem28(
    const RcElem28* value,
    int count,
    RcElem28* dest);

extern "C" void __fastcall FUN_00461c90(
    const RcElem28* value,
    int count,
    RcElem28* dest)
{
  StdUninitFillN_RcElem28(value, count, dest);
}
