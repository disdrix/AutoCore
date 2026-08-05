# Review B (skeptical / adversarial): `aa_004bcca0` CNDHash_FreeBuckets_009cb45c

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bcca0` |
| **VA** | `0x004bcca0` |
| **Canonical name** | `CNDHash_FreeBuckets_009cb45c` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004bcca0_CNDHash_FreeBuckets_009cb45c.md` |
| **System** | container / CNDHash |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Full object destructor | Dtor `FUN_004bd140` / `FUN_004e66a0` still run freelist helper `FUN_0059c8a0` after this | **Falsified** as complete dtor |
| 2 | Frees freelist `+0x20` | Body never touches `+0x20` | **Falsified** |
| 3 | Zeros list head/tail | Only Recreate writes `+0x14`/`+0x18` after call | **Falsified** for this VA |
| 4 | `free(buckets)` directly | Bytes `MOV EAX,[EAX]; PUSH; free` → free **\*buckets** | **Falsified** free-table-pointer-as-slab |
| 5 | Family-exclusive to `009cb45c` | Also called from dtor `FUN_004e66a0` (vtbl `009cc6c0`) + Recreate `FUN_004e4990` | **Agree** stamp is **primary**, body **shared** — document gap, not reject role |
| 6 | Non-owning reclaim only | `FUN_004e2bd0` virtual-deletes value slots before freelist push | **Falsified** pure non-owning |
| 7 | PDB name FreeBuckets proven | No string on body; family analogy | **Agree Open** product; role High OK |
| 8 | Named_VOG_DEBUG_STOP identity | Lock strings are parent Recreate/dtor only | **Falsified** |
| 9 | Twin-substitutable with `004bcc60` | Distinct reclaim (`004e2bd0` vs `004bcae0`); different node/value layouts | **Falsified** interchange |

---

## 2. Live ≡ raw

```
Live decompile ≡ raw 2026-07-23.
read_memory: 56 8B F1 C7 46 0C 00… E8 21 5F 02 00 … 5E C3  (0x34 B).
Callers: 004bcd66 (Recreate_009cb45c), 004bd18e (dtor 009cb45c),
         004e49b6 (parallel Recreate), 004e66ee (dtor 009cc6c0).
```

Alloc twin cross-check (`FUN_004bc840` / W29-K):

```
new[](N*4) → +0x10 table
malloc(N*0xC) → slab; buckets[i] = slab + i*0xC; stamp 009cb350
mask = N-1
```

⇒ `free(*buckets)` releases slab base; `delete[]` releases table. **Agree High** with A.

---

## 3. Surviving contract

```
// void __thiscall CNDHash_FreeBuckets_009cb45c(hash*)
// count=0; reclaim all entries to freelist (values destroyed in reclaim);
// free sentinel slab + bucket pointer table; buckets=null.
// Leaves freelist storage and list head/tail for parent to handle.
// Body shared beyond primary 009cb45c (see callers).
```

---

## 4. CF challenge of Review A

- Zero / reclaim / free / null: **agree Confirmed**
- thiscall plain ret: **agree Confirmed**
- Not full dtor: **agree**
- FreeBuckets name with primary stamp: **agree acceptable** — optional future rename if multi-family registry collision needs reclaim-stamp qualifier (`009cb360`); none required today
- Do not substitute tableC twin `004bcc60`: **agree**

---

## 5. Residual risks

1. `FUN_004e2bd0` exact value type / virtual-delete slot (callee residual).
2. Shared body with `009cc6c0` — stamp name is primary-family, not exclusive.
3. Double-free if `buckets` non-null but slab already freed (caller contract).
4. Product English FreeBuckets vs Clear vs Destroy.
5. Runtime / bit-exact / differential not run.

**Verdict:** **accept-with-gaps.** Agree with A on ABI, CF, callers, and FreeBuckets role.
