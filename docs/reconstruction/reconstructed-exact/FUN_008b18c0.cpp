// =============================================================================
// FUN_008b18c0
// -----------------------------------------------------------------------------
// Stable ID: aa_008b18c0
// Address:   0x008b18c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008b18c0 @ 0x008b18c0
// Stable ID: aa_008b18c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~62 non-empty decompiler lines.
//  - Control keywords: if×19, return×1.
//  - Notable callees: FUN_00792250, FUN_008b18c0.
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

void __thiscall FUN_008b18c0(int param_1,uint32_t /* width from decompiler */ param_2)



{

  char cVar1;

  

  FUN_00792250(param_2,0x3f000000);

  if ((char)param_2 != '\0') {

    if (*(int *)(param_1 + 0x504) != 0) {

      cVar1 = (**(code **)(**(int **)(param_1 + 0x504) + 0xd0))();

      if (cVar1 != '\0') {

        (**(code **)(**(int **)(param_1 + 0x504) + 0xcc))(0);

      }

    }

    if (*(int *)(param_1 + 0x528) != 0) {

      cVar1 = (**(code **)(**(int **)(param_1 + 0x528) + 0xd0))();

      if (cVar1 != '\0') {

        (**(code **)(**(int **)(param_1 + 0x528) + 0xcc))(0);

      }

    }

    if (*(int *)(param_1 + 0x52c) != 0) {

      cVar1 = (**(code **)(**(int **)(param_1 + 0x52c) + 0xd0))();

      if (cVar1 != '\0') {

        (**(code **)(**(int **)(param_1 + 0x52c) + 0xcc))(0);

      }

    }

    if (*(int *)(param_1 + 0x530) != 0) {

      cVar1 = (**(code **)(**(int **)(param_1 + 0x530) + 0xd0))();

      if (cVar1 != '\0') {

        (**(code **)(**(int **)(param_1 + 0x530) + 0xcc))(0);

      }

    }

    if (*(int *)(param_1 + 0x524) != 0) {

      cVar1 = (**(code **)(**(int **)(param_1 + 0x524) + 0xd0))();

      if (cVar1 != '\0') {

        (**(code **)(**(int **)(param_1 + 0x524) + 0xcc))(0);

      }

    }

    if (*(int *)(param_1 + 0x520) != 0) {

      cVar1 = (**(code **)(**(int **)(param_1 + 0x520) + 0xd0))();

      if (cVar1 != '\0') {

        (**(code **)(**(int **)(param_1 + 0x520) + 0xcc))(0);

      }

    }

    if (*(int *)(param_1 + 0x514) != 0) {

      cVar1 = (**(code **)(**(int **)(param_1 + 0x514) + 0xd0))();

      if (cVar1 != '\0') {

        (**(code **)(**(int **)(param_1 + 0x514) + 0xcc))(0);

      }

    }

    if (*(int *)(param_1 + 0x518) != 0) {

      cVar1 = (**(code **)(**(int **)(param_1 + 0x518) + 0xd0))();

      if (cVar1 != '\0') {

        (**(code **)(**(int **)(param_1 + 0x518) + 0xcc))(0);

      }

    }

    if (*(int *)(param_1 + 0x51c) != 0) {

      cVar1 = (**(code **)(**(int **)(param_1 + 0x51c) + 0xd0))();

      if (cVar1 != '\0') {

        (**(code **)(**(int **)(param_1 + 0x51c) + 0xcc))(0);

      }

    }

  }

  return;

}
