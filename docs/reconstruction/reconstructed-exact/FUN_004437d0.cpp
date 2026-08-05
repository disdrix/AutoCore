// =============================================================================
// FUN_004437d0
// -----------------------------------------------------------------------------
// Stable ID: aa_004437d0
// Address:   0x004437d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004437d0 @ 0x004437d0
// Stable ID: aa_004437d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_004437d0.
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

void FUN_004437d0(void)



{

  int iVar1;

  int *unaff_ESI;

  int *unaff_EDI;

  

  iVar1 = *unaff_ESI;

  if (iVar1 != 0) {

    *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + 1;

    if (*(int *)(iVar1 + 8) == 1) {

      (**(code **)(*(int *)(iVar1 + 4) + 4))();

    }

  }

  *unaff_EDI = *unaff_ESI;

  unaff_EDI[1] = unaff_ESI[1];

  unaff_EDI[2] = unaff_ESI[2];

  unaff_EDI[3] = unaff_ESI[3];

  unaff_EDI[4] = unaff_ESI[4];

  unaff_EDI[5] = unaff_ESI[5];

  unaff_EDI[6] = unaff_ESI[6];

  unaff_EDI[7] = unaff_ESI[7];

  unaff_EDI[8] = unaff_ESI[8];

  return;

}
