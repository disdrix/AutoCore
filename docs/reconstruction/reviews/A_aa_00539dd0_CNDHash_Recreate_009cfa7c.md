# Review A (reconstruction fidelity): `aa_00539dd0` CNDHash_Recreate_009cfa7c

| Field | Value |
|---|---|
| **Stable ID** | `aa_00539dd0` |
| **VA** | `0x00539dd0` |
| **Canonical name** | `CNDHash_Recreate` (object family vtbl `PTR_FUN_009cfa7c` / AllocBuckets `009cf014`) |
| **Inferred role** | Tear down + re-allocate CNDHash buckets (char mission-related hash at `+0x530`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw + bytes) |
| **Counterpart** | `reviews/B_aa_00539dd0_CNDHash_Recreate_009cfa7c.md` |
| **System** | container / CNDHash / missions-progression |
| **Dual status** | **Present — sealed 2026-07-29** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Twin of `FUN_00539d70` with **different** teardown/alloc stamps:

1. Lock `+0x1d` → log `"HashError:Recreate, already locked for traversal"` + `"VOG_DEBUG_STOP"`; **continue**.
2. `FUN_005390d0` — zero count; owning clear via `FUN_00538190` (node vtbl stamp `009cefe4` on freelist push); free slab + bucket table.
3. `+0x1c = bits`; `+0x18=0`; `+0x08 = 1<<bits`; `+0x14=0`.
4. `FUN_00537b50` AllocBuckets (sentinel stamp `PTR_LAB_009cf014`) → mask.

**ABI:** `__thiscall` + stack byte + **`RET 4`**.

Caller: `FUN_0052b4e0` — bulk mission-hash reset path:

```
FUN_00539dd0( *(char+0x530)->log2Bits );  // this unit
// then vtbl+4 clear on +0x548, +0x540, +0x538, +0x53c, +0x544
FUN_00539e30( *(char+0x55c)->log2Bits );
```

Ctor `FUN_00536920` builds the hash at **`param_1[0x14c]` → char+0x530** with object vtbl `009cfa7c`, bits=`4`, size=`0x10`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean | `raw/aa_00539dd0_*`, `reconstructed-exact/FUN_00539dd0.cpp` |
| Fresh decompile | `batch_decompile` @ `0x00539dd0` ≡ raw |
| Body image | `read_memory` — identical opcode skeleton to `00539d70`; epilogue `5E C2 04 00` |
| AllocBuckets dual | `A_aa_00537b50_CNDHash_AllocBuckets_009cf014.md` |
| Caller decompile | `FUN_0052b4e0` @ `0x0052b4e0` |
| Callers tool | sole static: `FUN_0052b4e0` |

**Not performed:** `disassemble_bytes`, Launcher, runtime, binary diff.

---

## 3. Evidence table

| Claim | Evidence | Confidence |
|---|---|---|
| CF skeleton ≡ `00539d70` | Byte-diff only call relocs | **High** |
| Teardown `005390d0` / clear `00538190` | Decompile | **High** |
| AllocBuckets `00537b50` / stamp `009cf014` | Call + sealed dual | **High** |
| Char slot **`+0x530`** | `FUN_0052b4e0` + ctor index `0x14c` | **High** |
| Owning value delete | `operator_delete` in `00538190` | **High** |
| Product hash English at `+0x530` | Not in system map primary list | **Open** |
| Runtime | Not run | **Open** |

---

## 4. Recovered CF

```c
// void __thiscall Recreate(CNDHash* this, uint8_t log2Bits)  // RET 4
if (this->lock) { log("HashError:Recreate, already locked…"); log("VOG_DEBUG_STOP"); }
Teardown_005390d0(this);           // owning clear; free table
this->log2Bits = log2Bits;         // +0x1c
this->tail = this->head = 0;       // +0x18, +0x14
this->size_or_mask = 1u << (log2Bits & 31);
AllocBuckets_00537b50(this);       // size → mask; sentinels 009cf014
```

---

## 5. Control flow: clean ≡ raw ≡ bytes

| Stage | Match |
|---|---|
| Lock-log-continue | **Yes** |
| Teardown → rewrite → AllocBuckets | **Yes** |
| Distinct from `00539d70`/`00539e30` callees | **Yes** |

---

## 6. Gaps

1. Product name for hash @ char+0x530 (not completed/active/pending labels from system map).
2. Full role of `FUN_0052b4e0` (mission wipe helper — not dualed here).
3. Runtime / bit-exact.

**Verdict:** **accept-with-gaps** — twin Recreate for `009cfa7c` / `+0x530` sealed High.
