// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_assPackManager_0076aba0
// -----------------------------------------------------------------------------
// Stable ID: aa_0076aba0
// Callee of Named_CalleeOf_Named_assPackManager (+1 other named callers)
// Address:   0x0076aba0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_assPackManager: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_CalleeOf_Named_assPackManager (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~135 non-empty decompiler lines.
//  - Control keywords: do×11, while×11, if×9, for×8, return×1.
//  - Notable callees: FUN_0076aba0, strchr.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_assPackManager (+1 other named callers)
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_assPackManager_0076aba0(char *param_1,uint8_t *param_2,char *param_3,char *param_4)



{

  char cVar1;

  bool bVar2;

  char *in_EAX;

  char *pcVar3;

  uint uVar4;

  uint uVar5;

  char *pcVar6;

  uint16_t *puVar7;

  

  *param_2 = 0;

  pcVar3 = in_EAX;

  if (in_EAX != (char *)0x0) {

    do {

      cVar1 = *pcVar3;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

    uVar4 = (int)pcVar3 - (int)in_EAX;

    pcVar3 = param_2 + -1;

    do {

      pcVar6 = pcVar3 + 1;

      pcVar3 = pcVar3 + 1;

    } while (*pcVar6 != '\0');

    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {

      *(uint32_t /* width from decompiler */ *)pcVar3 = *(uint32_t /* width from decompiler */ *)in_EAX;

      in_EAX = in_EAX + 4;

      pcVar3 = pcVar3 + 4;

    }

    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {

      *pcVar3 = *in_EAX;

      in_EAX = in_EAX + 1;

      pcVar3 = pcVar3 + 1;

    }

  }

  bVar2 = false;

  pcVar3 = param_1;

  if (param_1 != (char *)0x0) {

    do {

      cVar1 = *pcVar3;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

    uVar4 = (int)pcVar3 - (int)param_1;

    pcVar3 = param_2 + -1;

    do {

      pcVar6 = pcVar3 + 1;

      pcVar3 = pcVar3 + 1;

    } while (*pcVar6 != '\0');

    pcVar6 = param_1;

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

    if (*param_1 != '\0') {

      do {

        pcVar3 = param_1;

        param_1 = pcVar3 + 1;

      } while (*pcVar3 != '\0');

      pcVar3 = strchr("/\\",(int)pcVar3[-1]);

      if (pcVar3 == (char *)0x0) {

        bVar2 = true;

      }

    }

  }

  if ((param_3 != (char *)0x0) || (param_4 != (char *)0x0)) {

    if (bVar2) {

      puVar7 = (uint16_t *)(param_2 + -1);

      do {

        pcVar3 = (char *)((int)puVar7 + 1);

        puVar7 = (uint16_t *)((int)puVar7 + 1);

      } while (*pcVar3 != '\0');

      *puVar7 = DAT_00a2eb5c;

    }

    pcVar3 = param_3;

    if (param_3 != (char *)0x0) {

      do {

        cVar1 = *pcVar3;

        pcVar3 = pcVar3 + 1;

      } while (cVar1 != '\0');

      uVar4 = (int)pcVar3 - (int)param_3;

      pcVar3 = param_2 + -1;

      do {

        pcVar6 = pcVar3 + 1;

        pcVar3 = pcVar3 + 1;

      } while (*pcVar6 != '\0');

      for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {

        *(uint32_t /* width from decompiler */ *)pcVar3 = *(uint32_t /* width from decompiler */ *)param_3;

        param_3 = param_3 + 4;

        pcVar3 = pcVar3 + 4;

      }

      for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {

        *pcVar3 = *param_3;

        param_3 = param_3 + 1;

        pcVar3 = pcVar3 + 1;

      }

    }

    if (param_4 != (char *)0x0) {

      pcVar3 = param_4;

      if (*param_4 != '.') {

        puVar7 = (uint16_t *)(param_2 + -1);

        do {

          pcVar6 = (char *)((int)puVar7 + 1);

          puVar7 = (uint16_t *)((int)puVar7 + 1);

        } while (*pcVar6 != '\0');

        *puVar7 = DAT_00a2e610;

      }

      do {

        cVar1 = *pcVar3;

        pcVar3 = pcVar3 + 1;

      } while (cVar1 != '\0');

      uVar4 = (int)pcVar3 - (int)param_4;

      pcVar3 = param_2 + -1;

      do {

        pcVar6 = pcVar3 + 1;

        pcVar3 = pcVar3 + 1;

      } while (*pcVar6 != '\0');

      for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {

        *(uint32_t /* width from decompiler */ *)pcVar3 = *(uint32_t /* width from decompiler */ *)param_4;

        param_4 = param_4 + 4;

        pcVar3 = pcVar3 + 4;

      }

      for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {

        *pcVar3 = *param_4;

        param_4 = param_4 + 1;

        pcVar3 = pcVar3 + 1;

      }

    }

  }

  return;

}
