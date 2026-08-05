# Annotated low-level: hkDefaultSteering_update

| Field | Value |
|---|---|
| Stable ID | `aa_0064f840` |
| VA | `0x0064f840` |
| System | input-drive-control |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0064f840`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall hkDefaultSteering_update(int param_1)

{
  int iVar1;
  float fVar2;
  float fVar3;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  iVar1 = *(int *)(param_1 + 8);
  fVar2 = *(float *)(*(int *)(iVar1 + 0x14) + 0x14) * *(float *)(param_1 + 0x24);
  FUN_005d6ae0(*(int *)(*(int *)(iVar1 + 0x30) + 0x3c) + 0x80,*(int *)(iVar1 + 0x10) + 0x10);
  iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 8) + 0x30) + 0x3c);
  fVar3 = *(float *)(iVar1 + 0x48) * local_18 + *(float *)(iVar1 + 0x44) * local_1c +
          *(float *)(iVar1 + 0x40) * local_20;
  if (*(float *)(param_1 + 0x28) <= fVar3) {
    fVar3 = *(float *)(param_1 + 0x28) / fVar3;
    fVar2 = fVar3 * fVar3 * fVar2;
  }
  iVar1 = 0;
  *(float *)(param_1 + 0x10) = fVar2;
  if (0 < *(int *)(param_1 + 0x30)) {
    do {
      if (*(char *)(iVar1 + *(int *)(param_1 + 0x2c)) == '\0') {
        *(undefined4 *)(*(int *)(param_1 + 0x14) + iVar1 * 4) = 0;
      }
      else {
        *(undefined4 *)(*(int *)(param_1 + 0x14) + iVar1 * 4) = *(undefined4 *)(param_1 + 0x10);
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(param_1 + 0x30));
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
