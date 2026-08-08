# Review B (skeptical / adversarial): `aa_00403ee0` StdTree_Rrotate_Isnil31_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00403ee0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY WQ9L-C) |
| **Counterpart** | `reviews/A_aa_00403ee0_StdTree_Rrotate_Isnil31_Inferred.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Left rotate (not right) | **Falsified** — pivot is `*x` (left child); sets `y->right = x` |
| 2 | ECX = tree (isnil29 convention) | **Falsified** — `MOV EAX,[ECX]` treats ECX as node; tree loaded from `[esp+4]` |
| 3 | isnil@+0x29 / merge with `004192f0` | **Falsified** — opcode `80 7A 31 00` is **+0x31**; different VA |
| 4 | isnil@+0x2D / merge with `0042a840` | **Falsified** — different offset (`+0x31` vs `+0x2D`); same shape, distinct family |
| 5 | Recolors nodes (color@+0x30) | **Falsified** — no stores to +0x30; parents recolor around CALL |
| 6 | `ret` plain / no stack cleanup | **Falsified** — three `C2 04 00` exits |
| 7 | Non-leaf / allocates | **Falsified** — 0 callees; pure pointer surgery |
| 8 | Same as Max `004043e0` | **Falsified** — rotate vs rightmost walk; different ABI |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Right-rotate CF | **Confirmed** | Broken RB structure |
| ECX=node / stack tree / RET 4 | **Confirmed** | Arg swap corruption on rebalance |
| isnil@+0x31 | **Confirmed** | Wrong nil sentinel family |
| Product type English | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against L-rotate peer + other isnil families

```text
// Peer FUN_00403e90 (L-rotate): starts MOV from [param+8] (right child); same
//   isnil@+0x31 and same ECX=node / stack tree / RET 4 shape.
// isnil2D Rrotate 0042a840: identical CF shape with isnil 80 7A 2D 00 — keep
//   family-distinct (do not merge).
// isnil29 Rrotate 004192f0: ECX=tree / stack=node (ABI invert) + isnil@+0x29.
// Callers push tree then CALL with ECX already the pivot node.
```

---

## 4. Surviving contract for AutoCore

```text
// Port as shared tree right-rotate for isnil@+0x31:
//  - ECX = node x, stack = tree, RET 4
//  - y = x->left; reparent; y->right = x
//  - Pair with L-rotate 00403e90; erase 00408ed0; insert peer 00403250
// Do not merge with isnil2D (0042a840) or isnil29 (004192f0) rotates.
// Do not invert ECX/stack relative to isnil29 family.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/isnil/leaf. Product residual only → **accept**.
