# Review B (skeptical / adversarial): `aa_00407b70` StdMap_EraseRange_Isnil131_DestroyStr0C_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00407b70` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY WQ9K-B) |
| **Counterpart** | `reviews/A_aa_00407b70_StdMap_EraseRange_Isnil131_DestroyStr0C_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is free-subtree only | **Falsified as sole role** — free path is full-range gate; partial walks erase-node |
| 2 | This is single-node erase | **Falsified** — range loop + full-clear branch |
| 3 | isnil@+0x29 / +0x2d / +0x15 family | **Falsified** — free/succ/erase callees seal **isnil@+0x131** (no isnil imm in body itself) |
| 4 | Standard ECX `__thiscall` | **Falsified** — **ESI = map**; free still takes ECX=map |
| 5 | Same free as isnil2d / isnil29 | **Falsified as identity** — free is dualed `00409920` only |
| 6 | RET 4 / RET 8 | **Falsified** — **`RET 0x0c`** (3 stack args) |
| 7 | Skill/domain logic | **Reject** — generic STL helper; multi-caller map tidy |
| 8 | Merge with `00407f90` | **Reject** — different isnil family / free / partial erase |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Range-erase CF shape | **High** | Wrong clear vs partial |
| ABI ESI-this + RET 0x0c | **High** | Stack/register corruption |
| Free = 00409920 isnil131 | **High** | Wrong port wiring |
| Partial succ/erase residual | **High** | Incomplete port |
| Product type English | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against free dual

```
// WQ9J-I free 00409920: isnil@+0x131 + DestroyStr0C; sole external caller is this unit.
// Partial erase 00408ad0: isnil@+0x131 + ~basic_string@+0x0c (decomp evidence).
// Do not wire free to 00409970 / 00406c00 / 0051bbc0 without clone awareness.
```

---

## 4. Surviving contract for AutoCore

```
// Port as isnil131 string-family range erase:
//  - full [begin,end) → FreeSubtree_Isnil131(root) + head reset + size 0
//  - partial → successor 00404000 + erase 00408ad0
//  - ABI: ESI = map*, 3 stack args, ret 0x0c
// Do not merge with isnil2d peer 00407f90 or isnil29 Map_EraseRange_C.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/family. Product residual → **accept-with-gaps**.
