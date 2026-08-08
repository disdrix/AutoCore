# Review B (skeptical / adversarial): `aa_0050e9f0` StdTree_Lrotate_Isnil21_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0050e9f0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY R10-030) |
| **Counterpart** | `reviews/A_aa_0050e9f0_StdTree_Lrotate_Isnil21_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is right-rotate | **Falsified** — reads `x+8` (right), rehangs as left of promoted node; Rrotate twin `005a27f0` reads `*x` (left) |
| 2 | isnil@+0x29 / isnil29 family | **Falsified** — byte `80 7E 21 00` (imm `0x21`), not `0x29` |
| 3 | isnil@+0x2D / +0x31 family | **Falsified** — same imm seal; peers are different VAs |
| 4 | Color bit test / recolor helper | **Falsified** — only isnil@+0x21 tested; no color write in body |
| 5 | Skill / CVOGReaction exclusive helper | **Falsified** — 14 callers / 30 xrefs across map shells; old auto alias is chain noise |
| 6 | cdecl / no this | **Falsified** — parent sites `MOV ECX,EDI` before CALL; decomp `__thiscall` |
| 7 | `RET 0` / multi stack args | **Falsified** — three exits all `C2 04 00` |
| 8 | Non-leaf / calls other helpers | **Falsified** — callees empty; leaf classification |
| 9 | Same VA as Rrotate | **Falsified** — R is `0x005a27f0` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Lrotate CF | **High** | Wrong balance direction |
| ABI thiscall + RET 4 | **High** | Stack corruption |
| isnil@+0x21 | **High** | Wrong node family |
| Shared STL helper | **High** | Over-narrow port |
| Product type English | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against parent + peers

```
// WQ9I-B dualed InsertAndRebalance 00407200:
//   while parent color red: uncle recolor / L 0050e9f0 / R 005a27f0
//   color@+0x20; isnil@+0x21; node 0x28; buynode 00408990
// WQ9D-C dualed Lrotate isnil29 004192a0:
//   body hex identical except isnil imm 0x29 vs 0x21
// Twin residual Rrotate 005a27f0:
//   y = x->left (*x); rehang right; opposite of this unit
```

---

## 4. Surviving contract for AutoCore

```
// Port as shared StdTree left-rotate for isnil@+0x21:
//  - thiscall; ECX = tree*; stack Node* x; ret 4
//  - y = x->right (+8); x->right = y->left; if !isnil(y->left) parent-link
//  - reparent y; root/left/right reattach; y->left = x; x->parent = y
//  - isnil@+0x21; color@+0x20 (not touched here)
// Pair with Rrotate 005a27f0 and InsertAndRebalance 00407200.
// Do not merge with isnil29/2D/31 Lrotates or with Rrotate.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/family/role. Product residual → **accept-with-gaps**.
