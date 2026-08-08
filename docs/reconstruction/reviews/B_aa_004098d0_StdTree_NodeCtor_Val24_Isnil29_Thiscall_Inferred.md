# Review B (skeptical / independent): `aa_004098d0` StdTree_NodeCtor_Val24_Isnil29_Thiscall_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004098d0` |
| **VA** | `0x004098d0` |
| **Canonical name** | `StdTree_NodeCtor_Val24_Isnil29_Thiscall_Inferred` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Skeptical naming / anti-overclaim |
| **Counterpart** | `reviews/A_aa_004098d0_StdTree_NodeCtor_Val24_Isnil29_Thiscall_Inferred.md` |
| **System** | STL / map-set node construct |
| **Verdict** | **accept-with-gaps** — agree with A |

---

## 1. Adversarial read of proposed names

| Candidate | Ruling |
|---|---|
| `FUN_004098d0` only | Scaffold OK; under-describes sealed role |
| `Named_CalleeOf_*` chain scaffold | **Reject** — shared STL helper |
| CNDHash / freelist node init | **Reject** — pure field stores; no freelist |
| `StdTree_Buynode_*` (allocating) | **Reject** — construct-only; buy is `00407e30` |
| Merge with `FUN_00409880` as same symbol | **Reject** — distinct ABI |
| Merge with inlined `005a2de0` body | **Reject** — distinct VA; that unit inlines stores |
| Val12 / isnil21 family | **Reject** — Val24 / isnil@+0x29 |
| `StdTree_NodeCtor_Val24_Isnil29_Thiscall_Inferred` | **Accept** — family-aligned; ABI tag honest; `_Inferred` |

---

## 2. Attacks on A's CF claims

| Attack | Result |
|---|---|
| EAX-this not thiscall | **Fails** — entry `MOV EAX,ECX`; 5 stack args; RET 0x14 |
| Allocates inside unit | **Fails** — leaf stores only |
| Value is 1 dword key | **Fails** — six dword copies |
| isnil copied from color | **Fails** — hard 0 store |
| Same as empty head ctor | **Fails** — takes links/value/color args |
| Product English proven | **Fails** — open; keep `_Inferred` |

---

## 3. Agreement with Review A

- Store map + thiscall ABI + sole buynode caller: **agree Confirmed/High**
- Name with `_Inferred` + Thiscall tag: **agree**
- Gaps (PDB, runtime): **agree open**

---

## 4. Residual risks

- Do not merge with EAX twin `00409880` or no-SEH inlined buynode `005a2de0`.
- Value_type product English remains open across Val24 isnil29 family.

**Verdict:** **accept-with-gaps**
