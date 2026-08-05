// =============================================================================
// Named_CalleeOf_Client_INC_ContactCountdownTick_005134e0
// -----------------------------------------------------------------------------
// Stable ID: aa_005134e0
// Callee of Client_INC_ContactCountdownTick (+2 other named callers)
// Address:   0x005134e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_INC_ContactCountdownTick: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Client_INC_ContactCountdownTick (+2 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: return×3, if×2.
//  - Notable callees: FUN_005134e0.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Client_INC_ContactCountdownTick (+2 other named callers)
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

bool __fastcall Named_CalleeOf_Client_INC_ContactCountdownTick_005134e0(int param_1)



{

  int iVar1;

  bool bVar2;

  

  if (*(int **)(param_1 + 0xac) == (int *)0x0) {

    return (*(uint *)(param_1 + 0x184) & 8) != 0;

  }

  iVar1 = (**(code **)(**(int **)(param_1 + 0xac) + 0x19c))();

  bVar2 = (*(byte *)(param_1 + 0x184) & 8) != 0;

  if (iVar1 != 0) {

    return bVar2 || (*(byte *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 0x188 + iVar1) & 8) != 0;

  }

  return bVar2 || (*(byte *)(*(int *)(param_1 + 0xac) + 0x184) & 8) != 0;

}
