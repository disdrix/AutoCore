// =============================================================================
// FUN_00712c50
// -----------------------------------------------------------------------------
// Stable ID: aa_00712c50
// Address:   0x00712c50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00712c50 @ 0x00712c50
// Stable ID: aa_00712c50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: return×3, if×2.
//  - Notable callees: FUN_00712c50.
//  - Return sites: 3.

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

uint32_t /* width from decompiler */ FUN_00712c50(uint32_t /* width from decompiler */ *param_1,short param_2,float param_3)



{

  uint32_t /* width from decompiler */ *puVar1;

  

  if (param_1 == (uint32_t /* width from decompiler */ *)0x0) {

    return 1;

  }

  *param_1 = 0;

  puVar1 = (uint32_t /* width from decompiler */ *)(*(code *)PTR_calloc_00af8a48)(1,0x18);

  if (puVar1 == (uint32_t /* width from decompiler */ *)0x0) {

    return 1;

  }

  param_3 = param_3 * g_flMsToSeconds_Inferred;

  *param_1 = puVar1;

  *puVar1 = 0x4a9a6878;

  puVar1[1] = 0x4b6e97e2;

  *(uint16_t *)((int)puVar1 + 0xe) = 0;

  *(uint16_t *)(puVar1 + 4) = 0;

  *(uint8_t *)((int)puVar1 + 0x12) = 0xfe;

  *(uint8_t *)((int)puVar1 + 0x13) = 0;

  *(uint8_t *)(puVar1 + 5) = 0;

  *(uint8_t *)((int)puVar1 + 0x15) = 0;

  puVar1[2] = param_3 / (float)(int)param_2;

  return 0;

}
