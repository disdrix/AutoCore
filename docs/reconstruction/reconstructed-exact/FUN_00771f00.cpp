// =============================================================================
// FUN_00771f00
// -----------------------------------------------------------------------------
// Stable ID: aa_00771f00
// Address:   0x00771f00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00771f00 @ 0x00771f00
// Stable ID: aa_00771f00
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~67 non-empty decompiler lines.
//  - Control keywords: if×7, while×2, for×1, do×1, return×1.
//  - Notable callees: __allmul×2, CONCAT44, FUN_007703d0, FUN_007707d0, FUN_00771f00.
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

int FUN_00771f00(int *param_1,int *param_2,uint32_t /* width from decompiler */ *param_3)



{

  int iVar1;

  int iVar2;

  uint uVar3;

  int *piVar4;

  int iVar5;

  int iVar6;

  uint32_t /* width from decompiler */ uVar7;

  ulonglong uVar8;

  longlong lVar9;

  int local_c;

  int local_8;

  int local_4;

  

  iVar2 = FUN_007703d0();

  if (iVar2 == 0) {

    iVar2 = *param_1;

    local_8 = param_1[2];

    uVar7 = 0;

    uVar8 = 0;

    iVar1 = iVar2;

    while (iVar1 = iVar1 + -1, -1 < iVar1) {

      iVar6 = (int)((uVar8 << 0x1c) >> 0x20);

      uVar3 = *(uint *)(param_1[3] + iVar1 * 4) | (uint)(uVar8 << 0x1c);

      if ((iVar6 == 0) && (uVar3 < 3)) {

        iVar5 = 0;

        uVar8 = (ulonglong)uVar3;

      }

      else {

        uVar8 = __allmul(uVar3,iVar6,0x5555555,0);

        iVar5 = (int)(uVar8 >> 0x1c);

        lVar9 = __allmul(uVar8 >> 0x1c,0xfffffffd,0xffffffff);

        uVar8 = lVar9 + CONCAT44(iVar6,uVar3);

        iVar6 = (int)(uVar8 >> 0x20);

        for (; (iVar6 != 0 || (2 < (uint)uVar8)); uVar8 = uVar8 - 3) {

          iVar5 = iVar5 + 1;

          iVar6 = (int)(uVar8 >> 0x20) + -1 + (uint)(2 < (uint)uVar8);

        }

      }

      uVar7 = (uint32_t /* width from decompiler */)uVar8;

      *(int *)(local_4 + iVar1 * 4) = iVar5;

    }

    if (param_3 != (uint32_t /* width from decompiler */ *)0x0) {

      *param_3 = uVar7;

    }

    if (param_2 != (int *)0x0) {

      if (0 < iVar2) {

        piVar4 = (int *)(local_4 + -4 + iVar2 * 4);

        do {

          if (*piVar4 != 0) break;

          iVar2 = iVar2 + -1;

          piVar4 = piVar4 + -1;

        } while (0 < iVar2);

      }

      if (iVar2 == 0) {

        local_8 = 0;

      }

      *param_2 = iVar2;

      param_2[1] = local_c;

      param_2[2] = local_8;

      param_2[3] = local_4;

    }

    FUN_007707d0();

    iVar2 = 0;

  }

  return iVar2;

}
