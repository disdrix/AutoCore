# Review B (skeptical / independent): `aa_00407e30` StdTree_Buynode_Val24_Isnil29_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00407e30` |
| **VA** | `0x00407e30` |
| **Canonical name** | `StdTree_Buynode_Val24_Isnil29_Inferred` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Skeptical naming / anti-overclaim |
| **Counterpart** | `reviews/A_aa_00407e30_StdTree_Buynode_Val24_Isnil29_Inferred.md` |
| **System** | STL / map-set buynode |
| **Verdict** | **accept-with-gaps** — agree with A |

---

## 1. Adversarial read of proposed names

| Candidate | Ruling |
|---|---|
| `FUN_00407e30` only | Scaffold OK; under-describes sealed role |
| `Named_CalleeOf_*VOGClient_*` | **Reject** — chain-of-caller; shared STL helper |
| `StdTree_Buynode_Val12` | **Reject** — wrong size (0x30≠0x1c), isnil@+0x29≠+0x19 |
| `StdTree_Buynode_Val12_EsiValue` | **Reject** — ESI ABI + Val12 |
| Merge with `FUN_005a2de0` as same symbol | **Reject** — distinct VA; SEH vs inlined |
| Placement-new freelist buy | **Reject** — CRT `operator_new(0x30)` |
| `StdTree_Buynode_Val24_Isnil29_Inferred` | **Accept** — family-aligned; `_Inferred` honest |

---

## 2. Attacks on A's CF claims

| Attack | Result |
|---|---|
| thiscall ECX=map | **Fails** — pure stack; RET 0x14 |
| void return / no pointer | **Fails** — `MOV EAX,ESI` before ret |
| Value is 1 dword key only | **Fails** — ctor copies 6 dwords |
| isnil set from color arg | **Fails** — hard isnil=0 @+0x29 |
| Same body as insert | **Fails** — tiny alloc helper only |
| Product English proven | **Fails** — open; keep `_Inferred` |

---

## 3. Agreement with Review A

- Alloc/construct CF + ABI + layout: **agree Confirmed/High**
- Name with `_Inferred`: **agree**
- Gaps (PDB, ctor dual residual, runtime): **agree open**

---

## 4. Residual risks

- Do not merge with Val12 buynodes (`005ae220` / `0046c6c0`) or no-SEH twin `005a2de0` without layout/ABI check.
- Ctor `FUN_004098d0` undualed residual (not OWN).

**Verdict:** **accept-with-gaps**
