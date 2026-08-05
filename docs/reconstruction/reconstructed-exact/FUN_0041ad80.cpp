// =============================================================================
// FUN_0041ad80
// -----------------------------------------------------------------------------
// Stable ID: aa_0041ad80
// Address:   0x0041ad80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0041ad80 @ 0x0041ad80
// Stable ID: aa_0041ad80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: return×2, do×1, if×1, while×1.
//  - Notable callees: FUN_0041ad80, FUN_0041c660.
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

int __fastcall FUN_0041ad80(int param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  int iVar3;

  

  iVar2 = *(int *)(param_1 + 0x14);

  do {

    if (iVar2 == 0) {

      return 0;

    }

    puVar1 = (uint32_t /* width from decompiler */ *)(iVar2 + 8);

    iVar2 = *(int *)(iVar2 + 0x14);

    iVar3 = FUN_0041c660(*puVar1,0);

  } while (-1 < iVar3);

  return iVar3;

}
