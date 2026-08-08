# Review A (reconstruction fidelity): `aa_004063a0` CNDHash_Ctor_00a2c2b0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004063a0` |
| **VA** | `0x004063a0` |
| **Canonical name** | `CNDHash_Ctor_00a2c2b0` |
| **Prior alias** | `FUN_004063a0` |
| **Review date** | `2026-08-04` (OWN-ONLY dual A/B — WQ9H-D) |
| **Reviewer role** | Independent reconstruction review (Path A fidelity) |
| **Counterpart** | `reviews/B_aa_004063a0_CNDHash_Ctor_00a2c2b0.md` |
| **System** | container / CNDHash (host vtbl `00a2c2b0`) |
| **Live tools** | Ghidra `batch_decompile`, `analyze_function_complete`, `read_memory`, `disassemble_function`, callers/xrefs, `get_assembly_context` |
| **Partition** | `WAVE_2026-08-04_wq009_depth5_partition_map.md` → **WQ9H-D** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Construct host-family **CNDHash** (0x34 bytes) with vtbl **`PTR_FUN_00a2c2b0`**, seed log2 / provisional power-of-two count, clear structural fields, then allocate empty bucket table via sealed alloc twin:

```text
// CL = log2; stack self*; ret 4; EAX = self
self->vtbl = 00a2c2b0
self[+8]   = 1 << log2          // provisional COUNT
zero +4,+0xc,+0x10,+0x14,+0x18,+0x20,+0x28,+0x2c,+0x30
self[+0x1c] = log2
self[+0x1d] = 0                 // lock
// +0x24 unwritten
ESI = self; CALL CNDHash_AllocBucketTable_00a2c2e4  // COUNT→MASK; stamp 00a2c2e4
return self
```

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | `batch_decompile(0x004063a0)` ≡ 2026-07-23 raw CF |
| Body bytes | `read_memory` — vtbl imm `b0 c2 a2 00`; `ret 4` = `c2 04 00` |
| Disasm | `disassemble_function` — `SHL EAX,CL`; `MOV ESI,[ESP+0x18]`; `CALL 0x00406f20` |
| Caller | `get_assembly_context(0093e8eb)` — `PUSH EAX; MOV CL,2; CALL` after `new(0x34)` |
| Nested dual | `CNDHash_AllocBucketTable_00a2c2e4` sealed WQ9G-J |
| Clean | `reconstructed-exact/CNDHash_Ctor_00a2c2b0.cpp` |

---

## 3. ABI (SEALED)

| Slot | Role | Evidence |
|------|------|----------|
| **CL** | log2 | `SHL EAX,CL`; `MOV [ESI+0x1c],CL`; caller `MOV CL,2` |
| **stack[0]** | self* | `MOV ESI,[ESP+0x18]` after SEH+push; caller `PUSH EAX` |
| return | EAX=self | `MOV EAX,ESI` before epilogue |
| cleanup | **ret 4** | `C2 04 00` |
| **not** thiscall | this ∉ ECX | contrast skill ctor `ECX=this; stack log2` |

---

## 4. Control flow: clean ≡ live

| Stage | Match |
|---|---|
| vtbl install `00a2c2b0` | **Yes** (imm in bytes) |
| `1<<log2` at +8 | **Yes** |
| Field zero map + skip +0x24 | **Yes** |
| ESI alloc call `00406f20` | **Yes** |
| EAX=self; ret 4 | **Yes** |
| Host size 0x34 | **Yes** (sole `operator_new(0x34)`) |

---

## 5. Confidence

| Claim | Confidence |
|---|---|
| Role = CNDHash ctor for vtbl 00a2c2b0 | **High** |
| Inverted CL/stack ABI / ret 4 | **High** |
| Nested alloc stamp family 00a2c2e4 | **High** (WQ9G-J + CALL site) |
| Sole caller log2=2 | **High** |
| Product English / RTTI class name | **Open** |
| Runtime / bit-exact | **Open** |

**Verdict:** **accept-with-gaps**
