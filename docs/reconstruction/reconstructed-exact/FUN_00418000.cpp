// =============================================================================
// FUN_00418000
// -----------------------------------------------------------------------------
// Stable ID: aa_00418000
// Address:   0x00418000  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00418000 @ 0x00418000
// Stable ID: aa_00418000
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00418000, FUN_004180e0, FUN_00418460.
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

void __fastcall FUN_00418000(uint32_t /* width from decompiler */ param_1)



{

  int iVar1;

  int in_EAX;

  

  iVar1 = *(int *)(in_EAX + 4);

  if ((iVar1 != 0) &&

     ((uint)(*(int *)(in_EAX + 8) - iVar1 >> 3) < (uint)(*(int *)(in_EAX + 0xc) - iVar1 >> 3))) {

    iVar1 = *(int *)(in_EAX + 8);

    FUN_00418460(iVar1,1,param_1);

    *(int *)(in_EAX + 8) = iVar1 + 8;

    return;

  }

  FUN_004180e0(*(uint32_t /* width from decompiler */ *)(in_EAX + 8),param_1);

  return;

}
