# Review B (skeptical / adversarial): `aa_00407200` StdTree_InsertAndRebalance_Isnil21_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00407200` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY WQ9I-B) |
| **Counterpart** | `reviews/A_aa_00407200_StdTree_InsertAndRebalance_Isnil21_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is InsertHint (key compare + fallback) | **Falsified** — no less-than / no InsertOrFind call; pure allocate+link+RB |
| 2 | This is InsertOrFind / unique insert | **Falsified as sole role** — always inserts; uniqueness is parent's job |
| 3 | isnil@+0x29 / node 0x30 family | **Falsified** — buynode `00408990` is Val16/isnil21/0x28; color writes **+0x20** not +0x28 |
| 4 | Same VA as isnil29 always-insert | **Falsified** — peer is `00406c40` (different max/size/buynode/rotates) |
| 5 | Freelist / CNDHash insert | **Falsified** — `"map/set<T> too long"` + tree head/size + RB colors |
| 6 | `RET 0x0C` like InsertHint | **Falsified** — **`RET 0x10`** (4 stack args) |
| 7 | Max size same as isnil29 (`0x0AAAAAA8`) | **Falsified** — gate is **`0xFFFFFFFE`** compare |
| 8 | cdecl / no this | **Falsified** — `MOV EDI,ECX`; callers pass map in ECX |
| 9 | Performs key compare internally | **Falsified** — zero compare helpers; where comes from parent |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Always-insert + RB CF | **High** | Wrong uniqueness / balance |
| ABI thiscall + RET 0x10 | **High** | Stack corruption |
| isnil@+0x21 / color@+0x20 | **High** | Wrong node layout |
| Buynode pairing `00408990` | **High** | Wrong node size |
| Product type English | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against parents + peer

```
// WQ9H-F dualed InsertHint 00406560:
//   empty/begin/end/neighbor → CALL 00407200 (this unit)
//   else → InsertOrFind 00407060
// WQ9H-J dualed buynode 00408990:
//   operator_new(0x28); Val16; color@+0x20; isnil@+0x21
// WQ9E-G dualed isnil29 always-insert 00406c40:
//   same CF shape; color@+0x28; buynode 00407e30; max 0x0AAAAAA8
```

---

## 4. Surviving contract for AutoCore

```
// Port as shared StdTree always-insert + rebalance for isnil@+0x21:
//  - thiscall; ret 0x10; (out, addLeft, where, value)
//  - size >= 0xFFFFFFE → length_error("map/set<T> too long")
//  - buynode 00408990 (Val16 / red / isnil0 / 0x28)
//  - link + RB (rotates 0050e9f0 L / 005a27f0 R); root black@+0x20; *out = node
//  - NO key compare — pair with InsertHint 00406560 / InsertOrFind 00407060
// Do not merge with isnil29 always-insert 00406c40 or freelist helpers.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/family. Product residual → **accept-with-gaps**.
