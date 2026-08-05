// =============================================================================
// Named_CalleeOf_Mission_after_CVOGRegionMissions_00541aa0
// -----------------------------------------------------------------------------
// Stable ID: aa_00541aa0
// Callee of Mission_after_CVOGRegionMissions
// Address:   0x00541aa0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Mission_after_CVOGRegionMissions: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~65 non-empty decompiler lines.
//  - Control keywords: if×5, while×4, do×2, return×1.
//  - Notable callees: FUN_004a1620, FUN_00541aa0, FUN_00545890, FUN_0054b480.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Mission_after_CVOGRegionMissions
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

void Named_CalleeOf_Mission_after_CVOGRegionMissions_00541aa0(void)



{

  char cVar1;

  int *piVar2;

  int iVar3;

  char *pcVar4;

  int *piVar5;

  int *piVar6;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a3ff9;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  iVar3 = FUN_0054b480();

  piVar6 = (int *)**(int **)(iVar3 + 4);

  if (piVar6 != *(int **)(iVar3 + 4)) {

    do {

      pcVar4 = (char *)((int)piVar6 + 0x5b6);

      do {

        cVar1 = *pcVar4;

        pcVar4 = pcVar4 + 1;

      } while (cVar1 != '\0');

      if (pcVar4 != (char *)((int)piVar6 + 0x5b7)) {

        piVar5 = operator_new(0xc);

        local_4 = 0;

        if (piVar5 == (int *)0x0) {

          piVar5 = (int *)0x0;

        }

        else {

          FUN_004a1620();

        }

        *piVar5 = piVar6[3];

        local_4 = 0xffffffff;

        FUN_00545890(piVar6[3],piVar5,0);

      }

      if (*(char *)((int)piVar6 + 0x641) == '\0') {

        piVar5 = (int *)piVar6[2];

        if (*(char *)((int)piVar5 + 0x641) == '\0') {

          cVar1 = *(char *)(*piVar5 + 0x641);

          piVar6 = piVar5;

          piVar5 = (int *)*piVar5;

          while (cVar1 == '\0') {

            cVar1 = *(char *)(*piVar5 + 0x641);

            piVar6 = piVar5;

            piVar5 = (int *)*piVar5;

          }

        }

        else {

          cVar1 = *(char *)(piVar6[1] + 0x641);

          piVar2 = (int *)piVar6[1];

          piVar5 = piVar6;

          while ((piVar6 = piVar2, cVar1 == '\0' && (piVar5 == (int *)piVar6[2]))) {

            cVar1 = *(char *)(piVar6[1] + 0x641);

            piVar2 = (int *)piVar6[1];

            piVar5 = piVar6;

          }

        }

      }

    } while (piVar6 != *(int **)(iVar3 + 4));

  }

  ExceptionList = local_c;

  return;

}
