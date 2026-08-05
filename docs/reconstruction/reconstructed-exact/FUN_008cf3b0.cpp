// =============================================================================
// FUN_008cf3b0
// -----------------------------------------------------------------------------
// Stable ID: aa_008cf3b0
// Address:   0x008cf3b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008cf3b0 @ 0x008cf3b0
// Stable ID: aa_008cf3b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~61 non-empty decompiler lines.
//  - Control keywords: if×16, do×1, while×1, return×1.
//  - Notable callees: FUN_008cf3b0.
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

void FUN_008cf3b0(uint32_t /* width from decompiler */ param_1)



{

  int in_EAX;

  int iVar1;

  int *piVar2;

  

  if (*(int *)(in_EAX + 0x70c) != 0) {

    (**(code **)(**(int **)(in_EAX + 0x70c) + 4))(param_1);

  }

  if (*(int *)(in_EAX + 0x710) != 0) {

    (**(code **)(**(int **)(in_EAX + 0x710) + 4))(param_1);

  }

  if (*(int *)(in_EAX + 0x714) != 0) {

    (**(code **)(**(int **)(in_EAX + 0x714) + 4))(param_1);

  }

  if (*(int *)(in_EAX + 0x718) != 0) {

    (**(code **)(**(int **)(in_EAX + 0x718) + 4))(param_1);

  }

  if (*(int *)(in_EAX + 0x78c) != 0) {

    (**(code **)(**(int **)(in_EAX + 0x78c) + 4))(param_1);

  }

  if (*(int *)(in_EAX + 0x790) != 0) {

    (**(code **)(**(int **)(in_EAX + 0x790) + 4))(param_1);

  }

  if (*(int *)(in_EAX + 0x6b8) != 0) {

    (**(code **)(**(int **)(in_EAX + 0x6b8) + 4))(param_1);

  }

  if (*(int *)(in_EAX + 0x6b0) != 0) {

    (**(code **)(**(int **)(in_EAX + 0x6b0) + 4))(param_1);

  }

  if (*(int *)(in_EAX + 0x694) != 0) {

    (**(code **)(**(int **)(in_EAX + 0x694) + 4))(param_1);

  }

  if (*(int *)(in_EAX + 0x6a8) != 0) {

    (**(code **)(**(int **)(in_EAX + 0x6a8) + 4))(param_1);

  }

  if (*(int *)(in_EAX + 0x6a0) != 0) {

    (**(code **)(**(int **)(in_EAX + 0x6a0) + 4))(param_1);

  }

  if (*(int *)(in_EAX + 0x698) != 0) {

    (**(code **)(**(int **)(in_EAX + 0x698) + 4))(param_1);

  }

  piVar2 = (int *)(in_EAX + 0x774);

  iVar1 = 2;

  do {

    if (piVar2[-2] != 0) {

      (**(code **)(*(int *)piVar2[-2] + 4))(param_1);

    }

    if (*piVar2 != 0) {

      (**(code **)(*(int *)*piVar2 + 4))(param_1);

    }

    if (piVar2[2] != 0) {

      (**(code **)(*(int *)piVar2[2] + 4))(param_1);

    }

    if (piVar2[4] != 0) {

      (**(code **)(*(int *)piVar2[4] + 4))(param_1);

    }

    piVar2 = piVar2 + 1;

    iVar1 = iVar1 + -1;

  } while (iVar1 != 0);

  return;

}
