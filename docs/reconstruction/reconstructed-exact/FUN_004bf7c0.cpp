// =============================================================================
// FUN_004bf7c0
// -----------------------------------------------------------------------------
// Stable ID: aa_004bf7c0
// Address:   0x004bf7c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004bf7c0 @ 0x004bf7c0
// Stable ID: aa_004bf7c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_004bf7c0.
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

void __thiscall FUN_004bf7c0(int param_1,uint32_t /* width from decompiler */ *param_2)



{

  if (param_2 != (uint32_t /* width from decompiler */ *)0x0) {

    if (param_2[2] == 0) {

      *(uint32_t /* width from decompiler */ *)(param_1 + 4) = *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 4) + 4);

    }

    else {

      *(uint32_t /* width from decompiler */ *)(param_2[2] + 4) = param_2[1];

    }

    if (param_2[1] != 0) {

      *(uint32_t /* width from decompiler */ *)(param_2[1] + 8) = param_2[2];

    }

    (**(code **)*param_2)(1);

    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + -1;

  }

  return;

}
