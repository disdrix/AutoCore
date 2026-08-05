// =============================================================================
// FUN_006a3e40
// -----------------------------------------------------------------------------
// Stable ID: aa_006a3e40
// Address:   0x006a3e40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006a3e40 @ 0x006a3e40
// Stable ID: aa_006a3e40
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~70 non-empty decompiler lines.
//  - Control keywords: if×6, goto×2, do×1, while×1, return×1.
//  - Notable callees: CONCAT44×2, CARRY4, __allrem.
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

/* Library Function - Single Match

    __allrem

   

   Library: Visual Studio */



uint64_t __allrem(uint param_1,uint param_2,uint param_3,uint param_4)



{

  ulonglong uVar1;

  longlong lVar2;

  uint uVar3;

  uint uVar4;

  int iVar5;

  int iVar6;

  uint uVar7;

  uint uVar8;

  uint uVar9;

  uint uVar10;

  uint uVar11;

  bool bVar12;

  bool bVar13;

  

  bVar13 = (int)param_2 < 0;

  if (bVar13) {

    bVar12 = param_1 != 0;

    param_1 = -param_1;

    param_2 = -(uint)bVar12 - param_2;

  }

  uVar11 = (uint)bVar13;

  if ((int)param_4 < 0) {

    bVar13 = param_3 != 0;

    param_3 = -param_3;

    param_4 = -(uint)bVar13 - param_4;

  }

  uVar3 = param_1;

  uVar4 = param_3;

  uVar8 = param_2;

  uVar9 = param_4;

  if (param_4 == 0) {

    iVar5 = (int)(((ulonglong)param_2 % (ulonglong)param_3 << 0x20 | (ulonglong)param_1) %

                 (ulonglong)param_3);

    iVar6 = 0;

    if ((int)(uVar11 - 1) < 0) goto LAB_006a3eed;

  }

  else {

    do {

      uVar10 = uVar9 >> 1;

      uVar4 = uVar4 >> 1 | (uint)((uVar9 & 1) != 0) << 0x1f;

      uVar7 = uVar8 >> 1;

      uVar3 = uVar3 >> 1 | (uint)((uVar8 & 1) != 0) << 0x1f;

      uVar8 = uVar7;

      uVar9 = uVar10;

    } while (uVar10 != 0);

    uVar1 = CONCAT44(uVar7,uVar3) / (ulonglong)uVar4;

    uVar3 = (int)uVar1 * param_4;

    lVar2 = (uVar1 & 0xffffffff) * (ulonglong)param_3;

    uVar8 = (uint)((ulonglong)lVar2 >> 0x20);

    uVar4 = (uint)lVar2;

    uVar9 = uVar8 + uVar3;

    if (((CARRY4(uVar8,uVar3)) || (param_2 < uVar9)) || ((param_2 <= uVar9 && (param_1 < uVar4)))) {

      bVar13 = uVar4 < param_3;

      uVar4 = uVar4 - param_3;

      uVar9 = (uVar9 - param_4) - (uint)bVar13;

    }

    iVar5 = uVar4 - param_1;

    iVar6 = (uVar9 - param_2) - (uint)(uVar4 < param_1);

    if (-1 < (int)(uVar11 - 1)) goto LAB_006a3eed;

  }

  bVar13 = iVar5 != 0;

  iVar5 = -iVar5;

  iVar6 = -(uint)bVar13 - iVar6;

LAB_006a3eed:

  return CONCAT44(iVar6,iVar5);

}
