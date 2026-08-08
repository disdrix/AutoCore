# Annotated low-level: FUN_005a2de0 → StdTree_Buynode_Isnil29_Val24_Inferred

| Field | Value |
|---|---|
| Stable ID | `aa_005a2de0` |
| VA | `0x005a2de0`–`0x005a2e3a` (**91 B**) |
| System | std red-black tree / map node buy (isnil@+0x29 family) |
| Date | 2026-07-23 scaffold; **2026-08-04 WQ9F-A dual** |
| Canonical | `StdTree_Buynode_Isnil29_Val24_Inferred` |

## Machine-level notes

- **ABI:** MSVC **`__stdcall`**, five stack args, **`ret 0x14`**, **EAX** = new node* (null on OOM).
- **Size:** `operator_new(0x30)`.
- **Fields:** left=arg0, parent=arg1, right=arg2; copy **6 dwords** from value* to `node+0x10`; color=arg4 @ `+0x28`; **isnil=0** @ `+0x29`.
- **Does not write** `node+0x0c` (gap between right and value payload).
- Insert callers always pass **color=0** (red) and head as left/right seed (`FUN_004cbb60` / twins).
- Peer contrast: `StdTree_Buynode_Val12` `0x005ae220` (node 0x1c, value 3 dwords, isnil@+0x19) — **do not merge**.
- Prior scaffold name `Named_CalleeOf_…_Skill_GatherTarget` **narrow** — product path is generic map buynode for isnil29 trees, not skill gather.

## Pseudocode (annotated)

```c
// Node* __stdcall StdTree_Buynode_Isnil29_Val24_Inferred(
//   Node* left, Node* parent, Node* right, const uint32_t value6[6], uint8_t color)
void /* actually Node* in EAX */ FUN_005a2de0(
    undefined4 left, undefined4 parent, undefined4 right,
    undefined4 *value6, undefined1 color)
{
  undefined4 *node = operator_new(0x30);
  if (node != 0) {
    *node = left;                 // +0x00
    node[1] = parent;             // +0x04
    node[2] = right;              // +0x08
    // +0x0c untouched
    node[4] = value6[0];          // +0x10
    node[5] = value6[1];
    node[6] = value6[2];
    node[7] = value6[3];
    node[8] = value6[4];
    node[9] = value6[5];          // +0x24
    *(undefined1 *)(node + 10) = color;          // +0x28
    *(undefined1 *)((int)node + 0x29) = 0;       // isnil
  }
  // ret 0x14; EAX = node (0 if OOM)
}
```

## Open questions

- Product/MSVC demangle for value_type (6 dwords / 24 B).
- Exact key vs mapped field split inside Val24.
- Runtime / bit-exact open.
