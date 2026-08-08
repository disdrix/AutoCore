# Review B (skeptical / adversarial): `aa_005a4950` StdTree_InsertAndRebalance_Isnil21_Node0x24_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005a4950` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY R12-033; dual start 2646) |
| **Counterpart** | `reviews/A_aa_005a4950_StdTree_InsertAndRebalance_Isnil21_Node0x24_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is InsertOrFind / unique insert | **Falsified as sole role** — no key compare in body; always buynode+link; uniqueness is caller `005a4b70` |
| 2 | Same unit as `00407200` Val16/0x28 always-insert | **Falsified** — buynode `005a4870` uses `operator_new(0x24)`; size gate `0x0CCCCCCB` not `0xFFFFFFE`; different VA |
| 3 | isnil@+0x29 / isnil29 family | **Falsified** — byte `80 7A 21 00` (imm `0x21`); color writes `+0x20` |
| 4 | isnil@+0x2D / +0x31 family | **Falsified** — same imm seal |
| 5 | Freelist / CNDHash insert | **Falsified** — `"map/set<T> too long"` + tree head/size + RB colors + rotates |
| 6 | cdecl / no this | **Falsified** — entry `MOV EDI,ECX`; caller sites `MOV ECX,EDI` before CALL |
| 7 | `RET 0` / `RET 4` / `RET 0x0C` | **Falsified** — epilogue `C2 10 00` (**RET 0x10**) |
| 8 | Max size same as Val16 peer (`0xFFFFFFE`) | **Falsified** — `cmp [edi+8], 0x0CCCCCCB` |
| 9 | Leaf / no callees | **Falsified** — buynode + L/R rotates + throw path |
| 10 | Skill-only / CVOGReaction exclusive | **Falsified** — generic STL always-insert; system tag is map-set helper under skills-abilities partition |
| 11 | Node size 0x28 like Val16 family | **Falsified** — buynode `operator_new(0x24)` |
| 12 | Performs Lrotate only via call (no inline) | **Partial nuance** — one L path is **inlined** (isnil@+0x21); other L/R paths call dualed rotates; semantics still Lrotate |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Always-insert + RB CF | **High** | Wrong uniqueness / balance |
| ABI thiscall + RET 0x10 | **High** | Stack corruption |
| isnil@+0x21 / color@+0x20 | **High** | Wrong node family |
| Node 0x24 / buynode pairing | **High** | Wrong allocation size |
| Distinct from 00407200 | **High** | Port merge bug |
| Product type English | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against parent dual + peers

```
// R11-007 dualed Rrotate isnil21 005a27f0 (parent dual of this OWN):
//   leaf right-rotate; isnil@+0x21; color@+0x20; ret 4; called from this unit
// R10-030 dualed Lrotate isnil21 0050e9f0:
//   leaf left-rotate; same family; called + one path inlined here
// WQ9I-B dualed always-insert isnil21 00407200:
//   same CF shape; buynode 00408990 operator_new(0x28) Val16;
//   size gate 0xFFFFFFE — DO NOT MERGE
// Residual buynode 005a4870:
//   operator_new(0x24); key dword; FUN_005a42d0 vector copy; color@+0x20; isnil@+0x21
// Caller 005a4b70:
//   lower-bound on u32 key @ node[3]; isnil@+0x21; two CALL sites into this unit
```

---

## 4. Surviving contract for AutoCore

```
// Port as shared StdTree always-insert + rebalance for isnil@+0x21 / node 0x24:
//  - thiscall; ECX = map*; stack (out**, addLeft, where*, value*); ret 0x10
//  - size >= 0x0CCCCCCB → length_error("map/set<T> too long")
//  - buynode 005a4870 (0x24 / red / isnil0 / u32 key + vector payload)
//  - link empty/left/right + extremum; RB (L 0050e9f0 / R 005a27f0; one L inlined)
//  - root black@+0x20; *out = node
//  - NO key compare — pair with InsertOrFind-style 005a4b70
// Do not merge with Val16/0x28 always-insert 00407200 or isnil29/2D/31 families.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/family/node-size/role. Product residual → **accept-with-gaps**. Runtime Confirmed: **not claimed**.
