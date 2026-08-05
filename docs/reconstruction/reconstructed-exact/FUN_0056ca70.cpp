// =============================================================================
// FUN_0056ca70
// -----------------------------------------------------------------------------
// Stable ID: aa_0056ca70
// Address:   0x0056ca70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0056ca70 @ 0x0056ca70
// Stable ID: aa_0056ca70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~74 non-empty decompiler lines.
//  - Control keywords: if×5, return×2.
//  - Notable callees: FUN_004e8a40, FUN_004e8bf0, FUN_004f8c50, FUN_0056ca70, SQRT.
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

void __thiscall FUN_0056ca70(int param_1,float *param_2)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  float *pfVar4;

  uint32_t /* width from decompiler */ uVar5;

  int iVar6;

  float fVar7;

  float local_30;

  float local_2c;

  float local_28;

  float local_24;

  float fStack_20;

  float fStack_1c;

  float fStack_18;

  float fStack_14;

  

  local_30 = g_flOne;

  local_2c = 0.0;

  local_28 = 0.0;

  local_24 = 0.0;

  piVar1 = *(int **)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xb0 + param_1);

  if (piVar1 != (int *)0x0) {

    if (*(int *)(piVar1[0x2a] + 0x38) == 0xe) {

      iVar2 = (**(code **)(**(int **)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xb0 + param_1) + 0x1d4)

              )();

      iVar3 = *(int *)(*(int *)(param_1 + 4) + 4);

      FUN_004f8c50(&local_30,*(uint32_t /* width from decompiler */ *)(iVar3 + 0x164 + param_1),

                   *(uint32_t /* width from decompiler */ *)(iVar3 + 0x168 + param_1));

      iVar3 = *(int *)(iVar2 + 8);

      if (iVar3 == 0) {

        iVar6 = *(int *)(*(int *)(iVar2 + 4) + 4) + 0x94 + iVar2;

        iVar3 = *(int *)(*(int *)(iVar2 + 4) + 4) + 0x84 + iVar2;

      }

      else {

        iVar6 = *(int *)(iVar3 + 0x3c) + 0x30;

        iVar3 = *(int *)(iVar3 + 0x3c) + 0xb0;

      }

      FUN_004e8bf0(iVar3,iVar6,&local_30,&fStack_20);

      if (*(int *)(iVar2 + 8) == 0) {

        pfVar4 = (float *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 0x84 + iVar2);

      }

      else {

        pfVar4 = (float *)(*(int *)(*(int *)(iVar2 + 8) + 0x3c) + 0xb0);

      }

      fStack_20 = fStack_20 - *pfVar4;

      fStack_1c = fStack_1c - pfVar4[1];

      fStack_18 = fStack_18 - pfVar4[2];

      fVar7 = fStack_18 * fStack_18 + fStack_1c * fStack_1c + fStack_20 * fStack_20;

      local_24 = 0.0;

      if (fVar7 != 0.0) {

        local_24 = g_flOne / SQRT(fVar7);

      }

      local_30 = local_24 * fStack_20;

      local_2c = fStack_1c * local_24;

      local_28 = fStack_18 * local_24;

      local_24 = (fStack_14 - pfVar4[3]) * local_24;

    }

    else {

      uVar5 = (**(code **)(*piVar1 + 0x1a4))(&local_30);

      FUN_004e8a40(uVar5);

    }

    *param_2 = local_30;

    param_2[2] = local_28;

    param_2[3] = local_24;

    param_2[1] = local_2c;

    return;

  }

  *param_2 = g_flOne;

  param_2[2] = 0.0;

  param_2[3] = 0.0;

  param_2[1] = 0.0;

  return;

}
