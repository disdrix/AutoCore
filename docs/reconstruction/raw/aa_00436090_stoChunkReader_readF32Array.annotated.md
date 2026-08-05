# Annotated low-level: stoChunkReader_readF32Array

| Field | Value |
|---|---|
| Stable ID | `aa_00436090` |
| VA | `0x00436090` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_00436090`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* stoChunkReader read-N-float32 helper.
   Reads in_EAX (count, passed in EAX) little-endian f32 values into param_1 (fast path when
   *(param_2+0x4044)==0), else reads each element via FUN_00767fd0 (byte-swap path).
   Used by phyBoneSharedData_unserialize to read the hkQsTransform components (quaternion /
   translation / scale vectors). */

undefined4 __thiscall stoChunkReader_readF32Array(undefined4 *param_1,int param_2)

{
  int in_EAX;
  int iVar1;
  undefined4 uVar2;
  
  if (*(int *)(param_2 + 0x4044) == 0) {
    if (0xf < in_EAX) {
      uVar2 = FUN_00435f30(param_1,in_EAX * 4);
      return uVar2;
    }
    if (-1 < in_EAX + -1) {
      do {
        if ((*(int *)(param_2 + 0x18) + 4 <= *(int *)(param_2 + 0x20)) ||
           ((iVar1 = FUN_00435df0(*(int *)(param_2 + 0x1c) + *(int *)(param_2 + 0x18)), -1 < iVar1
            && (3 < *(int *)(param_2 + 0x20))))) {
          *param_1 = *(undefined4 *)(param_2 + 0x2c + *(int *)(param_2 + 0x18));
          *(int *)(param_2 + 0x18) = *(int *)(param_2 + 0x18) + 4;
        }
        param_1 = param_1 + 1;
        in_EAX = in_EAX + -1;
      } while (in_EAX != 0);
      return 0;
    }
  }
  else if (-1 < in_EAX + -1) {
    do {
      FUN_00767fd0(param_1);
      param_1 = param_1 + 1;
      in_EAX = in_EAX + -1;
    } while (in_EAX != 0);
  }
  return 0;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
