// =============================================================================
// FUN_00569bc0
// -----------------------------------------------------------------------------
// Stable ID: aa_00569bc0
// Address:   0x00569bc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00569bc0 @ 0x00569bc0
// Stable ID: aa_00569bc0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_00516720, FUN_00569bc0, FUN_005cb520.
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

void __thiscall FUN_00569bc0(int param_1,int param_2,int param_3,uint32_t /* width from decompiler */ param_4)



{

  if (param_2 != 0) {

    FUN_005cb520(param_2,param_3,param_4);

    if (param_3 == 2) {

      *(uint32_t /* width from decompiler */ *)(param_1 + -0x20) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x114);

      *(uint32_t /* width from decompiler */ *)(param_1 + -0x1c) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x118);

      *(uint32_t /* width from decompiler */ *)(param_1 + -0x18) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x11c);

      *(uint32_t /* width from decompiler */ *)(param_1 + -0x2c) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x108);

      *(uint32_t /* width from decompiler */ *)(param_1 + -0x28) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x10c);

      *(uint32_t /* width from decompiler */ *)(param_1 + -0x24) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x110);

      FUN_00516720(param_2 + 0x120);

      if (*(int *)(param_2 + 0xf4) != 0) {

        *(int *)(param_1 + -0x80) = *(int *)(param_2 + 0xf4);

        *(uint32_t /* width from decompiler */ *)(param_1 + -0x6c) = *(uint32_t /* width from decompiler */ *)(param_2 + 0xfc);

        *(uint32_t /* width from decompiler */ *)(param_1 + -0x68) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x100);

        *(uint32_t /* width from decompiler */ *)(param_1 + -0x74) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x104);

        *(uint32_t /* width from decompiler */ *)(param_1 + -0x54) = *(uint32_t /* width from decompiler */ *)(param_2 + 0xd8);

        *(uint32_t /* width from decompiler */ *)(param_1 + -0x50) = *(uint32_t /* width from decompiler */ *)(param_2 + 0xdc);

        *(uint32_t /* width from decompiler */ *)(param_1 + -0x4c) = *(uint32_t /* width from decompiler */ *)(param_2 + 0xe0);

        *(uint32_t /* width from decompiler */ *)(param_1 + -0x48) = *(uint32_t /* width from decompiler */ *)(param_2 + 0xe4);

        *(uint16_t *)(param_1 + -0x44) = *(uint16_t *)(param_2 + 0xe8);

        *(uint32_t /* width from decompiler */ *)(param_1 + -0x40) = *(uint32_t /* width from decompiler */ *)(param_2 + 0xec);

        *(uint16_t *)(param_1 + -0x38) = *(uint16_t *)(param_2 + 0xf0);

      }

    }

  }

  return;

}
