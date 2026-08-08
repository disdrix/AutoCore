# Review B (skeptical / independent): `aa_0051be90` Map_FreeSubtree_B

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051be90` |
| **VA** | `0x0051be90` |
| **Canonical name** | `Map_FreeSubtree_B` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Skeptical naming / anti-overclaim |
| **Counterpart** | `reviews/A_aa_0051be90_Map_FreeSubtree_B.md` |
| **System** | STL / map-set |
| **Verdict** | **accept-with-gaps** — agree with A |

---

## 1. Adversarial read of proposed names

| Candidate | Ruling |
|---|---|
| `FUN_0051be90` only | Scaffold; under-describes |
| Collapse into `MapFloatTfid_FreeSubtree_Isnil29_Inferred` | **Reject** — different VA/caller; MapFloatTfid is gather-distance map |
| `Map_FreeSubtree` shared with `0051bbc0` | **Reject as sole ID** — two free VAs need distinct names |
| Skill-cast product name | **Reject** — no skill string; map-host free helper only |
| `Map_FreeSubtree_B` | **Accept** — free discriminator of sealed Map_EraseRange_B |

---

## 2. Attacks on A's CF claims

| Attack | Result |
|---|---|
| Function only frees right child (decomp) | **Fails** — bytes show left load + loop; classic MSVC free |
| Dead / unused | **Fails** — Map_EraseRange_B full clear calls it |
| isnil not +0x29 | **Fails** — immediate `0x29` |
| This is erase-range not free | **Fails** — no map this; only node* + delete |

---

## 3. Agreement with Review A

- Byte-correct free algebra: **agree Confirmed**
- Name pairs with Map_EraseRange_B: **agree**
- Gaps: **agree open**

---

## 4. Residual risks

- Parent merge must keep `0051be90` and `0051bbc0` as separate free symbols.
- Do not trust decompiler alone for left-walk — always prefer bytes for free-subtree family.

**Verdict:** **accept-with-gaps**
