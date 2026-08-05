// =============================================================================
// FUN_00776110
// -----------------------------------------------------------------------------
// Stable ID: aa_00776110
// Address:   0x00776110  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00776110 @ 0x00776110
// Stable ID: aa_00776110
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~57 non-empty decompiler lines.
//  - Control keywords: if×9, goto×4, return×2, while×2, do×1.
//  - Notable callees: FUN_00770440×3, FUN_007707d0×3, FUN_00775a40×3, FUN_007716f0×2, FUN_007701d0, FUN_00770540, FUN_00770650, FUN_00770710.
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

int FUN_00776110(int param_1,uint param_2)



{

  uint32_t /* width from decompiler */ uVar1;

  int iVar2;

  uint32_t /* width from decompiler */ local_30 [2];

  int local_28;

  uint32_t /* width from decompiler */ *local_24;

  uint8_t local_20 [8];

  int local_18;

  uint8_t local_10 [16];

  

  if (((param_2 & 1) == 0) && (*(int *)(param_1 + 8) == 1)) {

    return -3;

  }

  iVar2 = FUN_00770440();

  if (iVar2 == 0) {

    iVar2 = FUN_00770440();

    if (iVar2 == 0) {

      iVar2 = FUN_00770440();

      if (iVar2 == 0) {

        uVar1 = *(uint32_t /* width from decompiler */ *)(param_1 + 8);

        *(uint32_t /* width from decompiler */ *)(param_1 + 8) = 0;

        FUN_007701d0();

        *local_24 = 2;

        local_30[0] = 1;

        do {

          iVar2 = FUN_00770650();

          if (iVar2 != 0) goto LAB_0077630c;

          iVar2 = FUN_00775a40(local_20,param_2 - 1);

          if ((iVar2 != 0) || (iVar2 = FUN_00774e60(local_10,local_20,local_30), iVar2 != 0))

          goto LAB_0077630c;

          iVar2 = FUN_007716f0(local_30);

          if ((iVar2 != 0) ||

             (((iVar2 = FUN_00771920(local_10,param_2,local_10), iVar2 != 0 ||

               (iVar2 = FUN_00773600(local_30,local_10,local_10,0), iVar2 != 0)) ||

              (iVar2 = FUN_007716f0(local_20), iVar2 != 0)))) goto LAB_0077630c;

        } while ((local_18 != local_28) || (iVar2 = FUN_00770710(), iVar2 != 0));

        iVar2 = FUN_00775a40(local_20,param_2);

        if (iVar2 == 0) {

          while (iVar2 = FUN_007707a0(), iVar2 == 1) {

            iVar2 = FUN_00771600(local_20,1,local_20);

            if ((iVar2 != 0) || (iVar2 = FUN_00775a40(local_20,param_2), iVar2 != 0))

            goto LAB_0077630c;

          }

          *(uint32_t /* width from decompiler */ *)(param_1 + 8) = uVar1;

          iVar2 = FUN_00770540();

          *(uint32_t /* width from decompiler */ *)(iVar2 + 8) = uVar1;

          iVar2 = 0;

        }

LAB_0077630c:

        FUN_007707d0();

      }

      FUN_007707d0();

    }

    FUN_007707d0();

  }

  return iVar2;

}
