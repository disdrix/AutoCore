// =============================================================================
// FUN_004a8960
// -----------------------------------------------------------------------------
// Stable ID: aa_004a8960
// Address:   0x004a8960  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004a8960 @ 0x004a8960
// Stable ID: aa_004a8960
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~50 non-empty decompiler lines.
//  - Control keywords: if×4, do×3, while×3, return×2.
//  - Notable callees: CONCAT11, CONCAT21, FUN_004a8960, FUN_00788ee0, FUN_00788f60, FUN_00788fd0, FUN_00789040, ROUND.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint32_t /* width from decompiler */ __thiscall FUN_004a8960(int param_1,int param_2)



{

  float fVar1;

  uint8_t uVar2;

  uint8_t uVar3;

  uint8_t uVar4;

  ushort uVar5;

  int iVar6;

  byte *pbVar7;

  int iVar8;

  int iVar9;

  int iVar10;

  

  if (param_2 == 0) {

    return 1;

  }

  iVar10 = 0;

  fVar1 = ROUND(_DAT_00af06d8);

  if (0 < *(int *)(param_1 + 0x14)) {

    do {

      iVar9 = 0;

      if (0 < *(int *)(param_1 + 0x10)) {

        do {

          uVar5 = FUN_00788ee0(iVar9,iVar10);

          uVar2 = FUN_00789040(iVar9,iVar10);

          uVar3 = FUN_00788fd0(iVar9,iVar10);

          uVar4 = FUN_00788f60(iVar9,iVar10);

          iVar6 = *(int *)(param_1 + 0x14);

          *(ushort *)(*(int *)(param_1 + 0x3e0) + (*(int *)(param_1 + 0x10) * iVar10 + iVar9) * 2) =

               (short)(int)fVar1 * (uVar5 & 0xff);

          iVar6 = iVar6 * iVar9 + iVar10;

          pbVar7 = (byte *)(*(int *)(param_1 + 0x3dc) + iVar6);

          *pbVar7 = *pbVar7 & 0xf8;

          iVar8 = 0;

          do {

            if ((uint)CONCAT21(CONCAT11(uVar4,uVar3),uVar2) == (&DAT_00af06b0)[iVar8]) {

              pbVar7 = (byte *)(iVar6 + *(int *)(param_1 + 0x3dc));

              *pbVar7 = *pbVar7 ^ (*pbVar7 ^ (byte)iVar8) & 7;

              break;

            }

            iVar8 = iVar8 + 1;

          } while (iVar8 < 8);

          iVar9 = iVar9 + 1;

        } while (iVar9 < *(int *)(param_1 + 0x10));

      }

      iVar10 = iVar10 + 1;

    } while (iVar10 < *(int *)(param_1 + 0x14));

  }

  return 0;

}
