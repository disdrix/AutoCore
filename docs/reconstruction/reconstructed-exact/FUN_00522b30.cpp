// =============================================================================
// FUN_00522b30
// -----------------------------------------------------------------------------
// Stable ID: aa_00522b30
// Address:   0x00522b30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00522b30 @ 0x00522b30
// Stable ID: aa_00522b30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00522b30.
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

uint32_t /* width from decompiler */ __thiscall

FUN_00522b30(int param_1,int param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,uint32_t /* width from decompiler */ param_5,

            uint32_t /* width from decompiler */ param_6,uint8_t param_7)



{

  if (((*(char *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1) + 0x7e) != '\0') &&

      (*(char *)(param_1 + 0xc7c) == '\0')) && (*(float *)(param_1 + 0xc80) <= g_flZero)) {

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xc88) = param_3;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xc8c) = param_4;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xc90) = param_5;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xc94) = param_6;

    *(uint8_t *)(param_1 + 0xc7d) = param_7;

    *(float *)(param_1 + 0xc80) = (float)param_2;

    *(uint8_t *)(param_1 + 0xc7c) = 1;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xc98) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x6c0);

    return 1;

  }

  return 0;

}
