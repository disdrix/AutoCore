# Annotated low-level: FUN_008ab8f0

> **REDIRECT (2026-07-29):** Canonical annotated unit is
> [`aa_008ab8f0_Client_MissionDialog_FlushPreparedResponse.annotated.md`](aa_008ab8f0_Client_MissionDialog_FlushPreparedResponse.annotated.md).
> This scaffold annotated file is kept only for legacy path stability.

| Field | Value |
|---|---|
| Stable ID | `aa_008ab8f0` |
| VA | `0x008ab8f0` |
| System | missions-progression (promoted; was unknown) |
| Date | 2026-07-23 (scaffold); sealed 2026-07-29 |

## Machine-level notes

- Source: raw capture for `aa_008ab8f0`.
- Prefer assembly when decompiler conflicts.
- **Promoted name:** `Client_MissionDialog_FlushPreparedResponse` — C2S `0x206E` flush (size `0x20` from `dialog+0x650`).
- Prefer the promoted annotated file for widths / side effects.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_008ab8f0(int *param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  
  if ((param_1[0x194] != 0) && (g_pSectorNetConnection_INFERRED != (void *)0x0)) {
    (**(code **)(*(int *)g_pSectorNetConnection_INFERRED + 0x18))(0xffffffff,param_1 + 0x194,0x20,0)
    ;
  }
  if ((((DAT_00d1d8dc != (int *)0x0) &&
       (cVar1 = (**(code **)(*DAT_00d1d8dc + 0x3d8))(), cVar1 != '\0')) &&
      (cVar1 = (**(code **)(*DAT_00d1d8dc + 0xd0))(), cVar1 != '\0')) && (DAT_00d1d8dc[0x146] != 0))
  {
    iVar3 = 0;
    piVar2 = param_1 + 0x156;
    do {
      if ((*piVar2 == DAT_00d1d8dc[0x148]) && (piVar2[1] == DAT_00d1d8dc[0x149])) {
        DAT_00d1d8f4 = 1;
        DAT_00d1d8f5 = 0;
        (**(code **)(*DAT_00d1d8dc + 4))(0);
        break;
      }
      iVar3 = iVar3 + 1;
      piVar2 = piVar2 + 2;
    } while (iVar3 < 4);
  }
  FUN_008aa320();
  (**(code **)(*param_1 + 0x3ac))();
  FUN_00792490();
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
