// READABILITY (auto CF):
//  - Body size: ~223 non-empty decompiler lines.
//  - Control keywords: if×24, goto×8, return×3, do×2, while×2.
//  - Notable callees: FUN_00767160×8, stoChunkWriter_EndChunk×3, FUN_0073f8a0×2, FUN_0076d1b0×2, fopen×2, stoChunkWriter_BeginChunk×2, ExitProcess, FUN_00436f80.
//  - Strings: "Tracks with identical names (%s) are not allowed!"; "C:\\vog\\1_code\\palantir\\palantir\\animation\\anmAnimMaster.cpp"; "c:\\VOGCRASH.txt"; ";

    uVar10 = 0x67;

  }

  fprintf(_File,".
//  - Return sites: 3.

// =============================================================================
// Named_anmAnimMaster_00963a10
// -----------------------------------------------------------------------------
// Stable ID: aa_00963a10
// Address:   0x00963a10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "anmAnimMaster"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __fastcall Named_anmAnimMaster_00963a10(uint32_t /* width from decompiler */ *param_1,int param_2)



{

  void **ppvVar1;

  char cVar2;

  uint uVar3;

  int *piVar4;

  void *pvVar5;

  int iVar6;

  FILE *_File;

  undefined *puVar7;

  uint32_t /* width from decompiler */ *puVar8;

  uint32_t /* width from decompiler */ *puVar9;

  void *unaff_ESI;

  uint32_t /* width from decompiler */ uVar10;

  char *pcVar11;

  uint32_t /* width from decompiler */ *puStack_2c;

  uint32_t /* width from decompiler */ *local_14;

  uint32_t /* width from decompiler */ *local_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009af844;

  pvStack_c = ExceptionList;

  if (*(int *)(param_2 + 0xc) == 0) {

    puVar8 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    puVar8 = (uint32_t /* width from decompiler */ *)(*(int *)(param_2 + 0x10) - *(int *)(param_2 + 0xc) >> 2);

  }

  puVar9 = (uint32_t /* width from decompiler */ *)0x0;

  ExceptionList = &pvStack_c;

  ppvVar1 = &pvStack_c;

  if (puVar8 != (uint32_t /* width from decompiler */ *)0x0) {

    do {

      ExceptionList = ppvVar1;

      puStack_2c = puVar9;

      cVar2 = FUN_009637d0(param_2);

      if (cVar2 != '\0') {

        puStack_2c = (uint32_t /* width from decompiler */ *)0x963aa4;

        piVar4 = (int *)(**(code **)(**(int **)(*(int *)(param_2 + 0xc) + (int)puVar9 * 4) + 8))();

        puStack_2c = (uint32_t /* width from decompiler */ *)*piVar4;

        if ((uint32_t /* width from decompiler */ *)*piVar4 == (uint32_t /* width from decompiler */ *)0x0) {

          puStack_2c = (uint32_t /* width from decompiler */ *)PTR_DAT_00afa2bc;

        }

        uVar10 = FUN_0076cec0(&local_14,"Tracks with identical names (%s) are not allowed!");

        vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\animation\\anmAnimMaster.cpp",0x3d,3,

                       uVar10);

        ExceptionList = pvStack_c;

        return 0xffffffff;

      }

      puVar9 = (uint32_t /* width from decompiler */ *)((int)puVar9 + 1);

      ppvVar1 = ExceptionList;

    } while (puVar9 < puVar8);

  }

  puStack_2c = (uint32_t /* width from decompiler */ *)0x4;

  local_10 = param_1;

  stoChunkWriter_BeginChunk(0x414e494d);

  puVar9 = (uint32_t /* width from decompiler */ *)0x0;

  local_4 = 0;

  if (param_1[7] == 0) {

    puStack_2c = (uint32_t /* width from decompiler */ *)0x4;

    local_14 = puVar8;

    uVar3 = (**(code **)(*(int *)*param_1 + 0x18))(&local_14);

    param_1[1] = param_1[1] | uVar3;

  }

  else {

    puStack_2c = puVar8;

    uVar3 = FUN_00767160(&DAT_00a9d718);

    param_1[1] = param_1[1] | uVar3;

    puStack_2c = (uint32_t /* width from decompiler */ *)0x2;

    uVar3 = (**(code **)(*(int *)*param_1 + 0x18))(&DAT_00a97b84);

    param_1[8] = 0;

    param_1[1] = uVar3 | param_1[1];

  }

  if (param_1[7] == 0) {

    uVar3 = (**(code **)(*(int *)*param_1 + 0x18))(&stack0xffffffe3,1);

    param_1[1] = param_1[1] | uVar3;

  }

  else {

    uVar3 = FUN_00767160(&DAT_00a9d718,*(uint8_t *)(param_2 + 4));

    param_1[1] = param_1[1] | uVar3;

    uVar3 = (**(code **)(*(int *)*param_1 + 0x18))(&DAT_00a97b84,2);

    param_1[8] = 0;

    param_1[1] = uVar3 | param_1[1];

  }

  if (puVar8 != (uint32_t /* width from decompiler */ *)0x0) {

    do {

      pvVar5 = (void *)(**(code **)(**(int **)(*(int *)(param_2 + 0xc) + (int)puVar9 * 4) + 0x10))()

      ;

      if (param_1[7] == 0) {

        uVar3 = (**(code **)(*(int *)*param_1 + 0x18))(&stack0xffffffdc,4);

        param_1[1] = param_1[1] | uVar3;

        unaff_ESI = pvVar5;

      }

      else {

        uVar3 = FUN_00767160(&DAT_00a9d718,pvVar5);

        param_1[1] = param_1[1] | uVar3;

        uVar3 = (**(code **)(*(int *)*param_1 + 0x18))(&DAT_00a97b84,2);

        param_1[8] = 0;

        param_1[1] = uVar3 | param_1[1];

      }

      (**(code **)(**(int **)(*(int *)(param_2 + 0xc) + (int)puVar9 * 4) + 0x14))(param_1);

      puVar9 = (uint32_t /* width from decompiler */ *)((int)puVar9 + 1);

    } while (puVar9 < puVar8);

  }

  pvVar5 = *(void **)(param_2 + 0x20);

  if (pvVar5 == (void *)0x2) {

    if (*(int *)(param_2 + 0x18) != 0) {

      if (param_1[7] == 0) {

        uVar3 = (**(code **)(*(int *)*param_1 + 0x18))(&stack0xffffffdc,4);

        param_1[1] = param_1[1] | uVar3;

        FUN_0073f8a0();

        unaff_ESI = pvVar5;

      }

      else {

        uVar3 = FUN_00767160(&DAT_00a37c64,2);

        param_1[1] = param_1[1] | uVar3;

        uVar3 = (**(code **)(*(int *)*param_1 + 0x18))(&DAT_00a97b84,2);

        param_1[8] = 0;

        param_1[1] = uVar3 | param_1[1];

        FUN_0073f8a0();

      }

      goto LAB_00963ebc;

    }

    iVar6 = FUN_0076d1b0("C:\\vog\\1_code\\palantir\\palantir\\animation\\anmAnimMaster.cpp",0x58,

                         "anmAnimMaster: ESM_INTERNAL mode specified with no anmAnimEventsImpl!");

    if (iVar6 != 3) {

LAB_00963ddc:

      if (param_1[7] != 0) {

        uVar3 = FUN_00767160(&DAT_00a37c64,0);

        param_1[1] = param_1[1] | uVar3;

        uVar3 = (**(code **)(*(int *)*param_1 + 0x18))(&DAT_00a97b84,2);

        param_1[8] = 0;

        goto LAB_00963eb2;

      }

      goto LAB_00963de7;

    }

    _File = fopen("c:\\VOGCRASH.txt","w");

    if (_File == (FILE *)0x0) goto LAB_00963e63;

    pcVar11 = "anmAnimMaster: ESM_INTERNAL mode specified with no anmAnimEventsImpl!";

    uVar10 = 0x58;

  }

  else {

    if (*(int *)(param_2 + 0x20) != 1) {

      if (param_1[7] != 0) {

        uVar3 = FUN_00767160(&DAT_00a37c64,0);

        param_1[1] = param_1[1] | uVar3;

        uVar3 = (**(code **)(*(int *)*param_1 + 0x18))(&DAT_00a97b84,2);

        param_1[8] = 0;

LAB_00963eb2:

        param_1[1] = uVar3 | param_1[1];

        goto LAB_00963ebc;

      }

LAB_00963de7:

      unaff_ESI = (void *)0x0;

      uVar3 = (**(code **)(*(int *)*param_1 + 0x18))(&stack0xffffffdc,4);

      param_1[1] = param_1[1] | uVar3;

LAB_00963ebc:

      stoChunkWriter_EndChunk();

      ExceptionList = unaff_ESI;

      return 0;

    }

    if (*(int *)(param_2 + 0x1c) != 0) {

      piVar4 = (int *)(*(int *)(param_2 + 0x1c) + 4);

      if (param_1[7] == 0) {

        uVar3 = (**(code **)(*(int *)*param_1 + 0x18))(&stack0xffffffdc,4);

        param_1[1] = param_1[1] | uVar3;

        unaff_ESI = pvVar5;

      }

      else {

        uVar3 = FUN_00767160(&DAT_00a37c64,pvVar5);

        param_1[1] = param_1[1] | uVar3;

        uVar3 = (**(code **)(*(int *)*param_1 + 0x18))(&DAT_00a97b84,2);

        param_1[8] = 0;

        param_1[1] = uVar3 | param_1[1];

      }

      if (DAT_00d1a560 == (code *)0x0) {

        puStack_2c = param_1;

        stoChunkWriter_BeginChunk(DAT_00d1ed20,1);

        puVar7 = (undefined *)*piVar4;

        if (puVar7 == (undefined *)0x0) {

          puVar7 = PTR_DAT_00afa2bc;

        }

        if (param_1[7] == 0) {

          uVar3 = FUN_00436f80(param_1,puVar7);

          param_1[1] = param_1[1] | uVar3;

          stoChunkWriter_EndChunk();

        }

        else {

          uVar3 = FUN_00767160(&DAT_00a9d6f8,puVar7);

          param_1[1] = param_1[1] | uVar3;

          uVar3 = (**(code **)(*(int *)*param_1 + 0x18))(&DAT_00a97b84,2);

          param_1[8] = 0;

          param_1[1] = uVar3 | param_1[1];

          stoChunkWriter_EndChunk();

        }

      }

      else {

        puStack_2c = (uint32_t /* width from decompiler */ *)0x0;

        iVar6 = (*DAT_00d1a560)(piVar4,&puStack_2c);

        if (-1 < iVar6) {

          FUN_0096a6f0(param_1,0);

        }

      }

      goto LAB_00963ebc;

    }

    iVar6 = FUN_0076d1b0("C:\\vog\\1_code\\palantir\\palantir\\animation\\anmAnimMaster.cpp",0x67,

                         "anmAnimMaster: ESM_EXTERNAL mode specified with Unbound anmAnimEvents!");

    if (iVar6 != 3) goto LAB_00963ddc;

    _File = fopen("c:\\VOGCRASH.txt","w");

    if (_File == (FILE *)0x0) goto LAB_00963e63;

    pcVar11 = "anmAnimMaster: ESM_EXTERNAL mode specified with Unbound anmAnimEvents!";

    uVar10 = 0x67;

  }

  fprintf(_File,"errReport::Massive failure EH_Abort: F:%s l:%d s:%d d:%s\n",

          "C:\\vog\\1_code\\palantir\\palantir\\animation\\anmAnimMaster.cpp",uVar10,2,pcVar11);

  fclose(_File);

LAB_00963e63:

  raise(0x16);

                    /* WARNING: Subroutine does not return */

  ExitProcess(3);

}
