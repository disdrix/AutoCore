// =============================================================================
// PhysHost_AttachObject_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_006291e0
// Address:   0x006291e0–0x00629231 (81 B / 0x51); ret 4
// Module:    autoassault.exe (image base 0x400000)
// Ghidra:    FUN_006291e0
// System:    world-object / phys host
// Dual:      2026-07-29 W30-I OWN-ONLY
// =============================================================================
//
// ABI: __thiscall  ECX = PhysHost*; stack = WorldObj*; void; ret 4
//
// CF (machine-sealed):
//   1. obj+0x44 = host
//   2. vec = host+0x3c {data, size, cap&0x7fffffff}; grow FUN_005b3370(vec,4) if full
//   3. data[size] = obj; size++; obj+0x58 = size-1
//   4. result = (*(obj+0x3c))->vtbl[+0x14]()     // this = nested
//   5. host->vtbl[+0x10](result)                 // this = host
//
// Sole caller: WorldObj_AttachRegisterHost_Inferred (0x0055e760) — three host this sources
// Nested grow: FUN_005b3370 (cdecl)

#include <stdint.h>

extern "C" void FUN_005b3370(int *desc, int elemSize);

extern "C" void __thiscall PhysHost_AttachObject_Inferred(
    int *host /*ECX*/,
    int obj)
{
  int *vec = host + 0xf; // host+0x3c
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
  *(int *)(obj + 0x58) = size; // == (size+1)-1

  nested = *(int *)(obj + 0x3c);
  nestedVtbl = *(int **)nested;
  result = ((int(__thiscall *)(int))nestedVtbl[5])(nested); // +0x14 / 4 = index 5

  hostVtbl = (int *)*host;
  ((void(__thiscall *)(int *, int))hostVtbl[4])(host, result); // +0x10 / 4 = index 4
}
