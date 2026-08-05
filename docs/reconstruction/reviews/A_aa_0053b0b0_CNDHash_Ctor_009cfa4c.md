# Review A (reconstruction fidelity): `aa_0053b0b0` CNDHash_Ctor_009cfa4c

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053b0b0` |
| **VA** | `0x0053b0b0` |
| **Canonical name** | `CNDHash_Ctor` (hash object vtbl `PTR_FUN_009cfa4c`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Path A — fidelity |
| **Counterpart** | `reviews/B_aa_0053b0b0_CNDHash_Ctor_009cfa4c.md` |
| **System** | container / CNDHash family / mission region tables |
| **Live tools** | batch + force decompile, bucket init callee, xrefs |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**CNDHash constructor** — `__thiscall Ctor(this, byte log2BucketBits)`:

1. Install object vtbl `PTR_FUN_009cfa4c`.
2. Zero secondary fields; set provisional bucket **count** `this+0x08 = 1 << (bits & 0x1f)`.
3. Zero count `+0x0c`, buckets `+0x10`, list head/tail `+0x14/+0x18`, freelist `+0x20`, slab vector slots `+0x28/+0x2c/+0x30`.
4. Store log2 bits at **`this+0x1c`**; clear lock **`this+0x1d`**.
5. Call **`FUN_005378d0`** — allocate bucket pointer table + sentinel slab, then convert `+0x08` from size → **mask** (`size - 1`).
6. Return `this`.

Sealed by residual `a_0053fff0`: mission-id primary hash uses this ctor with bits=`8` (256 buckets → mask `0xFF`).

Callers (xrefs): `0060b924`, `0060b985`, `0060b9be` (region mission table setup).

---

## 2. Layout written by ctor (+ bucket init)

| Off | Field | After ctor |
|---|---|---|
| +0x00 | object vtbl | `009cfa4c` |
| +0x04 | (zeroed) | 0 |
| +0x08 | mask | `(1<<bits)-1` after `FUN_005378d0` |
| +0x0c | count | 0 |
| +0x10 | buckets* | array of sentinel* |
| +0x14 / +0x18 | list head / tail | 0 |
| +0x1c | log2 bits (byte) | `param_2` |
| +0x1d | traversal lock | 0 |
| +0x20 | freelist head | 0 |
| +0x28 / +0x2c / +0x30 | freelist slab vector | 0 |

Object footprint at least **0x34**. `+0x24` not written here (Open residual).

---

## 3. Confidence

| Claim | Level |
|---|---|
| CF A≡B ≡ force | **Confirmed** |
| Bits arg drives `1<<bits` then mask | **Confirmed** |
| Bucket init delegated to `FUN_005378d0` | **Confirmed** |
| Lock / freelist / list zeroed | **Confirmed** |
| Mission primary uses this vtbl family | **High** (residual + callers) |
| Full product class name | **Probable** |
| `+0x24` role | **Open** |

---

## 4. Recovered CF

```c
// CNDHash* __thiscall Ctor(CNDHash *this, byte log2Bits)
this->vtbl = PTR_FUN_009cfa4c;
this->mask_or_size = 1u << (log2Bits & 31);  // size until AllocBuckets
this->count = 0;
this->buckets = this->head = this->tail = null;
this->log2Bits = log2Bits;                    // +0x1c
this->lock = 0;                               // +0x1d
this->freelist = 0;                           // +0x20
// zero freelist slab vector (+0x28..+0x30)
AllocBuckets_005378d0(this);                  // size→mask; fill table
return this;
```

---

## 5. Gaps

1. Exact sizeof(CNDHash) product (0x34 vs larger).
2. Field at `+0x04` / `+0x24` meaning.
3. Object-vtbl methods behind `009cfa4c` not dualed here.
4. Call-site bits always 8? Open beyond residual claim.

**Verdict:** **accept-with-gaps** — ctor CF + layout core sealed High.
