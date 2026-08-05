# Annotated low-level: StdMap_LowerBound_Tfid_Isnil29 (FUN_004cb4b0)

| Field | Value |
|---|---|
| Stable ID | `aa_004cb4b0` |
| VA | `0x004cb4b0`–`0x004cb4eb` exclusive (**59 B** / `0x3B`) |
| Canonical name | `StdMap_LowerBound_Tfid_Isnil29` |
| Ghidra name | `FUN_004cb4b0` |
| System | MSVC `_Tree` / `map` lower_bound (TFID-shaped 8-byte key, isnil@+0x29) |
| Date | 2026-07-29 (W31-N re-verify; scaffold 2026-07-23) |

## Machine-level notes

- **Leaf** — no callees; pure walk.
- Entry: `MOV EAX,[ECX+4]` head; stack key ptr at `[ESP+4]`.
- isnil test: `CMP BYTE PTR [ECX+0x29],0` on nodes (`80 79 29 00`).
- Compare: signed hi (`[node+0x14]` vs `key[1]`), then unsigned lo (`[node+0x10]` vs `*key`).
- Epilogue: `POP EDI; POP ESI; RET 4`.
- Returns lower_bound **node*** (may be head/end). Does **not** gate equality — consumers (`004cba00`, `004c8970`, `004cc400`, `005a0470`) apply exact-match / insert.
- Key shape matches **TFID** lo/hi used by `Object_TFIDMapLookupOrRelatedMatch` (W30-T) and `TFID_EqualsObjectId`.
- Reject scaffold plate `Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_*`.

## Pseudocode (annotated)

```c
// ECX = map host (head@+4); stack pKey; RET 4; returns Node*
Node_Isnil29* __thiscall StdMap_LowerBound_Tfid_Isnil29(
    MapHost_Head4* self, const KeyU32I32* pKey)
{
  Node_Isnil29* head = self->head;
  Node_Isnil29* cand = head;
  Node_Isnil29* node = head->parent; // root
  if (node->isnil) return head;
  do {
    // search <= node.key  → left + remember
    if ((int)pKey->hi < (int)node->key_hi ||
        ((int)pKey->hi <= (int)node->key_hi && pKey->lo <= node->key_lo)) {
      cand = node;
      node = node->left;
    } else {
      node = node->right;
    }
  } while (!node->isnil);
  return cand;
}
```

## Callers (all map find/insert shells)

| Caller | Role |
|---|---|
| `FUN_004c8970` / Object_TFIDMapLookup… | map@`obj+0x154`; hit → `*(node+0x20)` |
| `FUN_004ca760` | same map; accumulate `+ *(node+0x20)` then insert path |
| `FUN_004cba00` | pure find: lower_bound + equality gate → out node or end |
| `FUN_004cc400` | insert-or-find; return `node+0x20` value slot |
| `FUN_005a0470` | map head@`this+0x248`; erase path via `FUN_00409220` |

## Open questions

- Product map type / value at `+0x20`.
- Whether all five callers share one map type or clones with same node layout.
- Runtime / bit-exact.
