// =============================================================================
// FUN_0078edf0
// -----------------------------------------------------------------------------
// Stable ID: aa_0078edf0
// Address:   0x0078edf0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0078edf0 @ 0x0078edf0
// Stable ID: aa_0078edf0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0078edf0.
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

void __fastcall FUN_0078edf0(int *param_1)



{

  int iVar1;

  int iVar2;

  uint8_t local_8 [8];

  

  iVar2 = 1;

  iVar1 = 1;

  (**(code **)(*param_1 + 0x120))(local_8,1,1);

  if (*(char *)((int)param_1 + 0x4fd) == '\0') {

    iVar1 = (*(int *)(DAT_00d17948 + 0x10) - iVar2) - param_1[0x143];

    iVar2 = param_1[0x145] - param_1[0x143];

  }

  else {

    iVar1 = (*(int *)(DAT_00d17948 + 0xc) - iVar1) - param_1[0x142];

    iVar2 = param_1[0x144] - param_1[0x142];

  }

  (**(code **)(*param_1 + 0x454))((float)iVar1 / (float)iVar2,1);

  return;

}
