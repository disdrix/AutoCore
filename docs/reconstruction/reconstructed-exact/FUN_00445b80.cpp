// =============================================================================
// FUN_00445b80
// -----------------------------------------------------------------------------
// Stable ID: aa_00445b80
// Address:   0x00445b80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00445b80 @ 0x00445b80
// Stable ID: aa_00445b80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×1, for×1, return×1.
//  - Notable callees: FUN_00445b80, FUN_00445c30.
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

void FUN_00445b80(uint8_t *param_1)



{

  uint8_t *puVar1;

  char cVar2;

  uint8_t *puVar3;

  int iVar4;

  int unaff_EBX;

  int unaff_ESI;

  

  cVar2 = FUN_00445c30(unaff_ESI);

  if (cVar2 != '\0') {

    puVar1 = *(uint8_t **)(unaff_EBX + 4);

    puVar3 = puVar1;

    for (iVar4 = unaff_ESI; iVar4 != 0; iVar4 = iVar4 + -1) {

      *puVar3 = *param_1;

      puVar3 = puVar3 + 1;

    }

    *(uint8_t **)(unaff_EBX + 8) = puVar1 + unaff_ESI;

  }

  return;

}
