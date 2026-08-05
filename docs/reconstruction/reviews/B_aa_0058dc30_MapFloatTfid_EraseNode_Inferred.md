# Review B (skeptical / adversarial): `aa_0058dc30` MapFloatTfid_EraseNode_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0058dc30` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0058dc30_MapFloatTfid_EraseNode_Inferred.md` |
| **Agent** | W25-A OWN-ONLY |
| **Verdict** | **accept** on erase identity + epilogue; **needs-more-evidence** only on PDB K/V English |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Function ends at `operator_delete` (noreturn) | Bytes show size-- + `ret 8` after delete | **Falsified** |
| 2 | isnil at `+0x15` like 004baa30 | Prologue `cmp byte [eax+0x29]` | **Falsified** |
| 3 | List/vector erase | Throw string + RB rotates + head sentinel | **Falsified** |
| 4 | Multiple external callers | Single CODE xref `0058df60` | **Falsified** multi |
| 5 | Client input poll product role | Scaffold name only; gather map family | **Falsified** |
| 6 | No size field | `[ebp+8]` dec when >0 | **Falsified** |
| 7 | `ret 4` | `C2 08 00` | **Falsified** |
| 8 | FreeSubtree alias | Different body; range calls this per node | **Falsified** |
| 9 | Color at dword[5]/`+0x14` | Color uses `+0x28` / `param_3[10]` | **Falsified** small-node layout |
| 10 | Invented float/TFID payload | Payload not read by erase; family name from siblings | **Survives refined** — structural family, not payload proof in this VA |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| MSVC erase CF | **High** | Tree corruption if ported wrong |
| isnil/color offsets | **High** | Wrong node layout |
| size-- / ret 8 | **High** | ABI / leak of size |
| Sole EraseRange caller | **High** | Missed alternate erase paths |
| K/V product types | **Tentative** | Docs only |

---

## 3. Cross-check

```
if node.isnil(+0x29): throw "invalid map/set<T> iterator"
unlink node; fix head begin/rbegin
if node.color(+0x28)==black: rebalance (rotates 004192a0/004192f0)
operator_delete(node)
if tree.size>0: tree.size--
*out_it = successor; ret 8
```

Image: string @ `00a152f0`, prologue isnil, epilogue `ret 8`. Parent dual `MapFloatTfid_EraseRange` loops this.

Clean must **not** claim decompiler end is true end. **Must** include size--.

---

## 4. Surviving contract

```
// MapFloatTfid single erase (MSVC _Tree)
void EraseNode(Tree* t, Iterator* out, Node* n):
  if n->isnil: throw invalid_map_set_iterator
  splice_unlink(t, n)
  if n->color == black: rb_fixup(t, replacement)
  delete n
  if t->size > 0: t->size--
  *out = next_iterator
// ret 8; isnil@+0x29 color@+0x28 head@t+4 size@t+8
```

---

## 5. Open questions

1. PDB symbol / exact value type.
2. Whether any dynamic call sites exist outside EraseRange (none static).

**Verdict:** CF **accept**. PDB English **needs-more-evidence**.
