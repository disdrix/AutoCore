# Review B (skeptical / adversarial): `aa_00406560` StdTree_InsertHint_Isnil21_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00406560` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (OWN-ONLY WQ9H-F) |
| **Counterpart** | `reviews/A_aa_00406560_StdTree_InsertHint_Isnil21_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is always-insert (`FUN_00407200`) only | **Falsified as sole role** — always-insert sites are *conditional* fast paths; equal/invalid hint falls through to `FUN_00407060` |
| 2 | This is insert-or-find only | **Falsified** — empty/begin/end/neighbor paths skip full walk |
| 3 | Same as isnil29 InsertHint VA | **Falsified as identity** — peer CF at `0x004cc220` (isnil@+0x29); this is **isnil@+0x21** |
| 4 | Single int key @ +0x10 | **Falsified** — 2-dword key order via `FUN_00401480` / inlined hi-signed lo-unsigned |
| 5 | isnil@+0x29 family | **Falsified** — attachment immediates **`0x21`** |
| 6 | `RET 0x10` like insert rebalance | **Falsified** — **`RET 0x0c`** (3 stack args) |
| 7 | Decompiler where after prev/next always correct | **Partial fail** — decomp aliases; **bytes** show pred vs hint / hint vs succ |
| 8 | Multi-caller skill API | **Falsified** — single xref `FUN_004055c0` |
| 9 | Same as pair-key less leaf | **Falsified** — this is the **hint shell**; less leaf is `00401480` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Hint-insert CF shape | **High** | Wrong uniqueness / order |
| ABI thiscall + RET 0x0c | **High** | Stack corruption |
| isnil@+0x21 family | **High** | Wrong node layout |
| 2-dword key less | **High** | Mis-ordered map |
| Product type English | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against pair-key less + isnil29 peer

```
// WQ9G-B sealed FUN_00401480:
//   hi signed primary, lo unsigned secondary; RET 8; callers: this + 004cc220
// WQ9F-E sealed InsertHint isnil29:
//   same CF shape; different isnil (+0x29) and insert callees
// This OWN unit is the isnil21 pair-key peer residual.
```

---

## 4. Surviving contract for AutoCore

```
// Port as unique insert-with-hint (not always-insert, not pure find):
//  - empty / begin / end / neighbor-valid → FUN_00407200 always-insert
//  - else FUN_00407060 InsertOrFind → *out = node
//  - key: 2-dword ordered (FUN_00401480); isnil@+0x21
//  - ABI: thiscall + ret 0x0c
// Do not merge with isnil29 InsertHint or treat as the less leaf itself.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/family. Product residual → **accept-with-gaps**.