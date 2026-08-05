# Annotated low-level: CVOGSectorMap_DoCreatorLoadTrigger

| Field | Value |
|---|---|
| Stable ID | `aa_004cdd20` |
| VA | `0x004cdd20` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004cdd20`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* DoCreatorLoadTrigger: once per map instance (flag sector+0x74). Look up m_coidCreatorLoadTrigger
   (sector+0xE7E8) and fire vtable+0x114. Called from CVOGSectorMap_AddCharacter when character
   count condition met. */

void __fastcall CVOGSectorMap_DoCreatorLoadTrigger(int param_1)

{
  DWORD DVar1;
  int iVar2;
  
  if (*(char *)(param_1 + 0x74) == '\0') {
    *(undefined1 *)(param_1 + 0x74) = 1;
    DVar1 = GetTickCount();
    *(DWORD *)(param_1 + 0x6c) = DVar1;
    iVar2 = FUN_004bb1c0(0,*(undefined4 *)(param_1 + 0xe7e8),*(undefined4 *)(param_1 + 0xe7ec));
    if (iVar2 != 0) {
                    /* WARNING: Could not recover jumptable at 0x004cdd86. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(*(int *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 4 + iVar2) + 0x114))();
      return;
    }
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
