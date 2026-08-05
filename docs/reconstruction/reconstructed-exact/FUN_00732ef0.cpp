// =============================================================================
// FUN_00732ef0
// -----------------------------------------------------------------------------
// Stable ID: aa_00732ef0
// Address:   0x00732ef0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00732ef0 @ 0x00732ef0
// Stable ID: aa_00732ef0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: for×2, if×2, return×2.
//  - Notable callees: FUN_00732ef0.
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

void __fastcall FUN_00732ef0(int param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  

  puVar1 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x30);

  for (puVar2 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x2c); puVar2 != puVar1; puVar2 = puVar2 + 1) {

    (**(code **)(*(int *)*puVar2 + 0x18))();

  }

  if (*(int *)(param_1 + 0x58) != 0) {

    puVar1 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x40);

    for (puVar2 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x3c); puVar2 != puVar1; puVar2 = puVar2 + 1) {

      (**(code **)(*(int *)*puVar2 + 0x18))();

    }

    (**(code **)(**(int **)(param_1 + 0x58) + 0x18))();

  }

  if (*(int *)(param_1 + 0x5c) == 0) {

    return;

  }

                    /* WARNING: Could not recover jumptable at 0x00732f44. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  (**(code **)(**(int **)(param_1 + 0x5c) + 0x18))();

  return;

}
