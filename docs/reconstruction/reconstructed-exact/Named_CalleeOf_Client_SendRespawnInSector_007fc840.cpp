// =============================================================================
// Named_CalleeOf_Client_SendRespawnInSector_007fc840
// -----------------------------------------------------------------------------
// Stable ID: aa_007fc840
// Callee of Client_SendRespawnInSector
// Address:   0x007fc840  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_SendRespawnInSector: spawn/transfer helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~45 non-empty decompiler lines.
//  - Control keywords: if×12, return×1.
//  - Notable callees: FUN_007fb990, FUN_007fc840.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Client_SendRespawnInSector
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

void Named_CalleeOf_Client_SendRespawnInSector_007fc840(void)



{

  char cVar1;

  int in_EAX;

  int iVar2;

  

  if (*(int *)(in_EAX + 0x1158) != 0) {

    cVar1 = (**(code **)(**(int **)(in_EAX + 0x1158) + 0xd0))();

    if (cVar1 != '\0') {

      iVar2 = (**(code **)(**(int **)(in_EAX + 0x1158) + 0xe8))();

      if (iVar2 != -1) {

        (**(code **)(**(int **)(in_EAX + 0x1158) + 0xd4))(0);

        (**(code **)(**(int **)(in_EAX + 0x1158) + 0xfc))(0,0x3f000000);

      }

      FUN_007fb990();

    }

  }

  if (*(int *)(in_EAX + 0x1150) != 0) {

    cVar1 = (**(code **)(**(int **)(in_EAX + 0x1150) + 0xd0))();

    if (cVar1 != '\0') {

      iVar2 = (**(code **)(**(int **)(in_EAX + 0x1150) + 0xe8))();

      if (iVar2 != -1) {

        (**(code **)(**(int **)(in_EAX + 0x1150) + 0xfc))(0,0x3f000000);

      }

    }

  }

  if (*(int *)(in_EAX + 0x1154) != 0) {

    cVar1 = (**(code **)(**(int **)(in_EAX + 0x1154) + 0xd0))();

    if (cVar1 != '\0') {

      iVar2 = (**(code **)(**(int **)(in_EAX + 0x1154) + 0xe8))();

      if (iVar2 != -1) {

        (**(code **)(**(int **)(in_EAX + 0x1154) + 0xfc))(0,0x3f000000);

      }

    }

  }

  if (*(int *)(in_EAX + 0x114c) != 0) {

    cVar1 = (**(code **)(**(int **)(in_EAX + 0x114c) + 0xd0))();

    if (cVar1 != '\0') {

      iVar2 = (**(code **)(**(int **)(in_EAX + 0x114c) + 0xe8))();

      if (iVar2 != -1) {

        (**(code **)(**(int **)(in_EAX + 0x114c) + 0xfc))(0,0x3f000000);

      }

    }

  }

  return;

}
