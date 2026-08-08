# Review B (skeptical / adversarial): `aa_00407f90` StdMap_EraseRange_Isnil2d_DestroyStr0C_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00407f90` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY WQ9K-B) |
| **Counterpart** | `reviews/A_aa_00407f90_StdMap_EraseRange_Isnil2d_DestroyStr0C_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is free-subtree only | **Falsified as sole role** — free path is full-range gate; partial walks erase-node |
| 2 | This is single-node erase | **Falsified** — range loop + full-clear branch |
| 3 | isnil@+0x131 / +0x29 / +0x15 family | **Falsified** — body immediates **`0x2d`** only |
| 4 | Standard ECX `__thiscall` | **Falsified** — **EDI = map**; free still takes ECX=map |
| 5 | Same free as isnil131 / isnil29 | **Falsified as identity** — free is dualed `00409970` only |
| 6 | Same erase as isnil29 `Map_EraseNode_B` | **Falsified** — erase is dualed StringKey `004094c0` |
| 7 | RET 4 / RET 8 | **Falsified** — **`RET 0x0c`** |
| 8 | Merge with `00407b70` | **Reject** — different isnil family / free / partial erase |
| 9 | Scaffold Named_CalleeOf chain as product name | **Reject** — multi-caller generic STL |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Range-erase CF shape | **High** | Wrong clear vs partial |
| ABI EDI-this + RET 0x0c | **High** | Stack/register corruption |
| isnil@+0x2d family | **High** | Wrong node layout |
| Free = 00409970 / erase = 004094c0 | **High** | Wrong port wiring |
| Product type English | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against free + erase duals

```
// WQ9J-I free 00409970: isnil@+0x2d + DestroyStr0C; external full-clear caller is this unit.
// WQ9J-F StringKey erase 004094c0: isnil@+0x2d, color@+0x2c, string@+0x0c; sole caller was this unit.
// Do not wire free to 00409920 / 00406c00 or erase to Map_EraseNode_B 00409220 without clone awareness.
```

---

## 4. Surviving contract for AutoCore

```
// Port as isnil2d string-key range erase:
//  - full [begin,end) → FreeSubtree_Isnil2d(root) + head reset + size 0
//  - partial → inlined successor isnil@+0x2d + StringKey_EraseAndRebalance 004094c0
//  - ABI: EDI = map*, 3 stack args, ret 0x0c
// Do not merge with isnil131 peer 00407b70 or isnil29 Map_EraseRange_C.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/family. Product residual → **accept-with-gaps**.
