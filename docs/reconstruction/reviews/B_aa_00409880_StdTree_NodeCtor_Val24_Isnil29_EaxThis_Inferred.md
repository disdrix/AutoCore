# Review B (skeptical / independent): `aa_00409880` StdTree_NodeCtor_Val24_Isnil29_EaxThis_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00409880` |
| **VA** | `0x00409880` |
| **Canonical name** | `StdTree_NodeCtor_Val24_Isnil29_EaxThis_Inferred` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Skeptical naming / anti-overclaim |
| **Counterpart** | `reviews/A_aa_00409880_StdTree_NodeCtor_Val24_Isnil29_EaxThis_Inferred.md` |
| **System** | STL / map-set node construct |
| **Verdict** | **accept-with-gaps** — agree with A |

---

## 1. Adversarial read of proposed names

| Candidate | Ruling |
|---|---|
| `FUN_00409880` only | Scaffold OK; under-describes sealed role |
| `Named_CalleeOf_*Client_*` chain scaffold | **Reject** — shared STL helper |
| CNDHash / freelist node init | **Reject** — no freelist pop/push; pure field stores |
| `StdTree_Buynode_*` (allocating) | **Reject** — no `operator_new`; construct-only |
| Merge with `FUN_004098d0` as same symbol | **Reject** — distinct ABI (EAX-this / RET 0xC vs thiscall / RET 0x14) |
| Val12 / isnil21 family | **Reject** — 6 dwords @+0x10; isnil@+0x29 |
| `StdTree_NodeCtor_Val24_Isnil29_EaxThis_Inferred` | **Accept** — family-aligned; ABI tag honest; `_Inferred` |

---

## 2. Attacks on A's CF claims

| Attack | Result |
|---|---|
| thiscall ECX=this | **Fails** — ECX is value*; this is EAX |
| void body / no stores | **Fails** — full L/P/R/Val24/color/isnil map |
| Writes +0x0C | **Fails** — gap between links and value |
| isnil set from color arg | **Fails** — hard isnil=0 @+0x29 |
| Allocates 0x30 | **Fails** — caller allocates; this is leaf |
| Product English proven | **Fails** — open; keep `_Inferred` |

---

## 3. Agreement with Review A

- Store map + ABI + sole caller: **agree Confirmed/High**
- Name with `_Inferred` + EaxThis tag: **agree**
- Gaps (PDB, parent dual residual, runtime): **agree open**

---

## 4. Residual risks

- Do not merge with thiscall twin `004098d0` or inlined buynode `005a2de0`.
- Parent buynode `FUN_00404180` remains undualed residual (not OWN).

**Verdict:** **accept-with-gaps**
