// =============================================================================
// FUN_004c0080
// -----------------------------------------------------------------------------
// Stable ID: aa_004c0080
// Address:   0x004c0080  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004c0080 @ 0x004c0080
// Stable ID: aa_004c0080
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_004bff90, FUN_004c0080.
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

uint32_t /* width from decompiler */ FUN_004c0080(int param_1)



{

  int iVar1;

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  float local_14;

  

  if ((param_1 != 0) && (*(char *)(param_1 + 0xf) == '\0')) {

    local_18 = 0;

    local_1c = 0;

    local_20 = 0;

    local_14 = g_flOne;

    iVar1 = FUN_004bff90(param_1,&DAT_00b03780,&local_20,1,0,1);

    if (iVar1 != 0) {

      *(uint8_t *)(iVar1 + 0x6a) = 1;

      return 1;

    }

  }

  return 0;

}
