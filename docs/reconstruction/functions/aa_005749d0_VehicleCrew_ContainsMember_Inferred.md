# Function record: VehicleCrew_ContainsMember_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005749d0` |
| **Canonical name** | `VehicleCrew_ContainsMember_Inferred` |
| **Ghidra name** | `FUN_005749d0` |
| **Address** | `0x005749d0` |
| **Body** | `0x005749d0`–`0x00574a2e` exclusive (94 B) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `skills-abilities` |
| **Completion status** | **Dual sealed** (WQ9R-A 2026-08-04) — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (Terminal false) |

## Purpose

Crew-roster membership predicate. Scans `this+0x198` (4 slots, stride `0x10`) for a COID lo/hi match against the candidate object. Used by:

- Skill gather/filter **mode 0xb** ("same vehicle / plant crew") when `vehicle+0xCB0` points at the crew host (`FUN_0058a810`).
- `Skill_FilterTargetForResolveList_Inferred` crew accept arm (`skill+0x615 & 0x20`).
- `Client_RecvDestroyObject` and other client residual gates.
- Guard inside crew insert `FUN_005755b0`.

**Not** a standalone faction/friendly-fire formula — callers combine it with `vtbl+0x210` same-vehicle checks.

## Signature

```c
// __thiscall  RET 4
bool VehicleCrew_ContainsMember_Inferred(CrewHost* this, void* candidate);
```

## Layout

| Offset | Role |
|---|---|
| `this+0x198` | slot[0].coidLo |
| `this+0x19C` | slot[0].coidHi |
| +`0x10` per slot | slots 1..3 |
| `candidate` via `*(+4)→*(+4)` offBase | COID at `offBase+obj+0x164/0x168` |
| `vehicle+0xCB0` | crew-host pointer (caller-side) |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005749d0_FUN_005749d0.md`
- Annotated: `docs/reconstruction/raw/aa_005749d0_FUN_005749d0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/VehicleCrew_ContainsMember_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_005749d0.cpp`
- Dual A/B: `reviews/A|B_aa_005749d0_VehicleCrew_ContainsMember_Inferred.md`

## Related

| VA | Name | Relation |
|---|---|---|
| `0x005755b0` | crew insert twin | writes free `+0x198` slot |
| `0x00574a90` | crew clear twin | zeros matching slot |
| `0x0058a810` | gather pair filter | mode `0xb` consumer |
| `0x0054ff00` | `Skill_FilterTargetForResolveList_Inferred` | filter consumer |

## Confidence

| Claim | Level |
|---|---|
| Membership CF / 4-slot table | **Confirmed** |
| AL bool return | **Confirmed** |
| Mode 0xb crew role | **High** (caller + prior gather dual) |
| Product C++ name | **Inferred** |
