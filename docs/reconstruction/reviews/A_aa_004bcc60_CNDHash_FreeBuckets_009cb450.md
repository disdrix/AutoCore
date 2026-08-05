# Review A (reconstruction fidelity): `aa_004bcc60` CNDHash_FreeBuckets_009cb450

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bcc60` |
| **VA** | `0x004bcc60`–`0x004bcc94` (**52 B / `0x34`**; plain `ret`) |
| **Canonical name** | `CNDHash_FreeBuckets_009cb450` |
| **Ghidra name** | `FUN_004bcc60` |
| **Prior alias** | `Named_CalleeOf_Named_VOG_DEBUG_STOP_004bcc60` (**reject** as product id) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction fidelity (OWN-ONLY dual W31-M Path A) |
| **Counterpart** | `reviews/B_aa_004bcc60_CNDHash_FreeBuckets_009cb450.md` |
| **System** | container / CNDHash (object family `009cb450` / tableC) |
| **Live tools** | `decompile_function`, `read_memory`, callers/callees/xrefs |
| **Verdict** | **accept-with-gaps** |
| **Dual status** | **Present (first full dual)** — closes W30-G residual “FreeBuckets FUN_004bcc60 not OWN” |

**Tools note:** No `disassemble_bytes`. No Launcher. No parent ledgers.

---

## 1. Purpose

**FreeBuckets / clear storage** for tableC CNDHash family `009cb450`:

```c
// __thiscall  plain ret
void CNDHash_FreeBuckets_009cb450(CNDHash *this);
```

1. `this+0xC` (count) ← **0**
2. `FUN_004bcae0(this)` — iterate buckets `0…mask`, destroy values, freelist push `+0x20`, clear heads
3. If `this+0x10` ≠ 0: `free(*buckets)` slab + `delete[]` table + null

**Not** freelist teardown; **not** list head/tail zero.

**Twin of** `CNDHash_FreeBuckets_009cb45c` (`0x004bcca0`): same 52 B opcode skeleton; reclaim target `FUN_004bcae0` vs `FUN_004e2bd0` is the structural family split.

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | ≡ raw 2026-07-23 CF |
| Live bytes | full body through `POP ESI; RET` + `CC` pad |
| Alloc twin | `FUN_004bc7a0` / `CNDHash_AllocBucketTable_009cb348` (W29-K) |
| Reclaim callee | `FUN_004bcae0` — freelist push; value delete; node stamp `009cb358` |
| Caller Recreate | sealed dual `aa_004bcce0` `CNDHash_Recreate_009cb450` (W30-G) |
| Caller dtor | `FUN_004bd0b0` — vtbl `009cb450`, lock-warn, then this, then `FUN_0059c8a0` |
| Twin FreeBuckets | `0x004bcca0` (this dual) |

---

## 3. Authoritative body (bytes)

```text
004bcc60  PUSH ESI
004bcc61  MOV  ESI, ECX
004bcc63  MOV  dword ptr [ESI+0xC], 0
004bcc6a  CALL FUN_004bcae0          ; E8 71 FE FF FF → 004bcae0
004bcc6f  MOV  EAX, [ESI+0x10]
004bcc72  TEST EAX, EAX
004bcc74  JZ   done
004bcc76  MOV  EAX, [EAX]
004bcc78  PUSH EAX
004bcc79  CALL [free]                ; FF 15 24 65 9C 00
004bcc7f  MOV  ECX, [ESI+0x10]
004bcc82  PUSH ECX
004bcc83  CALL operator_delete[]     ; → 0048981c
004bcc88  ADD  ESP, 8
004bcc8b  MOV  dword ptr [ESI+0x10], 0
004bcc92  POP  ESI
004bcc93  RET
```

Hex:  
`56 8B F1 C7 46 0C 00 00 00 00 E8 71 FE FF FF 8B 46 10 85 C0 74 1C 8B 00 50 FF 15 24 65 9C 00 8B 4E 10 51 E8 94 CB FC FF 83 C4 08 C7 46 10 00 00 00 00 5E C3`

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
| `CNDHash_FreeBuckets_009cb450` | **Accept** — stamp-qualified FreeBuckets parallel to Recreate/Alloc/Ctor |
| `FUN_004bcc60` | scaffold |
| Named_CalleeOf VOG_DEBUG_STOP | **Reject** product identity |

---

## 6. Confidence

| Claim | Level |
|---|---|
| CF dual A ≡ raw ≡ live | **Confirmed** |
| `__thiscall` plain ret | **Confirmed** |
| Twin reloc-only vs `004bcca0` | **Confirmed** |
| Callers Recreate + dtor only | **Confirmed** (2 xrefs) |
| free(*buckets) = slab | **High** (matches Alloc) |
| Role FreeBuckets | **High** |
| Product/PDB symbol | **Open** |
| Full `FUN_004bcae0` value matrix | **Open** |
| Runtime / bit-exact / diff | **Open** |

**Verdict:** **accept-with-gaps.**
