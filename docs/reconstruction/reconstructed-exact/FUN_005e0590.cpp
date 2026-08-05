// =============================================================================
// FUN_005e0590 / LootCatalog_RandomBiasBandIndex_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_005e0590
// Address:   0x005e0590  (autoassault.exe, image base 0x400000)
// System:    inventory / loot catalog
// Generated: 2026-07-23 scaffold; refined 2026-07-29 OWN-ONLY W16-C dual seal
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================
//
// PURPOSE:
//   Draw unit float U16*(~1/65536) from global reaction RNG table and randomly
//   bias a band/quality index downward by 0, 1, or 2 (never upward).
//
// ABI:
//   Input max band in ESI (decompiler: unaff_ESI). No stack formals. bare ret.
//   Return biased index in EAX.
//
// SOLE CALLER: FUN_005e0cd0 (adds result to typeRow*0x32 for band table index).
//
// CONSTANTS (read_memory):
//   DAT_00aaa638 = ~1.5259e-5 (~1/65536)
//   DAT_00a0f298 = 0.5
//   DAT_009dbf08 ~ 0.333333 (~1/3)
//   DAT_009dbf04 ~ 0.666666 (~2/3)
//

#include <cstdint>

extern "C" void *CVOGReaction_RandomUnitScalar(void);
extern float DAT_00aaa638;
extern float DAT_00a0f298;
extern float DAT_009dbf08;
extern float DAT_009dbf04;

// Proposed name: LootCatalog_RandomBiasBandIndex_Inferred
// Ghidra: FUN_005e0590
// maxBand is carried in ESI at the call site (not a stack argument).
int FUN_005e0590(void)
{
  uint16_t uVar1;
  int iVar2;
  int unaff_ESI; // live register input: max band / quality index
  float fVar3;

  iVar2 = (int)(intptr_t)CVOGReaction_RandomUnitScalar();
  // Wrap table cursor when index >= 0x100000 (decompiler: 0xfffff < index)
  if (0xfffff < *(int *)(iVar2 + 0xc)) {
    *(uint32_t *)(iVar2 + 0xc) = 0;
  }
  uVar1 = *(uint16_t *)(*(int *)(iVar2 + 8) + *(int *)(iVar2 + 0xc) * 2);
  *(int *)(iVar2 + 0xc) = *(int *)(iVar2 + 0xc) + 1;
  fVar3 = (float)uVar1 * DAT_00aaa638;

  if (1 < unaff_ESI) {
    if (unaff_ESI == 2) {
      if (fVar3 < DAT_00a0f298) {
        return 2;
      }
      return 1;
    }
    if (DAT_009dbf08 <= fVar3) {
      iVar2 = unaff_ESI + -1;
      if (DAT_009dbf04 <= fVar3) {
        iVar2 = unaff_ESI + -2;
      }
      return iVar2;
    }
  }
  return unaff_ESI;
}
