// =============================================================================
// FUN_007911a0
// -----------------------------------------------------------------------------
// Stable ID: aa_007911a0
// Address:   0x007911a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007911a0 @ 0x007911a0
// Stable ID: aa_007911a0
// Embedded strings (evidence for future rename):
//   - "HashError:TraversalLock, already locked for traversal"
//   - "VOG_DEBUG_STOP"
//   - "HashError:TraverseToNext, not locked for traversal"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×6, for×2, return×2, while×1.
//  - Notable callees: FUN_007a4480×4, FUN_007911a0.
//  - Strings: "HashError:TraversalLock, already locked for traversal"; "VOG_DEBUG_STOP"; "HashError:TraverseToNext, not locked for traversal".
//  - Return sites: 2.

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

void __thiscall FUN_007911a0(int param_1,uint32_t /* width from decompiler */ param_2)



{

  int iVar1;

  int *piVar2;

  int iVar3;

  

  iVar1 = *(int *)(param_1 + 0x4c0);

  if (iVar1 != 0) {

    iVar3 = 0;

    if (*(char *)(iVar1 + 0x1d) != '\0') {

      FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    *(uint8_t *)(iVar1 + 0x1d) = 1;

    while( true ) {

      iVar1 = *(int *)(param_1 + 0x4c0);

      if (*(char *)(iVar1 + 0x1d) == '\0') {

        FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

        FUN_007a4480(0,"VOG_DEBUG_STOP");

      }

      if (iVar3 == 0) {

        iVar3 = *(int *)(iVar1 + 0x14);

      }

      else {

        iVar3 = *(int *)(iVar3 + 0x14);

      }

      if (iVar3 == 0) {

        piVar2 = (int *)0x0;

      }

      else {

        piVar2 = *(int **)(iVar3 + 8);

      }

      if (piVar2 == (int *)0x0) break;

      (**(code **)(*piVar2 + 0x174))(param_2);

    }

    *(uint8_t *)(*(int *)(param_1 + 0x4c0) + 0x1d) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x224) = param_2;

    return;

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x224) = param_2;

  return;

}
