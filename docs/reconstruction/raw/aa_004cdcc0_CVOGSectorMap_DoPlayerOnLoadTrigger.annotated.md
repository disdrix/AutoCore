# Annotated low-level: CVOGSectorMap_DoPlayerOnLoadTrigger

| Field | Value |
|---|---|
| Stable ID | `aa_004cdcc0` |
| VA | `0x004cdcc0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004cdcc0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* CVOGSectorMap_DoPlayerOnLoadTrigger: fire m_coidPerPlayerLoadTrigger after character add.
   Server: SectorMap.FireOnLoadPlayerMissions after Stage3 creates. */

void __fastcall CVOGSectorMap_DoPlayerOnLoadTrigger(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_004bb1c0(0,*(undefined4 *)(param_1 + 0xe7e0),*(undefined4 *)(param_1 + 0xe7e4));
  if (iVar1 != 0) {
                    /* WARNING: Could not recover jumptable at 0x004cdd0d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 4 + iVar1) + 0x114))();
    return;
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
