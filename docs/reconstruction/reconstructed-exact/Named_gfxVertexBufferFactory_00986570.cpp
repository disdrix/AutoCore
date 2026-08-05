// READABILITY (auto CF):
//  - Body size: ~111 non-empty decompiler lines.
//  - Control keywords: if×10, while×6, return×3, do×1, for×1.
//  - Notable callees: PostResoreDevice×2, Buffer, ExitProcess, FUN_00746640, FUN_0076cec0, FUN_0076d1b0, FUN_00986570, fclose.
//  - Strings: "

                                 ,0x194,"; "c:\\VOGCRASH.txt"; "errReport::Massive failure EH_Abort: F:%s l:%d s:%d d:%s\n"; ",

                      0x194,5,".
//  - Return sites: 3.

// =============================================================================
// Named_gfxVertexBufferFactory_00986570
// -----------------------------------------------------------------------------
// Stable ID: aa_00986570
// Address:   0x00986570  (autoassault.exe, image base 0x400000)
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

int Named_gfxVertexBufferFactory_00986570(void)



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

  int *local_4;

  

  piVar10 = *(int **)(in_EAX + 0x14);

  piVar11 = (int *)*piVar10;

  local_4 = piVar10;

  if (piVar11 != piVar10) {

    do {

      if ((*(byte *)((int)piVar11 + 0xe) & 0x28) == 0) {

        piVar2 = (int *)piVar11[6];

        for (piVar12 = (int *)piVar11[5]; piVar12 != piVar2; piVar12 = piVar12 + 8) {

          iVar7 = *piVar12;

          iVar7 = FUN_00746640(iVar7,*(uint32_t /* width from decompiler */ *)(iVar7 + 0xc),*(uint32_t /* width from decompiler */ *)(iVar7 + 8),

                               *(uint32_t /* width from decompiler */ *)(iVar7 + 4),0);

          if (iVar7 < 0) {

            iVar9 = FUN_0076d1b0("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxVertexBufferFactory.cpp"

                                 ,0x194,"Failed PostResoreDevice() on Vertex Buffers");

            if (iVar9 != 3) {

              return iVar7;

            }

            _File = fopen("c:\\VOGCRASH.txt","w");

            if (_File != (FILE *)0x0) {

              fprintf(_File,"errReport::Massive failure EH_Abort: F:%s l:%d s:%d d:%s\n",

                      "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxVertexBufferFactory.cpp",

                      0x194,5,"Failed PostResoreDevice() on Vertex Buffers");

              fclose(_File);

            }

            raise(0x16);

                    /* WARNING: Subroutine does not return */

            ExitProcess(3);

          }

          puVar3 = (uint32_t /* width from decompiler */ *)piVar12[2];

          puVar4 = (uint32_t /* width from decompiler */ *)*puVar3;

          while (puVar4 != puVar3) {

            puVar5 = *(uint32_t /* width from decompiler */ **)(puVar4[3] + 0x1c);

            if ((puVar5 != (uint32_t /* width from decompiler */ *)0x0) &&

               (iVar7 = (**(code **)*puVar5)(puVar4[3]), iVar7 < 0)) {

              uVar8 = FUN_0076cec0(&local_4,

                                   "RestoreSurfaceCallback Failed on Vertex Buffer (%d Verts)",

                                   *(uint32_t /* width from decompiler */ *)(puVar4[3] + 0x18));

              vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxVertexBufferFactory.cpp"

                             ,0x1a4,2,uVar8);

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

          piVar10 = local_4;

        }

      }

      if (*(char *)((int)piVar11 + 0x21) == '\0') {

        piVar2 = (int *)piVar11[2];

        if (*(char *)((int)piVar2 + 0x21) == '\0') {

          cVar1 = *(char *)(*piVar2 + 0x21);

          piVar11 = piVar2;

          piVar2 = (int *)*piVar2;

          while (cVar1 == '\0') {

            cVar1 = *(char *)(*piVar2 + 0x21);

            piVar11 = piVar2;

            piVar2 = (int *)*piVar2;

          }

        }

        else {

          cVar1 = *(char *)(piVar11[1] + 0x21);

          piVar12 = (int *)piVar11[1];

          piVar2 = piVar11;

          while ((piVar11 = piVar12, cVar1 == '\0' && (piVar2 == (int *)piVar11[2]))) {

            cVar1 = *(char *)(piVar11[1] + 0x21);

            piVar12 = (int *)piVar11[1];

            piVar2 = piVar11;

          }

        }

      }

    } while (piVar11 != piVar10);

  }

  return 0;

}
