# Annotated low-level: FUN_005afc80

| Field | Value |
|---|---|
| Stable ID | `aa_005afc80` |
| VA | `0x005afc80` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005afc80`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_005afc80(int param_1,int *param_2,int param_3,int param_4)

{
  int *piVar1;
  int *_Dst;
  void *pvVar2;
  int iVar3;
  
  iVar3 = *(int *)(*(int *)(*(int *)(param_1 + 0x10) + (*(uint *)(param_1 + 8) & (uint)param_2) * 4)
                  + 4);
  if (iVar3 == 0) {
LAB_005afcab:
    iVar3 = 0;
  }
  else {
    do {
      if (param_2 == *(int **)(iVar3 + 0x10)) {
        if (iVar3 == 0) goto LAB_005afcab;
        iVar3 = *(int *)(iVar3 + 8);
        goto LAB_005afcb2;
      }
      iVar3 = *(int *)(iVar3 + 0xc);
    } while (iVar3 != 0);
    iVar3 = 0;
  }
LAB_005afcb2:
  if (iVar3 != 0) {
    piVar1 = *(int **)(iVar3 + 0x5c);
    for (_Dst = *(int **)(iVar3 + 0x58); _Dst != piVar1; _Dst = _Dst + 2) {
      if ((*_Dst == param_3) && (_Dst[1] == param_4)) {
        if (_Dst != piVar1) {
          FUN_005b08d0(&param_2,_Dst + 2,piVar1,_Dst,&param_3);
          _Dst = param_2;
        }
        break;
      }
    }
    if (_Dst != *(int **)(iVar3 + 0x5c)) {
      pvVar2 = memmove(_Dst,*(int **)(iVar3 + 0x5c),0);
      *(void **)(iVar3 + 0x5c) = pvVar2;
    }
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
