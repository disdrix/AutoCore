# Review B (skeptical / independent): `aa_004c8610` Object_AggroMap_DecayOrPurge_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c8610` |
| **VA** | `0x004c8610` |
| **Canonical name** | `Object_AggroMap_DecayOrPurge_Inferred` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Skeptical naming / anti-overclaim |
| **Counterpart** | `reviews/A_aa_004c8610_Object_AggroMap_DecayOrPurge_Inferred.md` |
| **System** | object aggro / threat map |
| **Verdict** | **accept-with-gaps** — agree with A |

---

## 1. Adversarial read of proposed names

| Candidate | Ruling |
|---|---|
| `FUN_004c8610` only | Scaffold; under-describes sealed role |
| `StdTree_EraseAndRebalance_*` | **Reject** — this is a **caller**, not the erase worker |
| `Map_EraseRange` / free-subtree | **Reject** — per-node score decay + selective erase |
| `Skill_*` product cast name | **Reject** — no skill strings; map is host+0x158 |
| `GetTargetFromAggro` | **Reject** — different VA `00638ec0`; different container |
| `Object_AggroMap_DecayOrPurge_Inferred` | **Accept** — role High from peer TFID + decay; English `_Inferred` |

---

## 2. Attacks on A's CF claims

| Attack | Result |
|---|---|
| Always erases every node | **Fails** — keep branch when forcePurge==0 && score changed |
| Never erases when forcePurge==0 | **Fails** — zero residual falls to erase |
| Decay factor is 0.5 or integer half | **Fails** — float 0.85f constant sealed |
| Map at +0x158 is the shell base | **Fails** — erase LEA uses +0x154; +0x158 is head |
| Val12 isnil@+0x19 family | **Fails** — CMP [node+0x29]; erase dual is isnil29 |
| Product English proven | **Fails** — open; keep `_Inferred` |

---

## 3. Agreement with Review A

- Decay / keep / purge CF + ABI + erase callee: **agree Confirmed/High**
- Aggro-map naming with `_Inferred`: **agree**
- Gaps (PDB, forcePurge callers, runtime): **agree open**

---

## 4. Residual risks

- Do not merge with `GetTargetFromAggro` temporary list path.
- Peer purge/resolve `004c8780` and clear-target vtbl English remain residuals.
- forcePurge!=0 may be dead in this image — still part of sealed CF.

**Verdict:** **accept-with-gaps**
