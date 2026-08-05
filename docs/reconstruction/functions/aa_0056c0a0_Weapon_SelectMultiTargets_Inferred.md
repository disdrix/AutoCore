# Function record: Weapon_SelectMultiTargets_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0056c0a0` |
| **Canonical name** | `Weapon_SelectMultiTargets_Inferred` |
| **Ghidra name** | `FUN_0056c0a0` |
| **Address** | `0x0056c0a0` |
| **Body range** | `0x0056c0a0`–`0x0056c856` (exclusive end; **1974** B / `0x7B6`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | combat / vehicle weapon targeting |
| **Completion status** | **partial** — dual A/B **accept**; CF + ABI + string + vtable sealed; product class / runtime open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_0056c0a0_Weapon_SelectMultiTargets_Inferred.md`, `reviews/B_aa_0056c0a0_Weapon_SelectMultiTargets_Inferred.md` |
| **Last reviewed** | `2026-07-29` (W20-H) |

## Alias

- `FUN_0056c0a0` (Ghidra)
- Residual product English: SelectTargets / GatherTargets / BuildTargetList — **unsealed**

## Purpose

**Virtual weapon multi-target select:** fill the weapon's locked result list (`this+0x13c`) with up to `maxTargets` combat targets, ordered by `CVOGPhysicsUtils_FindDistanceToTarget`, optionally seeding from a preferred primary target. Failures return **−1**; success returns **count**.

Product typo string seals weapon domain:

`"WARNING Weaopn <%s> has invalid # of maxtargets(%d) set!"` @ `0x009d2fcc`

## Signature

```c
// __thiscall; ret 8
// ECX = weapon*; arg0 = locked object list*; arg1 = preferred target*
uint32_t Weapon_SelectMultiTargets_Inferred(void *thisWeapon, void *lockedList, void *preferredTarget);
```

## Algorithm

See annotated + raw. Spine:

1. Owner / list / physics gates → −1 (+ optional `FUN_0056bf70`).
2. `maxTargets = FUN_0056ac50`; clamp ≤100 with Weaopn log.
3. Aim basis (type 0xE hardpoint vs default).
4. Preferred target range-check → slot0.
5. Locked-list walk + filters + distance insert/append.
6. Merge secondary list; commit via `FUN_0056eca0`; return count.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0056c0a0_FUN_0056c0a0.md`
- Annotated: `docs/reconstruction/raw/aa_0056c0a0_FUN_0056c0a0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Weapon_SelectMultiTargets_Inferred.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_0056c0a0.cpp` (line-faithful CF)
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-004e24d0-0056c0a0-w20h-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | `FUN_0056bf70`, `FUN_0056ac50`, `FUN_007a4480`, orient/`FindDistanceToTarget` family, `FUN_005770d0`, list walk `004294f0`/`004022a0`, filters `005134e0`/`0040b1b0`, commit `0056eca0`/`0056f0b0`, `operator_new`, `LeaveCriticalSection` |
| **Callers** | **none direct** — DATA vtable `@ 0x009d3330` and `@ 0x009ddad8` |

## Confidence

| Claim | Level |
|---|---|
| thiscall + ret 8 | **High** |
| Return −1 fail / count success | **High** |
| Weaopn maxtargets string + clamp 100 | **High** |
| FindDistanceToTarget for range | **High** |
| Vtable-only entry (weapon class) | **High** |
| Product class / slot English name | Open / `_Inferred` |
| Full filter-bit dictionary | Partial |
| Runtime / bit-exact | Open |

## Related

- `aa_0056c860` `Weapon_TryFireResolveHits_Inferred` — same vtable base `0x009d3320` slot 0
- `aa_004e9aa0` `CVOGPhysicsUtils_FindDistanceToTarget`
- Area-style siblings `FUN_0056d600` / `FUN_0056db30` (different ABI; GetObjectsInArea)
