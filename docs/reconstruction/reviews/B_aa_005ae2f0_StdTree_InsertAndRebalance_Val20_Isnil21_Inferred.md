# Review B (skeptical / adversarial): `aa_005ae2f0` StdTree_InsertAndRebalance_Val20_Isnil21_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005ae2f0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY R12-034) |
| **Counterpart** | `reviews/A_aa_005ae2f0_StdTree_InsertAndRebalance_Val20_Isnil21_Inferred.md` |
| **Partition** | R12-034; parent dual residual of `0x005a27f0` |
| **Terminal** | **false** (no Runtime Confirmed) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is Rrotate / Lrotate leaf (`005a27f0` / `0050e9f0`) | **Falsified** — body is insert+rebalance; **calls** those leaves; size gate + buynode + `"map/set<T> too long"` |
| 2 | Same as Val12 insert `005ae4e0` (adjacent) | **Falsified** — max `0xCCCCCCB` vs `0x15555553`; buynode `005ae1c0` (0x24) vs `005ae220` (0x1c); rotates isnil21 vs Val12 rotates |
| 3 | Same as Val16 insert `00407200` | **Falsified** — max `0xCCCCCCB` vs `0xFFFFFFE`; buynode `005ae1c0` vs `00408990`; node 0x24 vs 0x28; only **rotates** shared |
| 4 | isnil@+0x19 / Val12 family | **Falsified** — color@+0x20, isnil@+0x21 in body + buynode; not +0x18/+0x19 |
| 5 | isnil@+0x29 / +0x2D / +0x31 family | **Falsified** — imm `0x21` on inline L path; CALL to dualed isnil21 rotates |
| 6 | MissionStopLimit / skill-only product API | **Falsified** — pure STL insert shell; old auto alias is chain noise; sole live parent is insert-or-find `005aec50` |
| 7 | Insert-or-find / key-compare inside this unit | **Falsified** — no key compare; parent `005aec50` compares int pair then calls this |
| 8 | cdecl / no this / wrong RET | **Falsified** — `mov edi,ecx`; `C2 10 00` ret 0x10; four stack args |
| 9 | Max size `0xFFFFFFE` or `0x15555553` | **Falsified** — bytes `cmp [edi+8], 0x0CCCCCCB` |
| 10 | Node size 0x28 (Val16) | **Falsified** — buynode `operator_new(0x24)`; 5 value dwords |
| 11 | Multiple callers / skill-wide fan-in | **Falsified** — 1 caller / 1 xref only (`FUN_005aec50`) |
| 12 | Runtime Confirmed | **Rejected** — no Launcher; Terminal false |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Always-insert + RB CF | **High** | Wrong map mutation |
| ABI thiscall + RET 0x10 | **High** | Stack corruption |
| Val20 / node 0x24 / isnil@+0x21 | **High** | Wrong layout port |
| Size gate `0xCCCCCCB` | **High** | Spurious throw / missing throw |
| Shared isnil21 rotates | **High** | Wrong rotate pairing |
| Sole caller shell | **High** | Over-broad ownership |
| Product type English | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against parent + peers

```
// Partition parent dual R11-007 Rrotate 005a27f0:
//   this unit is a *caller residual* of that leaf (not a child of Rrotate).
//   Role: insert+rebalance that *uses* L 0050e9f0 / R 005a27f0.
//
// Peer Val16 InsertAndRebalance 00407200 (WQ9I-B):
//   same rotate pair + color@+0x20/isnil@+0x21; node 0x28; max 0xFFFFFFE;
//   buynode 00408990 — DO NOT MERGE.
//
// Adjacent Val12 InsertAndRebalance 005ae4e0 (W27-T):
//   same SEH LAB_009a65a2 / ret 0x10 shape; node 0x1c; max 0x15555553;
//   rotates 00573170/00418c10 — DO NOT MERGE.
//
// Buynode 005ae1c0 (residual):
//   operator_new(0x24); copy 5 dwords; color@+0x20; isnil@+0x21=0.
//
// Sole parent 005aec50 (residual):
//   walk tree by (int,int) key at node+0x0C/+0x10; call this on miss.
```

---

## 4. Surviving contract for AutoCore

```
// Port as generic StdTree always-insert + rebalance for Val20 / isnil@+0x21:
//  - thiscall; ECX = map*; stack (out**, addLeft, where*, value*); ret 0x10
//  - node 0x24; color@+0x20; isnil@+0x21; Val20 5×u32 @+0x0C
//  - size gate: throw "map/set<T> too long" if size >= 0xCCCCCCB
//  - buynode FUN_005ae1c0 (color red); size++; link first|left|right
//  - RB while parent red: recolor uncle OR L 0050e9f0 / R 005a27f0 / inline L
//  - root black; *out = new node
//  - parent owns uniqueness (FUN_005aec50 insert-or-find)
// Do NOT merge with Val12 005ae4e0 or Val16 00407200.
// Do NOT treat as skill/MissionStopLimit-specific.
// Do NOT claim Runtime Confirmed.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/family/role/sole-caller. Product residual + no runtime → **accept-with-gaps**. All merge/narrow/wrong-RET/wrong-family attacks rejected.
