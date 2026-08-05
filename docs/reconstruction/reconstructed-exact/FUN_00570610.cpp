// =============================================================================
// FUN_00570610
// -----------------------------------------------------------------------------
// Stable ID: aa_00570610
// Address:   0x00570610  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00570610 @ 0x00570610
// Stable ID: aa_00570610
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~49 non-empty decompiler lines.
//  - Control keywords: if×6, return×4, do×2, while×2, goto×1.
//  - Notable callees: CONCAT31×3, FUN_00570610.
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

uint FUN_00570610(byte param_1,byte param_2,byte param_3,byte param_4,int param_5,int param_6,

                 int param_7,int param_8)



{

  uint uVar1;

  uint uVar2;

  longlong lVar3;

  uint uVar4;

  uint uVar5;

  uint uVar6;

  byte bVar7;

  uint uVar8;

  

  uVar4 = (uint)param_3;

  uVar1 = param_1 + uVar4;

  if (param_6 < (int)uVar1) {

    return 0;

  }

  uVar8 = (uint)param_4;

  uVar2 = param_2 + uVar8;

  if (param_7 < (int)uVar2) {

    return 0;

  }

  lVar3 = (longlong)(ulonglong)uVar8 / (longlong)param_8;

  uVar5 = (uint)lVar3;

  if (param_8 < (int)((uint)param_2 + (int)((longlong)(ulonglong)uVar8 % (longlong)param_8))) {

LAB_00570668:

    return uVar5 & 0xffffff00;

  }

  uVar6 = CONCAT31((int3)((ulonglong)lVar3 >> 8),param_3);

  do {

    if (uVar1 <= uVar4) {

      return CONCAT31((int3)(uVar6 >> 8),1);

    }

    if (uVar8 < uVar2) {

      uVar5 = uVar8;

      bVar7 = param_4;

      do {

        uVar5 = uVar5 + (uVar6 & 0xff) * param_7;

        if ((*(uint *)(param_5 + uVar5 * 8) & *(uint *)(param_5 + 4 + uVar5 * 8)) != 0xffffffff)

        goto LAB_00570668;

        bVar7 = bVar7 + 1;

        uVar5 = (uint)bVar7;

      } while (uVar5 < uVar2);

      uVar6 = (uint)param_3;

    }

    param_3 = (char)uVar6 + 1;

    uVar6 = CONCAT31((int3)(uVar6 >> 8),param_3);

    uVar4 = (uint)param_3;

  } while( true );

}
