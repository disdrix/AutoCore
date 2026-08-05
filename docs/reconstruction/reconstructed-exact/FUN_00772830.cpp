// =============================================================================
// FUN_00772830
// -----------------------------------------------------------------------------
// Stable ID: aa_00772830
// Address:   0x00772830  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00772830 @ 0x00772830
// Stable ID: aa_00772830
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×2, for×1, while×1, return×1.
//  - Notable callees: FUN_00772050×2, FUN_00770440, FUN_00770710, FUN_007707d0, FUN_00770ea0, FUN_007714a0, FUN_00771920, FUN_00772830.
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

int FUN_00772830(uint32_t /* width from decompiler */ param_1,int *param_2,int param_3)



{

  int iVar1;

  uint uVar2;

  int iVar3;

  int iVar4;

  uint8_t local_10 [16];

  

  iVar1 = FUN_00770440();

  if (iVar1 == 0) {

    iVar1 = *param_2;

    if (iVar1 == 0) {

      iVar4 = 0;

    }

    else {

      iVar4 = iVar1 * 0x1c + -0x1c;

      for (uVar2 = *(uint *)(param_2[3] + -4 + iVar1 * 4); uVar2 != 0; uVar2 = uVar2 >> 1) {

        iVar4 = iVar4 + 1;

      }

    }

    iVar1 = FUN_00772050(iVar4,local_10,param_1);

    while (((iVar1 == 0 &&

            (((param_3 == 1 || (iVar1 = FUN_00771920(local_10,param_3,local_10), iVar1 == 0)) &&

             (iVar1 = FUN_007714a0(param_1), iVar1 == 0)))) && (iVar3 = FUN_00770710(), iVar3 != -1)

           )) {

      FUN_00770ea0();

      iVar1 = FUN_00772050(iVar4,local_10,param_1);

    }

    FUN_007707d0();

  }

  return iVar1;

}
