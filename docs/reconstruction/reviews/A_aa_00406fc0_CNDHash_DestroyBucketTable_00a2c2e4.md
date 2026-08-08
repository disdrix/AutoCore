# Review A (reconstruction fidelity): `aa_00406fc0` CNDHash_DestroyBucketTable_00a2c2e4

| Field | Value |
|---|---|
| **Stable ID** | `aa_00406fc0` |
| **VA** | `0x00406fc0` |
| **Canonical name** | `CNDHash_DestroyBucketTable_00a2c2e4` |
| **Prior alias** | `FUN_00406fc0` |
| **Review date** | `2026-08-04` (OWN-ONLY dual A/B — WQ9G-J) |
| **Reviewer role** | Independent reconstruction review (Path A fidelity) |
| **Counterpart** | `reviews/B_aa_00406fc0_CNDHash_DestroyBucketTable_00a2c2e4.md` |
| **System** | container / CNDHash (host vtbl `00a2c2b0`) |
| **Live tools** | Ghidra `batch_decompile`, `analyze_function_complete`, `read_memory`, callers/xrefs, `get_assembly_context` |
| **Partition** | `WAVE_2026-08-04_wq009_depth4_partition_map.md` → **WQ9G-J** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Destroy host-family **CNDHash** bucket pointer table: zero live count, release chain nodes to freelist, free contiguous 0xc sentinel slab + pointer array.

```text
// custom EAX = hash*; bare ret
*(hash+0x0c) = 0
FUN_004085e0()                 // EBX=hash; freelist-walk chains
if table = *(hash+0x10):
  free(*table)                 // contiguous slab
  delete[] table
  *(hash+0x10) = 0
```

**Not** skill destroy thiscall twin. **Not** free-only of table without freelist. **Not** tree erase.

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | `batch_decompile(0x00406fc0)` ≡ 2026-07-23 raw |
| Entry / body bytes | `read_memory` — `53 8B D8 C7 43 0C 00…` … free IAT … `delete[]` … `5B C3` |
| Body range | `0x00406fc0`–`0x00406ff3` (**52 B**) |
| Callers | dtor `00406420` @ `0040646e` (`mov eax,esi`); Recreate `004195d0` @ `004195f6` |
| Nested | `FUN_004085e0` freelist (EBX; residual) |
| Clean | `reconstructed-exact/CNDHash_DestroyBucketTable_00a2c2e4.cpp` |

---

## 3. ABI (SEALED)

| Slot | Role | Evidence |
|------|------|----------|
| **EAX** | hash* | entry `mov ebx,eax`; callers `mov eax,esi` |
| **EBX** | hash* (for freelist) | preserved into `FUN_004085e0` |
| stack | none | bare `ret` |
| return | void | no EAX produce |

---

## 4. Control flow: clean ≡ live

| Stage | Match |
|---|---|
| Zero live count `@+0x0c` | **Yes** |
| Freelist helper call | **Yes** (`FUN_004085e0`) |
| free(`*table`) then delete[] table | **Yes** |
| Null `+0x10` | **Yes** |
| Leaves mask/log2/lock alone | **Yes** |

---

## 5. Confidence

| Claim | Confidence |
|---|---|
| Role = destroy bucket table | **High** (CF + dtor/Recreate callers + HashError strings on parents) |
| EAX custom ABI / bare ret | **High** |
| free slab then delete[] | **High** |
| Nested freelist dual complete | **Open** (not OWN) |
| Product English | **Open** |
| Runtime / bit-exact | **Open** |

**Verdict:** **accept-with-gaps**
