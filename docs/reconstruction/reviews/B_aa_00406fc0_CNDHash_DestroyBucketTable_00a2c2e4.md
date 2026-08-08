# Review B (skeptical / adversarial): `aa_00406fc0` CNDHash_DestroyBucketTable_00a2c2e4

| Field | Value |
|---|---|
| **Stable ID** | `aa_00406fc0` |
| **VA** | `0x00406fc0` |
| **Canonical name** | `CNDHash_DestroyBucketTable_00a2c2e4` |
| **Review date** | `2026-08-04` (WQ9G-J dual) |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_00406fc0_CNDHash_DestroyBucketTable_00a2c2e4.md` |
| **Live tools** | Independent `batch_decompile` + `read_memory` + caller `get_assembly_context` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Zeros mask `@+0x08` | **Falsified** — only writes `@+0x0c` then table free |
| 2 | free(table) treats pointer array as slab | **Falsified** — `free(*table)` then `delete[] table` |
| 3 | Thiscall ECX (skill merge `0x004cba60`) | **Falsified** — EAX; callers `mov eax,esi` |
| 4 | Soft-fail if locked | **Falsified** — lock check is in parent dtor/Recreate, not here |
| 5 | No freelist step / free-only | **Falsified** — always calls `FUN_004085e0` |
| 6 | Tree erase / map free-subtree | **Falsified** — hash bucket destroy shape only |
| 7 | Product English sealed | **Fails** — stamp-family name |
| 8 | Runtime Confirmed / bit-exact | **Fails** — open; no Launcher |

---

## 2. Decisive machine dataflow

```text
// entry
EBX = EAX                 // hash
[EBX+0xc] = 0
CALL FUN_004085e0         // freelist walk; EBX=hash
EAX = [EBX+0x10]
if EAX != 0:
  push [EAX]; call free   // free slab
  push [EBX+0x10]; call operator_delete[]
  [EBX+0x10] = 0
pop ebx; ret
```

Caller dtor (`0040646e`): after optional `"HashError:Destructor, already locked for traversal"` + `VOG_DEBUG_STOP`, `mov eax,esi; call 00406fc0`.

Caller Recreate (`004195f6`): same EAX setup before re-seed + alloc twin.

A ≡ B on live decompile + free-shape bytes.

---

## 3. Confidence (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Destroy CF + free order | **High** | Double-free / leak |
| EAX ABI | **High** | Wrong port |
| Freelist helper existence | **High** | Node leak |
| Freelist full dual | **Open** | Payload-owning edge cases |
| Null-table freelist | **Open** | Crash if called empty (callers guard by construction) |
| Product English | **Open** | Naming only |

---

## 4. Surviving contract

```text
CNDHash_DestroyBucketTable_00a2c2e4:
  EAX = hash*
  zero live count@+0xc
  release chains to freelist (FUN_004085e0, EBX=hash)
  free slab + delete[] table; null +0x10
  bare ret; leave mask/log2/lock alone
```

**Verdict:** **accept-with-gaps**
