# Review A (reconstruction fidelity): `aa_00537b50` CNDHash_AllocBuckets_009cf014

| Field | Value |
|---|---|
| **Stable ID** | `aa_00537b50` |
| **VA** | `0x00537b50` |
| **Canonical name** | `CNDHash_AllocBuckets` (sentinel vtbl `PTR_LAB_009cf014`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Path A — fidelity |
| **Counterpart** | `reviews/B_aa_00537b50_CNDHash_AllocBuckets_009cf014.md` |
| **System** | container / CNDHash family |
| **Live tools** | `batch_decompile`; twin family; xrefs |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Bucket alloc twin** — CF ≡ sealed AllocBuckets family:

- bits 1..16 else throw; `operator_new__` table; `malloc` sentinel slab; size→mask

**Only delta:** sentinel stamp **`PTR_LAB_009cf014`**.

### Callers

| Site | Role |
|---|---|
| `0x00537172` | Character ctor `FUN_00536920` — object vtbl `PTR_FUN_009cfa7c`, bits=`4`, size=`0x10` |
| `0x00539e1c` | `FUN_00539dd0` Recreate |

---

## 2. Confidence

| Claim | Level |
|---|---|
| CF ≡ family except stamp | **Confirmed** |
| Mask conversion | **Confirmed** |

---

## 3. Recovered CF

```c
// same as AllocBuckets family; sentinel vtbl = 009cf014
```

**Verdict:** **accept-with-gaps.**
