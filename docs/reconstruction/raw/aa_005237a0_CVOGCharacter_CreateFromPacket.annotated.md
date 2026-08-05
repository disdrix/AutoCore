# Annotated low-level: CVOGCharacter_CreateFromPacket

| Field | Value |
|---|---|
| Stable ID | `aa_005237a0` |
| VA | `0x005237a0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005237a0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall
CVOGCharacter_CreateFromPacket
          (int param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 param_5,
          undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  DWORD DVar1;
  int iVar2;
  int iVar3;
  
  FUN_005c9120(param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  if (((*(uint *)(param_1 + -0xb90) & *(uint *)(param_1 + -0xb8c)) != 0xffffffff) && (param_4 != 0))
  {
    DVar1 = GetTickCount();
    *(DWORD *)(param_1 + -0xd8c) = DVar1;
    iVar2 = FUN_004bafe0(*(undefined1 *)
                          (*(int *)(*(int *)(param_1 + -0xd9c) + 4) + -0xc34 + param_1),
                         *(undefined4 *)(param_1 + -0xb90),*(undefined4 *)(param_1 + -0xb8c));
    *(int *)(param_1 + -0xb50) = iVar2;
    if (iVar2 != 0) {
      if (param_1 == 0xda0) {
        iVar3 = 0;
      }
      else {
        iVar3 = *(int *)(*(int *)(param_1 + -0xd9c) + 4) + -0xd9c + param_1;
      }
      FUN_005131b0(iVar3);
      (**(code **)(*(int *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 4 + iVar2) + 0x218))
                (*(undefined4 *)(*(int *)(*(int *)(param_1 + -0xd9c) + 4) + -0xcf8 + param_1));
    }
    if (((char)param_7 == '\0') ||
       ((*(uint *)(*(int *)(*(int *)(param_1 + -0xd9c) + 4) + -0xc20 + param_1) >> 6 & 1) == 0)) {
      FUN_00521310(param_2,param_3,param_5,param_6,param_7,0);
    }
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
