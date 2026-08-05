# Annotated low-level: CNDHash_ReclaimToFreelist_009cb450 (`FUN_004bcae0`)

| Field | Value |
|---|---|
| Stable ID | `aa_004bcae0` |
| VA | `0x004bcae0`–`0x004bcb3e` inclusive (**95 B** / `0x5F`) |
| System | container / CNDHash (object family `009cb450` / tableC) |
| Date | 2026-08-04 (W37-G re-annotate) |
| Canonical | `CNDHash_ReclaimToFreelist_009cb450` |
| Ghidra | `FUN_004bcae0` |

## Machine-level notes

- **ABI:** **ECX=`hash*`** (`MOV EBX,ECX`); bare **`RET`** (`C3`); void.
- **No static callees** — value destroy is **virtual** `(*vtbl)(1)` on `node+0x8`.
- **Sole caller:** `CNDHash_FreeBuckets_009cb450` (`0x004bcc60`, W31-M) — zero count then this then free slab/table.
- **Twin (not owned; W37-J):** `FUN_004e2bd0` for family `009cb45c` — value @ `+0xC`, next @ `+0x10`, stamp `009cb360`.

## Layout (hash + node)

| Off | Field | Role here |
|----:|---|---|
| hash `+0x08` | mask | loop `i = 0 … mask` inclusive |
| hash `+0x10` | buckets* | `buckets[i]` → bucket object; chain head at `bucket+4` |
| hash `+0x20` | freelist head | nodes pushed here (intrusive) |
| node `+0x00` | link / stamp | stamp `PTR_FUN_009cb358` then freelist next |
| node `+0x08` | value* | owned payload; vtbl(1) if non-null; then null |
| node `+0x0C` | next | bucket chain |

## Pseudocode (annotated)

```c
// __thiscall / __fastcall(ECX)  bare RET  void
void CNDHash_ReclaimToFreelist_009cb450(CNDHash *hash /*ECX*/)
{
  uint32_t i = 0;
  do {
    // bucket = *(hash->buckets + i);  head = bucket->chain (+4)
    Node *node = *(Node**)(*(uint8_t**)((char*)hash + 0x10)[i] /* +0 */ + 4);
    while (node != nullptr) {
      Node *next = *(Node**)((char*)node + 0x0C);   // node[3]
      *(void**)node = &PTR_FUN_009cb358;            // stamp before destroy
      void *value = *(void**)((char*)node + 0x08);  // node[2]
      if (value != nullptr) {
        (**(void(***)(int))value)(1);               // scalar-deleting dtor
      }
      *(void**)((char*)node + 0x08) = nullptr;
      *(void**)node = *(void**)((char*)hash + 0x20); // freelist push
      *(void**)((char*)hash + 0x20) = node;
      node = next;
    }
    // clear this bucket's chain head
    void *bucket = ((void**)(*(void**)((char*)hash + 0x10)))[i];
    *(void**)((char*)bucket + 4) = nullptr;
    ++i;
  } while (i <= *(uint32_t*)((char*)hash + 0x08));
}
```

## Twin diff (vs `FUN_004e2bd0`)

| Site | `004bcae0` (this) | `004e2bd0` (twin) |
|---|---|---|
| Node stamp | `009cb358` | `009cb360` |
| Value slot | `node+0x08` | `node+0x0C` |
| Next slot | `node+0x0C` | `node+0x10` |
| FreeBuckets parent | `004bcc60` / `009cb450` | `004bcca0` / `009cb45c` |

## Open questions

- Product/PDB English for value type destroyed via vtbl(1).
- Whether freelist nodes retain stamp only transiently (yes — overwritten by freelist next).
- Runtime / bit-exact / differential.
