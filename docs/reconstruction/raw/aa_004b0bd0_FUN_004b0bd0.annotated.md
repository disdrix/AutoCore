# Annotated low-level: FUN_004b0bd0 / ObjectMotion_SlotEmptyDtor_Inferred

| Field | Value |
|---|---|
| Stable ID | `aa_004b0bd0` |
| VA | `0x004b0bd0`–`0x004b0bd1` exclusive (**1** B) |
| Canonical | `ObjectMotion_SlotEmptyDtor_Inferred` |
| System | client object motion / reaction slot freelist |
| Date | 2026-07-29 (W30-R dual seal) |

## Machine-level notes

- **Body:** single byte `C3` (`ret`). Following `CC` pad is **not** body.
- **No** stack cleanup (`ret` not `ret n`); ignores ECX and any pushed args.
- **Callees:** none. Classification: **stub**.
- **Sole caller:** `ObjectMotion_SlotReleaseToFreelist_Inferred` (`FUN_005be2b0`) — twice per release:
  1. optional child payload @ `node+0x8`
  2. the slot node itself
- Call sites use thiscall shape (`mov ecx, …; call`) purely so the empty leaf has a normal thiscall epilogue shape; stub returns immediately.

## Pseudocode (annotated)

```c
// thiscall at call sites; body ignores this
void ObjectMotion_SlotEmptyDtor_Inferred(void /*this*/)
{
  return;
}
```

## Distinction

| VA | Name | Role |
|---|---|---|
| `0x004b0bd0` | `ObjectMotion_SlotEmptyDtor_Inferred` | private empty dtor of motion-slot freelist release |
| `0x0056f570` | `EmptyRet` | mass-shared multi-role empty ret |
| `0x005081f0` | `CVOGHBBase_EmptyVFunc` | HB vtable empty |

## Open residual

- Why a dedicated empty dtor leaf remains (stripped MSVC dtor vs intentional nop) — behavior sealed either way.
- Product/PDB English.
