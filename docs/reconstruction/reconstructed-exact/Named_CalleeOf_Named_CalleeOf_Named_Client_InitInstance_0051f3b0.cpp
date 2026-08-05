// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_Client_InitInstance_0051f3b0
// -----------------------------------------------------------------------------
// Stable ID: aa_0051f3b0
// Callee of Named_CalleeOf_Named_Client_InitInstance
// Address:   0x0051f3b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_Client_InitInstance: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: return×2, do×1, if×1, while×1.
//  - Notable callees: CONCAT31, FUN_0051f3b0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_Client_InitInstance
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

uint __thiscall Named_CalleeOf_Named_CalleeOf_Named_Client_InitInstance_0051f3b0(int param_1,int param_2)



{

  uint uVar1;

  int *piVar2;

  

  uVar1 = 0;

  piVar2 = (int *)(param_1 + 0xd58);

  do {

    if (*piVar2 == param_2) {

      return CONCAT31((int3)(uVar1 >> 8),1);

    }

    uVar1 = uVar1 + 1;

    piVar2 = piVar2 + 1;

  } while ((int)uVar1 < 3);

  return uVar1 & 0xffffff00;

}
