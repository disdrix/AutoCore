// =============================================================================
// NDResource_DecRef  (Ghidra: FUN_00745ea0)
// -----------------------------------------------------------------------------
// Stable ID: aa_00745ea0
// Address:   0x00745ea0 – 0x00745ed9  (autoassault.exe, image base 0x400000)
// System:    client resource / NDResource shell
// Generated: 2026-07-29 W21-N OWN-ONLY dual (decompile + read_memory)
// Exactness: Byte-sealed CF ≡ decompiler. Soft decref only (no free/vtbl).
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

/*
 * Soft-decrement NDResource shell refcount under optional CRITICAL_SECTION.
 * ABI: __thiscall (ECX=this); 0 stack args; plain ret.
 * Returns 0 if decremented; 0xffffffff if refcount was already 0.
 *
 * Layout (shared with NDResource_AcquireInnerObject @ 0x00745ee0):
 *   +0x10 i32  refcount
 *   +0x20 CRITICAL_SECTION
 *   +0x38 u8   use-CS flag
 */

#include <stdint.h>
#include <windows.h>

uint32_t __fastcall NDResource_DecRef(void *self /* ECX this */)
{
  uint32_t result;

  if (*(uint8_t *)((char *)self + 0x38) != 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)((char *)self + 0x20));
  }

  result = 0xffffffffu;
  if (*(int *)((char *)self + 0x10) != 0) {
    *(int *)((char *)self + 0x10) =
        *(int *)((char *)self + 0x10) - 1;
    result = 0;
  }

  if (*(uint8_t *)((char *)self + 0x38) != 0) {
    LeaveCriticalSection((LPCRITICAL_SECTION)((char *)self + 0x20));
  }

  return result;
}
