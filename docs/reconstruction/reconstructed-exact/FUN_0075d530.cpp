// =============================================================================
// FUN_0075d530
// -----------------------------------------------------------------------------
// Stable ID: aa_0075d530
// Address:   0x0075d530  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0075d530 @ 0x0075d530
// Stable ID: aa_0075d530
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_0043ba40, FUN_0043c6f0, FUN_0044e8c0, FUN_0075d530.
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

void __fastcall FUN_0075d530(int param_1)



{

  uint32_t /* width from decompiler */ *in_EAX;

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ local_38;

  uint8_t **ppuStack_34;

  uint8_t **ppuStack_30;

  uint8_t *local_20 [2];

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  uint32_t /* width from decompiler */ local_10;

  

  ppuStack_30 = local_20;

  ppuStack_34 = (uint8_t **)0x75d544;

  FUN_0044e8c0();

  if (local_20[0] == *(uint8_t **)(param_1 + 8)) {

    ppuStack_30 = (uint8_t **)0x1;

    ppuStack_34 = (uint8_t **)0x0;

    local_20[0] = (uint8_t *)&local_38;

    local_38 = *in_EAX;

    puVar1 = (uint32_t /* width from decompiler */ *)FUN_0043c6f0();

    local_18 = *puVar1;

    local_14 = puVar1[1];

    local_10 = puVar1[2];

    ppuStack_30 = (uint8_t **)&local_18;

    ppuStack_34 = local_20;

    local_38 = 0x75d592;

    FUN_0043ba40();

    return;

  }

  *(int *)(local_20[0] + 0x10) = *(int *)(local_20[0] + 0x10) + 1;

  return;

}
