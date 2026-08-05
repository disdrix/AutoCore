# Function record: Object_RegisterListed

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bc180` |
| **Canonical name** | `Object_RegisterListed` |
| **Ghidra name** | `FUN_004bc180` |
| **Address** | `0x004bc180` |
| **Body range** | `0x004bc180`–`0x004bc41c` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | world object listing / mission notify hooks |
| **Completion status** | **partial** — dual A/B **accept-with-gaps**; CF + ABI + offsets sealed; product English / type names open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_004bc180_Object_RegisterListed.md`, `reviews/B_aa_004bc180_Object_RegisterListed.md` |
| **Last reviewed** | `2026-07-29` (W19-E) |

## Alias

- `FUN_004bc180` (Ghidra)
- `Mission_VOG_DEBUG_STOP` / `Named_VOG_DEBUG_STOP_004bc180` — **string-seed incomplete** (`"VOG_DEBUG_STOP"` is invalid-COID log only)
- Scaffold system was `unknown`

## Purpose

Register an object into a listing manager: validate COID, enforce manager mode flags, soft-reject duplicates, ensure type-keyed `CNDHash` bucket, allocate one or more listing handles (`FUN_004bc680` → `+0xdc/+0xd0/+0xd4/+0xd8`), and optionally notify mission fail reactions for special types / flag bit5.

## Signature

```c
// Machine: __thiscall, one stack arg, ret 4
// Returns 0 on success or already-listed; throws HRESULT on hard errors
int32_t __thiscall Object_RegisterListed(ListingContext* this, Object* obj);
```

## Layout (this unit)

### Object

| Offset | Field | Role |
|---:|---|---|
| `+0xa8` | meta* | `+0x34` log id; `+0x38` type key |
| `+0xd0` | handle | secondary (type 0x12 / special 0xe) |
| `+0xd4` | handle | tertiary (`FUN_005130e0`) |
| `+0xd8` | handle | quaternary (flag bit5) |
| `+0xdc` | handle | primary listing |
| `+0x160` / `+0x164` | COID lo/hi | `%I64d` |
| `+0x168` | mode char | selects manager `+0xc` vs `+0xd` |
| `+0x17c` bit5 | flag | extra handle + notify |
| vtbl `+0x208` | predicate | force key `0x30` if nonzero |
| vtbl `+0x1d4` | related | type `0xe` linked check (`+0x2ac`) |

### ListingContext

| Offset | Field | Role |
|---:|---|---|
| `+0x0c` / `+0x0d` | mode flags | required by object mode |
| `+0x18` | `CNDHash*` | bucket table |

## Algorithm

1. Invalid COID → log `"VOG_DEBUG_STOP"`; throw `0x80070057`.
2. Mode gate on manager `+0xc`/`+0xd`.
3. `FUN_004e77d0` already-listed → log; return `0`.
4. Key = `0x30` if `vtbl+0x208`, else type `@meta+0x38`.
5. Ensure hash bucket (`new 0x2c` / insert) or throw `0x8007000E`.
6. Primary `FUN_004bc680` → `+0xdc`.
7. Type 0x12 / special 0xe / 0x14 notify arms with optional secondary handle.
8. Optional `+0xd4` / `+0xd8` handles; return `0`.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004bc180_FUN_004bc180.md` (+ live 2026-07-29)
- Annotated: `docs/reconstruction/raw/aa_004bc180_FUN_004bc180.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Object_RegisterListed.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_004bc180.cpp`
- Legacy alias clean: `docs/reconstruction/reconstructed-exact/Mission_VOG_DEBUG_STOP.cpp` (string-seed; prefer Object_RegisterListed)
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-004bc180-00620480-w19e-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | `FUN_007a4480`, `_CxxThrowException`, `FUN_004e77d0`, `CNDHash_LookupByKey`, `operator_new`, `FUN_004bcb40`, `FUN_004bd1d0`, `FUN_004bc680`, `CVOGReaction_FailMissionNotify`, `FUN_005130e0` |
| **Callers (sample)** | spawn create vehicle/creature, inventory grab response, teleport special events, continent marker refresh, equip/sync, many `FUN_004d*` / `FUN_0056*` sites — **shared multi-domain** |

## Confidence

| Claim | Level |
|---|---|
| Control flow + throw/return surface | **High** |
| `__thiscall` + `ret 4` | **High** |
| COID / handle / type offsets | **High** |
| `"VOG_DEBUG_STOP"` ≠ primary purpose | **High** |
| Product/PDB symbol; type 0x12/0xe/0x14 English | Open |
| Runtime / bit-exact | Open |

## Related

- `FUN_004bc680` handle allocator
- `FUN_004e77d0` already-listed test
- `CVOGReaction_FailMissionNotify` (`0x004149d0`)
- Peer string-seed units at `0x004c82b0` / `0x004d2e50` (other `"VOG_DEBUG_STOP"` sites — not this VA)
