# Review A (reconstruction fidelity): `aa_004bfdb0` ObjectBucket_SetFlagByte51 (**INFERRED**)

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bfdb0` |
| **VA** | `0x004bfdb0` |
| **Canonical name** | `ObjectBucket_SetFlagByte51` (**INFERRED**) |
| **Ghidra symbol** | `FUN_004bfdb0` |
| **Review date** | `2026-07-29` |
| **Counterpart** | `reviews/B_aa_004bfdb0_ObjectBucket_SetFlagByte51_Inferred.md` |
| **System** | `inventory-transfer` (loot nested) |
| **Parent batch** | AddItem → `Inv_lootpickup` sole xref `0x0094582a` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Walk nine fixed buckets on `this`, find entry matching key via `FUN_005c6720`, set `*(match+0x51) = flag`.**

```c
// __thiscall
void ObjectBucket_SetFlagByte51(Host* this, void* matchKey, uint8_t flag);
```

Stops at **first** match. No match → no write.

---

## 2. Inspected artifacts

| Artifact | Evidence |
|---|---|
| Live decompile | ≡ raw |
| Live bytes | `53 55 56 57 33 ed 8d 59 08` … loop `uVar4 < 9`, stride `+0x0C` per bucket |
| Xrefs | **1** — lootpickup `0x0094582a` |
| Raw | `raw/aa_004bfdb0_FUN_004bfdb0.md` |

---

## 3. Control flow

| Stage | Match |
|---|---|
| Bucket base `this+8`, 9 iterations, step 3 dwords | **Yes** |
| Skip empty (`bucket[1]==0` or list head==self) | **Yes** |
| Node walk; payload `node[2]`; `FUN_005c6720(key)` | **Yes** |
| On match: `*(payload+0x51)=flag`; return | **Yes** |
| Fall through: no store | **Yes** |

---

## 4. Confidence

| Claim | Confidence |
|---|---|
| 9-bucket scan + first match sets `+0x51` | **High** |
| Lootpickup-only consumer | **High** |
| Product meaning of byte `+0x51` | **Open** |
| `FUN_005c6720` equality semantics | **Probable** (match predicate) |
| Runtime | **Open** |

**Verdict:** **accept-with-gaps** — sealed as loot-side flag stamp on matched bucket object.
