// READABILITY (auto CF):
//  - Body size: ~188 non-empty decompiler lines.
//  - Control keywords: if×17, goto×8, for×4, return×2, do×1, while×1.
//  - Notable callees: FUN_00767160×4, FUN_0076d1b0×4, fopen×4, FUN_0043b500×3, ExitProcess, FUN_00439810, FUN_007603a0, fclose.
//  - Strings: "

                               ,0x24c,"; "),

         iVar5 == 3)) {

        _File = fopen("; "Error serializing levels in gfxLODHandler_AutoAssault!"; "

                               ,0x25c,".
//  - Return sites: 2.

// =============================================================================
// Named_gfxLODHandler_AutoAssault_007603a0
// -----------------------------------------------------------------------------
// Stable ID: aa_007603a0
// Address:   0x007603a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "gfxLODHandler_AutoAssault"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint __thiscall Named_gfxLODHandler_AutoAssault_007603a0(int param_1,uint32_t /* width from decompiler */ *param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint uVar3;

  uint uVar4;

  int iVar5;

  FILE *_File;

  int *piVar6;

  uint *puVar7;

  uint32_t /* width from decompiler */ uVar8;

  char *pcVar9;

  int local_28;

  int local_24;

  uint uStack_20;

  int iStack_1c;

  uint uStack_18;

  int local_14;

  uint32_t /* width from decompiler */ *local_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puVar2 = param_2;

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009adb98;

  pvStack_c = ExceptionList;

  local_10 = param_2;

  ExceptionList = &pvStack_c;

  stoChunkWriter_BeginChunk(0x4c444141,1);

  local_4 = 0;

  param_2 = (uint32_t /* width from decompiler */ *)FUN_00439810();

  local_14 = *(int *)(param_1 + 0x10);

  local_28 = *(int *)(param_1 + 0xc);

  if (local_28 != local_14) {

    piVar6 = (int *)(local_28 + 0x14);

    do {

      uVar3 = FUN_0043b500(piVar6 + 3);

      uVar4 = FUN_0043b500(piVar6 + 4);

      uVar4 = (uint)param_2 | uVar3 | uVar4;

      if (((int)uVar4 < 0) &&

         (iVar5 = FUN_0076d1b0("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxLODHandler_AutoAssault.cpp"

                               ,0x24c,"Error serializing levels in gfxLODHandler_AutoAssault!"),

         iVar5 == 3)) {

        _File = fopen("c:\\VOGCRASH.txt","w");

        if (_File == (FILE *)0x0) goto LAB_0076077f;

        pcVar9 = "Error serializing levels in gfxLODHandler_AutoAssault!";

        uVar8 = 0x24c;

        goto LAB_00760764;

      }

      if (piVar6[-4] == 0) {

        iVar5 = 0;

      }

      else {

        iVar5 = piVar6[-3] - piVar6[-4] >> 2;

      }

      if (puVar2[7] == 0) {

        local_24 = iVar5;

        uVar3 = (**(code **)(*(int *)*puVar2 + 0x18))(&local_24,4);

        puVar2[1] = puVar2[1] | uVar3;

      }

      else {

        uVar3 = FUN_00767160(&DAT_00a9d718,iVar5);

        puVar2[1] = puVar2[1] | uVar3;

        uVar3 = (**(code **)(*(int *)*puVar2 + 0x18))(&DAT_00a97b84,2);

        puVar2[8] = 0;

        puVar2[1] = uVar3 | puVar2[1];

      }

      param_2 = (uint32_t /* width from decompiler */ *)(uVar4 | puVar2[1]);

      for (uVar3 = 0; (iVar5 = piVar6[-4], iVar5 != 0 && (uVar3 < (uint)(piVar6[-3] - iVar5 >> 2)));

          uVar3 = uVar3 + 1) {

        iVar1 = *(int *)(*(int *)(param_1 + 4) + 0xc0);

        for (uVar4 = 0;

            (iVar1 != 0 && (uVar4 < (uint)(*(int *)(*(int *)(param_1 + 4) + 0xc4) - iVar1 >> 2)));

            uVar4 = uVar4 + 1) {

          if (*(int *)(iVar1 + uVar4 * 4) == *(int *)(iVar5 + uVar3 * 4)) goto LAB_00760530;

        }

        uVar4 = 0xffffffff;

LAB_00760530:

        if (puVar2[7] == 0) {

          uVar8 = 4;

          puVar7 = &uStack_20;

          uStack_20 = uVar4;

        }

        else {

          uVar4 = FUN_00767160(&DAT_00a37c64,uVar4);

          puVar2[1] = puVar2[1] | uVar4;

          uVar8 = 2;

          puVar2[8] = 0;

          puVar7 = (uint *)&DAT_00a97b84;

        }

        uVar4 = (**(code **)(*(int *)*puVar2 + 0x18))(puVar7,uVar8);

        puVar2[1] = puVar2[1] | uVar4;

        param_2 = (uint32_t /* width from decompiler */ *)((uint)param_2 | puVar2[1]);

      }

      if (((int)param_2 < 0) &&

         (iVar5 = FUN_0076d1b0("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxLODHandler_AutoAssault.cpp"

                               ,0x25c,"Error serializing pieces in gfxLODHandler_AutoAssault!"),

         iVar5 == 3)) {

        _File = fopen("c:\\VOGCRASH.txt","w");

        if (_File == (FILE *)0x0) goto LAB_0076077f;

        pcVar9 = "Error serializing pieces in gfxLODHandler_AutoAssault!";

        uVar8 = 0x25c;

        goto LAB_00760764;

      }

      if (*piVar6 == 0) {

        iVar5 = 0;

      }

      else {

        iVar5 = piVar6[1] - *piVar6 >> 2;

      }

      if (puVar2[7] == 0) {

        iStack_1c = iVar5;

        uVar3 = (**(code **)(*(int *)*puVar2 + 0x18))(&iStack_1c,4);

        puVar2[1] = puVar2[1] | uVar3;

      }

      else {

        uVar3 = FUN_00767160(&DAT_00a9d718,iVar5);

        puVar2[1] = puVar2[1] | uVar3;

        uVar3 = (**(code **)(*(int *)*puVar2 + 0x18))(&DAT_00a97b84,2);

        puVar2[8] = 0;

        puVar2[1] = uVar3 | puVar2[1];

      }

      param_2 = (uint32_t /* width from decompiler */ *)((uint)param_2 | puVar2[1]);

      for (uVar3 = 0; (iVar5 = *piVar6, iVar5 != 0 && (uVar3 < (uint)(piVar6[1] - iVar5 >> 2)));

          uVar3 = uVar3 + 1) {

        iVar1 = *(int *)(*(int *)(param_1 + 4) + 0xd0);

        for (uVar4 = 0;

            (iVar1 != 0 && (uVar4 < (uint)(*(int *)(*(int *)(param_1 + 4) + 0xd4) - iVar1 >> 2)));

            uVar4 = uVar4 + 1) {

          if (*(int *)(iVar1 + uVar4 * 4) == *(int *)(iVar5 + uVar3 * 4)) goto LAB_0076066d;

        }

        uVar4 = 0xffffffff;

LAB_0076066d:

        if (puVar2[7] == 0) {

          uVar8 = 4;

          puVar7 = &uStack_18;

          uStack_18 = uVar4;

        }

        else {

          uVar4 = FUN_00767160(&DAT_00a37c64,uVar4);

          puVar2[1] = puVar2[1] | uVar4;

          uVar8 = 2;

          puVar2[8] = 0;

          puVar7 = (uint *)&DAT_00a97b84;

        }

        uVar4 = (**(code **)(*(int *)*puVar2 + 0x18))(puVar7,uVar8);

        puVar2[1] = puVar2[1] | uVar4;

        param_2 = (uint32_t /* width from decompiler */ *)((uint)param_2 | puVar2[1]);

      }

      if (((int)param_2 < 0) &&

         (iVar5 = FUN_0076d1b0("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxLODHandler_AutoAssault.cpp"

                               ,0x26c,"Error serializing shadows in gfxLODHandler_AutoAssault!"),

         iVar5 == 3)) {

        _File = fopen("c:\\VOGCRASH.txt","w");

        if (_File == (FILE *)0x0) goto LAB_0076077f;

        pcVar9 = "Error serializing shadows in gfxLODHandler_AutoAssault!";

        uVar8 = 0x26c;

        goto LAB_00760764;

      }

      local_28 = local_28 + 0x28;

      piVar6 = piVar6 + 10;

    } while (local_28 != local_14);

  }

  uVar3 = FUN_0043b500(param_1 + 0x1c);

  if ((-1 < (int)((uint)param_2 | uVar3)) ||

     (iVar5 = FUN_0076d1b0("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxLODHandler_AutoAssault.cpp"

                           ,0x276,"Error serializing dead band size in gfxLODHandler_AutoAssault!"),

     iVar5 != 3)) {

    local_4 = 0xffffffff;

    stoChunkWriter_EndChunk();

    ExceptionList = pvStack_c;

    return (uint)param_2 | uVar3;

  }

  _File = fopen("c:\\VOGCRASH.txt","w");

  if (_File != (FILE *)0x0) {

    pcVar9 = "Error serializing dead band size in gfxLODHandler_AutoAssault!";

    uVar8 = 0x276;

LAB_00760764:

    fprintf(_File,"errReport::Massive failure EH_Abort: F:%s l:%d s:%d d:%s\n",

            "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxLODHandler_AutoAssault.cpp",uVar8,3,

            pcVar9);

    fclose(_File);

  }

LAB_0076077f:

  raise(0x16);

                    /* WARNING: Subroutine does not return */

  ExitProcess(3);

}
