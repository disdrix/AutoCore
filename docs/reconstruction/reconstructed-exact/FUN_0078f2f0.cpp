// =============================================================================
// FUN_0078f2f0
// -----------------------------------------------------------------------------
// Stable ID: aa_0078f2f0
// Address:   0x0078f2f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0078f2f0 @ 0x0078f2f0
// Stable ID: aa_0078f2f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×4, return×4.
//  - Notable callees: FUN_0078f2f0, FUN_00791260.
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

int __thiscall

FUN_0078f2f0(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,uint32_t /* width from decompiler */ param_5

            )



{

  char cVar1;

  int iVar2;

  

  if (((*(int *)(param_1 + 0x948) != 0) && (*(char *)(DAT_00d17948 + 4) != '\0')) &&

     (cVar1 = (**(code **)(**(int **)(param_1 + 0x948) + 0x3c4))(), cVar1 != '\0')) {

    return *(int *)(param_1 + 0x948);

  }

  iVar2 = FUN_00791260(param_2,param_3,param_4,param_5);

  if (iVar2 != 0) {

    if (((*(char *)(DAT_00d17948 + 4) != '\0') && (*(int *)(param_1 + 0x948) != 0)) &&

       (cVar1 = (**(code **)(**(int **)(param_1 + 0x948) + 0x3c4))(), cVar1 != '\0')) {

      return iVar2;

    }

    if (iVar2 == *(int *)(param_1 + 0x940)) {

      return 0;

    }

  }

  return iVar2;

}
