// =============================================================================
// FUN_0059fcb0
// -----------------------------------------------------------------------------
// Stable ID: aa_0059fcb0
// Address:   0x0059fcb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0059fcb0 @ 0x0059fcb0
// Stable ID: aa_0059fcb0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~80 non-empty decompiler lines.
//  - Control keywords: if×8, return×1.
//  - Notable callees: FUN_00419190, FUN_0042b250, FUN_0059fcb0, FUN_00780980, FUN_00780a30, FUN_00781530, free, malloc.
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

void __fastcall FUN_0059fcb0(int param_1)



{

  int *piVar1;

  int *piVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ *puVar6;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a5fbc;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  if (*(char *)(*(int *)(param_1 + 0x1a8) + 0xa4) == '\0') {

    if ((*(byte *)(param_1 + 0xb4) & 1) == 0) {

      ExceptionList = &pvStack_c;

      FUN_00780980(1);

      FUN_00781530();

    }

    else {

      ExceptionList = &pvStack_c;

      FUN_00780a30(1);

    }

  }

  puVar4 = malloc(0x98);

  *puVar4 = 0x5000;

  *(uint8_t *)(puVar4 + 1) = 2;

  puVar4[2] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x250);

  puVar4[4] = *(uint32_t /* width from decompiler */ *)(param_1 + 600);

  puVar4[5] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x25c);

  puVar5 = operator_new(0x18);

  if (puVar5 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar5 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    puVar5[2] = 0;

  }

  puVar5[1] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x238);

  *puVar5 = 0;

  puVar6 = operator_new(0x18);

  local_4 = 0;

  if (puVar6 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar6 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    FUN_0042b250();

    *puVar6 = &PTR_LAB_009d7b00;

    puVar6[4] = 0;

    puVar6[3] = 0;

    *(uint8_t *)(puVar6 + 5) = 0;

  }

  piVar2 = (int *)puVar5[2];

  local_4 = 0xffffffff;

  if (piVar2 != (int *)0x0) {

    piVar1 = piVar2 + 2;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*piVar2 + 8))();

    }

  }

  puVar5[2] = puVar6;

  if (puVar6 != (uint32_t /* width from decompiler */ *)0x0) {

    puVar6[2] = puVar6[2] + 1;

  }

  iVar3 = puVar5[2];

  if (*(char *)(iVar3 + 0x14) != '\0') {

    *(uint8_t *)(iVar3 + 0x14) = 0;

    free(*(void **)(iVar3 + 0xc));

  }

  *(uint32_t /* width from decompiler */ **)(iVar3 + 0xc) = puVar4;

  *(uint8_t *)(iVar3 + 0x14) = 1;

  *(uint32_t /* width from decompiler */ *)(iVar3 + 0x10) = 0x98;

  puVar5[3] = *(uint32_t /* width from decompiler */ *)(puVar5[2] + 0xc);

  puVar5[4] = 0x98;

  FUN_00419190(puVar5);

  ExceptionList = pvStack_c;

  return;

}
