// =============================================================================
// FUN_007468b0
// -----------------------------------------------------------------------------
// Stable ID: aa_007468b0
// Address:   0x007468b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007468b0 @ 0x007468b0
// Stable ID: aa_007468b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_007467b0, FUN_007468b0.
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

int __fastcall FUN_007468b0(int param_1)



{

  int iVar1;

  uint64_t uVar2;

  

  if ((*(int *)(param_1 + 4) != 0) &&

     (iVar1 = *(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 3, iVar1 != 0)) {

    uVar2 = FUN_007467b0(iVar1);

    return (int)uVar2 + (uint)*(ushort *)((int)((ulonglong)uVar2 >> 0x20) + 2);

  }

  return 0;

}
