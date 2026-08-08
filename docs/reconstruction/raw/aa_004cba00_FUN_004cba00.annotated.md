# Annotated low-level: FUN_004cba00 / StdMap_Find_Tfid_Isnil29_Inferred

| Field | Value |
|---|---|
| Stable ID | `aa_004cba00` |
| VA | `0x004cba00`–`0x004cba51` (**82 B**) |
| System | STL map find / TFID-shaped key / isnil@+0x29 |
| Date | 2026-08-04 (WQ9G-G OWN) |
| Named | `StdMap_Find_Tfid_Isnil29_Inferred` |

## Machine-level notes

- Source: raw capture + WQ9G-G re-verify (`read_memory` full body, callers/xrefs, assembly_context).
- Prefer assembly when decompiler conflicts (none for CF here; ABI sealed by `RET 8`).
- Sole callee: dualed `StdMap_LowerBound_Tfid_Isnil29` (`0x004cb4b0`).
- Reject scaffold `Named_CalleeOf_Named_VOG_DEBUG_STOP_004cba00` as product identity.

## Semantics

MSVC-style **`map::find`** / `_Tree::find` over TFID-shaped `(u32 lo, i32 hi)` keys:

1. lower_bound via `FUN_004cb4b0` (no equality).
2. Hit only if `lb != head` **and** `!(key < lb.key)` i.e. `lb.key <= key` (hi signed@+0x14, lo@+0x10).
3. Write node* or head (end) to `*outIt`.

Does **not** insert, erase, or read payload `@+0x20` (callers do).

## Annotated pseudocode

```c
// ECX = map (head@+4); stack outIt*, pKey*; RET 8
void __thiscall StdMap_Find_Tfid_Isnil29_Inferred(Map* self, Node** outIt, const KeyU32I32* pKey)
{
  Node* lb = StdMap_LowerBound_Tfid_Isnil29(self, pKey); // FUN_004cb4b0
  Node* head = self->head; // +4
  if (lb != head) {
    // node.key <= *pKey  (after lower_bound ⇒ equality)
    if (lb->key_hi <= pKey->hi &&
        (lb->key_hi < pKey->hi || lb->key_lo <= pKey->lo)) {
      *outIt = lb;
      return;
    }
  }
  *outIt = head; // end / miss
}
```

## Call sites (evidence)

- `FUN_004ea350` ×3 — map embed near +0x164 relative shells.
- `FUN_00807550` — host map `@+0x244`, TFID key `@+0x160`, then `node[+0x20]` payload.
- `0x005dd84d` — find then optional insert `0x004cc400`.

## Open residual

- Product / PDB map value_type (payload @+0x20).
- Parent English for `FUN_004ea350` / ghost assign path.
- Runtime / bit-exact / differential.
