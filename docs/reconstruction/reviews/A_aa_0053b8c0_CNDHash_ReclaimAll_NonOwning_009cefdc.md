# Review A (reconstruction fidelity): `aa_0053b8c0` CNDHash_ReclaimAll_NonOwning_009cefdc

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053b8c0` |
| **VA** | `0x0053b8c0` |
| **Body** | `0x0053b8c0`–`0x0053b8ff` (**`ret`**, 64 B) |
| **Canonical name** | `CNDHash_ReclaimAll_NonOwning_009cefdc` (Ghidra `FUN_0053b8c0`; **Inferred**) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_0053b8c0_CNDHash_ReclaimAll_NonOwning_009cefdc.md` |
| **System** | container / CNDHash (node stamp `009cefdc`, FreeBuckets family `009cfa70`) |
| **Live tools** | Ghidra `decompile_function` + `read_memory` (no `disassemble_bytes`) |
| **Verdict** | **accept** — reclaim CF High; **non-owning** High |

---

## 1. Purpose

**Non-owning full-bucket reclaim** for CNDHash instances whose FreeBuckets path is `009cfa70`:

1. For `bucketIndex = 0 .. this->mask(+0x08)` **inclusive**:
2. Walk collision chain at `table[i]->head (+4)`.
3. For each node: stamp vtbl `009cefdc`; freelist-push via `this+0x20` (vtbl slot becomes freelist next). **No** `operator_delete` on values; **no** value zero at `+0x08`.
4. Clear bucket head to 0.

**Does not:** zero `count(+0x0c)`, free bucket table `+0x10`, free freelist slab.

Sole direct caller: `CNDHash_FreeBuckets_NonOwning_009cfa70` (`0x0053b880`) which zeros count then calls this then frees table.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Live decompile | `decompile_function` @ `0x0053b8c0` ≡ raw 2026-07-23 |
| Machine | `read_memory` 96 B @ `0x0053b8c0` |
| Vtbl stamp | imm `c7 02 dc ef 9c 00` → `0x009cefdc` |
| Caller | `get_function_xrefs` → only `0x0053b88a` in `FUN_0053b880` |
| Sibling duals | FreeBuckets `A_aa_0053b880_*`; owning reclaim `A_aa_00538200_*`; RemoveAll `A_aa_0053b330_*` |
| Raw / clean | `raw/aa_0053b8c0_*`, `reconstructed-exact/CNDHash_ReclaimAll_NonOwning_009cefdc.cpp`, `FUN_0053b8c0.cpp` |

---

## 3. Authoritative body (sealed)

```c
void __fastcall CNDHash_ReclaimAll_NonOwning_009cefdc(CNDHash *this)
{
  uint i = 0;
  do {
    Node *n = *(Node **)(*(uint8_t **)(*(uint8_t **)(this + 0x10) + i * 4) + 4);
    while (n) {
      Node *next = n->bucket_next; // +0x0c
      n->vtbl = &PTR_LAB_009cefdc;
      n->vtbl = this->freelist;    // +0x20 overwrite stamp
      this->freelist = n;
      n = next;
    }
    *(uint32_t *)(*(uint8_t **)(*(uint8_t **)(this + 0x10) + i * 4) + 4) = 0;
    i++;
  } while (i <= this->mask); // +0x08 inclusive
}
```

---

## 4. Machine seal (`read_memory` @ `0x0053b8c0`)

Hex (body through `c3`):  
`53 56 33 f6 8b 41 10 8b 14 b0 8b 42 04 85 c0 74 17 8b d0 8b 40 0c 85 c0 c7 02 dc ef 9c 00 8b 59 20 89 1a 89 51 20 75 e9 8b 41 10 8b 14 b0 83 c6 01 c7 42 04 00 00 00 00 3b 71 08 76 c7 5e 5b c3`

| Claim | Evidence | Conf |
|---|---|---|
| thiscall/fastcall ECX | `8b 41 10` / `8b 59 20` / `3b 71 08` | **High** |
| Stamp `009cefdc` | `c7 02 dc ef 9c 00` | **High** |
| freelist `+0x20` | `8b 59 20` / `89 1a` / `89 51 20` | **High** |
| next `+0x0c` | `8b 40 0c` | **High** |
| loop `jbe` vs mask `+8` | `3b 71 08 76 c7` | **High** |
| bare `ret` | `5e 5b c3` | **High** |
| **no** value delete | no `call` in body | **High** |
| Live ≡ raw | surface match | **High** |

---

## 5. Family context

| Unit | VA |
|---|---|
| **Reclaim (this)** | **`0x0053b8c0`** |
| FreeBuckets non-owning | `0x0053b880` |
| Dtor | `0x0053b810` |
| Scalar dtor | `0x0053b7f0` |
| Owning reclaim twin | `0x00538200` (stamp `009cefec` + delete values) |
| RemoveAll same stamp | `0x0053b330` (also zeros value) |

---

## 6. Gaps / open

1. Product FreeBuckets/Reclaim English / mangled names.
2. Stale `node+0x08` value pointers after freelist (external ownership contract residual).
3. Runtime / bit-exact.

**Verdict:** **accept**
