// =============================================================================
// FUN_0098acc0  (scaffold alias — prefer NDAssetImage_FlipHorizontal.cpp)
// -----------------------------------------------------------------------------
// Stable ID: aa_0098acc0
// Address:   0x0098acc0  (autoassault.exe, image base 0x400000)
// System:    client assets / NDAssetImage
// Generated: 2026-07-23 scaffold; 2026-07-29 W20-L rename note
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE: Scaffold unit for FUN_0098acc0 @ 0x0098acc0
// Canonical name (W20-L): NDAssetImage_FlipHorizontal
// See: reconstructed-exact/NDAssetImage_FlipHorizontal.cpp

// READABILITY (auto CF):
//  - Body size: ~90 non-empty decompiler lines.
//  - Control keywords: if×10, do×6, while×6, return×3.
//  - Notable callees: FUN_004320d0, FUN_00432260, FUN_00432580, FUN_00433390,
//    FUN_00433530, FUN_004337d0, operator_new.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * - W20-L: this in EDI; AL return; TGA bit4 horizontal flip.
 * - Live decompile ≡ 2026-07-23 raw (no CF delta).
 */

uint32_t /* width from decompiler */ FUN_0098acc0(void)
{
  short sVar1;
  uint32_t *puVar2;
  uint8_t *puVar3;
  int iVar4;
  uint8_t *puVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint8_t *puVar9;
  int unaff_EDI;
  int local_10;

  if (*(int *)(unaff_EDI + 4) == 0) {
    return 0;
  }
  puVar2 = operator_new(0x1b8);
  if (puVar2 == (uint32_t *)0x0) {
    return 0;
  }
  *puVar2 = (uint32_t)&PTR_FUN_00a9bcac;
  FUN_004320d0();
  FUN_00432260(unaff_EDI,0,0,1);
  sVar1 = *(short *)(unaff_EDI + 0x16);
  iVar4 = ((uint)(sVar1 == 0x18) * 2 + 1) * (*(int *)(unaff_EDI + 0xc) + -1);
  iVar8 = puVar2[0xd];
  puVar5 = (uint8_t *)(*(int *)(unaff_EDI + 0x34) + iVar4);
  if (sVar1 == 8) {
    local_10 = 0;
    if (0 < *(int *)(unaff_EDI + 0x10)) {
      do {
        iVar6 = 0;
        puVar3 = puVar5;
        if (-1 < iVar4) {
          do {
            *(uint8_t *)(iVar6 + iVar8) = *puVar3;
            iVar6 = iVar6 + 1;
            puVar3 = puVar3 + -1;
          } while (iVar6 <= iVar4);
        }
        puVar5 = puVar5 + *(int *)(unaff_EDI + 0x30);
        iVar8 = iVar8 + *(int *)(unaff_EDI + 0x30);
        local_10 = local_10 + 1;
      } while (local_10 < *(int *)(unaff_EDI + 0x10));
    }
  }
  else if (sVar1 == 0x18) {
    local_10 = 0;
    if (0 < *(int *)(unaff_EDI + 0x10)) {
      do {
        if (-1 < iVar4) {
          puVar3 = (uint8_t *)(iVar8 + 1);
          puVar9 = puVar5 + 2;
          uVar7 = (iVar4 + 3U) / 3;
          do {
            puVar3[-1] = puVar9[-2];
            *puVar3 = puVar9[-1];
            puVar3[1] = *puVar9;
            puVar3 = puVar3 + 3;
            puVar9 = puVar9 + -3;
            uVar7 = uVar7 - 1;
          } while (uVar7 != 0);
        }
        puVar5 = puVar5 + *(int *)(unaff_EDI + 0x30);
        iVar8 = iVar8 + *(int *)(unaff_EDI + 0x30);
        local_10 = local_10 + 1;
      } while (local_10 < *(int *)(unaff_EDI + 0x10));
    }
  }
  else {
    iVar8 = 0;
    if (0 < *(int *)(unaff_EDI + 0x10)) {
      do {
        iVar6 = 0;
        if (-1 < iVar4) {
          do {
            FUN_00433530();
            FUN_004337d0(iVar8);
            iVar6 = iVar6 + 1;
          } while (iVar6 <= iVar4);
        }
        iVar8 = iVar8 + 1;
      } while (iVar8 < *(int *)(unaff_EDI + 0x10));
    }
  }
  FUN_00433390();
  FUN_00432580(unaff_EDI);
  (**(code **)*puVar2)(1);
  return 1;
}
