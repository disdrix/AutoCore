// =============================================================================
// FUN_00464900
// -----------------------------------------------------------------------------
// Stable ID: aa_00464900
// Address:   0x00464900  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00464900 @ 0x00464900
// Stable ID: aa_00464900
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: ABS×6, FUN_00464900.
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



void FUN_00464900(void)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  int in_EAX;

  

  if (*(char *)(in_EAX + 0x218) == '\0') {

    fVar1 = ABS(*(float *)(in_EAX + 0x20c)) * _DAT_00aaa79c;

    fVar5 = ABS(*(float *)(in_EAX + 0x208)) * _DAT_00aaa798;

    fVar4 = ABS(*(float *)(in_EAX + 0x204)) * g_flOverheatCoolFrac;

    fVar3 = ABS(*(float *)(in_EAX + 0x1fc)) * _DAT_00aaa79c;

    fVar2 = ABS(*(float *)(in_EAX + 0x1f8)) * _DAT_00aaa798;

    *(uint8_t *)(in_EAX + 0x218) = 1;

    *(float *)(in_EAX + 0x21c) =

         (ABS(*(float *)(in_EAX + 500)) * g_flOverheatCoolFrac +

         fVar2 + fVar3 + fVar4 + fVar5 + fVar1) * *(float *)(in_EAX + 0x214);

  }

  return;

}
