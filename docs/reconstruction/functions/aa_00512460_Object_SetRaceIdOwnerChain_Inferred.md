# Function record: Object_SetRaceIdOwnerChain_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00512460` |
| **Canonical name** | `Object_SetRaceIdOwnerChain_Inferred` |
| **Ghidra name** | `FUN_00512460` |
| **Address** | `0x00512460` |
| **Body** | `0x00512460` – `0x00512487` (39 B) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | object / faction |
| **Classification** | leaf |
| **Completion status** | **accept-with-gaps** — Dual A/B W24-G 2026-07-29; algorithm sealed High |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Write race/faction id at **`+0x10`** on the target cloned object, then walk the **owner chain** at **`+0xAC`** and write the **same id** on every owner including the root. Companion **writer** to `Object_GetRootRaceId` (`0x00512440`).

## Signature (decompiler + byte sealed)

```c
void __thiscall Object_SetRaceIdOwnerChain_Inferred(void *pObject, RACE_ID_INFERRED raceId);
// ECX = pObject; stack arg = raceId; epilogue ret 4; void
```

| Item | Value |
|---|---|
| Convention | `__thiscall` (object in **ECX**, one stack DWORD) |
| Return | void |
| Callees | none |
| Null-safe | **no** (null `pObject` crashes) |

## Algorithm

```
*(p + 0x10) = raceId;
slot = p + 0xAC;
if (*slot == NULL) return;
while (true) {
  cur = *slot;
  *(cur + 0x10) = raceId;
  slot = cur + 0xAC;
  if (*slot == NULL) break;
}
```

## Related

| VA | Name | Role |
|---|---|---|
| `0x00512440` | `Object_GetRootRaceId` | Walk `+0xAC` to root; **return** root `+0x10` |
| — | Spawn `FactionDirty` | Caller applies map faction via this writer |

## Domain constants (id values, not body immediates)

| Value | Ghidra / docs |
|---|---|
| `0` | `RACE_HUMAN_INFERRED` |
| `1` | `RACE_BIOMEK_INFERRED` |
| `2` | `RACE_TRIBE_INFERRED` |
| `-100` (`0xFFFFFF9C`) | Neutral |
| `-1` (`~0`) | Special NPC faction path in hostility |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00512460_FUN_00512460.md`
- Annotated: `docs/reconstruction/raw/aa_00512460_FUN_00512460.annotated.md`
- Clean scaffold: `docs/reconstruction/reconstructed-exact/FUN_00512460.cpp`
- Clean named: `docs/reconstruction/reconstructed-exact/Object_SetRaceIdOwnerChain_Inferred.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_00512460_Object_SetRaceIdOwnerChain_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_00512460_Object_SetRaceIdOwnerChain_Inferred.md`
- Report: `docs/agents/task-dual-ab-w24g-00512460-00516be0-report.md`

## Callers / callees

**Callees:** none (leaf).

**Callers (Ghidra named + sample sites):**  
`CVOGSpawnPoint_CreateCreature`, `CVOGSpawnPoint_CreateTemplateVehicle`, `VehicleNet_ReconcilePrediction`, `FUN_004ca910`, `FUN_005131b0`, `FUN_00565950`, `FUN_005d2600`, `FUN_0060a030`, `FUN_00615020`, `FUN_0061e410`; plus reaction/dispatch call sites around `0057d0xx` / `00562c52`.

## Confidence

| Claim | Level |
|---|---|
| Control flow / offsets write `+0x10`, walk `+0xAC` | **High** |
| `__thiscall` ECX + stack id, `ret 4`, leaf | **High** |
| Root-inclusive chain write | **High** (byte loop) |
| Parameter semantic (`race/faction id`) | **High** (sibling + spawn docs) |
| Product field names | **Tentative** |
