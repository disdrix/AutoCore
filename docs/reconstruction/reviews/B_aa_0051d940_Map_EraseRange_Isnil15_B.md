# Review B (skeptical / independent): `aa_0051d940` Map_EraseRange_Isnil15_B

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051d940` |
| **VA** | `0x0051d940` |
| **Canonical name** | `Map_EraseRange_Isnil15_B` |
| **Review date** | `2026-08-04` (WQ9F-J OWN dual B) |
| **Reviewer role** | Skeptical naming / anti-overclaim |
| **Counterpart** | `reviews/A_aa_0051d940_Map_EraseRange_Isnil15_B.md` |
| **System** | STL / map-set |
| **Verdict** | **accept-with-gaps** — agree with A |

---

## 1. Adversarial read of proposed names

| Candidate | Ruling |
|---|---|
| `FUN_0051d940` only | Scaffold; under-describes sealed role |
| Collapse into `Map_EraseRange_Isnil15` | **Reject** — free-subtree VA differs (`bed0` vs `be50`); separate instantiation |
| `Map_EraseRange` / `Map_EraseRange_B` | **Reject** — those are **isnil@+0x29** |
| `Map_EraseRange_Isnil1d_Inferred` | **Reject** — different isnil family (`+0x1d` @ `0x0051d700`) |
| `StdMap_EraseRange_Inferred` | **Reject as identity** — reserved `0x004bacf0` |
| Skill-domain / cast-map product name | **Reject** — dtor-only xref; no skill string |
| `Map_EraseRange_Isnil15_B` | **Accept** — twin + free discriminator; matches `_B` series bar |

---

## 2. Attacks on A's CF claims

| Attack | Result |
|---|---|
| Function is dead / unused | **Fails** — dtor `FUN_0051e1b0` calls it for full clear |
| Different isnil than twin | **Fails** — both `+0x15` immediates |
| Partial path uses different erase-node | **Fails** — both call `FUN_0051ce00` |
| Free helpers identical code → same symbol | **Open residual** — decomp shapes match; still separate VAs; keep `_B` |
| Same as isnil@+0x29 range erase | **Fails** — isnil offset and free/erase callees differ |
| `ret 8` single-iterator erase | **Fails** — both exits `ret 0x0c` |

---

## 3. Agreement with Review A

- Twin CF + free discriminator: **agree Confirmed**  
- Name split required: **agree**  
- Gaps (K/V, free dual, host English, runtime): **agree open**

---

## 4. Residual risks

- Parent merge must not alias `Map_EraseRange_Isnil15` and `_B` without free-callee note.  
- Do not claim skill-cast semantics from WQ-009 membership alone — helper is generic STL.  
- Shared erase-node `FUN_0051ce00` does **not** prove identical value types with twin free path.

**Verdict:** **accept-with-gaps**
