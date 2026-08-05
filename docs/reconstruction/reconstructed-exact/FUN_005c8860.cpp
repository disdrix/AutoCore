// =============================================================================
// FUN_005c8860
// -----------------------------------------------------------------------------
// Stable ID: aa_005c8860
// Address:   0x005c8860  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005c8860 @ 0x005c8860
// Stable ID: aa_005c8860
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_005c8860.
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

void * FUN_005c8860(void)



{

  void *pvVar1;

  

  pvVar1 = operator_new(0xd8);

  if (pvVar1 != (void *)0x0) {

    *(uint32_t /* width from decompiler */ *)((int)pvVar1 + 0x6c) = 0;

    *(uint32_t /* width from decompiler */ *)((int)pvVar1 + 0x68) = 0;

    *(uint32_t /* width from decompiler */ *)((int)pvVar1 + 100) = 0;

    *(uint32_t /* width from decompiler */ *)((int)pvVar1 + 0x78) = 0;

    *(uint32_t /* width from decompiler */ *)((int)pvVar1 + 0x74) = 0;

    *(uint32_t /* width from decompiler */ *)((int)pvVar1 + 0x70) = 0;

    *(float *)((int)pvVar1 + 0x7c) = g_flMsToSeconds_Inferred;

    return pvVar1;

  }

  return (void *)0x0;

}
