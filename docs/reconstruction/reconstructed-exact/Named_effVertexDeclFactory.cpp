// READABILITY (auto CF):
//  - Body size: ~151 non-empty decompiler lines.
//  - Control keywords: if×18, return×6, do×3, while×3, for×1, goto×1.
//  - Notable callees: FUN_00967150×3, ExitProcess, FUN_004451c0, FUN_00456960, FUN_0076d1b0, fclose, fopen, fprintf.
//  - Strings: "

                             ,0x5c,"; ");

        if (iVar4 == 3) {

          _File = fopen("; "errReport::Massive failure EH_Abort: F:%s l:%d s:%d d:%s\n"; "

                    ,0x5c,3,".
//  - Return sites: 6.

// =============================================================================
// Named_effVertexDeclFactory
// -----------------------------------------------------------------------------
// Stable ID: aa_00967150
// Address:   0x00967150  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "effVertexDeclFactory"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall Named_effVertexDeclFactory(int param_1,int param_2)



{

  void *pvVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint8_t *puVar3;

  int iVar4;

  int iVar5;

  void *pvVar6;

  FILE *_File;

  int *piVar7;

  char *pcVar8;

  int unaff_EDI;

  char *pcVar9;

  bool bVar10;

  char *local_14;

  int local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009afa21;

  local_c = ExceptionList;

  local_14 = *(char **)(param_2 + 4);

  if (local_14 == (char *)0x0) {

    iVar4 = 0;

  }

  else {

    iVar4 = *(int *)(param_2 + 8) - (int)local_14 >> 3;

  }

  pvVar1 = (void *)(iVar4 + -1);

  if ((int)pvVar1 < 1) {

    return;

  }

  for (piVar7 = (int *)(*(int *)(param_1 + 0x14) + 4); local_10 = param_1,

      piVar7 != *(int **)(param_1 + 0x18); piVar7 = piVar7 + 1) {

    iVar4 = *piVar7;

    pcVar8 = *(char **)(iVar4 + 4);

    if (pcVar8 == (char *)0x0) {

      iVar5 = 0;

    }

    else {

      iVar5 = *(int *)(iVar4 + 8) - (int)pcVar8 >> 3;

    }

    if (pvVar1 == (void *)(iVar5 + -1)) {

      iVar5 = (int)pvVar1 * 8;

      bVar10 = true;

      pcVar9 = local_14;

      do {

        if (iVar5 == 0) break;

        iVar5 = iVar5 + -1;

        bVar10 = *pcVar8 == *pcVar9;

        pcVar8 = pcVar8 + 1;

        pcVar9 = pcVar9 + 1;

      } while (bVar10);

      if (bVar10) goto LAB_00967205;

    }

  }

  piVar7 = *(int **)(param_1 + 4);

  do {

    if (piVar7 == *(int **)(param_1 + 8)) {

      ExceptionList = &local_c;

      iVar4 = (**(code **)(*(int *)*DAT_00d1f044 + 0x158))((int *)*DAT_00d1f044,local_14,&local_14);

      if ((iVar4 < 0) || (unaff_EDI == 0)) {

        iVar4 = FUN_0076d1b0("C:\\vog\\1_code\\palantir\\palantir\\graphics\\Effects\\effVertexDeclFactory.cpp"

                             ,0x5c,"Unable to build device vertex declaration object");

        if (iVar4 == 3) {

          _File = fopen("c:\\VOGCRASH.txt","w");

          if (_File != (FILE *)0x0) {

            fprintf(_File,"errReport::Massive failure EH_Abort: F:%s l:%d s:%d d:%s\n",

                    "C:\\vog\\1_code\\palantir\\palantir\\graphics\\Effects\\effVertexDeclFactory.cpp"

                    ,0x5c,3,"Unable to build device vertex declaration object");

            fclose(_File);

          }

          raise(0x16);

                    /* WARNING: Subroutine does not return */

          ExitProcess(3);

        }

        *(uint32_t /* width from decompiler */ *)(puStack_8 + 0x10) = 0;

        *(uint32_t /* width from decompiler */ *)(puStack_8 + 0x14) = 0;

        ExceptionList = pvVar1;

        return;

      }

      pvVar6 = operator_new(0x18);

      puVar3 = puStack_8;

      local_10 = 0;

      if (pvVar6 == (void *)0x0) {

        puStack_8 = (uint8_t *)0x0;

      }

      else {

        puStack_8 = (uint8_t *)FUN_004451c0(pvVar6,puStack_8);

      }

      local_10 = 0xffffffff;

      *(int *)((int)puStack_8 + 0x10) = unaff_EDI;

      *(uint32_t /* width from decompiler */ *)((int)puStack_8 + 0x14) = 0;

      *(int *)(puVar3 + 0x10) = unaff_EDI;

      *(uint32_t /* width from decompiler */ *)(puVar3 + 0x14) = 0;

      iVar4 = *(int *)(param_1 + 4);

      if ((iVar4 != 0) &&

         ((uint)(*(int *)(param_1 + 8) - iVar4 >> 2) < (uint)(*(int *)(param_1 + 0xc) - iVar4 >> 2))

         ) {

        piVar7 = *(int **)(param_1 + 8);

        *piVar7 = (int)puStack_8;

        *(int **)(param_1 + 8) = piVar7 + 1;

        ExceptionList = pvVar1;

        return;

      }

      FUN_00456960(*(uint32_t /* width from decompiler */ *)(param_1 + 8));

      ExceptionList = pvVar1;

      return;

    }

    iVar4 = *piVar7;

    pcVar8 = *(char **)(iVar4 + 4);

    if (pcVar8 == (char *)0x0) {

      iVar5 = 0;

    }

    else {

      iVar5 = *(int *)(iVar4 + 8) - (int)pcVar8 >> 3;

    }

    if (pvVar1 == (void *)(iVar5 + -1)) {

      iVar5 = (int)pvVar1 * 8;

      bVar10 = true;

      pcVar9 = local_14;

      do {

        if (iVar5 == 0) break;

        iVar5 = iVar5 + -1;

        bVar10 = *pcVar8 == *pcVar9;

        pcVar8 = pcVar8 + 1;

        pcVar9 = pcVar9 + 1;

      } while (bVar10);

      if (bVar10) {

LAB_00967205:

        ExceptionList = &local_c;

        if (*(int *)(iVar4 + 0x10) == 0) {

          ExceptionList = &local_c;

          Named_effVertexDeclFactory(iVar4);

        }

        iVar5 = *(int *)(iVar4 + 0x10);

        uVar2 = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x14);

        if (iVar5 == 0) {

          Named_effVertexDeclFactory(iVar4);

          iVar5 = *(int *)(iVar4 + 0x10);

        }

        *(int *)(param_2 + 0x10) = iVar5;

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x14) = uVar2;

        ExceptionList = local_c;

        return;

      }

    }

    piVar7 = piVar7 + 1;

  } while( true );

}
