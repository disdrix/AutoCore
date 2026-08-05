// =============================================================================
// FUN_008b82d0
// -----------------------------------------------------------------------------
// Stable ID: aa_008b82d0
// Address:   0x008b82d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008b82d0 @ 0x008b82d0
// Stable ID: aa_008b82d0
// Embedded strings (evidence for future rename):
//   - "Drop An Item Here To Send"
//   - "Click Here To Remove Item"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~53 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_007a69d0×2, FUN_007a6de0×2, FUN_0085d970, FUN_008b82d0.
//  - Strings: "Drop An Item Here To Send"; "Click Here To Remove Item".
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

void FUN_008b82d0(void)



{

  int *in_EAX;

  uint32_t /* width from decompiler */ uVar1;

  int iVar2;

  int unaff_ESI;

  char *pcVar3;

  uint8_t *puStack_114;

  uint8_t local_104 [260];

  

  if (*(int *)(unaff_ESI + 0x594) != 0) {

    if (in_EAX == (int *)0x0) {

      puStack_114 = (uint8_t *)0x8b83e3;

      (**(code **)(**(int **)(unaff_ESI + 0x594) + 0x58))();

      iVar2 = **(int **)(unaff_ESI + 0x594);

      puStack_114 = (uint8_t *)0x1;

      uVar1 = 0xffffffff;

      pcVar3 = "Drop An Item Here To Send";

      FUN_007a69d0("Drop An Item Here To Send",0xffffffff,1);

      uVar1 = FUN_007a6de0(pcVar3,uVar1);

      (**(code **)(iVar2 + 0x1d8))(uVar1);

      puStack_114 = (uint8_t *)0xffffff;

      (**(code **)(**(int **)(unaff_ESI + 0x594) + 0x15c))(0,&puStack_114);

    }

    else {

      puStack_114 = local_104;

      FUN_0085d970();

      iVar2 = **(int **)(unaff_ESI + 0x594);

      puStack_114 = (uint8_t *)0x0;

      uVar1 = (**(code **)(**(int **)(unaff_ESI + 0x594) + 0x2c8))();

      (**(code **)(iVar2 + 0x50))(local_104,uVar1);

      puStack_114 = (uint8_t *)0xffffffff;

      (**(code **)(**(int **)(unaff_ESI + 0x594) + 0x15c))(0,&puStack_114);

      iVar2 = **(int **)(unaff_ESI + 0x594);

      uVar1 = 0xffffffff;

      pcVar3 = "Click Here To Remove Item";

      FUN_007a69d0("Click Here To Remove Item",0xffffffff,1,1);

      uVar1 = FUN_007a6de0(pcVar3,uVar1);

      (**(code **)(iVar2 + 0x1d8))(uVar1);

      if ((*(int *)(unaff_ESI + 0x588) != 0) &&

         ((iVar2 = (**(code **)(**(int **)(unaff_ESI + 0x588) + 0x1dc))(), iVar2 == 0 ||

          (pcVar3 = (char *)(**(code **)(**(int **)(unaff_ESI + 0x588) + 0x1dc))(), *pcVar3 == '\0')

          ))) {

        iVar2 = **(int **)(unaff_ESI + 0x588);

        uVar1 = (**(code **)(*in_EAX + 0x15c))();

        (**(code **)(iVar2 + 0x3ac))(uVar1);

        (**(code **)(**(int **)(unaff_ESI + 0x588) + 0x34c))();

      }

    }

    (**(code **)(**(int **)(unaff_ESI + 0x594) + 0x34c))();

    return;

  }

  return;

}
