// =============================================================================
// FUN_00782d00
// -----------------------------------------------------------------------------
// Stable ID: aa_00782d00
// Address:   0x00782d00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00782d00 @ 0x00782d00
// Stable ID: aa_00782d00
// Embedded strings (evidence for future rename):
//   - "This [ Parent || Left (count) | Right (count) ]\n"
//   - "Item: %i. [ %i || %i (%i) | %i (%i)]\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~68 non-empty decompiler lines.
//  - Control keywords: if×9, return×4, while×3, for×2.
//  - Notable callees: FUN_00782a90×2, i×2, printf×2, FUN_00782d00, Left, Right.
//  - Strings: "This [ Parent || Left (count) | Right (count) ]\n"; "Item: %i. [ %i || %i (%i) | %i (%i)]\n".
//  - Return sites: 4.

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

void FUN_00782d00(void)



{

  int iVar1;

  int in_EAX;

  uint32_t /* width from decompiler */ uVar2;

  int iVar3;

  uint32_t /* width from decompiler */ uVar4;

  int iVar5;

  uint32_t /* width from decompiler */ uVar6;

  uint32_t /* width from decompiler */ local_4;

  

  iVar5 = *(int *)(in_EAX + 4);

  if (iVar5 == 0) {

    iVar5 = 0;

  }

  else {

    for (iVar1 = *(int *)(iVar5 + 0xc); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0xc)) {

      iVar5 = iVar1;

    }

  }

  printf("This [ Parent || Left (count) | Right (count) ]\n");

  while( true ) {

    while( true ) {

      if (iVar5 == 0) {

        return;

      }

      uVar6 = 0;

      if (*(int *)(iVar5 + 8) == 0) {

        local_4 = 0;

      }

      else {

        local_4 = *(uint32_t /* width from decompiler */ *)(*(int *)(iVar5 + 8) + 0x14);

      }

      if (*(int *)(iVar5 + 0xc) == 0) {

        uVar4 = 0;

      }

      else {

        uVar4 = *(uint32_t /* width from decompiler */ *)(*(int *)(iVar5 + 0xc) + 0x14);

      }

      if (*(int *)(iVar5 + 0x10) != 0) {

        uVar6 = *(uint32_t /* width from decompiler */ *)(*(int *)(iVar5 + 0x10) + 0x14);

      }

      uVar2 = FUN_00782a90();

      uVar2 = FUN_00782a90(local_4,uVar2);

      printf("Item: %i. [ %i || %i (%i) | %i (%i)]\n",*(uint32_t /* width from decompiler */ *)(iVar5 + 0x14),uVar6,uVar4,

             uVar2);

      iVar1 = *(int *)(iVar5 + 8);

      if (iVar1 == 0) break;

      iVar5 = iVar1;

      for (iVar1 = *(int *)(iVar1 + 0xc); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0xc)) {

        iVar5 = iVar1;

      }

    }

    iVar1 = *(int *)(iVar5 + 0x10);

    if (iVar1 == 0) break;

    if (iVar1 == 0) {

      return;

    }

    while (iVar3 = iVar1, iVar5 != *(int *)(iVar3 + 0xc)) {

      iVar1 = *(int *)(iVar3 + 0x10);

      iVar5 = iVar3;

      if (*(int *)(iVar3 + 0x10) == 0) {

        return;

      }

    }

    iVar5 = *(int *)(iVar5 + 0x10);

  }

  return;

}
