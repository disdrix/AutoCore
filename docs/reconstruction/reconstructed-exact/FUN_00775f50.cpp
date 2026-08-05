// =============================================================================
// FUN_00775f50
// -----------------------------------------------------------------------------
// Stable ID: aa_00775f50
// Address:   0x00775f50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00775f50 @ 0x00775f50
// Stable ID: aa_00775f50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~50 non-empty decompiler lines.
//  - Control keywords: if×8, return×3, goto×1, do×1, while×1.
//  - Notable callees: FUN_00770280×2, FUN_00770250, FUN_00770440, FUN_00770650, FUN_00770710, FUN_00770770, FUN_007707d0, FUN_00770ea0.
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

int FUN_00775f50(int param_1,uint *param_2,uint32_t /* width from decompiler */ param_3)



{

  uint uVar1;

  int iVar2;

  int iVar3;

  uint32_t /* width from decompiler */ extraout_EDX;

  bool bVar4;

  uint8_t local_10 [16];

  

  uVar1 = *param_2;

  iVar2 = FUN_00770440();

  if (iVar2 != 0) {

    return iVar2;

  }

  iVar2 = FUN_00770650();

  if (iVar2 != 0) {

    return iVar2;

  }

  FUN_00770280();

  if (uVar1 < 0x8000001) {

    iVar2 = FUN_00771150(extraout_EDX,param_3,extraout_EDX,uVar1);

  }

  else {

    iVar2 = FUN_00774e60(extraout_EDX,param_3,extraout_EDX);

  }

  if (iVar2 == 0) {

    FUN_00770280();

    iVar2 = FUN_00771b60((uVar1 + 1) * 0x1c);

    if (((iVar2 == 0) && (iVar2 = FUN_00771300(local_10,param_2,local_10,uVar1 + 1), iVar2 == 0)) &&

       (iVar2 = FUN_007716f0(param_1), iVar2 == 0)) {

      iVar3 = FUN_00770770();

      if (iVar3 == -1) {

        FUN_00770250();

        iVar2 = FUN_00771c00();

        if ((iVar2 != 0) || (iVar2 = FUN_00772390(), iVar2 != 0)) goto LAB_007760a7;

      }

      do {

        if (*(uint *)(param_1 + 8) == param_2[2]) {

          iVar3 = FUN_00770710();

          bVar4 = iVar3 == -1;

        }

        else {

          bVar4 = *(uint *)(param_1 + 8) == 1;

        }

      } while ((!bVar4) && (iVar2 = FUN_00770ea0(), iVar2 == 0));

    }

  }

LAB_007760a7:

  FUN_007707d0();

  return iVar2;

}
