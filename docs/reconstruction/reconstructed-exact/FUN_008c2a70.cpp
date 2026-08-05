// =============================================================================
// FUN_008c2a70
// -----------------------------------------------------------------------------
// Stable ID: aa_008c2a70
// Address:   0x008c2a70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008c2a70 @ 0x008c2a70
// Stable ID: aa_008c2a70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: if×6, return×2.
//  - Notable callees: FUN_007916e0, FUN_008c2a70.
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

void __thiscall FUN_008c2a70(int *param_1,uint32_t /* width from decompiler */ param_2)



{

  FUN_007916e0(param_2);

  if ((char)param_2 != '\0') {

    if ((DAT_00d17764 < 2) || (param_1[0x143] == 1)) {

      param_1[0x146] = -1;

      param_1[0x147] = -1;

      (**(code **)(*param_1 + 0x448))();

    }

    else {

      if ((int *)param_1[0x150] != (int *)0x0) {

        (**(code **)(*(int *)param_1[0x150] + 0xcc))(0);

      }

      if ((int *)param_1[0x151] != (int *)0x0) {

        (**(code **)(*(int *)param_1[0x151] + 0xcc))(0);

      }

      if ((int *)param_1[0x152] != (int *)0x0) {

        (**(code **)(*(int *)param_1[0x152] + 0xcc))(0);

      }

      if ((int *)param_1[0x153] != (int *)0x0) {

        (**(code **)(*(int *)param_1[0x153] + 0xcc))(0);

        (**(code **)(*param_1 + 0x450))();

        return;

      }

    }

    (**(code **)(*param_1 + 0x450))();

  }

  return;

}
