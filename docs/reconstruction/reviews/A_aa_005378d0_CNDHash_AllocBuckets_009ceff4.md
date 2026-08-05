# Review A (reconstruction fidelity): `aa_005378d0` CNDHash_AllocBuckets_009ceff4

| Field | Value |
|---|---|
| **Stable ID** | `aa_005378d0` |
| **VA** | `0x005378d0` |
| **Canonical name** | `CNDHash_AllocBuckets` (sentinel vtbl `PTR_LAB_009ceff4`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Path A — fidelity |
| **Counterpart** | `reviews/B_aa_005378d0_CNDHash_AllocBuckets_009ceff4.md` |
| **System** | container / CNDHash family |
| **Live tools** | batch + force decompile, ctor caller |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Allocate bucket table + sentinel slab** for a freshly-constructed CNDHash — `__fastcall` / ECX = hash:

1. Require `1 <= (char)(this+0x1c) <= 16` (log2 bits). Else log `VOG_DEBUG_STOP` and throw signed `-0x7fffbffd` (`0x80004003` E_POINTER-shaped).
2. `this+0x08` holds **bucket count** `N = 1<<bits` (set by ctor).
3. `operator_new__(N * 4)` → pointer array stored at `this+0x10`.
4. `malloc(N * 0xc)` → contiguous sentinel slab.
5. For `i = 0 .. N-1`:
   - `table[i] = &slab[i]` (each sentinel 0x0c bytes).
   - Sentinel: vtbl `PTR_LAB_009ceff4`, `+4 = 0` (chain head), `+8 = 0`.
6. **`this+0x08 = N - 1`** — convert size → **mask** for `key & mask`.

Called from `FUN_0053b0b0` and other init sites (`00536f38`… family).

---

## 2. Sentinel layout (0x0c)

| Off | Field |
|---|---|
| +0x00 | vtbl `009ceff4` |
| +0x04 | first node* (bucket chain head; insert/remove use this) |
| +0x08 | reserved / zeroed |

Matches insert head-insert at `sentinel+4` and `FUN_004e2ca0` chain-root framing.

---

## 3. Confidence

| Claim | Level |
|---|---|
| CF A≡B ≡ force | **Confirmed** |
| Bits range 1..16 | **Confirmed** |
| Size→mask via `N-1` | **Confirmed** |
| Sentinel 0xc + vtbl stamp | **Confirmed** |
| `operator_new__` for ptr table, `malloc` for slab | **Confirmed** |
| Out-of-range → throw (noreturn) | **Confirmed** |

---

## 4. Recovered CF

```c
// void __fastcall AllocBuckets(CNDHash *this)
bits = this->log2Bits; // +0x1c
if (!(1 <= bits && bits <= 16)) { log; throw E_POINTER_shaped; }
N = this->mask_or_size; // still size
this->buckets = new void*[N];
slab = malloc(N * 0xc);
for (i=0; i<N; i++) {
  s = slab + i*0xc;
  this->buckets[i] = s;
  s->vtbl = 009ceff4; s->head = 0; s->pad = 0;
}
this->mask = N - 1;
```

---

## 5. Gaps

1. Sentinel vtbl methods.
2. Whether ptr table uses array-new dtor path on hash destroy (not this unit).
3. Twin allocs (`00537970` etc.) not dualed here beyond known delta.

**Verdict:** **accept-with-gaps** — AllocBuckets CF + mask conversion sealed High.
