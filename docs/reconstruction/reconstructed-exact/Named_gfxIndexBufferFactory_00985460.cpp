// READABILITY (auto CF):
//  - Body size: ~85 non-empty decompiler lines.
//  - Control keywords: if×6, while×6, do×1, for×1, return×1.
//  - Notable callees: FUN_0076cec0, FUN_00985460, vog_LogMessage.
//  - Strings: "IBFactory Shutdown - Slice still allocated! (%d Indices)".
//  - Return sites: 1.

// =============================================================================
// Named_gfxIndexBufferFactory_00985460
// -----------------------------------------------------------------------------
// Stable ID: aa_00985460
// Address:   0x00985460  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "gfxIndexBufferFactory"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_gfxIndexBufferFactory_00985460(void)



{

  char cVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ *puVar5;

  int *piVar6;

  uint32_t /* width from decompiler */ *puVar7;

  int *piVar8;

  int in_EAX;

  uint32_t /* width from decompiler */ uVar9;

  int *piVar10;

  int iVar11;

  int *piVar12;

  int *local_4;

  

  piVar10 = *(int **)(in_EAX + 0x14);

  piVar12 = (int *)*piVar10;

  local_4 = piVar10;

  if (piVar12 != piVar10) {

    do {

      iVar2 = piVar12[6];

      for (iVar11 = piVar12[5]; iVar11 != iVar2; iVar11 = iVar11 + 0x20) {

        if (*(int *)(iVar11 + 0xc) != 0) {

          puVar3 = *(uint32_t /* width from decompiler */ **)(iVar11 + 8);

          puVar4 = (uint32_t /* width from decompiler */ *)*puVar3;

          while (puVar4 != puVar3) {

            uVar9 = FUN_0076cec0(&local_4,"IBFactory Shutdown - Slice still allocated! (%d Indices)"

                                 ,*(uint32_t /* width from decompiler */ *)(puVar4[3] + 0x1c));

            vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxIndexBufferFactory.cpp"

                           ,0x73,2,uVar9);

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

                puVar7 = (uint32_t /* width from decompiler */ *)puVar4[1];

                puVar5 = puVar4;

                while ((puVar4 = puVar7, cVar1 == '\0' && (puVar5 == (uint32_t /* width from decompiler */ *)puVar4[2]))) {

                  cVar1 = *(char *)((int)puVar4[1] + 0x11);

                  puVar7 = (uint32_t /* width from decompiler */ *)puVar4[1];

                  puVar5 = puVar4;

                }

              }

            }

          }

        }

        piVar10 = local_4;

      }

      if (*(char *)((int)piVar12 + 0x21) == '\0') {

        piVar6 = (int *)piVar12[2];

        if (*(char *)((int)piVar6 + 0x21) == '\0') {

          cVar1 = *(char *)(*piVar6 + 0x21);

          piVar12 = piVar6;

          piVar6 = (int *)*piVar6;

          while (cVar1 == '\0') {

            cVar1 = *(char *)(*piVar6 + 0x21);

            piVar12 = piVar6;

            piVar6 = (int *)*piVar6;

          }

        }

        else {

          cVar1 = *(char *)(piVar12[1] + 0x21);

          piVar8 = (int *)piVar12[1];

          piVar6 = piVar12;

          while ((piVar12 = piVar8, cVar1 == '\0' && (piVar6 == (int *)piVar12[2]))) {

            cVar1 = *(char *)(piVar12[1] + 0x21);

            piVar8 = (int *)piVar12[1];

            piVar6 = piVar12;

          }

        }

      }

    } while (piVar12 != piVar10);

  }

  return;

}
