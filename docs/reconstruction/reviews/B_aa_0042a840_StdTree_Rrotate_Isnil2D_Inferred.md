# Review B (skeptical / adversarial): `aa_0042a840` StdTree_Rrotate_Isnil2D_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0042a840` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY WQ9K-J) |
| **Counterpart** | `reviews/A_aa_0042a840_StdTree_Rrotate_Isnil2D_Inferred.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Left rotate (not right) | **Falsified** — pivot is `*x` (left child); sets `y->right = x` |
| 2 | ECX = tree (isnil29 convention) | **Falsified** — `MOV EAX,[ECX]` treats ECX as node; tree loaded from `[esp+4]` |
| 3 | isnil@+0x29 / merge with `004192f0` | **Falsified** — opcode `80 7A 2D 00` is **+0x2D**; different VA/ABI |
| 4 | isnil@+0x49 / merge with `005681a0` | **Falsified** — different offset, ABI, consumers |
| 5 | Recolors nodes (color@+0x2C) | **Falsified** — no stores to +0x2C; parents recolor around CALL |
| 6 | `ret` plain / no stack cleanup | **Falsified** — three `C2 04 00` exits |
| 7 | Non-leaf / allocates | **Falsified** — 0 callees; pure pointer surgery |
| 8 | Skill-domain exclusive | **Falsified** — shared StringKey map insert/erase rebalance |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Right-rotate CF | **Confirmed** | Broken RB structure |
| ECX=node / stack tree / RET 4 | **Confirmed** | Arg swap corruption on rebalance |
| isnil@+0x2D | **Confirmed** | Wrong nil sentinel family |
| Product type English | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against L-rotate peer + isnil29

```
// Peer FUN_0044e010 (L-rotate): starts MOV EAX,[ECX+8] (right child); same
//   isnil@+0x2D and same ECX=node / stack tree / RET 4 shape.
// isnil29 Rrotate 004192f0: starts MOV EDX,[esp+4] (node on stack); ECX=tree;
//   isnil 80 7E 29 00 — keep distinct (ABI invert + offset).
// Callers push tree then CALL with ECX already the pivot node.
```

---

## 4. Surviving contract for AutoCore

```
// Port as shared tree right-rotate for isnil@+0x2D:
//  - ECX = node x, stack = tree, RET 4
//  - y = x->left; reparent; y->right = x
//  - Pair with L-rotate 0044e010; insert 00430b60; erase 004094c0
// Do not merge with isnil29 (004192f0) or isnil49 (005681a0) rotates.
// Do not invert ECX/stack relative to isnil29 family.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/isnil/leaf. Product residual only → **accept**.
