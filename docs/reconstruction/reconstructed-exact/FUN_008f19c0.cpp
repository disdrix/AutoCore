// =============================================================================
// FUN_008f19c0
// -----------------------------------------------------------------------------
// Stable ID: aa_008f19c0
// Address:   0x008f19c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008f19c0 @ 0x008f19c0
// Stable ID: aa_008f19c0
// Embedded strings (evidence for future rename):
//   - "Creation Fee: "
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_007a69d0, FUN_007a6de0, FUN_008f19c0, FUN_00977a30.
//  - Strings: "Creation Fee: ".
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

void FUN_008f19c0(void)



{

  int iVar1;

  int unaff_EDI;

  char *pcVar2;

  uint32_t /* width from decompiler */ uVar3;

  

  if (*(int *)(unaff_EDI + 0x548) != 0) {

    (**(code **)(**(int **)(unaff_EDI + 0x548) + 0x268))();

    iVar1 = **(int **)(unaff_EDI + 0x548);

    uVar3 = 0xffffffff;

    pcVar2 = "Creation Fee: ";

    FUN_007a69d0("Creation Fee: ",0xffffffff);

    uVar3 = FUN_007a6de0(pcVar2,uVar3);

    (**(code **)(iVar1 + 0x250))(uVar3);

    FUN_00977a30(DAT_00d1ad30,10000,0);

                    /* WARNING: Could not recover jumptable at 0x008f1a24. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    (**(code **)(**(int **)(unaff_EDI + 0x548) + 0x34c))();

    return;

  }

  return;

}
