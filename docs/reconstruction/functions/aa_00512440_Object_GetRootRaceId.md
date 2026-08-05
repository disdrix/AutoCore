# Function record: Object_GetRootRaceId

| Field | Value |
|---|---|
| **Stable ID** | `aa_00512440` |
| **Canonical name** | `Object_GetRootRaceId` |
| **Address** | `0x00512440` |
| **Body** | `0x00512440` â€“ `0x0051245f` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | object / faction |
| **Classification** | leaf |
| **Completion status** | **accept-with-gaps** â€” Dual A/B 2026-07-29; algorithm sealed High |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Walk the cloned-object **owner chain** at offset **`+0xAC`** to the root (null owner), then return the **DWORD race/faction id** at root **`+0x10`**.

## Signature (decompiler + byte sealed)

```c
/* ClonedObject_GetRootRaceId â€” walk owner chain (+0xAC) to the root object,
   return race id at root+0x10.

   Used by VehicleCombatPoolAction_ctor to pick 3000 vs 5000 ms period
   (race ids 0/1/2 â†’ 3000 ms). */

RACE_ID_INFERRED __fastcall Object_GetRootRaceId(void *pObject);
```

| Item | Value |
|---|---|
| Convention | `__fastcall` (object in **ECX**) |
| Return | **EAX** â€” `RACE_ID_INFERRED` (4-byte s32) |
| Callees | none |
| Null-safe | **no** (null `pObject` crashes) |

## Algorithm

```
while (*(p + 0xAC) != NULL) p = *(p + 0xAC);
return *(RACE_ID_INFERRED *)(p + 0x10);
```

## Related (not owned)

| VA | Name | Role |
|---|---|---|
| `0x00512460` | `FUN_00512460` | Write `+0x10` on self + owner chain |

## Domain constants (caller use of return)

| Value | Ghidra / docs |
|---|---|
| `0` | `RACE_HUMAN_INFERRED` |
| `1` | `RACE_BIOMEK_INFERRED` |
| `2` | `RACE_TRIBE_INFERRED` |
| `-100` (`0xFFFFFF9C`) | Neutral (AI no proactive target) |
| `-1` (`~0`) | Special NPC faction path in hostility |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00512440_Object_GetRootRaceId.md`
- Annotated: `docs/reconstruction/raw/aa_00512440_Object_GetRootRaceId.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Object_GetRootRaceId.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_00512440_Object_GetRootRaceId.md`
- Dual B: `docs/reconstruction/reviews/B_aa_00512440_Object_GetRootRaceId.md`
- Report: `docs/agents/task-dual-ab-00512440-object-getrootraceid-report.md`

## Callers / callees

**Callees:** none (leaf).

**Callers (Ghidra, non-exhaustive; 27 named / 38 xrefs):**  
`CVOGHBAIBase_FindTargetToAttack`, `CVOGHBRegeneration_ctor`, `CVOGSpawnPoint_CreateCreature`, `CVOGSpawnPoint_CreateTemplateVehicle`, `CVOGVariable_EvaluateComputed`, `FUN_004ca910`, `FUN_004d5110`, `FUN_00509010`, `FUN_0050aa80`, `FUN_005131b0`, `FUN_00562c70`, `FUN_00564b10`, `FUN_00565950`, `FUN_005b1290`, `FUN_005c81d0`, `FUN_005c84e0`, `FUN_005c8e00`, `FUN_005c9450`, `FUN_00605bc0`, `FUN_006082e0`, `FUN_00618270`, `FUN_0061e410`, `FUN_0090f250`, `FUN_0092b2a0`, `FUN_0092c080`, `FUN_00930fc0`, `FUN_00955eb0`.

## Confidence

| Claim | Level |
|---|---|
| Control flow / offsets `+0xAC` walk, return `+0x10` | **High** |
| `__fastcall` ECX / EAX, leaf | **High** |
| Parameter semantic (`pObject` cloned base) | **High** (callers) |
| Product names of fields | **Tentative** |
| Full race/faction enum table | **Partial** (0/1/2 + known sentinels) |
