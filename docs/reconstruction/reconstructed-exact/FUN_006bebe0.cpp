// =============================================================================
// FUN_006bebe0
// -----------------------------------------------------------------------------
// Stable ID: aa_006bebe0
// Address:   0x006bebe0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006bebe0 @ 0x006bebe0
// Stable ID: aa_006bebe0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~48 non-empty decompiler lines.
//  - Control keywords: if×5, do×1, while×1, return×1.
//  - Notable callees: FUN_005b3300, FUN_006bafb0, FUN_006bbe80, FUN_006be360, FUN_006bebe0.
//  - Return sites: 1.

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

void FUN_006bebe0(uint32_t /* width from decompiler */ param_1,int *param_2,uint32_t /* width from decompiler */ param_3,ushort param_4,int param_5,

                 uint32_t /* width from decompiler */ param_6,uint32_t /* width from decompiler */ param_7,int *param_8)



{

  int iVar1;

  ushort *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  ushort *puVar8;

  float10 fVar9;

  float local_10;

  

  if (param_2[2] != 1) {

    iVar4 = param_2[1];

    iVar5 = *param_2;

    puVar2 = (ushort *)(iVar4 + (uint)*(ushort *)(param_5 + 2) * 8);

    puVar8 = puVar2;

    do {

      if (*puVar8 == param_4) {

        local_10 = 4.0;

      }

      else {

        fVar9 = (float10)FUN_006bbe80(param_1,(uint)*puVar8 * 0x10 + iVar5,param_3,param_6,param_7);

        local_10 = (float)fVar9;

      }

      iVar6 = param_8[1];

      iVar1 = iVar6 + 1;

      if ((int)(param_8[2] & 0x7fffffffU) < iVar1) {

        iVar7 = (param_8[2] & 0x7fffffffU) * 2;

        if (iVar7 <= iVar1) {

          iVar7 = iVar1;

        }

        FUN_005b3300(param_8,iVar7,8);

      }

      puVar3 = (uint32_t /* width from decompiler */ *)(*param_8 + iVar6 * 8);

      param_8[1] = iVar1;

      *puVar3 = puVar8;

      puVar3[1] = local_10;

      puVar8 = (ushort *)(iVar4 + (uint)*(ushort *)(iVar4 + 2 + (uint)puVar8[2] * 8) * 8);

    } while (puVar8 != puVar2);

    if (1 < param_8[1]) {

      FUN_006bafb0(*param_8,0,param_8[1] + -1,&LAB_006bac90);

    }

    FUN_006be360(param_1,param_2,param_3,param_5,param_6,param_7,param_8);

  }

  return;

}
