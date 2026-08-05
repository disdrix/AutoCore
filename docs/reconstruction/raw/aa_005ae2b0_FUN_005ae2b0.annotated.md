# Annotated low-level: FUN_005ae2b0

| Field | Value |
|---|---|
| Stable ID | `aa_005ae2b0` |
| VA | `0x005ae2b0` |
| System | util / container (MSVC `_Tree` head/node alloc) |
| Date | 2026-07-29 (W16-G dual seal) |
| Structural name | `StdTree_AllocNode_0x1c_Inferred` |

---

## Machine-level notes

- Source: raw capture for `aa_005ae2b0` + live `decompile_function` + `read_memory` (2026-07-29).
- **Role:** allocate a **0x1C-byte** red-black tree node and zero-init the three link pointers + color/isnil trailer. Used as both **head/sentinel** factory (callers self-link + set isnil=1) and generic **node shell** for maps whose value footprint fits in the middle of the 0x1C block.
- **Sibling size family:** `FUN_005ae270` is the same pattern for **0x24** nodes (color `@+0x20`, isnil `@+0x21`). `MapFloatTfid_AllocNode` (`0x0058d9c0`) is 0x30 with color `@+0x28`.
- Decompiler `void` return is **wrong** — EAX leaves as `operator_new` result; every inspected caller assigns it.

### Node layout (0x1C)

| Offset | Field (MSVC `_Tree_node` style) |
|---|---|
| `+0x00` | left*  (zeroed) |
| `+0x04` | parent* (zeroed) |
| `+0x08` | right* (zeroed) |
| `+0x0C`..`+0x17` | value payload region (**not** written here; 12 bytes) |
| `+0x18` | color (`1` = black) |
| `+0x19` | isnil (`0` here; head ctors set `1`) |
| `+0x1A`..`+0x1B` | pad / unused by this unit |

### Head construction pattern (callers)

```text
head = FUN_005ae2b0();          // EAX
*(u8*)(head + 0x19) = 1;        // isnil = true
*(head+4) = head; *head = head; *(head+8) = head;  // L/P/R self
map.size = 0;                   // typically host+8
```

Seen in: `InventoryGrid_ctor_Inferred` (`+0x60` tree), `Skill_GetCategoryCooldownMap` (lazy map@`+0x6c`), `FUN_004e7420` (map object ctor), plus other xrefs.

### ABI

| Slot | Role |
|---|---|
| args | none |
| **EAX out** | node* (0x1C) — decompiler wrongly shows void |
| return | plain `C3` |

### Null / OOM note

If `operator_new` returns NULL, the three zero-stores are skipped, but the final `mov byte [eax+0x18/19]` still execute → crash on OOM. Same artifact as sibling alloc nodes; retail assumes new succeeds or aborts earlier.

---

## Pseudocode (annotated)

```c
// Returns node* in EAX (decompiler: void)
undefined4 *FUN_005ae2b0(void)
{
  undefined4 *puVar1 = operator_new(0x1c);
  if (puVar1 != 0) {
    *puVar1 = 0;           // left
  }
  if (puVar1 + 1 != 0) {   // always true if base non-null; MSVC null-check pattern
    puVar1[1] = 0;         // parent
  }
  if (puVar1 + 2 != 0) {
    puVar1[2] = 0;         // right
  }
  *(undefined1 *)(puVar1 + 6) = 1;              // +0x18 color = black
  *(undefined1 *)((int)puVar1 + 0x19) = 0;      // isnil = false
  return puVar1; // EAX
}
```

---

## Open questions

- Exact `value_type` per caller (12-byte middle) — domain-specific; not sealed at this VA.
- Whether any caller uses this as a non-head live node without further value construction.
- Product allocator / `_Tree` typedef name.
