# Raw capture: gfxIndexBufferImpl_Serialize

| Field | Value |
|---|---|
| **Stable ID** | `aa_00988a10` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00988a10` |
| **Canonical name** | `gfxIndexBufferImpl_Serialize` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* gfxIndexBufferImpl::Serialize  [palantir\graphics\gfxIndexBufferImpl.cpp:0x123]
   Writes an INDX (file bytes "XDNI") chunk, version 2: body = u32 id/hash + u16 indexSize(2|4) +
   u16 count + u32 count2 + raw index data (count2 x indexSize). Indices form TRIANGLE LISTS
   (verified: every retail chunk count divisible by 3; no strip flag exists). Locks/unlocks the
   device IB (gfxDeviceIB.cpp) around the write. */

int __fastcall gfxIndexBufferImpl_Serialize(int param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009afa6a;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  stoChunkWriter_BeginChunk(0x494e4458,2);
  iVar4 = 0;
  local_4 = 0;
  if (*(int *)(param_1 + 0x10) != 0) {
    iVar4 = FUN_00743be0(*(undefined4 *)(param_1 + 0x18),*(undefined4 *)(param_1 + 0x1c),0x810);
    if (iVar4 != 0) {
      FUN_00734640(*(undefined4 *)(param_1 + 0x1c),*(undefined4 *)(param_1 + 0x14));
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
```
