// =============================================================================
// FUN_00827920
// -----------------------------------------------------------------------------
// Stable ID: aa_00827920
// Address:   0x00827920  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00827920 @ 0x00827920
// Stable ID: aa_00827920
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_00826f90, FUN_00827920.
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

void FUN_00827920(void)



{

  int in_EAX;

  

  if (*(char *)(in_EAX + 0x4fd) != '\0') {

    if (*(int **)(in_EAX + 0x564) != (int *)0x0) {

      (**(code **)(**(int **)(in_EAX + 0x564) + 8))(in_EAX + 0x534);

      (**(code **)(**(int **)(in_EAX + 0x564) + 0x118))(in_EAX + 0x524);

      (**(code **)(**(int **)(in_EAX + 0x564) + 0x34c))();

    }

    if (*(int **)(in_EAX + 0x560) != (int *)0x0) {

      (**(code **)(**(int **)(in_EAX + 0x560) + 8))(in_EAX + 0x52c);

      (**(code **)(**(int **)(in_EAX + 0x560) + 0x118))(in_EAX + 0x51c);

      (**(code **)(**(int **)(in_EAX + 0x560) + 0x34c))();

    }

    *(uint8_t *)(in_EAX + 0x4fd) = 0;

  }

  FUN_00826f90();

  return;

}
