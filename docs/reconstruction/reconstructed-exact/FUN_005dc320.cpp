// =============================================================================
// FUN_005dc320
// -----------------------------------------------------------------------------
// Stable ID: aa_005dc320
// Address:   0x005dc320  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005dc320 @ 0x005dc320
// Stable ID: aa_005dc320
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~95 non-empty decompiler lines.
//  - Control keywords: if×8, do×3, while×3, return×2.
//  - Notable callees: fwrite×20, FUN_00512350, FUN_005123b0, FUN_005168a0, FUN_00518870, FUN_005dc260, FUN_005dc320.
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

uint32_t /* width from decompiler */ __thiscall FUN_005dc320(int param_1,FILE *param_2)



{

  FILE *_File;

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  int local_24;

  int local_20;

  int local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  uint32_t /* width from decompiler */ local_10;

  uint32_t /* width from decompiler */ local_c;

  uint local_8;

  uint32_t /* width from decompiler */ local_4;

  

  _File = param_2;

  if (param_2 != (FILE *)0x0) {

    fwrite((void *)(*(int *)(*(int *)(param_1 + -0x1bc) + 4) + -0x13c + param_1),0x10,1,param_2);

    fwrite((void *)(*(int *)(*(int *)(param_1 + -0x1bc) + 4) + -300 + param_1),0x10,1,_File);

    fwrite((void *)(*(int *)(*(int *)(param_1 + -0x1bc) + 4) + -0x104 + param_1),4,1,_File);

    fwrite((void *)(param_1 + -0xdd),0x40,1,_File);

    fwrite((void *)(param_1 + -0x6c),4,1,_File);

    fwrite((void *)(param_1 + -0x68),4,1,_File);

    fwrite((void *)(param_1 + -100),4,1,_File);

    fwrite((void *)(param_1 + -0xe4),1,1,_File);

    fwrite((void *)(param_1 + -0xe2),1,1,_File);

    fwrite((void *)(param_1 + -0xe1),1,1,_File);

    fwrite((void *)(param_1 + -0xde),1,1,_File);

    fwrite((void *)(param_1 + -0xe0),1,1,_File);

    fwrite((void *)(param_1 + -0xdf),1,1,_File);

    fwrite((void *)(param_1 + -0x35),1,1,_File);

    FUN_005168a0(param_1 + -0x7c,0x3a);

    if (*(int *)(param_1 + -0x78) == 0) {

      param_2 = (FILE *)0x0;

    }

    else {

      param_2 = (FILE *)(*(int *)(param_1 + -0x74) - *(int *)(param_1 + -0x78) >> 3);

    }

    fwrite(&param_2,4,1,_File);

    iVar2 = 0;

    if (0 < (int)param_2) {

      do {

        local_18 = *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + -0x78) + iVar2 * 8);

        local_14 = *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + -0x78) + iVar2 * 8 + 4);

        FUN_00512350(_File,&local_18);

        iVar2 = iVar2 + 1;

      } while (iVar2 < (int)param_2);

    }

    if (*(char *)(param_1 + -0xe4) == '\x04') {

      FUN_00518870(param_1 + -0x9c,0xffffffff);

    }

    if (*(int *)(param_1 + -0x98) == 0) {

      local_24 = 0;

    }

    else {

      local_24 = *(int *)(param_1 + -0x94) - *(int *)(param_1 + -0x98) >> 4;

    }

    fwrite(&local_24,4,1,_File);

    iVar2 = 0;

    if (0 < local_24) {

      local_1c = 0;

      do {

        puVar1 = (uint32_t /* width from decompiler */ *)(*(int *)(param_1 + -0x98) + local_1c);

        local_10 = *puVar1;

        local_c = puVar1[1];

        local_4 = puVar1[3];

        local_8 = puVar1[2] & 0xffffff00;

        FUN_005123b0(_File,&local_10);

        local_1c = local_1c + 0x10;

        iVar2 = iVar2 + 1;

      } while (iVar2 < local_24);

    }

    FUN_005dc260(param_1 + -0x5c,

                 *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + -0x1bc) + 4) + -0x118 + param_1));

    if (*(int *)(param_1 + -0x58) == 0) {

      local_20 = 0;

    }

    else {

      local_20 = (*(int *)(param_1 + -0x54) - *(int *)(param_1 + -0x58)) / 0xc;

    }

    fwrite(&local_20,4,1,_File);

    iVar2 = 0;

    if (0 < local_20) {

      local_1c = 0;

      do {

        fwrite((void *)(*(int *)(param_1 + -0x58) + local_1c),0xc,1,_File);

        local_1c = local_1c + 0xc;

        iVar2 = iVar2 + 1;

      } while (iVar2 < local_20);

    }

    fwrite((void *)(param_1 + -0x30),4,1,_File);

    fwrite((void *)(param_1 + -0x28),4,1,_File);

    return 1;

  }

  return 0;

}
