# Review A (reconstruction fidelity): `aa_00538200` CNDHash_ReclaimAll_ValueOwning_009cefec

| Field | Value |
|---|---|
| **Stable ID** | `aa_00538200` |
| **VA** | `0x00538200` |
| **Body** | `0x00538200`–`0x00538261` (**`ret`**, 98 B + int3 pad) |
| **Canonical name** | `CNDHash_ReclaimAll_ValueOwning_009cefec` (Ghidra `FUN_00538200`; **Inferred**) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_00538200_CNDHash_ReclaimAll_ValueOwning_009cefec.md` |
| **System** | container / CNDHash (node stamp `009cefec`, FreeBuckets family `009cfa88`) |
| **Live tools** | Ghidra `decompile_function` + `read_memory` (no `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Owning full-bucket reclaim** for CNDHash instances that use value-owning nodes (`PTR_FUN_009cefec`):

1. For `bucketIndex = 0 .. this->mask(+0x08)` **inclusive**:
2. Walk collision chain at `table[i]->head (+4)`.
3. For each node: stamp vtbl `009cefec`; if `node+0x08` non-null → **`operator_delete(value)`**; clear value; push node onto freelist `this+0x20` (vtbl slot becomes freelist next).
4. Clear bucket head to 0.

**Does not:** zero `count(+0x0c)`, free bucket table `+0x10`, free freelist slab, call virtual dtor on node.

Sole direct caller: `CNDHash_FreeBuckets_Owning_009cfa88` (`0x00539110`) which zeros count then calls this then frees table.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Live decompile | `decompile_function` @ `0x00538200` ≡ raw |
| Machine | `read_memory` 112 B @ `0x00538200` |
| Vtbl stamp | imm `c7 06 ec ef 9c 00` → `0x009cefec`; dword0 = `FUN_00537550` |
| Caller | `get_function_xrefs` → only `0x0053911a` in `FUN_00539110` |
| Sibling duals | FreeBuckets `A_aa_00539110_*`; node dtor `A_aa_00537550_*`; remove `A_aa_00538000_*` |
| Raw / clean | `raw/aa_00538200_*`, `reconstructed-exact/CNDHash_ReclaimAll_ValueOwning_009cefec.cpp`, `FUN_00538200.cpp` |

---

## 3. Authoritative body (sealed)

```c
void __thiscall CNDHash_ReclaimAll_ValueOwning_009cefec(CNDHash *this)
{
  uint i = 0;
  do {
    Node *n = *(Node **)(*(uint8_t **)(*(uint8_t **)(this + 0x10) + i) + 4);
    while (n) {
      Node *next = n->bucket_next; // +0x0c
      n->vtbl = &PTR_FUN_009cefec;
      if (n->value) operator_delete(n->value); // RETURNS
      n->value = 0;
      n->vtbl = this->freelist; // +0x20
      this->freelist = n;
      n = next;
    }
    *(uint32_t *)(*(uint8_t **)(*(uint8_t **)(this + 0x10) + i) + 4) = 0;
    i++;
  } while (i <= this->mask); // +0x08 inclusive
}
```

---

## 4. Machine seal (`read_memory` @ `0x00538200`)

Hex (body through `c3`):  
`53 55 56 8b d9 33 c9 57 33 ed … c7 06 ec ef 9c 00 74 0b 50 e8 ea 15 f5 ff 83 c4 04 33 c9 … 89 73 20 75 d4 … 3b 6b 08 76 b3 5f 5e 5d 5b c3`

| Claim | Evidence | Conf |
|---|---|---|
| thiscall ECX→EBX | `56 8b d9` pattern with pushes | **High** |
| Stamp `009cefec` | `c7 06 ec ef 9c 00` | **High** |
| delete returns | `e8 … 83 c4 04 33 c9` continues | **High** |
| freelist `+0x20` | `8b 43 20` / `89 73 20` | **High** |
| loop `jbe` vs mask `+8` | `3b 6b 08 76 b3` | **High** |
| bare `ret` | `5b c3` | **High** |
| Live ≡ raw | surface match | **High** |

---

## 5. Family context

| Unit | VA |
|---|---|
| **Reclaim (this)** | **`0x00538200`** |
| FreeBuckets owning | `0x00539110` |
| Recreate | `0x00539e30` |
| Remove owning | `0x00538000` |
| Node scalar dtor | `0x00537550` |
| Pending hash install | char `+0x55c` (family evidence) |

---

## 6. Gaps / open

1. Product FreeBuckets/Reclaim English / mangled names.
2. Exhaustive proof every `009cefec` user owns heap values (primary: pending objectives).
3. Runtime / bit-exact.

**Verdict:** **accept-with-gaps**
