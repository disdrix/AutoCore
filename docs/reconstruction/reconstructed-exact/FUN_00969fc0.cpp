// =============================================================================
// FUN_00969fc0
// -----------------------------------------------------------------------------
// Stable ID: aa_00969fc0
// Address:   0x00969fc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00969fc0 @ 0x00969fc0
// Stable ID: aa_00969fc0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_0076f5f0, FUN_00969b40, FUN_00969fc0.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



int FUN_00969fc0(void)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint32_t /* width from decompiler */ uVar6;

  int unaff_ESI;

  

  if (*(char *)(unaff_ESI + 0x118) != '\0') {

    if ((_DAT_00d20650 & 1) == 0) {

      _DAT_00d20650 = _DAT_00d20650 | 1;

      DAT_00d20644 = g_flOne;

      DAT_00d20648 = 0;

      DAT_00d2064c = 0;

    }

    *(uint8_t *)(unaff_ESI + 0x118) = 0;

    FUN_0076f5f0();

    FUN_00969b40();

    fVar1 = *(float *)(unaff_ESI + 0x128);

    fVar2 = *(float *)(unaff_ESI + 0x11c);

    fVar3 = *(float *)(unaff_ESI + 0x120);

    fVar4 = *(float *)(unaff_ESI + 0x124);

    uVar5 = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 300);

    uVar6 = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x130);

    *(float *)(unaff_ESI + 0x11c) = *(float *)(unaff_ESI + 0x134);

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x120) = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x138);

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x124) = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x13c);

    *(float *)(unaff_ESI + 0x128) = 0.0 - fVar2;

    *(float *)(unaff_ESI + 300) = 0.0 - fVar3;

    *(float *)(unaff_ESI + 0x134) = fVar1;

    *(float *)(unaff_ESI + 0x130) = 0.0 - fVar4;

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x138) = uVar5;

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x13c) = uVar6;

  }

  return unaff_ESI + 0x11c;

}
