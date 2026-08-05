# Review B (skeptical / adversarial): `aa_004bcae0` CNDHash_ReclaimToFreelist_009cb450

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bcae0` |
| **VA** | `0x004bcae0` |
| **Canonical name** | `CNDHash_ReclaimToFreelist_009cb450` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` |
| **Counterpart** | `reviews/A_aa_004bcae0_CNDHash_ReclaimToFreelist_009cb450.md` |
| **System** | container / CNDHash (tableC) |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Full FreeBuckets (frees slab/table) | Body never calls free/delete[]; only reclaim | **Falsified** as FreeBuckets |
| 2 | Non-owning freelist push only | Value path calls `(*vtbl)(1)` when non-null | **Falsified** pure non-owning |
| 3 | Same node layout as `004e2bd0` | Twin value `+0xC` / next `+0x10` / stamp `009cb360` | **Falsified** interchangeable |
| 4 | Loop is `i < mask` exclusive | Condition is `JBE` vs mask (`i <= mask`) | **Falsified** exclusive bound |
| 5 | Zeros count `+0x0C` | Parent FreeBuckets zeros count; this body does not | **Falsified** for this VA |
| 6 | Many static callers | Exactly 1 xref `004bcc6a` | **Agree** |
| 7 | PDB Reclaim proven | No body string | **Agree Open** product English |
| 8 | Named_VOG identity | Lock strings belong to dtor parent only | **Falsified** |

---

## 2. Live ≡ raw

```
Live decompile ≡ raw 2026-07-23.
read_memory: 53 55 56 33 C0 57 8B D9 … 5F 5E 5D 5B C3  (0x5F B).
Caller: FUN_004bcc60 @ 004bcc6a only.
Static callees: none (leaf + virtual call).
Twin FUN_004e2bd0: parallel CF; different node slots/stamps.
```

**Agree High** with A on ABI, loop bound, value slot, freelist push, sole caller.

---

## 3. Surviving contract

```
// void __thiscall CNDHash_ReclaimToFreelist_009cb450(hash*)
// i=0..mask incl.; destroy values @node+8; freelist @+0x20; clear heads.
// Do not free buckets/freelist heap. Do not use 004e2bd0 node map.
```

---

## 4. CF challenge of Review A

- Body 95 B / bare RET / ECX: **agree Confirmed**
- Owning reclaim + freelist push: **agree Confirmed**
- Twin split: **agree Confirmed**
- Name `CNDHash_ReclaimToFreelist_009cb450`: **agree acceptable**
- Product English residual: **agree Open** — not blocking

---

## 5. Residual risks

1. Concrete product type of value destroyed via vtbl(1).
2. Double-free if FreeBuckets called with corrupted freelist/table invariants.
3. Runtime / bit-exact / differential not run.

**Verdict:** **accept.** Agree with A on full structural contract; product English is non-blocking residual only.
