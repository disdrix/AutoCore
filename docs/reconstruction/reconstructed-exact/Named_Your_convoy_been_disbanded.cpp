// =============================================================================
// Named_Your_convoy_been_disbanded
// -----------------------------------------------------------------------------
// Stable ID: aa_008118e0
// Address:   0x008118e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_Your_convoy_been_disbanded @ 0x008118e0
// Stable ID: aa_008118e0
// Embedded strings (evidence for future rename):
//   - "Your convoy has been disbanded."
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: FUN_0066e8d0, FUN_007a69d0, FUN_007a6de0, Named_Your_convoy_been_disbanded, FUN_008f8200, FUN_0094cc00, FUN_0094dab0.
//  - Strings: "Your convoy has been disbanded.".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "Your convoy has been disbanded."
 * Domain alias of FUN_008118e0 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_Your_convoy_been_disbanded(void)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ uVar3;

  int unaff_ESI;

  

  uVar2 = FUN_007a69d0();

  if (*(uint32_t /* width from decompiler */ **)(unaff_ESI + 0xdf4) != *(uint32_t /* width from decompiler */ **)(unaff_ESI + 0xdf8)) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)**(uint32_t /* width from decompiler */ **)(unaff_ESI + 0xdf4));

  }

  if ((*(int **)(unaff_ESI + 0xf40) != (int *)0x0) && (**(int **)(unaff_ESI + 0xf40) != 0)) {

    uVar3 = FUN_007a6de0("Your convoy has been disbanded.",0xffffffff);

    if (DAT_00d1b8dc != 0) {

      FUN_008f8200(DAT_00d1b8dc,6,&DAT_00a156cc,uVar3,0);

    }

  }

  FUN_0094dab0(uVar2);

  FUN_0066e8d0();

  iVar1 = *(int *)(unaff_ESI + 0x10a0);

  if ((iVar1 != 0) && (DAT_00d1775e = 0, *(int *)(iVar1 + 0x5b4) != 0)) {

    (**(code **)(**(int **)(iVar1 + 0x5b4) + 0x3c8))(0,1);

  }

  FUN_0094cc00();

  return;

}
