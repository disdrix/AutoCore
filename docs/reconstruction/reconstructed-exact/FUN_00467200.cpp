// =============================================================================
// FUN_00467200
// -----------------------------------------------------------------------------
// Stable ID: aa_00467200
// Address:   0x00467200  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00467200 @ 0x00467200
// Stable ID: aa_00467200
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_0045f0f0, FUN_00467200, FUN_004672d0.
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

void __fastcall FUN_00467200(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2)



{

  int iVar1;

  int in_EAX;

  

  iVar1 = *(int *)(in_EAX + 4);

  if ((iVar1 != 0) &&

     ((uint)(*(int *)(in_EAX + 8) - iVar1 >> 5) < (uint)(*(int *)(in_EAX + 0xc) - iVar1 >> 5))) {

    iVar1 = *(int *)(in_EAX + 8);

    FUN_0045f0f0(param_1);

    *(int *)(in_EAX + 8) = iVar1 + 0x20;

    return;

  }

  FUN_004672d0(*(uint32_t /* width from decompiler */ *)(in_EAX + 8),param_2);

  return;

}
