# Review B (skeptical / adversarial): `aa_005690a0` StdMap_IntKey_InsertNodeAndRebalance_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005690a0` |
| **VA** | `0x005690a0` |
| **Canonical name** | `StdMap_IntKey_InsertNodeAndRebalance_Inferred` (**Inferred**) |
| **Review date** | `2026-07-29` (OWN-ONLY dual B — W22-E) |
| **Reviewer role** | Adversarial dual (attack over-claims) |
| **Counterpart** | `reviews/A_aa_005690a0_StdMap_IntKey_InsertNodeAndRebalance_Inferred.md` |
| **System** | stl-map |
| **Verdict** | **accept-with-gaps** on shape; **reject** find/upsert / staging-0x50 identity claims |

---

## 1. What this is *not*

| Attack | Result |
|---|---|
| “Insert-or-find / may skip alloc” | **Falsified** — always `FUN_00568f60` + `size++` |
| “Equal-key rewrite” | **Falsified** — no compare; parents own equal |
| “Same unit as mission staging insert `00538ea0`” | **Falsified** — staging is **0x50** / 14 dwords; this is **0x4C** / **15** dwords (shared rotate helpers only) |
| “`ret 8` like insert-or-find parent” | **Falsified** — epilogue **`C2 10 00`** (four stack args) |
| “Color 0 = black” | **Falsified** — 0=red, 1=black |
| “Self-recursive” | **Falsified** — no call to self |
| “Int key proven inside this body alone” | **Partial** — body only bulk-copies 15 dwords; **int key @ +0x0C** is from parent duals, not this VA’s compares |
| Product `std::map::_Insert` name | **Unproven** |

---

## 2. Decompiler hazards corrected by dual

| Decomp artifact | Reality |
|---|---|
| `param_1` as plain `int` | MapShell* ECX thiscall |
| `FUN_00568b70(piVar2)` one arg | `__thiscall(map, node*)`; ECX=map from EDI |
| `piVar6[0x12]` color | `0x12*4 = 0x48` |
| Inlined L-rotate vs missing helper | Same rewires as `FUN_00568b70`; isnil `+0x49` |
| Scaffold CVOG-named alias | **False** product name |

---

## 3. Layout challenges

| Challenge | Response | CF |
|---|---|---|
| Node size shared with string-key map? | String insert uses **0x30** / color +0x2C; this **0x4C** / +0x48 | **High** distinct |
| Node size shared with staging 0x50? | ctor `new(0x4C)` vs staging `new(0x50)` | **High** distinct |
| `+0x48` isnil? | color arg → +0x48; isnil 0 @ +0x49; rebalance vs rotate guards split cleanly | **High** |
| Size magic wrong? | `cmp [edi+8],0x04444443` / `jb` ≡ `size > 0x4444442` | **High** |
| 15-dword value over-read risk from int* parents | Parent may pass wider stack object; **payload domain Open**; copy width sealed | **High** width / **Open** domain |

---

## 4. Surviving contract (minimal)

```
// __thiscall on MapShell
// ALWAYS inserts a new 0x4C node (caller ensures miss + where/addLeft)

void StdMap_IntKey_InsertNodeAndRebalance(
    MapShell *map,          // ECX
    Node **outIt,
    char addLeft,
    Node *where,
    const void *value15);   // 15 dwords → node+0x0C
// RET 0x10
//
// Throws if map->size > 0x4444442 ("map/set<T> too long")
// color +0x48 red=0 black=1; isnil +0x49
// Rotates: FUN_00568b70 L, FUN_005681a0 R; one L inlined
//
// Do NOT use for equal-key refresh — parents FUN_00569320 / FUN_00569560.
```

---

## 5. Cross-check vs dual A

| A claim | B stance |
|---|---|
| `__thiscall` + `ret 0x10` | **Agree** |
| Always alloc + rebalance | **Agree** |
| Node 0x4C / 15 dwords / color +0x48 / isnil +0x49 | **Agree** |
| 0=red, 1=black | **Agree** |
| Shared rotates with 00538ea0 family | **Agree** helpers; **reject** same specialization |
| Int-key name | **Agree Inferred** — key role from parents, not this body |
| Product English open | **Agree** |

---

## 6. Residual (honest)

1. Product / typedef name.
2. Full 15-dword value layout English.
3. Dynamic call sites beyond static xrefs.
4. Runtime rebalance capture; bit-exact diff.
5. Inlined L-rotate codegen rationale (non-semantic).

---

## 7. Verdict

### **accept-with-gaps**

ABI, always-insert CF, size cap, **0x4C** geometry, color convention, rotation helpers (incl. inlined L), and static callers are **sealed**. Reject find/upsert and conflation with staging **0x50** insert. Dual A acceptable with product name + full value typedef open.
