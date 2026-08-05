// =============================================================================
// FUN_00521dc0
// -----------------------------------------------------------------------------
// Stable ID: aa_00521dc0
// Address:   0x00521dc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00521dc0 @ 0x00521dc0
// Stable ID: aa_00521dc0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_004f74c0, FUN_00521dc0.
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

int __fastcall FUN_00521dc0(int param_1)



{

  byte *pbVar1;

  int iVar2;

  

  iVar2 = *(int *)(*(int *)(param_1 + 4) + 4);

  pbVar1 = (byte *)(iVar2 + 0x180 + param_1);

  *pbVar1 = *pbVar1 | 0x80;

  if (*(int *)(param_1 + 0x250) != 0) {

    iVar2 = FUN_004f74c0();

    *(short *)(param_1 + 0x12e) = (short)iVar2;

    return iVar2;

  }

  *(uint16_t *)(param_1 + 0x12e) = 10;

  return iVar2 + 4 + param_1;

}
