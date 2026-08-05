// =============================================================================
// FUN_0042ffc0
// -----------------------------------------------------------------------------
// Stable ID: aa_0042ffc0
// Address:   0x0042ffc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0042ffc0 @ 0x0042ffc0
// Stable ID: aa_0042ffc0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~59 non-empty decompiler lines.
//  - Control keywords: if×7, do×2, while×2, return×2.
//  - Notable callees: BitStream_readBits×2, FUN_0042bdf0×2, FUN_0042ba90, FUN_0042bd10, FUN_0042c6c0, FUN_0042ffc0, FUN_007838a0.
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

void FUN_0042ffc0(uint32_t /* width from decompiler */ param_1,int param_2)



{

  char cVar1;

  int *piVar2;

  int iVar3;

  int *piVar4;

  int *piVar5;

  bool bVar6;

  int local_384 [4];

  uint8_t local_374 [256];

  uint8_t local_274 [624];

  int *piStack_4;

  

  piVar2 = (int *)FUN_0042c6c0();

  if (piVar2 != (int *)0x0) {

    BitStream_readBits(0x40,local_384 + 2);

    BitStream_readBits(0x40,local_384);

    iVar3 = 2;

    bVar6 = true;

    piVar4 = local_384 + 2;

    piVar5 = piVar2 + 0x4e;

    do {

      if (iVar3 == 0) break;

      iVar3 = iVar3 + -1;

      bVar6 = *piVar4 == *piVar5;

      piVar4 = piVar4 + 1;

      piVar5 = piVar5 + 1;

    } while (bVar6);

    if (bVar6) {

      iVar3 = 2;

      bVar6 = true;

      piVar4 = local_384;

      piVar5 = piVar2 + 0x50;

      do {

        if (iVar3 == 0) break;

        iVar3 = iVar3 + -1;

        bVar6 = *piVar4 == *piVar5;

        piVar4 = piVar4 + 1;

        piVar5 = piVar5 + 1;

      } while (bVar6);

      if (bVar6) {

        *(uint *)(param_2 + 0x18) = *(int *)(param_2 + 0x18) + 7U & 0xfffffff8;

        if (*(char *)((int)piVar2 + 0x135) != '\0') {

          FUN_007838a0();

          cVar1 = FUN_0042bd10(param_2,5,local_274);

          if (cVar1 == '\0') {

            FUN_0042bdf0();

            return;

          }

          FUN_0042bdf0();

        }

        FUN_0042ba90(local_374);

        piVar2[0x6e] = 8;

        (**(code **)(*piVar2 + 0x10))(3,local_374);

        (**(code **)(*piStack_4 + 0x10))(piVar2);

      }

    }

  }

  return;

}
