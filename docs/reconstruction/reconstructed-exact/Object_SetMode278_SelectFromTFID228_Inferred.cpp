// =============================================================================
// Object_SetMode278_SelectFromTFID228_Inferred
// -----------------------------------------------------------------------------
// Purpose:  Write owner mode byte at +0x278. When mode==1, resolve TFID_16 at
//           +0x228, require resolved+0xA0 non-null and MI self vtbl+0x298 OK,
//           then Object_SetSelectedTarget(mi_self, candidate).
//
// Address:  0x004c3c80 – 0x004c3d17 (151 B / 0x97)
// Stable:   aa_004c3c80
// System:   object / AI owner mode / selected-target apply
// Ghidra:   FUN_004c3c80
//
// Convention: MSVC __thiscall
//   this  object* (owner / creature)
//   mode  char (stack); ret 4
//
// Dual A/B: 2026-07-29 W28-L accept.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// =============================================================================

#include <stdint.h>
#include <string.h>

struct TFID_16 {
  uint32_t dwCoidLo;
  uint32_t dwCoidHi;
  uint32_t w2;
  uint32_t w3;
};

/* Sealed elsewhere */
extern void *Object_ResolveFromTFID(TFID_16 *tfid); /* 0x004bb950 */
extern void __thiscall Object_SetSelectedTarget(void *entity, void *pNewTarget); /* 0x005172d0 */

void __thiscall Object_SetMode278_SelectFromTFID228_Inferred(void *self, char mode)
{
  *(char *)((char *)self + 0x278) = mode;
  if (mode != 1) {
    return;
  }

  TFID_16 local;
  memcpy(&local, (char *)self + 0x228, sizeof(local));

  /* Bytes rebuild manager ECX from *(self+4) chain → +0xA8 → +0xE4E8
     before call; decompiler surface often omits (known residual). */
  void *resolved = Object_ResolveFromTFID(&local);
  if (resolved == 0) {
    return;
  }

  void *candidate = *(void **)((char *)resolved + 0xa0);
  if (candidate == 0) {
    return;
  }

  int baseAdj = *(int *)(*(int *)((char *)self + 4) + 4);
  void *mi = (char *)self + baseAdj + 4;
  char ok = (*(char (__thiscall **)(void *, void *))(*(int *)mi + 0x298))(mi, candidate);
  if (ok == 0) {
    return;
  }

  Object_SetSelectedTarget(mi, candidate);
}
