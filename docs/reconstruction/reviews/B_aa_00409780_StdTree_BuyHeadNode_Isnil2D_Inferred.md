# Review B (skeptical / independent): `aa_00409780` StdTree_BuyHeadNode_Isnil2D_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00409780` |
| **VA** | `0x00409780` |
| **Canonical name** | `StdTree_BuyHeadNode_Isnil2D_Inferred` |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Skeptical naming / anti-overclaim |
| **Counterpart** | `reviews/A_aa_00409780_StdTree_BuyHeadNode_Isnil2D_Inferred.md` |
| **System** | STL / map-set head node |
| **Verdict** | **accept-with-gaps** — agree with A |

---

## 1. Adversarial read of proposed names

| Candidate | Ruling |
|---|---|
| `FUN_00409780` only | Scaffold OK; under-describes role |
| Chain-of-caller / error-string plate | **Reject** — shared STL head helper |
| `CNDHash_*` / freelist release | **Reject** — CRT new; no freelist @+0x20 |
| `StdTree_Buynode_Val24_*` / value buy | **Reject** — no value copy; no stack args |
| `StdTree_BuyHeadNode_Isnil29_*` merge | **Reject** — isnil@**+0x2d** not +0x29 |
| Full MSVC `_Buyheadnode` (self-link inside) | **Reject** — self-link + isnil1 are **caller** side |
| `StdTree_BuyHeadNode_Isnil2D_Inferred` | **Accept** — role from caller; `_Inferred` honest |

---

## 2. Attacks on A's CF claims

| Attack | Result |
|---|---|
| void return (no pointer) | **Fails** — EAX node used by sole caller |
| thiscall ECX=host | **Fails** — no ECX use; bare RET |
| isnil left at 0 permanently | **Fails** — caller forces `byte [eax+0x2d]=1` |
| Initializes Val32 payload | **Fails** — only links + color/isnil |
| Same as `00408a30` isnil29 head | **Fails** — color/isnil offsets differ (+0x2c/+0x2d vs +0x28/+0x29) |
| Same isnil family as co-located `00409820` | **Fails** — pred uses +0x29; this uses +0x2d |
| Freelist pop | **Fails** — `operator_new(0x30)` |
| Product English proven | **Fails** — open; keep `_Inferred` |

---

## 3. Agreement with Review A

- Alloc shell CF + layout + caller head-install pattern: **agree Confirmed/High**
- Name with `_Inferred`: **agree**
- Gaps (PDB, ctor dual, OOM odd, runtime): **agree open**

---

## 4. Residual risks

- Do not claim self-link inside this VA; document caller completion.
- Do not merge with isnil29 BuyHeadNode `00408a30` or co-located isnil29 pred `00409820` as same node family.
- Clean plate softens OOM field-check oddity — annotated/raw preserve machine shape.

**Verdict:** **accept-with-gaps**
