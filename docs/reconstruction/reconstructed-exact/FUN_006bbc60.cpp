// =============================================================================
// FUN_006bbc60
// -----------------------------------------------------------------------------
// Stable ID: aa_006bbc60
// Address:   0x006bbc60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006bbc60 @ 0x006bbc60
// Stable ID: aa_006bbc60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~60 non-empty decompiler lines.
//  - Control keywords: if×4, while×3, return×2, do×1.
//  - Notable callees: FUN_006bba50×4, FUN_006bbc60.
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



void FUN_006bbc60(int *param_1,int param_2,int *param_3,float *param_4)



{

  ushort *puVar1;

  int iVar2;

  int iVar3;

  bool bVar4;

  int iVar5;

  float *pfVar6;

  float *pfVar7;

  float *pfVar8;

  int local_40;

  

  iVar2 = *param_1;

  *param_3 = param_1[1];

  param_3[1] = *(int *)(param_2 + 4);

  param_3[2] = 0;

  param_3[4] = 0;

  param_3[3] = -1;

  pfVar7 = (float *)((uint)*(ushort *)param_3[1] * 0x10 + iVar2);

  pfVar8 = (float *)((uint)*(ushort *)*param_3 * 0x10 + iVar2);

  FUN_006bba50(pfVar8,pfVar7,param_4);

  iVar5 = (param_1[2] + *(int *)(param_2 + 8)) * 2;

  local_40 = 0;

  if (0 < iVar5) {

    do {

      iVar3 = param_1[2];

      bVar4 = false;

      while (iVar3 = iVar3 + -1, -1 < iVar3) {

        pfVar6 = (float *)((uint)*(ushort *)(param_1[1] + iVar3 * 8) * 0x10 + iVar2);

        if (_DAT_00a0d15c <

            param_4[2] * (pfVar6[2] - pfVar8[2]) +

            param_4[1] * (pfVar6[1] - pfVar8[1]) + *param_4 * (*pfVar6 - *pfVar8)) {

          *param_3 = param_1[1] + iVar3 * 8;

          FUN_006bba50(pfVar6,pfVar7,param_4);

          bVar4 = true;

          pfVar8 = pfVar6;

        }

      }

      iVar3 = *(int *)(param_2 + 8);

      while (iVar3 = iVar3 + -1, -1 < iVar3) {

        puVar1 = (ushort *)(*(int *)(param_2 + 4) + iVar3 * 8);

        pfVar6 = (float *)((uint)*puVar1 * 0x10 + iVar2);

        if (_DAT_00a0d15c <

            param_4[2] * (pfVar6[2] - pfVar7[2]) +

            param_4[1] * (pfVar6[1] - pfVar7[1]) + *param_4 * (*pfVar6 - *pfVar7)) {

          param_3[1] = (int)puVar1;

          FUN_006bba50(pfVar8,pfVar6,param_4);

          bVar4 = true;

          pfVar7 = pfVar6;

        }

      }

      if (!bVar4) {

        return;

      }

      FUN_006bba50(pfVar8,pfVar7,param_4);

      local_40 = local_40 + 1;

    } while (local_40 < iVar5);

  }

  return;

}
