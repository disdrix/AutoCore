// =============================================================================
// FUN_006412c0
// -----------------------------------------------------------------------------
// Stable ID: aa_006412c0
// Address:   0x006412c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006412c0 @ 0x006412c0
// Stable ID: aa_006412c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_0063fb30, FUN_0063fc60, FUN_0063fca0, FUN_00640580, FUN_006412c0, FUN_00652910.
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

void __fastcall FUN_006412c0(int param_1)



{

  char *pcVar1;

  uint8_t local_d;

  uint32_t /* width from decompiler */ local_c;

  uint32_t /* width from decompiler */ local_8;

  uint32_t /* width from decompiler */ local_4;

  

  FUN_00652910(&local_8,8,1);

  pcVar1 = (char *)FUN_0063fb30(&local_d);

  if ((*pcVar1 != '\0') && (*(int *)(param_1 + 0x18) != 0)) {

    local_c = 0;

    pcVar1 = (char *)FUN_00640580(&local_d,&local_c,*(uint32_t /* width from decompiler */ *)(param_1 + 8));

    if (*pcVar1 != '\0') {

      FUN_0063fc60(&local_d,local_8,local_4,local_c);

    }

    FUN_0063fca0(local_c);

  }

  return;

}
