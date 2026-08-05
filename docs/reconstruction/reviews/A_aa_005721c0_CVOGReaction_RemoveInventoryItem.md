# Review A (reconstruction fidelity): `aa_005721c0` CVOGReaction_RemoveInventoryItem

| Field | Value |
|---|---|
| **Stable ID** | `aa_005721c0` |
| **VA** | `0x005721c0` |
| **Canonical name** | `CVOGReaction_RemoveInventoryItem` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005721c0_CVOGReaction_RemoveInventoryItem.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Walk a locked inventory (`this`) and remove up to `qty` of items matching clonebase **CBID** (`param_2`):

1. Early-out if `cbid == -1` or `qty < 1` → return 0.
2. SEH + build temp list (`FUN_0040fb90`) + take lock (`FUN_004294f0`).
3. Iterate items (`FUN_004022a0`); match `*(item[0x2a]+0x34) == cbid`.
4. Stack qty via vfunc `+0x25c`; if stack &gt; need → reduce via `+0x260`, accumulate, stop.
5. Else full-remove stack into temp list, subtract need, continue.
6. Leave CS if `inv+0x54` held (`+0x30` CRITICAL_SECTION); destroy queued via `FUN_00571b80(...,1000000,1)` + `FUN_004d4790`; free list; return removed total.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005721c0_CVOGReaction_RemoveInventoryItem.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGReaction_RemoveInventoryItem.cpp` |
| Function record | `docs/reconstruction/functions/aa_005721c0_CVOGReaction_RemoveInventoryItem.md` |
| System map | `docs/reconstruction/systems/inventory-transfer.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `__thiscall(inv, cbid, qty) → removed` | **High** | Raw |
| Early -1 / qty&lt;1 | **High** | Raw |
| CBID match at clonebase+0x34 via item[0x2a] | **High** | Same inventory pattern |
| Partial reduce vs full remove | **High** | CF |
| CS at +0x30 / held +0x54 | **High** | LeaveCriticalSection |
| Temp list destroy loop | **High** | Explicit |
| FUN names for list/iter/destroy | **Tentative** | Unnamed |
| Magic `1000000` destroy qty | **Probable** | “all” sentinel style |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| SEH / early out | **Yes** |
| Lock + iterate | **Yes** |
| Partial / full branches | **Yes** |
| Unlock + destroy + return | **Yes** |
| Infinite-loop decompile shape preserved | **Yes** |

---

## 5. Gaps

1. Temp-list node structure Probable only.
2. Iterator FUN semantics open.
3. Reaction-dispatch call sites not enumerated here.
4. Runtime multi-stack remove not observed.

**Verdict:** Remove-by-CBID CF faithful. **accept-with-gaps.**
