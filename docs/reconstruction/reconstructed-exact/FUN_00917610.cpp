// =============================================================================
// FUN_00917610
// -----------------------------------------------------------------------------
// Stable ID: aa_00917610
// Address:   0x00917610  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00917610 @ 0x00917610
// Stable ID: aa_00917610
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~39 non-empty decompiler lines.
//  - Control keywords: if×3, return×3.
//  - Notable callees: _CIacos×2, FUN_004e88e0, FUN_004e8a40, FUN_00917610, _CIasin.
//  - Return sites: 3.

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

void FUN_00917610(void)



{

  uint32_t /* width from decompiler */ *puVar1;

  int unaff_ESI;

  float10 fVar2;

  float afStack_3c [2];

  float fStack_34;

  uint32_t /* width from decompiler */ uStack_30;

  uint32_t /* width from decompiler */ uStack_2c;

  uint32_t /* width from decompiler */ uStack_28;

  uint32_t /* width from decompiler */ uStack_24;

  uint8_t auStack_20 [28];

  

  if (DAT_00d1b6d8 != 0) {

    puVar1 = (uint32_t /* width from decompiler */ *)

             (**(code **)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 + DAT_00d1b6d8) +

                         0x1a4))();

    uStack_30 = *puVar1;

    uStack_2c = puVar1[1];

    uStack_28 = puVar1[2];

    uStack_24 = puVar1[3];

    FUN_004e8a40(&uStack_30,auStack_20);

    FUN_004e88e0(afStack_3c,auStack_20);

    *(float *)(unaff_ESI + 0x5ac) = 0.0 - afStack_3c[0];

    *(float *)(unaff_ESI + 0x5b4) = 0.0 - fStack_34;

    if (0.0 - fStack_34 < 0.0) {

      fVar2 = (float10)_CIasin();

      *(float *)(unaff_ESI + 0xa48) = (float)fVar2;

      return;

    }

    if (0.0 < 0.0 - afStack_3c[0]) {

      fVar2 = (float10)_CIacos();

      *(float *)(unaff_ESI + 0xa48) = (float)fVar2;

      return;

    }

    fVar2 = (float10)_CIacos();

    *(float *)(unaff_ESI + 0xa48) = (float)-fVar2;

  }

  return;

}
