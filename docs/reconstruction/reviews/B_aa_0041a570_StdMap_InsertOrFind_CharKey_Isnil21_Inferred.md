# Review B (skeptical / adversarial): `aa_0041a570` StdMap_InsertOrFind_CharKey_Isnil21_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0041a570` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY R13-021) |
| **Counterpart** | `reviews/A_aa_0041a570_StdMap_InsertOrFind_CharKey_Isnil21_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is always-insert only (no uniqueness) | **Falsified** — equal path writes `inserted=0` and returns existing node; no insert call |
| 2 | Same unit as insert child `0041ba30` | **Falsified** — this unit compares keys and may skip insert; `0041ba30` never compares |
| 3 | Same as pair-key isnil21 InsertOrFind `00407060` | **Falsified** — single char @+0x0C vs hi/lo pair; insert worker `0041ba30` not `00407200` |
| 4 | Int-key isnil29 InsertOrFind `004cbe20` | **Falsified** — isnil@**+0x21**; char compare; different insert |
| 5 | Freelist / CNDHash insert | **Falsified** — tree head/isnil walk + dualed map insert + pred |
| 6 | `RET 0x10` like insert child | **Falsified** — **`RET 0x8`** (`C2 08 00` ×3) |
| 7 | `RET 0x0C` / three stack args | **Falsified** — two stack args (out, value) |
| 8 | cdecl / no this | **Falsified** — `MOV EDI,ECX`; callers `MOV ECX,ESI/EBP` |
| 9 | Hit rewrites mapped value | **Falsified** — equal path only stores it + flag |
| 10 | isnil@+0x29 / node 0x30 family | **Falsified** — isnil checks `+0x21`; parent dual node 0x24 |
| 11 | Skill/CVOGReaction-specific product name | **Falsified as name** — pure STL map insert-or-find; system tag skills-abilities is inventory only |
| 12 | Runtime Confirmed | **Rejected** — no Launcher / no live probe this dual |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Unique insert-or-find CF | **High** | Wrong uniqueness / double-insert |
| ABI thiscall + RET 0x8 | **High** | Stack corruption |
| isnil@+0x21 / char key@+0x0C | **High** | Wrong node layout |
| Pairing with insert `0041ba30` | **High** | Wrong family / wrong max/node size |
| Pred pairing `005adff0` | **High** (CF) | Wrong placement if pred misread |
| Product type English | **Low** | Naming only |
| Runtime | **Open** | Matrix policy — never Confirmed here |

---

## 3. Cross-check against parent insert + peers

```
// R12-011 dualed always-insert 0041ba30:
//   thiscall map; ret 0x10; no key compare; node 0x24; max 0x0CCCCCCB
// WQ9I-C dualed pair InsertOrFind 00407060:
//   same CF shape (walk / begin / pred / miss / equal); pair key; insert 00407200
// This unit 0041a570:
//   same CF shape; char key @+0x0C; insert 0041ba30; pred 005adff0; ret 0x8
// Callers 007eaf20 / 0059a940:
//   build value via 0041c140; char key front; MOV ECX,map; CALL this
```

---

## 4. Surviving contract for AutoCore

```
// Port as shared StdMap unique insert-or-find for char-key isnil@+0x21:
//  - thiscall; ret 0x8; (out, value); out = {it, inserted@+4}
//  - walk: goLeft = (*key < node.key@+0x0C); isnil@+0x21
//  - goLeft && where==begin → insert addLeft=1
//  - goLeft && !begin → pred(where); then strict where.key < key → insert
//  - !goLeft → strict where.key < key → insert; else equal {it,0}
//  - insert worker: 0041ba30 (always-insert + RB); never rewrite on hit
// Do not merge with pair InsertOrFind 00407060, always-insert 0041ba30 as sole role,
// Val16 always-insert 00407200, or freelist helpers.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/family/disambiguation. Product residual → **accept-with-gaps**. Runtime Confirmed: **not claimed**.
