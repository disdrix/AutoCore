// =============================================================================
// Com_LoaderCtx_NestedTeardown_Inferred
// -----------------------------------------------------------------------------
// Purpose:  Nested teardown for COM/DB loader context: tear Ado rowset holder
//           at ctx+0x10, defensive IUnknown::Release on +0x10/+0x14, then
//           destroy owned nested object at *(ctx+0x0C) (delete buffer, free
//           head, zero three dwords, delete object).
//
// Address:  0x0041a8e0  (autoassault.exe, image base 0x400000)
// Body:     0x0041a8e0–0x0041a988 (169 bytes)
// Stable:   aa_0041a8e0
// System:   crt-com / DB-WAD loader context
// Ghidra:   FUN_0041a8e0
//
// ABI:      __stdcall one formal (ctx); ret 4. SEH LAB_009bd810.
// Parent:   Com_LoaderCtx_Teardown_Inferred (0x0041a3e0) @ 0x0041a428
// Callees:  OleDb_ReleaseAccessorHandleArray_Inferred (0x00422de0)
//           AdoRowsetHolder_Teardown_Inferred (0x0041bf70) x2
//           IUnknown::Release (vtbl+8)
//           operator_delete @ 0x00489822 (x2)
//           free IAT [0x009c6524]
//
// Exactness: Byte-sealed CF from read_memory supersedes truncated decompile
//            (operator_delete falsely noreturn in Ghidra).
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Dual A/B: accept-with-gaps (2026-07-29 W22-M seal).
// =============================================================================

#include <stdint.h>
#include <stdlib.h>

/* Nested duals (names sealed on their own VAs). */
extern void OleDb_ReleaseAccessorHandleArray_Inferred(void /* reg ABI */);
extern void AdoRowsetHolder_Teardown_Inferred(void /* EDI = holder */);

/* Minimal COM Release shape: vtbl+8. */
typedef struct IUnknown_min {
  struct { void *qi; void *addref; unsigned long (__stdcall *Release)(void *self); } *vtbl;
} IUnknown_min;

void __stdcall Com_LoaderCtx_NestedTeardown_Inferred(void *ctx)
{
  /* SEH frame omitted (LAB_009bd810); state 0/1/0 around Releases. */

  IUnknown_min **slot10 = (IUnknown_min **)((char *)ctx + 0x10);

  if (*slot10 != 0) {
    /* Call site: EAX = *slot10, ESI = ctx before FUN_00422de0. */
    OleDb_ReleaseAccessorHandleArray_Inferred();
    AdoRowsetHolder_Teardown_Inferred(); /* EDI = slot10 */
  }

  /* SEH state = 1 */
  AdoRowsetHolder_Teardown_Inferred();   /* always; EDI = slot10 */

  if (slot10[1] != 0) {
    slot10[1]->vtbl->Release(slot10[1]); /* *(ctx+0x14) */
  }

  /* SEH state = 0 */
  if (slot10[0] != 0) {
    slot10[0]->vtbl->Release(slot10[0]); /* *(ctx+0x10) */
  }

  {
    uint32_t *p = *(uint32_t **)((char *)ctx + 0x0C);
    if (p != 0) {
      operator delete((void *)(uintptr_t)p[3]); /* *(p+0x0C) */
      if (p[0] != 0) {
        free((void *)(uintptr_t)p[0]);         /* IAT free */
      }
      p[0] = 0;
      p[1] = 0;
      p[2] = 0;
      operator delete(p);
      /* ctx+0x0C left unchanged (not nulled). */
    }
  }
}
