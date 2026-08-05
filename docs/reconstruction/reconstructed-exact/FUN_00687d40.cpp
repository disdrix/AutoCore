// =============================================================================
// FUN_00687d40
// -----------------------------------------------------------------------------
// Stable ID: aa_00687d40
// Address:   0x00687d40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00687d40 @ 0x00687d40
// Stable ID: aa_00687d40
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00687d40, FUN_006a3db0.
//  - Return sites: 1.

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

int __fastcall FUN_00687d40(int *param_1)



{

  ushort uVar1;

  int iVar2;

  

  uVar1 = *(ushort *)(*param_1 + 0x70);

  iVar2 = FUN_006a3db0();

  if ((int)(short)iVar2 == (uint)uVar1) {

    iVar2 = iVar2 + -1;

  }

  return iVar2;

}
