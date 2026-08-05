// =============================================================================
// Named_CalleeOf_Named_anmAnimMaster_009637d0
// -----------------------------------------------------------------------------
// Stable ID: aa_009637d0
// Callee of Named_anmAnimMaster
// Address:   0x009637d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_anmAnimMaster: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~43 non-empty decompiler lines.
//  - Control keywords: if×5, return×3, do×1, while×1.
//  - Notable callees: CONCAT31, FUN_009637d0.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_anmAnimMaster
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

uint Named_CalleeOf_Named_anmAnimMaster_009637d0(uint param_1,uint param_2)



{

  int iVar1;

  int *piVar2;

  int iVar3;

  uint uVar4;

  uint *puVar5;

  uint *puVar6;

  uint uVar7;

  

  iVar3 = param_1;

  uVar4 = 0;

  if (*(int *)(param_1 + 0xc) == 0) {

    param_1 = 0;

  }

  else {

    param_1 = *(int *)(param_1 + 0x10) - *(int *)(param_1 + 0xc) >> 2;

  }

  uVar7 = 0;

  if (param_1 != 0) {

    do {

      if (param_2 != uVar7) {

        iVar1 = *(int *)(iVar3 + 0xc);

        piVar2 = *(int **)(iVar1 + param_2 * 4);

        puVar5 = (uint *)(**(code **)(**(int **)(iVar1 + uVar7 * 4) + 8))();

        puVar6 = (uint *)(**(code **)(*piVar2 + 8))();

        uVar4 = *puVar6;

        if (uVar4 == *puVar5) {

          iVar1 = *(int *)(iVar3 + 0xc);

          piVar2 = *(int **)(iVar1 + param_2 * 4);

          puVar5 = (uint *)(**(code **)(**(int **)(iVar1 + uVar7 * 4) + 0xc))();

          puVar6 = (uint *)(**(code **)(*piVar2 + 0xc))();

          uVar4 = *puVar6;

          if (uVar4 == *puVar5) {

            return CONCAT31((int3)(uVar4 >> 8),1);

          }

        }

      }

      uVar7 = uVar7 + 1;

    } while (uVar7 < param_1);

    return uVar4 & 0xffffff00;

  }

  return 0;

}
