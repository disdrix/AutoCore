// =============================================================================
// FUN_007fbbb0
// -----------------------------------------------------------------------------
// Stable ID: aa_007fbbb0
// Address:   0x007fbbb0 – 0x007fbc6a  (autoassault.exe, image base 0x400000)
// System:    inventory-transfer (Grab pre-helper / shared held-object UI clear)
// Generated: 2026-07-23 scaffold; refined 2026-07-29 dual (wave8 OWN-ONLY)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// Duals:     reviews/A_aa_007fbbb0_FUN_007fbbb0.md
//            reviews/B_aa_007fbbb0_FUN_007fbbb0.md
// =============================================================================
//
// PURPOSE:
//   Client-host (ESI) helper used before InventoryGrab senders and other UI paths.
//   If a held inventory object at host+0x113c passes vtbl+0xd0 and +0x2b0 gates:
//     - UI root **(host+0xf40) detaches held (vtbl+0xb0)
//     - held released via vtbl+4(0)
//     - UI root vtbl+0x1c8(0), vtbl+0x3c0(0)
//     - optional copy ui+0x514→+0x498 and ui+0x518→+0x49c when positive
//   Does NOT pack opcode 0x2034, send packets, or set Grab busy flags.
//
// ABI:
//   ESI = client host* (Grab sites often load DAT_00d1a840)
//   No stack args consumed by body. Return void.
//
// READABILITY:
//   - Control keywords: if×4, return×1.
//   - All calls are CALLIND (vtable); no named direct callees.
//   - unaff_ESI kept as decompiler form; portable ports may take host* explicitly.
// =============================================================================

#include <cstdint>

// Ghidra: void FUN_007fbbb0(void) with unaff_ESI host
void FUN_007fbbb0(void)
{
  int iVar1;
  char cVar2;
  int unaff_ESI; /* client host* in ESI */

  if (*(int *)(unaff_ESI + 0x113c) != 0) {
    cVar2 = (**(code **)(**(int **)(unaff_ESI + 0x113c) + 0xd0))();
    if ((cVar2 != '\0') && (*(int *)(*(int *)(unaff_ESI + 0x113c) + 0x2b0) != 0)) {
      (**(code **)(*(int *)**(uint32_t **)(unaff_ESI + 0xf40) + 0xb0))(
          *(int *)(unaff_ESI + 0x113c));
      (**(code **)(**(int **)(unaff_ESI + 0x113c) + 4))(0);
      (**(code **)(*(int *)**(uint32_t **)(unaff_ESI + 0xf40) + 0x1c8))(0);
      (**(code **)(*(int *)**(uint32_t **)(unaff_ESI + 0xf40) + 0x3c0))(0);
      if (0 < *(int *)(**(int **)(unaff_ESI + 0xf40) + 0x514)) {
        iVar1 = **(int **)(unaff_ESI + 0xf40);
        *(uint32_t *)(iVar1 + 0x498) = *(uint32_t *)(iVar1 + 0x514);
      }
      if (0 < *(int *)(**(int **)(unaff_ESI + 0xf40) + 0x518)) {
        iVar1 = **(int **)(unaff_ESI + 0xf40);
        *(uint32_t *)(iVar1 + 0x49c) = *(uint32_t *)(iVar1 + 0x518);
      }
    }
  }
  return;
}
