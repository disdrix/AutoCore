// =============================================================================
// FUN_00576d70
// -----------------------------------------------------------------------------
// Stable ID: aa_00576d70
// Address:   0x00576d70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00576d70 @ 0x00576d70
// Stable ID: aa_00576d70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_00576d70, FUN_00577030, FUN_00746400.
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

uint32_t /* width from decompiler */ FUN_00576d70(void)



{

  void *pvVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  

  pvVar1 = operator_new(4);

  if (pvVar1 != (void *)0x0) {

    iVar2 = FUN_00577030();

    if (iVar2 != 0) {

      uVar3 = FUN_00746400(iVar2);

      return uVar3;

    }

  }

  return 0xffffffff;

}
