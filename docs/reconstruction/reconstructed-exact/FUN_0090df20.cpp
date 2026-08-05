// =============================================================================
// FUN_0090df20
// -----------------------------------------------------------------------------
// Stable ID: aa_0090df20
// Address:   0x0090df20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0090df20 @ 0x0090df20
// Stable ID: aa_0090df20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: do×2, if×2, while×2, return×1.
//  - Notable callees: FUN_0090df20.
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

void FUN_0090df20(uint32_t /* width from decompiler */ param_1)



{

  int iVar1;

  int *piVar2;

  

  piVar2 = &DAT_00d09940;

  do {

    iVar1 = 0xc;

    do {

      if (*piVar2 != 0) {

        (**(code **)(*(int *)*piVar2 + 0x44))();

        (**(code **)(*(int *)(*piVar2 + 0x40) + 0x28))(param_1);

        if (*(int **)(*piVar2 + 0x48) != (int *)0x0) {

          (**(code **)(**(int **)(*piVar2 + 0x48) + 0x10))(3);

        }

      }

      piVar2 = piVar2 + 1;

      iVar1 = iVar1 + -1;

    } while (iVar1 != 0);

  } while ((int)piVar2 < 0xd09971);

  return;

}
