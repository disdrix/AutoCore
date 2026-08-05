// =============================================================================
// gfxIndexBufferImpl_Serialize
// -----------------------------------------------------------------------------
// Purpose:  Write INDX ("XDNI") chunk v2: id + indexSize(2|4) + counts + raw
//           triangle-list indices. Locks device IB around write.
//
// Address:  0x00988a10  (autoassault.exe, image base 0x400000)
// Stable:   aa_00988a10
// System:   graphics / gfx (asset I/O)
//
// Layout: u32 id · u16 indexSize · u16 count · u32 count2 · data[count2*indexSize]
// Topology: D3DPT_TRIANGLELIST (no strip flag).
// =============================================================================

int __fastcall gfxIndexBufferImpl_Serialize(int param_1)



{

  int *piVar1;

  int *piVar2;

  int *piVar3;

  int iVar4;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009afa6a;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  stoChunkWriter_BeginChunk(0x494e4458,2);

  iVar4 = 0;

  local_4 = 0;

  if (*(int *)(param_1 + 0x10) != 0) {

    iVar4 = FUN_00743be0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x18),*(uint32_t /* width from decompiler */ *)(param_1 + 0x1c),0x810);

    if (iVar4 != 0) {

      FUN_00734640(*(uint32_t /* width from decompiler */ *)(param_1 + 0x1c),*(uint32_t /* width from decompiler */ *)(param_1 + 0x14));

    }

  }

  FUN_0044c9e0();

  FUN_00439870();

  if (iVar4 == 0) {

    iVar4 = -1;

  }

  else {

    iVar4 = FUN_0044ed10();

  }

  piVar2 = *(int **)(param_1 + 0x10);

  if ((piVar2 != (int *)0x0) && (piVar3 = (int *)*piVar2, piVar3 != (int *)0x0)) {

    piVar1 = piVar2 + 3;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 < 0) {

      vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxDeviceIB.cpp",0xca,1,

                     "Call to gfxDeviceIB::Unlock more times than locked! Bad mojo...");

      piVar2[3] = 0;

    }

    else {

      (**(code **)(*piVar3 + 0x30))(piVar3);

    }

  }

  if (iVar4 < 0) {

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxIndexBufferImpl.cpp",0x123,3,

                   "Failed to Serialize Index Buffer");

  }

  local_4 = 0xffffffff;

  stoChunkWriter_EndChunk();

  ExceptionList = local_c;

  return iVar4;

}
