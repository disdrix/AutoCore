// =============================================================================
// FUN_00748220
// -----------------------------------------------------------------------------
// Stable ID: aa_00748220
// Address:   0x00748220  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00748220 @ 0x00748220
// Stable ID: aa_00748220
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00748220, FUN_0096aa20.
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

void __fastcall FUN_00748220(int param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  

  puVar1 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x5c);

  iVar2 = FUN_0096aa20(*(uint32_t /* width from decompiler */ *)(param_1 + 0x58));

  if (iVar2 < 0) {

    *(uint32_t /* width from decompiler */ *)(param_1 + 100) = *puVar1;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x60) = puVar1[7];

    return;

  }

  *(int *)(param_1 + 100) = *(int *)(puVar1[3] + iVar2 * 4) + 0x30;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x60) = puVar1[7];

  return;

}
