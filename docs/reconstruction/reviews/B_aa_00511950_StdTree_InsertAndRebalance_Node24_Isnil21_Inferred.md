# Review B (skeptical / adversarial): `aa_00511950` StdTree_InsertAndRebalance_Node24_Isnil21_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00511950` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY R12-014) |
| **Counterpart** | `reviews/A_aa_00511950_StdTree_InsertAndRebalance_Node24_Isnil21_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is InsertOrFind / lower_bound | **Falsified** — no key compare; parent `00511b40` compares int keys and calls this only for insert path |
| 2 | Same unit as Val16 peer `00407200` | **Falsified** — different VA, max gate `0xCCCCCCB` vs `0xFFFFFFE`, buynode `005118b0`/`new(0x24)` vs `00408990`/`0x28` |
| 3 | isnil@+0x29 / isnil29 family | **Falsified** — inlined Lrotate tests `80 7A 21 00`; color@+0x20 matches isnil21 |
| 4 | Erase / rebalance-delete helper | **Falsified** — size++, buynode, `"map/set<T> too long"` insert path |
| 5 | cdecl / no this | **Falsified** — `MOV EDI,ECX` entry; call sites `MOV ECX,EDI` |
| 6 | `RET 4` / single stack arg | **Falsified** — epilogue `C2 10 00` (RET 0x10) |
| 7 | Skill / ability exclusive logic | **Falsified** — pure STL insert shell; system tag is residual partition only |
| 8 | Leaf (no callees) | **Falsified** — calls buynode + L/R rotates + throw path |
| 9 | Both rotates always callees (no inline) | **Partial** — L called at one site; **one Lrotate path inlined** (right-parent uncle-black). CF still Lrotate; not a different algorithm |
| 10 | Merge name with `StdTree_InsertAndRebalance_Isnil21_Inferred` | **Falsified** — that name is owned by `aa_00407200`; Node24 disambiguator required |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Always-insert + RB CF | **High** | Wrong map op |
| ABI thiscall + RET 0x10 | **High** | Stack corruption |
| isnil@+0x21 / color@+0x20 / node 0x24 | **High** | Wrong node family / allocator |
| Distinct from Val16 peer | **High** | Silent merge bug |
| Product type English | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against parent + peers

```
// R11-007 dualed Rrotate 005a27f0 (parent dual):
//   this unit calls it for insert rebalance (2 sites + inlined L pair)
// R10-030 dualed Lrotate 0050e9f0:
//   one CALL site; one equivalent inline L path
// WQ9I-B dualed InsertAndRebalance Val16 00407200:
//   same CF shape; node 0x28 / max 0xFFFFFFE / buynode 00408990
// Parent shell 00511b40 (residual, not OWN):
//   int key lower_bound; calls this with addLeft=1 / addLeft=bVar2
// Nested buynode 005118b0 (residual, not OWN):
//   operator_new(0x24); key=*value; vector-copy FUN_005114e0; color red; isnil0
```

---

## 4. Surviving contract for AutoCore

```
// Port as shared StdTree always-insert + rebalance for Node24 / isnil@+0x21:
//  - thiscall; ECX = map*; stack (out**, addLeft, where*, value*); ret 0x10
//  - throw if size >= 0xCCCCCCB ("map/set<T> too long")
//  - buynode Node24 red; size++; link empty/left/right + extremum
//  - while parent red: uncle recolor / L 0050e9f0 / R 005a27f0 / one L inlined
//  - root black; *out = new node
// Do NOT merge with Val16 insert 00407200 or isnil29 insert 00406c40.
// Pair with dualed L/R rotates isnil21; residual buynode 005118b0 + InsertOrFind 00511b40.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/family/role/disambiguation from Val16 peer. Product residual → **accept-with-gaps**. Runtime Confirmed: **not claimed**.
