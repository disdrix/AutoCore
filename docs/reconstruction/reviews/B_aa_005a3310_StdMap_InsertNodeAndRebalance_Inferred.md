# Review B (skeptical / adversarial): `aa_005a3310` StdMap_InsertNodeAndRebalance_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005a3310` |
| **VA** | `0x005a3310` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_005a3310_StdMap_InsertNodeAndRebalance_Inferred.md` |
| **Evidence** | Live decompile + string throw + node ctor + sole caller `005a3b00` dual |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | This is insert-or-find (handles equals) | No compare walk; assumes missing key; only links + rebalances | **Falsified conflation with `005a3b00`** |
| 2 | Hash map / unordered | RB parent color loop + rotations | **Falsified** |
| 3 | Silent overflow | Throws `"map/set<T> too long"` | **Falsified silent** |
| 4 | Node is 16 bytes | `operator_new(0x30)` | **Falsified** |
| 5 | Nil flag at `+0x1d` (other families) | Ctor writes **`+0x29`** | **Falsified other family** |
| 6 | Multiple independent callers | Only `005a3b00` | **Confirmed sole** |
| 7 | `param_3` is unused | Selects left vs right child link | **Falsified** |
| 8 | Clean dropped exception path | Scaffold keeps throw | **Falsified** |
| 9 | Safe to call without prior walk | Parent/side must match tree position from front | **Falsified standalone misuse** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Insert+RB role | **Confirmed** | Tree corruption |
| Size throw string | **Confirmed** | Missing length_error |
| Color `+0x28` / nil `+0x29` | **Confirmed** | Infinite walk elsewhere |
| Split vs `005a3b00` | **Confirmed** | Wrong dual ownership |
| Payload English | **Medium** | GhostNet value layout |
| Runtime | **Open** | — |

---

## 3. Surviving contract for AutoCore

```
// map thiscall; ret 0x10
if (map.size > 0x0AAAAAA8) throw length_error("map/set<T> too long");
node = AllocNode_0x30(header, parent, keyPayload6, color=0, nil=0);
map.size++;
link node as left/right child of parent (update header extremes);
RB_rebalance_up(node);   // recolor + rotate until root black
*out = node;
// NOT key compare; NOT erase; requires correct parent/side from walk
```

Port rule: keep as private insert core under insert-or-find front; do not expose without walk.

---

## 4. Cross-check vs front

`005a3b00` owns **pair-key order + equal detection + inserted bool**. This unit owns **node link + RB + size**. Predecessor step `004cb4f0` stays on the front. GhostNet `005a0b30` only sees the front.

---

## 5. Open questions

1. Six-dword payload field map beyond lo/hi key.
2. Whether any other map host reuses this insert helper after reanalysis.
3. Runtime overflow path (unlikely in production sizes).

**Verdict:** **accept-with-gaps** — adversarial pass keeps map/set insert core sealed; payload residual only.
