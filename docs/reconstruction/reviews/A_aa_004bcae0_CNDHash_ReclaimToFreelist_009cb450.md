# Review A (reconstruction fidelity): `aa_004bcae0` CNDHash_ReclaimToFreelist_009cb450

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bcae0` |
| **VA** | `0x004bcae0`–`0x004bcb3e` inclusive (**95 B** / `0x5F`) |
| **Canonical name** | `CNDHash_ReclaimToFreelist_009cb450` |
| **Ghidra name** | `FUN_004bcae0` |
| **Prior alias** | `Named_CalleeOf_*VOG_DEBUG_STOP_004bcae0` (**reject** as product id) |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Independent reconstruction fidelity (OWN-ONLY dual W37-G Path A) |
| **Counterpart** | `reviews/B_aa_004bcae0_CNDHash_ReclaimToFreelist_009cb450.md` |
| **System** | container / CNDHash (family `009cb450` / tableC) |
| **Live tools** | `batch_decompile`, `analyze_function_complete`, `get_function_by_address`, `read_memory` (full 95 B). **No** `disassemble_bytes`. |
| **Verdict** | **accept** |
| **Dual status** | **Present (first full dual)** — closes W31-M residual “full FUN_004bcae0 value matrix open” |

**Tools note:** No Launcher. No parent ledgers.

---

## 1. Purpose

Owning **reclaim-to-freelist** for tableC FreeBuckets:

```c
// ECX=hash*  bare RET  void
void CNDHash_ReclaimToFreelist_009cb450(void *hash /*ECX*/);
```

1. For `i = 0 … *(hash+8)` **inclusive** (mask):
2. Walk chain head `(*(hash+0x10))[i]->+4`.
3. Per node: stamp `PTR_FUN_009cb358`; if value `node+0x08` non-null → `(*vtbl)(1)`; null value; freelist-push via `*node = freelist; freelist = node` at `hash+0x20`.
4. Clear bucket head `bucket+4 = 0`.

**Not** FreeBuckets (count zero / slab free / delete[] table — parent `004bcc60`).  
**Not** freelist heap free (dtor path).

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | ≡ raw 2026-07-23 CF |
| Live bytes | full 95 B through `POP EBX; RET` + `CC` pad |
| Parent FreeBuckets | `CNDHash_FreeBuckets_009cb450` (`0x004bcc60`, W31-M) |
| Twin reclaim | `FUN_004e2bd0` (W37-J, not owned) — value `+0xC` / next `+0x10` / stamp `009cb360` |
| Pattern peer | `CNDHash_ReleaseNodesToFreelist_Inferred` (`0x00413ea0`) older family |

---

## 3. Authoritative body (bytes summary)

```text
004bcae0  PUSH EBX/EBP/ESI; XOR EAX,EAX; PUSH EDI; MOV EBX,ECX; XOR EBP,EBP
          ; loop i=EBP:
          ;   node = *(*(buckets[i])+4)
          ;   while node:
          ;     next = node[3]          ; +0x0C
          ;     *node = 009cb358
          ;     if node[2]: (*vtbl)(1)  ; value +0x08
          ;     node[2]=0; freelist push via +0x20
          ;   clear head; ++i; while i <= mask
004bcb3e  POP EDI/ESI/EBP/EBX; RET
```

Hex (95 B):  
`53 55 56 33 C0 57 8B D9 33 ED … 3B 6B 08 76 B6 5F 5E 5D 5B C3`

---

## 4. Layout

| Off | Field | Role |
|----:|---|---|
| hash `+0x08` | mask | inclusive upper bound |
| hash `+0x10` | buckets* | array of bucket* |
| hash `+0x20` | freelist | push target |
| node `+0x00` | stamp / freelist next | |
| node `+0x08` | value* | owned; vtbl(1) |
| node `+0x0C` | next | chain |

---

## 5. Naming

| Candidate | Decision |
|---|---|
| `CNDHash_ReclaimToFreelist_009cb450` | **Accept** — stamp-family FreeBuckets parent; reclaim role sealed |
| `FUN_004bcae0` | scaffold |
| Named_VOG_DEBUG_STOP | **Reject** |
| Interchange with `004e2bd0` | **Reject** (node slot/stamp split) |

---

## 6. Confidence

| Claim | Level |
|---|---|
| CF dual A ≡ raw ≡ live | **Confirmed** |
| ECX this / bare RET / 95 B | **Confirmed** |
| Value `+0x08` / next `+0x0C` / stamp `009cb358` | **Confirmed** |
| Sole FreeBuckets_009cb450 caller | **Confirmed** |
| Twin structural split | **Confirmed** |
| Product value-type English | **Open** (does not block accept) |
| Runtime / bit-exact / diff | **Open** |

**Verdict:** **accept.** Residual product English only; structural contract sealed.
