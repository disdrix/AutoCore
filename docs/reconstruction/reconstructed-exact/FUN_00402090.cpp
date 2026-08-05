// =============================================================================
// FUN_00402090
// -----------------------------------------------------------------------------
// Stable ID: aa_00402090
// Address:   0x00402090  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00402090 @ 0x00402090
// Stable ID: aa_00402090
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_006a3db0×2, FUN_00402090.
//  - Return sites: 1.

// READABILITY:
// Control-flow (from raw @ 0x00402090; evidence only — no invented semantics):
//  - Entry: `int __fastcall FUN_00402090(int param_1)`.
//  - Branches: if (uVar2 <= uVar4); if (uVar3 < uVar2).
//  - Calls: FUN_006a3db0().
//  - Returns (1 site(s)): `*(param_1 + 0x28) + (iVar1 * uVar2 + ...`.




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

int __fastcall FUN_00402090(int param_1)



{

  int iVar1;

  uint uVar2;

  uint uVar3;

  uint uVar4;

  

  uVar2 = FUN_006a3db0();

  iVar1 = *(int *)(param_1 + 4);

  uVar4 = iVar1 - 1;

  if (uVar2 <= uVar4) {

    uVar4 = uVar2;

  }

  uVar2 = FUN_006a3db0();

  uVar3 = *(int *)(param_1 + 8) - 1;

  if (uVar3 < uVar2) {

    uVar2 = uVar3;

  }

  return *(int *)(param_1 + 0x28) + (iVar1 * uVar2 + uVar4) * 0x28;

}
