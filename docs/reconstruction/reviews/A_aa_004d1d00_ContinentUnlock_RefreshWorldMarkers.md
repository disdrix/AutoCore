# Review A (reconstruction fidelity): `aa_004d1d00` ContinentUnlock_RefreshWorldMarkers

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d1d00` |
| **VA** | `0x004d1d00` |
| **Canonical name** | `ContinentUnlock_RefreshWorldMarkers` (role-sealed; PDB open) |
| **Ghidra name** | `FUN_004d1d00` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004d1d00_ContinentUnlock_RefreshWorldMarkers.md` |
| **System** | `missions-progression` / exploration (continent unlock visual side-effect) |
| **Parent chain** | Nested residual from GiveMission / CompleteObjective unlock / HasCompleted continent path → `CVOGReaction_UnlockContinentObject` / `RelockContinentObject` |
| **Dual status** | **Written this pass** (no prior `A_aa_*`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Refresh world-map / continent **marker objects** when continent unlock state changes for the **primary local entity**:

```c
void __fastcall ContinentUnlock_RefreshWorldMarkers(ClientWorld* world /* ECX */);
```

### Gate

1. `world+0xe8a0` non-null.
2. Vtbl call `(*world+0xe8a0)+0x1dc` returns non-zero (primary / local entity probe — same pattern as toast primary gate in CompleteObjective).
3. Marker table range `[world+0xe798, world+0xe79c)` non-empty.

### Per-entry loop (stride **0x40**)

For each marker slot `entry`:

1. Resolve related object via `FUN_004bb1f0(entry)`; require live + flag `obj+0xde ≠ 0`.
2. `FUN_0052b2e0(entry+0x1c)` → desired unlocked sense; `needRefresh = (result == 0)`.
3. If `entry+0x38` (cached state bool) already matches desired sense → skip.
4. Else:
   - If TFID at `entry+0x28` ≠ null TFID (`DAT_009cbf68` all-ones / empty):
     - `Object_ResolveFromTFID` → vcall `+0x2a8` with `world+0xe4e8` + `FUN_004d0e90` teardown.
     - Clear TFID to empty constant.
   - Write `entry+0x38 = needRefresh` (desired sense).
5. **Proximity veto:** scan other entries; if another live marker within squared distance **`DAT_00a0f718`** (bytes `0A D7 23 3C` ≈ **0.01f**) and conflicting spawn state → set `entry+0x38 = 0xFF` (skip spawn) and break.
6. If not vetoed (`+0x38 != -1`):
   - **Unlock sense** (`needRefresh`): `CVOGReaction_GiveItemByCbid(DAT_00af1b60)` then vcall create `(cbid, world, 1)`.
   - **Lock sense**: same with `DAT_00af1b64`.
   - On alloc fail log **`"allocatenewobjectfromcbid failed %d Get a programmer"`**.
   - On success: decrement counter pair `world+0xe6e8/+0xe6ec`, `FUN_00512160`, copy position floats from entry `+0x10/+0x14/+0x18` into object slots, `FUN_004bc180`, orientation/vcall chain, store object TFID back into `entry+0x28..+0x34`.

### Callers (live)

| Caller | Role |
|---|---|
| `CVOGReaction_UnlockContinentObject` `0x00531c80` | After insert into char continent hash `+0x534`; only if primary entity match |
| `CVOGReaction_RelockContinentObject` `0x0052a1b0` | After remove path; same primary gate |
| `FUN_004d9f00` | Related world refresh path |

UnlockContinent plate notes GiveMission / CompleteObjective / RecvUnlockRegion as higher callers of UnlockContinent — this unit is the **visual marker side-effect**, not the hash insert itself.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004d1d00_FUN_004d1d00.md` |
| Annotated | `docs/reconstruction/raw/aa_004d1d00_FUN_004d1d00.annotated.md` |
| Clean | `reconstructed-exact/FUN_004d1d00.cpp` / named continent callee scaffold |
| Function record | `docs/reconstruction/functions/aa_004d1d00_FUN_004d1d00.md` |
| Live decompile | `batch_decompile` `0x004d1d00` ≡ raw |
| Live constants | `read_memory` `DAT_00a0f718`, `DAT_00af1b60/64`, `DAT_009cbf68` |
| Callers | `get_function_callers` + decompile Unlock/Relock |
| Parent residual context | GiveMission / CompleteObjective unlock side-effects; SetAreaExploredBit → UnlockContinent |

**Not performed:** CE live CBID fill of `DAT_00af1b60/64` (static image both `0xFFFFFFFF`); Launcher; bit-exact; `disassemble_bytes`.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Role = refresh continent unlock world markers | **High** | Unlock/Relock-only core callers + spawn/despawn |
| `this` = client world / large host with `+0xe8xx` tables | **High** | field cluster matches other world helpers |
| Primary-entity gate `+0xe8a0` / vtbl `+0x1dc` | **High** | matches CompleteObjective toast gate pattern |
| Entry stride `0x40` | **High** | loop add |
| Despawn old TFID then spawn by CBID pair | **High** | body |
| Distance constant ≈ 0.01f squared threshold | **High** (value) / **Probable** (units) | float bytes |
| Static CBIDs `DAT_00af1b60/64` product values | **Open** | image both −1; runtime-filled likely |
| Exact marker schema English | **Probable** | unlock pin / fog marker family |
| Does not itself insert `+0x534` hash | **High** | callers do hash; this is visual only |
| clean ≡ raw CF | **High** | |

---

## 4. Gaps

1. Runtime values of spawn CBIDs.
2. Full English for `FUN_0052b2e0` / `FUN_004bb1f0` / `FUN_004d0e90`.
3. Whether `FUN_004d9f00` adds non-continent callers with different meaning.
4. Server port: client-only presentation.

**Verdict:** **accept-with-gaps** — CF + continent unlock visual role High; CBID globals open.
