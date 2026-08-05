# Review A (reconstruction fidelity): `aa_0051f4e0` Character_SetLocalVehiclePtr_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051f4e0` |
| **VA** | `0x0051f4e0`–`0x0051f505` (approx; short body) |
| **Canonical name** | `Character_SetLocalVehiclePtr_Inferred` (Ghidra `FUN_0051f4e0`) |
| **Ghidra name** | `FUN_0051f4e0` |
| **Prior alias** | `Named_CalleeOf_Client_RecvInventoryUsePaint_0051f4e0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual) |
| **Counterpart** | `reviews/B_aa_0051f4e0_Character_SetLocalVehiclePtr_Inferred.md` |
| **System** | character / local vehicle / inventory cursor residual |
| **Live tools** | `batch_decompile`, paint + cursor callers |
| **Verdict** | **accept-with-gaps** |
| **Dual status** | **Present (first full dual)** |

---

## 1. Purpose

**Set character field `+0xcd0` (local / bound vehicle pointer)** and, if non-null, invoke vehicle vfunc **`+0x158`** (refresh / bind-side-effect):

```c
// __thiscall
void Character_SetLocalVehiclePtr_Inferred(Character *this, void *vehicleOrNull);
```

```c
*(this + 0xcd0) = vehicleOrNull;
if (vehicleOrNull != NULL)
  vehicleOrNull->vtbl[+0x158]();   // decompiler: jumptable noise; still indirect call
```

### Callers

| Caller | Pattern |
|---|---|
| `Client_RecvInventoryUsePaint` `0x008095f0` | When painted object is local vehicle (`char+0xcd0`), call with **0** (clear / rebind path per parent dual) |
| `Client_ClearInventoryCursor` `0x007fc150` | Via `client+0xe98` character path → `FUN_0051f4e0(0)` |
| `Client_SetInventoryCursor` `0x007fc270` | Prep call on same `client+0xe98` ECX |

`OBJECT_LAYOUTS` / inventory docs treat `client+0xe98` as local character-ish object; `+0xcd0` is the local vehicle slot referenced across paint and destroy paths (`unaff_EDI[0x3a6]+0xcd8` TFID pair sits near).

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | `batch_decompile` @ `0x0051f4e0` ≡ raw |
| Paint dual | `A_aa_008095f0_Client_RecvInventoryUsePaint` |
| Cursor duals | `A_aa_007fc150_*`, `A_aa_007fc270_*` |
| Raw / clean | `raw/aa_0051f4e0_*`, `reconstructed-exact/FUN_0051f4e0.cpp` |

---

## 3. Confidence

| Claim | Level |
|---|---|
| CF dual A≡B ≡ raw ≡ live | **Confirmed** |
| Store at `this+0xcd0` | **Confirmed** |
| Null skips vfunc | **Confirmed** |
| Non-null calls `vtbl+0x158` | **Confirmed** (indirect) |
| Field is local vehicle pointer | **High** (paint “local vehicle char+0xcd0”; destroy TFID pair nearby) |
| Product English of vfunc `+0x158` | **Open** |
| Whether paint’s `(0)` is intentional clear vs refresh-only | **Open** (parent residual) |

**Verdict:** **accept-with-gaps.**
