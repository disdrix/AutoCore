// =============================================================================
// FUN_00553010
// -----------------------------------------------------------------------------
// Stable ID: aa_00553010
// Address:   0x00553010  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00553010 @ 0x00553010
// Stable ID: aa_00553010
// Embedded strings (evidence for future rename):
//   - "Next Rank"
//   - "%s: %s\n"
//   - "%s: %d %s\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_007a6de0×4, sprintf×2, FUN_00553010, FUN_007a69d0.
//  - Strings: "Next Rank"; "%s: %s\n"; "%s: %d %s\n".
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

void __thiscall FUN_00553010(int param_1,char *param_2)



{

  short sVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ uVar3;

  int iVar4;

  

  FUN_007a69d0();

  sVar1 = *(short *)(param_1 + 2);

  if (sVar1 == 0) {

    uVar2 = FUN_007a6de0(&DAT_009d2524,0xffffffff);

    uVar3 = FUN_007a6de0("Next Rank",0xffffffff);

    sprintf(param_2,"%s: %s\n",uVar3,uVar2);

    return;

  }

  uVar2 = FUN_007a6de0(&DAT_00a4abd0,0xffffffff);

  iVar4 = (int)sVar1;

  uVar3 = FUN_007a6de0("Next Rank",0xffffffff);

  sprintf(param_2,"%s: %d %s\n",uVar3,iVar4,uVar2);

  return;

}
