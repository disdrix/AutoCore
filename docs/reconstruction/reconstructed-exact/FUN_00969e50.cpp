// =============================================================================
// FUN_00969e50
// -----------------------------------------------------------------------------
// Stable ID: aa_00969e50
// Address:   0x00969e50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00969e50 @ 0x00969e50
// Stable ID: aa_00969e50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00969e50.
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



int FUN_00969e50(void)



{

  float fVar1;

  float fVar2;

  float fVar3;

  int in_EAX;

  float fVar4;

  float fVar5;

  float fVar6;

  

  if (*(char *)(in_EAX + 0xf0) != '\0') {

    if ((_DAT_00d20640 & 1) == 0) {

      _DAT_00d20640 = _DAT_00d20640 | 1;

      _DAT_00d20634 = g_flOne;

      _DAT_00d20638 = 0;

      _DAT_00d2063c = 0;

    }

    *(uint8_t *)(in_EAX + 0xf0) = 0;

    fVar1 = *(float *)(in_EAX + 0x40);

    fVar2 = *(float *)(in_EAX + 0x50);

    fVar3 = *(float *)(in_EAX + 0x30);

    fVar6 = 0.0 - *(float *)(in_EAX + 0x48);

    fVar4 = 0.0 - *(float *)(in_EAX + 0x58);

    fVar5 = 0.0 - *(float *)(in_EAX + 0x38);

    *(float *)(in_EAX + 0xf4) = fVar3;

    *(float *)(in_EAX + 0xf8) = fVar1;

    *(float *)(in_EAX + 0xfc) = fVar2;

    *(float *)(in_EAX + 0x100) = fVar5;

    *(float *)(in_EAX + 0x104) = fVar6;

    *(float *)(in_EAX + 0x108) = fVar4;

    *(float *)(in_EAX + 0x10c) = 0.0 - (fVar2 * fVar6 - fVar1 * fVar4);

    *(float *)(in_EAX + 0x110) = 0.0 - (fVar4 * fVar3 - fVar2 * fVar5);

    *(float *)(in_EAX + 0x114) = 0.0 - (fVar1 * fVar5 - fVar3 * fVar6);

  }

  return in_EAX + 0xf4;

}
