# Review A (reconstruction fidelity): `aa_0054de50` SkillElementTypeMap_TreeInsertAndRebalance

| Field | Value |
|---|---|
| **Stable ID** | `aa_0054de50` |
| **VA** | `0x0054de50` |
| **Body** | `0x0054de50`–`0x0054e03a` |
| **Canonical name** | `SkillElementTypeMap_TreeInsertAndRebalance` (Ghidra `FUN_0054de50`; **Inferred**) |
| **Review date** | `2026-07-29` (W20-B OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_0054de50_SkillElementTypeMap_TreeInsertAndRebalance.md` |
| **System** | `skills-abilities` (skill-element type factory catalog map) |
| **Live tools** | Ghidra `decompile_function`, `read_memory`, `get_function_by_address`, `get_function_callers`, `get_function_callees`, `get_xrefs_to` (no `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

MSVC-style **`std::_Tree` always-insert + red-black rebalance** for the **0x18-node** int-keyed map whose mapped value is a **pointer** (skill-element type id → factory instance*).

```
*outIt = SkillElementTypeMap_TreeInsertAndRebalance(map, addLeft, where, value)
// __thiscall; this = map shell; RET 0x10 (four stack dwords)
```

1. If `map->size > 0x1ffffffd` → throw with string **`"map/set<T> too long"`**.
2. `FUN_006173a0(head, where, head, value, color=0)` → `operator_new(0x18)`, copy **2 dwords** @ `+0x0C`, color `+0x14=0` (red), isnil `+0x15=0`.
3. `size++` at `map+8`.
4. Link under `where` (first / left / right + leftmost/rightmost head updates).
5. RB fixup while parent color red; root painted black; `*outIt = newNode`.

**Not** insert-or-find: parent `SkillElementTypeMap_InsertOrFind` (`0x0054eb20`) owns key walk and only calls this on miss (×2 sites).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0054de50_FUN_0054de50.md` (+ 2026-07-29 re-verify) |
| Annotated | `docs/reconstruction/raw/aa_0054de50_FUN_0054de50.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/SkillElementTypeMap_TreeInsertAndRebalance.cpp` |
| Clean FUN_* | `docs/reconstruction/reconstructed-exact/FUN_0054de50.cpp` |
| Function record | `docs/reconstruction/functions/aa_0054de50_SkillElementTypeMap_TreeInsertAndRebalance.md` |
| Live decompile | Ghidra @ `0x0054de50` ≡ raw 2026-07-23 CF |
| Bytes | prologue size cmp + string push; epilogue `C2 10 00`; string @ `0x00a1530c` |
| Node ctor | `FUN_006173a0` — `new(0x18)`, color/isnil layout |
| Parent dual | `A/B_aa_0054eb20_SkillElementTypeMap_InsertOrFind` |
| Callers | sole static `FUN_0054eb20` @ `0x0054eb79`, `0x0054ebb0` |

**Not performed:** `disassemble_bytes`, Launcher, runtime capture, binary diff.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `__thiscall` + **`RET 0x10`** (4 stack dwords) | **Confirmed** | epilogue `C2 10 00`; ECX→EDI |
| Always allocates (no key compare) | **Confirmed** | always `FUN_006173a0` + size++ |
| Max size throw `"map/set<T> too long"` | **Confirmed** | `cmp [edi+8],0x1ffffffd`; string @ `0x00a1530c` |
| Map head `this+4`, size `this+8` | **Confirmed** | body |
| Node **0x18**; value **2 dwords** @ `+0x0C` | **Confirmed** | ctor `new(0x18)` + two dword stores |
| color `+0x14`, isnil `+0x15`, 0=red / 1=black | **Confirmed** | ctor + rebalance loop |
| Left `*node`, parent `+4`, right `+8` | **Confirmed** | link + rotate paths |
| Head leftmost/root/rightmost convention | **High** | first-node + extremum updates |
| `FUN_004e22d0` / `FUN_006753b0` = rotates | **High** | call sites in rebalance; product English open |
| Inlined left-rotate path (isnil `+0x15`) | **High** | decompile else-branch |
| Sole static caller `0x0054eb20` | **Confirmed** | xrefs / callers |
| Domain: skill-element type factory map | **High** | parent dual + catalog register |
| Product STL / RTTI name | **Open** | no PDB |
| Runtime / bit-exact image diff | **Open** | matrix policy |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Size check → throw | Yes |
| Node construct color red | Yes |
| size++ | Yes |
| Link first / right / left + head extrema | Yes |
| RB loop parent color | Yes |
| Uncle recolor / rotate cases | Yes |
| Inlined L-rotate on grandparent | Yes |
| Root black + `*outIt` | Yes |
| `RET 0x10` | Yes |

---

## 5. Sealed layouts

```
MapShell
  +0x04  head / end sentinel*
  +0x08  size (u32); throw if > 0x1ffffffd

MapNode_IntPtr  // size 0x18 (FUN_006173a0)
  +0x00  left*
  +0x04  parent*
  +0x08  right*
  +0x0C  key (int)
  +0x10  mapped*
  +0x14  color (u8): 0=red, 1=black
  +0x15  isnil (u8)

// ABI
// void __thiscall SkillElementTypeMap_TreeInsertAndRebalance(
//     MapShell* map, Node** outIt, char addLeft, Node* where, const IntPtrPair* value);
// RET 0x10
```

### Callers

| Caller | Sites | Role |
|---|---|---|
| `SkillElementTypeMap_InsertOrFind` | 2 in `0x0054eb20` | Miss path only |

No other static xrefs in image (this dual pass).

---

## 6. Gaps / open

1. Product / RTTI name for the map / insert method.
2. Product English for rotate helpers `FUN_004e22d0` / `FUN_006753b0` (roles sealed).
3. Full dual of node ctor `FUN_006173a0` (body sealed here as callee only).
4. Dynamic/fn-ptr call sites residual.
5. Runtime / bit-exact image diff (deferred).

**Verdict:** **accept-with-gaps** — ABI, always-insert CF, node **0x18** layout, size cap + throw string, sole catalog insert parent, RB color convention **sealed High/Confirmed**; product English + runtime/diff remain.
