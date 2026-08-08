# Review B (skeptical / adversarial): `aa_0041ba30` StdTree_InsertAndRebalance_CharKey_Isnil21_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0041ba30` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY R12-011) |
| **Counterpart** | `reviews/A_aa_0041ba30_StdTree_InsertAndRebalance_CharKey_Isnil21_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is InsertHint (key compare + fallback) | **Falsified** — no less-than / no InsertOrFind call; pure allocate+link+RB |
| 2 | This is InsertOrFind / unique insert | **Falsified as sole role** — always inserts; uniqueness is parent `0041a570` |
| 3 | Same unit as Val16 isnil21 always-insert `00407200` | **Falsified** — buynode `0041d860` (0x24) vs `00408990` (0x28); max `0x0CCCCCCB` vs `0xFFFFFFE`; sole caller `0041a570` |
| 4 | isnil@+0x29 / node 0x30 family | **Falsified** — buynode isnil@**+0x21**; color writes **+0x20**; rotates are isnil21 duals |
| 5 | Freelist / CNDHash insert | **Falsified** — `"map/set<T> too long"` + tree head/size + RB colors |
| 6 | `RET 0x0C` like some InsertHint shells | **Falsified** — **`RET 0x10`** (`C2 10 00`) |
| 7 | Max size same as Val16 peer (`0xFFFFFFE`) | **Falsified** — gate is **`0x0CCCCCCB`** |
| 8 | cdecl / no this | **Falsified** — `MOV EDI,ECX`; callers `MOV ECX,EDI` |
| 9 | Performs key compare internally | **Falsified** — zero compare helpers; where comes from parent |
| 10 | Skill/CVOGReaction-specific product name | **Falsified as name** — pure STL tree insert; system tag skills-abilities is inventory only |
| 11 | Runtime Confirmed | **Rejected** — no Launcher / no live probe this dual |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Always-insert + RB CF | **High** | Wrong uniqueness / balance |
| ABI thiscall + RET 0x10 | **High** | Stack corruption |
| isnil@+0x21 / color@+0x20 / node 0x24 | **High** | Wrong node layout |
| Char-key disambiguation vs `00407200` | **High** | Wrong merge / wrong max |
| Buynode pairing `0041d860` | **High** (raw) | Wrong node size if buynode misread |
| Product type English | **Low** | Naming only |
| Runtime | **Open** | Matrix policy — never Confirmed here |

---

## 3. Cross-check against parent rotates + peer

```
// R11-007 dualed Rrotate 005a27f0:
//   thiscall map; ret 4; color@+0x20; isnil@+0x21; leaf
// R10-030 dualed Lrotate 0050e9f0:
//   twin Lrotate same family
// WQ9I-B dualed Val16 always-insert 00407200:
//   same CF shape; buynode 00408990; max 0xFFFFFFE; node 0x28
// This unit 0041ba30:
//   same CF shape; buynode 0041d860; max 0x0CCCCCCB; node 0x24; char key
// Parent 0041a570 (undualed evidence only):
//   walks isnil@+0x21; compares *charKey < node[+0x0C]
```

---

## 4. Surviving contract for AutoCore

```
// Port as shared StdTree always-insert + rebalance for char-key isnil@+0x21:
//  - thiscall; ret 0x10; (out, addLeft, where, value); EAX=out
//  - size >= 0x0CCCCCCB → length_error("map/set<T> too long")
//  - buynode 0041d860 (node 0x24 / red / isnil0 / char@+0x0C)
//  - link + RB (rotates 0050e9f0 L / 005a27f0 R); root black@+0x20; *out = node
//  - NO key compare — pair with parent 0041a570
// Do not merge with Val16 always-insert 00407200, isnil29 00406c40, or freelist helpers.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/family/disambiguation. Product residual → **accept-with-gaps**. Runtime Confirmed: **not claimed**.
