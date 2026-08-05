// =============================================================================
// FUN_005be6a0
// -----------------------------------------------------------------------------
// Stable ID: aa_005be6a0
// Address:   0x005be6a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005be6a0 @ 0x005be6a0
// Stable ID: aa_005be6a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_005be6a0.
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

void __fastcall FUN_005be6a0(int param_1)



{

  if (*(char *)(param_1 + 0xc4) != '\0') {

    *(uint8_t *)(param_1 + 0xc4) = 0;

    if (*(int *)(param_1 + 200) == 0) {

      DAT_00b45510 = *(uint32_t /* width from decompiler */ *)(param_1 + 0xcc);

    }

    else {

      *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 200) + 0xcc) = *(uint32_t /* width from decompiler */ *)(param_1 + 0xcc);

    }

    if (*(int *)(param_1 + 0xcc) == 0) {

      DAT_00b45514 = *(uint32_t /* width from decompiler */ *)(param_1 + 200);

    }

    else {

      *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xcc) + 200) = *(uint32_t /* width from decompiler */ *)(param_1 + 200);

    }

    DAT_00b45518 = DAT_00b45518 + -1;

    if (DAT_00b45518 == 0) {

      DAT_00b45510 = 0;

      DAT_00b45514 = 0;

    }

  }

  return;

}
