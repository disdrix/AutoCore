// =============================================================================
// FUN_0092ec60
// -----------------------------------------------------------------------------
// Stable ID: aa_0092ec60
// Address:   0x0092ec60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0092ec60 @ 0x0092ec60
// Stable ID: aa_0092ec60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~141 non-empty decompiler lines.
//  - Control keywords: if×44, return×1.
//  - Notable callees: FUN_007fb560, FUN_007fc010, FUN_007fc060, FUN_0092ec60.
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

void FUN_0092ec60(void)



{

  char cVar1;

  int in_EAX;

  

  if (*(int *)(in_EAX + 0x1148) != 0) {

    (**(code **)(**(int **)(in_EAX + 0x1148) + 0x94))();

  }

  if (*(int *)(in_EAX + 0x1114) != 0) {

    cVar1 = (**(code **)(**(int **)(in_EAX + 0x1114) + 0x3d8))();

    if (cVar1 != '\0') {

      (**(code **)(**(int **)(in_EAX + 0x1114) + 0x94))();

    }

  }

  if (*(int *)(in_EAX + 0x1044) != 0) {

    cVar1 = (**(code **)(**(int **)(in_EAX + 0x1044) + 0x3d8))();

    if (cVar1 != '\0') {

      (**(code **)(**(int **)(in_EAX + 0x1044) + 0x94))();

    }

  }

  if (*(int *)(in_EAX + 0x113c) != 0) {

    cVar1 = (**(code **)(**(int **)(in_EAX + 0x113c) + 0x3d8))();

    if (cVar1 != '\0') {

      cVar1 = (**(code **)(**(int **)(in_EAX + 0x113c) + 0xd0))();

      if (cVar1 != '\0') {

        (**(code **)(**(int **)(in_EAX + 0x113c) + 0x94))();

      }

    }

  }

  if (*(int *)(in_EAX + 0x111c) != 0) {

    cVar1 = (**(code **)(**(int **)(in_EAX + 0x111c) + 0x3d8))();

    if (cVar1 != '\0') {

      cVar1 = (**(code **)(**(int **)(in_EAX + 0x111c) + 0xd0))();

      if (cVar1 != '\0') {

        (**(code **)(**(int **)(in_EAX + 0x111c) + 0x94))();

      }

    }

  }

  if (*(int *)(in_EAX + 0x1118) != 0) {

    cVar1 = (**(code **)(**(int **)(in_EAX + 0x1118) + 0x3d8))();

    if (cVar1 != '\0') {

      cVar1 = (**(code **)(**(int **)(in_EAX + 0x1118) + 0xd0))();

      if (cVar1 != '\0') {

        (**(code **)(**(int **)(in_EAX + 0x1118) + 0x94))();

      }

    }

  }

  if (*(int *)(in_EAX + 0x1124) != 0) {

    cVar1 = (**(code **)(**(int **)(in_EAX + 0x1124) + 0x3d8))();

    if (cVar1 != '\0') {

      cVar1 = (**(code **)(**(int **)(in_EAX + 0x1124) + 0xd0))();

      if (cVar1 != '\0') {

        (**(code **)(**(int **)(in_EAX + 0x1124) + 0x94))();

      }

    }

  }

  if (*(int *)(in_EAX + 0x1158) != 0) {

    cVar1 = (**(code **)(**(int **)(in_EAX + 0x1158) + 0xd0))();

    if (cVar1 != '\0') {

      if (*(int *)(in_EAX + 0x1150) != 0) {

        cVar1 = (**(code **)(**(int **)(in_EAX + 0x1150) + 0xd0))();

        if (cVar1 != '\0') {

          (**(code **)(**(int **)(in_EAX + 0x1150) + 0x94))();

        }

      }

      if (*(int *)(in_EAX + 0x1154) != 0) {

        cVar1 = (**(code **)(**(int **)(in_EAX + 0x1154) + 0xd0))();

        if (cVar1 != '\0') {

          (**(code **)(**(int **)(in_EAX + 0x1154) + 0x94))();

        }

      }

      if (*(int *)(in_EAX + 0x114c) != 0) {

        cVar1 = (**(code **)(**(int **)(in_EAX + 0x114c) + 0xd0))();

        if (cVar1 != '\0') {

          (**(code **)(**(int **)(in_EAX + 0x114c) + 0x94))();

        }

      }

      (**(code **)(**(int **)(in_EAX + 0x1158) + 0x94))();

    }

  }

  if (*(int *)(in_EAX + 0x10d4) != 0) {

    cVar1 = (**(code **)(**(int **)(in_EAX + 0x10d4) + 0x3d8))();

    if (cVar1 != '\0') {

      (**(code **)(**(int **)(in_EAX + 0x10d4) + 0x94))();

    }

  }

  if (*(int *)(in_EAX + 0x1064) != 0) {

    cVar1 = (**(code **)(**(int **)(in_EAX + 0x1064) + 0x3d8))();

    if (cVar1 != '\0') {

      (**(code **)(**(int **)(in_EAX + 0x1064) + 0x94))();

    }

  }

  FUN_007fc010();

  FUN_007fc060();

  if (*(int *)(in_EAX + 0x1164) != 0) {

    cVar1 = (**(code **)(**(int **)(in_EAX + 0x1164) + 0x3d8))();

    if (cVar1 != '\0') {

      cVar1 = (**(code **)(**(int **)(in_EAX + 0x1164) + 0x468))();

      if (cVar1 == '\0') {

        (**(code **)(**(int **)(in_EAX + 0x1164) + 0x94))();

      }

    }

  }

  if (*(int *)(in_EAX + 0x309c) != 0) {

    cVar1 = (**(code **)(**(int **)(in_EAX + 0x309c) + 0x3d8))();

    if (cVar1 != '\0') {

      (**(code **)(**(int **)(in_EAX + 0x309c) + 0x94))();

    }

  }

  if (*(int *)(in_EAX + 0x30a0) != 0) {

    cVar1 = (**(code **)(**(int **)(in_EAX + 0x30a0) + 0x3d8))();

    if (cVar1 != '\0') {

      (**(code **)(**(int **)(in_EAX + 0x30a0) + 0x94))();

    }

  }

  if (*(int *)(in_EAX + 0x30a4) != 0) {

    cVar1 = (**(code **)(**(int **)(in_EAX + 0x30a4) + 0x3d8))();

    if (cVar1 != '\0') {

      (**(code **)(**(int **)(in_EAX + 0x30a4) + 0x94))();

    }

  }

  if (*(int *)(in_EAX + 0x30a8) != 0) {

    cVar1 = (**(code **)(**(int **)(in_EAX + 0x30a8) + 0x3d8))();

    if (cVar1 != '\0') {

      (**(code **)(**(int **)(in_EAX + 0x30a8) + 0x94))();

    }

  }

  if (*(int *)(in_EAX + 0x30ac) != 0) {

    cVar1 = (**(code **)(**(int **)(in_EAX + 0x30ac) + 0x3d8))();

    if (cVar1 != '\0') {

      (**(code **)(**(int **)(in_EAX + 0x30ac) + 0x94))();

    }

  }

  if (*(int *)(in_EAX + 0x30b0) != 0) {

    cVar1 = (**(code **)(**(int **)(in_EAX + 0x30b0) + 0x3d8))();

    if (cVar1 != '\0') {

      (**(code **)(**(int **)(in_EAX + 0x30b0) + 0x94))();

    }

  }

  FUN_007fb560();

  return;

}
