// =============================================================================
// FUN_008bcb80
// -----------------------------------------------------------------------------
// Stable ID: aa_008bcb80
// Address:   0x008bcb80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008bcb80 @ 0x008bcb80
// Stable ID: aa_008bcb80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_007916e0, FUN_008bcb80.
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

void __thiscall FUN_008bcb80(int param_1,uint32_t /* width from decompiler */ param_2)



{

  float10 fVar1;

  

  FUN_007916e0(param_2);

  if (((char)param_2 != '\0') && (*(int *)(param_1 + 0x524) != 0)) {

    fVar1 = (float10)(**(code **)(**(int **)(param_1 + 0x524) + 0x3c4))();

    if ((float10)g_flZero == fVar1) {

      (**(code **)(**(int **)(param_1 + 0x524) + 0xcc))(0);

      if (*(int *)(param_1 + 0x520) != 0) {

                    /* WARNING: Could not recover jumptable at 0x008bcbe4. Too many branches */

                    /* WARNING: Treating indirect jump as call */

        (**(code **)(**(int **)(param_1 + 0x520) + 0xcc))();

        return;

      }

    }

  }

  return;

}
