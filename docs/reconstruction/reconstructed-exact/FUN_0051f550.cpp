// =============================================================================
// FUN_0051f550
// -----------------------------------------------------------------------------
// Stable ID: aa_0051f550
// Address:   0x0051f550  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0051f550 @ 0x0051f550
// Stable ID: aa_0051f550
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~82 non-empty decompiler lines.
//  - Control keywords: do×7, while×7, return×4, if×3, switch×1.
//  - Notable callees: FUN_0051f550.
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

uint16_t * FUN_0051f550(int param_1,uint32_t /* width from decompiler */ param_2)



{

  uint8_t uVar1;

  uint8_t uVar2;

  uint8_t uVar3;

  uint8_t uVar4;

  uint16_t *puVar5;

  uint16_t *puVar6;

  

  uVar3 = DAT_009ceefa;

  uVar2 = DAT_009ceef6;

  uVar1 = DAT_009ceef2;

  DAT_00b04600._0_1_ = 0;

  if (param_1 == 0) {

    puVar5 = (uint16_t *)((int)&DAT_00b045fc + 3);

    do {

      puVar6 = puVar5;

      puVar5 = (uint16_t *)((int)puVar6 + 1);

    } while (*(char *)((int)puVar6 + 1) != '\0');

    *(uint16_t *)((int)puVar6 + 1) = DAT_009ceef0;

    *(uint8_t *)((int)puVar6 + 3) = uVar1;

  }

  else if (param_1 == 1) {

    puVar5 = (uint16_t *)((int)&DAT_00b045fc + 3);

    do {

      puVar6 = puVar5;

      puVar5 = (uint16_t *)((int)puVar6 + 1);

    } while (*(char *)((int)puVar6 + 1) != '\0');

    *(uint16_t *)((int)puVar6 + 1) = DAT_009ceef4;

    *(uint8_t *)((int)puVar6 + 3) = uVar2;

  }

  else if (param_1 == 2) {

    puVar5 = (uint16_t *)((int)&DAT_00b045fc + 3);

    do {

      puVar6 = puVar5;

      puVar5 = (uint16_t *)((int)puVar6 + 1);

    } while (*(char *)((int)puVar6 + 1) != '\0');

    *(uint16_t *)((int)puVar6 + 1) = DAT_009ceef8;

    *(uint8_t *)((int)puVar6 + 3) = uVar3;

  }

  uVar4 = DAT_009ceeee;

  uVar3 = DAT_009ceeea;

  uVar2 = DAT_009ceee6;

  uVar1 = DAT_009ceee2;

  switch(param_2) {

  case 0:

    puVar5 = (uint16_t *)((int)&DAT_00b045fc + 3);

    do {

      puVar6 = puVar5;

      puVar5 = (uint16_t *)((int)puVar6 + 1);

    } while (*(char *)((int)puVar6 + 1) != '\0');

    *(uint16_t *)((int)puVar6 + 1) = DAT_009ceeec;

    *(uint8_t *)((int)puVar6 + 3) = uVar4;

    return &DAT_00b04600;

  case 1:

    puVar5 = (uint16_t *)((int)&DAT_00b045fc + 3);

    do {

      puVar6 = puVar5;

      puVar5 = (uint16_t *)((int)puVar6 + 1);

    } while (*(char *)((int)puVar6 + 1) != '\0');

    *(uint16_t *)((int)puVar6 + 1) = DAT_009ceee8;

    *(uint8_t *)((int)puVar6 + 3) = uVar3;

    return &DAT_00b04600;

  case 2:

    puVar5 = (uint16_t *)((int)&DAT_00b045fc + 3);

    do {

      puVar6 = puVar5;

      puVar5 = (uint16_t *)((int)puVar6 + 1);

    } while (*(char *)((int)puVar6 + 1) != '\0');

    *(uint16_t *)((int)puVar6 + 1) = DAT_009ceee4;

    *(uint8_t *)((int)puVar6 + 3) = uVar2;

    return &DAT_00b04600;

  case 3:

    puVar5 = (uint16_t *)((int)&DAT_00b045fc + 3);

    do {

      puVar6 = puVar5;

      puVar5 = (uint16_t *)((int)puVar6 + 1);

    } while (*(char *)((int)puVar6 + 1) != '\0');

    *(uint16_t *)((int)puVar6 + 1) = DAT_009ceee0;

    *(uint8_t *)((int)puVar6 + 3) = uVar1;

  }

  return &DAT_00b04600;

}
