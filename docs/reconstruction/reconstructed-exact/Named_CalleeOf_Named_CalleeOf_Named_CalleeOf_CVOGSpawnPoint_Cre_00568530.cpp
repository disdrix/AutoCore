// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGSpawnPoint_Cre_00568530
// -----------------------------------------------------------------------------
// Stable ID: aa_00568530
// Callee of Named_CalleeOf_Named_CalleeOf_CVOGSpawnPoint_CreateTemplateVehi
// Address:   0x00568530  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_CVOGSpawnPoint_CreateTemplateVehi: spawn/transfer helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~57 non-empty decompiler lines.
//  - Control keywords: if×6, return×4, while×3, do×1, for×1.
//  - Notable callees: FUN_00568530, FUN_00569030.
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_CVOGSpawnPoint_CreateTemplateVehi
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

uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGSpawnPoint_Cre_00568530(int *param_1,uint32_t /* width from decompiler */ param_2,int param_3,int *param_4)



{

  char cVar1;

  int *piVar2;

  int *piVar3;

  int iVar4;

  int *piVar5;

  int *local_4;

  

  local_4 = param_1;

  FUN_00569030(&local_4,&param_2);

  piVar5 = (int *)param_1[9];

  if (local_4 == piVar5) {

    return 0;

  }

  iVar4 = 0;

  if (0 < param_3) {

    do {

      if (*(char *)((int)local_4 + 0x49) == '\0') {

        piVar2 = (int *)local_4[2];

        if (*(char *)((int)piVar2 + 0x49) == '\0') {

          cVar1 = *(char *)(*piVar2 + 0x49);

          local_4 = piVar2;

          piVar2 = (int *)*piVar2;

          while (cVar1 == '\0') {

            cVar1 = *(char *)(*piVar2 + 0x49);

            local_4 = piVar2;

            piVar2 = (int *)*piVar2;

          }

        }

        else {

          cVar1 = *(char *)(local_4[1] + 0x49);

          piVar3 = (int *)local_4[1];

          piVar2 = local_4;

          while ((local_4 = piVar3, cVar1 == '\0' && (piVar2 == (int *)local_4[2]))) {

            cVar1 = *(char *)(local_4[1] + 0x49);

            piVar3 = (int *)local_4[1];

            piVar2 = local_4;

          }

        }

      }

      if (local_4 == piVar5) {

        return 0;

      }

      iVar4 = iVar4 + 1;

    } while (iVar4 < param_3);

  }

  if (local_4 == piVar5) {

    return 0;

  }

  piVar5 = local_4 + 4;

  for (iVar4 = 0xe; iVar4 != 0; iVar4 = iVar4 + -1) {

    *param_4 = *piVar5;

    piVar5 = piVar5 + 1;

    param_4 = param_4 + 1;

  }

  return 1;

}
