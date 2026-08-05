// =============================================================================
// FUN_0080fea0
// -----------------------------------------------------------------------------
// Stable ID: aa_0080fea0
// Address:   0x0080fea0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0080fea0 @ 0x0080fea0
// Stable ID: aa_0080fea0
// Embedded strings (evidence for future rename):
//   - "The server is not accepting logins at this time. Please try again in a few moments..."
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_007a69d0, FUN_007a6de0, FUN_007fdfb0, FUN_0080fea0, FUN_00920050, FUN_00937560.
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

void FUN_0080fea0(int param_1)



{

  int in_EAX;

  uint32_t /* width from decompiler */ uVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ uVar4;

  

  FUN_007a69d0();

  if (*(char *)(param_1 + 4) == '\0') {

    uVar4 = 0;

    uVar3 = 1;

    uVar2 = 0xffffffff;

    uVar1 = FUN_007a6de0("The server is not accepting logins at this time. Please try again in a few moments..."

                         ,0xffffffff);

    FUN_007fdfb0(in_EAX,uVar1,uVar2,uVar3,uVar4);

  }

  else {

    FUN_00937560(in_EAX);

    if (*(int *)(in_EAX + 0xf38) != 0) {

      FUN_00920050();

      return;

    }

  }

  return;

}
