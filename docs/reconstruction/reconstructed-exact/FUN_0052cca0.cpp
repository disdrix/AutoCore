// =============================================================================
// FUN_0052cca0
// -----------------------------------------------------------------------------
// Stable ID: aa_0052cca0
// Address:   0x0052cca0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0052cca0 @ 0x0052cca0
// Stable ID: aa_0052cca0
// Embedded strings (evidence for future rename):
//   - "HashError:TraversalLock, already locked for traversal"
//   - "VOG_DEBUG_STOP"
//   - "HashError:TraverseToNext, not locked for traversal"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~112 non-empty decompiler lines.
//  - Control keywords: if×19, return×8, while×3, goto×2, for×2, do×1.
//  - Notable callees: CNDHash_LookupByKey×5, FUN_007a4480×4, FUN_0052cca0, FUN_0053fff0, FUN_00541a80.
//  - Strings: "HashError:TraversalLock, already locked for traversal"; "VOG_DEBUG_STOP"; "HashError:TraverseToNext, not locked for traversal".
//  - Return sites: 8.

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

uint __thiscall FUN_0052cca0(int param_1,uint param_2)



{

  byte bVar1;

  void *this;

  int iVar2;

  void *pvVar3;

  int iVar4;

  uint uVar5;

  void *pvVar6;

  int iVar7;

  int *piVar8;

  

  iVar2 = FUN_00541a80();

  iVar2 = *(int *)(*(int *)(*(int *)(iVar2 + 0x10) + (*(uint *)(iVar2 + 8) & param_2) * 4) + 4);

  if (iVar2 == 0) {

LAB_0052ccda:

    iVar2 = 0;

  }

  else {

    do {

      if (param_2 == *(uint *)(iVar2 + 0x10)) {

        if (iVar2 == 0) goto LAB_0052ccda;

        iVar2 = *(int *)(iVar2 + 8);

        goto LAB_0052cce1;

      }

      iVar2 = *(int *)(iVar2 + 0xc);

    } while (iVar2 != 0);

    iVar2 = 0;

  }

LAB_0052cce1:

  if (iVar2 == 0) {

    return 1;

  }

  if ((*(int *)(iVar2 + 0x10) != 0) && (uVar5 = *(uint *)(iVar2 + 0x140), uVar5 != 0xffffffff)) {

    if (((*(int *)(iVar2 + 0x18) == 0) && (*(char *)(param_1 + 0x4ff) != '\0')) &&

       ((uVar5 == 0xfffffffe ||

        (pvVar3 = CNDHash_LookupByKey(*(void **)(param_1 + 0x538),uVar5), pvVar3 != (void *)0x0))))

    {

      return 3;

    }

    return *(byte *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c)

                    + 0x532) + 4;

  }

  iVar4 = *(int *)(param_1 + 0x548);

  iVar7 = 0;

  if (*(char *)(iVar4 + 0x1d) != '\0') {

    FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

    FUN_007a4480(0,"VOG_DEBUG_STOP");

  }

  *(uint8_t *)(iVar4 + 0x1d) = 1;

  while( true ) {

    iVar4 = *(int *)(param_1 + 0x548);

    if (*(char *)(iVar4 + 0x1d) == '\0') {

      FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    if (iVar7 == 0) {

      iVar7 = *(int *)(iVar4 + 0x14);

    }

    else {

      iVar7 = *(int *)(iVar7 + 0x14);

    }

    if (iVar7 == 0) {

      iVar4 = 0;

    }

    else {

      iVar4 = *(int *)(iVar7 + 8);

    }

    if (iVar4 == 0) break;

    if (*(uint *)(iVar4 + 0x120) == param_2) {

      uVar5 = (uint)*(byte *)(iVar4 + 0x124);

      if (uVar5 == 0) {

        uVar5 = 1;

      }

      *(uint8_t *)(*(int *)(param_1 + 0x548) + 0x1d) = 0;

      return uVar5;

    }

  }

  *(uint8_t *)(*(int *)(param_1 + 0x548) + 0x1d) = 0;

  uVar5 = *(uint *)(iVar2 + 0xa8);

  param_2 = 1;

  if (uVar5 != 0xffffffff) {

    iVar2 = FUN_0053fff0();

    if ((*(void **)(iVar2 + 4) != (void *)0x0) &&

       (pvVar3 = CNDHash_LookupByKey(*(void **)(iVar2 + 4),uVar5), pvVar3 != (void *)0x0)) {

      uVar5 = **(uint **)((int)pvVar3 + 0x14c);

      pvVar6 = CNDHash_LookupByKey(*(void **)(param_1 + 0x538),uVar5);

      if (pvVar6 == (void *)0x0) {

        pvVar6 = CNDHash_LookupByKey(*(void **)(param_1 + 0x540),uVar5);

        if (pvVar6 == (void *)0x0) {

          return 1;

        }

        bVar1 = *(byte *)((int)pvVar6 + 0x130);

        iVar2 = 0;

        if (bVar1 == 0) {

          return 1;

        }

        this = *(void **)(param_1 + 0x548);

        piVar8 = *(int **)((int)pvVar6 + 0x13c);

        while ((pvVar6 = CNDHash_LookupByKey(this,*(uint *)(*piVar8 + 0x10)), pvVar6 == (void *)0x0

               || (*(byte *)((int)pvVar6 + 0x14) <= *(byte *)((int)pvVar3 + 0x14)))) {

          iVar2 = iVar2 + 1;

          piVar8 = piVar8 + 1;

          if ((int)(uint)bVar1 <= iVar2) {

            return 1;

          }

        }

      }

      param_2 = 2;

    }

  }

  return param_2;

}
