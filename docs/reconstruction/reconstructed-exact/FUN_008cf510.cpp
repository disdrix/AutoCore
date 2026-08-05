// =============================================================================
// FUN_008cf510
// -----------------------------------------------------------------------------
// Stable ID: aa_008cf510
// Address:   0x008cf510  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008cf510 @ 0x008cf510
// Stable ID: aa_008cf510
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~94 non-empty decompiler lines.
//  - Control keywords: if×27, do×1, while×1, return×1.
//  - Notable callees: FUN_008cf510.
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

void FUN_008cf510(uint32_t /* width from decompiler */ param_1)



{

  int in_EAX;

  int iVar1;

  int *piVar2;

  

  if (*(int *)(in_EAX + 0x6e0) != 0) {

    (**(code **)(**(int **)(in_EAX + 0x6e0) + 4))(param_1);

  }

  if (*(int *)(in_EAX + 0x6e4) != 0) {

    (**(code **)(**(int **)(in_EAX + 0x6e4) + 4))(param_1);

  }

  if (*(int *)(in_EAX + 0x6e8) != 0) {

    (**(code **)(**(int **)(in_EAX + 0x6e8) + 4))(param_1);

  }

  if (*(int *)(in_EAX + 0x6ec) != 0) {

    (**(code **)(**(int **)(in_EAX + 0x6ec) + 4))(param_1);

  }

  if (*(int *)(in_EAX + 0x6f0) != 0) {

    (**(code **)(**(int **)(in_EAX + 0x6f0) + 4))(param_1);

  }

  if (*(int *)(in_EAX + 0x6f4) != 0) {

    (**(code **)(**(int **)(in_EAX + 0x6f4) + 4))(param_1);

  }

  if (*(int *)(in_EAX + 0x6f8) != 0) {

    (**(code **)(**(int **)(in_EAX + 0x6f8) + 4))(param_1);

  }

  if (*(int *)(in_EAX + 0x6fc) != 0) {

    (**(code **)(**(int **)(in_EAX + 0x6fc) + 4))(param_1);

  }

  if (*(int *)(in_EAX + 0x75c) != 0) {

    (**(code **)(**(int **)(in_EAX + 0x75c) + 4))(param_1);

  }

  if (*(int *)(in_EAX + 0x700) != 0) {

    (**(code **)(**(int **)(in_EAX + 0x700) + 4))(param_1);

  }

  if (*(int *)(in_EAX + 0x704) != 0) {

    (**(code **)(**(int **)(in_EAX + 0x704) + 4))(param_1);

  }

  if (*(int *)(in_EAX + 0x708) != 0) {

    (**(code **)(**(int **)(in_EAX + 0x708) + 4))(param_1);

  }

  if (*(int *)(in_EAX + 0x760) != 0) {

    (**(code **)(**(int **)(in_EAX + 0x760) + 4))(param_1);

  }

  if (*(int *)(in_EAX + 0x764) != 0) {

    (**(code **)(**(int **)(in_EAX + 0x764) + 4))(param_1);

  }

  if (*(int *)(in_EAX + 0x768) != 0) {

    (**(code **)(**(int **)(in_EAX + 0x768) + 4))(param_1);

  }

  if (*(int *)(in_EAX + 0x6b4) != 0) {

    (**(code **)(**(int **)(in_EAX + 0x6b4) + 4))(param_1);

  }

  if (*(int *)(in_EAX + 0x6ac) != 0) {

    (**(code **)(**(int **)(in_EAX + 0x6ac) + 4))(param_1);

  }

  if (*(int *)(in_EAX + 0x6a4) != 0) {

    (**(code **)(**(int **)(in_EAX + 0x6a4) + 4))(param_1);

  }

  if (*(int *)(in_EAX + 0x69c) != 0) {

    (**(code **)(**(int **)(in_EAX + 0x69c) + 4))(param_1);

  }

  piVar2 = (int *)(in_EAX + 0x724);

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

    if (piVar2[6] != 0) {

      (**(code **)(*(int *)piVar2[6] + 4))(param_1);

    }

    if (piVar2[8] != 0) {

      (**(code **)(*(int *)piVar2[8] + 4))(param_1);

    }

    if (piVar2[10] != 0) {

      (**(code **)(*(int *)piVar2[10] + 4))(param_1);

    }

    if (piVar2[0xc] != 0) {

      (**(code **)(*(int *)piVar2[0xc] + 4))(param_1);

    }

    piVar2 = piVar2 + 1;

    iVar1 = iVar1 + -1;

  } while (iVar1 != 0);

  return;

}
