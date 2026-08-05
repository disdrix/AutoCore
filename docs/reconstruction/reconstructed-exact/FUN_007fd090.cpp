// =============================================================================
// FUN_007fd090
// -----------------------------------------------------------------------------
// Stable ID: aa_007fd090
// Address:   0x007fd090  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007fd090 @ 0x007fd090
// Stable ID: aa_007fd090
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~53 non-empty decompiler lines.
//  - Control keywords: if×6, return×2, goto×1.
//  - Notable callees: FUN_007fb990, FUN_007fc6c0, FUN_007fd090, FUN_0092f000.
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

void FUN_007fd090(void)



{

  int *piVar1;

  char cVar2;

  int in_EAX;

  char *unaff_EDI;

  uint32_t /* width from decompiler */ **ppuVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint32_t /* width from decompiler */ *puStack_18;

  uint32_t /* width from decompiler */ uStack_10;

  int iStack_c;

  

  if (*(int *)(in_EAX + 0x1144) != 0) {

    if ((unaff_EDI != (char *)0x0) && (*unaff_EDI != '\0')) {

      iStack_c = 0x7fd0c0;

      cVar2 = (**(code **)(**(int **)(in_EAX + 0x1168) + 0xd0))();

      if (cVar2 != '\0') {

        iStack_c = *(int *)(in_EAX + 0x1144);

        piVar1 = *(int **)(iStack_c + 0x2b0);

        if (piVar1 != (int *)0x0) {

          if (piVar1 == (int *)**(int **)(in_EAX + 0xf40)) goto LAB_007fd106;

          if (piVar1 != (int *)0x0) {

            uStack_10 = 0x7fd0ef;

            (**(code **)(*piVar1 + 0xb0))();

          }

        }

        iStack_c = *(uint32_t /* width from decompiler */ *)(in_EAX + 0x1144);

        uStack_10 = 0x7fd106;

        (**(code **)(*(int *)**(uint32_t /* width from decompiler */ **)(in_EAX + 0xf40) + 0xa8))();

LAB_007fd106:

        iStack_c = 1;

        uStack_10 = 1;

        puStack_18 = (uint32_t /* width from decompiler */ *)0x7fd119;

        (**(code **)(**(int **)(in_EAX + 0x1144) + 0x1d8))();

        puStack_18 = (uint32_t /* width from decompiler */ *)0x7fd127;

        (**(code **)(**(int **)(in_EAX + 0x1144) + 0x13c))();

        puStack_18 = &uStack_10;

        uStack_10 = 0xffebebeb;

        uVar4 = 1;

        (**(code **)(**(int **)(in_EAX + 0x1144) + 0x15c))(1);

        ppuVar3 = &puStack_18;

        puStack_18 = (uint32_t /* width from decompiler */ *)0x96232323;

        (**(code **)(**(int **)(in_EAX + 0x1144) + 0x15c))(0,ppuVar3);

        (**(code **)(**(int **)(in_EAX + 0x1144) + 0xfc))(1,0x3dcccccd);

        FUN_007fc6c0(ppuVar3,uVar4);

        FUN_0092f000();

        return;

      }

    }

    iStack_c = 0x7fd1ac;

    FUN_007fb990();

  }

  return;

}
