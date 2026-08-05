// =============================================================================
// FUN_00461720  — twin of StdVector_EraseRange_RcElem28
// -----------------------------------------------------------------------------
// Stable ID: aa_00461720
// Address:   0x00461720  (autoassault.exe, image base 0x400000)
// Body:      0x00461720 – 0x0046177F exclusive (95 B / 0x5F)
// Wave:      W36-N OWN-ONLY dual 2026-07-29
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

struct RcElem28 {
  uint32_t dw0;
  uint32_t dw1;
  uint32_t dw2;
  uint32_t dw3;
  void* shared;
  uint8_t b14;
  uint8_t b15;
  uint8_t b16;
  uint32_t dw18;
};

struct StdVectorRc28 {
  void* unknown0;
  RcElem28* begin;
  RcElem28* end;
};

extern "C" RcElem28** StdVector_EraseRange_RcElem28(
    StdVectorRc28* vec,
    RcElem28** outIt,
    RcElem28* first,
    RcElem28* last);

// Ghidra: int * FUN_00461720(int param_1,int *param_2,int param_3,int param_4)
// Sealed retail ABI: stdcall vec*/outIt*/first/last, RET 0x10, stride 0x1c.
// Port via StdVector_EraseRange_RcElem28; this twin keeps the Ghidra symbol.
extern "C" int* FUN_00461720(int param_1, int* param_2, int param_3, int param_4)
{
  return reinterpret_cast<int*>(StdVector_EraseRange_RcElem28(
      reinterpret_cast<StdVectorRc28*>(param_1),
      reinterpret_cast<RcElem28**>(param_2),
      reinterpret_cast<RcElem28*>(param_3),
      reinterpret_cast<RcElem28*>(param_4)));
}
