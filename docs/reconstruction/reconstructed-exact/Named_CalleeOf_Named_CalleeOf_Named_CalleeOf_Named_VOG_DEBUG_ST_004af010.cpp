// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST_004af010
// -----------------------------------------------------------------------------
// Stable ID: aa_004af010
// Callee of Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP
// Address:   0x004af010  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_004aee50×5, FUN_004af010.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST_004af010(int param_1,int param_2,int param_3,uint32_t /* width from decompiler */ param_4)



{

  int iVar1;

  int iVar2;

  int iVar3;

  

  iVar1 = param_3 - param_1 >> 3;

  if (0x28 < iVar1) {

    iVar1 = iVar1 + 1;

    iVar2 = (int)(iVar1 + (iVar1 >> 0x1f & 7U)) >> 3;

    iVar1 = iVar2 * 8 + param_1;

    FUN_004aee50(param_1,iVar1,iVar2 * 0x10 + param_1,param_4);

    FUN_004aee50(param_2 + iVar2 * -8,param_2,iVar2 * 8 + param_2,param_4);

    iVar3 = param_3 + iVar2 * -8;

    FUN_004aee50(param_3 + iVar2 * -0x10,iVar3,param_3,param_4);

    FUN_004aee50(iVar1,param_2,iVar3,param_4);

    return;

  }

  FUN_004aee50();

  return;

}
