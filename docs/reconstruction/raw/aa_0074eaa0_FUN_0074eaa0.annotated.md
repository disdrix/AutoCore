# Annotated low-level: FUN_0074eaa0

| Field | Value |
|---|---|
| Stable ID | `aa_0074eaa0` |
| VA | `0x0074eaa0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0074eaa0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_0074eaa0(void)

{
  int iVar1;
  uint uVar2;
  int unaff_ESI;
  uint uVar3;
  float10 fVar4;
  
  if ((*(int *)(unaff_ESI + 4) != 0) &&
     (uVar2 = *(int *)(unaff_ESI + 8) - *(int *)(unaff_ESI + 4) >> 2, uVar2 != 0)) {
    FUN_00449000(uVar2,0);
    FUN_00449000(uVar2,0);
    uVar3 = 0;
    if (uVar2 != 0) {
      do {
        iVar1 = uVar3 * 4;
        *(float *)(*(int *)(unaff_ESI + 0x18) + iVar1) = g_flOne;
        (**(code **)(**(int **)(*(int *)(unaff_ESI + 4) + iVar1) + 0x10))
                  (*(int *)(unaff_ESI + 0x28) + iVar1);
        uVar3 = uVar3 + 1;
      } while (uVar3 < uVar2);
    }
    fVar4 = (float10)(**(code **)(*(int *)**(undefined4 **)(unaff_ESI + 4) + 4))();
    *(float *)(unaff_ESI + 0x48) = (float)fVar4;
  }
  FUN_0074e9d0(0x3f800000);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
