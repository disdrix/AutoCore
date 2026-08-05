// =============================================================================
// FUN_0046cc90
// -----------------------------------------------------------------------------
// Stable ID: aa_0046cc90
// Address:   0x0046cc90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0046cc90 @ 0x0046cc90
// Stable ID: aa_0046cc90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, do×1, while×1.
//  - Notable callees: CONCAT21, CONCAT31, FUN_0046cc90, NAN.
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

uint FUN_0046cc90(void)



{

  int *piVar1;

  float fVar2;

  uint3 uVar3;

  int in_EAX;

  uint uVar4;

  float *pfVar5;

  int iVar6;

  

  uVar4 = *(uint *)(in_EAX + 4);

  piVar1 = (int *)(uVar4 + 0x14);

  iVar6 = 1;

  if (1 < *piVar1) {

    pfVar5 = *(float **)(uVar4 + 0xc);

    do {

      pfVar5 = pfVar5 + 1;

      fVar2 = *pfVar5;

      uVar3 = CONCAT21((short)(uVar4 >> 0x10),

                       (fVar2 == 0.0) << 6 | NAN(fVar2) << 2 | 2U | fVar2 < 0.0);

      uVar4 = (uint)uVar3 << 8;

      if (fVar2 != 0.0) {

        return CONCAT31(uVar3,1);

      }

      iVar6 = iVar6 + 1;

    } while (iVar6 < *piVar1);

  }

  return uVar4 & 0xffffff00;

}
