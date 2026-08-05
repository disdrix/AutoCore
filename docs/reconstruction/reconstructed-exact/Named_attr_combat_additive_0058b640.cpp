// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×5, return×2.
//  - Notable callees: FUN_005781b0×4, FUN_0058b640.
//  - Strings: "attr_combat] (additive)\n"; "attr_perception] (additive)\n"; "attr_tech] (additive)\n"; "attr_theory] (additive)\n".
//  - Return sites: 2.

// =============================================================================
// Named_attr_combat_additive_0058b640
// -----------------------------------------------------------------------------
// Stable ID: aa_0058b640
// Address:   0x0058b640  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "attr_combat] (additive)
"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ Named_attr_combat_additive_0058b640(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  if ((*(byte *)(param_1 + 0x624) & 0x40) != 0) {

    if (*(short *)(param_1 + 0xd0) != 0) {

      FUN_005781b0(param_3,param_2,"attr_combat] (additive)\n",1);

    }

    if (*(short *)(param_1 + 0xd4) != 0) {

      FUN_005781b0(param_3,param_2,"attr_perception] (additive)\n",1);

    }

    if (*(short *)(param_1 + 0xd6) != 0) {

      FUN_005781b0(param_3,param_2,"attr_tech] (additive)\n",1);

    }

    if (*(short *)(param_1 + 0xd2) != 0) {

      FUN_005781b0(param_3,param_2,"attr_theory] (additive)\n",1);

    }

    return 0;

  }

  return 0;

}
