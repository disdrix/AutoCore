// =============================================================================
// FUN_0099ee90
// -----------------------------------------------------------------------------
// Stable ID: aa_0099ee90
// Address:   0x0099ee90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0099ee90 @ 0x0099ee90
// Stable ID: aa_0099ee90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~116 non-empty decompiler lines.
//  - Control keywords: if×13, return×1.
//  - Notable callees: FUN_0042b810×2, malloc×2, FUN_00424d10, FUN_0042be80, FUN_0099ee90.
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

void FUN_0099ee90(void)



{

  int *piVar1;

  int *piVar2;

  uint32_t /* width from decompiler */ *puVar3;

  void *pvVar4;

  int iVar5;

  uint uVar6;

  int unaff_EDI;

  undefined **local_138;

  uint32_t /* width from decompiler */ local_134;

  uint32_t /* width from decompiler */ local_130;

  uint32_t /* width from decompiler */ local_12c;

  int local_128;

  uint8_t local_124;

  uint local_120;

  char local_11c;

  uint8_t local_11b;

  int local_10c;

  int local_108;

  uint32_t /* width from decompiler */ local_104;

  uint8_t local_100;

  

  local_128 = *(int *)(unaff_EDI + 0x10);

  local_12c = *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0xc);

  local_10c = local_128 * 8;

  local_134 = 0;

  local_130 = 0;

  local_124 = 0;

  local_138 = &PTR_LAB_009d7b94;

  local_120 = 0;

  local_11c = '\0';

  local_11b = 0;

  local_100 = 0;

  local_104 = 0;

  local_108 = local_10c;

  puVar3 = operator_new(0x18);

  if (puVar3 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar3 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    puVar3[1] = 0;

    puVar3[2] = 0;

    *puVar3 = &PTR_LAB_009d7b00;

    puVar3[4] = 0;

    pvVar4 = malloc(0);

    puVar3[3] = pvVar4;

    *(uint8_t *)(puVar3 + 5) = 1;

  }

  piVar2 = *(int **)(unaff_EDI + 0x1c);

  if (piVar2 != (int *)0x0) {

    piVar1 = piVar2 + 2;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*piVar2 + 8))();

    }

  }

  *(uint32_t /* width from decompiler */ **)(unaff_EDI + 0x1c) = puVar3;

  if (puVar3 != (uint32_t /* width from decompiler */ *)0x0) {

    puVar3[2] = puVar3[2] + 1;

  }

  FUN_0042b810(&local_138);

  pvVar4 = operator_new(0x24);

  if (pvVar4 == (void *)0x0) {

    iVar5 = 0;

  }

  else {

    iVar5 = FUN_0042be80(&local_138);

  }

  piVar2 = *(int **)(unaff_EDI + 0x18);

  if (piVar2 != (int *)0x0) {

    piVar1 = piVar2 + 2;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*piVar2 + 8))();

    }

  }

  *(int *)(unaff_EDI + 0x18) = iVar5;

  if (iVar5 != 0) {

    *(int *)(iVar5 + 8) = *(int *)(iVar5 + 8) + 1;

  }

  puVar3 = operator_new(0x18);

  if (puVar3 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar3 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    puVar3[1] = 0;

    puVar3[2] = 0;

    *puVar3 = &PTR_LAB_009d7b00;

    puVar3[4] = 0;

    pvVar4 = malloc(0);

    puVar3[3] = pvVar4;

    *(uint8_t *)(puVar3 + 5) = 1;

  }

  piVar2 = *(int **)(unaff_EDI + 0x20);

  if (piVar2 != (int *)0x0) {

    piVar1 = piVar2 + 2;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*piVar2 + 8))();

    }

  }

  *(uint32_t /* width from decompiler */ **)(unaff_EDI + 0x20) = puVar3;

  if (puVar3 != (uint32_t /* width from decompiler */ *)0x0) {

    puVar3[2] = puVar3[2] + 1;

  }

  uVar6 = local_120 + 7;

  local_120 = uVar6 & 0xfffffff8;

  *(uint *)(unaff_EDI + 0x28) = uVar6 >> 3;

  FUN_0042b810(&local_138);

  if (((local_11c == '\0') && (*(uint *)(unaff_EDI + 0x10) == local_120 + 7 >> 3)) &&

     (*(char *)(*(int *)(unaff_EDI + 0x18) + 0x20) != '\0')) {

    *(uint8_t *)(unaff_EDI + 0x24) = 1;

  }

  FUN_00424d10();

  return;

}
