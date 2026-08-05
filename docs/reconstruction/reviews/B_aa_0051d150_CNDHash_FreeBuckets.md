# Review B (skeptical / adversarial): `aa_0051d150` CNDHash_FreeBuckets

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051d150` |
| **VA** | `0x0051d150` |
| **Canonical name** | `CNDHash_FreeBuckets` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0051d150_CNDHash_FreeBuckets.md` |
| **System** | container / medal CNDHash |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Full object destructor | Dtor `FUN_0051dfe0` still runs freelist helper after this | **Falsified** as complete dtor |
| 2 | Frees freelist `+0x20` | Body never touches `+0x20` | **Falsified** |
| 3 | Zeros list head/tail | Only Recreate writes `+0x14`/`+0x18` after call | **Falsified** for this VA |
| 4 | `free(buckets)` directly | Bytes `MOV EAX,[EAX]; PUSH; free` → free **\*buckets** | **Falsified** free-table-pointer-as-slab |
| 5 | Non-owning reclaim only | `FUN_0051bfb0` deletes node+8 values when non-null | **Falsified** pure non-owning |
| 6 | Many static callers | Exactly 2 xrefs: Recreate + dtor | **Agree** |
| 7 | PDB name FreeBuckets proven | No string on body; family analogy | **Agree Open** product; role High OK |
| 8 | Named_VOG_DEBUG_STOP identity | Lock strings are parent Recreate/dtor only | **Falsified** |

---

## 2. Live ≡ raw

```
Live decompile ≡ raw.
read_memory: 56 8B F1 C7 46 0C 00… E8 … 5E C3  (0x33 B).
Callers: 0051d256 (Recreate), 0051e02e (dtor).
```

Alloc twin cross-check (`FUN_0051ba40`):

```
new[](N*4) → +0x10 table
malloc(N*0xC) → slab; buckets[i] = slab + i*0xC
mask = N-1
```

⇒ `free(*buckets)` releases slab base; `delete[]` releases table. **Agree High** with A.

---

## 3. Surviving contract

```
// void __thiscall CNDHash_FreeBuckets(hash*)
// count=0; reclaim all entries to freelist (values destroyed in reclaim);
// free sentinel slab + bucket pointer table; buckets=null.
// Leaves freelist storage and list head/tail for parent to handle.
```

---

## 4. CF challenge of Review A

- Zero / reclaim / free / null: **agree Confirmed**
- thiscall: **agree Confirmed**
- Not full dtor: **agree** (explicit gap)
- FreeBuckets name without stamp suffix: **agree acceptable** — other FreeBuckets use `009cfa*` method stamps; this family pairs with Recreate string + dtor vtbl `009ce1a0`. Optional future rename `CNDHash_FreeBuckets_009ce1a0` if registry collision appears; none today.
- Do not merge with owning FreeBuckets stamped siblings: **agree**

---

## 5. Residual risks

1. `FUN_0051bfb0` exact value type / when `FUN_00604e30` runs (callee residual).
2. Double-free if `buckets` non-null but slab already freed (caller contract).
3. Product English FreeBuckets vs Clear vs Destroy.
4. Runtime / bit-exact / differential not run.

**Verdict:** **accept-with-gaps.** Agree with A on ABI, CF, callers, and FreeBuckets role.
