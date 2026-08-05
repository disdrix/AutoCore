// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00650440
// -----------------------------------------------------------------------------
// Stable ID: aa_00650440
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x00650440  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_006380d0, FUN_00650210, FUN_00650440.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00650440(int *param_1,int param_2)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  uint32_t /* width from decompiler */ *puVar5;

  

  iVar1 = *param_1;

  iVar4 = param_1[2] + 1;

  iVar3 = (**(code **)(*DAT_00b05060 + 0x10))(param_2 * 8,0x12);

  *param_1 = iVar3;

  FUN_006380d0(iVar3,0,param_2 * 4);

  param_1[2] = param_2 + -1;

  iVar3 = 0;

  param_1[1] = 0;

  if (0 < iVar4) {

    puVar5 = (uint32_t /* width from decompiler */ *)(iVar1 + iVar4 * 4);

    do {

      iVar2 = *(int *)(iVar1 + iVar3 * 4);

      if (iVar2 != 0) {

        FUN_00650210(iVar2,*puVar5);

      }

      puVar5 = puVar5 + 1;

      iVar3 = iVar3 + 1;

    } while (iVar3 < iVar4);

  }

  (**(code **)(*DAT_00b05060 + 0x14))(iVar1,iVar4 * 8,0x12);

  return;

}
