// =============================================================================
// FUN_0050843d  (alias of CVOGHBBase_EndOrDestroy_HardListUnlink)
// -----------------------------------------------------------------------------
// Stable ID: aa_0050843d
// Address:   0x0050843d  (autoassault.exe, image base 0x400000)
// System:    heartbeat / CVOGHBBase
// Generated: 2026-07-29 W20-R dual A/B seal
// Exactness: Behavior-preserving; read_memory preferred for FUN_005085b0 ABI.
// Canonical clean: reconstructed-exact/CVOGHBBase_EndOrDestroy_HardListUnlink.cpp
// =============================================================================

#include <stdint.h>

extern void FUN_0050846f(void);
extern uint32_t __thiscall FUN_005085b0(int listMgr, int hb);

void FUN_0050843d(void)
{
  int unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;

  *(int *)(unaff_EBP + -4) = unaff_EBX;
  *(uint8_t *)(unaff_EBP + -4) = 3;
  if (((*(char *)(unaff_EBP + 0xc) != (char)unaff_EBX) &&
       (*(int *)(unaff_ESI + 0x18) != unaff_EBX)) &&
      (*(int *)(*(int *)(unaff_ESI + 0x18) + 0xb0) != unaff_EBX)) {
    // Bytes: push esi; mov ecx, *( *(esi+0x18) + 0xb0 ); call FUN_005085b0
    FUN_005085b0(*(int *)(*(int *)(unaff_ESI + 0x18) + 0xb0), unaff_ESI);
    FUN_0050846f();
    return;
  }
  // Soft path body is FUN_0050846f in the image (decomp may inline)
  *(uint8_t *)(unaff_ESI + 0x20) = 1;
  *(int *)(unaff_ESI + 0x18) = unaff_EBX;
  return;
}
