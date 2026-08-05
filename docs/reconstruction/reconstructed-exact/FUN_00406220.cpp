// =============================================================================
// FUN_00406220
// -----------------------------------------------------------------------------
// Stable ID: aa_00406220
// Address:   0x00406220  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00406220 @ 0x00406220
// Stable ID: aa_00406220
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00406220, FUN_00406de0, FUN_00409d40.
//  - Return sites: 2.

// READABILITY:
// Control-flow (from raw @ 0x00406220; evidence only — no invented semantics):
//  - Entry: `void __fastcall FUN_00406220(undefined4 param_1)`.
//  - Branches: if ((iVar1 != 0) && (((*(in_EAX + 8) - iVar1) / 0x28) < ((*(in_EAX + 0xc)...).
//  - Calls: FUN_00409d40(iVar1,1); FUN_00406de0(&local_4,*(in_EAX + 8),param_1).
//  - Returns (2 site(s)): `void`.




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

void __fastcall FUN_00406220(uint32_t /* width from decompiler */ param_1)



{

  int iVar1;

  int in_EAX;

  uint32_t /* width from decompiler */ local_4;

  

  iVar1 = *(int *)(in_EAX + 4);

  local_4 = param_1;

  if ((iVar1 != 0) &&

     ((uint)((*(int *)(in_EAX + 8) - iVar1) / 0x28) <

      (uint)((*(int *)(in_EAX + 0xc) - iVar1) / 0x28))) {

    iVar1 = *(int *)(in_EAX + 8);

    FUN_00409d40(iVar1,1);

    *(int *)(in_EAX + 8) = iVar1 + 0x28;

    return;

  }

  FUN_00406de0(&local_4,*(uint32_t /* width from decompiler */ *)(in_EAX + 8),param_1);

  return;

}
