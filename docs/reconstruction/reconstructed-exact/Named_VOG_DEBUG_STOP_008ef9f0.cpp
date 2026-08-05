// READABILITY (auto CF):
//  - Body size: ~71 non-empty decompiler lines.
//  - Control keywords: if×11, goto×4, while×2, for×2, do×1, return×1.
//  - Notable callees: FUN_007a4480×4, FUN_0040e490×2, CONCAT31, FUN_00541a80, FUN_008ef7d0, FUN_008ef9f0.
//  - Strings: "HashError:TraversalLock, already locked for traversal"; "VOG_DEBUG_STOP"; "HashError:TraverseToNext, not locked for traversal".
//  - Return sites: 1.

// =============================================================================
// Named_VOG_DEBUG_STOP_008ef9f0
// -----------------------------------------------------------------------------
// Stable ID: aa_008ef9f0
// Address:   0x008ef9f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "VOG_DEBUG_STOP"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall Named_VOG_DEBUG_STOP_008ef9f0(int *param_1)



{

  uint uVar1;

  int iVar2;

  uint *puVar3;

  uint uVar4;

  int iVar5;

  

  iVar2 = FUN_0040e490(param_1 + 0x16c);

  while (iVar2 != 0) {

    (**(code **)(*param_1 + 0xbc))(iVar2);

    iVar2 = FUN_0040e490(param_1 + 0x16c);

  }

  if (DAT_00d1b6d8 != 0) {

    iVar2 = *(int *)(DAT_00d1b6d8 + 0x534);

    iVar5 = 0;

    if (*(char *)(iVar2 + 0x1d) != '\0') {

      FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    *(uint8_t *)(iVar2 + 0x1d) = 1;

LAB_008efa60:

    iVar2 = *(int *)(DAT_00d1b6d8 + 0x534);

    if (*(char *)(iVar2 + 0x1d) == '\0') {

      FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    if (iVar5 == 0) {

      iVar5 = *(int *)(iVar2 + 0x14);

      if (iVar5 == 0) goto LAB_008efaa8;

      puVar3 = *(uint **)(iVar5 + 8);

    }

    else {

      iVar5 = *(int *)(iVar5 + 0x14);

      if (iVar5 == 0) {

LAB_008efaa8:

        puVar3 = (uint *)0x0;

      }

      else {

        puVar3 = *(uint **)(iVar5 + 8);

      }

    }

    if (puVar3 != (uint *)0x0) {

      uVar1 = *puVar3;

      iVar2 = FUN_00541a80();

      uVar4 = *(uint *)(iVar2 + 8) & uVar1;

      iVar2 = *(int *)(*(int *)(*(int *)(iVar2 + 0x10) + uVar4 * 4) + 4);

      if (iVar2 == 0) {

LAB_008efae2:

        iVar2 = 0;

      }

      else {

        do {

          if (uVar1 == *(uint *)(iVar2 + 0x10)) {

            if (iVar2 == 0) goto LAB_008efae2;

            iVar2 = *(int *)(iVar2 + 8);

            goto LAB_008efae9;

          }

          iVar2 = *(int *)(iVar2 + 0xc);

        } while (iVar2 != 0);

        iVar2 = 0;

      }

LAB_008efae9:

      if (iVar2 != 0) {

        FUN_008ef7d0(param_1,CONCAT31((int3)(uVar4 >> 8),(char)puVar3[1]));

      }

      goto LAB_008efa60;

    }

    *(uint8_t *)(*(int *)(DAT_00d1b6d8 + 0x534) + 0x1d) = 0;

  }

  return;

}
