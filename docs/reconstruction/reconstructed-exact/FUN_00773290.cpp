// =============================================================================
// FUN_00773290
// -----------------------------------------------------------------------------
// Stable ID: aa_00773290
// Address:   0x00773290  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00773290 @ 0x00773290
// Stable ID: aa_00773290
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~84 non-empty decompiler lines.
//  - Control keywords: if×16, return×6, goto×2, while×1.
//  - Notable callees: FUN_00772050×5, FUN_00770650×3, FUN_007706b0×3, FUN_00770440×2, FUN_007707d0×2, FUN_007701d0, FUN_00770540, FUN_00770710.
//  - Return sites: 6.

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

int __thiscall FUN_00773290(int *param_1,int *param_2)



{

  int *in_EAX;

  int iVar1;

  int iVar2;

  int iVar3;

  uint32_t /* width from decompiler */ uVar4;

  int iVar5;

  int local_20 [2];

  uint32_t /* width from decompiler */ local_18;

  uint8_t local_10 [8];

  uint32_t /* width from decompiler */ local_8;

  

  if (*param_1 == 0) {

    if (*in_EAX == 0) {

LAB_007732df:

      FUN_007701d0();

      return 0;

    }

  }

  else {

    iVar1 = *in_EAX;

    in_EAX = param_1;

    if (iVar1 != 0) {

      if (*param_1 != 0) {

        iVar1 = FUN_00770440();

        if (iVar1 != 0) {

          return iVar1;

        }

        iVar1 = FUN_00770650();

        if (iVar1 != 0) {

          return iVar1;

        }

        iVar1 = FUN_00770440();

        if (iVar1 == 0) {

          iVar1 = FUN_00770650();

        }

        if (iVar1 == 0) {

          local_18 = 0;

          local_8 = 0;

          iVar2 = FUN_007706b0();

          iVar3 = FUN_007706b0();

          iVar5 = iVar2;

          if (iVar3 <= iVar2) {

            iVar5 = iVar3;

          }

          if (((iVar5 < 1) ||

              ((iVar1 = FUN_00772050(iVar5,local_10,0), iVar1 == 0 &&

               (iVar1 = FUN_00772050(iVar5,local_20,0), iVar1 == 0)))) &&

             ((iVar2 == iVar5 || (iVar1 = FUN_00772050(iVar2 - iVar5,local_10,0), iVar1 == 0)))) {

            if (iVar3 == iVar5) goto joined_r0x007733d8;

            iVar1 = FUN_00772050(iVar3 - iVar5,local_20,0);

            while (iVar1 == 0) {

joined_r0x007733d8:

              if (local_20[0] == 0) {

                iVar1 = FUN_00772b90(iVar5);

                if (iVar1 == 0) {

                  param_2[2] = 0;

                }

                break;

              }

              iVar1 = FUN_00770710();

              if (iVar1 == 1) {

                FUN_00770540();

              }

              iVar1 = FUN_00770ea0();

              if (iVar1 != 0) break;

              uVar4 = FUN_007706b0(local_20,0);

              iVar1 = FUN_00772050(uVar4);

            }

          }

          FUN_007707d0();

        }

        FUN_007707d0();

        return iVar1;

      }

      goto LAB_007732df;

    }

  }

  if ((in_EAX != param_2) && (iVar1 = FUN_00770650(), iVar1 != 0)) {

    return iVar1;

  }

  param_2[2] = 0;

  return 0;

}
