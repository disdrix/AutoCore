# Function record: Character_ClearEquippedRaceItemTfId_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005210b0` |
| **Canonical name** | `Character_ClearEquippedRaceItemTfId_Inferred` |
| **Ghidra name** | `FUN_005210b0` |
| **Address** | `0x005210b0` |
| **Body range** | `0x005210b0`–`0x0052112b` (124 bytes) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | character race-item equip / inventory / ghost |
| **Completion status** | **partial** — dual A/B **accept**; CF + bytes + null template sealed; product English **INFERRED**; runtime/diff open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_005210b0_Character_ClearEquippedRaceItemTfId_Inferred.md`, `reviews/B_aa_005210b0_Character_ClearEquippedRaceItemTfId_Inferred.md` (2026-07-29 W21-E) |
| **Last reviewed** | `2026-07-29` |

## Alias

- `FUN_005210b0`
- Teardown helper referenced by `Character_SyncEquippedRaceItemFromCbid_Inferred` (`aa_00522f70`)

## Purpose

Clear the character’s equipped **race-item TFID cache** at `this+0x518`:

1. Gate on TFID present (`(lo & hi) != -1` or byte `+0x520 != 0`) **and** host component non-null.
2. Resolve world object for that TFID (via `*(host+0xe4e8)` context + `Object_ResolveFromTFID`).
3. If resolved: `Object_EnqueueDeferredOnce(host, obj)` (sealed `aa_004d0e90`) — deferred teardown, not free-now.
4. Write null TFID template `DAT_009cee98` = `{0xffffffff,0xffffffff,0,0}` into `this+0x518`..`+0x524`.

Does **not** modify CBID at `this+0x514` (parent sync/setter owns CBID).

## Signature

```c
// __thiscall  ECX = character*  (decomp surface: __fastcall int param_1)
void Character_ClearEquippedRaceItemTfId_Inferred(void *self);
```

## Algorithm

1. If TFID looks null/sentinel and `+0x520` is zero → return.
2. Host = `*(*(self+4)+4 + self + 0xa8)`; if null → return.
3. `obj = Object_ResolveFromTFID(self+0x518)` (bytes: thiscall on `*(host+0xe4e8)`).
4. If `obj`: `Object_EnqueueDeferredOnce(host, obj)`.
5. Copy 16-byte null template into TFID cache.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005210b0_FUN_005210b0.md`
- Annotated: `docs/reconstruction/raw/aa_005210b0_FUN_005210b0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Character_ClearEquippedRaceItemTfId_Inferred.cpp`
- Alias clean: `docs/reconstruction/reconstructed-exact/FUN_005210b0.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_005210b0_FUN_005210b0.md`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-0051b5f0-005210b0-w21e-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | `Object_ResolveFromTFID` @ `0x004bb950`, `Object_EnqueueDeferredOnce` (`FUN_004d0e90`) @ `0x004d0e90` |
| **Callers** | `FUN_00522f70` / `Character_SyncEquippedRaceItemFromCbid_Inferred`, `FUN_0052f260` |

## Confidence

| Claim | Level |
|---|---|
| Control flow + bytes | **High** |
| ECX = this; no stack formals | **High** |
| TFID at `+0x518`; null template | **High** (`read_memory` @ `0x009cee98`) |
| Enqueue = sealed deferred once | **High** (callee dual + call-site ECX/stack) |
| Role = race-item binding teardown | **High** (parent sync dual + fields) |
| Product English “race item” | **Inferred** (parallel vehicle race-item path) |
| Runtime / differential | Open |

## Related

- Parent: `Character_SyncEquippedRaceItemFromCbid_Inferred` @ `0x00522f70`
- Vehicle twin equip: `Vehicle_SetEquippedRaceItem` @ `0x00502460` (hardpoint `+0x270`)
- Deferred queue: `Object_EnqueueDeferredOnce` @ `0x004d0e90`
