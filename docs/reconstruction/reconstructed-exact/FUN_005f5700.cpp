// =============================================================================
// FUN_005f5700
// -----------------------------------------------------------------------------
// Stable ID: aa_005f5700
// Address:   0x005f5700  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005f5700 @ 0x005f5700
// Stable ID: aa_005f5700
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, do×1, while×1.
//  - Notable callees: FUN_005b3370, FUN_005f5700.
//  - Return sites: 2.

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

void __thiscall FUN_005f5700(int param_1,int param_2,uint32_t /* width from decompiler */ param_3)



{

  int iVar1;

  int iVar2;

  int *piVar3;

  

  iVar2 = 0;

  if (0 < *(int *)(param_1 + 0x34)) {

    piVar3 = *(int **)(param_1 + 0x30);

    do {

      if (*piVar3 == param_2) {

        return;

      }

      iVar2 = iVar2 + 1;

      piVar3 = piVar3 + 2;

    } while (iVar2 < *(int *)(param_1 + 0x34));

  }

  if (*(uint *)(param_1 + 0x34) == (*(uint *)(param_1 + 0x38) & 0x7fffffff)) {

    FUN_005b3370((int *)(param_1 + 0x30),8);

  }

  iVar2 = *(int *)(param_1 + 0x34);

  iVar1 = *(int *)(param_1 + 0x30);

  *(int *)(iVar1 + iVar2 * 8) = param_2;

  *(uint32_t /* width from decompiler */ *)(iVar1 + 4 + iVar2 * 8) = param_3;

  *(int *)(param_1 + 0x34) = *(int *)(param_1 + 0x34) + 1;

  return;

}
