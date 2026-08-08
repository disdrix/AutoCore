# Review B (skeptical / independent): `aa_00401db0` StdTree_InsertAndRebalance_Isnil2D_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00401db0` |
| **VA** | `0x00401db0` |
| **Canonical name** | `StdTree_InsertAndRebalance_Isnil2D_Inferred` |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Skeptical naming / anti-overclaim |
| **Counterpart** | `reviews/A_aa_00401db0_StdTree_InsertAndRebalance_Isnil2D_Inferred.md` |
| **System** | STL / map-set |
| **Verdict** | **accept-with-gaps** — agree with A |

---

## 1. Adversarial read of proposed names

| Candidate | Ruling |
|---|---|
| `FUN_00401db0` only | Acceptable scaffold; under-describes sealed role |
| `Named_CalleeOf_*Mission*null*dialog*_00401db0` | **Reject** — chain-of-caller noise; body has zero mission/dialog strings or UI calls |
| `Mission_NullDialog_InsertNode` | **Reject** — invents product domain from partition hint only |
| `StdMap_StringKey_InsertNodeAndRebalance` (unsuffixed) | **Reject as sole name** — already owned by dualed clone `0x00430b60`; would collide clean path |
| `StdTree_InsertAndRebalance_Isnil29_Inferred` | **Reject** — wrong family (color@+0x28, max `0x0AAAAAA8`, thiscall ECX=map RET 0x10) |
| `StdTree_InsertAndRebalance_Isnil31_*` | **Reject** — wrong isnil offset / node size |
| `StdTree_InsertAndRebalance_Isnil2D_Inferred` | **Accept** — family-aligned with dualed rotates; `_Inferred` honest |

---

## 2. Attacks on A's CF claims

| Attack | Result |
|---|---|
| Function is insert-or-find (compares keys) | **Fails** — no key compare; parent `00401c50` walks with `operator<` on string @+0x0C |
| Map lives in ECX (standard thiscall) | **Fails** — entry never `mov edi,ecx`; uses preloaded EDI; call sites `MOV EDI,EDX` then `MOV ECX,EBP` |
| isnil@+0x29 / color@+0x28 family | **Fails** — immediates `+0x2c` color; rotates dualed isnil2D check `+0x2d` |
| Max size same as isnil29 (`0x0AAAAAA8`) | **Fails** — imm `0x7fffffe` matches string-key clone `00430b60` |
| L/R rotate args omit map / wrong direction | **Fails** — `PUSH EDI` then CALL; L at `0044e010` when uncle is right-side black case; R at `0042a840` symmetric |
| Product mission English proven | **Fails** — open; keep `_Inferred` |
| Same function as `00430b60` | **Fails** — different VA/body/buynode; structural clone only |

---

## 3. Agreement with Review A

- Always-insert + RB + EDI/ECX/`ret 0x0C` + isnil2D layout: **agree Confirmed/High**
- Name with `_Inferred`: **agree**
- Gaps (PDB, mapped payload, parent dual, runtime): **agree open**
- Partition mission-dialog hint is non-product for this VA: **agree**

---

## 4. Residual risks

- Do not merge clean path with `StdMap_StringKey_InsertNodeAndRebalance.cpp` (`00430b60`).
- Do not merge with isnil29 insert `00406c40` without layout/ABI check.
- Buynode `FUN_00401f40` / ctor `FUN_00401fe0` / parent `FUN_00401c50` remain undualed OWN residuals.
- Decompiler `void __thiscall` + `unaff_EDI` misleads casual readers — assembly is authoritative for ABI.

**Verdict:** **accept-with-gaps**
