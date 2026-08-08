# Annotated: FUN_004cbe20 → StdMap_InsertOrFind_IntKey_Isnil29_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cbe20` |
| **VA** | `0x004cbe20` |
| **Named** | `StdMap_InsertOrFind_IntKey_Isnil29_Inferred` |
| **Ghidra** | `FUN_004cbe20` |
| **Agent** | WQ9F-D 2026-08-04 |
| **Companion raw** | `aa_004cbe20_FUN_004cbe20.md` |

---

## Role

MSVC-style **`std::map` insert-or-find** (unique key) for the **isnil@+0x29** tree family. Walks from root with **signed int** key at value dword0 / node **+0x10**. On miss, always-insert via dualed `StdTree_InsertAndRebalance_Isnil29_Inferred` (`0x004cbb60`). On hit, returns existing iterator with **inserted=0** and **does not** rewrite mapped fields.

Not skill product logic — shared container helper used by skill active-cast binding insert (`0x00518ca0`) and a rebuild walk (`0x004c9380`).

---

## ABI / layout

| Item | Value |
|---|---|
| Convention | `__thiscall` |
| ECX | map shell* (`head` @ +4, `size` @ +8) |
| Stack +4 | `InsertPair*` — `{ Node* it; bool inserted; }` (inserted as byte at out+4) |
| Stack +8 | `const Val*` — key at `*value` (int32); remainder is mapped payload for insert |
| Return | void (out via pair*); **RET 8** |
| Node | left+0 parent+4 right+8; value@+0x10 (6 dwords for insert buynode); color+0x28; isnil+0x29; size **0x30** |

---

## Control flow (annotated)

1. **Load head** `map->head`; **root** = `head->parent` (head[1]).
2. **Empty / nil root:** if `root->isnil` skip walk; `addLeft=true`, where=head.
3. **Lower-bound walk** while child not nil:
   - `goLeft = (key < node.key)` **signed** (`SETL`)
   - left child if goLeft else right
4. **If goLeft:**
   - if where == leftmost (`*head`): **insert** addLeft=1 under where → out `{new,1}`
   - else **predecessor** `FUN_004cb4f0(&where)` then fall through
5. **If where.key < key** (signed): **insert** with current addLeft → out `{new,1}`
6. **Else equal:** out `{where, 0}` — **no** mapped rewrite

---

## Callees

| VA | Role |
|---|---|
| `0x004cbb60` | `StdTree_InsertAndRebalance_Isnil29_Inferred` — always-insert + RB |
| `0x004cb4f0` | Tree predecessor (iterator --); residual undualed here |

---

## Callers

| Caller | Site | Note |
|---|---|---|
| `FUN_004c9380` | `0x004c93d1` | Rebuild/copy into this map family |
| `FUN_00518ca0` | `0x00518cda` | `Skill_InsertActiveCastBinding_Inferred` packs Val then insert-or-find |

---

## Reject / narrow

- Scaffold **GetTargetFromAggro** Named_CalleeOf product alias — generic STL map helper only.
- Not always-insert: equal key path is live.
- Not Val12 / isnil@+0x19 family.
- Not erase / range helpers.
