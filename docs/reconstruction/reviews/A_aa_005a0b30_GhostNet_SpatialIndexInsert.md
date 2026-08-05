# Review A (reconstruction fidelity): `aa_005a0b30` GhostNet_SpatialIndexInsert

| Field | Value |
|---|---|
| **Stable ID** | `aa_005a0b30` |
| **VA** | `0x005a0b30` |
| **Canonical name** | `GhostNet_SpatialIndexInsert` (inferred; Ghidra `FUN_005a0b30`) |
| **Review date** | `2026-07-29` (OWN-ONLY dual A) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005a0b30_GhostNet_SpatialIndexInsert.md` |
| **System** | input-drive-control / GhostVehicle / ghost spatial index |
| **Evidence pass** | Live `batch_decompile` + `analyze_function_complete`; callees `FUN_005a3b00`; callers GhostObject_OnGhostAdd / VehicleNet_PostCorrectionEvent / VehicleNet_UnpackGhostVehicle |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Thin key packer → ordered map insert/find** for ghost spatial / object index.

1. Copy **4 dwords** from `param_2` into stack key (`local_18..local_c`).
2. Store `param_1` as fifth dword (`local_8`) — typically the ghost/event object pointer.
3. Call `FUN_005a3b00(out8, &key)` — BST/map walk comparing key dwords `[0]/[1]` as ordered pair; insert via `FUN_005a3310` when missing; out is `{node*, inserted_bool}`.

**Callers (live):**

| Caller | Role |
|---|---|
| `GhostObject_OnGhostAdd` `0x005b0d70` | Fallback when `this+0x50` null: `FUN_005a0b30(this, this+0x40)` |
| `VehicleNet_PostCorrectionEvent` `0x005f7360` | After deferred equip blob enqueue |
| `VehicleNet_UnpackGhostVehicle` `0x005f7720` | Ghost unpack spatial register |

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005a0b30_FUN_005a0b30.md` |
| Annotated | `docs/reconstruction/raw/aa_005a0b30_FUN_005a0b30.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_005a0b30.cpp` |
| Function record | `docs/reconstruction/functions/aa_005a0b30_FUN_005a0b30.md` |

**Three-rep:** present (scaffold).

---

## 3. Signature

```c
// free-func; packs key then map insert
void GhostNet_SpatialIndexInsert(void *objectOrGhost, uint32_t *spatialWords4 /* typically +0x40 */);
```

| Formal | Source | Conf |
|---|---|---|
| `param_1` → key slot 4 (object*) | live stack | **High** |
| `param_2` → 4 dwords key head | live copy loop | **High** |
| Map host for `FUN_005a3b00` ECX | residual (global / outer this) | **Tentative** |
| Out `local_20` discarded by callers | no use of return/out | **High** |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match | Conf |
|---|---|---|
| Copy 4 dwords from `param_2` | **Yes** | **High** |
| `local_8 = param_1` | **Yes** | **High** |
| Sole callee `FUN_005a3b00` | **Yes** | **High** |
| No branches / no free | **Yes** | **High** |
| Clean ≡ raw scaffold | **Yes** | **High** |

### Decompiler hazards

- `FUN_005a3b00` is `__thiscall` with 3 formals; call site shows two stack args — **ECX map host** not recovered in this unit (must come from caller context or global).
- `local_20` is 8-byte out pair, not map this.

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Role: pack spatial/object key + map insert | **High** | callers + BST callee |
| 5-dword key layout (4 + object*) | **High** | body |
| Product English “spatial index” | **Probable** | GhostAdd + PostCorrection usage |
| Map container type / global vs member | **Open** | ECX residual |
| Runtime / bit-for-bit | **Open** | deferred |

---

## 6. Gaps

1. Seal `FUN_005a3b00` map host (global DAT vs ghost manager).
2. Whether key `[0..1]` is TFID pair vs position hash — comparison is signed/unsigned dual on those two dwords only for order; remaining key payload stored on insert.

**Verdict:** **accept-with-gaps**
