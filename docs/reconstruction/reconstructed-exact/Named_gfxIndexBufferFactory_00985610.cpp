// READABILITY (auto CF):
//  - Body size: ~116 non-empty decompiler lines.
//  - Control keywords: if×10, while×6, return×3, do×1, for×1.
//  - Notable callees: PostResoreDevice×2, Buffer, ExitProcess, FUN_00743cd0, FUN_0076cec0, FUN_0076d1b0, FUN_00985610, fclose.
//  - Strings: "

                                 ,0x180,"; "c:\\VOGCRASH.txt"; "errReport::Massive failure EH_Abort: F:%s l:%d s:%d d:%s\n"; ",

                      0x180,5,".
//  - Return sites: 3.

// =============================================================================
// Named_gfxIndexBufferFactory_00985610
// -----------------------------------------------------------------------------
// Stable ID: aa_00985610
// Address:   0x00985610  (autoassault.exe, image base 0x400000)
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

int Named_gfxIndexBufferFactory_00985610(void)



{

  char cVar1;

  int *piVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ *puVar6;

  int in_EAX;

  int iVar7;

  uint32_t /* width from decompiler */ uVar8;

  int iVar9;

  FILE *_File;

  int *piVar10;

  int *piVar11;

  int *piVar12;

  int *local_10;

  int *local_4;

  

  piVar12 = *(int **)(in_EAX + 0x14);

  piVar10 = (int *)*piVar12;

  local_10 = piVar10;

  local_4 = piVar12;

  if (piVar10 != piVar12) {

    do {

      if ((*(byte *)(piVar10 + 3) & 0x28) == 0) {

        piVar2 = (int *)piVar10[6];

        piVar11 = (int *)piVar10[5];

        for (; piVar11 != piVar2; piVar11 = piVar11 + 8) {

          iVar7 = *piVar11;

          iVar7 = FUN_00743cd0(*(uint32_t /* width from decompiler */ *)(iVar7 + 4),*(uint32_t /* width from decompiler */ *)(iVar7 + 8),

                               *(int *)(iVar7 + 0x10) == 4);

          if (iVar7 < 0) {

            iVar9 = FUN_0076d1b0("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxIndexBufferFactory.cpp"

                                 ,0x180,"Failed PostResoreDevice() on Index Buffers");

            if (iVar9 != 3) {

              return iVar7;

            }

            _File = fopen("c:\\VOGCRASH.txt","w");

            if (_File != (FILE *)0x0) {

              fprintf(_File,"errReport::Massive failure EH_Abort: F:%s l:%d s:%d d:%s\n",

                      "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxIndexBufferFactory.cpp",

                      0x180,5,"Failed PostResoreDevice() on Index Buffers");

              fclose(_File);

            }

            raise(0x16);

                    /* WARNING: Subroutine does not return */

            ExitProcess(3);

          }

          puVar3 = (uint32_t /* width from decompiler */ *)piVar11[2];

          puVar4 = (uint32_t /* width from decompiler */ *)*puVar3;

          while (puVar4 != puVar3) {

            puVar5 = *(uint32_t /* width from decompiler */ **)(puVar4[3] + 0x20);

            if ((puVar5 != (uint32_t /* width from decompiler */ *)0x0) &&

               (iVar7 = (**(code **)*puVar5)(puVar4[3]), iVar7 < 0)) {

              uVar8 = FUN_0076cec0(&local_4,

                                   "RestoreSurfaceCallback Failed on Index Buffer (%d indices)",

                                   *(uint32_t /* width from decompiler */ *)(puVar4[3] + 0x1c));

              vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxIndexBufferFactory.cpp"

                             ,400,2,uVar8);

            }

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

                puVar6 = (uint32_t /* width from decompiler */ *)puVar4[1];

                puVar5 = puVar4;

                while ((puVar4 = puVar6, cVar1 == '\0' && (puVar5 == (uint32_t /* width from decompiler */ *)puVar4[2]))) {

                  cVar1 = *(char *)((int)puVar4[1] + 0x11);

                  puVar6 = (uint32_t /* width from decompiler */ *)puVar4[1];

                  puVar5 = puVar4;

                }

              }

            }

          }

          piVar10 = local_10;

          piVar12 = local_4;

        }

      }

      if (*(char *)((int)piVar10 + 0x21) == '\0') {

        piVar2 = (int *)piVar10[2];

        if (*(char *)((int)piVar2 + 0x21) == '\0') {

          cVar1 = *(char *)(*piVar2 + 0x21);

          piVar10 = piVar2;

          piVar2 = (int *)*piVar2;

          while (local_10 = piVar10, cVar1 == '\0') {

            cVar1 = *(char *)(*piVar2 + 0x21);

            piVar10 = piVar2;

            piVar2 = (int *)*piVar2;

          }

        }

        else {

          cVar1 = *(char *)(piVar10[1] + 0x21);

          piVar11 = (int *)piVar10[1];

          piVar2 = piVar10;

          while ((piVar10 = piVar11, local_10 = piVar10, cVar1 == '\0' &&

                 (piVar2 == (int *)piVar10[2]))) {

            cVar1 = *(char *)(piVar10[1] + 0x21);

            piVar11 = (int *)piVar10[1];

            piVar2 = piVar10;

          }

        }

      }

    } while (piVar10 != piVar12);

  }

  return 0;

}
