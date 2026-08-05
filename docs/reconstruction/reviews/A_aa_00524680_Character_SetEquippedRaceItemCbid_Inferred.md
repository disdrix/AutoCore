# Review A (reconstruction fidelity): `aa_00524680` Character_SetEquippedRaceItemCbid_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00524680` |
| **VA** | `0x00524680` |
| **Canonical name** | `Character_SetEquippedRaceItemCbid_Inferred` (Ghidra `FUN_00524680`) |
| **Review date** | `2026-07-29` (OWN-ONLY dual A) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00524680_Character_SetEquippedRaceItemCbid_Inferred.md` |
| **System** | character race-item equip / ghost net |
| **Evidence pass** | Live `batch_decompile` + `read_memory`; calls `FUN_00522f70`; masks `0x40000000` / `0x1000000` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Set character equipped race-item CBID** at **`this+0x514`**, with optional net dirty + materialize via `Character_SyncEquippedRaceItemFromCbid` (`0x00522f70`).

CF (sealed High from decomp + bytes):

```
if (*(this+0x514) == newCbid) return;

base = *( *(this+4)+4 ) + this
map  = *(base + 0xa8)

if (*(map+0x7e) == 0):
  *(this+0x514) = newCbid
  return                    // store only; no dirty / no sync

// map+0x7e non-zero:
if (*(map+0xf5) == 0) OR (charNet = *(base+0x18)) is null:
  vehicle = *(this+0x250)
  if vehicle && vehicleNet:
    NetObject_SetMaskBits(vehicleNet, 0x1000000, 0)
  // if no vehicle net: no dirty, still fall through to store+sync
else:
  NetObject_SetMaskBits(charNet, 0x40000000, 0)

*(this+0x514) = newCbid
Character_SyncEquippedRaceItemFromCbid(this)   // FUN_00522f70
*(this+0x514) = newCbid   // redundant second store (fallthrough LAB)
```

**Callers:** `VehicleNet_UnpackGhostVehicle`, `VehicleNet_ReconcilePrediction`, `FUN_0060a030`, `FUN_0060a820`, plus two sites in `0x00625d*`.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00524680_FUN_00524680.md` |
| Annotated | `docs/reconstruction/raw/aa_00524680_FUN_00524680.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00524680.cpp` |
| Function record | `docs/reconstruction/functions/aa_00524680_FUN_00524680.md` |
| Live | cmp `[esi+0x514]`; map flags `+0x7e`/`+0xf5`; masks `0x40000000` / `0x1000000`; call `0x00522f70` |

**Three-rep:** present.

---

## 3. Signature

```c
// __thiscall  ECX = character*
// stack: int cbid  (ret 4; -1 clears via sync)
void Character_SetEquippedRaceItemCbid(void *self, int cbid);
```

| Formal | Source | Conf |
|---|---|---|
| this | ECX | **High** |
| cbid | stack dword → `+0x514` | **High** |
| early equal-out | **High** | |
| map gate `+0x7e` | **High** | skip dirty+sync |
| local-player net mask | `0x40000000` | **High** |
| vehicle net mask | `0x1000000` | **High** |
| sync callee | `0x00522f70` | **High** |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match | Conf |
|---|---|---|
| Equal early return | **Yes** | **High** |
| `map+0x7e==0` store-only | **Yes** | **High** |
| `map+0xf5` chooses char vs vehicle dirty | **Yes** | **High** |
| Store + sync + fallthrough store | **Yes** | **High** |
| Clean invents masks | **No** | **High** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Field `+0x514` is equipped CBID | **High** | paired with sync `+0x518` TFID |
| Calls sync on active map | **High** | |
| Dual mask selection by map/net availability | **High** | |
| Product “race item” name | **Probable** | parallel vehicle equip; not string-proven |
| Meaning of `map+0x7e` / `map+0xf5` | **Tentative** | client/server or local-player flags residual |
| Runtime | **Open** | deferred |

---

## 6. Gaps

1. Name map flags `+0x7e` / `+0xf5` (local authority / client presentation).
2. Confirm pack bit for `0x40000000` vs vehicle `0x1000000`.
3. Cross-link dual for teardown `FUN_005210b0` and vehicle `Vehicle_SetEquippedRaceItem`.

**Verdict:** **accept-with-gaps**
