// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00689d90
// -----------------------------------------------------------------------------
// Stable ID: aa_00689d90
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVO
// Address:   0x00689d90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVO: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~98 non-empty decompiler lines.
//  - Control keywords: if×11, while×2, return×1.
//  - Notable callees: FUN_00689d90.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVO
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00689d90(int *param_1,int *param_2)



{

  int iVar1;

  void *pvVar2;

  int iVar3;

  int iVar4;

  uint uVar5;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  puStack_c = &LAB_009aa122;

  local_10 = ExceptionList;

  iVar4 = *param_1;

  local_8 = 0;

  if (*(uint *)(iVar4 + 0x3c) < 0x10) {

    iVar4 = iVar4 + 0x28;

  }

  else {

    iVar4 = *(int *)(iVar4 + 0x28);

  }

  ExceptionList = &local_10;

  *param_2 = iVar4;

  iVar4 = *param_1;

  iVar1 = 0;

  if (*(int *)(iVar4 + 0x94) != 0) {

    iVar1 = (*(int *)(iVar4 + 0x98) - *(int *)(iVar4 + 0x94)) / 0x54;

  }

  param_2[1] = iVar1;

  if (iVar1 == 0) {

    param_2[2] = 0;

  }

  else {

    pvVar2 = operator_new__(iVar1 << 2);

    param_2[2] = (int)pvVar2;

    uVar5 = 0;

    while ((iVar1 = *(int *)(iVar4 + 0x94), iVar1 != 0 &&

           (uVar5 < (uint)((*(int *)(iVar4 + 0x98) - iVar1) / 0x54)))) {

      iVar3 = uVar5 * 0x54 + iVar1;

      if (*(uint *)(uVar5 * 0x54 + 0x2c + iVar1) < 0x10) {

        *(int *)(param_2[2] + uVar5 * 4) = iVar3 + 0x18;

        uVar5 = uVar5 + 1;

      }

      else {

        *(uint32_t /* width from decompiler */ *)(param_2[2] + uVar5 * 4) = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x18);

        uVar5 = uVar5 + 1;

      }

    }

  }

  iVar4 = *(int *)(param_1[0x16] + 0x44);

  if (iVar4 == 0) {

    iVar4 = 0;

  }

  else {

    iVar4 = (*(int *)(param_1[0x16] + 0x48) - iVar4) / 0x2c;

  }

  param_2[3] = iVar4;

  if (iVar4 == 0) {

    param_2[4] = 0;

  }

  else {

    pvVar2 = operator_new__(iVar4 << 2);

    param_2[4] = (int)pvVar2;

    uVar5 = 0;

    while (uVar5 < (uint)param_2[3]) {

      iVar4 = uVar5 * 0x2c + *(int *)(param_1[0x16] + 0x44);

      if (*(uint *)(uVar5 * 0x2c + 0x18 + *(int *)(param_1[0x16] + 0x44)) < 0x10) {

        *(int *)(param_2[4] + uVar5 * 4) = iVar4 + 4;

        uVar5 = uVar5 + 1;

      }

      else {

        *(uint32_t /* width from decompiler */ *)(param_2[4] + uVar5 * 4) = *(uint32_t /* width from decompiler */ *)(iVar4 + 4);

        uVar5 = uVar5 + 1;

      }

    }

  }

  iVar4 = param_1[0x14];

  if (iVar4 != 0) {

    if (*(uint *)(iVar4 + 0x3c) < 0x10) {

      iVar4 = iVar4 + 0x28;

    }

    else {

      iVar4 = *(int *)(iVar4 + 0x28);

    }

    param_2[6] = iVar4;

  }

  iVar4 = param_1[0x13];

  if (iVar4 != 0) {

    if (*(uint *)(iVar4 + 0x30) < 0x10) {

      iVar4 = iVar4 + 0x1c;

    }

    else {

      iVar4 = *(int *)(iVar4 + 0x1c);

    }

    param_2[5] = iVar4;

  }

  ExceptionList = local_10;

  return;

}
