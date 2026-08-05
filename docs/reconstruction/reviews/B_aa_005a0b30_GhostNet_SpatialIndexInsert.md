# Review B (skeptical / adversarial): `aa_005a0b30` GhostNet_SpatialIndexInsert

| Field | Value |
|---|---|
| **Stable ID** | `aa_005a0b30` |
| **VA** | `0x005a0b30` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_005a0b30_GhostNet_SpatialIndexInsert.md` |
| **Evidence** | Live decompile + callers; callee `FUN_005a3b00` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Result | Why |
|---|---|---|---|
| 1 | Body allocates / frees memory | **Falsified** | Only stack locals + one call |
| 2 | Returns map iterator to caller | **Falsified** | void; out discarded |
| 3 | `param_2` is a full object | **Falsified** | exactly 4 dwords copied |
| 4 | Clean diverges from raw | **Falsified** | ≡ live CF |
| 5 | This is the BST implementation | **Falsified** | thin wrapper; BST is `0x005a3b00` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| 4+1 key pack + single map call | **High** | wrong ghost register path |
| Map host identity | **Low–Medium** | wrong global vs instance |
| Spatial vs TFID key semantics | **Medium** | misname only |
| Runtime | **Open** | — |

---

## 3. Surviving contract

```
GhostNet_SpatialIndexInsert(obj, words4):
  key = { words4[0..3], obj }
  MapInsertOrFind(map?, out, &key)   // FUN_005a3b00
  // out discarded
```

**Verdict:** **accept-with-gaps**
