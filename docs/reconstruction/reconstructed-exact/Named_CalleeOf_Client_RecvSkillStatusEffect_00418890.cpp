// =============================================================================
// Named_CalleeOf_Client_RecvSkillStatusEffect_00418890
// -----------------------------------------------------------------------------
// Stable ID: aa_00418890
// Callee of Client_RecvSkillStatusEffect (+1 other named callers)
// Address:   0x00418890  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_RecvSkillStatusEffect: skill/cast helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Client_RecvSkillStatusEffect (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00418890, FUN_00418c70.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Client_RecvSkillStatusEffect (+1 other named callers)
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

void __thiscall Named_CalleeOf_Client_RecvSkillStatusEffect_00418890(int param_1,int *param_2,int *param_3)



{

  int iVar1;

  

  iVar1 = FUN_00418c70(param_3);

  if ((iVar1 != *(int *)(param_1 + 4)) && (*(int *)(iVar1 + 0xc) <= *param_3)) {

    *param_2 = iVar1;

    return;

  }

  *param_2 = *(int *)(param_1 + 4);

  return;

}
