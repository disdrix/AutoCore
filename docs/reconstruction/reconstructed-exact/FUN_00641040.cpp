// =============================================================================
// FUN_00641040
// -----------------------------------------------------------------------------
// Stable ID: aa_00641040
// Address:   0x00641040  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00641040 @ 0x00641040
// Stable ID: aa_00641040
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: if×3, for×1, return×1.
//  - Notable callees: FUN_005b3300, FUN_0063f630, FUN_00641040.
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

uint32_t /* width from decompiler */ * __thiscall FUN_00641040(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  

  *param_1 = &PTR_FUN_009e40a0;

  *(uint16_t *)((int)param_1 + 6) = 1;

  param_1[2] = 0;

  param_1[3] = 0;

  param_1[4] = 0x80000000;

  param_1[6] = param_2;

  param_1[7] = param_3;

  param_1[5] = 0;

  piVar1 = param_1 + 8;

  *piVar1 = 0;

  param_1[9] = 0;

  param_1[10] = 0x80000000;

  *(short *)(param_1[7] + 6) = *(short *)(param_1[7] + 6) + 1;

  iVar2 = FUN_0063f630();

  iVar2 = *(int *)(iVar2 + 4);

  iVar4 = param_1[9];

  if (iVar4 < iVar2) {

    if ((int)(param_1[10] & 0x7fffffff) < iVar2) {

      iVar3 = (param_1[10] & 0x7fffffff) * 2;

      if (iVar3 <= iVar2) {

        iVar3 = iVar2;

      }

      FUN_005b3300(piVar1,iVar3,4);

    }

    for (; iVar4 < iVar2; iVar4 = iVar4 + 1) {

      *(uint32_t /* width from decompiler */ *)(*piVar1 + iVar4 * 4) = 0;

    }

  }

  param_1[9] = iVar2;

  return param_1;

}
