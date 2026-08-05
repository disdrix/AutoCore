// =============================================================================
// FUN_009746a0
// -----------------------------------------------------------------------------
// Stable ID: aa_009746a0
// Address:   0x009746a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009746a0 @ 0x009746a0
// Stable ID: aa_009746a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×1, do×1, while×1, return×1.
//  - Notable callees: FUN_0077fe70, FUN_0077ff10, FUN_009746a0, FUN_00976080.
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

void FUN_009746a0(void)



{

  uint uVar1;

  int iVar2;

  int *unaff_EBX;

  

  FUN_0077ff10();

  uVar1 = FUN_00976080();

  unaff_EBX[1] = (uVar1 % 0x105) * 2 + 0xff;

  iVar2 = FUN_0077fe70();

  *unaff_EBX = iVar2;

  uVar1 = 0;

  if (unaff_EBX[1] != 0) {

    do {

      *(uint32_t /* width from decompiler */ *)(*unaff_EBX + uVar1 * 4) = 0;

      uVar1 = uVar1 + 1;

    } while (uVar1 < (uint)unaff_EBX[1]);

  }

  return;

}
