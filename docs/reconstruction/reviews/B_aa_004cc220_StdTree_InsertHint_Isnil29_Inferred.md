# Review B (skeptical / adversarial): `aa_004cc220` StdTree_InsertHint_Isnil29_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cc220` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (OWN-ONLY WQ9F-E) |
| **Counterpart** | `reviews/A_aa_004cc220_StdTree_InsertHint_Isnil29_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is always-insert (`FUN_004cbb60`) | **Falsified as sole role** — 7 always-insert sites are *conditional* fast paths; equal/invalid hint falls through to `FUN_004cbee0` |
| 2 | This is insert-or-find only | **Falsified** — empty/begin/end/neighbor paths skip full walk |
| 3 | Same as Val12 InsertHint VA | **Falsified** — peer CF at `0x0053a8e0` (isnil@+0x19); this is isnil@+0x29 |
| 4 | Single int key @ +0x10 | **Falsified** — 2-dword key order via `FUN_00401480` on +0/+4 and node +0x10/+0x14 |
| 5 | `RET 0x10` like insert rebalance | **Falsified** — **`RET 0x0c`** (3 stack args) |
| 6 | Product VOG_DEBUG_STOP method | **Reject** — generic STL helper; sole caller is map operator-index style shell |
| 7 | Decompiler where after prev/next always correct | **Partial fail** — decomp aliases both insert wheres to same SSA; **bytes** show pred vs hint / hint vs succ |
| 8 | Multi-caller skill API | **Falsified** — single xref `FUN_004cc400` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Hint-insert CF shape | **High** | Wrong uniqueness / order |
| ABI thiscall + RET 0x0c | **High** | Stack corruption |
| isnil@+0x29 family | **High** | Wrong node layout |
| 2-dword key less | **High** | Mis-ordered map |
| Product type English | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against insert rebalance dual

```
// WQ9E-E sealed FUN_004cbb60:
//   always-insert + RB; RET 0x10; 4 stack args (out, addLeft, where, value)
// This OWN unit selects (addLeft, where) or delegates to FUN_004cbee0.
// Partition residual: insert-path peer / caller of dualed insert rebalance.
```

---

## 4. Surviving contract for AutoCore

```
// Port as unique insert-with-hint (not always-insert, not pure find):
//  - empty / begin / end / neighbor-valid → InsertAndRebalance_Isnil29
//  - else InsertOrFind → *out = node
//  - key: 2-dword ordered (FUN_00401480); isnil@+0x29
//  - ABI: thiscall + ret 0x0c
// Do not merge with Val12 InsertHint or int-key insert-or-find (004cbe20).
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/family. Product key English residual → **accept-with-gaps**.
