// =============================================================================
// FUN_009a0370
// -----------------------------------------------------------------------------
// Stable ID: aa_009a0370
// Address:   0x009a0370  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009a0370 @ 0x009a0370
// Stable ID: aa_009a0370
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~45 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: CONCAT44×2, CARRY4, __aulldiv.
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

    __aulldiv

   

   Library: Visual Studio */



uint64_t __aulldiv(uint param_1,uint param_2,uint param_3,uint param_4)



{

  ulonglong uVar1;

  longlong lVar2;

  uint uVar3;

  int iVar4;

  uint uVar5;

  uint uVar6;

  uint uVar7;

  uint uVar8;

  uint uVar9;

  

  uVar3 = param_1;

  uVar8 = param_4;

  uVar6 = param_2;

  uVar9 = param_3;

  if (param_4 == 0) {

    uVar3 = param_2 / param_3;

    iVar4 = (int)(((ulonglong)param_2 % (ulonglong)param_3 << 0x20 | (ulonglong)param_1) /

                 (ulonglong)param_3);

  }

  else {

    do {

      uVar5 = uVar8 >> 1;

      uVar9 = uVar9 >> 1 | (uint)((uVar8 & 1) != 0) << 0x1f;

      uVar7 = uVar6 >> 1;

      uVar3 = uVar3 >> 1 | (uint)((uVar6 & 1) != 0) << 0x1f;

      uVar8 = uVar5;

      uVar6 = uVar7;

    } while (uVar5 != 0);

    uVar1 = CONCAT44(uVar7,uVar3) / (ulonglong)uVar9;

    iVar4 = (int)uVar1;

    lVar2 = (ulonglong)param_3 * (uVar1 & 0xffffffff);

    uVar3 = (uint)((ulonglong)lVar2 >> 0x20);

    uVar8 = uVar3 + iVar4 * param_4;

    if (((CARRY4(uVar3,iVar4 * param_4)) || (param_2 < uVar8)) ||

       ((param_2 <= uVar8 && (param_1 < (uint)lVar2)))) {

      iVar4 = iVar4 + -1;

    }

    uVar3 = 0;

  }

  return CONCAT44(uVar3,iVar4);

}
