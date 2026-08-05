# Review A (reconstruction fidelity): `aa_005d1df0` Map_EraseNode_IntKey

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d1df0` |
| **VA** | `0x005d1df0` |
| **Canonical name** | `Map_EraseNode_IntKey` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005d1df0_Map_EraseNode_IntKey.md` |
| **System** | `missions-progression` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

MSVC-style **map node erase** for int-key maps. `__thiscall(this, pMap, pOutIt, pNode)` rebalances/unlinks node; uses string locals (allocator/debug paths) and many Ghidra unreachable blocks. Counterpart to lower_bound helpers used by XP/loot maps. ~327 lines.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005d1df0_*.md` |
| Annotated | `docs/reconstruction/raw/aa_005d1df0_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Map_EraseNode_IntKey.cpp` |
| Function record | `docs/reconstruction/functions/aa_005d1df0_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Map erase / unlink node | High | Name + signature |
| Int-key map family | High | Domain |
| Complex RB rebalance residual | Medium | Unreachable noise |
| Exact iterator invalidation contract | Medium | STL residual |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| erase node → rebalance → out iterator | Yes |

---

## 5. Gaps / open

1. Seal against MSVC map erase for XP map clear paths.
2. Find call sites (table reload / teardown).

**Verdict:** **accept-with-gaps**
