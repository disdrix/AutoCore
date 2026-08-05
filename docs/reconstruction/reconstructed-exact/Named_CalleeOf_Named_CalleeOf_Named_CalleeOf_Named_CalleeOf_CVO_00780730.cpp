// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVO_00780730
// -----------------------------------------------------------------------------
// Stable ID: aa_00780730
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGCharacter_Sear
// Address:   0x00780730  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGCharacter_Sear: character create/apply helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00780730, QueryPerformanceFrequency, __alldiv.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGCharacter_Sear
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVO_00780730(void)



{

  LARGE_INTEGER *lpFrequency;

  uint32_t /* width from decompiler */ *unaff_ESI;

  LONGLONG LVar1;

  

  lpFrequency = (LARGE_INTEGER *)(unaff_ESI + 4);

  *unaff_ESI = 0;

  unaff_ESI[1] = 0;

  unaff_ESI[2] = 0;

  unaff_ESI[3] = 0;

  unaff_ESI[6] = 0;

  unaff_ESI[7] = 0;

  unaff_ESI[8] = 0;

  unaff_ESI[9] = 0;

  unaff_ESI[10] = 0;

  QueryPerformanceFrequency(lpFrequency);

  LVar1 = (LONGLONG)__alldiv((lpFrequency->s).LowPart,unaff_ESI[5],1000000,0);

  lpFrequency->QuadPart = LVar1;

  return;

}
