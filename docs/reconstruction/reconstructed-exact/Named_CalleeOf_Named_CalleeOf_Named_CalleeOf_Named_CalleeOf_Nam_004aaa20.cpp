// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_004aaa20
// -----------------------------------------------------------------------------
// Stable ID: aa_004aaa20
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_Server_needs
// Address:   0x004aaa20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_Server_needs: callee helper. Evidence string: "Could not locate the following map: %s". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - ".fam"
//   - "Could not locate the following map: %s"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~115 non-empty decompiler lines.
//  - Control keywords: if×6, do×6, while×6, for×3, return×2.
//  - Notable callees: strrchr×7, FUN_007b6a20×2, FUN_004a94e0, FUN_004aa200, FUN_004aaa20, FUN_007a4480, FUN_007b70b0, FUN_007b72b0.
//  - Strings: ".fam"; "Could not locate the following map: %s".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_Server_needs
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

uint32_t /* width from decompiler */ Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_004aaa20(char *param_1)



{

  char cVar1;

  char *pcVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int iVar4;

  uint uVar5;

  char *pcVar6;

  char *pcVar7;

  char *pcVar8;

  uint32_t /* width from decompiler */ *puVar9;

  uint8_t *puVar10;

  uint8_t local_21c [4];

  char local_218 [2];

  uint32_t /* width from decompiler */ uStack_216;

  CHAR local_110 [268];

  

  local_218[0] = '\0';

  local_218[1] = '\0';

  puVar3 = &uStack_216;

  for (iVar4 = 0x40; iVar4 != 0; iVar4 = iVar4 + -1) {

    *puVar3 = 0;

    puVar3 = puVar3 + 1;

  }

  *(uint16_t *)puVar3 = 0;

  pcVar2 = strrchr(param_1,0x5c);

  if ((pcVar2 == (char *)0x0) && (pcVar2 = strrchr(param_1,0x2f), pcVar2 == (char *)0x0)) {

    pcVar7 = (char *)((int)local_21c + 0x1e);

    strncpy(pcVar7,param_1,0x104);

    *(uint8_t *)((int)local_21c + 0x122) = 0;

    pcVar2 = pcVar7;

    do {

      cVar1 = *pcVar2;

      pcVar2 = pcVar2 + 1;

    } while (cVar1 != '\0');

    pcVar8 = local_21c + 3;

    do {

      pcVar6 = pcVar8 + 1;

      pcVar8 = pcVar8 + 1;

    } while (*pcVar6 != '\0');

    pcVar6 = pcVar7;

    for (uVar5 = (uint)((int)pcVar2 - (int)pcVar7) >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {

      *(uint32_t /* width from decompiler */ *)pcVar8 = *(uint32_t /* width from decompiler */ *)pcVar6;

      pcVar6 = pcVar6 + 4;

      pcVar8 = pcVar8 + 4;

    }

    for (uVar5 = (int)pcVar2 - (int)pcVar7 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {

      *pcVar8 = *pcVar6;

      pcVar6 = pcVar6 + 1;

      pcVar8 = pcVar8 + 1;

    }

  }

  else {

    iVar4 = -(int)param_1;

    do {

      cVar1 = *param_1;

      param_1[(int)(local_218 + iVar4)] = cVar1;

      param_1 = param_1 + 1;

    } while (cVar1 != '\0');

    pcVar2 = strrchr(local_218,0x5c);

    if (pcVar2 == (char *)0x0) {

      pcVar2 = strrchr(local_218,0x2f);

      pcVar7 = (char *)((int)local_21c + 0x1e);

      do {

        cVar1 = *pcVar2;

        *pcVar7 = cVar1;

        pcVar2 = pcVar2 + 1;

        pcVar7 = pcVar7 + 1;

      } while (cVar1 != '\0');

    }

  }

  _strlwr((char *)((int)local_21c + 0x1e));

  pcVar2 = strstr(local_218,".fam");

  if (pcVar2 == (char *)0x0) {

    puVar3 = (uint32_t /* width from decompiler */ *)(local_21c + 3);

    do {

      puVar9 = puVar3;

      puVar3 = (uint32_t /* width from decompiler */ *)((int)puVar9 + 1);

    } while (*(char *)((int)puVar9 + 1) != '\0');

    *(uint32_t /* width from decompiler */ *)((int)puVar9 + 1) = DAT_00a285c4;

    *(uint8_t *)((int)puVar9 + 5) = DAT_00a285c8;

  }

  GetCurrentDirectoryA(0x104,local_110);

  pcVar2 = local_218;

  FUN_007b6a20(pcVar2);

  puVar3 = (uint32_t /* width from decompiler */ *)FUN_007b72b0(pcVar2);

  if (puVar3 != (uint32_t /* width from decompiler */ *)0x0) {

    FUN_004a94e0(puVar3);

    (**(code **)*puVar3)(1);

    pcVar2 = strrchr(local_21c,0x2e);

    if (pcVar2 != (char *)0x0) {

      *pcVar2 = '\0';

    }

    puVar3 = (uint32_t /* width from decompiler */ *)&stack0xfffffde3;

    do {

      puVar9 = puVar3;

      puVar3 = (uint32_t /* width from decompiler */ *)((int)puVar9 + 1);

    } while (*(char *)((int)puVar9 + 1) != '\0');

    *(uint32_t /* width from decompiler */ *)((int)puVar9 + 1) = DAT_00a395dc;

    *(uint8_t *)((int)puVar9 + 5) = DAT_00a395e0;

    pcVar2 = strrchr(local_21c,0x5c);

    if ((pcVar2 == (char *)0x0) && (pcVar2 = strrchr(local_21c,0x2f), pcVar2 == (char *)0x0)) {

      pcVar2 = local_21c;

    }

    else {

      pcVar2 = pcVar2 + 1;

    }

    FUN_004aa200(pcVar2);

    puVar10 = local_21c;

    FUN_007b6a20(puVar10);

    FUN_007b70b0(puVar10);

    return 1;

  }

  FUN_007a4480(1,"Could not locate the following map: %s",local_218);

  return 0;

}
