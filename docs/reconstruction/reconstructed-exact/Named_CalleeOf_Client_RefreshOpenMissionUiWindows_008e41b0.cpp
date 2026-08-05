// =============================================================================
// Named_CalleeOf_Client_RefreshOpenMissionUiWindows_008e41b0
// -----------------------------------------------------------------------------
// Stable ID: aa_008e41b0
// Callee of Client_RefreshOpenMissionUiWindows
// Address:   0x008e41b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_RefreshOpenMissionUiWindows: mission/objective helper. Evidence string: "Chance of Success". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "Chance of Success"
//   - "\n%s: 0%%"
//   - "\n%s: %.1f%%"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~84 non-empty decompiler lines.
//  - Control keywords: if×8, return×3, do×1, while×1.
//  - Notable callees: FUN_007a69d0×3, FUN_007a6de0×3, sprintf×3, FUN_0040f4e0, FUN_005202d0, FUN_00520340, FUN_00522860, FUN_0052d450.
//  - Strings: "Complexity"; "%s: %i/%i"; "Chance of Success"; "\n%s: 0%%".
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Client_RefreshOpenMissionUiWindows
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_CalleeOf_Client_RefreshOpenMissionUiWindows_008e41b0(void)



{

  uint uVar1;

  char cVar2;

  int in_EAX;

  int iVar3;

  uint uVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint32_t /* width from decompiler */ uVar6;

  uint uVar7;

  int iVar8;

  float10 fVar9;

  char *pcVar10;

  uint32_t /* width from decompiler */ uVar11;

  uint64_t uVar12;

  uint32_t /* width from decompiler */ *puStack_114;

  int iStack_110;

  char acStack_104 [4];

  char acStack_100 [256];

  

  if (*(int *)(in_EAX + 0x7cc) != 0) {

    iVar8 = 0;

    iVar3 = (**(code **)(**(int **)(in_EAX + 0x7cc) + 0x60))();

    if (0 < iVar3) {

      iStack_110 = in_EAX + 0x550;

      do {

        uVar4 = (**(code **)(**(int **)(in_EAX + 0x7cc) + 0x5c))(iVar8);

        if ((uVar4 & 0xffff) == 0xffffffff) {

          uVar5 = FUN_00520340(iVar8 + 1);

          uVar6 = FUN_008e4020();

          uVar11 = 0xffffffff;

          pcVar10 = "Complexity";

          FUN_007a69d0("Complexity",0xffffffff,uVar6,uVar5);

          uVar5 = FUN_007a6de0(pcVar10,uVar11);

          sprintf(acStack_104,"%s: %i/%i",uVar5);

          (**(code **)(*(int *)*puStack_114 + 0x1d8))(acStack_104,1,1);

          (**(code **)(*(int *)*puStack_114 + 0x15c))(1,&stack0xfffffedc);

          (**(code **)(*(int *)*puStack_114 + 0x34c))();

          iVar8 = iStack_110;

        }

        puStack_114 = puStack_114 + 1;

        iVar8 = iVar8 + 1;

        iVar3 = (**(code **)(**(int **)(in_EAX + 0x7cc) + 0x60))();

        iStack_110 = iVar8;

      } while (iVar8 < iVar3);

    }

    if ((*(char *)(in_EAX + 0x7e1) != '\0') &&

       (cVar2 = FUN_0052d450(*(uint32_t /* width from decompiler */ *)(in_EAX + 0x7cc),acStack_104), cVar2 != '\0')) {

      iVar8 = *(int *)(in_EAX + 0x7cc);

      if ((iVar8 != 0) &&

         (cVar2 = FUN_005202d0(*(uint32_t /* width from decompiler */ *)(iVar8 + 0x160),*(uint32_t /* width from decompiler */ *)(iVar8 + 0x164)),

         cVar2 != '\0')) {

        uVar4 = *(uint *)(DAT_00d1b6d8 + 0x720);

        uVar1 = *(uint *)(DAT_00d1b6d8 + 0x728);

        iVar8 = (*(int *)(DAT_00d1b6d8 + 0x724) - *(int *)(DAT_00d1b6d8 + 0x72c)) -

                (uint)(uVar4 < *(uint *)(DAT_00d1b6d8 + 0x728));

        uVar7 = FUN_0040f4e0();

        if (iVar8 < (int)uVar7 >> 0x1f) {

          return;

        }

        if ((iVar8 <= (int)uVar7 >> 0x1f) && (uVar4 - uVar1 < uVar7)) {

          return;

        }

      }

      FUN_008e40f0();

      if (*(char *)(in_EAX + 0x7d8) == '\0') {

        uVar12 = 0xffffffff00a3ade8;

        FUN_007a69d0("Chance of Success");

        FUN_007a6de0(uVar12);

        sprintf(acStack_100,"\n%s: 0%%");

      }

      else {

        fVar9 = (float10)FUN_00522860();

        uVar5 = 0xffffffff;

        pcVar10 = "Chance of Success";

        FUN_007a69d0("Chance of Success",0xffffffff,(double)(fVar9 * (float10)DAT_00aaa7ac));

        uVar5 = FUN_007a6de0(pcVar10,uVar5);

        sprintf(acStack_100,"\n%s: %.1f%%",uVar5);

      }

      (**(code **)(**(int **)(in_EAX + 0x528) + 0x1d8))(acStack_100,1,1);

      (**(code **)(**(int **)(in_EAX + 0x528) + 0x34c))();

    }

  }

  return;

}
