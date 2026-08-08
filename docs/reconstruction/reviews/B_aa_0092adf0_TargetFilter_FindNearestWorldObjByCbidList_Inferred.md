# Review B (adversarial): `aa_0092adf0` TargetFilter_FindNearestWorldObjByCbidList_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0092adf0` |
| **VA** | `0x0092adf0` |
| **Canonical name** | `TargetFilter_FindNearestWorldObjByCbidList_Inferred` |
| **Review date** | `2026-08-04` (WQ8R-I dual seal) |
| **Reviewer role** | Adversarial / red-team reconstruction |
| **Counterpart** | `reviews/A_aa_0092adf0_TargetFilter_FindNearestWorldObjByCbidList_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## Attacks considered

### 1. “This is just generic world scan — not inventory-related”

**Reject.** Image mid-loop **always** calls `InventoryGrid_FindItemByCoid` with object COID and continues only on **NULL**. That is a hard inventory dependency, even if the primary UX is “pick nearest CBID”.

### 2. “ECX for Find is cargo `+0x2B0`, not locker `+0xCBC`”

**Reject for this VA.** Bytes: after `ECX = character`, self-check uses `+0x250`, then **`mov ecx,[ecx+0xCBC]`** before the Find call. Cargo path is used by **sibling** unit `0x00941f50`, not this one.

### 3. “unaff_EDI is phantom / wrong register”

**Reject.** Entry uses `[edi]` for client; caller `FUN_0092af80` keeps filter object in a register across sibling calls; count gate `in_EAX+0x28` on the same object. EDI binding is consistent with sibling `0092abc0` decompile.

### 4. “Returns nearest always / mutates inventory”

**Reject.** No inventory mutation; only read Find. May leave `*bestOut` unchanged if no match. Always returns 1 after unlock (success of scan, not “found”).

### 5. “Name overclaims skill system”

**Partial accept.** No RTTI/string on this leaf. Name uses **TargetFilter_** + **_Inferred** from caller graph (`0092af80` multi-list + `0092bf60` character target attempt). Product English residual is explicit gap — not a seal failure on CF.

### 6. “clonebase+0x34 is not CBID”

**Low risk.** Same plate used across inventory/mission duals for CBID; whitelist compare is structural even if product string differs.

---

## Residual risks

| Risk | Severity | Mitigation |
|---|---|---|
| Locker-only absence may be intentional type-3 semantics | Med | Documented; do not “fix” to cargo without bytes |
| Filter ctx layout beyond used fields | Low | Only seal used offsets |
| vtbl+0x144 side effects | Low | Call order sealed; semantics open |

---

## Verdict

**accept-with-gaps** — adversarial review does **not** overturn A on sealed CF, ABI, Find gate, or CBID nearest logic. Naming remains inferred.
