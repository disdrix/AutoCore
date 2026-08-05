# Review A (reconstruction fidelity): `aa_00573810` StdMap_InsertOrFind_Val12_UintKey

| Field | Value |
|---|---|
| **Stable ID** | `aa_00573810` |
| **VA** | `0x00573810` |
| **Body** | `0x00573810`–`0x005738c8` exclusive (**184** B) |
| **Canonical name** | `StdMap_InsertOrFind_Val12_UintKey` (inferred) |
| **Ghidra symbol** | `FUN_00573810` |
| **Prior / alias** | `Named_CalleeOf_…_Client_ShowInvento_00573810` (narrow) |
| **Review date** | `2026-07-29` (W28-T OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_00573810_StdMap_InsertOrFind_Val12_UintKey.md` |
| **System** | std map insert-or-find |
| **Live tools** | Ghidra `decompile_function`, `read_memory`, meta/xrefs (**no** `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

`std::map`-style **insert-or-find** on a Val12 red-black tree (`__thiscall` on map shell). Walks by **uint key** (`value+0` / `node+0x0c`); on miss allocates via `FUN_00573510` → `FUN_005ae220`; on hit returns existing iterator with `inserted=0` and **does not** rewrite value fields.

```
pair{it, inserted} = Map_InsertOrFind(map, value{key,v1,v2})
// RET 0x8; this = map in ECX
```

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00573810_FUN_00573810.md` (+ W28-T append) |
| Annotated | `raw/aa_00573810_FUN_00573810.annotated.md` |
| Clean | `reconstructed-exact/StdMap_InsertOrFind_Val12_UintKey.cpp` |
| Function record | `functions/aa_00573810_StdMap_InsertOrFind_Val12_UintKey.md` |
| Live decompile | ≡ raw (2026-07-29) |
| Bytes | `read_memory` entry + epilogue @ `0x005738b0` (3× `C2 08 00`) |
| Callees | `0x00573510` insert+rebalance (W27-S); `0x005ae050` predecessor |
| Callers | `FUN_00572360`, `FUN_00572730`, `FUN_00572ab0` (2 sites) |
| Peer | `Skill_CategoryCooldownMap_Insert` `0x0051d2f0` (same CF family) |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `__thiscall` + **`RET 0x8`** | **High** | three epilogues `C2 08 00`; `mov edi,ecx` |
| Signature `(map this, outPair*, value*)` | **High** | prolog + stack layout |
| Out pair `{node* @+0, inserted @+4}` | **High** | `mov [eax],…` / `mov byte [eax+4],0/1` |
| Map shell head@+4 | **High** | `mov esi,[edi+4]` |
| Node key `+0x0C`, isnil `+0x19` | **High** | walk compares + isnil gate |
| Tree walk left/right by uint key | **High** | body CF ≡ raw ≡ bytes |
| New-key path: `FUN_00573510` | **High** | 2 call sites |
| `FUN_005ae050` = predecessor | **High** | decompile of helper |
| Equal key: **no** value write | **High** | third ret path stores only out-pair |
| Always-insert uses stack buy `005ae220` (not ESI `0046c6c0`) | **High** | W27-S seal on `00573510` |
| Three static callers / 4 xrefs | **High** | xrefs 2026-07-29 |
| Product payload English for v1/v2 | **Inferred** | open |
| Runtime / bit-exact | Open | matrix policy |

---

## 4. Control flow: clean ≡ raw ≡ bytes

| Stage | Match |
|---|---|
| Head/root walk by key; isnil `+0x19` | **Yes** |
| goLeft + leftmost → insert flag 1 | **Yes** |
| goLeft + not leftmost → predecessor | **Yes** |
| parent.key < key → insert | **Yes** |
| else equal → out `{parent,0}` no mutate | **Yes** |
| `RET 0x8` all exits | **Yes** |

---

## 5. Asm-sealed signature + layouts

```c
struct Val12Entry {
    uint32_t key;
    uint32_t v1;
    uint32_t v2;
};

struct Val12Node { // size 0x1C
    Val12Node* left;    // +0x00
    Val12Node* parent;  // +0x04
    Val12Node* right;   // +0x08
    uint32_t key;       // +0x0C
    uint32_t v1;        // +0x10
    uint32_t v2;        // +0x14
    uint8_t  color;     // +0x18
    uint8_t  isnil;     // +0x19
};

struct InsertPair {
    Val12Node* it;  // +0
    uint8_t inserted; // +4
};

void __thiscall StdMap_InsertOrFind_Val12_UintKey(
    void* thisMap,
    InsertPair* pOut,
    const Val12Entry* pValue);
// RET 0x8
```

---

## 6. Gaps / open

1. Product English / demangle for map value payload (inventory context likely).  
2. Full dual of callers (out of ownership).  
3. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps** — ABI, out-pair, Val12 key/isnil, insert-or-find CF, helper roles **sealed High**; product demangle + runtime open.
