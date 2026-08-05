// =============================================================================
// FUN_0042ae30
// -----------------------------------------------------------------------------
// Stable ID: aa_0042ae30
// Address:   0x0042ae30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0042ae30 @ 0x0042ae30
// Stable ID: aa_0042ae30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0042ae30.
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

void FUN_0042ae30(void)



{

  uint32_t /* width from decompiler */ *puVar1;

  void *pvVar2;

  uint unaff_EBX;

  int *unaff_ESI;

  

  unaff_ESI[1] = unaff_EBX;

  puVar1 = operator_new(0xc);

  if (puVar1 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar1 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    pvVar2 = operator_new__(unaff_EBX);

    puVar1[1] = pvVar2;

  }

  *unaff_ESI = (int)puVar1;

  *puVar1 = 0;

  *(uint32_t /* width from decompiler */ *)(*unaff_ESI + 8) = 0;

  unaff_ESI[2] = 0;

  unaff_ESI[3] = 0xc;

  unaff_ESI[4] = 0;

  return;

}
