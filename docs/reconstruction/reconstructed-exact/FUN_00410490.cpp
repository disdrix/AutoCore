// =============================================================================
// FUN_00410490 / StdVector_EraseRange_Dword_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00410490
// Address:   0x00410490  (autoassault.exe, image base 0x400000)
// System:    STL / container utility (dword vector)
// Generated: 2026-07-29 dual seal (W16-S); raw capture 2026-07-23
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE:
//   MSVC-style range erase for a vector of dword (4-byte) POD elements:
//     if first != last:
//       size = ((end - last) >> 2) * 4;   // bytes in tail [last, end)
//       memmove(first, last, size);       // close the hole
//       end = first + size;               // rebind end @ this+8
//     *outIt = first;
//
//   No dtor calls, no capacity change, no free of the buffer.
//
// ABI: __thiscall (ECX = vector); stack (outIt*, first, last); ret 0xC.
// Layout: end pointer at this+8 (begin typically this+4, formed by callers).
//
// Callers (shrink / erase consumers):
//   FUN_00410420, FUN_004365e0, FUN_004367f0 (StdVector_DwordResize shrink),
//   FUN_00449000.

// READABILITY:
//  - Control keywords: if×1, return×1.
//  - Notable callees: memmove (IAT).
//  - Element width: 4 bytes (>>2 / *4).

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile + read_memory (2026-07-29).
 * - Size math ((end-last)>>2)*4 is identity on dword-aligned pointers; keeps
 *   MSVC-style dword scaling visible in the clean body.
 * - Runtime / differential verification: OPEN.
 */

#include <stddef.h>

void *__cdecl memmove(void *dst, const void *src, size_t size);

void __thiscall FUN_00410490(int param_1 /* this */,
                             void **param_2 /* outIt */,
                             void *param_3 /* first */,
                             void *param_4 /* last */)
{
  size_t _Size;
  void *pvVar1;

  if (param_3 != param_4) {
    _Size = (*(int *)(param_1 + 8) - (int)param_4 >> 2) * 4;
    pvVar1 = memmove(param_3, param_4, _Size);
    *(void **)(param_1 + 8) = (void *)((int)pvVar1 + _Size);
  }
  *param_2 = param_3;
  return;
}
