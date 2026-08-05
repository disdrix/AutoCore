// =============================================================================
// FUN_006291e0  (twin of PhysHost_AttachObject_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_006291e0
// Address:   0x006291e0–0x00629231 (81 B / 0x51); ret 4
// Module:    autoassault.exe (image base 0x400000)
// System:    world-object / phys host
// Dual:      2026-07-29 W30-I OWN-ONLY
// Exactness: Behavior-preserving rewrite of decompiler + machine CF.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <stdint.h>

extern "C" void FUN_005b3370(int *desc, int elemSize);

// Ghidra surface name; preferred: PhysHost_AttachObject_Inferred
extern "C" void __thiscall FUN_006291e0(int *host /*ECX*/, int obj)
{
  int *vec = host + 0xf; // +0x3c
  int size;
  int nested;
  int result;
  int *hostVtbl;
  int *nestedVtbl;

  *(int **)(obj + 0x44) = host;

  if (vec[1] == (vec[2] & 0x7fffffff)) {
    FUN_005b3370(vec, 4);
  }

  size = vec[1];
  *(int *)(vec[0] + size * 4) = obj;
  vec[1] = size + 1;
  *(int *)(obj + 0x58) = size;

  nested = *(int *)(obj + 0x3c);
  nestedVtbl = *(int **)nested;
  result = ((int(__thiscall *)(int))nestedVtbl[5])(nested);

  hostVtbl = (int *)*host;
  ((void(__thiscall *)(int *, int))hostVtbl[4])(host, result);
}
