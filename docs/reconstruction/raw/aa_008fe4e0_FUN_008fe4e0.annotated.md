# Annotated low-level: FUN_008fe4e0

| Field | Value |
|---|---|
| Stable ID | `aa_008fe4e0` |
| VA | `0x008fe4e0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_008fe4e0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_008fe4e0(void)

{
  int in_EAX;
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  
  if ((((DAT_00d1b6d8 != 0) && (*(int *)(in_EAX + 0x72c) != 0)) && (*(int *)(in_EAX + 0x73c) != 0))
     && (*(int *)(in_EAX + 0x600) != 0)) {
    iVar3 = 0;
    if (0 < *(int *)(in_EAX + 0x51c)) {
      do {
        iVar1 = *(int *)(in_EAX + 0x524) + iVar3;
        if (iVar1 < *(int *)(in_EAX + 0x514)) {
          if (*(int *)(*(int *)(in_EAX + 0x600) + iVar1 * 4) != 0) {
            iVar1 = **(int **)(*(int *)(in_EAX + 0x72c) + iVar3 * 4);
            uVar2 = (**(code **)(**(int **)(*(int *)(in_EAX + 0x72c) + iVar3 * 4) + 0x2c8))(0);
            (**(code **)(iVar1 + 0x50))
                      (*(undefined4 *)
                        (*(int *)(in_EAX + 0x600) + (*(int *)(in_EAX + 0x524) + iVar3) * 4),uVar2);
            (**(code **)(**(int **)(*(int *)(in_EAX + 0x72c) + iVar3 * 4) + 0xfc))(1,0x3f000000);
            if (*(int *)(in_EAX + 0x52c) + -1 == *(int *)(in_EAX + 0x524) + iVar3) {
              pcVar4 = "i_d_body_2d_btn_uninstall";
            }
            else {
              pcVar4 = (char *)(in_EAX + 0x604);
            }
            (**(code **)(**(int **)(*(int *)(in_EAX + 0x73c) + iVar3 * 4) + 0x3ac))(pcVar4);
            (**(code **)(**(int **)(*(int *)(in_EAX + 0x73c) + iVar3 * 4) + 0xfc))(1,0x3f000000);
          }
        }
        else {
          (**(code **)(**(int **)(*(int *)(in_EAX + 0x72c) + iVar3 * 4) + 0x58))();
          (**(code **)(**(int **)(*(int *)(in_EAX + 0x72c) + iVar3 * 4) + 0xcc))(0);
          (**(code **)(**(int **)(*(int *)(in_EAX + 0x73c) + iVar3 * 4) + 0xcc))(0);
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < *(int *)(in_EAX + 0x51c));
    }
    FUN_008fc650();
    FUN_008fdb60(in_EAX);
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
