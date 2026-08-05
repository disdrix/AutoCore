// =============================================================================
// FUN_00762ad0
// -----------------------------------------------------------------------------
// Stable ID: aa_00762ad0
// Address:   0x00762ad0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00762ad0 @ 0x00762ad0
// Stable ID: aa_00762ad0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, do×1, while×1.
//  - Notable callees: FUN_00762ad0.
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

uint32_t /* width from decompiler */ __thiscall FUN_00762ad0(int *param_1,uint32_t /* width from decompiler */ param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  

  (**(code **)(*param_1 + 0x34))();

  if (*(char *)(DAT_00d1f048 + 0xf) != '\0') {

    if (param_1[0x25] != 0) {

      (**(code **)(*(int *)param_1[0x25] + 0x18))(param_2);

      return 0;

    }

    puVar1 = (uint32_t /* width from decompiler */ *)param_1[0x34];

    if (puVar1 != (uint32_t /* width from decompiler */ *)param_1[0x35]) {

      do {

        (**(code **)(*param_1 + 0x70))(*puVar1,param_2);

        puVar1 = puVar1 + 1;

      } while (puVar1 != (uint32_t /* width from decompiler */ *)param_1[0x35]);

    }

  }

  return 0;

}
