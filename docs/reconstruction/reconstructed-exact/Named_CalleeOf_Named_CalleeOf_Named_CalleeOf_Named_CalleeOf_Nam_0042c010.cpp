// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0042c010
// -----------------------------------------------------------------------------
// Stable ID: aa_0042c010
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Aut
// Address:   0x0042c010  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Aut: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~53 non-empty decompiler lines.
//  - Control keywords: if×3, do×1, while×1, return×1.
//  - Notable callees: FUN_0042af10, FUN_0042b2a0, FUN_0042c010, FUN_0077bad0, FUN_0077bb70, FUN_0077bc40, FUN_007833a0, FUN_00974780.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Aut
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

uint32_t /* width from decompiler */ * __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0042c010(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2)



{

  uint *puVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  bool bVar4;

  

  param_1[1] = 0;

  param_1[2] = 0;

  *param_1 = &PTR_LAB_00a9b350;

  param_1[5] = 0;

  param_1[3] = 0;

  param_1[4] = 0;

  param_1[8] = 0;

  param_1[6] = 0;

  param_1[7] = 0;

  puVar1 = param_1 + 6;

  param_1[0xb] = 0;

  param_1[9] = 0;

  param_1[10] = 0;

  param_1[0xe] = 0;

  param_1[0xc] = 0;

  param_1[0xd] = 0;

  param_1[0xf] = 0;

  param_1[0x10] = 0;

  FUN_00974780();

  TNL_Socket_Constructor(param_1 + 0x1a,param_2,0x8000,0x8000,1,1);

  FUN_0042af10();

  bVar4 = DAT_00d179d9 == '\0';

  param_1[0x20] = 0;

  *(uint8_t *)(param_1 + 0x24) = 1;

  *(uint8_t *)(param_1 + 0x1f) = 0;

  if (bVar4) {

    DAT_00d179d9 = '\x01';

    FUN_0077bc40(&DAT_00d0a3b8);

    FUN_0077bb70(&DAT_00d0a3b8);

  }

  FUN_0077bad0(param_1 + 0x21,0xc,&DAT_00d0a3b8);

  FUN_0042b2a0();

  if ((*puVar1 < 0x81) || (0x81 < *puVar1)) {

    *puVar1 = 0x81;

  }

  iVar2 = 0;

  if (0 < (int)*puVar1) {

    do {

      *(uint32_t /* width from decompiler */ *)(param_1[8] + iVar2 * 4) = 0;

      iVar2 = iVar2 + 1;

    } while (iVar2 < (int)*puVar1);

  }

  param_1[0x27] = 0;

  uVar3 = FUN_007833a0();

  param_1[0x1e] = uVar3;

  return param_1;

}
