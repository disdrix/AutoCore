// =============================================================================
// FUN_005813b0
// -----------------------------------------------------------------------------
// Stable ID: aa_005813b0
// Address:   0x005813b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005813b0 @ 0x005813b0
// Stable ID: aa_005813b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, do×1, while×1.
//  - Notable callees: fwrite×5, CONCAT31, FUN_005813b0.
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

uint32_t /* width from decompiler */ __thiscall FUN_005813b0(int param_1,FILE *param_2)



{

  char *pcVar1;

  char cVar2;

  FILE *_File;

  char *pcVar3;

  size_t local_8;

  uint32_t /* width from decompiler */ local_4;

  

  _File = param_2;

  if (param_2 == (FILE *)0x0) {

    return 0;

  }

  pcVar3 = *(char **)(param_1 + 0x18);

  if (pcVar3 == (char *)0x0) {

    local_8 = 0;

    fwrite(&local_8,4,1,param_2);

  }

  else {

    pcVar1 = pcVar3 + 1;

    do {

      cVar2 = *pcVar3;

      pcVar3 = pcVar3 + 1;

    } while (cVar2 != '\0');

    local_8 = (int)pcVar3 - (int)pcVar1;

    fwrite(&local_8,4,1,param_2);

    fwrite(*(void **)(param_1 + 0x18),1,local_8,_File);

  }

  param_2 = (FILE *)(CONCAT31(param_2._1_3_,

                              (char)(*(uint *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0x180 + param_1

                                              ) >> 0x12)) & 0xffffff01);

  fwrite(&param_2,1,1,_File);

  local_4 = *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0x118 + param_1);

  fwrite(&local_4,4,1,_File);

  return 1;

}
