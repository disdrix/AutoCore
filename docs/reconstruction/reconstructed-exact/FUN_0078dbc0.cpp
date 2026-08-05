// =============================================================================
// FUN_0078dbc0
// -----------------------------------------------------------------------------
// Stable ID: aa_0078dbc0
// Address:   0x0078dbc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0078dbc0 @ 0x0078dbc0
// Stable ID: aa_0078dbc0
// Embedded strings (evidence for future rename):
//   - "HashError:TraversalLock, already locked for traversal"
//   - "VOG_DEBUG_STOP"
//   - "HashError:TraverseToNext, not locked for traversal"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~48 non-empty decompiler lines.
//  - Control keywords: if×7, for×2, while×1, return×1.
//  - Notable callees: FUN_007a4480×4, FUN_0078dbc0.
//  - Strings: "HashError:TraversalLock, already locked for traversal"; "VOG_DEBUG_STOP"; "HashError:TraverseToNext, not locked for traversal".
//  - Return sites: 1.

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

void __thiscall FUN_0078dbc0(int param_1,int param_2,int param_3)



{

  int iVar1;

  int unaff_ESI;

  int *piVar2;

  int iVar3;

  int aiStack_10 [3];

  int iStack_4;

  

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

      iVar1 = (**(code **)(*piVar2 + 0x78))();

      if (0x67 < iVar1) {

        (**(code **)(*piVar2 + 0x120))(aiStack_10,1,0);

        aiStack_10[0] = iStack_4 + unaff_ESI;

        (**(code **)(*piVar2 + 0x110))(&stack0xffffffec);

      }

    }

    *(uint8_t *)(*(int *)(param_1 + 0x4c0) + 0x1d) = 0;

    *(int *)(param_1 + 0x910) = *(int *)(param_1 + 0x910) + param_2;

    *(int *)(param_1 + 0x914) = *(int *)(param_1 + 0x914) + param_3;

  }

  return;

}
