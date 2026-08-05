// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_00540090
// -----------------------------------------------------------------------------
// Stable ID: aa_00540090
// Callee of Named_VOG_DEBUG_STOP
// Address:   0x00540090  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~132 non-empty decompiler lines.
//  - Control keywords: do×11, while×11, if×3, for×2, goto×1, switch×1, return×1.
//  - Notable callees: FUN_00540090, strncpy.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_VOG_DEBUG_STOP
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

void Named_CalleeOf_Named_VOG_DEBUG_STOP_00540090(int param_1,char *param_2,size_t param_3)



{

  char *pcVar1;

  char cVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint8_t uVar5;

  char *pcVar6;

  uint uVar7;

  char *pcVar8;

  uint16_t *puVar9;

  uint16_t *puVar10;

  uint32_t /* width from decompiler */ *puVar11;

  char *pcVar12;

  uint32_t /* width from decompiler */ local_400;

  uint16_t local_3fc;

  uint8_t local_3fa [1018];

  

  local_400 = DAT_009d01bc;

  iVar3 = *(int *)(param_1 + 0x180);

  local_3fc = DAT_009d01c0;

  local_3fa[0] = DAT_009d01c2;

  if (iVar3 == 0) {

    puVar9 = (uint16_t *)&stack0xfffffbff;

    do {

      pcVar1 = (char *)((int)puVar9 + 1);

      puVar9 = (uint16_t *)((int)puVar9 + 1);

    } while (*pcVar1 != '\0');

    *puVar9 = DAT_009cf9f0;

    uVar5 = DAT_009cf9f2;

  }

  else {

    puVar9 = (uint16_t *)&stack0xfffffbff;

    if (iVar3 == 1) {

      do {

        pcVar1 = (char *)((int)puVar9 + 1);

        puVar9 = (uint16_t *)((int)puVar9 + 1);

      } while (*pcVar1 != '\0');

      *puVar9 = DAT_009cf9f4;

      uVar5 = DAT_009cf9f6;

    }

    else {

      if (iVar3 == 2) {

        do {

          puVar10 = puVar9;

          puVar9 = (uint16_t *)((int)puVar10 + 1);

        } while (*(char *)((int)puVar10 + 1) != '\0');

        *(uint16_t *)((int)puVar10 + 1) = DAT_009cf9ec;

        *(uint8_t *)((int)puVar10 + 3) = DAT_009cf9ee;

        goto LAB_0054014b;

      }

      do {

        pcVar1 = (char *)((int)puVar9 + 1);

        puVar9 = (uint16_t *)((int)puVar9 + 1);

      } while (*pcVar1 != '\0');

      *puVar9 = DAT_009d01b8;

      uVar5 = DAT_009d01ba;

    }

  }

  *(uint8_t *)(puVar9 + 1) = uVar5;

LAB_0054014b:

  switch(*(uint32_t /* width from decompiler */ *)(param_1 + 0x17c)) {

  case 0:

    puVar9 = (uint16_t *)&stack0xfffffbff;

    do {

      puVar10 = puVar9;

      puVar9 = (uint16_t *)((int)puVar10 + 1);

    } while (*(char *)((int)puVar10 + 1) != '\0');

    *(uint16_t *)((int)puVar10 + 1) = DAT_009cf9ec;

    *(uint8_t *)((int)puVar10 + 3) = DAT_009cf9ee;

    break;

  case 1:

    puVar9 = (uint16_t *)&stack0xfffffbff;

    do {

      puVar10 = puVar9;

      puVar9 = (uint16_t *)((int)puVar10 + 1);

    } while (*(char *)((int)puVar10 + 1) != '\0');

    *(uint16_t *)((int)puVar10 + 1) = DAT_009cf9e8;

    *(uint8_t *)((int)puVar10 + 3) = DAT_009cf9ea;

    break;

  case 2:

    puVar9 = (uint16_t *)&stack0xfffffbff;

    do {

      puVar10 = puVar9;

      puVar9 = (uint16_t *)((int)puVar10 + 1);

    } while (*(char *)((int)puVar10 + 1) != '\0');

    *(uint16_t *)((int)puVar10 + 1) = DAT_009cf9e4;

    *(uint8_t *)((int)puVar10 + 3) = DAT_009cf9e6;

    break;

  case 3:

    puVar9 = (uint16_t *)&stack0xfffffbff;

    do {

      puVar10 = puVar9;

      puVar9 = (uint16_t *)((int)puVar10 + 1);

    } while (*(char *)((int)puVar10 + 1) != '\0');

    *(uint16_t *)((int)puVar10 + 1) = DAT_009cf9e0;

    *(uint8_t *)((int)puVar10 + 3) = DAT_009cf9e2;

    break;

  default:

    puVar4 = (uint32_t /* width from decompiler */ *)&stack0xfffffbff;

    do {

      puVar11 = puVar4;

      puVar4 = (uint32_t /* width from decompiler */ *)((int)puVar11 + 1);

    } while (*(char *)((int)puVar11 + 1) != '\0');

    *(uint32_t /* width from decompiler */ *)((int)puVar11 + 1) = DAT_009d01b0;

    *(uint16_t *)((int)puVar11 + 5) = DAT_009d01b4;

    *(uint8_t *)((int)puVar11 + 7) = DAT_009d01b6;

  }

  pcVar1 = (char *)(param_1 + 0x5a6);

  pcVar6 = pcVar1;

  do {

    cVar2 = *pcVar6;

    pcVar6 = pcVar6 + 1;

  } while (cVar2 != '\0');

  pcVar12 = &stack0xfffffbff;

  do {

    pcVar8 = pcVar12 + 1;

    pcVar12 = pcVar12 + 1;

  } while (*pcVar8 != '\0');

  pcVar8 = pcVar1;

  for (uVar7 = (uint)((int)pcVar6 - (int)pcVar1) >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {

    *(uint32_t /* width from decompiler */ *)pcVar12 = *(uint32_t /* width from decompiler */ *)pcVar8;

    pcVar8 = pcVar8 + 4;

    pcVar12 = pcVar12 + 4;

  }

  for (uVar7 = (int)pcVar6 - (int)pcVar1 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {

    *pcVar12 = *pcVar8;

    pcVar8 = pcVar8 + 1;

    pcVar12 = pcVar12 + 1;

  }

  strncpy(param_2,(char *)&local_400,param_3);

  return;

}
