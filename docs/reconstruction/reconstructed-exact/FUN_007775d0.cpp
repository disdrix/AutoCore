// =============================================================================
// FUN_007775d0
// -----------------------------------------------------------------------------
// Stable ID: aa_007775d0
// Address:   0x007775d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007775d0 @ 0x007775d0
// Stable ID: aa_007775d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~46 non-empty decompiler lines.
//  - Control keywords: if×6, return×4, do×2, while×2, goto×1.
//  - Notable callees: FUN_007701d0, FUN_00770440, FUN_007707d0, FUN_007760c0, FUN_00777440, FUN_007775d0.
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

int FUN_007775d0(int *param_1,int param_2,uint32_t /* width from decompiler */ *param_3)



{

  uint uVar1;

  int iVar2;

  uint *puVar3;

  int iVar4;

  int local_14;

  uint local_10;

  uint *local_4;

  

  *param_3 = 0;

  if ((param_2 < 1) || (0x100 < param_2)) {

    return -3;

  }

  puVar3 = &DAT_00a23cd0;

  do {

    if ((((param_1[2] != 1) && (*param_1 < 2)) && (*(uint *)param_1[3] <= *puVar3)) &&

       (*puVar3 <= *(uint *)param_1[3])) {

      *param_3 = 1;

      return 0;

    }

    puVar3 = puVar3 + 1;

  } while ((int)puVar3 < 0xa240d0);

  iVar2 = FUN_007760c0();

  if ((iVar2 != 0) || (local_14 == 1)) {

    return iVar2;

  }

  iVar2 = FUN_00770440();

  if (iVar2 == 0) {

    iVar4 = 0;

    if (0 < param_2) {

      do {

        uVar1 = (&DAT_00a23cd0)[iVar4];

        FUN_007701d0();

        local_10 = (uint)((uVar1 & 0xfffffff) != 0);

        *local_4 = uVar1 & 0xfffffff;

        iVar2 = FUN_00777440(param_1,&local_14);

        if ((iVar2 != 0) || (local_14 == 0)) goto LAB_007776ca;

        iVar4 = iVar4 + 1;

      } while (iVar4 < param_2);

    }

    *param_3 = 1;

LAB_007776ca:

    FUN_007707d0();

  }

  return iVar2;

}
