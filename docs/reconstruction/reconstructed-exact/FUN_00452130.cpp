// =============================================================================
// FUN_00452130
// -----------------------------------------------------------------------------
// Stable ID: aa_00452130
// Address:   0x00452130  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00452130 @ 0x00452130
// Stable ID: aa_00452130
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00452130, FUN_004552b0.
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

void __fastcall FUN_00452130(int param_1)



{

  ushort *in_EAX;

  int iVar1;

  int *unaff_EBX;

  

  iVar1 = FUN_004552b0();

  if (((iVar1 != *(int *)(param_1 + 4)) && (*(ushort *)(iVar1 + 0xc) <= *in_EAX)) &&

     ((*in_EAX != *(ushort *)(iVar1 + 0xc) || (*(ushort *)(iVar1 + 0xe) <= in_EAX[1])))) {

    *unaff_EBX = iVar1;

    return;

  }

  *unaff_EBX = *(int *)(param_1 + 4);

  return;

}
