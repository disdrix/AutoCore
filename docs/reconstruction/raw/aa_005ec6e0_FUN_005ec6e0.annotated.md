# Annotated low-level: FUN_005ec6e0

| Field | Value |
|---|---|
| Stable ID | `aa_005ec6e0` |
| VA | `0x005ec6e0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005ec6e0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_005ec6e0(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (*(int *)(param_1 + 0x54) - *(int *)(param_1 + 0x50) >> 2 != 0) {
    do {
      uVar1 = 0;
      if (*(int *)(param_2 + 0x54) - *(int *)(param_2 + 0x50) >> 2 != 0) {
        do {
          if (*(int *)(*(int *)(param_1 + 0x50) + uVar2 * 4) ==
              *(int *)(*(int *)(param_2 + 0x50) + uVar1 * 4)) {
            if ((uint)(*(int *)(param_2 + 0x54) - *(int *)(param_2 + 0x50) >> 2) < 2) {
              *(undefined4 *)(param_2 + 0x54) = *(undefined4 *)(param_2 + 0x50);
            }
            else {
              if (uVar1 != (*(int *)(param_2 + 0x54) - *(int *)(param_2 + 0x50) >> 2) - 1U) {
                *(undefined4 *)(*(int *)(param_2 + 0x50) + uVar1 * 4) =
                     *(undefined4 *)(*(int *)(param_2 + 0x54) + -4);
              }
              *(int *)(param_2 + 0x54) = *(int *)(param_2 + 0x54) + -4;
            }
          }
          else {
            uVar1 = uVar1 + 1;
          }
        } while (uVar1 < (uint)(*(int *)(param_2 + 0x54) - *(int *)(param_2 + 0x50) >> 2));
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < (uint)(*(int *)(param_1 + 0x54) - *(int *)(param_1 + 0x50) >> 2));
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
