# Review A (reconstruction fidelity): `aa_00537ab0` CNDHash_AllocBuckets_009cf00c

| Field | Value |
|---|---|
| **Stable ID** | `aa_00537ab0` |
| **VA** | `0x00537ab0` |
| **Canonical name** | `CNDHash_AllocBuckets` (sentinel vtbl `PTR_LAB_009cf00c`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Path A — fidelity |
| **Counterpart** | `reviews/B_aa_00537ab0_CNDHash_AllocBuckets_009cf00c.md` |
| **System** | container / CNDHash family |
| **Live tools** | `batch_decompile` + `force_decompile`; twin family; xrefs |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Bucket alloc twin** of `FUN_005378d0` / `FUN_00537a10` — identical CF:

- bits range 1..16 else throw
- `new` pointer table @ `+0x10`, `malloc` sentinel slab `N*0xc`
- size → mask (`N-1`) at `+0x08`

**Only delta:** each sentinel stamped with **`PTR_LAB_009cf00c`**.

### Callers

| Site | Role |
|---|---|
| `0x00537113` | Character ctor `FUN_00536920` inline — object vtbl `PTR_FUN_009cfa70`, bits=`4`, size=`0x10` → mask `0xF` |

No Recreate twin found that calls this VA (unlike `00537a10`/`00537b50`/`00537bf0`).

---

## 2. Confidence

| Claim | Level |
|---|---|
| CF ≡ AllocBuckets family except stamp | **Confirmed** |
| Mask conversion | **Confirmed** |
| force ≡ batch | **Confirmed** |

---

## 3. Recovered CF

```c
// same as AllocBuckets_009ceff4 with sentinel vtbl = 009cf00c
```

**Verdict:** **accept-with-gaps** — twin sealed; do not merge VAs.
