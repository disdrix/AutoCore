// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_assManager_00744360
// -----------------------------------------------------------------------------
// Stable ID: aa_00744360
// Callee of Named_CalleeOf_Named_assManager
// Address:   0x00744360  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_assManager: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~55 non-empty decompiler lines.
//  - Control keywords: if×5, while×3, do×1, return×1, for×1, goto×1.
//  - Notable callees: FUN_00744360×2, FUN_00426f60, FUN_0043e3d0, FUN_0044d960.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_assManager
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

void Named_CalleeOf_Named_CalleeOf_Named_assManager_00744360(uint32_t /* width from decompiler */ param_1,int param_2)



{

  char cVar1;

  int *piVar2;

  int iVar3;

  int *piVar4;

  int iVar5;

  uint uVar6;

  int *local_14;

  int *local_10;

  

  FUN_00426f60();

  FUN_0044d960();

  do {

    if (local_14 == local_10) {

      return;

    }

    piVar2 = local_14 + 6;

    for (iVar5 = *(int *)(param_2 + 0x10) + *(int *)(param_2 + 0xc);

        iVar5 != *(int *)(param_2 + 0xc); iVar5 = iVar5 + -1) {

      uVar6 = iVar5 - 1U >> 2;

      iVar3 = uVar6 * -4;

      if (*(uint *)(param_2 + 8) <= uVar6) {

        uVar6 = uVar6 - *(uint *)(param_2 + 8);

      }

      if (*(int *)(*(int *)(*(int *)(param_2 + 4) + uVar6 * 4) + ((iVar5 - 1U) + iVar3) * 4) ==

          *piVar2) goto LAB_00744409;

    }

    Named_CalleeOf_Named_CalleeOf_Named_assManager_00744360(piVar2,param_2);

    FUN_0043e3d0(piVar2);

LAB_00744409:

    if (*(char *)((int)local_14 + 0x25) == '\0') {

      piVar2 = (int *)local_14[2];

      if (*(char *)((int)piVar2 + 0x25) == '\0') {

        cVar1 = *(char *)(*piVar2 + 0x25);

        local_14 = piVar2;

        piVar2 = (int *)*piVar2;

        while (cVar1 == '\0') {

          cVar1 = *(char *)(*piVar2 + 0x25);

          local_14 = piVar2;

          piVar2 = (int *)*piVar2;

        }

      }

      else {

        cVar1 = *(char *)(local_14[1] + 0x25);

        piVar4 = (int *)local_14[1];

        piVar2 = local_14;

        while ((local_14 = piVar4, cVar1 == '\0' && (piVar2 == (int *)local_14[2]))) {

          cVar1 = *(char *)(local_14[1] + 0x25);

          piVar4 = (int *)local_14[1];

          piVar2 = local_14;

        }

      }

    }

  } while( true );

}
