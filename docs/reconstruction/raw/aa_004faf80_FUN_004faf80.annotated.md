# Annotated low-level: FUN_004faf80

| Field | Value |
|---|---|
| Stable ID | `aa_004faf80` |
| VA | `0x004faf80` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004faf80`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_004faf80(int param_1)

{
  int iVar1;
  int iVar2;
  float10 fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  
  if (*(int *)(param_1 + 0x118) == 1) {
    iVar1 = *(int *)(*(int *)(param_1 + 8) + 0x3c);
    iVar2 = *(int *)(param_1 + 0x1a4);
    *(undefined4 *)(iVar2 + 0x40) = *(undefined4 *)(iVar1 + 0xb0);
    *(undefined4 *)(iVar2 + 0x44) = *(undefined4 *)(iVar1 + 0xb4);
    *(undefined4 *)(iVar2 + 0x48) = *(undefined4 *)(iVar1 + 0xb8);
    *(undefined4 *)(iVar2 + 0x4c) = *(undefined4 *)(iVar1 + 0xbc);
    iVar1 = *(int *)(*(int *)(param_1 + 8) + 0x3c);
    iVar2 = *(int *)(param_1 + 0x1a4);
    *(undefined4 *)(iVar2 + 0x60) = *(undefined4 *)(iVar1 + 0x30);
    *(undefined4 *)(iVar2 + 100) = *(undefined4 *)(iVar1 + 0x34);
    *(undefined4 *)(iVar2 + 0x68) = *(undefined4 *)(iVar1 + 0x38);
    *(undefined4 *)(iVar2 + 0x6c) = *(undefined4 *)(iVar1 + 0x3c);
    iVar1 = *(int *)(param_1 + 0x1a4);
    fVar3 = (float10)FUN_004cd220(*(undefined4 *)(iVar1 + 0x40),*(undefined4 *)(iVar1 + 0x48));
    *(float *)(*(int *)(param_1 + 0x1a4) + 0x50) =
         (float)((float10)*(float *)(iVar1 + 0x44) - fVar3);
    iVar1 = *(int *)(param_1 + 0x1a4);
    *(undefined4 *)(iVar1 + 0x40) = *(undefined4 *)(iVar1 + 0x40);
    *(undefined4 *)(iVar1 + 0x44) = 0;
    *(undefined4 *)(iVar1 + 0x48) = *(undefined4 *)(iVar1 + 0x48);
    *(undefined4 *)(iVar1 + 0x4c) = 0;
    iVar1 = *(int *)(param_1 + 0x1a4);
    fVar6 = *(float *)(iVar1 + 0x48) - *(float *)(iVar1 + 0x18);
    fVar5 = *(float *)(iVar1 + 0x44) - *(float *)(iVar1 + 0x14);
    fVar4 = *(float *)(iVar1 + 0x40) - *(float *)(iVar1 + 0x10);
    *(float *)(iVar1 + 0x7c) = SQRT(fVar4 * fVar4 + fVar5 * fVar5 + fVar6 * fVar6);
    iVar1 = *(int *)(param_1 + 0x1a4);
    if (*(float *)(iVar1 + 0x90) <= *(float *)(iVar1 + 0x7c) &&
        *(float *)(iVar1 + 0x7c) != *(float *)(iVar1 + 0x90)) {
      *(undefined4 *)(iVar1 + 0x90) = *(undefined4 *)(iVar1 + 0x7c);
      **(undefined1 **)(param_1 + 0x1a4) = 1;
    }
    iVar1 = *(int *)(param_1 + 0x1a4);
    if (*(float *)(iVar1 + 0x98) <= *(float *)(iVar1 + 0x84) &&
        *(float *)(iVar1 + 0x84) != *(float *)(iVar1 + 0x98)) {
      *(undefined4 *)(iVar1 + 0x98) = *(undefined4 *)(iVar1 + 0x84);
      **(undefined1 **)(param_1 + 0x1a4) = 1;
    }
    iVar1 = *(int *)(param_1 + 0x1a4);
    if (*(float *)(iVar1 + 0x94) <= *(float *)(iVar1 + 0x80) &&
        *(float *)(iVar1 + 0x80) != *(float *)(iVar1 + 0x94)) {
      *(undefined4 *)(iVar1 + 0x94) = *(undefined4 *)(iVar1 + 0x80);
      **(undefined1 **)(param_1 + 0x1a4) = 1;
    }
    *(undefined4 *)(param_1 + 0x118) = 2;
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
