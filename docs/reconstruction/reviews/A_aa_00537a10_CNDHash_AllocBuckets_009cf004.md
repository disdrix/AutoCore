# Review A (reconstruction fidelity): `aa_00537a10` CNDHash_AllocBuckets_009cf004

| Field | Value |
|---|---|
| **Stable ID** | `aa_00537a10` |
| **VA** | `0x00537a10` |
| **Canonical name** | `CNDHash_AllocBuckets` (sentinel vtbl `PTR_LAB_009cf004`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Path A — fidelity |
| **Counterpart** | `reviews/B_aa_00537a10_CNDHash_AllocBuckets_009cf004.md` |
| **System** | container / CNDHash family |
| **Live tools** | `batch_decompile` + `force_decompile`; sealed twins `005378d0`/`00537970`; callers |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Allocate bucket table + sentinel slab** — twin of sealed `FUN_005378d0` / `FUN_00537970`. `__fastcall` / ECX = hash:

1. Require `1 <= (char)(this+0x1c) <= 16` (log2 bits). Else log `VOG_DEBUG_STOP` and throw signed `-0x7fffbffd` (`0x80004003` E_POINTER-shaped).
2. `this+0x08` holds **bucket count** `N` (set by ctor/recreate as `1<<bits`).
3. `operator_new__(N * 4)` → pointer array stored at `this+0x10`.
4. `malloc(N * 0xc)` → contiguous sentinel slab.
5. For `i = 0 .. N-1`:
   - `table[i] = &slab[i]` (each sentinel 0x0c bytes).
   - Sentinel: vtbl **`PTR_LAB_009cf004`**, `+4 = 0` (chain head), `+8 = 0`.
6. **`this+0x08 = N - 1`** — convert size → **mask** for `key & mask`.

**Only delta vs sealed AllocBuckets:** sentinel stamp **`009cf004`**.

### Callers (live xrefs)

| Site | Role |
|---|---|
| `0x00536ed9` | Inline hash build in character ctor cluster `FUN_00536920` — object vtbl `PTR_FUN_009cfa64`, bits=`8`, size=`0x100` → mask `0xFF` |
| `0x00539dbc` | `FUN_00539d70` Recreate — teardown then re-alloc with this twin |

---

## 2. Confidence

| Claim | Level |
|---|---|
| CF A≡B ≡ force ≡ raw | **Confirmed** |
| Bits range 1..16 | **Confirmed** |
| Size→mask via `N-1` | **Confirmed** |
| Sentinel 0xc + vtbl `009cf004` | **Confirmed** |
| Separate `operator_new__` + `malloc` | **Confirmed** |

---

## 3. Recovered CF

```c
// void __fastcall AllocBuckets_009cf004(CNDHash *this)
bits = this->log2Bits; // +0x1c
if (!(1 <= bits && bits <= 16)) { log; throw E_POINTER_shaped; }
N = this->mask_or_size; // still size
this->buckets = new void*[N];
slab = malloc(N * 0xc);
for (i=0; i<N; i++) {
  s = slab + i*0xc;
  this->buckets[i] = s;
  s->vtbl = 009cf004; s->head = 0; s->pad = 0;
}
this->mask = N - 1;
```

---

## 4. Gaps

1. Sentinel vtbl methods behind `009cf004`.
2. Full product name for object vtbl `009cfa64` hash that consumes this alloc.
3. Do not merge with `005378d0`/`00537970`/later twins — stamp differs.

**Verdict:** **accept-with-gaps** — AllocBuckets twin CF + mask conversion sealed High.
