# Function record: Vehicle_ResolveFirstHardpointOccupantTfid_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f8b80` |
| **Canonical name** | `Vehicle_ResolveFirstHardpointOccupantTfid_Inferred` |
| **Prior** | `FUN_004f8b80` |
| **Address** | `0x004f8b80` |
| **System** | skills-abilities |
| **Name confidence** | **Probable / Inferred** — method English open; **table walk Confirmed** as weapon hardpoints |
| **Status** | Human-refined + dual A/B strengthen (2026-07-29 vehicle+0x260 walk) |

## Purpose

Walk `*(vehicle+0x260)` **3-slot weapon hardpoint** pointer table. For each active slot with non-empty list at `slot+0x13c`, return pointer to first occupant’s TFID: `*(listValue+4)+0x160`. Else return sentinel `&DAT_009cd0f8` (all-ones coid).

**ResolveCastTarget role:** alt TFID when `outFlags&4` and skill flag `+0x614&8`; invalid result → UX `"No enemies found."`.

## Sealed walk facts

| Fact | Confidence | Evidence |
|---|---|---|
| `table = *(vehicle+0x260)`; index byte offs 0/4/8 | **Confirmed** | body asm |
| 3 weapon hardpoint slots | **Confirmed** | bound + equip `"Tried to equip same weapon"` |
| Occupant `*(listValue+4)+0x160` | **Confirmed** | body asm |
| Sole caller ResolveCastTarget | **Confirmed** | callers |
| Sentinel all-ones coid @ `DAT_009cd0f8` | **Confirmed** | read_memory |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004f8b80_FUN_004f8b80.md` (+ rename append)
- Annotated: `docs/reconstruction/raw/aa_004f8b80_Vehicle_ResolveFirstHardpointOccupantTfid_Inferred.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Vehicle_ResolveFirstHardpointOccupantTfid_Inferred.cpp`
- Dual: `reviews/A|B_aa_004f8b80_Vehicle_ResolveFirstHardpointOccupantTfid_Inferred.md`
