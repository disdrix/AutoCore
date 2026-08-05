// =============================================================================
// FUN_00660d50
// -----------------------------------------------------------------------------
// Stable ID: aa_00660d50
// Address:   0x00660d50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00660d50 @ 0x00660d50
// Stable ID: aa_00660d50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~92 non-empty decompiler lines.
//  - Control keywords: if×7, do×1, while×1, return×1.
//  - Notable callees: FUN_005b3370×6, FUN_00660d50.
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

void __thiscall FUN_00660d50(int param_1,int *param_2)



{

  int iVar1;

  int iVar2;

  int *piVar3;

  uint32_t /* width from decompiler */ *puVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  uint32_t /* width from decompiler */ *puVar8;

  int local_18;

  

  if ((*(int *)(param_1 + 0x50) != 0) &&

     (local_18 = *(int *)(*(int *)(param_1 + 0x50) + 0x10), -1 < local_18)) {

    iVar2 = local_18 * 0xc;

    local_18 = local_18 + 1;

    do {

      iVar5 = (*(int **)(param_1 + 0x50))[3];

      iVar7 = *(int *)(iVar2 + 4 + iVar5);

      piVar3 = (int *)(iVar2 + iVar5);

      iVar5 = piVar3[2];

      iVar6 = *piVar3 * 0x10;

      puVar8 = (uint32_t /* width from decompiler */ *)(**(int **)(param_1 + 0x50) + iVar6);

      if (param_2[1] == (param_2[2] & 0x7fffffffU)) {

        FUN_005b3370(param_2,0x10);

      }

      puVar4 = (uint32_t /* width from decompiler */ *)(param_2[1] * 0x10 + *param_2);

      param_2[1] = param_2[1] + 1;

      *puVar4 = *puVar8;

      puVar4[1] = puVar8[1];

      puVar4[2] = puVar8[2];

      puVar4[3] = puVar8[3];

      iVar7 = iVar7 * 0x10;

      puVar8 = (uint32_t /* width from decompiler */ *)(**(int **)(param_1 + 0x50) + iVar7);

      if (param_2[1] == (param_2[2] & 0x7fffffffU)) {

        FUN_005b3370(param_2,0x10);

      }

      iVar1 = param_2[1];

      param_2[1] = iVar1 + 1;

      puVar4 = (uint32_t /* width from decompiler */ *)(iVar1 * 0x10 + *param_2);

      *puVar4 = *puVar8;

      puVar4[1] = puVar8[1];

      puVar4[2] = puVar8[2];

      puVar4[3] = puVar8[3];

      puVar8 = (uint32_t /* width from decompiler */ *)(**(int **)(param_1 + 0x50) + iVar6);

      if (param_2[1] == (param_2[2] & 0x7fffffffU)) {

        FUN_005b3370(param_2,0x10);

      }

      puVar4 = (uint32_t /* width from decompiler */ *)(param_2[1] * 0x10 + *param_2);

      param_2[1] = param_2[1] + 1;

      *puVar4 = *puVar8;

      puVar4[1] = puVar8[1];

      puVar4[2] = puVar8[2];

      puVar4[3] = puVar8[3];

      iVar5 = iVar5 * 0x10;

      puVar8 = (uint32_t /* width from decompiler */ *)(**(int **)(param_1 + 0x50) + iVar5);

      if (param_2[1] == (param_2[2] & 0x7fffffffU)) {

        FUN_005b3370(param_2,0x10);

      }

      iVar6 = param_2[1];

      param_2[1] = iVar6 + 1;

      puVar4 = (uint32_t /* width from decompiler */ *)(iVar6 * 0x10 + *param_2);

      *puVar4 = *puVar8;

      puVar4[1] = puVar8[1];

      puVar4[2] = puVar8[2];

      puVar4[3] = puVar8[3];

      puVar8 = (uint32_t /* width from decompiler */ *)(**(int **)(param_1 + 0x50) + iVar7);

      if (param_2[1] == (param_2[2] & 0x7fffffffU)) {

        FUN_005b3370(param_2,0x10);

      }

      puVar4 = (uint32_t /* width from decompiler */ *)(param_2[1] * 0x10 + *param_2);

      param_2[1] = param_2[1] + 1;

      *puVar4 = *puVar8;

      puVar4[1] = puVar8[1];

      puVar4[2] = puVar8[2];

      puVar4[3] = puVar8[3];

      puVar8 = (uint32_t /* width from decompiler */ *)(**(int **)(param_1 + 0x50) + iVar5);

      if (param_2[1] == (param_2[2] & 0x7fffffffU)) {

        FUN_005b3370(param_2,0x10);

      }

      iVar5 = param_2[1];

      iVar2 = iVar2 + -0xc;

      param_2[1] = iVar5 + 1;

      puVar4 = (uint32_t /* width from decompiler */ *)(iVar5 * 0x10 + *param_2);

      local_18 = local_18 + -1;

      *puVar4 = *puVar8;

      puVar4[1] = puVar8[1];

      puVar4[2] = puVar8[2];

      puVar4[3] = puVar8[3];

    } while (local_18 != 0);

  }

  return;

}
