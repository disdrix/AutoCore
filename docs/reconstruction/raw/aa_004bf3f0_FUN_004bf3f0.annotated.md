# Annotated low-level: FUN_004bf3f0

| Field | Value |
|---|---|
| Stable ID | `aa_004bf3f0` |
| VA | `0x004bf3f0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004bf3f0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_004bf3f0(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  void *pvVar3;
  
  uVar1 = *(undefined4 *)(param_1 + 0x590);
  uVar2 = *(undefined4 *)(param_1 + 0x58c);
  if (*(void **)(param_1 + 0x57c) != *(void **)(param_1 + 0x580)) {
    pvVar3 = memmove(*(void **)(param_1 + 0x57c),*(void **)(param_1 + 0x580),0);
    *(void **)(param_1 + 0x580) = pvVar3;
  }
  FUN_004bf830(*(undefined4 *)(param_1 + 0x57c),uVar2,uVar1,param_1);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
