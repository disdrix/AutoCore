// =============================================================================
// FUN_0079a9f0
// -----------------------------------------------------------------------------
// Stable ID: aa_0079a9f0
// Address:   0x0079a9f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0079a9f0 @ 0x0079a9f0
// Stable ID: aa_0079a9f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_0079a1f0, FUN_0079a2c0, FUN_0079a750, FUN_0079a9f0.
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

void FUN_0079a9f0(void)



{

  int iVar1;

  float *pfVar2;

  int unaff_ESI;

  

  pfVar2 = (float *)(unaff_ESI + 0xd8);

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 100) = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x30);

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x10c) = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xd8);

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x144) = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x110);

  iVar1 = 0;

  do {

    *(uint8_t *)(unaff_ESI + 0x20 + iVar1) = 0;

    if ((((iVar1 != 0) && (iVar1 != 0xd)) && (iVar1 != 2)) && (iVar1 != 3)) {

      *(float *)(unaff_ESI + 100) = *(float *)(unaff_ESI + 100) - pfVar2[-0x2a];

      *(float *)(unaff_ESI + 0x10c) = *(float *)(unaff_ESI + 0x10c) - *pfVar2;

      *(float *)(unaff_ESI + 0x144) = *(float *)(unaff_ESI + 0x144) - pfVar2[0xe];

    }

    iVar1 = iVar1 + 1;

    pfVar2 = pfVar2 + 1;

  } while (iVar1 < 0xe);

  FUN_0079a1f0();

  if (*(int *)(unaff_ESI + 0x10) == *(int *)(unaff_ESI + 0xc)) {

    FUN_0079a2c0();

    FUN_0079a750(unaff_ESI);

  }

  return;

}
