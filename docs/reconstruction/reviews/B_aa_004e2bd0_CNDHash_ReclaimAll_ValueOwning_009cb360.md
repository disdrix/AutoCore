# Review B (skeptical / adversarial): `aa_004e2bd0` CNDHash_ReclaimAll_ValueOwning_009cb360

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e2bd0` |
| **VA** | `0x004e2bd0` |
| **Canonical name** | `CNDHash_ReclaimAll_ValueOwning_009cb360` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` |
| **Counterpart** | `reviews/A_aa_004e2bd0_CNDHash_ReclaimAll_ValueOwning_009cb360.md` |
| **System** | container / CNDHash |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Full FreeBuckets / dtor | FreeBuckets still zeros count + free slab/table after this; dtor still frees freelist | **Falsified** as complete FreeBuckets/dtor |
| 2 | Non-owning freelist recycle only | Bytes call `(*value_vtbl)(1)` when value non-null | **Falsified** pure non-owning |
| 3 | Zeros `count(+0x0C)` | Body never writes +0x0C | **Falsified** |
| 4 | Frees bucket table | No free/delete on +0x10 | **Falsified** |
| 5 | Twin-substitutable with `004bcae0` | Different stamp (`009cb360` vs `009cb358`); value@+C/next@+10 vs value@+8/next@+C | **Falsified** interchange |
| 6 | Uses `operator_delete` on values | Bytes use virtual delete arg 1, not CRT delete | **Agree** distinct from medal `00538200` path |
| 7 | Multiple static callers | Only xref `004bccaa` | **Agree** sole static caller |
| 8 | PDB name proven | No body string | **Agree Open** product; role High OK |
| 9 | Named_VOG_DEBUG_STOP identity | Lock strings live on Recreate/dtor parents only | **Falsified** |
| 10 | Stamp remains on freelist node | After stamp write, freelist push **overwrites** `*node` with next freelist pointer | **Agree** stamp is transient class-set; freelist link reuses slot 0 |

---

## 2. Live ≡ raw

```
Live decompile ≡ raw 2026-07-23.
read_memory: 53 55 56 33 C0 57 8B D9 … 5F 5E 5D 5B C3  (0x5E B).
Caller: FUN_004bcca0 @ 004bccaa only.
Stamp imm32: 60 B3 9C 00 → 009cb360.
Twin 004bcae0: same CF skeleton, relocated value/next offsets + stamp 009cb358.
```

---

## 3. Surviving contract

```
// void __thiscall CNDHash_ReclaimAll_ValueOwning_009cb360(hash*)
// for i in 0..mask inclusive:
//   walk chain; stamp 009cb360; delete value@+0xC via vtbl(1);
//   push node to freelist@+0x20; clear bucket head.
// Leaves count, table pointer, freelist storage, list ends for parent.
// Not interchangeable with 004bcae0 (009cb358 layout).
```

---

## 4. CF challenge of Review A

- Loop / own-delete / freelist / clear heads: **agree Confirmed**
- thiscall plain ret void: **agree Confirmed**
- Sole FreeBuckets caller: **agree Confirmed**
- Name `CNDHash_ReclaimAll_ValueOwning_009cb360`: **agree acceptable** (stamp-qualified ValueOwning family)
- Do not substitute twin `004bcae0`: **agree**

---

## 5. Residual risks

1. Product English (Reclaim vs Clear vs ReleaseNodes).
2. Exact C++ type of owned values under this stamp family.
3. Whether all `009cb45c` / shared-body hash users always own values (contract with FreeBuckets parents).
4. Runtime / bit-exact / differential not run.

**Verdict:** **accept-with-gaps.** Agree with A on ABI, CF, callers, ownership, and stamp-qualified name.
