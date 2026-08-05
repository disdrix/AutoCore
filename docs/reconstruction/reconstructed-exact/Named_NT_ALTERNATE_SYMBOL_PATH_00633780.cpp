// =============================================================================
// Named_NT_ALTERNATE_SYMBOL_PATH_00633780
// -----------------------------------------------------------------------------
// Stable ID: aa_00633780
// Address:   0x00633780  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_NT_ALTERNATE_SYMBOL_PATH_00633780 @ 0x00633780
// Stable ID: aa_00633780
// Embedded strings (evidence for future rename):
//   - "_NT_SYMBOL_PATH"
//   - "_NT_ALTERNATE_SYMBOL_PATH"
//   - "SYSTEMROOT"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~172 non-empty decompiler lines.
//  - Control keywords: do×16, while×16, for×10, if×4, return×1.
//  - Notable callees: GetEnvironmentVariableA×3, FUN_00633780.
//  - Strings: "_NT_SYMBOL_PATH"; "_NT_ALTERNATE_SYMBOL_PATH"; "SYSTEMROOT".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * String-driven rename evidence: "_NT_ALTERNATE_SYMBOL_PATH"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_NT_ALTERNATE_SYMBOL_PATH_00633780(uint16_t *param_1,char *param_2)



{

  char cVar1;

  DWORD DVar2;

  char *pcVar3;

  uint uVar4;

  uint uVar5;

  char *pcVar6;

  char *pcVar7;

  uint16_t *puVar8;

  CHAR local_200 [512];

  

  *param_1 = 0x2e;

  DVar2 = GetEnvironmentVariableA("_NT_SYMBOL_PATH",local_200,0x200);

  if (DVar2 != 0) {

    puVar8 = (uint16_t *)((int)param_1 + -1);

    do {

      pcVar3 = (char *)((int)puVar8 + 1);

      puVar8 = (uint16_t *)((int)puVar8 + 1);

    } while (*pcVar3 != '\0');

    *puVar8 = DAT_00a46e78;

    pcVar3 = local_200;

    do {

      cVar1 = *pcVar3;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

    uVar4 = (int)pcVar3 - (int)local_200;

    pcVar3 = (char *)((int)param_1 + -1);

    do {

      pcVar6 = pcVar3 + 1;

      pcVar3 = pcVar3 + 1;

    } while (*pcVar6 != '\0');

    pcVar6 = local_200;

    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {

      *(uint32_t /* width from decompiler */ *)pcVar3 = *(uint32_t /* width from decompiler */ *)pcVar6;

      pcVar6 = pcVar6 + 4;

      pcVar3 = pcVar3 + 4;

    }

    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {

      *pcVar3 = *pcVar6;

      pcVar6 = pcVar6 + 1;

      pcVar3 = pcVar3 + 1;

    }

  }

  DVar2 = GetEnvironmentVariableA("_NT_ALTERNATE_SYMBOL_PATH",local_200,0x200);

  if (DVar2 != 0) {

    puVar8 = (uint16_t *)((int)param_1 + -1);

    do {

      pcVar3 = (char *)((int)puVar8 + 1);

      puVar8 = (uint16_t *)((int)puVar8 + 1);

    } while (*pcVar3 != '\0');

    *puVar8 = DAT_00a46e78;

    pcVar3 = local_200;

    do {

      cVar1 = *pcVar3;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

    uVar4 = (int)pcVar3 - (int)local_200;

    pcVar3 = (char *)((int)param_1 + -1);

    do {

      pcVar6 = pcVar3 + 1;

      pcVar3 = pcVar3 + 1;

    } while (*pcVar6 != '\0');

    pcVar6 = local_200;

    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {

      *(uint32_t /* width from decompiler */ *)pcVar3 = *(uint32_t /* width from decompiler */ *)pcVar6;

      pcVar6 = pcVar6 + 4;

      pcVar3 = pcVar3 + 4;

    }

    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {

      *pcVar3 = *pcVar6;

      pcVar6 = pcVar6 + 1;

      pcVar3 = pcVar3 + 1;

    }

  }

  DVar2 = GetEnvironmentVariableA("SYSTEMROOT",local_200,0x200);

  if (DVar2 != 0) {

    puVar8 = (uint16_t *)((int)param_1 + -1);

    do {

      pcVar3 = (char *)((int)puVar8 + 1);

      puVar8 = (uint16_t *)((int)puVar8 + 1);

    } while (*pcVar3 != '\0');

    *puVar8 = DAT_00a46e78;

    pcVar3 = local_200;

    do {

      cVar1 = *pcVar3;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

    uVar4 = (int)pcVar3 - (int)local_200;

    pcVar3 = (char *)((int)param_1 + -1);

    do {

      pcVar6 = pcVar3 + 1;

      pcVar3 = pcVar3 + 1;

    } while (*pcVar6 != '\0');

    pcVar6 = local_200;

    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {

      *(uint32_t /* width from decompiler */ *)pcVar3 = *(uint32_t /* width from decompiler */ *)pcVar6;

      pcVar6 = pcVar6 + 4;

      pcVar3 = pcVar3 + 4;

    }

    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {

      *pcVar3 = *pcVar6;

      pcVar6 = pcVar6 + 1;

      pcVar3 = pcVar3 + 1;

    }

    puVar8 = (uint16_t *)((int)param_1 + -1);

    do {

      pcVar3 = (char *)((int)puVar8 + 1);

      puVar8 = (uint16_t *)((int)puVar8 + 1);

    } while (*pcVar3 != '\0');

    *puVar8 = DAT_00a46e78;

    pcVar3 = local_200;

    do {

      cVar1 = *pcVar3;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

    uVar4 = (int)pcVar3 - (int)local_200;

    pcVar3 = (char *)((int)param_1 + -1);

    do {

      pcVar6 = pcVar3 + 1;

      pcVar3 = pcVar3 + 1;

    } while (*pcVar6 != '\0');

    pcVar6 = local_200;

    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {

      *(uint32_t /* width from decompiler */ *)pcVar3 = *(uint32_t /* width from decompiler */ *)pcVar6;

      pcVar6 = pcVar6 + 4;

      pcVar3 = pcVar3 + 4;

    }

    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {

      *pcVar3 = *pcVar6;

      pcVar6 = pcVar6 + 1;

      pcVar3 = pcVar3 + 1;

    }

    pcVar3 = (char *)((int)param_1 + -1);

    do {

      pcVar6 = pcVar3;

      pcVar3 = pcVar6 + 1;

    } while (pcVar6[1] != '\0');

    *(uint32_t /* width from decompiler */ *)(pcVar6 + 1) = s__System32_009e35d0._0_4_;

    *(uint32_t /* width from decompiler */ *)(pcVar6 + 5) = s__System32_009e35d0._4_4_;

    *(uint16_t *)(pcVar6 + 9) = s__System32_009e35d0._8_2_;

  }

  if ((param_2 != (char *)0x0) && (*param_2 != '\0')) {

    puVar8 = (uint16_t *)((int)param_1 + -1);

    do {

      pcVar3 = (char *)((int)puVar8 + 1);

      puVar8 = (uint16_t *)((int)puVar8 + 1);

    } while (*pcVar3 != '\0');

    *puVar8 = DAT_00a46e78;

    pcVar3 = param_2;

    do {

      cVar1 = *pcVar3;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

    pcVar6 = (char *)((int)param_1 + -1);

    do {

      pcVar7 = pcVar6 + 1;

      pcVar6 = pcVar6 + 1;

    } while (*pcVar7 != '\0');

    pcVar7 = param_2;

    for (uVar4 = (uint)((int)pcVar3 - (int)param_2) >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {

      *(uint32_t /* width from decompiler */ *)pcVar6 = *(uint32_t /* width from decompiler */ *)pcVar7;

      pcVar7 = pcVar7 + 4;

      pcVar6 = pcVar6 + 4;

    }

    for (uVar4 = (int)pcVar3 - (int)param_2 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {

      *pcVar6 = *pcVar7;

      pcVar7 = pcVar7 + 1;

      pcVar6 = pcVar6 + 1;

    }

  }

  return;

}
