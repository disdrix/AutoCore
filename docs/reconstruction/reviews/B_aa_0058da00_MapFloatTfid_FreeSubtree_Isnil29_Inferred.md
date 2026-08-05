# Review B (skeptical / adversarial): `aa_0058da00` MapFloatTfid_FreeSubtree_Isnil29_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0058da00` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W24-T) |
| **Counterpart** | `reviews/A_aa_0058da00_MapFloatTfid_FreeSubtree_Isnil29_Inferred.md` |
| **Scratch** | `tmp/a_0058da00.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Raw decompiler CF is complete | **Falsified** — decompile shows only right-recurse + delete; bytes loop on left (`8B 36` / `74 E2`) |
| 2 | isnil is +0x15 like twin | **Falsified** — this family uses **`+0x29`** (`80 7F 29 00`) |
| 3 | This is list free / single delete | **Falsified** — recursive right + left walk is map subtree free; parent is erase-range full clear |
| 4 | ECX is used as tree root | **Overstated** — ECX threaded to recursive call but never loaded for fields; stack node is authority |
| 5 | Multiple external callers | **Falsified** — external xrefs: only `FUN_0058df60` (+ self) |
| 6 | Chain-name PollBound alias is product | **Falsified** — transitive callee chain only; true domain is MapFloatTfid teardown |
| 7 | Value dtor runs here | **Open** — no dtor call in body; may be POD pair or pre-destroyed |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Byte CF right-recurse + left walk | **High** | Leak / double-free |
| isnil +0x29 | **High** | Free sentinel / hang |
| Sole external caller erase-range | **High** | Missed teardown site |
| Twin pattern isnil15 | **High** | Naming only |
| Product STL English | **Medium** | Naming |
| Value lifetime | **Medium** | Leak / UAF if non-POD |
| Runtime | **Open** | Matrix |

---

## 3. Cross-check against raw + bytes

```
node = stack
if isnil(+0x29): return
loop:
  FreeSubtree(node->right)   // +8
  left = node->left          // +0
  operator_delete(node)
  node = left
  if isnil: break
RET 4
```

Raw decompile must be treated as **incomplete**. Clean plate restores left-walk from `read_memory`. Same residual class as `StdMap_FreeSubtree_Isnil15_Inferred`.

---

## 4. Surviving contract for AutoCore

```
// MapFloatTfid full-clear helper (not public API)
// FreeSubtree(root): right-first recurse, delete, walk left until isnil@+0x29
// call only from erase-range full clear after detaching head self-links
// node layout: left0 parent4 right8 ... isnil29
// do not use isnil15 offsets from the other map family
```

---

## 5. Verdict

Adversarial pass **confirms** A: byte CF/ABI/isnil sealed; decompiler residual documented; naming inferred from parent family → **accept**.
