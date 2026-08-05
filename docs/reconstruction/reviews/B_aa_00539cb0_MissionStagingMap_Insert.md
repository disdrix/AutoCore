# Review B (skeptical / adversarial): `aa_00539cb0` Mission staging map insert

| Field | Value |
|---|---|
| **Stable ID** | `aa_00539cb0` |
| **VA** | `0x00539cb0` |
| **Canonical name** | `FUN_00539cb0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Adversarial dual (attack over-claims) |
| **Counterpart** | `reviews/A_aa_00539cb0_MissionStagingMap_Insert.md` |
| **System** | `missions-progression` |
| **Verdict** | **accept-with-gaps** on shape; **reject** upsert-on-equal, product name, and non-map roles |

---

## 1. What this is *not*

| Attack | Result |
|---|---|
| “Mission eligibility / GiveMission” | **Falsified** — pure tree insert-or-find; no def/prereq reads |
| “Always allocates a new node” | **Falsified** — equal key returns `{parent, inserted=0}` |
| “Insert **updates** payload when key exists” | **Falsified** — equal path has no stores to `+0x10..+0x47`; parent `FUN_0052c700` overwrites payload **before** calling insert only on lower_bound **miss** (hit path copies in-place without this unit) |
| “`FUN_00537770` is tree insert / rebalance” | **Falsified** — predecessor only (`0x00537770` body) |
| “Node size unknown / small CD-map node” | **Falsified** — `FUN_005380d0` `new(0x50)`; not the 0x1C category-CD node |
| “Many callers / shared generic insert for all maps” | **Partial** — **this** VA is specialized (isnil `+0x49`, key `+0x10`, value 14 dwords); static xrefs = only `FUN_0052c700`. Other maps use sibling insert VAs |
| “`void` / no out pair” | **Falsified** — writes `*out` + `out+4`; three `RET 8` |
| Product name `std::map::insert` as export | **Unproven** — structure is MSVC map-like; no PDB string for this instance |

---

## 2. Decompiler hazards corrected by dual

| Decomp artifact | Reality |
|---|---|
| `FUN_00537770()` with no args | Asm: `LEA ECX,[esp+…]` then call — **`__fastcall` iterator\*** (predecessor) |
| `FUN_00538ea0(&param_3, …)` first arg looks like out-it only | Full ABI: `(map this, outIt*, addLeft, where, valuePair*)` — this unit passes `ECX=map` |
| `void` return type | No value in EAX required by thiscall void; **out-param** is the contract (parent may ignore inserted flag) |
| Scaffold clean listed “FUN_00539cb0” as callee of itself | **False** — no recursion; callees are `FUN_00538ea0` ×2 and `FUN_00537770` |

---

## 3. Layout challenges

| Challenge | Response | CF |
|---|---|---|
| Is value really 12-dword staging payload? | Parent dual sealed `REP MOVSD` ECX=0xC to `node+0x18`; ctor copies 14 dwords from pair = key+pad+12 | **High** |
| Is `+0x14` part of key (64-bit)? | Compares use **one** dword at `+0x10` only; parent forces mission key as u32 | **High** single-int key |
| Is color/isnil swapped? | ctor: color `*(node+0x12 dword)= +0x48`, isnil `+0x49`; rebalance reads `+0x48` as color | **High** |
| Map object only `+4` head? | Size at `+8` proven in insert helper max-check / increment | **High** |

---

## 4. Surviving contract (minimal)

```
// thiscall on staging MapShell (Character+0x508)
void MissionStagingMap_Insert(
    MapShell* map,
    InsertOutPair* out,          // { node*, inserted }
    const StagingValuePair* v);  // 14 dwords: key, pad, payload[12]
// RET 8
//
// Behavior: insert-or-find by key @ v->key / node+0x10
//   miss → FUN_005380d0 new(0x50) via FUN_00538ea0; rebalance; out.inserted=1
//   hit  → out.it=existing; out.inserted=0; payload UNCHANGED
//
// Do NOT use this unit for equal-key payload refresh — parent hit path
// overwrites node+0x18 without calling insert.
```

---

## 5. Cross-check vs dual A

| A claim | B stance |
|---|---|
| `RET 8` + out pair | **Agree** |
| Key `+0x10`, isnil `+0x49`, color `+0x48` | **Agree** |
| Node `0x50`, 14-dword value block | **Agree** |
| Insert-or-find, no equal overwrite | **Agree** — critical for not mis-porting as upsert |
| Sole caller `FUN_0052c700` | **Agree** (static) |
| Product English open | **Agree** — keep open |
| Helper roles High | **Agree** roles; English names Tentative |

---

## 6. Residual (honest)

1. Product / export / typedef name.
2. Exact English for pad dword `+0x14`.
3. Runtime multi-mission insert capture (size@`map+8`).
4. Bit-exact image diff.
5. Whether head node at `map+4` is fully typed (leftmost/rightmost/parent links) — shape used by insert helper, not re-proven here beyond call sites.

---

## 7. Verdict

### **accept-with-gaps**

ABI, CF, node geometry, helper roles, and insert-or-find (not insert-or-assign) are **sealed**. Reject eligibility/dialog claims, equal-key value update, and mis-role of predecessor as insert. Dual A layout table is acceptable with product name open.
