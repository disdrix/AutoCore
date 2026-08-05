// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_00799350
// -----------------------------------------------------------------------------
// Stable ID: aa_00799350
// Callee of Named_VOG_DEBUG_STOP
// Address:   0x00799350  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: return×4, if×3.
//  - Notable callees: FUN_00798bb0, FUN_00799350, swscanf.
//  - Strings: "%d;%d".
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Callee of Named_VOG_DEBUG_STOP
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

char Named_CalleeOf_Named_VOG_DEBUG_STOP_00799350(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,int *param_3,int *param_4,

                 uint8_t *param_5)



{

  char cVar1;

  int iVar2;

  wchar_t local_80 [64];

  

  cVar1 = FUN_00798bb0(param_1,param_2,local_80);

  *param_5 = 0;

  if (cVar1 == '\0') {

    return '\0';

  }

  iVar2 = swscanf(local_80,L"%d;%d",param_3,param_4);

  if (iVar2 < 1) {

    return '\0';

  }

  if (iVar2 < 2) {

    *param_5 = 0;

    return cVar1;

  }

  *param_4 = *param_4 - *param_3;

  *param_5 = 1;

  return cVar1;

}
