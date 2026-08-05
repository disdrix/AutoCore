// =============================================================================
// FUN_008f0f80
// -----------------------------------------------------------------------------
// Stable ID: aa_008f0f80
// Address:   0x008f0f80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008f0f80 @ 0x008f0f80
// Stable ID: aa_008f0f80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~43 non-empty decompiler lines.
//  - Control keywords: if×10, do×1, while×1, return×1.
//  - Notable callees: FUN_008f0f80.
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

void FUN_008f0f80(uint32_t /* width from decompiler */ param_1)



{

  int in_EAX;

  int iVar1;

  int *piVar2;

  

  if (*(int *)(in_EAX + 0x55c) != 0) {

    (**(code **)(**(int **)(in_EAX + 0x55c) + 4))(param_1);

  }

  if (*(int *)(in_EAX + 0x560) != 0) {

    (**(code **)(**(int **)(in_EAX + 0x560) + 4))(param_1);

  }

  if (*(int *)(in_EAX + 0x564) != 0) {

    (**(code **)(**(int **)(in_EAX + 0x564) + 4))(param_1);

  }

  if (*(int *)(in_EAX + 0x568) != 0) {

    (**(code **)(**(int **)(in_EAX + 0x568) + 4))(param_1);

  }

  if (*(int *)(in_EAX + 0x56c) != 0) {

    (**(code **)(**(int **)(in_EAX + 0x56c) + 4))(param_1);

  }

  if (*(int *)(in_EAX + 0x588) != 0) {

    (**(code **)(**(int **)(in_EAX + 0x588) + 4))(param_1);

  }

  if (*(int *)(in_EAX + 0x58c) != 0) {

    (**(code **)(**(int **)(in_EAX + 0x58c) + 4))(param_1);

  }

  if (*(int *)(in_EAX + 0x590) != 0) {

    (**(code **)(**(int **)(in_EAX + 0x590) + 4))(param_1);

  }

  piVar2 = (int *)(in_EAX + 0x57c);

  iVar1 = 3;

  do {

    if (piVar2[-3] != 0) {

      (**(code **)(*(int *)piVar2[-3] + 4))(param_1);

    }

    if (*piVar2 != 0) {

      (**(code **)(*(int *)*piVar2 + 4))(param_1);

    }

    piVar2 = piVar2 + 1;

    iVar1 = iVar1 + -1;

  } while (iVar1 != 0);

  return;

}
