// =============================================================================
// Named_CalleeOf_Named_CalleeOf_CVOGSectorMap_LoadMapFile_00787530
// -----------------------------------------------------------------------------
// Stable ID: aa_00787530
// Callee of Named_CalleeOf_CVOGSectorMap_LoadMapFile
// Address:   0x00787530  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_CVOGSectorMap_LoadMapFile: config/load helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~59 non-empty decompiler lines.
//  - Control keywords: if×5, return×4, while×2, do×1.
//  - Notable callees: FUN_0079cf40×5, FUN_00793830×3, FUN_007874b0, FUN_00787530, FUN_00793d20, _snprintf.
//  - Strings: "%s %i %i %i ".
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_CVOGSectorMap_LoadMapFile
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_Named_CalleeOf_CVOGSectorMap_LoadMapFile_00787530(int *param_1,int *param_2)



{

  char *pcVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint32_t /* width from decompiler */ unaff_EBP;

  uint8_t uStack_10d;

  uint16_t local_10c;

  uint8_t local_10a;

  uint32_t /* width from decompiler */ local_108;

  uint8_t local_104;

  char local_100;

  char local_ff [255];

  

  local_10c = DAT_00a9ab90;

  local_10a = DAT_00a9ab92;

  local_108 = DAT_00a9ab88;

  local_104 = DAT_00a9ab8c;

  if (*(char *)((int)param_2 + 6) != '\0') {

    _snprintf(&local_100,0x100,"%s %i %i %i ",&local_10c,*param_1,param_1[1],0xff);

    pcVar1 = &local_100;

    while (local_100 != '\0') {

      pcVar1 = pcVar1 + 1;

      local_100 = *pcVar1;

    }

    (**(code **)(*param_2 + 8))(&local_100,(int)pcVar1 - (int)&local_100);

    (**(code **)(*param_2 + 8))(param_1[2],*param_1 * param_1[1]);

    return 1;

  }

  if (*(char *)((int)param_2 + 5) == '\0') {

    return 1;

  }

  FUN_0079cf40(&local_100,0x100,&local_108);

  iVar2 = FUN_00793d20();

  if (iVar2 == 0) {

    uVar3 = (**(code **)(*param_2 + 0x1c))();

    (**(code **)(*param_2 + 4))(&uStack_10d,1);

    if ((char)((uint)unaff_EBP >> 0x18) == '#') {

      do {

        FUN_0079cf40(&local_108,0x100,&DAT_00a9ab74);

        (**(code **)(*param_2 + 0x1c))();

        (**(code **)(*param_2 + 4))(&stack0xfffffeeb,1);

      } while( true );

    }

    (**(code **)(*param_2 + 0x24))(uVar3);

    FUN_0079cf40(&local_10c,0x100,&stack0xfffffeec);

    uVar3 = FUN_00793830(&local_10c);

    FUN_0079cf40(&local_10c,0x100,&stack0xfffffeec);

    uVar4 = FUN_00793830(&local_10c);

    FUN_0079cf40(&local_10c,0x100,&stack0xfffffeec);

    iVar2 = FUN_00793830(&local_10c);

    if (iVar2 == 0xff) {

      FUN_007874b0(uVar3,uVar4);

      (**(code **)(*param_2 + 4))(param_1[2],param_1[1] * *param_1);

      return 1;

    }

  }

  return 0;

}
