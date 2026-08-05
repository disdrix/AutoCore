// =============================================================================
// FUN_009347b0
// -----------------------------------------------------------------------------
// Stable ID: aa_009347b0
// Address:   0x009347b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009347b0 @ 0x009347b0
// Stable ID: aa_009347b0
// Embedded strings (evidence for future rename):
//   - "Sending stage 2 for %I64d"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: if×6, for×1, return×1.
//  - Notable callees: FUN_007a4480, FUN_009347b0.
//  - Strings: "Sending stage 2 for %I64d".
//  - Return sites: 1.

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

void FUN_009347b0(void)



{

  char cVar1;

  int unaff_ESI;

  uint32_t /* width from decompiler */ uStack_10;

  uint32_t /* width from decompiler */ uStack_c;

  uint32_t /* width from decompiler */ uStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  *(uint8_t *)(*(int *)(unaff_ESI + 0xe04) + 0x81) = 0;

  if (*(int *)(unaff_ESI + 0xc78) != 0) {

    cVar1 = (**(code **)(**(int **)(unaff_ESI + 0xc78) + 8))();

    if (cVar1 != '\0') {

      (**(code **)(**(int **)(unaff_ESI + 0xc78) + 0x10))();

    }

  }

  FUN_007a4480(0xffffffff,"Sending stage 2 for %I64d",*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x508),

               *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x50c));

  uStack_8 = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x508);

  uStack_4 = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x50c);

  uStack_10 = 0x2001;

  if (*(char *)(unaff_ESI + 0x113) == '\0') {

    uStack_c = 0;

  }

  else {

    uStack_c = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x134);

  }

  if (*(int *)(unaff_ESI + 0xc78) != 0) {

    (**(code **)(**(int **)(unaff_ESI + 0xc78) + 0x18))(0xffffffff,&uStack_10,0x10,0);

    if (*(int *)(unaff_ESI + 0xc78) != 0) {

      cVar1 = (**(code **)(**(int **)(unaff_ESI + 0xc78) + 8))();

      if (cVar1 != '\0') {

        (**(code **)(**(int **)(unaff_ESI + 0xc78) + 0x10))();

      }

    }

  }

  return;

}
