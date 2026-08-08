# Review A (reconstruction fidelity): `aa_004160b0` Class_00a6f61c_ScalarDeletingDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_004160b0` |
| **VA** | `0x004160b0`–`0x004160cd` |
| **Canonical name** | `Class_00a6f61c_ScalarDeletingDtor` (**Inferred** structural) |
| **Prior scaffold** | `FUN_004160b0` |
| **Review date** | `2026-08-04` (OWN-ONLY dual A/B — WQ9I-E) |
| **Reviewer role** | Independent reconstruction review (Path A fidelity) |
| **Counterpart** | `reviews/B_aa_004160b0_Class_00a6f61c_ScalarDeletingDtor.md` |
| **System** | MSVC scalar-deleting destructor / vtbl `PTR_FUN_00a6f61c` |
| **Live tools** | Ghidra `batch_decompile`, `analyze_function_complete`, `read_memory`, xrefs, `disassemble_function` |
| **Partition** | `WAVE_2026-08-04_wq009_depth6_partition_map.md` → **WQ9I-E** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

MSVC **scalar-deleting destructor** (vtbl[0]) for class family stamped by **`PTR_FUN_00a6f61c`**:

```text
// thiscall ECX=this; stack flags; RET 4; returns this*
complete_dtor(this)           // FUN_0097a8a0
if (flags & 1) operator_delete(this)
return this
```

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | `batch_decompile(0x004160b0)` ≡ raw |
| Body bytes | `read_memory` / `disassemble_function` — `56 8B F1` … `C2 04 00` |
| Body range | `0x004160b0`–`0x004160cd` (**30 B**); `CC` pad after |
| Vtbl | `read_memory(0x00a6f61c)` LE dword = `0x004160b0` |
| Complete dtor | `FUN_0097a8a0` sets `*this = &PTR_FUN_00a6f61c`, calls `FUN_00792c20` |
| Clean | `reconstructed-exact/Class_00a6f61c_ScalarDeletingDtor.cpp` |

---

## 3. ABI (SEALED)

| Slot | Role | Evidence |
|------|------|----------|
| **ECX** | this | entry `MOV ESI,ECX` |
| stack | flags (byte in dword) | `TEST [ESP+8],1` after push ESI |
| epilogue | **RET 4** | `C2 04 00` |
| return | this* | `MOV EAX,ESI` |

---

## 4. Control flow: clean ≡ live

| Stage | Match |
|---|---|
| Always call complete dtor `0097a8a0` | **Yes** |
| Conditional `operator_delete` on bit0 | **Yes** |
| Return this after free path | **Yes** (delete is **not** noreturn despite decompiler WARNING) |
| vtbl[0] identity | **Yes** |

---

## 5. Confidence

| Claim | Confidence |
|---|---|
| Role = scalar deleting dtor | **High** |
| thiscall + RET 4 + flags&1 | **High** |
| vtbl stamp `00a6f61c` | **High** |
| Product class English / RTTI | **Open** |
| Runtime | **Open** |

**Verdict:** **accept-with-gaps**
