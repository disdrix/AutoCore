// =============================================================================
// Named_invited_you_join_clan_named
// -----------------------------------------------------------------------------
// Stable ID: aa_0080a8f0
// Address:   0x0080a8f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_invited_you_join_clan_named @ 0x0080a8f0
// Stable ID: aa_0080a8f0
// Embedded strings (evidence for future rename):
//   - "Do you accept"
//   - "has invited you to join the clan named"
//   - "%s %s: %s. %s?"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_007a6de0×2, FUN_007a69d0, FUN_007fdfb0, Named_invited_you_join_clan_named, sprintf.
//  - Strings: "Do you accept"; "has invited you to join the clan named"; "%s %s: %s. %s?".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "has invited you to join the clan named"
 * Domain alias of FUN_0080a8f0 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_invited_you_join_clan_named(uint32_t /* width from decompiler */ param_1)



{

  int in_EAX;

  uint32_t /* width from decompiler */ uVar1;

  uint32_t /* width from decompiler */ uVar2;

  int iVar3;

  char local_200 [512];

  

  FUN_007a69d0();

  uVar1 = FUN_007a6de0("Do you accept",0xffffffff);

  iVar3 = in_EAX + 0x10;

  uVar2 = FUN_007a6de0("has invited you to join the clan named",0xffffffff);

  sprintf(local_200,"%s %s: %s. %s?",in_EAX + 0x43,uVar2,iVar3,uVar1);

  FUN_007fdfb0(param_1,local_200,0x4e38,1,0);

  return;

}
