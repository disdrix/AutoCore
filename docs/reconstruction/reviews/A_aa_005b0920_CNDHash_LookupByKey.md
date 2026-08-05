# Review A (reconstruction fidelity): `aa_005b0920` CNDHash_LookupByKey

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b0920` |
| **VA** | `0x005b0920` |
| **Canonical name** | `CNDHash_LookupByKey` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005b0920_CNDHash_LookupByKey.md` |
| **System** | shared hash container (missions / inventory / map unlock / skills / UI — many consumers) |
| **Verdict** | **accept** — pure leaf lookup; ABI + bucket walk + node offsets **sealed** |

---

## 1. Purpose

Generic **CNDHash** lookup: given `this` hash table and a **uint32 key**, return the **value pointer** for the matching entry, or **NULL**.

Used widely (200+ call sites): mission state, continent unlock, skill trees, NPC interact icons, journal, tooltip stats, `CNDHash_Insert` pre-checks, etc. This unit is **read-only** and has **no callees**.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005b0920_CNDHash_LookupByKey.md` |
| Annotated | `docs/reconstruction/raw/aa_005b0920_CNDHash_LookupByKey.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CNDHash_LookupByKey.cpp` |
| Function record | `docs/reconstruction/functions/aa_005b0920_CNDHash_LookupByKey.md` |
| Live decompile | Ghidra `decompile_function` `0x005b0920` — body ≡ raw |
| Live bytes | Ghidra `read_memory` `0x005b0920` length 64 |
| Function meta | `get_function_by_address` → body `005b0920`–`005b0953` |
| Xrefs | `get_function_xrefs` → 200+ sites (paginated) |
| Callees | `get_function_callees` → **none** (leaf) |
| Layout cross-check | sibling `CNDHash_Insert` `0x0053c560` (node field assignment) |

---

## 3. Sealed residuals

### 3.1 ABI — **SEALED**

| Fact | Evidence |
|---|---|
| Convention | **`__thiscall`**: `this` in **ECX**, stack arg `key` |
| Stack arg | `MOV EDX, [ESP+4]` @ entry+3 |
| Epilogue | **`RET 4`** (`C2 04 00`) — three sites in body |
| Return | value `void*` in **EAX**, or **0** |
| Body size | `0x005b0920`–`0x005b0953` (52 bytes); tail `CC` padding |

```c
void * __thiscall CNDHash_LookupByKey(void *this, uint32_t key);
```

### 3.2 Algorithm — **SEALED**

```
bucketIndex = (this->mask @ +0x08) & key
bucketHdr   = this->buckets[+0x10][bucketIndex]   // dword array, *4
node        = *(bucketHdr + 0x4)                  // chain head
while node:
  if node->key(+0x10) == key:
    return node->value(+0x08)
  node = node->next(+0x0c)
return NULL
```

- Hashing is **only** `key & mask` (no multi-hash / murmur / multiply).
- Collision resolution: **singly-linked chain**, walk until key match or null.
- Match returns **value**, not the node.
- Empty bucket (head null) → NULL without walking.

### 3.3 Layouts used by this unit — **SEALED**

**CNDHash (fields touched):**

| Off | Type | Role |
|---|---|---|
| `+0x08` | `uint32` | bucket mask (`index = mask & key`) |
| `+0x10` | `T**` | pointer to bucket-header pointer array |

**Bucket header (fields touched):**

| Off | Type | Role |
|---|---|---|
| `+0x04` | `Node*` | chain head |

**Node (fields touched):**

| Off | Type | Role |
|---|---|---|
| `+0x08` | `void*` | **value** (return) |
| `+0x0c` | `Node*` | next in bucket chain |
| `+0x10` | `uint32` | **key** |

Cross-check from `CNDHash_Insert` (`0x0053c560`): new node sets `puVar3[2]=value`, `puVar3[4]=key`, `puVar3[3]=oldHead`, then writes head at `bucketHdr+4` — same offsets.

### 3.4 Machine bytes (entry) — **SEALED**

```
8B 41 08          mov  eax, [ecx+8]       ; mask
8B 54 24 04       mov  edx, [esp+4]       ; key
8B 49 10          mov  ecx, [ecx+10h]     ; buckets
23 C2             and  eax, edx           ; index
8B 04 81          mov  eax, [ecx+eax*4]   ; bucketHdr
8B 40 04          mov  eax, [eax+4]       ; node = head
85 C0             test eax, eax
74 13             jz   → null_ret
; loop:
3B 50 10          cmp  edx, [eax+10h]     ; key == node.key?
74 0A             je   → found
8B 40 0C          mov  eax, [eax+0Ch]     ; next
85 C0             test eax, eax
75 F4             jnz  loop
C2 04 00          ret  4                  ; miss
; found:
85 C0             test eax, eax
75 05             jnz  → ret_value
; null_ret:
33 C0             xor  eax, eax
C2 04 00          ret  4
; ret_value:
8B 40 08          mov  eax, [eax+8]       ; value
C2 04 00          ret  4
```

Decompiler CF ≡ this walk (including redundant post-match `if (iVar1 != 0)` before load value — always true after successful compare path from non-null node).

### 3.5 Side effects / locks — **SEALED for this unit**

- **No** reads of traversal-lock `this+0x1d` (Insert/walkers assert lock; Lookup does **not**).
- **No** count / list head/tail mutation (`+0x0c` / `+0x14` / `+0x18` unused here).
- **No** calls.

### 3.6 Name — **SEALED**

Plate / Ghidra name `CNDHash_LookupByKey` is product-correct: returns **value by key**, not node. Stable ID `aa_005b0920`.

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| mask & key → bucket → head | Yes |
| while key mismatch → next | Yes |
| match → value / miss → 0 | Yes |
| `RET 4` | Yes |

---

## 5. Gaps / open

1. Full CNDHash object size / ctor / power-of-two mask invariant (not proven in this unit alone).
2. Bucket header full type (only `+0x04` used here).
3. Exact product name of node class / vtable `PTR_FUN_009cefd4` (Insert allocates it; out of scope).
4. Duplicate-key chain order when `allowDuplicate` paths exist elsewhere — Lookup returns **first** chain match (head is newest after Insert prepend).
5. Runtime live hash dump / bit-exact image diff not run.
6. Complete enumerated caller catalog (200+ sites; sample sealed, not full product matrix).

**Verdict:** **accept**
