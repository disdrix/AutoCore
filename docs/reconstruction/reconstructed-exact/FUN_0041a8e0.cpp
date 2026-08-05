// =============================================================================
// FUN_0041a8e0  (scaffold alias of Com_LoaderCtx_NestedTeardown_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0041a8e0
// Address:   0x0041a8e0  (autoassault.exe, image base 0x400000)
// Body:      0x0041a8e0–0x0041a988 (169 bytes)
// Named:     Com_LoaderCtx_NestedTeardown_Inferred.cpp (authoritative clean)
// System:    crt-com / DB-WAD loader context
// Generated: 2026-07-29 W22-M — byte-sealed CF (decompiler tail incomplete)
// Exactness: Behavior-preserving; not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <stdint.h>
#include <stdlib.h>

extern void FUN_00422de0(void);
extern void FUN_0041bf70(void);

/* Scaffold keeps FUN_* names; named clean is authoritative for ports. */

void __stdcall FUN_0041a8e0(int param_1)
{
  int *piVar1;
  uint32_t *p;

  /* SEH: LAB_009bd810 — omitted frame mechanics */

  /* EDI = param_1 + 0x10 */
  if (*(int *)(param_1 + 0x10) != 0) {
    FUN_00422de0();
    FUN_0041bf70();
  }

  /* SEH state = 1 */
  FUN_0041bf70();

  piVar1 = *(int **)(param_1 + 0x14);
  if (piVar1 != (int *)0) {
    (**(void (__stdcall ***)(int *))(*piVar1 + 8))(piVar1); /* Release */
  }

  /* SEH state = 0 */
  piVar1 = *(int **)(param_1 + 0x10);
  if (piVar1 != (int *)0) {
    (**(void (__stdcall ***)(int *))(*piVar1 + 8))(piVar1); /* Release */
  }

  /* Byte-sealed tail (decompiler truncated after first operator_delete). */
  p = *(uint32_t **)(param_1 + 0x0C);
  if (p != (uint32_t *)0) {
    operator delete((void *)(uintptr_t)p[3]);
    if (p[0] != 0) {
      free((void *)(uintptr_t)p[0]); /* IAT [0x009c6524] */
    }
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
    operator delete(p);
  }
}
