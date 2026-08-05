// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_ChatClientIm_0095cf70
// -----------------------------------------------------------------------------
// Stable ID: aa_0095cf70
// Callee of Named_CalleeOf_Named_CalleeOf_Named_ChatClientImpl
// Address:   0x0095cf70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_ChatClientImpl: social/chat helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: CreateEventA, FUN_0095cf70.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_ChatClientImpl
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

uint32_t /* width from decompiler */ * __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_ChatClientIm_0095cf70(uint32_t /* width from decompiler */ *param_1,byte param_2,byte param_3,LPCSTR param_4)



{

  HANDLE pvVar1;

  

  *(byte *)(param_1 + 2) = param_2;

  param_1[1] = 0;

  *param_1 = &PTR_FUN_00aa9a94;

  pvVar1 = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,(uint)param_2,(uint)param_3,param_4);

  param_1[1] = pvVar1;

  return param_1;

}
