// =============================================================================
// FUN_00523d50
// -----------------------------------------------------------------------------
// Stable ID: aa_00523d50
// Address:   0x00523d50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00523d50 @ 0x00523d50
// Stable ID: aa_00523d50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×3, return×3, do×1, while×1.
//  - Notable callees: SQRT×2, FUN_00523d50, FUN_00574760.
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

uint32_t /* width from decompiler */ __thiscall FUN_00523d50(int param_1,float *param_2)



{

  float *pfVar1;

  int iVar2;

  int iVar3;

  

  pfVar1 = (float *)(**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) + 0x1a0

                                ))();

  if (SQRT((pfVar1[2] - param_2[2]) * (pfVar1[2] - param_2[2]) +

           (*pfVar1 - *param_2) * (*pfVar1 - *param_2)) <= DAT_00aaa884) {

    return 1;

  }

  if ((*(int *)(param_1 + 0xcb0) != 0) &&

     (iVar3 = 0, *(char *)(*(int *)(param_1 + 0xcb0) + 0x1d8) != '\0')) {

    do {

      iVar2 = FUN_00574760(iVar3);

      if ((iVar2 != 0) &&

         (pfVar1 = (float *)(**(code **)(*(int *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 4 + iVar2) +

                                        0x1a0))(),

         DAT_00aaa884 <

         SQRT((pfVar1[2] - param_2[2]) * (pfVar1[2] - param_2[2]) +

              (*pfVar1 - *param_2) * (*pfVar1 - *param_2)))) {

        return 1;

      }

      iVar3 = iVar3 + 1;

    } while (iVar3 < (int)(uint)*(byte *)(*(int *)(param_1 + 0xcb0) + 0x1d8));

  }

  return 0;

}
