# Review A (reconstruction fidelity): `aa_0051d150` CNDHash_FreeBuckets

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051d150` |
| **VA** | `0x0051d150`–`0x0051d183` (**0x33** bytes; plain `ret`) |
| **Canonical name** | `CNDHash_FreeBuckets` |
| **Ghidra name** | `FUN_0051d150` |
| **Prior alias** | `Named_CalleeOf_Named_VOG_DEBUG_STOP_0051d150` (**reject** as product id) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction fidelity (OWN-ONLY dual W24-H Path A) |
| **Counterpart** | `reviews/B_aa_0051d150_CNDHash_FreeBuckets.md` |
| **System** | container / missions-progression (medal CNDHash) |
| **Live tools** | `decompile_function`, `read_memory`, `get_function_by_address`, callers/callees/xrefs |
| **Verdict** | **accept-with-gaps** |
| **Dual status** | **Present (first full dual)** — closes Recreate open “full destroy semantics of FUN_0051d150” |

**Tools note:** No `disassemble_bytes`. No Launcher. No parent ledgers.

---

## 1. Purpose

**FreeBuckets / clear storage** for the medal-family CNDHash:

```c
// __thiscall  plain ret
void CNDHash_FreeBuckets(CNDHash *this);
```

1. `this+0xC` (count) ← **0**
2. `FUN_0051bfb0(this)` — iterate buckets `0…mask`, destroy values, push nodes onto freelist `+0x20`, clear per-bucket heads
3. If `this+0x10` (buckets*) ≠ 0:
   - `free(*buckets)` — contiguous sentinel slab (alloc twin writes `buckets[i]=slab+i*0xC`)
   - `operator_delete[](buckets)` — pointer table
   - `buckets ← 0`

**Not** freelist vector teardown (`+0x20` survives for Recreate; dtor calls `FUN_0059c8a0` after).  
**Not** list head/tail zero (Recreate stores 0 to `+0x14`/`+0x18` after this).

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | ≡ raw 2026-07-23 |
| Live bytes | full body through `POP ESI; RET` |
| Alloc twin | `FUN_0051ba40` — `new[]` table + `malloc` slab + vtbl `009ce090` |
| Reclaim callee | `FUN_0051bfb0` — freelist push; value delete path |
| Caller Recreate | sealed dual `aa_0051d230` (string `"HashError:Recreate…"`) |
| Caller dtor | `FUN_0051dfe0` — vtbl `009ce1a0`, lock-warn string, then this, then freelist helper |
| Sibling FreeBuckets | owning/non-owning stamped families (`009cfa*`) — same role pattern |
| Insert sibling | `CNDHash_Insert_009ce0a8` |

---

## 3. Authoritative body (bytes)

```text
0051d150  PUSH ESI
0051d151  MOV  ESI, ECX
0051d153  MOV  dword ptr [ESI+0xC], 0
0051d15a  CALL FUN_0051bfb0
0051d15f  MOV  EAX, [ESI+0x10]
0051d162  TEST EAX, EAX
0051d164  JZ   done
0051d166  MOV  EAX, [EAX]           ; *buckets
0051d168  PUSH EAX
0051d169  CALL [free]
0051d16f  MOV  ECX, [ESI+0x10]
0051d172  PUSH ECX
0051d173  CALL operator_delete[]
0051d178  ADD  ESP, 8
0051d17b  MOV  dword ptr [ESI+0x10], 0
0051d182  POP  ESI
0051d183  RET
```

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
| `CNDHash_FreeBuckets` | **Accept** — same role as sealed FreeBuckets siblings; callers Recreate + dtor |
| `CNDHash_ClearAndFreeBuckets` | Acceptable alias; prefer FreeBuckets family vocabulary |
| `FUN_0051d150` | scaffold |
| Named_CalleeOf VOG_DEBUG_STOP | **Reject** product identity |

No body string; name is structural/family (High), not PDB.

---

## 6. Confidence

| Claim | Level |
|---|---|
| CF dual A ≡ raw ≡ live | **Confirmed** |
| `__thiscall` plain ret | **Confirmed** |
| count zero + free table | **Confirmed** |
| free(*buckets) = slab | **High** (matches Alloc layout) |
| Callers Recreate + dtor only | **Confirmed** (2 xrefs) |
| Role FreeBuckets | **High** |
| Product/PDB symbol | **Open** |
| Full `FUN_0051bfb0` value matrix | **Open** |
| Runtime / bit-exact / diff | **Open** |

**Verdict:** **accept-with-gaps.**
