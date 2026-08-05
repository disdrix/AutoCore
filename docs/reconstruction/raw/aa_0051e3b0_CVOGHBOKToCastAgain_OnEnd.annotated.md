# Annotated low-level: CVOGHBOKToCastAgain_OnEnd

| Field | Value |
|---|---|
| Stable ID | `aa_0051e3b0` |
| VA | `0x0051e3b0` |
| System | skills-abilities |
| Date | 2026-07-23 |
| Residual | 2026-07-29 (`reviews/a_0051e3b0.md`) |

## Machine-level notes

- Source: raw capture + `read_memory` body seal.
- Prefer assembly when decompiler conflicts (`unaff_SI` is phantom).
- `HB+0x18` = owner object; `HB+0x24` = skill (ctor + AttachOwner).
- `FUN_005081f0` = shared empty stub (`C3`), not real cleanup.
- Sole xref: vtbl DATA `0x009ce1d8` (slot +0x14 of `0x009ce1c4`).

## Pseudocode (machine-faithful)

```c
/* CVOGHBOKToCastAgain_OnEnd (HB complete/abort, vtbl+0x14) */

void __thiscall CVOGHBOKToCastAgain_OnEnd(void *pHeartbeat)
{
  if (*(int *)((int)pHeartbeat + 0x18) != 0) {
    Skill_SetIsCastingFlag(*(void **)((int)pHeartbeat + 0x24), /*bIsCasting=*/0);
  }
  /* tail jmp */ FUN_005081f0();  /* empty ret @ 0x005081f0 */
}
```

## Bytes (authoritative)

```
56 8B F1 83 7E 18 00 74 0A 8B 4E 24 6A 00 E8 0D 1F 03 00
8B CE 5E E9 25 9E FE FF
```

## Open questions

- Product English for `FUN_005081f0` (behavior sealed no-op).
- Enumerate vcall sites of `vtbl+0x14` (sibling units).
