// =============================================================================
// FUN_0083dae0
// -----------------------------------------------------------------------------
// Stable ID: aa_0083dae0
// Address:   0x0083dae0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0083dae0 @ 0x0083dae0
// Stable ID: aa_0083dae0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~55 non-empty decompiler lines.
//  - Control keywords: if×7, return×1.
//  - Notable callees: FUN_0040ac40, FUN_0083dae0, sprintf.
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

void FUN_0083dae0(void)



{

  ushort uVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint uVar4;

  int unaff_ESI;

  float fStack_20;

  float fStack_1c;

  float fStack_18;

  float fStack_14;

  char acStack_10 [16];

  

  if ((*(int **)(unaff_ESI + 0x500) == (int *)0x0) ||

     (iVar2 = (**(code **)(**(int **)(unaff_ESI + 0x500) + 0x25c))(),

     *(int *)(unaff_ESI + 0x4fc) <= iVar2)) {

    if (*(int *)(unaff_ESI + 0x4fc) < 0) {

      *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x4fc) = 0;

    }

    else if (*(int *)(unaff_ESI + 0x500) != 0) {

      iVar2 = *(int *)(*(int *)(unaff_ESI + 0x500) + 0xa8);

      if (*(int *)(iVar2 + 0x38) == 4) {

        uVar4 = 999999;

      }

      else {

        uVar1 = *(ushort *)(*(int *)(iVar2 + 0x3c) + 0x4ba);

        uVar4 = (uint)uVar1;

        if (uVar1 == 0) {

          uVar4 = 200;

        }

      }

      if ((int)(uVar4 & 0xffff) < *(int *)(unaff_ESI + 0x4fc)) {

        uVar4 = FUN_0040ac40();

        *(uint *)(unaff_ESI + 0x4fc) = uVar4 & 0xffff;

      }

    }

  }

  else {

    uVar3 = (**(code **)(**(int **)(unaff_ESI + 0x500) + 0x25c))();

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x4fc) = uVar3;

  }

  sprintf(acStack_10,"%i",*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x4fc));

  fStack_20 = g_flOne;

  if ((*(int **)(unaff_ESI + 0x500) != (int *)0x0) &&

     (iVar2 = (**(code **)(**(int **)(unaff_ESI + 0x500) + 0x25c))(), fStack_20 = g_flOne,

     *(int *)(unaff_ESI + 0x4fc) == iVar2)) {

    fStack_20 = 0.0;

  }

  fStack_1c = g_flOne;

  fStack_18 = fStack_20;

  fStack_14 = g_flOne;

  (**(code **)(**(int **)(unaff_ESI + 0x510) + 0x158))(1,&fStack_20);

  (**(code **)(**(int **)(unaff_ESI + 0x510) + 0x3ac))(&fStack_18);

  (**(code **)(**(int **)(unaff_ESI + 0x510) + 0x34c))();

  return;

}
