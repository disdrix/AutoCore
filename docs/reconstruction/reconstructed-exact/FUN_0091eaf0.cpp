// =============================================================================
// FUN_0091eaf0
// -----------------------------------------------------------------------------
// Stable ID: aa_0091eaf0
// Address:   0x0091eaf0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0091eaf0 @ 0x0091eaf0
// Stable ID: aa_0091eaf0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_007fef20×11, FUN_004c3f10, FUN_007fe1d0, FUN_0091eaf0.
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

void FUN_0091eaf0(void)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  

  FUN_007fef20(0x1b,1,0);

  FUN_007fef20(0x1c,1,0);

  if (DAT_00d1a8e4 == '\0') {

    FUN_007fef20(0x1e,1,0);

    uVar2 = 0x21;

  }

  else {

    uVar2 = 0x1d;

  }

  FUN_007fef20(uVar2,1,0);

  FUN_007fef20(0x1f,1,0);

  FUN_007fef20(0x16,1,0);

  FUN_007fef20(0x22,1,0);

  FUN_007fef20(0x23,1,0);

  FUN_007fef20(0x2f,1,0);

  FUN_007fe1d0(1);

  FUN_007fef20(0x30,1,0);

  if (DAT_00d1b6d8 != 0) {

    iVar1 = FUN_004c3f10(1);

    if (iVar1 != 0) {

      FUN_007fef20(0x32,1,0);

    }

  }

  return;

}
