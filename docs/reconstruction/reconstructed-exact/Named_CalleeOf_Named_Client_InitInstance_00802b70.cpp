// =============================================================================
// Named_CalleeOf_Named_Client_InitInstance_00802b70
// -----------------------------------------------------------------------------
// Stable ID: aa_00802b70
// Callee of Named_Client_InitInstance
// Address:   0x00802b70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_Client_InitInstance: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~47 non-empty decompiler lines.
//  - Control keywords: if×10, return×4.
//  - Notable callees: FUN_00578270×3, FUN_007fc970, FUN_008027e0, FUN_00802b70, FUN_0083bf40, FUN_0087d810.
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Callee of Named_Client_InitInstance
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

void Named_CalleeOf_Named_Client_InitInstance_00802b70(int param_1)



{

  char cVar1;

  int iVar2;

  int iVar3;

  int *piVar4;

  

  if (param_1 != 0) {

    if ((DAT_00d1d8e0 != 0) && (*(int *)(DAT_00d1d8e0 + 0x514) == param_1)) {

      FUN_007fc970();

    }

    if ((DAT_00d1b6d8 != 0) && (*(int **)(param_1 + 0x18) != (int *)0x0)) {

      iVar2 = (**(code **)(**(int **)(param_1 + 0x18) + 0x1dc))();

      if ((iVar2 == DAT_00d1b6d8) ||

         (iVar2 = *(int *)(DAT_00d1b6d8 + 0x250),

         iVar3 = (**(code **)(**(int **)(param_1 + 0x18) + 0x1d4))(), iVar3 == iVar2)) {

        if ((DAT_00d1b8b8 != (int *)0x0) &&

           (cVar1 = (**(code **)(*DAT_00d1b8b8 + 0x3d8))(), cVar1 != '\0')) {

          FUN_0087d810(DAT_00d1b8b8);

        }

      }

      else {

        if (*(char *)(param_1 + 0xfe) == '\0') {

          return;

        }

        iVar2 = FUN_00578270();

        if (iVar2 == 0) {

          return;

        }

        piVar4 = (int *)FUN_00578270();

        iVar2 = (**(code **)(*piVar4 + 0x1dc))();

        if (iVar2 != DAT_00d1b6d8) {

          piVar4 = (int *)FUN_00578270();

          iVar2 = *(int *)(DAT_00d1b6d8 + 0x250);

          iVar3 = (**(code **)(*piVar4 + 0x1d4))();

          if (iVar3 != iVar2) {

            return;

          }

        }

        FUN_008027e0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x18));

      }

      if ((DAT_00d1b8ec != 0) && (*(int *)(DAT_00d1b8ec + 0x590) != 0)) {

        FUN_0083bf40(*(int *)(DAT_00d1b8ec + 0x590),param_1);

      }

    }

  }

  return;

}
