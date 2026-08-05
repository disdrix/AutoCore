# Review A (reconstruction fidelity): `aa_0053b670` CNDHash_Dtor_009cfa58

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053b670` |
| **VA** | `0x0053b670` |
| **Canonical name** | `CNDHash_Dtor` (object vtbl `PTR_FUN_009cfa58`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Path A — fidelity |
| **Counterpart** | `reviews/B_aa_0053b670_CNDHash_Dtor_009cfa58.md` |
| **System** | container / CNDHash family / objectives |
| **Live tools** | `batch_decompile`; twin dtor family; callers |
| **Dual status** | **Present — sealed 2026-07-29** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**CNDHash destructor twin** of `FUN_0053b560` for object vtbl **`PTR_FUN_009cfa58`** (matches sealed ctor `0053b1b0` / char active-objectives install).

| Step | This VA | Twin `0053b560` |
|---|---|---|
| Object vtbl | `009cfa58` | `009cfa4c` |
| FreeBuckets | `FUN_0053b6e0` | `FUN_0053b5d0` |
| Reclaim | `FUN_0053b720` (node stamp `009cf02c`) | `FUN_0053b610` (`009cf024`) |
| Freelist slabs | `FUN_0059c8a0` | same |
| Scalar dtor | `FUN_0053b650` | `FUN_0053b540` |

CF: SEH → vtbl stamp → lock log → FreeBuckets (non-owning reclaim + free table) → freelist vector teardown.

Reclaim loop: for `bucket = 0 .. mask` inclusive; walk `sentinel->head` (`table[i]+4`); push nodes to freelist `+0x20` (overwrite node vtbl with freelist link).

---

## 2. Confidence

| Claim | Level |
|---|---|
| CF ≡ dtor family | **Confirmed** |
| Non-owning reclaim | **Confirmed** (no value delete) |
| Pairs with ctor `0053b1b0` | **High** |
| Char `+0x548` uses this object vtbl | **High** (ctor install) |

**Verdict:** **accept-with-gaps.**
