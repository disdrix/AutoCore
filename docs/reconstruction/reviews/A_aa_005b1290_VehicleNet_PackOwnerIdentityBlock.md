# Review A (reconstruction fidelity): `aa_005b1290` VehicleNet_PackOwnerIdentityBlock

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b1290` |
| **VA** | `0x005b1290` |
| **Canonical name** | `VehicleNet_PackOwnerIdentityBlock` (inferred; Ghidra `FUN_005b1290`) |
| **Plate alias** | `Named_CalleeOf_Drive_Packing_initial_update_for_vehicle_I64_005b1290` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005b1290_VehicleNet_PackOwnerIdentityBlock.md` |
| **System** | input-drive-control / GhostVehicle pack |
| **Evidence pass** | Live `batch_decompile` + `read_memory` full body (~160 B) + callees/callers; parent dual `aa_005f5de0` VehicleNet_PackUpdate |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Initial-update** owner / identity seed block written into the GhostVehicle pack BitStream from parent entity at `ghost+0x50`:

| Order | Wire | Source |
|---|---|---|
| 1 | **64 bits** | TFID halves `entity+0x160`, `entity+0x164` |
| 2 | **1 flag** | `entity+0x168` (global/TFID domain byte) |
| 3 | **20-bit int** | `*(entity+0xa8)+0x34` (CBID / template id) |
| 4 | **18-bit int** | vfunc `entity.vtbl+0x244()` clamped: if &lt; 0 → **0**, else re-call and write |
| 5 | **16 bits** | `Object_GetRootRaceId(entity)` |
| 6 | **16 bits** | vfunc `entity.vtbl+0x290()`; if **equals** root race → write **0** (delta-zero convention) |

Used from `VehicleNet_PackUpdate` **initial** path (and sibling pack helpers `FUN_005d2800`, `FUN_0060a230`). **Not** the HB skill list packer (`0x005b2830`).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005b1290_FUN_005b1290.md` |
| Annotated | `docs/reconstruction/raw/aa_005b1290_FUN_005b1290.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_005b1290.cpp` (+ Named_* alias) |
| Function record | `docs/reconstruction/functions/aa_005b1290_FUN_005b1290.md` |
| Parent dual | `reviews/A_aa_005f5de0_VehicleNet_PackUpdate.md` |
| Live | decompile ≡ raw; body ends `ret 4` |

**Three-rep:** present.

---

## 3. Signature

```c
// __thiscall  ECX = GhostVehicle* (or pack context with +0x50 → parent entity)
// stack: BitStream* stream  (ret 4)
void VehicleNet_PackOwnerIdentityBlock(void *ghost, BitStream *stream);
```

| Formal | Source | Conf |
|---|---|---|
| `this` ghost | ECX → ESI; `*(this+0x50)` entity | **High** |
| stream | stack; loaded to EDI; BitStream_* thiscall targets | **High** |
| Epilogue | `ret 4` | **High** (bytes) |

Decompiler second formal `RACE_ID_INFERRED` is **stack-slot reuse** for race writes — not a true second input.

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match | Conf |
|---|---|---|
| 64b TFID write from `+0x160/+0x164` | **Yes** | **High** |
| Flag from `+0x168` | **Yes** | **High** |
| 20b int from `*(+0xa8)+0x34` | **Yes** | **High** |
| 18b from vtbl `+0x244`, neg → 0 | **Yes** | **High** |
| Root race 16b via `Object_GetRootRaceId` | **Yes** | **High** |
| Second 16b via vtbl `+0x290`; equal root → 0 | **Yes** | **High** |
| No loops / no HB walk | **Yes** | **High** |
| Callees only BitStream write* + GetRootRaceId + 2 vfuncs | **Yes** | **High** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Initial identity seed (not skill HB list) | **High** | CF; parent dual split vs `0x005b2830` |
| Field offsets on parent entity | **High CF** | live loads |
| 20b / 18b / 16b / 16b widths | **High** | immediates 0x14, 0x12, 0x10, 0x10 |
| Race equal-collapse to 0 | **High** | short cmp |
| English names of `+0xa8` blob / vfuncs | **Tentative** | CBID-ish; residual |
| Product name | **Tentative** | inferred |
| Bit-exact / runtime | **Open** | deferred |

---

## 6. Gaps

1. Product names for vtbl `+0x244` / `+0x290` and `entity+0xa8` object.
2. Whether 18b is HP, level, or other clamp-to-zero metric (parent combat uses 18b health elsewhere — **not** sealed as same field here).
3. Full GhostVehicle layout beyond `+0x50`.
4. Server AutoCore pack order cross-check for this sub-block only.

**Verdict:** **accept-with-gaps**
