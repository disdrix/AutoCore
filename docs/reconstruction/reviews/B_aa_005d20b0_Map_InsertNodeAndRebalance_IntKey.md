# Review B (skeptical / adversarial): `aa_005d20b0` Map_InsertNodeAndRebalance_IntKey

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d20b0` |
| **VA** | `0x005d20b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_005d20b0_Map_InsertNodeAndRebalance_IntKey.md` |
| **Evidence** | Live decompile + string throw + node ctor + sole caller `005d2360` dual |
| **Agent** | W17-Q OWN-ONLY |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | This is insert-or-find (handles equals) | No compare walk; always allocs; only links + rebalances | **Falsified conflation with `005d2360`** |
| 2 | Hash map / unordered | RB parent color loop + rotations | **Falsified** |
| 3 | Silent overflow | Throws `"map/set<T> too long"` | **Falsified silent** |
| 4 | Node is 0x30 / 0x50 (other families) | `operator_new(0x18)` in `006173a0` | **Falsified other family** |
| 5 | Color/isnil at `+0x28`/`+0x29` (GhostNet family) | Ctor writes **`+0x14`/`+0x15`** | **Falsified other family** |
| 6 | Multiple independent callers | Only `Map_InsertOrFind_IntKey` (2 sites) | **Confirmed sole** |
| 7 | `param_3` is unused | Selects left vs right child link | **Falsified** |
| 8 | Same size cap as `005a3310` (`0x0AAAAAA8`) | Body uses **`0x1FFFFFFE`** compare | **Falsified shared cap** |
| 9 | Safe to call without prior walk | Parent/side must match tree position from front | **Falsified standalone misuse** |
| 10 | Clean dropped exception path | Plate keeps throw + string | **Falsified drop** |
| 11 | This is erase / rebalance-only | Always `FUN_006173a0` + size++ | **Falsified erase** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Insert+RB role | **Confirmed** | Tree corruption |
| Size throw string | **Confirmed** | Missing length_error |
| Color `+0x14` / nil `+0x15` | **Confirmed** | Infinite walk elsewhere |
| Split vs `005d2360` | **Confirmed** | Wrong dual ownership |
| Node 0x18 / int pair payload | **Confirmed** | Wrong heap size |
| Size threshold family-specific | **Confirmed** | Wrong cap if ported from other map |
| Product English name | **Open** | Doc-only |
| Runtime | **Open** | — |

---

## 3. Cross-check vs front

`005d2360` owns **int-key order + equal detection + inserted bool** (and does **not** rewrite mapped on equal). This unit owns **node link + RB + size**. Predecessor step `FUN_005a2850` stays on the front. Domain consumer `NPC_TryCastSkillFromSet` only sees the front.

Sibling family contrast (do **not** merge layouts):

| Family | Insert core | Node | Color | Nil | Size cap (compare imm) |
|---|---|---|---|---|---|
| IntKey (this) | `0x005d20b0` | 0x18 | +0x14 | +0x15 | 0x1FFFFFFE |
| GhostNet pair | `0x005a3310` | 0x30 | +0x28 | +0x29 | 0x0AAAAAA9 |
| Mission staging | `0x00538ea0` | 0x50 | +0x48 | +0x49 | 0x4924923 |

---

## 4. Byte anchors

```text
0x005d20b0: … 8B F9                  ; edi = map this
            81 7F 08 FE FF FF 1F    ; cmp [edi+8], 0x1FFFFFFE
            72 59                   ; jb past_throw
            … "map/set<T> too long" @ 0x00a1530c …
… size++:   BB 01 00 00 00  01 5F 08
… color:    80 7A 14 00             ; cmp byte [edx+0x14],0
… epilogue: 83 C4 50  C2 10 00      ; add esp,0x50; ret 0x10
```

Node ctor `0x006173a0`: `push 0x18` / copy `param_4[0]`→`+0x0C`, `[1]`→`+0x10` / color `+0x14` / isnil `+0x15=0`.

---

## 5. What would reverse the seal?

- Second static caller inserting via this VA with a different node family.
- Live size compare imm not `0x1FFFFFFE`.
- Node ctor no longer `new(0x18)` / color not `+0x14`.

None observed on current static image.

---

## 6. Open questions

1. Rotate helper product names.  
2. Other map hosts reusing this helper after reanalysis.  
3. Runtime overflow path.

**Verdict:** **accept-with-gaps** — adversarial pass keeps int-key map insert core sealed; front retains walk/equal; product name residual only.
