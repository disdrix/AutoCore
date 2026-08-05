// =============================================================================
// FUN_00782b00
// -----------------------------------------------------------------------------
// Stable ID: aa_00782b00
// Address:   0x00782b00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00782b00 @ 0x00782b00
// Stable ID: aa_00782b00
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: while×1, for×1, if×1, return×1.
//  - Notable callees: FUN_00782890, FUN_00782b00.
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

int FUN_00782b00(void)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  char unaff_BL;

  int iVar3;

  int unaff_EDI;

  

  iVar3 = 0;

  while (puVar1 = *(uint32_t /* width from decompiler */ **)(unaff_EDI + 4), puVar1 != (uint32_t /* width from decompiler */ *)0x0) {

    for (puVar2 = (uint32_t /* width from decompiler */ *)puVar1[3]; puVar2 != (uint32_t /* width from decompiler */ *)0x0;

        puVar2 = (uint32_t /* width from decompiler */ *)puVar2[3]) {

      puVar1 = puVar2;

    }

    FUN_00782890();

    if (unaff_BL != '\0') {

      (**(code **)*puVar1)(1);

    }

    iVar3 = iVar3 + 1;

  }

  return iVar3;

}
