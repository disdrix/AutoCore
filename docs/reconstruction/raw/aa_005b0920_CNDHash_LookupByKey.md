# Raw capture: CNDHash_LookupByKey

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b0920` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005b0920` |
| **Body** | `0x005b0920`–`0x005b0953` |
| **Canonical name** | `CNDHash_LookupByKey` |
| **System** | shared CNDHash container |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* Generic CNDHash lookup by key. Returns value pointer or NULL.
   Used for USContinentUnlocked hash (character+0x534 / secondary-0x86c). */

void * __thiscall CNDHash_LookupByKey(void *this,uint key)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(*(int *)((int)this + 0x10) + (*(uint *)((int)this + 8) & key) * 4) + 4);
  if (iVar1 != 0) {
    while (key != *(uint *)(iVar1 + 0x10)) {
      iVar1 = *(int *)(iVar1 + 0xc);
      if (iVar1 == 0) {
        return (void *)0x0;
      }
    }
    if (iVar1 != 0) {
      return *(void **)(iVar1 + 8);
    }
  }
  return (void *)0x0;
}
```

---

## Residual 2026-07-29 (dual A/B seal)

**Tools:** `decompile_function` `0x005b0920`, `read_memory` length 64, `get_function_by_address`, `get_function_xrefs` (paginated), `get_function_callees`.

**Live decompile:** ≡ raw body above (plate comment unchanged).

**Live entry bytes (hex):**

```
8B 41 08 8B 54 24 04 8B 49 10 23 C2 8B 04 81 8B 40 04
85 C0 74 13 3B 50 10 74 0A 8B 40 0C 85 C0 75 F4 C2 04 00
85 C0 75 05 33 C0 C2 04 00 8B 40 08 C2 04 00 CC...
```

**Machine reconstruction (from bytes, not disassemble_bytes tool):**

| Addr | Bytes | Meaning |
|---|---|---|
| `005b0920` | `8B 41 08` | `mask = *(this+8)` |
| `005b0923` | `8B 54 24 04` | `key = [esp+4]` |
| `005b0927` | `8B 49 10` | `buckets = *(this+0x10)` |
| `005b092a` | `23 C2` | `index = mask & key` |
| `005b092c` | `8B 04 81` | `bucketHdr = buckets[index]` |
| `005b092f` | `8B 40 04` | `node = *(bucketHdr+4)` |
| `005b0932` | `85 C0` / `74 13` | empty → null |
| `005b0936` | `3B 50 10` / `74 0A` | key == node+0x10? |
| `005b093b` | `8B 40 0C` … `75 F4` | next / loop |
| `005b0942` | `C2 04 00` | miss `RET 4` |
| `005b094e` | `8B 40 08` / `C2 04 00` | return value; `RET 4` |

**Callees:** none. **Call sites:** 200+ (xrefs).

**Sibling layout check:** `CNDHash_Insert` `0x0053c560` assigns node value `@+8`, key `@+10`, next `@+c`, head at `bucket+4`.
