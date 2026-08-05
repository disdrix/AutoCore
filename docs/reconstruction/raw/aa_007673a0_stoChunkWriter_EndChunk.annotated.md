# Annotated low-level: stoChunkWriter_EndChunk

| Field | Value |
|---|---|
| Stable ID | `aa_007673a0` |
| VA | `0x007673a0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_007673a0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

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

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
