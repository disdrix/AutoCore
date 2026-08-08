# Review B (skeptical / independent): `aa_00408a30` StdTree_BuyHeadNode_Isnil29_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00408a30` |
| **VA** | `0x00408a30` |
| **Canonical name** | `StdTree_BuyHeadNode_Isnil29_Inferred` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Skeptical naming / anti-overclaim |
| **Counterpart** | `reviews/A_aa_00408a30_StdTree_BuyHeadNode_Isnil29_Inferred.md` |
| **System** | STL / map-set head node |
| **Verdict** | **accept-with-gaps** — agree with A |

---

## 1. Adversarial read of proposed names

| Candidate | Ruling |
|---|---|
| `FUN_00408a30` only | Scaffold OK; under-describes role |
| `Named_CalleeOf_Named_Client_Constructor_00408a30` | **Reject** — chain-of-caller; shared STL head helper |
| `CNDHash_*` / freelist release | **Reject** — CRT new; no hash freelist @+0x20 |
| `StdTree_Buynode_Val24_*` | **Reject** — no value copy; no stack args; head shell |
| Full MSVC `_Buyheadnode` (self-link inside) | **Reject** — self-link + isnil1 are **caller** side |
| `StdTree_BuyHeadNode_Isnil29_Inferred` | **Accept** — role from callers; `_Inferred` honest |

---

## 2. Attacks on A's CF claims

| Attack | Result |
|---|---|
| void return (no pointer) | **Fails** — EAX node used by all callers |
| thiscall ECX=host | **Fails** — no ECX use; bare RET |
| isnil left at 0 permanently | **Fails** — callers force `byte [eax+0x29]=1` |
| Initializes Val24 payload | **Fails** — only links + color/isnil |
| Same as `00408990` buynode | **Fails** — 0x30 vs 0x28; different ABI |
| Freelist pop | **Fails** — `operator_new(0x30)` |
| Product English proven | **Fails** — open; keep `_Inferred` |

---

## 3. Agreement with Review A

- Alloc shell CF + layout + caller head-install pattern: **agree Confirmed/High**
- Name with `_Inferred`: **agree**
- Gaps (PDB, ctor duals, OOM odd, runtime): **agree open**

---

## 4. Residual risks

- Do not claim self-link inside this VA; document caller completion.
- Do not merge with Val16 buynode `00408990` or Val24 insert buynode `00407e30`.
- Clean plate softens OOM field-check oddity — annotated/raw preserve machine shape.

**Verdict:** **accept-with-gaps**
