// =============================================================================
// FUN_006d52c0
// -----------------------------------------------------------------------------
// Stable ID: aa_006d52c0
// Address:   0x006d52c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006d52c0 @ 0x006d52c0
// Stable ID: aa_006d52c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×3, do×1, while×1, return×1.
//  - Notable callees: FUN_005b3300, FUN_006d52c0.
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

uint32_t /* width from decompiler */ * __thiscall

FUN_006d52c0(uint32_t /* width from decompiler */ *param_1,int *param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,

            uint32_t /* width from decompiler */ param_5)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  

  param_1[2] = param_5;

  piVar1 = param_1 + 3;

  *param_1 = &PTR_FUN_00a0e428;

  *piVar1 = (int)(param_1 + 6);

  param_1[4] = 0;

  param_1[5] = 0x80000004;

  iVar2 = *(int *)(*param_2 + 0x14);

  if ((int)(param_1[5] & 0x7fffffff) < iVar2) {

    iVar3 = (param_1[5] & 0x7fffffff) * 2;

    if (iVar3 <= iVar2) {

      iVar3 = iVar2;

    }

    FUN_005b3300(piVar1,iVar3,4);

  }

  iVar3 = 0;

  param_1[4] = iVar2;

  if (0 < iVar2) {

    do {

      *(uint8_t *)(*piVar1 + iVar3 * 4) = 0;

      iVar3 = iVar3 + 1;

    } while (iVar3 < iVar2);

  }

  return param_1;

}
