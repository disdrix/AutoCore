# Review A (reconstruction fidelity): `aa_00538120` CNDHash_ReleaseNodesToFreelist_Owning_009cefd4

| Field | Value |
|---|---|
| **Stable ID** | `aa_00538120` |
| **VA** | `0x00538120` |
| **Body** | `0x00538120`–`0x00538177` (**`ret`**) |
| **Canonical name** | `CNDHash_ReleaseNodesToFreelist_Owning_009cefd4` (Ghidra `FUN_00538120`; **Inferred**) |
| **Review date** | `2026-07-29` (OWN-ONLY dual W17-K) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_00538120_CNDHash_ReleaseNodesToFreelist_Owning_009cefd4.md` |
| **System** | container / CNDHash (object family `PTR_FUN_009cfa64`, node vtbl `009cefd4`, char hash `+0x534`) |
| **Live tools** | Ghidra `decompile_function` + `read_memory` (no `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Owning **ReleaseNodesToFreelist** stage for FreeBuckets of CNDHash family **`009cfa64`**:

For each bucket index `i = 0 .. *(hash+8)` **inclusive**:

1. Walk chain at `*(table[i]+4)`.
2. Per node: stamp vtbl `PTR_FUN_009cefd4`; if value `node+8` non-null → `operator_delete(value)`; clear value; push node onto freelist `hash+0x20` (`*node = old; freelist = node`).
3. Zero bucket head `*(table[i]+4) = 0`.

Does **not** zero count, free table, or touch freelist slab vector (parent FreeBuckets / Dtor).

**Caller (sole):** `CNDHash_FreeBuckets_Owning_009cfa64` @ `0x00539090`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Fresh decompile | `decompile_function` @ `0x00538120` ≡ raw 2026-07-23 |
| Machine | `read_memory` @ `0x00538120` length 128; body ends `5f 5e 5d 5b c3` |
| Parent FreeBuckets dual | `A_aa_00539090_CNDHash_FreeBuckets_Owning_009cfa64.md` |
| Insert twin (node layout) | `CNDHash_Insert` / `0x0053c560` (same `009cefd4`, value `+8`, next `+0xc`) |
| Raw / clean / function | `raw/aa_00538120_*`, `reconstructed-exact/FUN_00538120.cpp`, `functions/aa_00538120_*` |

---

## 3. Authoritative body

```c
void __fastcall CNDHash_ReleaseNodesToFreelist_Owning_009cefd4(CNDHash *hash)
{
  uint32_t i = 0;
  do {
    uint32_t *node = *(uint32_t **)(*(uint32_t **)((char *)hash + 0x10)[i] + 4);
    while (node) {
      uint32_t *next = (uint32_t *)node[3];
      *node = (uint32_t)&PTR_FUN_009cefd4;
      if ((void *)node[2])
        operator_delete((void *)node[2]);
      node[2] = 0;
      *node = *(uint32_t *)((char *)hash + 0x20);
      *(uint32_t **)((char *)hash + 0x20) = node;
      node = next;
    }
    *(uint32_t *)(*(uint32_t **)((char *)hash + 0x10)[i] + 4) = 0;
    i++;
  } while (i <= *(uint32_t *)((char *)hash + 8));
}
```

---

## 4. Machine seal

| Claim | Evidence | Conf |
|---|---|---|
| ECX→EBX this | `8b d9` | **High** |
| Inclusive loop on `+8` | `3b 6b 08` / `76 b3` (`jbe`) | **High** |
| Stamp `009cefd4` | `c7 06 d4 ef 9c 00` | **High** |
| `operator_delete` value `+8` | load `[esi+8]`; call; clear | **High** |
| Freelist `+0x20` | `8b 43 20; 89 06; 89 73 20` | **High** |
| Next `+0xc` | `8b 7f 0c` | **High** |
| Sole caller FreeBuckets | xref `0x0053909a` | **High** |

---

## 5. Confidence

| Claim | Conf |
|---|---|
| Owning reclaim → freelist | **High** |
| Node layout matches Insert `009cefd4` | **High** |
| CF clean ≡ raw ≡ machine | **High** |
| Product English name | **Tentative** |
| Value payload type | **Open** (domain of hash install site) |

---

## 6. Gaps / open

1. Product/PDB name for reclaim helper.
2. Runtime / bit-exact / differential — open.
3. Confirm all install sites of this hash family share POD value free safety.

**Verdict:** **accept-with-gaps**
