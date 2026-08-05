// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_SkyBoxPartic_00638140
// -----------------------------------------------------------------------------
// Stable ID: aa_00638140
// Callee of Named_CalleeOf_Named_CalleeOf_Named_SkyBoxParticles
// Address:   0x00638140  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_SkyBoxParticles: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: do×2, while×2, return×1.
//  - Notable callees: FUN_00638140.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_SkyBoxParticles
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_SkyBoxPartic_00638140(char *param_1)



{

  char cVar1;

  char *pcVar2;

  int iVar3;

  

  pcVar2 = param_1;

  do {

    cVar1 = *pcVar2;

    pcVar2 = pcVar2 + 1;

  } while (cVar1 != '\0');

  iVar3 = (**(code **)*DAT_00b05060)(pcVar2 + (1 - (int)(param_1 + 1)),0x11);

  iVar3 = iVar3 - (int)param_1;

  do {

    cVar1 = *param_1;

    param_1[iVar3] = cVar1;

    param_1 = param_1 + 1;

  } while (cVar1 != '\0');

  return;

}
