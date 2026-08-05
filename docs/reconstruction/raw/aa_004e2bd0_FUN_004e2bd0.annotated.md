# Annotated low-level: FUN_004e2bd0 → CNDHash_ReclaimAll_ValueOwning_009cb360

| Field | Value |
|---|---|
| Stable ID | `aa_004e2bd0` |
| VA | `0x004e2bd0`–`0x004e2c2e` exclusive (**94 B** / `0x5E`) |
| System | container / CNDHash (node freelist stamp `009cb360`) |
| Date | 2026-07-23 scaffold; **2026-08-04 W37-J dual seal** |
| Canonical name | `CNDHash_ReclaimAll_ValueOwning_009cb360` |

## Machine-level notes

- Source: raw capture + live `read_memory` / decompile (W37-J).
- **No** `disassemble_bytes`; CF reconstructed from decompile ≡ bytes.
- This is the **owning reclaim** callee of FreeBuckets `004bcca0` (W31-M).
- Twin: `FUN_004bcae0` @ `0x004bcae0` (node stamp `009cb358`; value@+8 / next@+C) — W37-G.

## ABI

```
__thiscall void CNDHash_ReclaimAll_ValueOwning_009cb360(CNDHash *this);
// ECX=this → EBX; plain ret; void
```

## Pseudocode (annotated)

```c
// Reclaim every live node in buckets[0..mask] onto freelist(+0x20).
// Destroys owned values via scalar-deleting vcall (arg 1) at node+0xC.
// Does NOT zero count(+0xC), free table(+0x10), or free freelist storage.
void __thiscall CNDHash_ReclaimAll_ValueOwning_009cb360(CNDHash *hash)
{
  uint i = 0;
  do {
    Node *node = *(Node **)(*(int *)(hash->buckets + i * 4) + 4); // chain head
    while (node != NULL) {
      Node *next = node->chainNext;           // +0x10
      node->vtbl = &PTR_FUN_009cb360;         // freelist-class stamp
      if (node->value != NULL) {              // +0x0C
        (*node->value->vtbl)(node->value, 1); // deleting destroy
      }
      node->value = NULL;
      node->freelistNext = hash->freelist;    // *node = freelist
      hash->freelist = node;                  // +0x20
      node = next;
    }
    *(Node **)(*(int *)(hash->buckets + i * 4) + 4) = NULL; // clear head
    i++;
  } while (i <= hash->mask); // +0x08 inclusive
}
```

## Layout

| Off | Role |
|---:|---|
| hash+0x08 | mask |
| hash+0x10 | buckets* |
| hash+0x20 | freelist |
| bucket+0x04 | chain head |
| node+0x00 | vtbl / freelist link |
| node+0x0C | owned value* |
| node+0x10 | chain next |

## Callers / callees

| Dir | Symbol | Note |
|---|---|---|
| Caller | `CNDHash_FreeBuckets_009cb45c` `0x004bcca0` @ `0x004bccaa` | sole static xref |
| Callee | virtual `(*value_vtbl)(1)` | owned payload delete |

## Open questions

- Product/PDB English beyond structural ReclaimAll / ValueOwning role.
- Exact C++ type of owned value payloads under stamp `009cb360`.
- Runtime / bit-exact / differential.
