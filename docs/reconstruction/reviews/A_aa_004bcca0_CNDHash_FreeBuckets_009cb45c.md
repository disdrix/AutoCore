# Review A (reconstruction fidelity): `aa_004bcca0` CNDHash_FreeBuckets_009cb45c

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bcca0` |
| **VA** | `0x004bcca0`–`0x004bccd4` (**52 B / `0x34`**; plain `ret`) |
| **Canonical name** | `CNDHash_FreeBuckets_009cb45c` |
| **Ghidra name** | `FUN_004bcca0` |
| **Prior alias** | `Named_CalleeOf_Named_VOG_DEBUG_STOP_004bcca0` (**reject** as product id) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction fidelity (OWN-ONLY dual W31-M Path A) |
| **Counterpart** | `reviews/B_aa_004bcca0_CNDHash_FreeBuckets_009cb45c.md` |
| **System** | container / CNDHash (object family `009cb45c` primary) |
| **Live tools** | `decompile_function`, `read_memory`, callers/callees/xrefs |
| **Verdict** | **accept-with-gaps** |
| **Dual status** | **Present (first full dual)** — closes W30-G residual “FreeBuckets body FUN_004bcca0 not OWN” |

**Tools note:** No `disassemble_bytes`. No Launcher. No parent ledgers.

---

## 1. Purpose

**FreeBuckets / clear storage** for primary CNDHash family `009cb45c` (body also shared with `009cc6c0` dtor + parallel Recreate):

```c
// __thiscall  plain ret
void CNDHash_FreeBuckets_009cb45c(CNDHash *this);
```

1. `this+0xC` (count) ← **0**
2. `FUN_004e2bd0(this)` — iterate buckets `0…mask`, destroy values, push nodes onto freelist `+0x20`, clear per-bucket heads
3. If `this+0x10` (buckets*) ≠ 0:
   - `free(*buckets)` — contiguous sentinel slab (alloc twin `FUN_004bc840` writes `buckets[i]=slab+i*0xC`)
   - `operator_delete[](buckets)` — pointer table
   - `buckets ← 0`

**Not** freelist vector teardown (`+0x20` survives for Recreate; dtor calls `FUN_0059c8a0` after).  
**Not** list head/tail zero (Recreate stores 0 to `+0x14`/`+0x18` after this).

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | ≡ raw 2026-07-23 CF |
| Live bytes | full body through `POP ESI; RET` + `CC` pad |
| Alloc twin | `FUN_004bc840` / `CNDHash_AllocBucketTable_009cb350` (W29-K) |
| Reclaim callee | `FUN_004e2bd0` — freelist push; value delete; node stamp `009cb360` |
| Caller Recreate | sealed dual `aa_004bcd40` `CNDHash_Recreate_009cb45c` (W30-G) |
| Caller dtor | `FUN_004bd140` — vtbl `009cb45c`, lock-warn, then this, then freelist helper |
| Extra callers | `FUN_004e4990` (parallel Recreate); `FUN_004e66a0` (vtbl `009cc6c0` dtor) |
| Twin FreeBuckets | `0x004bcc60` / `CNDHash_FreeBuckets_009cb450` (this dual) |
| Medal parallel | `CNDHash_FreeBuckets` `0x0051d150` (W24-H) |

---

## 3. Authoritative body (bytes)

```text
004bcca0  PUSH ESI
004bcca1  MOV  ESI, ECX
004bcca3  MOV  dword ptr [ESI+0xC], 0
004bccaa  CALL FUN_004e2bd0          ; E8 21 5F 02 00 → 004e2bd0
004bccaf  MOV  EAX, [ESI+0x10]
004bccb2  TEST EAX, EAX
004bccb4  JZ   done
004bccb6  MOV  EAX, [EAX]            ; *buckets
004bccb8  PUSH EAX
004bccb9  CALL [free]                ; FF 15 24 65 9C 00
004bccbf  MOV  ECX, [ESI+0x10]
004bccc2  PUSH ECX
004bccc3  CALL operator_delete[]     ; → 0048981c
004bccc8  ADD  ESP, 8
004bcccb  MOV  dword ptr [ESI+0x10], 0
004bccd2  POP  ESI
004bccd3  RET
```

Hex:  
`56 8B F1 C7 46 0C 00 00 00 00 E8 21 5F 02 00 8B 46 10 85 C0 74 1C 8B 00 50 FF 15 24 65 9C 00 8B 4E 10 51 E8 54 CB FC FF 83 C4 08 C7 46 10 00 00 00 00 5E C3`

---

## 4. Layout (this body)

| Off | Field | Mutation |
|---|---|---|
| `+0x0C` | count | ← 0 |
| `+0x10` | buckets* | free slab + delete[] table + null |
| `+0x08` | mask | unread here (reclaim uses) |
| `+0x14`/`+0x18` | list ends | untouched |
| `+0x20` | freelist | reclaim fills; not freed |

---

## 5. Naming

| Candidate | Decision |
|---|---|
| `CNDHash_FreeBuckets_009cb45c` | **Accept** — FreeBuckets family vocabulary + primary object vtbl stamp (parallel Recreate/Alloc/Ctor naming) |
| `CNDHash_FreeBuckets_Owning_009cb45c` | Acceptable alias; reclaim is value-owning; prefer shorter stamp form unless NonOwning twin collides |
| `FUN_004bcca0` | scaffold |
| Named_CalleeOf VOG_DEBUG_STOP | **Reject** product identity |

No body string; name is structural/family (**High**), not PDB. Stamp is **primary** family — body is also reachable from `009cc6c0` dtor (document as shared).

---

## 6. Confidence

| Claim | Level |
|---|---|
| CF dual A ≡ raw ≡ live | **Confirmed** |
| `__thiscall` plain ret | **Confirmed** |
| count zero + free table | **Confirmed** |
| free(*buckets) = slab | **High** (matches Alloc layout) |
| Callers 4 static xrefs | **Confirmed** |
| Role FreeBuckets | **High** |
| Product/PDB symbol | **Open** |
| Full `FUN_004e2bd0` value matrix | **Open** |
| Runtime / bit-exact / diff | **Open** |

**Verdict:** **accept-with-gaps.**
