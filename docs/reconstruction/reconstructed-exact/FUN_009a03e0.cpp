// =============================================================================
// FUN_009a03e0
// -----------------------------------------------------------------------------
// Stable ID: aa_009a03e0
// Address:   0x009a03e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009a03e0 @ 0x009a03e0
// Stable ID: aa_009a03e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~51 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: CONCAT44×2, CARRY4, __aullrem.
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

    __aullrem

   

   Library: Visual Studio */



uint64_t __aullrem(uint param_1,uint param_2,uint param_3,uint param_4)



{

  ulonglong uVar1;

  longlong lVar2;

  uint uVar3;

  uint uVar4;

  uint uVar5;

  int iVar6;

  int iVar7;

  uint uVar8;

  uint uVar9;

  uint uVar10;

  bool bVar11;

  

  uVar3 = param_1;

  uVar4 = param_4;

  uVar9 = param_2;

  uVar10 = param_3;

  if (param_4 == 0) {

    iVar6 = (int)(((ulonglong)param_2 % (ulonglong)param_3 << 0x20 | (ulonglong)param_1) %

                 (ulonglong)param_3);

    iVar7 = 0;

  }

  else {

    do {

      uVar5 = uVar4 >> 1;

      uVar10 = uVar10 >> 1 | (uint)((uVar4 & 1) != 0) << 0x1f;

      uVar8 = uVar9 >> 1;

      uVar3 = uVar3 >> 1 | (uint)((uVar9 & 1) != 0) << 0x1f;

      uVar4 = uVar5;

      uVar9 = uVar8;

    } while (uVar5 != 0);

    uVar1 = CONCAT44(uVar8,uVar3) / (ulonglong)uVar10;

    uVar3 = (int)uVar1 * param_4;

    lVar2 = (uVar1 & 0xffffffff) * (ulonglong)param_3;

    uVar9 = (uint)((ulonglong)lVar2 >> 0x20);

    uVar4 = (uint)lVar2;

    uVar10 = uVar9 + uVar3;

    if (((CARRY4(uVar9,uVar3)) || (param_2 < uVar10)) || ((param_2 <= uVar10 && (param_1 < uVar4))))

    {

      bVar11 = uVar4 < param_3;

      uVar4 = uVar4 - param_3;

      uVar10 = (uVar10 - param_4) - (uint)bVar11;

    }

    iVar6 = -(uVar4 - param_1);

    iVar7 = -(uint)(uVar4 - param_1 != 0) - ((uVar10 - param_2) - (uint)(uVar4 < param_1));

  }

  return CONCAT44(iVar7,iVar6);

}
