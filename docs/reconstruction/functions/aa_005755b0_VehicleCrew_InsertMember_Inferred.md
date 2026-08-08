# Function record: VehicleCrew_InsertMember_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005755b0` |
| **Canonical name** | `VehicleCrew_InsertMember_Inferred` |
| **Ghidra name** | `FUN_005755b0` |
| **Address** | `0x005755b0` |
| **Body** | `0x005755b0`–`0x00575694` exclusive (228 B) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `skills-abilities` |
| **Completion status** | **Dual sealed** (WQ9D-D 2026-08-04) — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (Terminal false) |

## Purpose

Crew-roster **insert** writer. Complements dualed Contains (`0x005749d0`) for skill gather mode **0xb** (“same vehicle / plant crew”) infrastructure:

1. Reject if `(u8)count@+0x1D8 + (i32)@+0x1E4 > 3`.
2. Reject if already a member (`Contains`).
3. Find free slot: `(coidLo & coidHi) == 0xFFFFFFFF`.
4. Write COID lo/hi + object*; set **member+0xCB0 = host**; push COID to vector **host+0x1F4**; **count++**.
5. If no free slot: `"VOG_DEBUG_STOP"` then false.

## Signature

```c
// __thiscall  RET 4
bool VehicleCrew_InsertMember_Inferred(CrewHost* this, void* member);
```

## Layout

| Offset | Role |
|---|---|
| `this+0x198` | slot[0].coidLo (stride `0x10` × 4) |
| `this+0x19C` | slot[0].coidHi |
| `this+0x1A0` | slot[0].object* |
| `this+0x1D8` | u8 live count |
| `this+0x1E4` | i32 capacity bias |
| `this+0x1F4` | COID vector |
| `member+0xCB0` | crew-host back-pointer after insert |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005755b0_FUN_005755b0.md`
- Annotated: `docs/reconstruction/raw/aa_005755b0_FUN_005755b0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/VehicleCrew_InsertMember_Inferred.cpp`
- Twin scaffold: `docs/reconstruction/reconstructed-exact/FUN_005755b0.cpp`
- Dual A/B: `reviews/A|B_aa_005755b0_VehicleCrew_InsertMember_Inferred.md`

## Related

| VA | Name | Relation |
|---|---|---|
| `0x005749d0` | `VehicleCrew_ContainsMember_Inferred` | uniqueness guard / twin reader |
| `0x00574a90` | crew clear | twin clear (WQ9D-G) |
| `0x00520330` | `*(this+0xCB0)=arg` | back-link leaf |
| `0x00418d70` | vector push 8 B | COID list |
| `0x0058a810` | gather pair filter mode 0xb | Contains consumer |

## Confidence

| Claim | Level |
|---|---|
| Insert CF / 4-slot table / AL bool | **Confirmed** |
| member+0xCB0 / host+0x1F4 call setups | **Confirmed** |
| Mode 0xb crew role | **High** (via Contains dual + layout) |
| Live callers | **Open** (0 xrefs) |
| Product C++ name | **Inferred** |
