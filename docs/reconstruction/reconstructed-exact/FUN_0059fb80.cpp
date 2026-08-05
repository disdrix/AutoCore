// =============================================================================
// FUN_0059fb80
// -----------------------------------------------------------------------------
// Stable ID: aa_0059fb80
// Address:   0x0059fb80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0059fb80 @ 0x0059fb80
// Stable ID: aa_0059fb80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~75 non-empty decompiler lines.
//  - Control keywords: if×6, do×1, while×1, return×1.
//  - Notable callees: FUN_00419190, FUN_0042b250, FUN_0059fb80, free, malloc.
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

void __thiscall FUN_0059fb80(int param_1,uint32_t /* width from decompiler */ param_2,char *param_3)



{

  int *piVar1;

  char cVar2;

  int *piVar3;

  int iVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint32_t /* width from decompiler */ *puVar6;

  uint32_t /* width from decompiler */ *puVar7;

  uint32_t /* width from decompiler */ *puVar8;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a5fa7;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  puVar6 = malloc(0x98);

  *puVar6 = 0x5000;

  *(uint8_t *)(puVar6 + 1) = 0;

  iVar4 = 0x18 - (int)param_3;

  do {

    cVar2 = *param_3;

    param_3[(int)puVar6 + iVar4] = cVar2;

    param_3 = param_3 + 1;

  } while (cVar2 != '\0');

  puVar7 = operator_new(0x18);

  if (puVar7 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar7 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    puVar7[2] = 0;

  }

  puVar7[1] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x238);

  *puVar7 = 0;

  puVar8 = operator_new(0x18);

  local_4 = 0;

  if (puVar8 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar8 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    FUN_0042b250();

    *puVar8 = &PTR_LAB_009d7b00;

    puVar8[4] = 0;

    puVar8[3] = 0;

    *(uint8_t *)(puVar8 + 5) = 0;

  }

  piVar3 = (int *)puVar7[2];

  local_4 = 0xffffffff;

  if (piVar3 != (int *)0x0) {

    piVar1 = piVar3 + 2;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*piVar3 + 8))();

    }

  }

  puVar7[2] = puVar8;

  if (puVar8 != (uint32_t /* width from decompiler */ *)0x0) {

    puVar8[2] = puVar8[2] + 1;

  }

  iVar4 = puVar7[2];

  if (*(char *)(iVar4 + 0x14) != '\0') {

    *(uint8_t *)(iVar4 + 0x14) = 0;

    free(*(void **)(iVar4 + 0xc));

  }

  *(uint32_t /* width from decompiler */ **)(iVar4 + 0xc) = puVar6;

  *(uint8_t *)(iVar4 + 0x14) = 1;

  *(uint32_t /* width from decompiler */ *)(iVar4 + 0x10) = 0x98;

  uVar5 = *(uint32_t /* width from decompiler */ *)(puVar7[2] + 0xc);

  puVar7[4] = 0x98;

  puVar7[3] = uVar5;

  FUN_00419190(puVar7);

  ExceptionList = pvStack_c;

  return;

}
