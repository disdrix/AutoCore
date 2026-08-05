// =============================================================================
// FUN_00734690
// -----------------------------------------------------------------------------
// Stable ID: aa_00734690
// Address:   0x00734690  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00734690 @ 0x00734690
// Stable ID: aa_00734690
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00468aa0, FUN_00734690, FUN_007684e0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

bool __fastcall FUN_00734690(uint32_t /* width from decompiler */ param_1)



{

  int in_EAX;

  int iVar1;

  

  if (*(int *)(in_EAX + 0x4044) == 0) {

    iVar1 = FUN_00468aa0();

    return -1 < iVar1;

  }

  iVar1 = FUN_007684e0(param_1);

  return -1 < iVar1;

}
