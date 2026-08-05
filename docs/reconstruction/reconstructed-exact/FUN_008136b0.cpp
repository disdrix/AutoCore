// =============================================================================
// FUN_008136b0
// -----------------------------------------------------------------------------
// Stable ID: aa_008136b0
// Address:   0x008136b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008136b0 @ 0x008136b0
// Stable ID: aa_008136b0
// Embedded strings (evidence for future rename):
//   - "Failed to drop the item, get a programmer!"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: Client_RefreshOpenMissionUiWindows, FUN_007fc150, FUN_007fdfb0, FUN_008136b0, FUN_0092ce90, FUN_009440e0.
//  - Strings: "Failed to drop the item, get a programmer!".
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

void __fastcall FUN_008136b0(uint32_t /* width from decompiler */ param_1)



{

  int in_EAX;

  int iVar1;

  

  iVar1 = CVOGReaction_ResolveObjectTarget

                    (1,*(uint32_t /* width from decompiler */ *)(in_EAX + 8),*(uint32_t /* width from decompiler */ *)(in_EAX + 0xc));

  if (iVar1 != 0) {

    if (*(char *)(in_EAX + 0x30) == '\0') {

      FUN_007fdfb0(param_1,"Failed to drop the item, get a programmer!",0xffffffff,1,0);

      return;

    }

    FUN_009440e0(iVar1,1,0,0xffffffff,0xffffffff);

    FUN_007fc150();

    Client_RefreshOpenMissionUiWindows(param_1);

    FUN_0092ce90();

  }

  return;

}
