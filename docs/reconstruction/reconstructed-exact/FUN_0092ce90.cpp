// =============================================================================
// FUN_0092ce90  /  Client_RefreshMissionRelatedUi (role name; original unknown)
// -----------------------------------------------------------------------------
// Stable ID: aa_0092ce90
// Address:   0x0092ce90  (autoassault.exe, image base 0x400000)
// System:    missions-progression
// Generated: 2026-07-23 from raw capture; dual A/B seal 2026-07-29
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
//
// Purpose: Refresh mission-related UI after progress / inventory mutations.
//   client in EDI; thiscall ECX = panel for each vcall
//   client+0x107c mission UI root: if ready (+0xd0) and visible (+0x3d8) → +0x448
//   client+0x10b8 secondary panel: if ready/visible → dirty byte +0x520
// Does NOT call EvaluatePendingObjectives or CompleteObjective.
// Sibling: Client_HideMissionDialogIfOpen @ 0x0092ce50
// Dual: reviews/A_aa_0092ce90_Client_RefreshMissionRelatedUi.md
//       reviews/B_aa_0092ce90_Client_RefreshMissionRelatedUi.md
// Residual parent: reviews/a_00809460.md
// =============================================================================

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×6, return×1.
//  - Notable callees: FUN_0092ce90.
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

void FUN_0092ce90(void)



{

  int *piVar1;

  char cVar2;

  int unaff_EDI;

  

  piVar1 = *(int **)(unaff_EDI + 0x107c);

  if (piVar1 != (int *)0x0) {

    cVar2 = (**(code **)(*piVar1 + 0xd0))();

    if (cVar2 != '\0') {

      cVar2 = (**(code **)(*piVar1 + 0x3d8))();

      if (cVar2 != '\0') {

        (**(code **)(*piVar1 + 0x448))();

      }

    }

  }

  piVar1 = *(int **)(unaff_EDI + 0x10b8);

  if (piVar1 != (int *)0x0) {

    cVar2 = (**(code **)(*piVar1 + 0xd0))();

    if (cVar2 != '\0') {

      cVar2 = (**(code **)(*piVar1 + 0x3d8))();

      if (cVar2 != '\0') {

        *(uint8_t *)(piVar1 + 0x148) = 1;

      }

    }

  }

  return;

}
