// =============================================================================
// FUN_004e2e80  →  Mem_MoveDwordRange_ReturnEnd
// -----------------------------------------------------------------------------
// Stable ID: aa_004e2e80
// Address:   0x004e2e80  (autoassault.exe, image base 0x400000)
// System:    stl-helpers
// Generated: 2026-07-29 W19-C dual seal (scaffold alias of named clean)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
// Prefer: reconstructed-exact/Mem_MoveDwordRange_ReturnEnd.cpp

#include <cstring>
#include <cstddef>

// __stdcall ret 0xC
void * FUN_004e2e80(void *param_1, int param_2, void *param_3)
{
  size_t _Size;
  void *pvVar1;

  _Size = (param_2 - (int)param_1 >> 2) * 4;
  pvVar1 = memmove(param_3, param_1, _Size);
  return (void *)((int)pvVar1 + _Size);
}
