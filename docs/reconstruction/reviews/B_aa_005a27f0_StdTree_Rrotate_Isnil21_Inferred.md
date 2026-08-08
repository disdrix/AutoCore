# Review B (skeptical / adversarial): `aa_005a27f0` StdTree_Rrotate_Isnil21_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005a27f0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY R11-007) |
| **Counterpart** | `reviews/A_aa_005a27f0_StdTree_Rrotate_Isnil21_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is left-rotate | **Falsified** — reads `*x` (left), rehangs as right of promoted node; Lrotate twin `0050e9f0` reads `x+8` (right) |
| 2 | isnil@+0x29 / isnil29 family | **Falsified** — byte `80 7E 21 00` (imm `0x21`), not `0x29` |
| 3 | isnil@+0x2D / +0x31 family | **Falsified** — same imm seal; peers are different VAs |
| 4 | Color bit test / recolor helper | **Falsified** — only isnil@+0x21 tested; no color write in body |
| 5 | Skill / CVOGReaction exclusive helper | **Falsified** — 14 callers / 35 xrefs across map shells; old auto alias is chain noise |
| 6 | cdecl / no this | **Falsified** — parent sites `MOV ECX,EDI` before CALL; decomp `__thiscall` |
| 7 | `RET 0` / multi stack args | **Falsified** — three exits all `C2 04 00` |
| 8 | Non-leaf / calls other helpers | **Falsified** — callees empty; leaf classification |
| 9 | Same VA as Lrotate | **Falsified** — L is `0x0050e9f0` |
| 10 | Merge with peer Rrotate isnil29 body | **Falsified** — CF twin, different isnil imm / VA |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Rrotate CF | **High** | Wrong balance direction |
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
// R10-030 dualed Lrotate isnil21 0050e9f0:
//   y = x->right (+8); rehang left; opposite of this unit
// WQ9D-D dualed Rrotate isnil29 004192f0:
//   identical CF; isnil imm 0x29 vs 0x21
// Peer Rrotates isnil2D 0042a840 / isnil31 00403ee0 (dualed elsewhere)
```

---

## 4. Surviving contract for AutoCore

```
// Port as shared StdTree right-rotate for isnil@+0x21:
//  - thiscall; ECX = tree*; stack Node* x; ret 4
//  - y = x->left (*x); x->left = y->right; if !isnil(y->right) parent-link
//  - reparent y; root/right/left reattach; y->right = x; x->parent = y
//  - isnil@+0x21; color@+0x20 (not touched here)
// Pair with Lrotate 0050e9f0 and InsertAndRebalance 00407200.
// Do not merge with isnil29/2D/31 Rrotates or with Lrotate.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/family/role. Product residual → **accept-with-gaps**.
