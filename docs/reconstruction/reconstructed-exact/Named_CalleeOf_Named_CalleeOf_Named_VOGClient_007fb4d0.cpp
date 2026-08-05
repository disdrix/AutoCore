// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_VOGClient_007fb4d0
// -----------------------------------------------------------------------------
// Stable ID: aa_007fb4d0
// Callee of Named_CalleeOf_Named_VOGClient
// Address:   0x007fb4d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_VOGClient: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_007fb4d0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_VOGClient
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

uint32_t /* width from decompiler */ Named_CalleeOf_Named_CalleeOf_Named_VOGClient_007fb4d0(int param_1,int param_2,char param_3)



{

  int in_EAX;

  uint32_t /* width from decompiler */ uVar1;

  float fVar2;

  float fVar3;

  

  if (*(code **)(in_EAX + 0xdd4) == (code *)0x0) {

    return 0;

  }

  fVar2 = ((float)param_1 / (float)param_2) * DAT_00aaa690;

  if (g_flOne < fVar2) {

    fVar2 = g_flOne;

  }

  if (param_3 == '\0') {

    _param_3 = DAT_00a0f708;

    fVar3 = 0.0;

  }

  else {

    _param_3 = DAT_00aaa68c;

    fVar3 = fVar2;

  }

  uVar1 = (**(code **)(in_EAX + 0xdd4))(fVar3,fVar2,_param_3);

  return uVar1;

}
