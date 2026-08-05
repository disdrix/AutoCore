# Review A (reconstruction fidelity): `aa_0051bfb0` CNDHash_ReclaimAll_ValueOwning_009ce0a8

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051bfb0` |
| **VA** | `0x0051bfb0`–`0x0051c021` (**0x72** B; plain `ret`) |
| **Canonical name** | `CNDHash_ReclaimAll_ValueOwning_009ce0a8` (Ghidra `FUN_0051bfb0`; **Inferred**) |
| **Prior alias** | `Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_0051bfb0` (**reject**) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction fidelity (OWN-ONLY dual W25-F Path A) |
| **Counterpart** | `reviews/B_aa_0051bfb0_CNDHash_ReclaimAll_ValueOwning_009ce0a8.md` |
| **System** | container / CNDHash (medal family; node stamp `009ce0a8`) |
| **Live tools** | `decompile_function`, `read_memory`, `get_function_by_address`, xrefs/callees |
| **Verdict** | **accept-with-gaps** |
| **Dual status** | **Present (first full dual)** — closes FreeBuckets residual “full value-ownership matrix inside FUN_0051bfb0” |

**Tools note:** No `disassemble_bytes`. No Launcher. No parent ledgers.

---

## 1. Purpose

**Owning full-bucket reclaim** for CNDHash instances that use value-owning nodes with stamp `PTR_FUN_009ce0a8` **and nested value teardown**:

```c
// __thiscall  plain ret
void CNDHash_ReclaimAll_ValueOwning_009ce0a8(CNDHash *this);
```

1. For `bucketIndex = 0 .. this->mask(+0x08)` **inclusive**
2. Walk chain at `table[i]->head (+4)`
3. Per node: stamp `009ce0a8`; if `node+0x08` ≠ 0 → **`FUN_00604e30(value)`** then **`operator_delete(value)`**; clear value; push freelist `this+0x20`
4. Clear each bucket head to 0

**Does not:** zero `count(+0x0C)`, free bucket table `+0x10`, free freelist slab, invoke virtual node dtor.

Sole direct caller: `CNDHash_FreeBuckets` (`0x0051d150`) which zeros count then calls this then frees table.

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | ≡ raw 2026-07-23 |
| Live bytes | full body through `POP ECX; RET` (0x72 B) |
| Stamp imm | `C7 06 A8 E0 9C 00` → `0x009ce0a8` |
| Nested teardown | `MOV ECX,EBX; CALL FUN_00604e30` then `PUSH; operator_delete; ADD ESP,4` |
| Caller FreeBuckets | sealed dual `aa_0051d150` (W24-H) |
| Alloc twin | `CNDHash_AllocBucketTable_009ce090` (`FUN_0051ba40`, same dual) |
| Sibling reclaim | plain owning `009cefec` / `009cefe4` (no `FUN_00604e30`) |
| Raw / clean | `raw/aa_0051bfb0_*`, `reconstructed-exact/CNDHash_ReclaimAll_ValueOwning_009ce0a8.cpp`, `FUN_0051bfb0.cpp` |

---

## 3. Authoritative body (sealed CF)

```c
void __thiscall CNDHash_ReclaimAll_ValueOwning_009ce0a8(CNDHash *this)
{
  uint i = 0;
  do {
    Node *n = *(Node **)(*(uint8_t **)(*(uint8_t **)(this + 0x10) + i) + 4);
    while (n) {
      Node *next = n->bucket_next; // +0x0c
      void *value = n->value;      // +0x08
      n->vtbl = &PTR_FUN_009ce0a8;
      if (value) {
        FUN_00604e30(value);       // thiscall nested; RETURNS
        operator_delete(value);    // RETURNS
      }
      n->value = 0;
      n->vtbl = this->freelist;    // +0x20 push
      this->freelist = n;
      n = next;
    }
    *(uint32_t *)(*(uint8_t **)(*(uint8_t **)(this + 0x10) + i) + 4) = 0;
    i++;
  } while (i <= this->mask); // +0x08 inclusive
}
```

---

## 4. Machine seal (`read_memory` @ `0x0051bfb0`)

Hex (body through `c3`):  
`51 53 55 8B E9 33 C9 56 33 C0 57 … C7 06 A8 E0 9C 00 74 16 8B CB E8 … 53 E8 … 83 C4 04 … 89 75 20 75 C9 … 3B 45 08 … 76 A4 5F 5E 5D 5B 59 C3`

| Claim | Evidence | Conf |
|---|---|---|
| thiscall ECX→EBP | `55 8B E9` after push frame | **High** |
| Stamp `009ce0a8` | `C7 06 A8 E0 9C 00` | **High** |
| Nested thiscall | `8B CB E8` to `FUN_00604e30` | **High** |
| delete returns | `E8 … 83 C4 04 33 C9` continues | **High** |
| freelist `+0x20` | `8B 55 20 / 89 16 / 89 75 20` | **High** |
| loop `JBE` vs mask `+8` | `3B 45 08 76 A4` | **High** |
| bare `ret` | `59 C3` | **High** |
| Live ≡ raw | surface match | **High** |

---

## 5. Naming

| Candidate | Decision |
|---|---|
| `CNDHash_ReclaimAll_ValueOwning_009ce0a8` | **Accept** — family vocabulary + node stamp; nested teardown documented |
| `CNDHash_ReclaimAll_ValueNestedOwning_009ce0a8` | Acceptable longer alias |
| `FUN_0051bfb0` | scaffold |
| Named_CalleeOf VOG chain | **Reject** product identity |

No body string; name is structural/family (**High**), not PDB.

---

## 6. Confidence

| Claim | Level |
|---|---|
| CF dual A ≡ raw ≡ live | **Confirmed** |
| `__thiscall` plain ret | **Confirmed** |
| Value delete + freelist | **Confirmed** |
| Nested `FUN_00604e30` | **Confirmed** |
| Sole FreeBuckets caller | **Confirmed** (1 xref) |
| Role ReclaimAll value-owning | **High** |
| Product/PDB symbol | **Open** |
| Exact value struct fields | **Open** (residual) |
| Runtime / bit-exact / diff | **Open** |

**Verdict:** **accept-with-gaps.**
