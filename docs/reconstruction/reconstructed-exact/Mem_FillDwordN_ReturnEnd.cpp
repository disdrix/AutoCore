// =============================================================================
// Mem_FillDwordN_ReturnEnd
// -----------------------------------------------------------------------------
// Stable ID: aa_004651d0
// Address:   0x004651d0  (autoassault.exe, image base 0x400000)
// Body:      0x004651d0–0x004651f0 (33 bytes through bare ret)
// System:    stl-helpers / POD fill
// Generated: 2026-07-29 W22-T dual seal (decompile + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Fill N consecutive dwords at dest with *value (re-read each iteration).
//   Return dest + N (write end) for chaining after vector realloc prefix copy.
//
// ABI (custom register — not standard thiscall/stdcall):
//   EDI = dest (uint32_t *)
//   ESI = count (element count)
//   EDX = value pointer (uint32_t const *)
//   bare ret (no stack formals)
//   EAX out = dest + count  (lea eax,[edi+esi*4])
//
// ISA: leaf integer mov loop; push/pop ebx; lea esp,[esp+0] NOP in hot path.
// Ghidra: FUN_004651d0

#include <stdint.h>

// Register ABI cannot be expressed portably; document contract in signature comment.
// Portable semantic equivalent (normal C++ calling convention):
uint32_t *Mem_FillDwordN_ReturnEnd(uint32_t *dest, int count, uint32_t const *value)
{
  uint32_t *p = dest;
  for (int i = count; i != 0; i = i - 1) {
    *p = *value;
    p = p + 1;
  }
  return dest + count;
}

// Scaffold alias kept for Ghidra symbol search:
//   FUN_004651d0 == Mem_FillDwordN_ReturnEnd
