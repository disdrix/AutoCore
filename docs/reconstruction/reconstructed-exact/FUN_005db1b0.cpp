// =============================================================================
// FUN_005db1b0
// -----------------------------------------------------------------------------
// Stable ID: aa_005db1b0
// Address:   0x005db1b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005db1b0 @ 0x005db1b0
// Stable ID: aa_005db1b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: FUN_00560020, FUN_005db1b0.
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

void __fastcall FUN_005db1b0(int param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  

  if (*(int *)(param_1 + 0xd0) != 0) {

    if (*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1) + 0xe4a4) != 0) {

      FUN_00560020(*(int *)(param_1 + 0xd0));

    }

    puVar1 = *(uint32_t /* width from decompiler */ **)(param_1 + 0xd0);

    *(short *)((int)puVar1 + 6) = *(short *)((int)puVar1 + 6) + -1;

    if (*(short *)((int)puVar1 + 6) == 0) {

      (**(code **)*puVar1)(1);

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xd0) = 0;

    if (*(void **)(param_1 + 0xd4) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

      operator_delete(*(void **)(param_1 + 0xd4));

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xd4) = 0;

  }

  return;

}
