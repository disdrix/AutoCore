// =============================================================================
// Named_CalleeOf_Named_SetWindStrength_expects_new_wind_strength_0068ed90
// -----------------------------------------------------------------------------
// Stable ID: aa_0068ed90
// Callee of Named_SetWindStrength_expects_new_wind_strength_0_0
// Address:   0x0068ed90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_SetWindStrength_expects_new_wind_strength: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: if×1, do×1, while×1, return×1.
//  - Notable callees: FUN_0068ed90.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_SetWindStrength_expects_new_wind_strength_0_0
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

void __fastcall Named_CalleeOf_Named_SetWindStrength_expects_new_wind_strength_0068ed90(int param_1)



{

  int iVar1;

  int iVar2;

  

  if ((*(int *)(param_1 + 0x2c) != 0) && (iVar1 = 0, *(short *)(param_1 + 0x28) != 0)) {

    iVar2 = 0;

    do {

      *(uint8_t *)(iVar2 + 0x3c + *(int *)(param_1 + 0x2c)) = 0;

      iVar1 = iVar1 + 1;

      iVar2 = iVar2 + 0x44;

    } while (iVar1 < (int)(uint)*(ushort *)(param_1 + 0x28));

  }

  return;

}
