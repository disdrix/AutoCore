// =============================================================================
// FUN_00419e20  (scaffold twin of Com_BstrHolder_Release)
// -----------------------------------------------------------------------------
// Stable ID: aa_00419e20
// Address:   0x00419e20  (autoassault.exe, image base 0x400000)
// System:    crt-com / MSVC BSTR smart-holder
// Generated: 2026-07-29 W22-L dual seal (scaffold keeps Ghidra name)
// Exactness: Behavior-preserving rewrite of decompiler + byte seal.
// Bit-for-bit vs retail EXE: DEFERRED.
// Canonical clean: Com_BstrHolder_Release.cpp
// =============================================================================

#include <stdint.h>
#include <windows.h>

/* ESI-this: decompiler unaff_ESI. */
LONG FUN_00419e20(void)
{
  LONG LVar1;
  uint32_t *unaff_ESI; /* register: holder* */

  LVar1 = InterlockedDecrement((LONG *)(unaff_ESI + 2));
  if (LVar1 != 0) {
    return (LONG)unaff_ESI[2];
  }
  if (unaff_ESI != 0) {
    if ((BSTR)unaff_ESI[0] != 0) {
      SysFreeString((BSTR)unaff_ESI[0]);
    }
    if ((void *)unaff_ESI[1] != 0) {
      operator delete[]((void *)unaff_ESI[1]);
    }
    /* operator_delete DOES return (decompiler warning is false). */
    operator delete(unaff_ESI);
  }
  return 0;
}
