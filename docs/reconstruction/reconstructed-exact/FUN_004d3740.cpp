// =============================================================================
// FUN_004d3740
// -----------------------------------------------------------------------------
// Stable ID: aa_004d3740
// Address:   0x004d3740  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004d3740 @ 0x004d3740
// Stable ID: aa_004d3740
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, for×1.
//  - Notable callees: FUN_004d3670, FUN_004d3740, FUN_004e2fe0, wcscpy.
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

uint32_t /* width from decompiler */ __thiscall FUN_004d3740(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ *param_3)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int local_4;

  

  local_4 = param_1;

  if ((*(int *)(param_1 + 0x3c) == 0) && (*(char *)(param_1 + 0x40) == '\0')) {

    FUN_004d3670();

  }

  FUN_004e2fe0(&local_4,&param_2);

  if (local_4 != *(int *)(param_1 + 0x38)) {

    puVar2 = *(uint32_t /* width from decompiler */ **)(local_4 + 0x10);

    puVar3 = param_3;

    for (iVar1 = 0x1b; iVar1 != 0; iVar1 = iVar1 + -1) {

      *puVar3 = *puVar2;

      puVar2 = puVar2 + 1;

      puVar3 = puVar3 + 1;

    }

    wcscpy((wchar_t *)((int)param_3 + 2),(wchar_t *)(*(int *)(local_4 + 0x10) + 2));

    return 1;

  }

  return 0;

}
