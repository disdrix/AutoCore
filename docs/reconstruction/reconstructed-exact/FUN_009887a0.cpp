// =============================================================================
// FUN_009887a0
// -----------------------------------------------------------------------------
// Stable ID: aa_009887a0
// Address:   0x009887a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009887a0 @ 0x009887a0
// Stable ID: aa_009887a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_0044f520, FUN_00970060, FUN_009887a0.
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

void FUN_009887a0(void)



{

  int iVar1;

  int unaff_EBX;

  int unaff_EDI;

  float local_20;

  float local_1c;

  float local_18;

  float local_14;

  

  FUN_00970060(*(uint32_t /* width from decompiler */ *)(unaff_EBX + 4),*(uint32_t /* width from decompiler */ *)(unaff_EDI + 0xb8));

  iVar1 = *(int *)(unaff_EDI + 0xb8);

  local_20 = 0.0;

  if (iVar1 == 0) {

    local_1c = 0.0;

  }

  else {

    local_1c = (float)*(int *)(unaff_EDI + 0x84) /

               (float)*(int *)(*(int *)(unaff_EDI + 0xb8) + 0x20);

  }

  if (*(int *)(unaff_EDI + 0xb8) != 0) {

    local_20 = (float)*(int *)(unaff_EDI + 0x80) /

               (float)*(int *)(*(int *)(unaff_EDI + 0xb8) + 0x1c);

  }

  local_14 = g_flOne / (float)*(int *)(iVar1 + 0x20);

  local_18 = g_flOne / (float)*(int *)(iVar1 + 0x1c);

  FUN_0044f520(*(uint32_t /* width from decompiler */ *)(unaff_EBX + 8),&local_20);

  *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0xc) = *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x80);

  *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x10) = *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x84);

  return;

}
