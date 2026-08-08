# Review B (skeptical / independent): `aa_0051be50` Map_FreeSubtree_Isnil15

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051be50` |
| **VA** | `0x0051be50` |
| **Canonical name** | `Map_FreeSubtree_Isnil15` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Skeptical naming / anti-overclaim |
| **Counterpart** | `reviews/A_aa_0051be50_Map_FreeSubtree_Isnil15.md` |
| **System** | STL / map-set |
| **Verdict** | **accept-with-gaps** — agree with A |

---

## 1. Adversarial read of proposed names

| Candidate | Ruling |
|---|---|
| `FUN_0051be50` only | Scaffold; under-describes |
| Collapse into `StdMap_FreeSubtree_Isnil15_Inferred` | **Reject** — different VA/callers; skill-neighborhood free of Map_EraseRange_Isnil15 |
| `Map_FreeSubtree_Isnil29` / `Map_FreeSubtree_B` | **Reject as sole ID** — different isnil immediates / callers |
| Skill-cast product name | **Reject** — no skill string; map-host free helper only |
| `Map_FreeSubtree_Isnil15` | **Accept** — free discriminator of sealed Map_EraseRange_Isnil15 |

---

## 2. Attacks on A's CF claims

| Attack | Result |
|---|---|
| Function only frees right child (decomp) | **Fails** — bytes show left load + loop; classic MSVC free |
| Dead / unused | **Fails** — Map_EraseRange_Isnil15 full clear calls it |
| isnil not +0x15 | **Fails** — immediate `0x15` |
| This is erase-range not free | **Fails** — no map this; only node* + delete |
| Same symbol as isnil1d free `0051be10` | **Fails** — isnil immediate differs (`+0x1d` vs `+0x15`) |

---

## 3. Agreement with Review A

- Byte-correct free algebra: **agree Confirmed**
- Name pairs with Map_EraseRange_Isnil15: **agree**
- Gaps: **agree open**

---

## 4. Residual risks

- Parent merge must keep `0051be50` distinct from `004ba770` / `0051bbc0` / `0051be90` / `0051be10`.
- Do not trust decompiler alone for left-walk — always prefer bytes for free-subtree family.

**Verdict:** **accept-with-gaps**
