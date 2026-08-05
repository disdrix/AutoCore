# Review A (reconstruction fidelity): `aa_0051d2f0` Skill_CategoryCooldownMap_Insert

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051d2f0` |
| **VA** | `0x0051d2f0` |
| **Canonical name** | `Skill_CategoryCooldownMap_Insert` |
| **Review date** | `2026-07-29` (dual residual seal; prior 2026-07-23 scaffold) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0051d2f0_Skill_CategoryCooldownMap_Insert.md` |
| **System** | `skills-abilities` |
| **Verdict** | **accept-with-gaps** |
| **Scratch** | `reviews/a_0051d2f0.md` |

---

## 1. Purpose

`std::map`-style **insert-or-find** on the category-cooldown red-black tree (`__thiscall` on map shell). Walks by **category key** (`entry+0` / `node+0x0C`); on miss allocates a **0x1C** node via `FUN_0051c1c0` → `FUN_005ae220` (copies `{key,start,duration}`); on hit returns existing iterator with `inserted=0` and **does not** rewrite start/duration. Core mutator under `Skill_InsertCategoryCooldown` and `CVOGHBOKToCastAgain_ctor`.

```
pair{it, inserted} = Map_InsertOrFind(map, {key, startTick, durationMs})
// RET 0x8; this = map in ECX
```

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0051d2f0_Skill_CategoryCooldownMap_Insert.md` |
| Annotated | `raw/aa_0051d2f0_Skill_CategoryCooldownMap_Insert.annotated.md` |
| Clean | `reconstructed-exact/Skill_CategoryCooldownMap_Insert.cpp` |
| Function record | `functions/aa_0051d2f0_Skill_CategoryCooldownMap_Insert.md` |
| Ghidra re-decompile | `0x0051d2f0` (2026-07-29) — body ≡ raw |
| Bytes | `read_memory` `0x0051d2f0`–`0x0051d3a8` (3× `C2 08 00`); node ctor `0x005ae220` (`push 0x1c`, color `+0x18`, isnil `+0x19`) |
| Callees | `0x0051c1c0` insert+rebalance; `0x005ae050` predecessor; `0x005ae220` node construct |
| Callers | `Skill_InsertCategoryCooldown` `0x00518df0`; `CVOGHBOKToCastAgain_ctor` `0x0051e240` |
| Consumers | `Skill_GetCategoryCooldownRemaining` `+0x10`/`+0x14`; `Skill_GetCategoryCooldownMap` shell `+0x6c` / size `0xc` |
| Residual scratch | `reviews/a_0051d2f0.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `__thiscall` + **`RET 0x8`** (2 stack dwords) | **High** | three epilogues `C2 08 00` |
| Signature `(map this, outPair*, entry*)` | **High** | prolog + callers |
| Out pair `{node* @+0, inserted @+4}` | **High** | `mov [eax],…` / `mov byte [eax+4],0/1` |
| Map shell `+4` head, `+8` size, size **0x0c** | **High** | GetMap + insert helper |
| Node size **0x1c**; key `+0x0C`, start `+0x10`, duration `+0x14`, color `+0x18`, isnil `+0x19` | **High** | `FUN_005ae220` + GetRemaining |
| Tree walk left/right by key | **High** | body CF ≡ raw ≡ bytes |
| New-key path: `FUN_0051c1c0` (+ node ctor) | **High** | callees + `"map/set<T> too long"` |
| `FUN_005ae050` = **predecessor**, not insert | **High** | body of `0x005ae050` |
| Equal key: **no** value write (`inserted=0`) | **High** | third ret path |
| Prior "insert/**update** writes fields" | **Falsified** | find-only on equal |
| Only two static callers | **High** | `get_xrefs_to` 2026-07-29 |
| Not player input poll | **High** | CD bookkeeping |
| Runtime / bit-exact | Open | matrix policy |

---

## 4. Control flow: clean ≡ raw ≡ asm

| Stage | Match |
|---|---|
| Head/root walk by key; isnil `+0x19` | **Yes** |
| goLeft + leftmost → insert flag 1 | **Yes** |
| goLeft + not leftmost → predecessor | **Yes** |
| parent.key < key → insert | **Yes** |
| else equal → out `{parent,0}` no mutate | **Yes** |
| `RET 0x8` all exits | **Yes** |
| No skill-grant / tooltip | **Yes** |

---

## 5. Asm-sealed signature + layouts

```c
struct CategoryCooldownEntry {
    int32_t  key;        // category id
    uint32_t startTick;  // g_dwClientTickMs at arm
    int32_t  durationMs;
};

struct CategoryCooldownNode { // size 0x1C
    CategoryCooldownNode* left;    // +0x00
    CategoryCooldownNode* parent;  // +0x04
    CategoryCooldownNode* right;   // +0x08
    int32_t  key;                  // +0x0C
    uint32_t startTick;            // +0x10
    int32_t  durationMs;           // +0x14
    uint8_t  color;                // +0x18
    uint8_t  isnil;                // +0x19
};

struct InsertPair {
    CategoryCooldownNode* it; // +0
    uint8_t inserted;         // +4
};

void __thiscall Skill_CategoryCooldownMap_Insert(
    void* thisMap,
    InsertPair* pOut,
    const CategoryCooldownEntry* pValue);
// RET 0x8
```

---

## 6. Gaps / open

1. Optional Ghidra/NAMING promote of helper product names (`Map_TreeInsertAndRebalance`, `Tree_Predecessor`, `CategoryCooldownMap_Node_Construct`) — **roles sealed**.
2. Runtime cast capture proving no equal-key refresh (implied by asm; not live-traced).
3. Server CD authority parity (out of unit).
4. Bit-exact / image diff (deferred).

**Verdict:** **accept-with-gaps** — ABI, out-pair, node **0x1c** layout, insert-or-find CF, helper roles, two callers **sealed High**; value-update-on-equal **falsified**; runtime/diff remain.
