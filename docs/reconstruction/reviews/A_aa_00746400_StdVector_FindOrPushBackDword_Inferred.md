# Review A (reconstruction fidelity): `aa_00746400` StdVector_FindOrPushBackDword_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00746400` |
| **VA** | `0x00746400`–`0x00746437` (**56 B**) |
| **Canonical name** | `StdVector_FindOrPushBackDword_Inferred` |
| **Ghidra name** | `FUN_00746400` |
| **Review date** | `2026-08-04` (W37-V dual seal) |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W37-V) |
| **Counterpart** | `reviews/B_aa_00746400_StdVector_FindOrPushBackDword_Inferred.md` |
| **System** | container / std::vector-like dword registry |
| **Evidence pass** | Live Ghidra `batch_decompile` + `read_memory` (full 56 B) + `analyze_function_complete` + callers/callee decompile |
| **Verdict** | **accept** |

**Tools:** decompile + read_memory only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

Linear-scan a dword vector `[this+4, this+8)` for a stack value; on hit return **1**; on miss push via `StdVector_PushBackDword_Inferred` (`FUN_004406e0`) and return **0**.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00746400_FUN_00746400.md` (+ W37-V append) |
| Annotated | `docs/reconstruction/raw/aa_00746400_FUN_00746400.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_FindOrPushBackDword_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00746400.cpp` |
| Function | `docs/reconstruction/functions/aa_00746400_FUN_00746400.md` |
| Named | `docs/reconstruction/functions/aa_00746400_StdVector_FindOrPushBackDword_Inferred.md` |
| Live | decompile ≡ raw CF; full 56 B hex; 5 callers; callee `004406e0` dualed |
| Context | W32-S water token; `StdVector_PushBackDword` dual |

---

## 3. Signature (sealed)

```c
uint32_t __thiscall StdVector_FindOrPushBackDword_Inferred(
    VecDword *vec /*ECX*/,
    uint32_t value /*stack*/);
/* RET 4; 1=found, 0=appended */
```

| Slot | Source | Conf |
|---|---|---|
| this | `MOV EAX,ECX`; begin/end from EAX | **High** |
| value | `MOV ECX,[esp+8]` after `PUSH ESI` | **High** |
| return 1 | `MOV EAX,1; RET 4` | **High** |
| return 0 | `XOR EAX,EAX; RET 4` after push | **High** |
| push path | `LEA ESI,&value`; `call 004406e0` (EAX=this) | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
EAX = ECX (this)
cursor = *(this+4); end = *(this+8)
while cursor != end:
  if *cursor == value:
    if cursor != end: return 1
    else: goto append
  cursor++
append:
  PushBackDword(EAX=this, ESI=&value)
  return 0
```

| Stage | Match | Conf |
|---|---|---|
| begin/end + stride 4 | **Yes** | **High** |
| equal-dword compare | **Yes** | **High** |
| push via `004406e0` EAX/ESI | **Yes** | **High** |
| RET 4 both paths | **Yes** | **High** |
| Common host `DAT_00d1f620` | **Yes** (caller bytes) | **High** |
| Product host English | open | **Low** |

---

## 5. Gaps / open

1. Product C++ type / English name of `DAT_00d1f620` host.
2. Whether host `+0` is vtbl (unread here).
3. Runtime / bit-exact / differential.

**Verdict:** **accept** — ABI/CF/return/push-path sealed; residual is product naming only.
