// =============================================================================
// UI_cont_continent_map
// -----------------------------------------------------------------------------
// Stable ID: aa_008ed8a0
// Address:   0x008ed8a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for UI_cont_continent_map @ 0x008ed8a0
// Stable ID: aa_008ed8a0
// Embedded strings (evidence for future rename):
//   - "Central Wastelands"
//   - "i_d_cont_2d_wnd_continent-map.dds"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~104 non-empty decompiler lines.
//  - Control keywords: if×5, while×4, do×2, for×1, return×1.
//  - Notable callees: FUN_0040e490×4, FUN_0040e230×2, FUN_007b6a20×2, InitializeCriticalSection×2, FUN_0040e1e0, FUN_0075e2d0, FUN_007b70b0, FUN_008eba20.
//  - Strings: "Central Wastelands"; "i_d_cont_2d_wnd_continent-map.dds".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "i_d_cont_2d_wnd_continent-map.dds"
 * Domain alias of FUN_008ed8a0 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall UI_cont_continent_map(int param_1)



{

  char cVar1;

  char *pcVar2;

  int iVar3;

  int *piVar4;

  char *pcVar5;

  uint32_t /* width from decompiler */ *puVar6;

  uint16_t *puVar7;

  uint8_t auStack_164 [4];

  undefined **ppuStack_160;

  uint32_t /* width from decompiler */ uStack_15c;

  uint32_t /* width from decompiler */ uStack_158;

  uint32_t /* width from decompiler */ uStack_154;

  _RTL_CRITICAL_SECTION _Stack_150;

  _RTL_CRITICAL_SECTION _Stack_138;

  uint32_t /* width from decompiler */ uStack_120;

  uint16_t uStack_118;

  uint32_t /* width from decompiler */ auStack_116 [64];

  void *pvStack_14;

  uint8_t *puStack_10;

  uint32_t /* width from decompiler */ uStack_c;

  

  uStack_c = 0xffffffff;

  puStack_10 = &LAB_009b1058;

  pvStack_14 = ExceptionList;

  ExceptionList = &pvStack_14;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x50c) = 0;

  FUN_008eba20();

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x540) = 0xffffffff;

  if (*(int **)(param_1 + 0x59c) != (int *)0x0) {

    (**(code **)(**(int **)(param_1 + 0x59c) + 0x1d8))("Central Wastelands",1,1);

    (**(code **)(**(int **)(param_1 + 0x59c) + 0x34c))();

  }

  if (*(int **)(param_1 + 0x574) != (int *)0x0) {

    pcVar2 = (char *)(**(code **)(**(int **)(param_1 + 0x574) + 0x2b8))();

    pcVar5 = (char *)&uStack_118;

    do {

      cVar1 = *pcVar2;

      *pcVar5 = cVar1;

      pcVar2 = pcVar2 + 1;

      pcVar5 = pcVar5 + 1;

    } while (cVar1 != '\0');

    (**(code **)(**(int **)(param_1 + 0x574) + 0x50))("i_d_cont_2d_wnd_continent-map.dds",1,0);

    *(uint8_t *)(*(int *)(param_1 + 0x574) + 0xd7) = 1;

    (**(code **)(**(int **)(param_1 + 0x574) + 0x34c))();

    FUN_007b6a20();

    FUN_00989e00(auStack_164,&uStack_118);

    FUN_0075e2d0(auStack_164);

  }

  if ((*(int **)(param_1 + 0x67c) != (int *)0x0) &&

     (iVar3 = (**(code **)(**(int **)(param_1 + 0x67c) + 700))(), iVar3 != 0)) {

    uStack_118 = 0;

    puVar6 = auStack_116;

    for (iVar3 = 0x3f; iVar3 != 0; iVar3 = iVar3 + -1) {

      *puVar6 = 0;

      puVar6 = puVar6 + 1;

    }

    piVar4 = *(int **)(param_1 + 0x67c);

    *(uint16_t *)puVar6 = 0;

    iVar3 = (**(code **)(*piVar4 + 0x2b8))();

    if (iVar3 != 0) {

      pcVar2 = (char *)(**(code **)(**(int **)(param_1 + 0x67c) + 0x2b8))();

      pcVar5 = (char *)&uStack_118;

      do {

        cVar1 = *pcVar2;

        *pcVar5 = cVar1;

        pcVar2 = pcVar2 + 1;

        pcVar5 = pcVar5 + 1;

      } while (cVar1 != '\0');

    }

    (**(code **)(**(int **)(param_1 + 0x67c) + 0x58))();

    (**(code **)(**(int **)(param_1 + 0x67c) + 4))(0);

    if ((char)uStack_118 != '\0') {

      puVar7 = &uStack_118;

      FUN_007b6a20(puVar7);

      FUN_007b70b0(puVar7);

    }

  }

  ppuStack_160 = &PTR_FUN_00a39350;

  uStack_15c = 0;

  uStack_158 = 0;

  uStack_154 = 0;

  uStack_120 = 0xffffffff;

  InitializeCriticalSection(&_Stack_150);

  InitializeCriticalSection(&_Stack_138);

  uStack_c = 0;

  param_1 = param_1 + 0x5b0;

  piVar4 = (int *)FUN_0040e490(param_1);

  while (piVar4 != (int *)0x0) {

    (**(code **)(*piVar4 + 4))(1);

    FUN_0040e230(&ppuStack_160);

    piVar4 = (int *)FUN_0040e490(param_1);

  }

  iVar3 = FUN_0040e490(&ppuStack_160);

  while (iVar3 != 0) {

    FUN_0040e230(param_1);

    iVar3 = FUN_0040e490(&ppuStack_160);

  }

  FUN_008ec980();

  uStack_c = 0xffffffff;

  FUN_0040e1e0();

  ExceptionList = pvStack_14;

  return;

}
