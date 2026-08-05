// =============================================================================
// FUN_00974780
// -----------------------------------------------------------------------------
// Stable ID: aa_00974780
// Address:   0x00974780  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00974780 @ 0x00974780
// Stable ID: aa_00974780
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~39 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: FUN_00433ce0×2, FUN_0077bad0×2, FUN_0077bb70×2, FUN_0077bc40×2, FUN_00974780.
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

void FUN_00974780(void)



{

  void *pvVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ *unaff_ESI;

  bool bVar3;

  

  bVar3 = DAT_00d179d9 == '\0';

  *unaff_ESI = 0x11;

  unaff_ESI[1] = 0;

  unaff_ESI[2] = 0;

  if (bVar3) {

    DAT_00d179d9 = '\x01';

    FUN_0077bc40(&DAT_00d0a3b8);

    FUN_0077bb70(&DAT_00d0a3b8);

  }

  FUN_0077bad0(unaff_ESI + 3,8,&DAT_00d0a3b8);

  if (DAT_00d179d9 == '\0') {

    DAT_00d179d9 = '\x01';

    FUN_0077bc40(&DAT_00d0a3b8);

    FUN_0077bb70(&DAT_00d0a3b8);

  }

  FUN_0077bad0(unaff_ESI + 5,8,&DAT_00d0a3b8);

  pvVar1 = operator_new(0x10);

  if (pvVar1 == (void *)0x0) {

    uVar2 = 0;

  }

  else {

    uVar2 = FUN_00433ce0();

  }

  unaff_ESI[7] = uVar2;

  pvVar1 = operator_new(0x10);

  if (pvVar1 != (void *)0x0) {

    uVar2 = FUN_00433ce0();

    unaff_ESI[8] = uVar2;

    return;

  }

  unaff_ESI[8] = 0;

  return;

}
