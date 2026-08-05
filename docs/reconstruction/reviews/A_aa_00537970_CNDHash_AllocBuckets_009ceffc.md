# Review A (reconstruction fidelity): `aa_00537970` CNDHash_AllocBuckets_009ceffc

| Field | Value |
|---|---|
| **Stable ID** | `aa_00537970` |
| **VA** | `0x00537970` |
| **Canonical name** | `CNDHash_AllocBuckets` (sentinel vtbl `PTR_LAB_009ceffc`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Path A — fidelity |
| **Counterpart** | `reviews/B_aa_00537970_CNDHash_AllocBuckets_009ceffc.md` |
| **System** | container / CNDHash family |
| **Live tools** | batch decompile, twin `005378d0`, ctor `0053b1b0` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Bucket alloc twin** of `FUN_005378d0` — identical CF:

- bits range 1..16 else throw
- `new` pointer table @ `+0x10`, `malloc` sentinel slab `N*0xc`
- size → mask (`N-1`) at `+0x08`

**Only delta:** each sentinel stamped with **`PTR_LAB_009ceffc`** (not `009ceff4`).

Caller: `FUN_0053b1b0` @ `0053b20a`; also `005370b4`.

---

## 2. Confidence

| Claim | Level |
|---|---|
| CF ≡ `005378d0` except sentinel vtbl | **Confirmed** |
| Mask conversion | **Confirmed** |

---

## 3. Recovered CF

```c
// same as AllocBuckets_009ceff4 with sentinel vtbl = 009ceffc
```

**Verdict:** **accept-with-gaps** — twin sealed; do not merge VAs.
