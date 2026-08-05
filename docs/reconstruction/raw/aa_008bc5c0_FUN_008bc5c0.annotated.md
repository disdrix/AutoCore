# Annotated low-level: FUN_008bc5c0

| Field | Value |
|---|---|
| Stable ID | `aa_008bc5c0` |
| VA | `0x008bc5c0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_008bc5c0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_008bc5c0(void)

{
  int iVar1;
  int unaff_ESI;
  char *pcVar2;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  if ((*(int *)(unaff_ESI + 0x518) != 0) && (DAT_00d1b6d8 != 0)) {
    if (*(char *)(unaff_ESI + 0x514) != '\0') {
      if (*(int *)(DAT_00d1b6d8 + 0xcb0) == 0) {
LAB_008bc601:
        iVar1 = **(int **)(unaff_ESI + 0x518);
        uStack_c = 1;
        uStack_10 = 1;
        uStack_14 = 0xffffffff;
        pcVar2 = "Killing Spree!";
        FUN_007a69d0("Killing Spree!");
        uStack_14 = FUN_007a6de0(pcVar2);
        (**(code **)(iVar1 + 0x1d8))();
        iVar1 = (**(code **)(**(int **)(unaff_ESI + 0x518) + 0x164))(1);
        uStack_14 = CONCAT13(*(undefined1 *)(iVar1 + 3),0xff8000);
        (**(code **)(**(int **)(unaff_ESI + 0x518) + 0x15c))(1,&uStack_14);
        (**(code **)(**(int **)(unaff_ESI + 0x518) + 0x34c))();
        *(undefined1 *)(unaff_ESI + 0x514) = 0;
        return;
      }
      uStack_c = 0x8bc5f8;
      iVar1 = FUN_00574780();
      if (iVar1 < 2) goto LAB_008bc601;
      if (*(char *)(unaff_ESI + 0x514) != '\0') {
        return;
      }
    }
    if (*(int *)(DAT_00d1b6d8 + 0xcb0) != 0) {
      uStack_c = 0x8bc6a6;
      iVar1 = FUN_00574780();
      if (1 < iVar1) {
        iVar1 = **(int **)(unaff_ESI + 0x518);
        uStack_c = 1;
        uStack_10 = 1;
        uStack_14 = 0xffffffff;
        pcVar2 = "Convoy - Killing Spree!";
        FUN_007a69d0("Convoy - Killing Spree!");
        uStack_14 = FUN_007a6de0(pcVar2);
        (**(code **)(iVar1 + 0x1d8))();
        iVar1 = (**(code **)(**(int **)(unaff_ESI + 0x518) + 0x164))(1);
        uStack_14 = CONCAT13(*(undefined1 *)(iVar1 + 3),0xffe400);
        (**(code **)(**(int **)(unaff_ESI + 0x518) + 0x15c))(1,&uStack_14);
        (**(code **)(**(int **)(unaff_ESI + 0x518) + 0x34c))();
        *(undefined1 *)(unaff_ESI + 0x514) = 1;
      }
    }
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
