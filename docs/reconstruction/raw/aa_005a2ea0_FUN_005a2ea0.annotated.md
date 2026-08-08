# Annotated low-level: FUN_005a2ea0 → StdTree_EraseAndRebalance_Isnil21_Inferred

| Field | Value |
|---|---|
| Stable ID | `aa_005a2ea0` |
| VA | `0x005a2ea0`–`0x005a3155` inclusive (**694 B** / `0x2B6`) |
| System | skills-abilities / STL map-set helpers (isnil@+0x21 family) |
| Date | 2026-08-05 (R12-030 OWN dual; scaffold 2026-07-23) |
| Canonical name | `StdTree_EraseAndRebalance_Isnil21_Inferred` |
| Parent dual | `0x005a27f0` StdTree_Rrotate_Isnil21_Inferred (R11-007) |
| Terminal | **false** |

## Machine-level notes

- Source: raw capture + R12-030 live re-verify.
- Prefer assembly / `read_memory` when decompiler conflicts (false noreturn on `operator_delete`; missing size-- / `*outIt` / `ret 8`).
- Layout: color@**+0x20**, isnil@**+0x21**, node **0x28**, head@map+4, size@map+8.
- ABI: `__thiscall` ECX=map; two stack args; **`ret 8`**.
- Role: single-node MSVC `_Tree::erase(const_iterator)` — not range, not insert, not Val12/isnil29.

## Algorithm (annotated)

1. **SEH** frame (`LAB_009a6342`); `EBP = ECX` (map).
2. If `node->isnil (+0x21) != 0` → throw `"invalid map/set<T> iterator"` via `DAT_00acc34c`.
3. **`FUN_004e12c0`** — advance out-iterator / capture successor (isnil21 nextnode).
4. **Splice** replacement child; reattach parent/root; fix head leftmost (`FUN_004cb2c0`) / rightmost (`FUN_00421a60`).
5. Decompiler "unreachable" blocks in mid-body are the **two-child successor-swap** plate (live in asm; same family as peer erase clones).
6. If erased **color black** (`+0x20 == 1`) → RB fixup with **Lrotate `0050e9f0`** / **Rrotate `005a27f0`**.
7. **`operator_delete(node)`** only (no value dtor / no secondary heap free in this body).
8. **Byte-sealed:** if size>0 then `--size`; `*outIt = successor`; `ADD ESP,0x54`; **`RET 8`**.

## Call sites

| Site | Notes |
|---|---|
| `FUN_005a3860` @ `005a38ff` | EraseRange while begin≠end; `MOV ECX,EDI`; parent `ret 0xC` |
| Orphan @ `005a052b` | Unrecovered function body (~`005a04d0`–`005a053d`); `MOV ECX,EDI`; parent `ret 4`; DATA slot `009d7f0c` |

## Pseudocode (annotated copy of raw + epilogue correction)

```c
// __thiscall  RET 8
void StdTree_EraseAndRebalance_Isnil21_Inferred(
    /*ECX*/ MapShell_Isnil21 *map,
    MapNode_Isnil21 **outIt,
    MapNode_Isnil21 *node)
{
  // SEH omitted
  if (node->isnil != 0)
    throw invalid_map_set_iterator; // "invalid map/set<T> iterator"

  FUN_004e12c0(/* successor prep on out-it / node shadow */);

  // unlink + extremity fix (min 004cb2c0 / max 00421a60)
  // if erased black: RB with 0050e9f0 / 005a27f0
  // (see raw for full splice/RB CF; two-child swap in "unreachable" blocks)

  operator_delete(node);
  if (map->size > 0) map->size -= 1;
  *outIt = successor; // sealed in epilogue bytes
  // ret 8
}
```

## Open questions

- Product demangle for map `value_type` of `FUN_005a3860` / orphan host.
- Full recovery of orphan function at `005a04d0` (vtable/data `009d7f0c`).
- Runtime / bit-exact / differential.
