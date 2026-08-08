# Review B (skeptical / independent): `aa_00408990` StdTree_Buynode_Val16_Isnil21_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00408990` |
| **VA** | `0x00408990` |
| **Canonical name** | `StdTree_Buynode_Val16_Isnil21_Inferred` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Skeptical naming / anti-overclaim |
| **Counterpart** | `reviews/A_aa_00408990_StdTree_Buynode_Val16_Isnil21_Inferred.md` |
| **System** | STL / map-set buynode |
| **Verdict** | **accept-with-gaps** — agree with A |

---

## 1. Adversarial read of proposed names

| Candidate | Ruling |
|---|---|
| `FUN_00408990` only | Scaffold OK; under-describes sealed role |
| `Named_CalleeOf_*` / Client chain | **Reject** — not a client method; shared STL helper |
| `CNDHash_*` / freelist reclaim | **Reject** — CRT `new(0x28)` + tree ctor; no freelist head |
| `StdTree_Buynode_Val24_Isnil29` | **Reject** — wrong size (0x28≠0x30), isnil@+0x21≠+0x29 |
| `StdTree_Buynode_Val12` | **Reject** — Val16 (4 dwords), not Val12 |
| Placement-new freelist buy | **Reject** — `operator_new` not freelist pop |
| `StdTree_Buynode_Val16_Isnil21_Inferred` | **Accept** — family-aligned; `_Inferred` honest |

---

## 2. Attacks on A's CF claims

| Attack | Result |
|---|---|
| thiscall ECX=map on entry | **Fails** — pure stack args; `RET 0x14`; ECX loaded only for ctor |
| void return / no pointer | **Fails** — `MOV EAX,ESI` before ret |
| Value is 6 dwords (Val24) | **Fails** — ctor copies 4 dwords only |
| isnil set from color arg | **Fails** — hard isnil=0 @+0x21 |
| color at +0x28 | **Fails** — color @+0x20 for this family |
| Same body as head alloc `00408a30` | **Fails** — different size/args/ABI |
| Product English proven | **Fails** — open; keep `_Inferred` |

---

## 3. Agreement with Review A

- Alloc/construct CF + ABI + layout: **agree Confirmed/High**
- Name with `_Inferred`: **agree**
- Gaps (PDB, ctor/insert dual residual, runtime): **agree open**

---

## 4. Residual risks

- Do not merge with Val24 isnil29 buynodes (`00407e30` / `005a2de0`) or head shell `00408a30`.
- Ctor `FUN_004099b0` and insert `FUN_00407200` undualed residuals (not OWN).

**Verdict:** **accept-with-gaps**
