// =============================================================================
// Named_CalleeOf_Named_SERVER_GOT_GIGO_0x_x_00631f10
// -----------------------------------------------------------------------------
// Stable ID: aa_00631f10
// Callee of Named_SERVER_GOT_GIGO_0x_x
// Address:   0x00631f10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_SERVER_GOT_GIGO_0x_x: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00631f10, FUN_00638060, _vsnprintf.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_SERVER_GOT_GIGO_0x_x
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

void Named_CalleeOf_Named_SERVER_GOT_GIGO_0x_x_00631f10(int param_1,char *param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  char local_400 [1024];

  

  _vsnprintf(local_400,0x400,param_2,&stack0x0000000c);

  iVar1 = **(int **)(param_1 + 8);

  uVar2 = FUN_00638060(local_400);

  (**(code **)(iVar1 + 8))(local_400,uVar2);

  return;

}
