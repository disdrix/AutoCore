# Review A (reconstruction fidelity): `aa_004e2bd0` CNDHash_ReclaimAll_ValueOwning_009cb360

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e2bd0` |
| **VA** | `0x004e2bd0`–`0x004e2c2e` exclusive (**94 B** / `0x5E`; plain `ret`) |
| **Canonical name** | `CNDHash_ReclaimAll_ValueOwning_009cb360` |
| **Ghidra name** | `FUN_004e2bd0` |
| **Prior alias** | `Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_004e2bd0` (**reject** as product id) |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Independent reconstruction fidelity (OWN-ONLY dual W37-J Path A) |
| **Counterpart** | `reviews/B_aa_004e2bd0_CNDHash_ReclaimAll_ValueOwning_009cb360.md` |
| **System** | container / CNDHash (node freelist stamp `009cb360`) |
| **Live tools** | `batch_decompile`, `analyze_function_complete`, `read_memory`, callers/xrefs |
| **Verdict** | **accept-with-gaps** |
| **Dual status** | **Present (first full dual)** — closes W31-M residual “full value-ownership matrix inside reclaim FUN_004e2bd0” |

**Tools note:** No `disassemble_bytes`. No Launcher. No parent ledgers.

---

## 1. Purpose

**Owning full-bucket reclaim** for CNDHash family using node freelist stamp **`009cb360`**:

```c
// __thiscall  plain ret  void
void CNDHash_ReclaimAll_ValueOwning_009cb360(CNDHash *this);
```

For `i = 0 .. mask(+0x08)` **inclusive**:

1. Walk chain at `buckets[i]->head` (`*(bucket+4)`).
2. Per node: stamp `PTR_FUN_009cb360`; if `value(+0x0C)` non-null call `(*vtbl)(1)` (scalar-deleting destroy); null value; push node onto freelist `+0x20` (intrusive `*node = old; freelist = node`).
3. Clear bucket head.

**Does not:** zero `count(+0x0C)`; free table `+0x10`; free freelist storage; touch list head/tail.

**Sole caller:** FreeBuckets `CNDHash_FreeBuckets_009cb45c` (`0x004bcca0`) @ `0x004bccaa` (zeros count then this then free slab/table).

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | ≡ raw 2026-07-23 CF |
| Live bytes | full 94 B through `POP EBX; RET` + `CC` pad |
| FreeBuckets parent | `aa_004bcca0` dual W31-M |
| Twin reclaim | `FUN_004bcae0` @ `0x004bcae0` stamp `009cb358` (value@+8 / next@+C) |
| Parallel named | `CNDHash_ReclaimAll_ValueOwning_009cefec` @ `0x00538200` (W18-J) |
| ReleaseNodes sibling | `CNDHash_ReleaseNodesToFreelist_Inferred` @ `0x00413ea0` (same value@+C / next@+10 pattern) |

---

## 3. Authoritative body (bytes)

Prologue / loop essence (from `read_memory`):

```text
004e2bd0  PUSH EBX / EBP / ESI
004e2bd4  XOR  EAX,EAX
004e2bd6  PUSH EDI
004e2bd7  MOV  EBX,ECX              ; this
004e2bd9  XOR  EBP,EBP              ; i = 0
...
          MOV  ECX,[EBX+0x10]       ; buckets
          MOV  EDX,[ECX+EBP*4]
          MOV  EDI,[EDX+4]          ; head
          ... walk; C7 06 60 B3 9C 00  ; *node = 009cb360
          ... if value: PUSH 1; CALL [vtbl]
          ... freelist push via [EBX+0x20]
          INC  EBP
          CMP  EBP,[EBX+8]
          JBE  loop
004e2c29  POP  EDI/ESI/EBP/EBX
004e2c2d  RET
```

Full hex:  
`53555633c0578bd933ed8d9b000000008b4b108b14a98b7a043bf8742c8d49008bf78b4e0c3bc88b7f10c70660b39c0074088b016a01ff1033c03bf889460c8b4b20890e89732075d78b53108b0caa83c5018941043b6b0876b65f5e5d5bc3`

---

## 4. Layout (this body)

| Off | Field | Mutation |
|---|---|---|
| `+0x08` | mask | read (`i <= mask`) |
| `+0x10` | buckets* | read (heads cleared) |
| `+0x20` | freelist | filled with reclaimed nodes |
| node`+0x0C` | value* | vcall(1) then 0 |
| node`+0x10` | chain next | walk |
| node`+0x00` | vtbl/freelist | stamp then freelist link |

---

## 5. Naming

| Candidate | Decision |
|---|---|
| `CNDHash_ReclaimAll_ValueOwning_009cb360` | **Accept** — matches W18-J `…_ValueOwning_<stamp>` vocabulary; stamp is freelist-class vtbl written into nodes |
| `CNDHash_ReleaseNodesToFreelist_009cb360` | Acceptable alias (parallel `00413ea0`); prefer ValueOwning form for owning delete |
| `FUN_004e2bd0` | scaffold |
| Named_CalleeOf VOG_DEBUG_STOP | **Reject** product identity |

---

## 6. Confidence

| Claim | Level |
|---|---|
| CF dual A ≡ raw ≡ live | **Confirmed** |
| `__thiscall` plain ret void | **Confirmed** |
| Loop `0..mask` inclusive; clear heads | **Confirmed** |
| Value slot +0x0C; next +0x10; freelist +0x20 | **Confirmed** |
| Stamp `009cb360` bytes | **Confirmed** |
| Scalar-deleting destroy arg 1 | **Confirmed** |
| Sole caller FreeBuckets `004bcca0` | **Confirmed** |
| Role owning reclaim | **High** |
| Product/PDB English | **Open** |
| Exact owned value C++ type | **Open** |
| Runtime / bit-exact / diff | **Open** |

**Verdict:** **accept-with-gaps.**
