// =============================================================================
// FUN_00777440
// -----------------------------------------------------------------------------
// Stable ID: aa_00777440
// Address:   0x00777440  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00777440 @ 0x00777440
// Stable ID: aa_00777440
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~60 non-empty decompiler lines.
//  - Control keywords: if×13, return×4, goto×4, do×1, while×1.
//  - Notable callees: FUN_00770440×3, FUN_007707a0×3, FUN_007707d0×3, FUN_00770650×2, FUN_00770770×2, FUN_007706b0, FUN_00771600, FUN_00772050.
//  - Return sites: 4.

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

int FUN_00777440(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ *param_2)



{

  int *in_EAX;

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int extraout_ECX;

  uint8_t local_30 [16];

  uint8_t local_20 [16];

  uint8_t local_10 [16];

  

  *param_2 = 0;

  if ((in_EAX[2] == 1) || ((*in_EAX < 2 && (*(uint *)in_EAX[3] < 2)))) {

    return -3;

  }

  iVar1 = FUN_00770440();

  if (iVar1 != 0) {

    return iVar1;

  }

  iVar1 = FUN_00770650();

  if (iVar1 != 0) {

    return iVar1;

  }

  iVar1 = FUN_00771600(local_20,1,local_20);

  if (iVar1 != 0) goto LAB_007775be;

  iVar1 = FUN_00770440();

  if (iVar1 == 0) {

    iVar1 = FUN_00770650();

  }

  if (iVar1 != 0) goto LAB_007775be;

  iVar2 = FUN_007706b0();

  iVar1 = FUN_00772050(iVar2,local_10,0);

  if ((iVar1 == 0) && (iVar1 = FUN_00770440(), iVar1 == 0)) {

    iVar1 = FUN_007772e0();

    if (iVar1 == 0) {

      iVar3 = FUN_00770770();

      if ((iVar3 != 0) && (iVar3 = FUN_007707a0(), iVar3 != 0)) {

        iVar3 = 1;

        if (0 < iVar2 + -1) {

          do {

            iVar4 = FUN_007707a0();

            if (iVar4 == 0) break;

            iVar1 = FUN_00775e20(local_30,param_1,local_30);

            if ((iVar1 != 0) || (iVar4 = FUN_00770770(), iVar4 == 0)) goto LAB_007775ab;

            iVar3 = iVar3 + extraout_ECX;

          } while (iVar3 <= iVar2 + -1);

        }

        iVar2 = FUN_007707a0();

        if (iVar2 != 0) goto LAB_007775ab;

      }

      *param_2 = 1;

    }

LAB_007775ab:

    FUN_007707d0();

  }

  FUN_007707d0();

LAB_007775be:

  FUN_007707d0();

  return iVar1;

}
