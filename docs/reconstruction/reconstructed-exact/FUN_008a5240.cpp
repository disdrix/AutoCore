// =============================================================================
// FUN_008a5240
// -----------------------------------------------------------------------------
// Stable ID: aa_008a5240
// Address:   0x008a5240  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008a5240 @ 0x008a5240
// Stable ID: aa_008a5240
// Embedded strings (evidence for future rename):
//   - "HashError:TraversalLock, already locked for traversal"
//   - "VOG_DEBUG_STOP"
//   - "HashError:TraverseToNext, not locked for traversal"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~365 non-empty decompiler lines.
//  - Control keywords: if×47, while×9, goto×7, for×6, do×5, return×2.
//  - Notable callees: FUN_007a4480×8, FUN_00419880×3, FUN_0082a8b0×3, CONCAT31×2, FUN_0082a050×2, FUN_00403450, FUN_00541a80, FUN_00547920.
//  - Strings: "HashError:TraversalLock, already locked for traversal"; "VOG_DEBUG_STOP"; "HashError:TraverseToNext, not locked for traversal".
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

void FUN_008a5240(void)



{

  uint32_t /* width from decompiler */ *puVar1;

  void *_Src;

  void **ppvVar2;

  char cVar3;

  int iVar4;

  void *pvVar5;

  int iVar6;

  int *piVar7;

  uint32_t /* width from decompiler */ uVar8;

  int *piVar9;

  uint uVar10;

  int *unaff_EDI;

  int *piStack_2b8;

  int iStack_2b4;

  int iStack_2b0;

  uint uStack_2ac;

  int local_2a8;

  uint32_t /* width from decompiler */ local_2a4;

  int iStack_2a0;

  int *piStack_29c;

  int iStack_298;

  int iStack_294;

  char acStack_218 [520];

  uint32_t /* width from decompiler */ uStack_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009b61c2;

  local_c = ExceptionList;

  uVar10 = 0;

  if (DAT_00d1b6d8 == 0) {

    return;

  }

  local_2a4 = 0;

  local_2a8 = -1;

  ExceptionList = &local_c;

  ppvVar2 = &local_c;

  if (unaff_EDI[0x146] != -1) {

    while( true ) {

      ExceptionList = ppvVar2;

      iVar4 = unaff_EDI[0x169];

      if ((iVar4 == 0) || ((uint)(unaff_EDI[0x16a] - iVar4 >> 2) <= uVar10)) goto LAB_008a52db;

      piVar7 = *(int **)(iVar4 + uVar10 * 4);

      if ((piVar7 != (int *)0x0) &&

         (((piVar7[0x141] != 0 && (*(int *)(piVar7[0x141] + 0x14c) != 0)) &&

          (iVar4 = (**(code **)(*piVar7 + 0x78))(), iVar4 == unaff_EDI[0x146])))) break;

      uVar10 = uVar10 + 1;

      ppvVar2 = ExceptionList;

    }

    local_2a8 = **(int **)(piVar7[0x141] + 0x14c);

  }

LAB_008a52db:

  unaff_EDI[0x146] = -1;

  for (uVar10 = 0;

      (iVar4 = unaff_EDI[0x16d], iVar4 != 0 && (uVar10 < (uint)(unaff_EDI[0x16e] - iVar4 >> 2)));

      uVar10 = uVar10 + 1) {

    cVar3 = (**(code **)(**(int **)(iVar4 + uVar10 * 4) + 0x3d8))();

    if (cVar3 != '\0') {

      (**(code **)(**(int **)(unaff_EDI[0x16d] + uVar10 * 4) + 0x440))();

    }

    (**(code **)(*unaff_EDI + 0xb0))(*(uint32_t /* width from decompiler */ *)(unaff_EDI[0x16d] + uVar10 * 4));

    puVar1 = *(uint32_t /* width from decompiler */ **)(unaff_EDI[0x16d] + uVar10 * 4);

    if (puVar1 != (uint32_t /* width from decompiler */ *)0x0) {

      (**(code **)*puVar1)(1);

    }

    *(uint32_t /* width from decompiler */ *)(unaff_EDI[0x16d] + uVar10 * 4) = 0;

  }

  pvVar5 = (void *)unaff_EDI[0x16d];

  if (pvVar5 != (void *)0x0) {

    _Src = (void *)unaff_EDI[0x16e];

    piStack_2b8 = (int *)((int)_Src - (int)pvVar5 >> 2);

    if ((piStack_2b8 != (int *)0x0) && (pvVar5 != _Src)) {

      pvVar5 = memmove(pvVar5,_Src,0);

      unaff_EDI[0x16e] = (int)pvVar5;

    }

  }

  iVar4 = *(int *)(DAT_00d1b6d8 + 0x548);

  uStack_2ac = 0;

  iStack_2b4 = 0;

  piStack_29c = (int *)CONCAT31(piStack_29c._1_3_,1);

  iStack_294 = 0;

  if (*(char *)(iVar4 + 0x1d) != '\0') {

    FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

    FUN_007a4480(0,"VOG_DEBUG_STOP");

  }

  *(uint8_t *)(iVar4 + 0x1d) = 1;

LAB_008a53e0:

  do {

    iVar4 = *(int *)(DAT_00d1b6d8 + 0x548);

    if (*(char *)(iVar4 + 0x1d) == '\0') {

      FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    if (iStack_2b4 == 0) {

      iStack_2b4 = *(int *)(iVar4 + 0x14);

      if (iStack_2b4 == 0) goto LAB_008a543b;

      iVar4 = *(int *)(iStack_2b4 + 8);

    }

    else {

      iStack_2b4 = *(int *)(iStack_2b4 + 0x14);

      if (iStack_2b4 == 0) {

LAB_008a543b:

        iVar4 = 0;

      }

      else {

        iVar4 = *(int *)(iStack_2b4 + 8);

      }

    }

    if (iVar4 == 0) break;

    cVar3 = FUN_0059dc50(DAT_00d1b6d8);

    if (cVar3 != '\0') {

      FUN_00547920(0);

      iStack_298 = iVar4;

      iStack_2a0 = FUN_0059db80(DAT_00d1b6d8);

      while( true ) {

        if (unaff_EDI[0x169] == 0) {

          iVar6 = 0;

        }

        else {

          iVar6 = unaff_EDI[0x16a] - unaff_EDI[0x169] >> 2;

        }

        if ((int)uStack_2ac < iVar6) break;

        piStack_2b8 = operator_new(0x534);

        uStack_4 = 0;

        if (piStack_2b8 == (int *)0x0) {

          piVar7 = (int *)0x0;

        }

        else {

          piVar7 = (int *)FUN_0082a8b0(piStack_2b8);

        }

        uStack_4 = 0xffffffff;

        piStack_2b8 = piVar7;

        (**(code **)(*piVar7 + 0x74))(uStack_2ac + 0x9c4a);

        (**(code **)(*piVar7 + 8))(unaff_EDI + 0x14b);

        iVar6 = unaff_EDI[0x169];

        if ((iVar6 == 0) ||

           ((uint)(unaff_EDI[0x16b] - iVar6 >> 2) <= (uint)(unaff_EDI[0x16a] - iVar6 >> 2))) {

          FUN_00419880(unaff_EDI + 0x168,unaff_EDI[0x16a],&piStack_2b8);

        }

        else {

          puVar1 = (uint32_t /* width from decompiler */ *)unaff_EDI[0x16a];

          *puVar1 = piVar7;

          unaff_EDI[0x16a] = (int)(puVar1 + 1);

        }

      }

      iVar6 = uStack_2ac * 4;

      (**(code **)(*unaff_EDI + 0xa8))(*(uint32_t /* width from decompiler */ *)(iVar6 + unaff_EDI[0x169]));

      *(uint8_t *)(*(int *)(iVar6 + unaff_EDI[0x169]) + 0x4fd) = 1;

      (**(code **)(**(int **)(iVar6 + unaff_EDI[0x169]) + 0x43c))();

      FUN_0082a050();

      if ((*(int **)(iVar4 + 0x14c) != (int *)0x0) && (**(int **)(iVar4 + 0x14c) == local_2a8)) {

        local_2a4 = *(uint32_t /* width from decompiler */ *)(iVar6 + unaff_EDI[0x169]);

      }

      uVar10 = 0;

      while (((unaff_EDI[0x16d] != 0 && (uVar10 < (uint)(unaff_EDI[0x16e] - unaff_EDI[0x16d] >> 2)))

             && (*(int *)(*(int *)(unaff_EDI[0x16d] + uVar10 * 4) + 0x110) != iStack_2a0))) {

        uVar10 = uVar10 + 1;

      }

      if ((unaff_EDI[0x16d] == 0) || ((uint)(unaff_EDI[0x16e] - unaff_EDI[0x16d] >> 2) <= uVar10)) {

        piStack_2b8 = operator_new(0x534);

        uStack_4 = 1;

        if (piStack_2b8 == (int *)0x0) {

          piVar7 = (int *)0x0;

        }

        else {

          piVar7 = (int *)FUN_0082a8b0(piStack_2b8);

        }

        uStack_4 = 0xffffffff;

        if (unaff_EDI[0x16d] == 0) {

          iVar4 = 0;

        }

        else {

          iVar4 = unaff_EDI[0x16e] - unaff_EDI[0x16d] >> 2;

        }

        piStack_2b8 = piVar7;

        (**(code **)(*piVar7 + 0x74))(iVar4 + 0xafd2);

        (**(code **)(*piVar7 + 8))(unaff_EDI + 0x14b);

        (**(code **)(*unaff_EDI + 0xa8))(piVar7);

        *(uint8_t *)(piVar7 + 0x13f) = 1;

        (**(code **)(*piVar7 + 0x43c))();

        uVar10 = uStack_2ac;

        piVar7[0x44] = uStack_2ac;

        iVar4 = FUN_00541a80();

        iVar4 = *(int *)(*(int *)(*(int *)(iVar4 + 0x10) + (*(uint *)(iVar4 + 8) & uVar10) * 4) + 4)

        ;

        if (iVar4 == 0) {

LAB_008a56cc:

          iVar4 = 0;

        }

        else {

          do {

            if (uVar10 == *(uint *)(iVar4 + 0x10)) {

              if (iVar4 == 0) goto LAB_008a56cc;

              iVar4 = *(int *)(iVar4 + 8);

              goto LAB_008a56d3;

            }

            iVar4 = *(int *)(iVar4 + 0xc);

          } while (iVar4 != 0);

          iVar4 = 0;

        }

LAB_008a56d3:

        if (iVar4 == 0) {

          sprintf(acStack_218,"%d",piVar7[0x44]);

        }

        else {

          piStack_29c = &iStack_298;

          uVar8 = (*(code *)PTR_FUN_00af8c9c)();

          FUN_00403450(iVar4 + 0xb4,uVar8);

          piVar9 = piStack_29c;

          do {

            iVar4 = *piVar9;

            *(char *)((int)piVar9 + (int)(acStack_218 + -(int)piStack_29c)) = (char)iVar4;

            piVar9 = (int *)((int)piVar9 + 1);

          } while ((char)iVar4 != '\0');

          uStack_10 = 0xffffffff;

          if (piStack_29c != &iStack_298) {

            free(piStack_29c);

          }

        }

        (**(code **)(*(int *)piVar7[0x14b] + 0x1d8))(acStack_218,1,1);

        piVar9 = *(int **)unaff_EDI[0x171];

        if (piVar9 != (int *)unaff_EDI[0x171]) {

          do {

            if (piVar9[2] == uVar10) {

              uVar8 = 0;

              goto LAB_008a5796;

            }

            piVar9 = (int *)*piVar9;

          } while (piVar9 != (int *)unaff_EDI[0x171]);

        }

        uVar8 = 1;

LAB_008a5796:

        (**(code **)(*(int *)piVar7[0x14a] + 0x3c8))(uVar8,1);

        iVar4 = unaff_EDI[0x16d];

        if ((iVar4 != 0) &&

           ((uint)(unaff_EDI[0x16e] - iVar4 >> 2) < (uint)(unaff_EDI[0x16f] - iVar4 >> 2))) {

          puVar1 = (uint32_t /* width from decompiler */ *)unaff_EDI[0x16e];

          *puVar1 = piVar7;

          uStack_2ac = uStack_2ac + 1;

          unaff_EDI[0x16e] = (int)(puVar1 + 1);

          goto LAB_008a53e0;

        }

        FUN_00419880(unaff_EDI + 0x16c,unaff_EDI[0x16e],&piStack_2b8);

      }

      uStack_2ac = uStack_2ac + 1;

    }

  } while( true );

  *(uint8_t *)(*(int *)(DAT_00d1b6d8 + 0x548) + 0x1d) = 0;

  iVar4 = *(int *)(DAT_00d1b644 + 0xe5cc);

  piStack_29c = (int *)CONCAT31(piStack_29c._1_3_,2);

  iStack_298 = 0;

  if (*(char *)(iVar4 + 0x1d) != '\0') {

    FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

    FUN_007a4480(0,"VOG_DEBUG_STOP");

  }

  *(uint8_t *)(iVar4 + 0x1d) = 1;

  uVar10 = uStack_2ac;

  iVar4 = 0;

  do {

    iVar6 = *(int *)(DAT_00d1b644 + 0xe5cc);

    if (*(char *)(iVar6 + 0x1d) == '\0') {

      FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    if (iVar4 == 0) {

      iStack_2b4 = *(int *)(iVar6 + 0x14);

      if (iStack_2b4 == 0) goto LAB_008a58b0;

      iStack_2b0 = *(int *)(iStack_2b4 + 8);

    }

    else {

      iStack_2b4 = *(int *)(iVar4 + 0x14);

      if (iStack_2b4 == 0) {

LAB_008a58b0:

        iStack_2b0 = 0;

      }

      else {

        iStack_2b0 = *(int *)(iStack_2b4 + 8);

      }

    }

    if (iStack_2b0 == 0) {

      *(uint8_t *)(*(int *)(DAT_00d1b644 + 0xe5cc) + 0x1d) = 0;

      if (unaff_EDI[0x169] == 0) {

        iVar4 = 0;

      }

      else {

        iVar4 = unaff_EDI[0x16a] - unaff_EDI[0x169] >> 2;

      }

      iStack_2b0 = 0;

      for (; (int)uVar10 < iVar4; uVar10 = uVar10 + 1) {

        if ((*(int *)(unaff_EDI[0x169] + uVar10 * 4) != 0) &&

           (piVar7 = *(int **)(unaff_EDI[0x169] + uVar10 * 4), piVar7[0xac] != 0)) {

          (**(code **)(*piVar7 + 0x440))();

          (**(code **)(*unaff_EDI + 0xb0))(*(uint32_t /* width from decompiler */ *)(unaff_EDI[0x169] + uVar10 * 4));

        }

        piVar7 = *(int **)(unaff_EDI[0x169] + uVar10 * 4);

        piVar7[0x140] = 0;

        piVar7[0x141] = 0;

        piVar7[0x142] = 0;

        *(uint8_t *)((int)piVar7 + 0x4fe) = 0;

        if ((int *)piVar7[0x14b] != (int *)0x0) {

          (**(code **)(*(int *)piVar7[0x14b] + 0x1d8))(&DAT_00a1419b,1,1);

          (**(code **)(*(int *)piVar7[0x14b] + 0xcc))(0);

        }

        (**(code **)(*piVar7 + 0xcc))(0);

        (**(code **)(*piVar7 + 0x34c))();

        FUN_00829fa0();

      }

      FUN_008a2670();

      if (unaff_EDI[0x148] <= unaff_EDI[0x147]) {

        unaff_EDI[0x147] = unaff_EDI[0x148] + -1;

      }

      if (unaff_EDI[0x147] < 0) {

        unaff_EDI[0x147] = 0;

      }

      FUN_008a3510(local_2a4);

      FUN_008a2df0();

      ExceptionList = local_c;

      return;

    }

    iVar4 = iStack_2b4;

    if (*(char *)(iStack_2b0 + 0xc) == '\x01') {

      while( true ) {

        if (unaff_EDI[0x169] == 0) {

          iVar4 = 0;

        }

        else {

          iVar4 = unaff_EDI[0x16a] - unaff_EDI[0x169] >> 2;

        }

        if ((int)uVar10 < iVar4) break;

        piStack_2b8 = operator_new(0x534);

        uStack_4 = 3;

        if (piStack_2b8 == (int *)0x0) {

          piVar7 = (int *)0x0;

        }

        else {

          piVar7 = (int *)FUN_0082a8b0(piStack_2b8);

        }

        uStack_4 = 0xffffffff;

        piStack_2b8 = piVar7;

        (**(code **)(*piVar7 + 0x74))(uVar10 + 0x9c4a);

        (**(code **)(*piVar7 + 8))(unaff_EDI + 0x14b);

        iVar4 = unaff_EDI[0x169];

        if ((iVar4 == 0) ||

           ((uint)(unaff_EDI[0x16b] - iVar4 >> 2) <= (uint)(unaff_EDI[0x16a] - iVar4 >> 2))) {

          FUN_00419880(unaff_EDI + 0x168,unaff_EDI[0x16a],&piStack_2b8);

        }

        else {

          puVar1 = (uint32_t /* width from decompiler */ *)unaff_EDI[0x16a];

          *puVar1 = piVar7;

          unaff_EDI[0x16a] = (int)(puVar1 + 1);

        }

      }

      iStack_294 = iStack_2b0;

      (**(code **)(*unaff_EDI + 0xa8))(*(uint32_t /* width from decompiler */ *)(unaff_EDI[0x169] + uVar10 * 4));

      *(uint8_t *)(*(int *)(unaff_EDI[0x169] + uVar10 * 4) + 0x4fd) = 1;

      (**(code **)(**(int **)(unaff_EDI[0x169] + uVar10 * 4) + 0x43c))();

      FUN_0082a050();

      uVar10 = uVar10 + 1;

      iVar4 = iStack_2b4;

    }

  } while( true );

}
