# Review B (skeptical / adversarial): `aa_00511b40` StdMap_InsertOrFind_IntKey_Isnil21_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00511b40` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY R13-031; dual start **2686**) |
| **Counterpart** | `reviews/A_aa_00511b40_StdMap_InsertOrFind_IntKey_Isnil21_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Always-insert (merge with parent `00511950`) | **Falsified** — equal path writes `inserted=0` and returns existing node; parent is only the miss-path worker |
| 2 | isnil29 twin merge (`004cbe20`) | **Falsified** — this body uses `+0x21` / key `+0x0C`; isnil29 uses `+0x29` / key `+0x10` |
| 3 | PairKey isnil21 merge (`00407060`) | **Falsified** — this compares a single signed int via `SETL` on `[node+0xC]`, not pair less helper |
| 4 | Unsigned key | **Falsified** — `SETL` / signed `CMP` / `JL`-family (`0F 9C C1`) |
| 5 | `__cdecl` / wrong RET | **Falsified** — `MOV EDI,ECX` thiscall; `C2 08 00` RET 8 ×3; call site `MOV ECX,EDI` |
| 6 | Rewrites mapped payload on hit | **Falsified** — equal path only stores iterator + `inserted=0` |
| 7 | Skill/ability product helper (partition name) | **Falsified** — body has no skill strings; pure STL insert-or-find; partition is residual proximity only |
| 8 | Multiple domain callers / multi-xref | **Falsified as multi** — exactly **1** xref (`FUN_0050ba90`); still a shared-shape helper, not product-named |
| 9 | Key at +0x10 like isnil29 | **Falsified** — bytes `3B 50 0C` / `CMP … [EAX+0xC]` |
| 10 | Runtime Confirmed | **Fails** — open (no Launcher); Terminal **false** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Insert-or-find CF (miss vs equal) | **High** (static) | Double-insert / silent overwrite |
| isnil@+0x21 | **High** (static) | Walk off end / wrong family merge |
| Signed key@+0x0C | **High** (static) | Wrong ordering / unsigned mis-sort |
| RET 8 thiscall | **High** (static) | Stack smash / wrong arg count |
| Distinct from always-insert parent | **High** (static) | Accidental merge of two units |
| Distinct from isnil29 / PairKey peers | **High** (static) | Wrong node layout port |
| Product value_type English | **Low** | Name only (`_Inferred`) |
| Runtime | **Open** | No claim |

---

## 3. Cross-check against raw / bytes

```text
raw 2026-07-23 ≡ live decompile 2026-08-05 ≡ clean StdMap_InsertOrFind_IntKey_Isnil21_Inferred.cpp

Prologue:  51 55 8B 6C 24 10 56 57 8B F9     ; thiscall; EBP=value*
isnil:     80 78 21 00                        ; [node+0x21]
key:       3B 50 0C  … 0F 9C C1               ; signed SETL vs [node+0x0C]
insert×2:  E8 → 00511950 (addLeft=1 and goLeft)
pred:      E8 → 005adff0
equal:     C6 40 04 00                        ; inserted=0
RET×3:     C2 08 00

Body: 0x00511b40–0x00511bf8 inclusive (185 B); pad CC before FUN_00511c00.
Call site: MOV ECX,EDI; PUSH out; PUSH value; CALL 00511b40  (1× UNCONDITIONAL_CALL)
```

Reject ports that:

- Name this as always-insert / rebalance (parent `00511950`).
- Merge with isnil29 IntKey (`004cbe20`) or PairKey isnil21 (`00407060`).
- Use unsigned key compare or key@+0x10.
- Drop equal-path `inserted=0` (would force always-insert semantics).
- Claim skill-product ownership from partition tag alone.
- Claim Runtime Confirmed without Launcher evidence.

---

## 4. Surviving contract for AutoCore

```text
StdMap_InsertOrFind_IntKey_Isnil21_Inferred(map /*ECX*/, out, value) → void:
  lower_bound by signed int key @ node+0x0C / value[0], isnil@+0x21
  miss → StdTree_InsertAndRebalance_Node24_Isnil21_Inferred → out={new, true}
  hit  → out={existing, false}  // no mapped rewrite
  RET 8

// Keep separate from:
//   00511950 always-insert Node24 isnil21
//   004cbe20 InsertOrFind IntKey isnil29
//   00407060 InsertOrFind PairKey isnil21
// Port as free/thiscall map insert; do not invent skill-domain ownership here.
```

---

## 5. Open questions

- Host map product type at `FUN_0050ba90` (value vector of 0x10 elements per parent insert notes).
- Why only one xref — specialization instance vs shared plate emission.
- Dual of `FUN_005adff0` predecessor for full family seal.

**Verdict:** Adversarial pass confirms A on CF/ABI/isnil21/signed-int-key/RET8; always-insert-merge, isnil29-merge, PairKey-merge, skill-product, and Runtime Confirmed claims **falsified** → **accept-with-gaps**.
