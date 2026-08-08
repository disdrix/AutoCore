# Function record: CVOGHBAI_DecEntityA4SecondaryCounter_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005cc560` |
| **Canonical name** | `CVOGHBAI_DecEntityA4SecondaryCounter_Inferred` |
| **Ghidra name** | `FUN_005cc560` |
| **Address** | `0x005cc560`–`0x005cc5ad` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | input-drive-control / npc-ai / HBAI entity counters |
| **Wave** | MEGA-093 OWN dual |
| **Verdict** | **accept-with-gaps** |

## Signature

```c
void __thiscall CVOGHBAI_DecEntityA4SecondaryCounter_Inferred(void *self);
```

## Sealed contract

1. Load entity from `this+0x18`; return if null.
2. Load counters from `entity+0xA4`; return if null.
3. `related = entity->vtbl[+0x214]()` (thiscall entity).
4. If related null, return.
5. If `related+0x250 == 0`: `counters[+0x18]--`; else `counters[+0x1c]--`.
6. No stack formals; plain ret via `0x005081e0`.

## Naming

- Structural: entity A4 secondary counter pair (`+0x18`/`+0x1c`) selected by related `+0x250`.
- `_Inferred`: product plate for counter role / related getter / `+0x250` English open.
- RTTI hosts: `CVOGHBAICreatureBase` family; Driver park override tails into this.

## Artifacts

See `aa_005cc560_FUN_005cc560.md` for full paths.
