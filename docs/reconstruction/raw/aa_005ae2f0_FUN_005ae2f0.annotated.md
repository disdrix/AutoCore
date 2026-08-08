# Annotated low-level: FUN_005ae2f0 → StdTree_InsertAndRebalance_Val20_Isnil21_Inferred

| Field | Value |
|---|---|
| Stable ID | `aa_005ae2f0` |
| VA | `0x005ae2f0`–`0x005ae4da` inclusive (**491** B) |
| System | skills-abilities / STL map-set helpers (Val20 / isnil@+0x21) |
| Date | 2026-08-05 (R12-034 OWN dual; raw 2026-07-23) |
| Canonical name | `StdTree_InsertAndRebalance_Val20_Isnil21_Inferred` |

## Machine-level notes

- Source: raw capture + R12-034 live re-verify (`decompile_function`, `analyze_function_complete`, callers/xrefs, `read_memory`).
- **Role:** MSVC `_Tree` **always-insert** + red-black rebalance for **Val20** nodes (node size **0x24**).
- **Layout:** left@+0, parent@+4, right@+8, value 5×dword @+0x0C..+0x1C, color@**+0x20**, isnil@**+0x21**.
- **Map shell:** +0x04 head sentinel; +0x08 size.
- **ABI:** `__thiscall` ECX=map; stack `(Node** out, char addLeft, Node* where, const Val20* value)`; **`ret 0x10`**.
- **Size gate:** `cmp [map+8], 0xCCCCCCB` / `jb` ok → throw `"map/set<T> too long"` when `size >= 0xCCCCCCB` (MSVC `max_size()-1` for 20-byte value: `0xFFFFFFFF/0x14 - 1`).
- **Buynode:** `FUN_005ae1c0` — `operator_new(0x24)`, copies 5 dwords, color arg, isnil=0.
- **Rotates:** shared isnil21 leaves — `FUN_0050e9f0` Lrotate, `FUN_005a27f0` Rrotate (also used by Val16 InsertAndRebalance `00407200`). One Lrotate path is **inlined** (isnil@+0x21 test in body).
- **Sole caller:** `FUN_005aec50` insert-or-find (composite int key at value[0]/value[1]).
- **Do not merge** with Val12 insert `005ae4e0` (adjacent; different max/buynode/rotates) or Val16 insert `00407200` (different max/buynode/node size).
- Prefer bytes when decompiler conflicts; product demangle open → `_Inferred`.

## Pseudocode (annotated)

```c
// __thiscall ECX = map*; RET 0x10
void __thiscall
StdTree_InsertAndRebalance_Val20_Isnil21_Inferred(
    int map,                 // +4 head, +8 size
    undefined4 *outIt,       // *outIt = new node
    char addLeft,            // 1 left of where; 0 right
    undefined4 *where,       // parent or head
    undefined4 value)        // Val20* (5 dwords)
{
  // SEH: LAB_009a65a2
  if (0xcccccca < *(uint *)(map + 8)) {  // size >= 0xCCCCCCB
    // basic_string("map/set<T> too long") + length_error + _CxxThrowException
    _CxxThrowException(...);
  }
  // buynode node 0x24, color=red(0), isnil=0
  n = FUN_005ae1c0(head, where, head, value, 0);
  size++;
  // link first | right | left (+ leftmost/rightmost on head)
  // RB while parent color@+0x20 == red:
  //   uncle recolor OR Lrotate(0050e9f0)/Rrotate(005a27f0)/inline L
  // root black; *outIt = n
}
```

Full decompiler body remains authority in raw `aa_005ae2f0_FUN_005ae2f0.md`.

## Open questions

- Product / MSVC demangle for the map value_type (5-dword payload; caller keys first 2 ints).
- Buynode null OOM path (decomp returns null unchecked — same pattern as peer inserts).
- Runtime / bit-exact / differential — open (Terminal false).
