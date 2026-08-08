# Review B (skeptical / independent): `aa_0051bed0` Map_FreeSubtree_Isnil15_B

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051bed0` |
| **VA** | `0x0051bed0` |
| **Canonical name** | `Map_FreeSubtree_Isnil15_B` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Skeptical naming / anti-overclaim |
| **Counterpart** | `reviews/A_aa_0051bed0_Map_FreeSubtree_Isnil15_B.md` |
| **System** | STL / map-set |
| **Verdict** | **accept-with-gaps** — agree with A |

---

## 1. Adversarial read of proposed names

| Candidate | Ruling |
|---|---|
| `FUN_0051bed0` only | Scaffold; under-describes |
| Collapse into `Map_FreeSubtree_Isnil15` | **Reject** — different VA/callers; free of Map_EraseRange_Isnil15_B |
| Collapse into `StdMap_FreeSubtree_Isnil15_Inferred` | **Reject** — different VA/callers |
| `Map_FreeSubtree_Isnil29` / `Map_FreeSubtree_B` | **Reject as sole ID** — different isnil immediates / callers |
| Skill-cast product name | **Reject** — no skill string; map-host free helper only |
| `Map_FreeSubtree_Isnil15_B` | **Accept** — free discriminator of sealed Map_EraseRange_Isnil15_B |

---

## 2. Attacks on A's CF claims

| Attack | Result |
|---|---|
| Function only frees right child (decomp) | **Fails** — bytes show left load + loop; classic MSVC free |
| Dead / unused | **Fails** — Map_EraseRange_Isnil15_B full clear calls it |
| isnil not +0x15 | **Fails** — immediate `0x15` |
| This is erase-range not free | **Fails** — no map this; only node* + delete |
| Same symbol as twin free `0051be50` | **Fails** — distinct VA; external callers differ |

---

## 3. Agreement with Review A

- Byte-correct free algebra: **agree Confirmed**
- Name pairs with Map_EraseRange_Isnil15_B: **agree**
- Gaps: **agree open**

---

## 4. Residual risks

- Parent merge must keep `0051bed0` distinct from `0051be50` / `004ba770` / `0051bbc0` / `0051be90` / `0051be10`.
- Do not trust decompiler alone for left-walk — always prefer bytes for free-subtree family.

**Verdict:** **accept-with-gaps**
