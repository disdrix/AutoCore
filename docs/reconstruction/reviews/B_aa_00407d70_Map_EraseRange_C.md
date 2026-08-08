# Review B (skeptical / adversarial): `aa_00407d70` Map_EraseRange_C

| Field | Value |
|---|---|
| **Stable ID** | `aa_00407d70` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (OWN-ONLY WQ9H-F) |
| **Counterpart** | `reviews/A_aa_00407d70_Map_EraseRange_C.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is free-subtree only | **Falsified as sole role** — free path is full-range gate; partial walks erase-node |
| 2 | This is single-node erase | **Falsified** — range loop + full-clear branch |
| 3 | isnil@+0x15 / +0x1d family | **Falsified** — immediates **`0x29`** only |
| 4 | Same free callee as Map_EraseRange (`0051bbc0`) | **Falsified as identity** — this free is dualed `00406c00`; peer A uses `0051bbc0` (same role, different clone) |
| 5 | Same erase as Map_EraseNode (`0051cb40`) | **Falsified as identity** — erase is dualed `Map_EraseNode_B` (`00409220`) |
| 6 | RET 8 like erase-node | **Falsified** — **`RET 0x0c`** (3 stack args) |
| 7 | Skill cast SM logic | **Reject** — generic STL helper; multi-caller map tidy |
| 8 | Scaffold Named_CalleeOf chain | **Reject** — multi-caller generic |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Range-erase CF shape | **High** | Wrong clear vs partial |
| ABI thiscall + RET 0x0c | **High** | Stack corruption |
| isnil@+0x29 family | **High** | Wrong node layout |
| Free = 00406c00 / erase = Map_EraseNode_B | **High** | Wrong port wiring |
| Product type English | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against free + erase duals

```
// WQ9G free-subtree 00406c00: right-first free while isnil@+0x29 == 0
// WQ9E-G Map_EraseNode_B 00409220: single erase RET 8
// This OWN unit is the range parent that was residual in both duals.
```

---

## 4. Surviving contract for AutoCore

```
// Port as isnil29 range erase (third clone):
//  - full [begin,end) → FreeSubtree(root) + head reset + size 0
//  - partial → successor + Map_EraseNode_B
//  - ABI: thiscall + ret 0x0c
// Do not merge free callee with 0051bbc0 or erase with 0051cb40 without clone awareness.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/family. Product residual → **accept-with-gaps**.