# Review A (reconstruction fidelity): `aa_00537bf0` CNDHash_AllocBuckets_009cf01c

| Field | Value |
|---|---|
| **Stable ID** | `aa_00537bf0` |
| **VA** | `0x00537bf0` |
| **Canonical name** | `CNDHash_AllocBuckets` (sentinel vtbl `PTR_LAB_009cf01c`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Path A — fidelity |
| **Counterpart** | `reviews/B_aa_00537bf0_CNDHash_AllocBuckets_009cf01c.md` |
| **System** | container / CNDHash family |
| **Live tools** | `batch_decompile`; twin family; xrefs |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Bucket alloc twin** — CF ≡ sealed AllocBuckets family:

- bits 1..16 else throw; pointer table + sentinel slab; size→mask

**Only delta:** sentinel stamp **`PTR_LAB_009cf01c`**.

### Callers

| Site | Role |
|---|---|
| `0x005371d1` | Character ctor `FUN_00536920` — object vtbl `PTR_FUN_009cfa88`, bits=`2`, size=`4` → mask `3` |
| `0x00539e7c` | `FUN_00539e30` Recreate |

---

## 2. Confidence

| Claim | Level |
|---|---|
| CF ≡ family except stamp | **Confirmed** |
| Small table (4 buckets / mask 3) used product-side | **High** (ctor inline) |
| Mask conversion | **Confirmed** |

---

## 3. Recovered CF

```c
// same as AllocBuckets family; sentinel vtbl = 009cf01c
```

**Verdict:** **accept-with-gaps.**
