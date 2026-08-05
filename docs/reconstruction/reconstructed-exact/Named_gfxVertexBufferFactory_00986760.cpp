// READABILITY (auto CF):
//  - Body size: ~141 non-empty decompiler lines.
//  - Control keywords: if×11, while×7, return×4, do×2, for×1.
//  - Notable callees: FUN_0045f5d0, FUN_0045f860, FUN_0045f9d0, FUN_007465c0, FUN_0076cec0, FUN_00986760, vog_LogMessage.
//  - Strings: "VBFactory Shutdown - Slice still allocated! (%d Vertices)".
//  - Return sites: 4.

// =============================================================================
// Named_gfxVertexBufferFactory_00986760
// -----------------------------------------------------------------------------
// Stable ID: aa_00986760
// Address:   0x00986760  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "gfxVertexBufferFactory"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_gfxVertexBufferFactory_00986760(int param_1)



{

  char cVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ *puVar5;

  int *piVar6;

  void *pvVar7;

  int iVar8;

  uint32_t /* width from decompiler */ *puVar9;

  uint32_t /* width from decompiler */ *puVar10;

  uint32_t /* width from decompiler */ uVar11;

  uint32_t /* width from decompiler */ *puVar12;

  uint32_t /* width from decompiler */ *puVar13;

  int iVar14;

  uint32_t /* width from decompiler */ *puVar15;

  

  puVar2 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x14);

  puVar13 = (uint32_t /* width from decompiler */ *)*puVar2;

  puVar9 = puVar13;

  iVar14 = param_1;

  do {

    param_1 = iVar14;

    if (puVar13 == puVar2) {

      FUN_0045f9d0(*(uint32_t /* width from decompiler */ *)(*(int *)(iVar14 + 0x14) + 4));

      *(int *)(*(int *)(iVar14 + 0x14) + 4) = *(int *)(iVar14 + 0x14);

      *(uint32_t /* width from decompiler */ *)(iVar14 + 0x18) = 0;

      *(uint32_t /* width from decompiler */ *)*(uint32_t /* width from decompiler */ *)(iVar14 + 0x14) = *(uint32_t /* width from decompiler */ *)(iVar14 + 0x14);

      *(int *)(*(int *)(iVar14 + 0x14) + 8) = *(int *)(iVar14 + 0x14);

      return;

    }

    puVar3 = (uint32_t /* width from decompiler */ *)puVar13[6];

    puVar15 = (uint32_t /* width from decompiler */ *)puVar13[5];

    if (puVar15 != puVar3) {

      puVar12 = puVar15 + 5;

      do {

        if (puVar12[-2] != 0) {

          puVar13 = (uint32_t /* width from decompiler */ *)puVar12[-3];

          puVar4 = (uint32_t /* width from decompiler */ *)*puVar13;

          while (puVar4 != puVar13) {

            uVar11 = FUN_0076cec0(&param_1,

                                  "VBFactory Shutdown - Slice still allocated! (%d Vertices)",

                                  *(uint32_t /* width from decompiler */ *)(puVar4[3] + 0x18));

            vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxVertexBufferFactory.cpp"

                           ,0x47,2,uVar11);

            if (*(char *)((int)puVar4 + 0x11) == '\0') {

              puVar5 = (uint32_t /* width from decompiler */ *)puVar4[2];

              if (*(char *)((int)puVar5 + 0x11) == '\0') {

                cVar1 = *(char *)((int)*puVar5 + 0x11);

                puVar4 = puVar5;

                puVar5 = (uint32_t /* width from decompiler */ *)*puVar5;

                while (cVar1 == '\0') {

                  cVar1 = *(char *)((int)*puVar5 + 0x11);

                  puVar4 = puVar5;

                  puVar5 = (uint32_t /* width from decompiler */ *)*puVar5;

                }

              }

              else {

                cVar1 = *(char *)((int)puVar4[1] + 0x11);

                puVar10 = (uint32_t /* width from decompiler */ *)puVar4[1];

                puVar5 = puVar4;

                while ((puVar4 = puVar10, cVar1 == '\0' && (puVar5 == (uint32_t /* width from decompiler */ *)puVar4[2]))) {

                  cVar1 = *(char *)((int)puVar4[1] + 0x11);

                  puVar10 = (uint32_t /* width from decompiler */ *)puVar4[1];

                  puVar5 = puVar4;

                }

              }

            }

          }

        }

        piVar6 = (int *)*puVar15;

        if (piVar6 != (int *)0x0) {

          FUN_007465c0();

          piVar6[1] = -1;

          piVar6[2] = 0;

          piVar6[3] = 0;

          *piVar6 = (int)DAT_00d219c0;

          DAT_00d219c0 = piVar6;

        }

        *puVar15 = 0;

        pvVar7 = *(void **)(puVar12[-3] + 4);

        if (*(char *)((int)pvVar7 + 0x11) == '\0') {

          FUN_0045f860(*(uint32_t /* width from decompiler */ *)((int)pvVar7 + 8));

                    /* WARNING: Subroutine does not return */

          operator_delete(pvVar7);

        }

        *(uint32_t /* width from decompiler */ *)(puVar12[-3] + 4) = puVar12[-3];

        puVar12[-2] = 0;

        *(uint32_t /* width from decompiler */ *)puVar12[-3] = puVar12[-3];

        *(uint32_t /* width from decompiler */ *)(puVar12[-3] + 8) = puVar12[-3];

        if ((void *)*puVar12 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

          operator_delete((void *)*puVar12);

        }

        puVar15 = puVar15 + 8;

        *puVar12 = 0;

        puVar12[1] = 0;

        puVar12[2] = 0;

        puVar12 = puVar12 + 8;

        puVar13 = puVar9;

      } while (puVar15 != puVar3);

    }

    iVar14 = puVar13[5];

    if (iVar14 != 0) {

      iVar8 = puVar13[6];

      for (; iVar14 != iVar8; iVar14 = iVar14 + 0x20) {

        FUN_0045f5d0();

      }

                    /* WARNING: Subroutine does not return */

      operator_delete((void *)puVar13[5]);

    }

    puVar13[5] = 0;

    puVar13[6] = 0;

    puVar13[7] = 0;

    iVar14 = param_1;

    if (*(char *)((int)puVar13 + 0x21) == '\0') {

      puVar9 = (uint32_t /* width from decompiler */ *)puVar13[2];

      if (*(char *)((int)puVar9 + 0x21) == '\0') {

        cVar1 = *(char *)((int)*puVar9 + 0x21);

        puVar13 = puVar9;

        puVar3 = (uint32_t /* width from decompiler */ *)*puVar9;

        while (puVar9 = puVar13, cVar1 == '\0') {

          cVar1 = *(char *)((int)*puVar3 + 0x21);

          puVar13 = puVar3;

          puVar3 = (uint32_t /* width from decompiler */ *)*puVar3;

        }

      }

      else {

        cVar1 = *(char *)((int)puVar13[1] + 0x21);

        puVar9 = (uint32_t /* width from decompiler */ *)puVar13[1];

        puVar3 = puVar13;

        while ((puVar13 = puVar9, puVar9 = puVar13, cVar1 == '\0' &&

               (puVar3 == (uint32_t /* width from decompiler */ *)puVar13[2]))) {

          cVar1 = *(char *)((int)puVar13[1] + 0x21);

          puVar9 = (uint32_t /* width from decompiler */ *)puVar13[1];

          puVar3 = puVar13;

        }

      }

    }

  } while( true );

}
