# Raw capture: stoChunkWriter_EndChunk

| Field | Value |
|---|---|
| **Stable ID** | `aa_007673a0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007673a0` |
| **Canonical name** | `stoChunkWriter_EndChunk` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* stoChunkWriter::EndChunk()  [arda2\storage\stoChunk.cpp]
   Binary mode: pops the chunk stack, computes size = tell() - headerPos - 0x10 (so the size field
   EXCLUDES the 16-byte header), seeks back, rewrites the 16-byte header with the real size, seeks
   to end. Text mode: writes closing '}'. */

undefined4 __fastcall stoChunkWriter_EndChunk(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  if (param_1[7] == 0) {
    uVar3 = (param_1[6] + param_1[5]) - 1;
    if ((uint)param_1[4] <= uVar3) {
      uVar3 = uVar3 - param_1[4];
    }
    iVar2 = *(int *)(param_1[3] + uVar3 * 4);
    iVar1 = (**(code **)(*(int *)*param_1 + 0x30))();
    *(int *)(iVar2 + 4) = (iVar1 - *(int *)(iVar2 + 0x10)) + -0x10;
    uVar3 = (**(code **)(*(int *)*param_1 + 4))(*(int *)(iVar2 + 0x10),0);
    param_1[1] = param_1[1] | uVar3;
    uVar3 = (**(code **)(*(int *)*param_1 + 0x18))(iVar2,0x10);
    param_1[1] = param_1[1] | uVar3;
    uVar3 = (**(code **)(*(int *)*param_1 + 4))(iVar1,0);
    param_1[1] = param_1[1] | uVar3;
  }
  if ((param_1[6] != 0) && (iVar2 = param_1[6] + -1, param_1[6] = iVar2, iVar2 == 0)) {
    param_1[5] = 0;
  }
  if (param_1[7] == 1) {
    uVar3 = FUN_00767160(&DAT_00a6bfd0);
    param_1[1] = param_1[1] | uVar3;
    param_1[8] = 0;
    uVar3 = (**(code **)(*(int *)*param_1 + 0x18))(&DAT_00a97b84,2);
    param_1[1] = param_1[1] | uVar3;
  }
  return param_1[1];
}
```
