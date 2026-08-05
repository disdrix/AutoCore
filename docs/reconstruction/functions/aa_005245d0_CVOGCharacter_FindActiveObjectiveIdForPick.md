# Function record: CVOGCharacter_FindActiveObjectiveIdForPick

| Field | Value |
|---|---|
| **Stable ID** | `aa_005245d0` |
| **Canonical name** | `CVOGCharacter_FindActiveObjectiveIdForPick` |
| **Prior** | `FUN_005245d0`; scaffold `CVOGCharacter_FindActiveObjectiveIdForInteractAlt`; assert-noise `Named_VOG_DEBUG_STOP` risk |
| **Address** | `0x005245d0` |
| **System** | interaction-activation |
| **Status** | **Human-refined** — three-rep + dual A/B 2026-07-29 |
| **Runtime** | Open |

## Purpose

`thiscall` on character: walk active-objective hash `char+0x548`; return **objective id** (`instance+0x10`) of first objective whose evaluators match the world object via `FUN_0059da10` (**vtable+0x44**), or **0**.

Sibling of `CVOGCharacter_FindActiveObjectiveIdForInteract` (`0x00524520` / `FUN_0059d9c0` / **+0x40**). Same walk/return shape; different evaluator slot and call-site bias (pick/hover select vs IfInteractable id fill).

## Related

| Kind | Path |
|------|------|
| Raw / annotated | `raw/aa_005245d0_*` |
| Clean | `reconstructed-exact/CVOGCharacter_FindActiveObjectiveIdForPick.cpp` |
| Reviews | `reviews/A|B_aa_005245d0_CVOGCharacter_FindActiveObjectiveIdForPick.md` |
| Helper | `FUN_0059da10` @ `0x0059da10` (eval range `+0x158..+0x15c`, slot **+0x44**) |
| Sibling | `aa_00524520` FindActiveObjectiveIdForInteract |
| Callers | `Client_InteractClickPickTarget` `0x009247b0`; `FUN_00925820`; `FUN_00490070` |

## Name evidence (Probable)

1. Structurally identical id-returning walker to sibling (not a bool).
2. Match path is `0059da10` / **+0x44**, not interact **+0x40**.
3. Callers are pick/hover: ClickPickTarget, pick filter, hover select-only (`FUN_0093e120` without IfInteractable when only this matches).

## Open

- Character ECX at each call site.
- `+0x44` implementers per requirement type.
- Runtime first-wins order under multi-active objectives.
