# Review A (reconstruction fidelity): `aa_005e18d0` StdMap_InsertOrFindByIntKey_Val12

| Field | Value |
|---|---|
| **Stable ID** | `aa_005e18d0` |
| **VA** | `0x005e18d0`–`0x005e1988` (184 B / `0xB8`) |
| **Canonical name** | `StdMap_InsertOrFindByIntKey_Val12` (inferred) |
| **Ghidra symbol** | `FUN_005e18d0` |
| **Prior / alias** | `Named_CalleeOf_…_Mission_…_005e18d0` (narrow) |
| **Review date** | `2026-07-29` (W30-L OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_005e18d0_StdMap_InsertOrFindByIntKey_Val12.md` |
| **System** | std map insert-or-find |
| **Live tools** | Ghidra `decompile_function`, `read_memory`, meta/xrefs (**no** `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

`std::map`-style **insert-or-find** on a Val12 red-black tree (`__thiscall` on map shell). Walks by **signed int key** (`value+0` / `node+0x0c`); on miss allocates via `FUN_005e13b0` → `FUN_005ae220`; on hit returns existing iterator with `inserted=0` and **does not** rewrite value fields.

```
pair{it, inserted} = Map_InsertOrFind(map, value{key,v1,v2})
// RET 0x8; this = map in ECX
```

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005e18d0_FUN_005e18d0.md` (+ W30-L append) |
| Annotated | `raw/aa_005e18d0_FUN_005e18d0.annotated.md` |
| Clean | `reconstructed-exact/StdMap_InsertOrFindByIntKey_Val12_005e18d0.cpp` |
| Function record | `functions/aa_005e18d0_StdMap_InsertOrFindByIntKey_Val12.md` |
| Live decompile | ≡ raw (2026-07-29) |
| Bytes | `read_memory` entry + epilogue (2× `C2 08 00` visible; third via insert helper return) |
| Callees | `0x005e13b0` insert+rebalance; `0x005ae050` predecessor (W29-E) |
| Callers | `FUN_005e0610` only |
| Peer | `aa_0053a1a0` StdMap_InsertOrFindByIntKey_Val12 (W28-P) |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `__thiscall` + **`RET 0x8`** | **High** | epilogues `C2 08 00`; `mov edi,ecx` |
| Signature `(map this, outPair*, value*)` | **High** | prolog + stack layout |
| Out pair `{node* @+0, inserted @+4}` | **High** | `mov [eax],…` / `mov byte [eax+4],0/1` |
| Map shell head@+4 | **High** | `mov esi,[edi+4]` |
| Node key `+0x0C`, isnil `+0x19` | **High** | walk compares + isnil gate |
| Tree walk left/right by **signed** key | **High** | `setl` / `jge` sealed |
| New-key path: `FUN_005e13b0` | **High** | 2 call sites |
| `FUN_005ae050` = predecessor | **High** | W29-E dual |
| Equal key: **no** value write | **High** | third path stores only out-pair |
| Sole static caller | **High** | 1 xref |
| Product payload English for v1/v2 | **Inferred** | open |
| Runtime / bit-exact | Open | matrix policy |

---

## 4. Control flow: clean ≡ raw ≡ bytes

| Stage | Match |
|---|---|
| Head/root walk by key; isnil `+0x19` | **Yes** |
| goLeft + leftmost → insert flag 1 | **Yes** |
| goLeft + not leftmost → predecessor | **Yes** |
| parent.key < key → insert | **Yes** (signed) |
| else equal → out `{parent,0}` no mutate | **Yes** |
| `RET 0x8` exits | **Yes** |

---

## 5. Asm-sealed signature + layouts

```c
struct Val12Entry {
    int32_t key;     // SIGNED
    uint32_t v1;
    uint32_t v2;
};

struct Val12Node { // size 0x1C
    Val12Node* left;    // +0x00
    Val12Node* parent;  // +0x04
    Val12Node* right;   // +0x08
    int32_t key;        // +0x0C
    uint32_t v1;        // +0x10
    uint32_t v2;        // +0x14
    uint8_t  color;     // +0x18
    uint8_t  isnil;     // +0x19
};

struct InsertPair {
    Val12Node* it;      // +0
    uint8_t inserted;   // +4
};
```

---

## 6. Gaps

1. Product English / demangle for map of `FUN_005e0610`.  
2. Full dual of always-insert `FUN_005e13b0` (not OWN).  
3. Runtime / bit-exact / differential — open.

**Verdict:** **accept-with-gaps**
