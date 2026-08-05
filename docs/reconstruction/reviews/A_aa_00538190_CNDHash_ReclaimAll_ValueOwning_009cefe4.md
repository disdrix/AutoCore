# Review A (reconstruction fidelity): `aa_00538190` CNDHash_ReclaimAll_ValueOwning_009cefe4

| Field | Value |
|---|---|
| **Stable ID** | `aa_00538190` |
| **VA** | `0x00538190` |
| **Body** | `0x00538190`–`0x005381f1` (**`ret`**, 98 B + int3 pad) |
| **Canonical name** | `CNDHash_ReclaimAll_ValueOwning_009cefe4` (Ghidra `FUN_00538190`; **Inferred**) |
| **Review date** | `2026-07-29` (W19-K dual seal) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_00538190_CNDHash_ReclaimAll_ValueOwning_009cefe4.md` |
| **System** | container / CNDHash (node stamp `009cefe4`, FreeBuckets family `009cfa7c`) |
| **Live tools** | Ghidra `decompile_function` + `read_memory` (no `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Owning full-bucket reclaim** for CNDHash instances that use value-owning nodes (`PTR_FUN_009cefe4`):

1. For `bucketIndex = 0 .. this->mask(+0x08)` **inclusive**:
2. Walk collision chain at `table[i]->head (+4)`.
3. For each node: stamp vtbl `009cefe4`; if `node+0x08` non-null → **`operator_delete(value)`**; clear value; push node onto freelist `this+0x20` (vtbl slot becomes freelist next).
4. Clear bucket head to 0.

**Does not:** zero `count(+0x0c)`, free bucket table `+0x10`, free freelist slab, call virtual dtor on node.

Sole direct caller: `CNDHash_FreeBuckets_Owning_009cfa7c` (`0x005390d0`) which zeros count then calls this then frees table.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Live decompile | `decompile_function` @ `0x00538190` ≡ raw |
| Machine | `read_memory` 256 B @ `0x00538190` |
| Vtbl stamp | imm `c7 06 e4 ef 9c 00` → `0x009cefe4` |
| Caller | `get_function_callers` → only `FUN_005390d0` |
| Sibling duals | FreeBuckets `A_aa_005390d0_*`; twin reclaim `A_aa_00538200_*` |
| Raw / clean | `raw/aa_00538190_*`, `reconstructed-exact/CNDHash_ReclaimAll_ValueOwning_009cefe4.cpp`, `FUN_00538190.cpp` |

---

## 3. Authoritative body (sealed)

```c
void __thiscall CNDHash_ReclaimAll_ValueOwning_009cefe4(CNDHash *this)
{
  uint i = 0;
  do {
    Node *n = *(Node **)(*(uint8_t **)(*(uint8_t **)(this + 0x10) + i) + 4);
    while (n) {
      Node *next = n->bucket_next; // +0x0c
      n->vtbl = &PTR_FUN_009cefe4;
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

## 4. Machine seal (`read_memory` @ `0x00538190`)

Hex (body through `c3`):  
`53 55 56 8b d9 33 c9 57 33 ed … c7 06 e4 ef 9c 00 74 0b 50 e8 5a 16 f5 ff 83 c4 04 33 c9 … 89 73 20 75 d4 … 3b 6b 08 76 b3 5f 5e 5d 5b c3`

| Claim | Evidence | Conf |
|---|---|---|
| thiscall ECX→EBX | `56 8b d9` pattern with pushes | **High** |
| Stamp `009cefe4` | `c7 06 e4 ef 9c 00` | **High** |
| delete returns | `e8 … 83 c4 04 33 c9` continues | **High** |
| freelist `+0x20` | `8b 43 20` / `89 73 20` | **High** |
| loop `jbe` vs mask `+8` | `3b 6b 08 76 b3` | **High** |
| bare `ret` | `5b c3` | **High** |
| Live ≡ raw | surface match | **High** |
| Call target `0x00489822` | near-call reloc from `0x005381c3` | **High** |

---

## 5. Family context

| Unit | VA |
|---|---|
| **Reclaim (this)** | **`0x00538190`** |
| FreeBuckets owning | `0x005390d0` |
| Recreate | `0x00539dd0` |
| Dtor (via FreeBuckets) | `0x0053b920` |
| Twin reclaim `009cefec` | `0x00538200` |

---

## 6. Gaps / open

1. Product FreeBuckets/Reclaim English / mangled names.
2. Exhaustive proof every `009cefe4` user owns heap values (primary: mission state-blob family via FreeBuckets `009cfa7c`).
3. Runtime / bit-exact.

**Verdict:** **accept-with-gaps**
