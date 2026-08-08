# Review B (skeptical / independent): `aa_00406c40` StdTree_InsertAndRebalance_Isnil29_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00406c40` |
| **VA** | `0x00406c40` |
| **Canonical name** | `StdTree_InsertAndRebalance_Isnil29_Inferred` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Skeptical naming / anti-overclaim |
| **Counterpart** | `reviews/A_aa_00406c40_StdTree_InsertAndRebalance_Isnil29_Inferred.md` |
| **System** | STL / map-set |
| **Verdict** | **accept-with-gaps** — agree with A |

---

## 1. Adversarial read of proposed names

| Candidate | Ruling |
|---|---|
| `FUN_00406c40` only | Acceptable scaffold; under-describes sealed role |
| `Named_CalleeOf_*VOGClient_00406c40` | **Reject** — chain-of-caller; shared STL helper |
| `Skill_InsertBindingNode` | **Reject** — no skill-domain string; single parent is generic int-key map |
| `StdMap_StringKey_InsertNodeAndRebalance` | **Reject** — wrong node layout (isnil@+0x2D) |
| `StdTree_InsertAndRebalance_Val8_Isnil15_*` | **Reject** — wrong isnil offset family |
| `StdTree_InsertAndRebalance_Isnil29_Inferred` | **Accept** — family-aligned; `_Inferred` honest |

---

## 2. Attacks on A's CF claims

| Attack | Result |
|---|---|
| Function is insert-or-find (compares keys) | **Fails** — no key compare; parent `00406040` compares `node[4]` |
| Map lives in EDI not ECX (StringKey hazard) | **Fails** — entry `mov edi,ecx`; thiscall sealed |
| isnil@+0x19 Val12 family | **Fails** — color/isnil immediates 0x28/0x29; rotates are isnil29 duals |
| Max size same as Val8 (`0x1ffffffd`) | **Fails** — imm `0x0AAAAAA9` matches 0x18 value stride |
| Lrotate/Rrotate args omit map | **Fails** — bytes pass ECX=map (`8B CF` / `8B CE` style) |
| Product English proven | **Fails** — open; keep `_Inferred` |

---

## 3. Agreement with Review A

- Always-insert + RB + ABI + family layout: **agree Confirmed/High**
- Name with `_Inferred`: **agree**
- Gaps (PDB, payload English, runtime): **agree open**

---

## 4. Residual risks

- Do not merge with string-key or isnil15 insert clones without layout check.
- Buynode `FUN_00407e30` / ctor `FUN_004098d0` remain undualed OWN residuals.
- Parent `FUN_00406040` undualed — insert-or-find wrapper residual.

**Verdict:** **accept-with-gaps**
