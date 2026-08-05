# Review A (reconstruction fidelity): `aa_00539d70` CNDHash_Recreate_009cfa64

| Field | Value |
|---|---|
| **Stable ID** | `aa_00539d70` |
| **VA** | `0x00539d70` |
| **Canonical name** | `CNDHash_Recreate` (object family vtbl `PTR_FUN_009cfa64` / AllocBuckets `009cf004`) |
| **Inferred role** | Tear down + re-allocate CNDHash buckets for a new log2 size |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw + bytes) |
| **Counterpart** | `reviews/B_aa_00539d70_CNDHash_Recreate_009cfa64.md` |
| **System** | container / CNDHash family / character mission-skill tables |
| **Dual status** | **Present — sealed 2026-07-29** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

`__thiscall` **Recreate** on a CNDHash whose AllocBuckets twin is `FUN_00537a10` (sentinel vtbl `PTR_LAB_009cf004`, object vtbl family `009cfa64`):

1. If traversal lock `this+0x1d != 0`: log `"HashError:Recreate, already locked for traversal"` then `"VOG_DEBUG_STOP"` — **does not return**; continues.
2. `FUN_00539090(this)` — zero count, **owning** clear of all bucket chains (`FUN_00538120`: `operator_delete` values, freelist-push nodes), free sentinel slab + bucket pointer table, null `+0x10`.
3. Store new log2 bits at `this+0x1c` from stack arg.
4. Zero list tail `+0x18` and head `+0x14`.
5. Provisional bucket **count** `this+0x08 = 1 << (bits & 0x1f)`.
6. `FUN_00537a10(this)` — AllocBuckets; converts `+0x08` size → **mask** (`N-1`).

**ABI:** one stack byte (promoted) + `RET 4` (`C2 04 00`).

Sole static caller (live): `CVOGCharacter_ApplyCreateFromPacket` @ `0x00534bd0` — passes current bits from hash at character slot **`+0x534`** (`param_1[0x14d]` in ctor `FUN_00536920`) before re-inserting packet skill triples.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00539d70_FUN_00539d70.md` |
| Annotated | `docs/reconstruction/raw/aa_00539d70_FUN_00539d70.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00539d70.cpp` |
| Function record | `docs/reconstruction/functions/aa_00539d70_FUN_00539d70.md` |
| Fresh decompile | Ghidra `batch_decompile` @ `0x00539d70` (2026-07-29) ≡ raw 2026-07-23 |
| Body image | `read_memory` @ `0x00539d70` — lock `cmp [esi+0x1d]`; `shl eax,cl`; stores `+0x1c/+0x18/+0x08/+0x14`; epilogue `5E C2 04 00` |
| Teardown | `FUN_00539090` → `FUN_00538120` (owning value delete + freelist) |
| AllocBuckets dual | `A_aa_00537a10_CNDHash_AllocBuckets_009cf004.md` |
| Caller | `get_function_callers` → only `CVOGCharacter_ApplyCreateFromPacket` |
| Twin Recreates | `0x00539dd0` (`009cfa7c`/`009cf014`), `0x00539e30` (`009cfa88`/`009cf01c`) |

**Not performed:** `disassemble_bytes`, Launcher, runtime capture, binary diff.

---

## 3. Evidence table

| Claim | Evidence | Confidence |
|---|---|---|
| `__thiscall(this, byte log2Bits)` + **`RET 4`** | Entry `mov esi,ecx`; epilogue `pop esi; ret 4` | **High** |
| Lock check continues (not early-out) | `je` skips logs only; both paths call teardown | **High** |
| Strings Recreate-locked + VOG_DEBUG_STOP | Push imm before `FUN_007a4480` | **High** |
| Teardown frees table + owning values | `FUN_00539090` / `FUN_00538120` decompile | **High** |
| Bits @ `+0x1c`, size@`+0x08=1<<bits`, head/tail zero | Body stores | **High** |
| AllocBuckets `FUN_00537a10` → mask | Sealed dual + call site | **High** |
| Character hash slot **`+0x534`** | Ctor stores hash* at `param_1[0x14d]`; ApplyCreate uses `-0x86c` secondary path → same family | **High** (slot) / **Probable** product English |
| Product export name `Recreate` | Inferred from string; no PDB | **Open** |
| Runtime / bit-exact | Not run | **Open** |

---

## 4. Sealed layout (hash object, after Recreate)

```
CNDHash (this)  // footprint ≥ 0x34; object vtbl 009cfa64 when from char ctor
  +0x08  mask = (1<<bits)-1     // after AllocBuckets
  +0x0c  count = 0              // zeroed in teardown
  +0x10  buckets*               // new table
  +0x14  list head = 0
  +0x18  list tail = 0
  +0x1c  log2Bits (u8)
  +0x1d  lock (must be 0 for clean recreate; logged if set)
  +0x20  freelist head          // nodes reclaimed during teardown (not wiped)
```

---

## 5. Control flow: clean ≡ raw ≡ bytes

| Stage | Match |
|---|---|
| Lock log then fall through | **Yes** |
| Teardown then field rewrite then AllocBuckets | **Yes** |
| No invent of Insert/Remove semantics | **Yes** |
| Single `RET 4` | **Yes** |

---

## 6. Gaps

1. Product / export English name beyond string-inferred Recreate.
2. Exact English for character hash at `+0x534` (skill-related insert in ApplyCreate — product label open).
3. Whether freelist slab vector `+0x28..` must be empty (not touched here).
4. Runtime lock-hit capture.

**Verdict:** **accept-with-gaps** — Recreate CF, ABI, twin stamp, and `+0x534` consumer sealed High.
