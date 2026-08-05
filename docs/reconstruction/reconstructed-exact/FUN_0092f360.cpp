// =============================================================================
// FUN_0092f360
// -----------------------------------------------------------------------------
// Stable ID: aa_0092f360
// Address:   0x0092f360  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0092f360 @ 0x0092f360
// Stable ID: aa_0092f360
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0092f360.
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

void __fastcall FUN_0092f360(int param_1)



{

  int iVar1;

  int iVar2;

  

  iVar1 = *(int *)(param_1 + 0xe98);

  if (iVar1 != 0) {

    iVar2 = *(int *)(*(int *)(iVar1 + 4) + 4);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x508) = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x164 + iVar1);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x50c) = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x168 + iVar1);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x510) =

         *(uint32_t /* width from decompiler */ *)

          (*(int *)(*(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 0xac + iVar1) + 0x3c) + 4);

  }

  return;

}
