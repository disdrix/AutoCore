# Review B (skeptical / adversarial): `aa_004bcc60` CNDHash_FreeBuckets_009cb450

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bcc60` |
| **VA** | `0x004bcc60` |
| **Canonical name** | `CNDHash_FreeBuckets_009cb450` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004bcc60_CNDHash_FreeBuckets_009cb450.md` |
| **System** | container / CNDHash (tableC) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Full object destructor | Dtor `FUN_004bd0b0` still runs freelist helper after this | **Falsified** as complete dtor |
| 2 | Frees freelist `+0x20` | Body never touches `+0x20` | **Falsified** |
| 3 | Zeros list head/tail | Only Recreate writes `+0x14`/`+0x18` after call | **Falsified** for this VA |
| 4 | `free(buckets)` directly | Bytes free **\*buckets** (slab), then delete[] table | **Falsified** free-table-as-slab |
| 5 | Interchangeable with `004bcca0` | Reclaim `004bcae0` vs `004e2bd0`; different value slots / node stamps | **Falsified** |
| 6 | Non-owning reclaim | `FUN_004bcae0` virtual-deletes values before freelist push | **Falsified** pure non-owning |
| 7 | Many static callers | Exactly 2 xrefs: Recreate + dtor | **Agree** |
| 8 | PDB FreeBuckets proven | No body string | **Agree Open** product |
| 9 | Named_VOG identity | Lock strings are parent only | **Falsified** |

---

## 2. Live ≡ raw

```
Live decompile ≡ raw 2026-07-23.
read_memory: 56 8B F1 C7 46 0C 00… E8 71 FE FF FF … 5E C3  (0x34 B).
Callers: 004bcd06 (Recreate_009cb450), 004bd0fe (dtor 009cb450).
Twin hex vs 004bcca0: differ only reclaim E8 rel + operator_delete[] E8 rel.
```

Alloc twin cross-check (`FUN_004bc7a0` / W29-K): sentinel stamp `009cb348`; same table+slab layout ⇒ `free(*buckets)` = slab free. **Agree High** with A.

---

## 3. Surviving contract

```
// void __thiscall CNDHash_FreeBuckets_009cb450(hash*)
// count=0; reclaim via FUN_004bcae0; free slab + delete[] table; buckets=null.
// Leaves freelist and list ends for parent. Do not use 004bcca0 reclaim path.
```

---

## 4. CF challenge of Review A

- Zero / reclaim / free / null: **agree Confirmed**
- thiscall: **agree Confirmed**
- Twin reloc-only: **agree Confirmed**
- FreeBuckets_009cb450 name: **agree acceptable**
- Do not merge with `004bcca0`: **agree**

---

## 5. Residual risks

1. `FUN_004bcae0` exact value type / slot (+8 vs twin reclaim +0xC) — callee residual.
2. Double-free if caller violates table invariant.
3. Product English.
4. Runtime / bit-exact / differential not run.

**Verdict:** **accept-with-gaps.** Agree with A on ABI, CF, callers, twin split, and FreeBuckets role.
