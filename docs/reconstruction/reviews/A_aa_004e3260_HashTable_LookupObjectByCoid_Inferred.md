# Review A (reconstruction fidelity): `aa_004e3260` HashTable_LookupObjectByCoid_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e3260` |
| **VA** | `0x004e3260` – `0x004e328b` |
| **Body span** | **44** bytes (`004e3260`–`004e328b` exclusive end `004e328c`; ends `ret 8`) |
| **Canonical name** | `FUN_004e3260` (Ghidra) |
| **Proposed name** | `HashTable_LookupObjectByCoid_Inferred` (**Probable**; no product string) |
| **Prior scaffold alias** | `Named_CalleeOf_CVOGReaction_ResolveObjectTarget_004e3260` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A/B **create** — live Ghidra W16-I) |
| **Reviewer role** | Independent reconstruction review (clean ≡ image; raw decompile incomplete) |
| **Counterpart** | `reviews/B_aa_004e3260_HashTable_LookupObjectByCoid_Inferred.md` |
| **System** | object-resolve / id-hash |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Tiny **thiscall hash lookup** used as the shared leaf under dual-table TFID resolve and other COID finders:

1. Hash `coidLo` with table mask `@+0x8`.
2. Load chain head from bucket array `@+0x10`.
3. Walk chain via `FUN_004e23d0` matching `(coidLo, coidHi)` at node `+0x18/+0x1c`.
4. Return **`*(node+0xc)`** object pointer, or **0**.

**No mutation.** Does not insert/remove; does not select domain tables (that is `CVOGReaction_ResolveObjectTarget`).

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004e3260_FUN_004e3260.md` |
| Annotated | `docs/reconstruction/raw/aa_004e3260_FUN_004e3260.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_004e3260.cpp` |
| Named scaffold | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_CVOGReaction_ResolveObjectTarget_004e3260.cpp` |
| Function record | `docs/reconstruction/functions/aa_004e3260_FUN_004e3260.md` |
| Live decompile | Ghidra `decompile_function` @ `0x004e3260` |
| Live bytes | `read_memory` @ `0x004e3260` length 64 (body 44 B) |
| Callee | `decompile_function` + `read_memory` @ `0x004e23d0` |
| Function meta | `get_function_by_address` → body `004e3260`–`004e328b` |
| Live xrefs | `get_xrefs_to` / `get_function_callers` |
| Parent dual (context) | `A/B_aa_004bae70_CVOGReaction_ResolveObjectTarget.md` |

**Not performed:** Launcher, runtime golden, bit-exact image diff, deep dual of non-owned callees beyond walk contract, ledger updates.

---

## 3. Signature (sealed)

```c
// __thiscall  ECX = hash table object
// stack args cleaned by ret 8  (2 dwords)
void * HashTable_LookupObjectByCoid_Inferred(
    void *pTable,           // this ECX — mask +0x8; buckets* +0x10
    unsigned int coidLo,    // hashed; matched at node +0x18
    unsigned int coidHi);   // matched at node +0x1c
// returns object* or NULL
```

---

## 4. Control flow (assembly-sealed; decompiler incomplete)

Ghidra decompile matches **return payload** (`node+0xc` or 0) but **drops** thiscall table use, bucket index, and `ret 8`. Prefer image:

```
// 0x004e3260 (read_memory 2026-07-29)
// ECX = pTable
edx = coidHi;
push &stack_coidLo;          // out-prev for FUN_004e23d0
eax = coidLo;
push coidHi;
bucket = coidLo & *(u32*)(pTable + 0x8);
push coidLo;
listHead = *( *(void***)(pTable + 0x10) + bucket );
// CALL FUN_004e23d0 with ECX=listHead
node = FUN_004e23d0(...);
if (node == 0) return 0;     // ret 8
return *(void**)(node + 0xc); // ret 8
```

| Stage | Match clean≡image | Confidence |
|---|---|---|
| `__thiscall` ECX = table | **Yes** (was free-fn in scaffold) | **High** (bytes) |
| Mask load `table+0x8` | **Yes** | **High** |
| Bucket `coidLo & mask` | **Yes** | **High** |
| Head from `*(table+0x10)[bucket]` | **Yes** | **High** |
| Sole callee `FUN_004e23d0` | **Yes** | **High** |
| Miss → 0 / hit → `*(node+0xc)` | **Yes** (also in decompiler) | **High** |
| `ret 8` (2 stack args) | **Yes** | **Confirmed** |
| No stores | **Yes** | **High** |

### 4.1 Machine bytes (`read_memory` @ `0x004e3260`)

```
8b 54 24 08          mov edx, [esp+8]
8d 44 24 04          lea eax, [esp+4]
50                   push eax
8b 44 24 08          mov eax, [esp+8]
52                   push edx
8b 51 08             mov edx, [ecx+8]
23 d0                and edx, eax
50                   push eax
8b 41 10             mov eax, [ecx+0x10]
8b 0c 90             mov ecx, [eax+edx*4]
e8 51 f1 ff ff       call 0x004e23d0
85 c0                test eax, eax
75 03                jnz +3
c2 08 00             ret 8
8b 40 0c             mov eax, [eax+0xc]
c2 08 00             ret 8
```

### 4.2 Callee contract (supporting; not OWN dual of walk)

| Addr | Role | Sealed bits |
|---|---|---|
| `FUN_004e23d0` `0x004e23d0` | Chain walk | ECX=list head; `cur=*(head+4)`; match `+0x18/+0x1c`; next `+0x10`; `*outPrev` chain; `ret 0xc`; result node in EAX |

Hash-node layout corroborated by parent dual / RemoveObject insert (`payload +0xc`, keys `+0x18/+0x1c`).

---

## 5. Callers (OWN VA xrefs)

| Function | Sites | Role (caller CF — not dualed here) |
|---|---|---|
| `CVOGReaction_ResolveObjectTarget` | `004bae95`, `004baea8` | Dual-table TFID resolve (global/local) |
| `FUN_004c82b0` | `004c8438` | Additional COID lookup path |
| `FUN_004dfcc0` | `004e0537`, `004e055e` | Two sites |
| `Vehicle_applyCreatePacket` | `005054a7` | Vehicle create resolve |

**6** `UNCONDITIONAL_CALL` sites / **4** caller functions.

---

## 6. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Function exists @ `0x004e3260` | **Confirmed** | Ghidra + bytes |
| `__thiscall` + 2 stack args (`ret 8`) | **High** | image epilogue |
| Bucket = `coidLo & *(table+0x8)` | **High** | `and edx,eax` after load mask |
| Head = `(*(table+0x10))[bucket]` | **High** | `mov ecx,[eax+edx*4]` |
| Return object* @ node `+0xc` | **High** | `mov eax,[eax+0xc]` + insert layout |
| No mutation | **High** | no stores |
| Decompiler complete CF | **Falsified** | missing table/bucket |
| Product name of table / method | **Open** | residual FUN_* |
| Full sentinel semantics of head+4 start | **Tentative** | owned only as callee contract |

---

## 7. Gaps / open

1. Product / PDB names for table type and this method.
2. Whether bucket head is a dedicated sentinel object vs first node with prev slot (walk starts at `*(head+4)` inside callee).
3. Runtime miss rate / concurrent mutation assumptions.
4. Bit-exact / differential vs retail image open.
5. Optional Ghidra rename to proposed name.

**Verdict:** **accept-with-gaps** — machine body, ABI, hash indexing, payload offset, and 6-site caller inventory sealed static; product name + full table type remain open. Package **not complete** for runtime/diff.
