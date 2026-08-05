// =============================================================================
// FUN_00587750
// -----------------------------------------------------------------------------
// Stable ID: aa_00587750
// Address:   0x00587750  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00587750 @ 0x00587750
// Stable ID: aa_00587750
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~53 non-empty decompiler lines.
//  - Control keywords: do×2, while×2, if×2, return×1.
//  - Notable callees: fwrite×14, CONCAT31, FUN_00587750.
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

uint32_t /* width from decompiler */ __thiscall FUN_00587750(int param_1,FILE *param_2)



{

  char *pcVar1;

  char cVar2;

  FILE *_File;

  char *pcVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint8_t local_15;

  size_t local_14;

  int local_10;

  uint32_t /* width from decompiler */ local_c;

  uint32_t /* width from decompiler */ local_8;

  uint32_t /* width from decompiler */ local_4;

  

  _File = param_2;

  fwrite((void *)(*(int *)(*(int *)(param_1 + -0x4fc) + 4) + -0x47c + param_1),0x10,1,param_2);

  fwrite((void *)(*(int *)(*(int *)(param_1 + -0x4fc) + 4) + -0x46c + param_1),0x10,1,_File);

  puVar4 = (uint32_t /* width from decompiler */ *)(param_1 + -0x3f8);

  local_10 = 0x1e;

  do {

    local_8 = puVar4[1];

    local_15 = *(uint8_t *)(puVar4 + 2);

    local_c = *puVar4;

    param_2 = (FILE *)CONCAT31(param_2._1_3_,*(uint8_t *)(puVar4 + -1));

    local_4 = puVar4[3];

    fwrite(&param_2,1,1,_File);

    fwrite(&local_c,4,1,_File);

    fwrite(&local_8,4,1,_File);

    fwrite(&local_15,1,1,_File);

    fwrite(&local_4,4,1,_File);

    puVar4 = puVar4 + 5;

    local_10 = local_10 + -1;

  } while (local_10 != 0);

  pcVar3 = *(char **)(param_1 + -0x28);

  local_14 = 0;

  if (pcVar3 != (char *)0x0) {

    pcVar1 = pcVar3 + 1;

    do {

      cVar2 = *pcVar3;

      pcVar3 = pcVar3 + 1;

    } while (cVar2 != '\0');

    local_14 = (int)pcVar3 - (int)pcVar1;

  }

  fwrite(&local_14,4,1,_File);

  if (0 < (int)local_14) {

    fwrite(*(void **)(param_1 + -0x28),1,local_14,_File);

  }

  fwrite((void *)(param_1 + -0x24),4,1,_File);

  fwrite((void *)(param_1 + -0x20),4,1,_File);

  fwrite((void *)(param_1 + -0x1c),1,1,_File);

  fwrite((void *)(param_1 + -0x1b),1,1,_File);

  fwrite((void *)(param_1 + -0x1a),1,1,_File);

  return 1;

}
