// =============================================================================
// FUN_0048ea00
// -----------------------------------------------------------------------------
// Stable ID: aa_0048ea00
// Address:   0x0048ea00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0048ea00 @ 0x0048ea00
// Stable ID: aa_0048ea00
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×5, return×2.
//  - Notable callees: FUN_0048ea00, FUN_0074ecf0.
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

void __fastcall FUN_0048ea00(int param_1)



{

  void *pvVar1;

  

  if (*(int **)(param_1 + 0x188) != (int *)0x0) {

    (**(code **)(**(int **)(param_1 + 0x188) + 0x10))(*(uint32_t /* width from decompiler */ *)(param_1 + 0x180));

    pvVar1 = *(void **)(param_1 + 0x180);

    if (pvVar1 != (void *)0x0) {

      FUN_0074ecf0();

                    /* WARNING: Subroutine does not return */

      operator_delete(pvVar1);

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x180) = 0;

  }

  if (*(uint32_t /* width from decompiler */ **)(param_1 + 0x184) != (uint32_t /* width from decompiler */ *)0x0) {

    (**(code **)**(uint32_t /* width from decompiler */ **)(param_1 + 0x184))(1);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x184) = 0;

  if (*(uint32_t /* width from decompiler */ **)(param_1 + 0x188) != (uint32_t /* width from decompiler */ *)0x0) {

    (**(code **)**(uint32_t /* width from decompiler */ **)(param_1 + 0x188))(1);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x188) = 0;

  if (*(uint32_t /* width from decompiler */ **)(param_1 + 0x94) != (uint32_t /* width from decompiler */ *)0x0) {

    (**(code **)**(uint32_t /* width from decompiler */ **)(param_1 + 0x94))(1);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x94) = 0;

  return;

}
