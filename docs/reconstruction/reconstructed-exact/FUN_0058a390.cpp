// =============================================================================
// FUN_0058a390
// -----------------------------------------------------------------------------
// Stable ID: aa_0058a390
// Address:   0x0058a390  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0058a390 @ 0x0058a390
// Stable ID: aa_0058a390
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~39 non-empty decompiler lines.
//  - Control keywords: if×8, return×2.
//  - Notable callees: CONCAT21, CONCAT31, FUN_0058a390, NAN.
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

uint FUN_0058a390(int *param_1,int param_2,float param_3)



{

  float fVar1;

  uint in_EAX;

  int iVar2;

  

  if (param_1 != (int *)0x0) {

    iVar2 = (**(code **)(*param_1 + 0x214))();

    in_EAX = 0;

    if (iVar2 != 0) {

      if (*(float *)(param_2 + 0xa8) != 0.0) {

        *(float *)(iVar2 + 0x164) = *(float *)(param_2 + 0xa8) * param_3 + *(float *)(iVar2 + 0x164)

        ;

      }

      if (*(float *)(param_2 + 0xac) != 0.0) {

        *(float *)(iVar2 + 0x168) = *(float *)(param_2 + 0xac) * param_3 + *(float *)(iVar2 + 0x168)

        ;

      }

      if (*(float *)(param_2 + 0xb0) != 0.0) {

        *(float *)(iVar2 + 0x16c) = *(float *)(param_2 + 0xb0) * param_3 + *(float *)(iVar2 + 0x16c)

        ;

      }

      if (*(float *)(param_2 + 0xb4) != 0.0) {

        *(float *)(iVar2 + 0x170) = *(float *)(param_2 + 0xb4) * param_3 + *(float *)(iVar2 + 0x170)

        ;

      }

      if (*(float *)(param_2 + 0xb8) != 0.0) {

        *(float *)(iVar2 + 0x174) = *(float *)(param_2 + 0xb8) * param_3 + *(float *)(iVar2 + 0x174)

        ;

      }

      fVar1 = *(float *)(param_2 + 0xbc);

      if (fVar1 != 0.0) {

        *(float *)(iVar2 + 0x178) = fVar1 * param_3 + *(float *)(iVar2 + 0x178);

      }

      return CONCAT31(CONCAT21((short)((uint)iVar2 >> 0x10),

                               (fVar1 == 0.0) << 6 | NAN(fVar1) << 2 | 2U | fVar1 < 0.0),1);

    }

  }

  return in_EAX & 0xffffff00;

}
