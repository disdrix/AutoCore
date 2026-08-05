// =============================================================================
// FUN_00907f30
// -----------------------------------------------------------------------------
// Stable ID: aa_00907f30
// Address:   0x00907f30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00907f30 @ 0x00907f30
// Stable ID: aa_00907f30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_007a69d0, FUN_00907f30, FUN_009803a0.
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

void FUN_00907f30(uint32_t /* width from decompiler */ param_1)



{

  int iVar1;

  int unaff_ESI;

  

  if (DAT_00d1b6d8 != 0) {

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x538) = 999999999;

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x53c) = 0;

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x530) = 0;

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x534) = 0;

    *(uint8_t *)(unaff_ESI + 0x529) = 0xf;

    *(uint8_t *)(unaff_ESI + 0x528) = 0xf;

    *(uint8_t *)(unaff_ESI + 0x52c) = 0xff;

    *(uint8_t *)(unaff_ESI + 0x52d) = 0xff;

    iVar1 = FUN_007a69d0();

    *(uint8_t *)(unaff_ESI + 0x52e) = *(uint8_t *)(iVar1 + 0x2c);

    *(uint8_t *)(unaff_ESI + 0x52b) = 0x50;

    *(uint8_t *)(unaff_ESI + 0x52a) = 0;

    iVar1 = *(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4);

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x540) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x164 + DAT_00d1b6d8);

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x544) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x168 + DAT_00d1b6d8);

    *(uint8_t *)(unaff_ESI + 0x55d) = 0;

    *(uint8_t *)(unaff_ESI + 0x54c) = 0;

    FUN_009803a0(DAT_00d1ad2c,param_1);

  }

  return;

}
