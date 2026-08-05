// =============================================================================
// FUN_00718350
// -----------------------------------------------------------------------------
// Stable ID: aa_00718350
// Address:   0x00718350  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00718350 @ 0x00718350
// Stable ID: aa_00718350
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~74 non-empty decompiler lines.
//  - Control keywords: if×9, do×2, while×2, return×1.
//  - Notable callees: FUN_00718350.
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

float10 FUN_00718350(void)



{

  int iVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  

  iVar1 = 2;

  fVar2 = DAT_00aaacc8;

  fVar4 = DAT_00a110d8;

  do {

    fVar5 = (fVar2 + fVar4) * DAT_00a0f298;

    fVar3 = fVar5;

    if ((ushort)((uint)(DAT_00bc5630 + fVar5 + DAT_009d81fc) >> 6) < 0xb) {

      fVar3 = fVar2;

      fVar4 = fVar5;

    }

    fVar5 = (fVar3 + fVar4) * DAT_00a0f298;

    fVar2 = fVar5;

    if ((ushort)((uint)(DAT_00bc5630 + fVar5 + DAT_009d81fc) >> 6) < 0xb) {

      fVar2 = fVar3;

      fVar4 = fVar5;

    }

    fVar5 = (fVar2 + fVar4) * DAT_00a0f298;

    fVar3 = fVar5;

    if ((ushort)((uint)(DAT_00bc5630 + fVar5 + DAT_009d81fc) >> 6) < 0xb) {

      fVar3 = fVar2;

      fVar4 = fVar5;

    }

    fVar5 = (fVar3 + fVar4) * DAT_00a0f298;

    fVar2 = fVar5;

    if ((ushort)((uint)(DAT_00bc5630 + fVar5 + DAT_009d81fc) >> 6) < 0xb) {

      fVar2 = fVar3;

      fVar4 = fVar5;

    }

    fVar5 = (fVar2 + fVar4) * DAT_00a0f298;

    fVar3 = fVar5;

    if ((ushort)((uint)(DAT_00bc5630 + fVar5 + DAT_009d81fc) >> 6) < 0xb) {

      fVar3 = fVar2;

      fVar4 = fVar5;

    }

    fVar5 = (fVar3 + fVar4) * DAT_00a0f298;

    fVar2 = fVar5;

    if ((ushort)((uint)(DAT_00bc5630 + fVar5 + DAT_009d81fc) >> 6) < 0xb) {

      fVar2 = fVar3;

      fVar4 = fVar5;

    }

    fVar5 = (fVar2 + fVar4) * DAT_00a0f298;

    fVar3 = fVar5;

    if ((ushort)((uint)(DAT_00bc5630 + fVar5 + DAT_009d81fc) >> 6) < 0xb) {

      fVar3 = fVar2;

      fVar4 = fVar5;

    }

    fVar5 = (fVar3 + fVar4) * DAT_00a0f298;

    fVar2 = fVar5;

    if ((ushort)((uint)(DAT_00bc5630 + fVar5 + DAT_009d81fc) >> 6) < 0xb) {

      fVar2 = fVar3;

      fVar4 = fVar5;

    }

    iVar1 = iVar1 + -1;

  } while (iVar1 != 0);

  iVar1 = 7;

  do {

    fVar5 = (fVar2 + fVar4) * DAT_00a0f298;

    fVar3 = fVar5;

    if ((ushort)((uint)(DAT_00bc5630 + fVar5 + DAT_009d81fc) >> 6) < 0xb) {

      fVar3 = fVar2;

      fVar4 = fVar5;

    }

    iVar1 = iVar1 + -1;

    fVar2 = fVar3;

  } while (iVar1 != 0);

  return ((float10)fVar3 + (float10)fVar4) * (float10)DAT_00a0f298 - (float10)DAT_00aaacc8;

}
