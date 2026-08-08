# Review B (skeptical / independent): `aa_0051c7c0` Map_EraseRange

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051c7c0` |
| **VA** | `0x0051c7c0` |
| **Canonical name** | `Map_EraseRange` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Skeptical naming / anti-overclaim |
| **Counterpart** | `reviews/A_aa_0051c7c0_Map_EraseRange.md` |
| **System** | STL / map-set |
| **Verdict** | **accept-with-gaps** — agree with A |

---

## 1. Adversarial read of proposed names

| Candidate | Ruling |
|---|---|
| `FUN_0051c7c0` only | Scaffold only; under-describes sealed role |
| `Named_CalleeOf_CVOGHBAIBase_GetTargetFromAggro_0051c7c0` | **Reject** — also map dtor; generic STL |
| `Skill_EraseCastMapRange` | **Reject** — no cast-binding-only evidence; aggro caller |
| `StdMap_EraseRange_Inferred` | **Reject as identity** — that name is isnil@+0x15 family (`0x004bacf0`) |
| `Map_EraseRange` | **Accept** — pairs with `Map_EraseNode`; isnil@+0x29 |

---

## 2. Attacks on A's CF claims

| Attack | Result |
|---|---|
| Only full clear (no partial) | **Fails** — successor loop + Map_EraseNode present |
| List erase not tree | **Fails** — parent climb / right-min successor |
| Same as `0x0051d880` bit-identical | **Fails** — free call target differs (`0051bbc0` vs `0051be90`) |
| Same as isnil@+0x15 EraseRange | **Fails** — gate uses `+0x29` |
| `ret 8` like Map_EraseNode | **Fails** — both exits `ret 0x0c` (3 stack args) |
| Decomp shows Map_EraseNode without this | **Trap only** — bytes `mov ecx, edi` before call |

---

## 3. Agreement with Review A

- STL range-erase role + ABI + dual paths: **agree Confirmed/High**
- Structural name without product English: **agree**
- Gaps (payload types, free-subtree dual, runtime): **agree open**

---

## 4. Residual risks

- Free-subtree `FUN_0051bbc0` not dual-sealed this pass — do not invent value-dtor English.
- Do not merge with `Map_EraseRange_B` without free-callee check.
- Scaffold chain alias must stay rejected in registry merge.

**Verdict:** **accept-with-gaps**
