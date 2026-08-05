# Review A (reconstruction fidelity): `aa_00539e30` CNDHash_Recreate_009cfa88

| Field | Value |
|---|---|
| **Stable ID** | `aa_00539e30` |
| **VA** | `0x00539e30` |
| **Canonical name** | `CNDHash_Recreate` (object family vtbl `PTR_FUN_009cfa88` / AllocBuckets `009cf01c`) |
| **Inferred role** | Tear down + re-allocate pending-objective CNDHash at **char+0x55c** |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw + bytes) |
| **Counterpart** | `reviews/B_aa_00539e30_CNDHash_Recreate_009cfa88.md` |
| **System** | container / CNDHash / missions-progression |
| **Dual status** | **Present — sealed 2026-07-29** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Third Recreate twin:

1. Lock `+0x1d` → log Recreate-locked + `VOG_DEBUG_STOP`; continue.
2. `FUN_00539110` teardown → owning clear `FUN_00538200` (freelist stamp `009cefec`); free table/slab.
3. Store bits `+0x1c`; zero tail/head; size `1<<bits` @ `+0x08`.
4. `FUN_00537bf0` AllocBuckets (sentinel `PTR_LAB_009cf01c`) → mask.

**ABI:** `__thiscall` + stack byte + **`RET 4`**.

Caller: `FUN_0052b4e0` end:

```
FUN_00539e30( *(char+0x55c)->log2Bits );
```

System map + ctor: **pending objectives** hash lives at **char+0x55c** (`param_1[0x157]` in `FUN_00536920`, object vtbl `009cfa88`, bits=`2`, size=`4` → mask `3` after alloc).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / clean | `raw/aa_00539e30_*`, `reconstructed-exact/FUN_00539e30.cpp` |
| Fresh decompile | `batch_decompile` @ `0x00539e30` ≡ raw |
| Body image | `read_memory` — same skeleton; `5E C2 04 00` |
| AllocBuckets dual | `A_aa_00537bf0_CNDHash_AllocBuckets_009cf01c.md` |
| System map | `systems/missions-progression.md` — pending `+0x55c` |
| AddActiveObjective dual | `A_aa_00531b00_*` — pending map interaction |
| Caller | `FUN_0052b4e0` only (static) |

**Not performed:** `disassemble_bytes`, Launcher, runtime, binary diff.

---

## 3. Evidence table

| Claim | Evidence | Confidence |
|---|---|---|
| CF ≡ Recreate family | Bytes + decompile | **High** |
| Teardown `00539110` / clear `00538200` | Decompile | **High** |
| AllocBuckets `00537bf0` | Call + dual | **High** |
| Slot **char+0x55c** pending objectives | System map + ctor + `FUN_0052b4e0` | **High** |
| Default bits 2 / 4 buckets | Ctor stores bits=`2`, size=`4` | **High** (ctor path) |
| Product method name | String-inferred only | **Open** |
| Runtime | Not run | **Open** |

---

## 4. Recovered CF

```c
// void __thiscall Recreate(CNDHash* this, uint8_t log2Bits)  // RET 4
if (this->lock) log Recreate-locked + VOG_DEBUG_STOP;
Teardown_00539110(this);
this->log2Bits = log2Bits;
this->tail = this->head = 0;
this->size_or_mask = 1u << (log2Bits & 31);
AllocBuckets_00537bf0(this);  // mask = N-1; sentinels 009cf01c
```

---

## 5. Control flow: clean ≡ raw ≡ bytes

| Stage | Match |
|---|---|
| Lock-log-continue | **Yes** |
| Owning teardown + AllocBuckets | **Yes** |
| Distinct callees vs other twins | **Yes** |

---

## 6. Gaps

1. Export / RTTI name.
2. Whether recreate bits always re-read from `+0x1c` (yes at sole caller).
3. Interaction with `CVOGMission_AddActiveObjective` after wipe — parent responsibility.
4. Runtime / bit-exact.

**Verdict:** **accept-with-gaps** — pending-hash Recreate twin sealed High.
