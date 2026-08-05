// =============================================================================
// FUN_00553f50
// -----------------------------------------------------------------------------
// Stable ID: aa_00553f50
// Address:   0x00553f50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00553f50 @ 0x00553f50
// Stable ID: aa_00553f50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_004b8dc0×2, FUN_004b73c0, FUN_00553f50.
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

void __thiscall FUN_00553f50(int param_1,uint32_t /* width from decompiler */ param_2,int param_3,uint32_t /* width from decompiler */ param_4)



{

  if (param_3 != 0) {

    if ((char)param_2 == '\0') {

      FUN_004b8dc0(0,0);

    }

    else if (*(int *)(param_1 + 0x188) != 0) {

      FUN_004b73c0(*(int *)(*(int *)(*(int *)(param_1 + 0x188) + 4) + 4) + 4 +

                   *(int *)(param_1 + 0x188));

      FUN_004b8dc0(param_2,0);

      *(uint32_t /* width from decompiler */ *)(param_3 + 0x38) = param_4;

      *(uint32_t /* width from decompiler */ *)(param_3 + 0x2c) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x40);

      return;

    }

  }

  return;

}
