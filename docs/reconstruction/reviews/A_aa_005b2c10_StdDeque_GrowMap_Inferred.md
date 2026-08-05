# Review A (reconstruction fidelity): `aa_005b2c10` StdDeque_GrowMap_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b2c10` |
| **VA** | `0x005b2c10` |
| **Body** | `0x005b2c10`–`0x005b2d63` |
| **Canonical name** | `StdDeque_GrowMap_Inferred` |
| **Ghidra name** | `FUN_005b2c10` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_005b2c10_StdDeque_GrowMap_Inferred.md` |
| **System** | util / container (MSVC deque map grow; twin of `aa_0051c3b0`) |
| **Live tools** | Ghidra `batch_decompile`, `read_memory`, caller `005b2d70`, throw `005b2a80` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Grow the block-pointer map** of an MSVC-style `std::deque` (map of block pointers — **not** the element data blocks).

```c
void __thiscall StdDeque_GrowMap_Inferred(Deque *this, uint growRequest);
```

| Offset | Role |
|---:|---|
| `+0x4` | `map` — pointer to array of block pointers |
| `+0x8` | `mapsize` — number of map slots |
| `+0xC` | `off` — element offset (`off>>2` = start block index for rotate) |

Algorithm (matches sealed twin `FUN_0051c3b0` / skill deferred-cast deque):

1. If `mapsize + grow` would exceed `0x0FFFFFFF` → `FUN_005b2a80()` — throws **`"deque<T> too long"`** (noreturn).
2. `prefer = max(mapsize >> 1, 8)`; if `growRequest < prefer` and no overflow, **raise grow to prefer**.
3. `operator_new((mapsize + grow) * 4)` new map.
4. **Rotate/copy** old map entries around `off>>2` so the front block index is preserved; zero-fill new pointer slots (two branches: grow < vs ≥ front index).
5. If old map null: `mapsize += grow`, install new map, return.
6. Else `operator_delete(old map)` — decompiler marks noreturn after delete (same hazard as twin).

**Sole live caller:** `FUN_005b2d70` with **`grow=1`** when push needs more map capacity (predicate: `(off+size) % 4 == 0` and mapsize tight).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Function record / raw / clean | `aa_005b2c10_*` |
| Live decompile | ≡ raw grow policy |
| Throw | `FUN_005b2a80` string **`"deque<T> too long"`** |
| Caller | `FUN_005b2d70` `0x005b2d70` — push element / alloc block |
| Twin dual | `A\|B_aa_0051c3b0_FUN_0051c3b0` (same algorithm, skill cast slot) |
| Body bytes | `read_memory 0x005b2c10` length 200 |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Deque family (string-sealed throw) | **Confirmed** | `"deque<T> too long"` |
| Grows **map of pointers**, not data blocks | **Confirmed** | `*4` pointer slots |
| Prefer grow `max(mapsize/2, 8)` | **Confirmed** | |
| Rotate around `off>>2` | **Confirmed** | memmove split |
| Zero new map slots | **Confirmed** | loops |
| Sole caller push path `005b2d70` | **Confirmed** | |
| Clean ≡ raw ≡ live CF | **Confirmed** | |
| Exact mangled `_Growmap` name | **Open** | `_Inferred` |
| Non-null free path mapsize write order | **Medium** | decomp noreturn hazard |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Overflow → throw helper | **Yes** |
| Prefer ≥ max(half, 8) | **Yes** |
| Alloc `(old+grow)*4` | **Yes** |
| Rotate memmoves + zero pad | **Yes** |
| Null-old: install + mapsize+=grow | **Yes** |
| Non-null: delete old | **Yes** (decomp) |

Not domain logic — pure container.

---

## 5. Relationship to twin `0x0051c3b0`

| | `0051c3b0` | `005b2c10` (this) |
|---|---|---|
| Role | deque map grow | deque map grow |
| Throw helper | `0051b5f0` | `005b2a80` |
| Caller domain | skill deferred cast ids | `005b2d70` push (object/net path) |
| Algorithm | same shape | same shape |

---

## 6. Gaps

1. Asm seal of mapsize update on non-null free path.
2. Element type of this deque instance (caller allocates `0x10` blocks of 4 dword slots).
3. Product C++ mangled name.

**Verdict:** **accept-with-gaps** — grow policy + deque identity High; free-path bookkeeping Medium residual.
