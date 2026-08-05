// =============================================================================
// Named_AllocateNewObjectFromCbidFailed_008120d0
// -----------------------------------------------------------------------------
// Stable ID: aa_008120d0
// Address:   0x008120d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_AllocateNewObjectFromCbidFailed_008120d0 @ 0x008120d0
// Stable ID: aa_008120d0
// Embedded strings (evidence for future rename):
//   - "allocatenewobjectfromcbid failed %d Get a programmer"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~43 non-empty decompiler lines.
//  - Control keywords: if×5, return×2.
//  - Notable callees: CONCAT31×2, block×2, CVOGReaction_GiveItemByCbid, FUN_007a4480, FUN_007fb2b0, FUN_008024d0, Named_AllocateNewObjectFromCbidFailed_008120d0, FUN_009972a0.
//  - Strings: "allocatenewobjectfromcbid failed %d Get a programmer".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "allocatenewobjectfromcbid failed %d Get a programmer"
 * Domain alias of FUN_008120d0 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Removing unreachable block (ram,0x0081229e) */

/* WARNING: Removing unreachable block (ram,0x008122a7) */



int * Named_AllocateNewObjectFromCbidFailed_008120d0(int param_1,int param_2)



{

  int *piVar1;

  uint uVar2;

  uint unaff_EBP;

  uint uVar3;

  

  piVar1 = (int *)CVOGReaction_GiveItemByCbid(*(int *)(param_2 + 4));

  if (piVar1 != (int *)0x0) {

    (**(code **)(*piVar1 + 8))(*(uint32_t /* width from decompiler */ *)(param_2 + 4),*(uint32_t /* width from decompiler */ *)(param_1 + 0xe04),0);

    (**(code **)(*piVar1 + 0x1cc))();

    uVar2 = 0;

    if (((((*(uint *)(param_2 + 8) & *(uint *)(param_2 + 0xc)) == 0xffffffff) &&

         (*(char *)(param_2 + 0xa8) == '\0')) && (*(char *)(param_2 + 0xa7) == '\0')) &&

       (*(char *)(param_2 + 0xa0) == '\0')) {

      uVar2 = 1;

    }

    uVar3 = unaff_EBP & 0xffffff00;

    piVar1[0x61] = piVar1[0x61] ^ (uVar2 ^ piVar1[0x61]) & 1;

    if (((*(uint *)(param_2 + 8) & *(uint *)(param_2 + 0xc)) != 0xffffffff) ||

       ((((*(char *)(param_2 + 0xc0) == '\0' && (*(char *)(param_2 + 0xa8) == '\0')) &&

         ((*(char *)(param_2 + 0xa7) == '\0' && (*(char *)(param_2 + 0xa2) == '\0')))) &&

        ((*(char *)(param_2 + 0xa0) == '\0' || (*(char *)(*(int *)(param_1 + 0xe04) + 0xf5) == '\0')

         ))))) {

      uVar3 = CONCAT31((int3)(unaff_EBP >> 8),1);

    }

    (**(code **)(*piVar1 + 0xc4))

              (param_2,2,*(uint32_t /* width from decompiler */ *)(param_1 + 0xe04),

               CONCAT31((int3)(uVar3 >> 8),*(char *)(param_2 + 0xa1) == '\0'),uVar3,uVar3);

    if (*(char *)(param_2 + 0xa1) != '\0') {

      FUN_009972a0();

      FUN_008024d0(param_1,DAT_00d1d86c,DAT_00d1d870,0,0,0,piVar1[0x58],piVar1[0x59]);

    }

    if (*(char *)(param_2 + 0xc0) != '\0') {

      FUN_007fb2b0(piVar1[0x58],piVar1[0x59]);

    }

    return piVar1;

  }

  FUN_007a4480(1,"allocatenewobjectfromcbid failed %d Get a programmer",*(uint32_t /* width from decompiler */ *)(param_2 + 4)

              );

  return (int *)0x0;

}
