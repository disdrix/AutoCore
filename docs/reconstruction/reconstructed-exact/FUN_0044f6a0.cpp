// =============================================================================
// FUN_0044f6a0
// -----------------------------------------------------------------------------
// Stable ID: aa_0044f6a0
// Address:   0x0044f6a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0044f6a0 @ 0x0044f6a0
// Stable ID: aa_0044f6a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_0044f6a0, FUN_0044fcf0, FUN_0046c3e0.
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

void __fastcall FUN_0044f6a0(uint32_t /* width from decompiler */ param_1)



{

  int iVar1;

  int in_EAX;

  uint32_t /* width from decompiler */ unaff_EBX;

  uint32_t /* width from decompiler */ local_4;

  

  iVar1 = *(int *)(in_EAX + 4);

  local_4 = param_1;

  if ((iVar1 != 0) &&

     ((uint)((*(int *)(in_EAX + 8) - iVar1) / 6) < (uint)((*(int *)(in_EAX + 0xc) - iVar1) / 6))) {

    iVar1 = *(int *)(in_EAX + 8);

    FUN_0044fcf0(param_1);

    *(int *)(in_EAX + 8) = iVar1 + 6;

    return;

  }

  FUN_0046c3e0(&local_4,*(uint32_t /* width from decompiler */ *)(in_EAX + 8),unaff_EBX);

  return;

}
