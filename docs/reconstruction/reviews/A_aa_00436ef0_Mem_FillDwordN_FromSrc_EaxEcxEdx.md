# Review A (reconstruction fidelity): `aa_00436ef0` Mem_FillDwordN_FromSrc_EaxEcxEdx

| Field | Value |
|---|---|
| **Stable ID** | `aa_00436ef0` |
| **VA** | `0x00436ef0`–`0x00436f06` (**23 B** / `0x17`) |
| **Canonical name** | `Mem_FillDwordN_FromSrc_EaxEcxEdx` |
| **Ghidra name** | `FUN_00436ef0` |
| **Review date** | `2026-07-29` (W34-D dual seal) |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W34-D) |
| **Counterpart** | `reviews/B_aa_00436ef0_Mem_FillDwordN_FromSrc_EaxEcxEdx.md` |
| **System** | stl-helpers / POD fill |
| **Evidence pass** | Live Ghidra `batch_decompile` + `analyze_function_complete` + `read_memory` (full 23 B) + callers/xrefs. **No** `disassemble_bytes`. |
| **Verdict** | **accept** |

**Tools:** decompile + read_memory only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

Leaf dword fill-from-pointer:

1. If `count == 0` (ECX), return.
2. Else loop count times: if dest (EAX) non-null, `*dest = *src` (EDX); always `dest += 1` dword; decrement count.
3. Bare `RET`.

Used by `PtrVecShell_InitFill_Inferred` after `operator_new(count*4)` and many other fill sites.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W34-D append) | `docs/reconstruction/raw/aa_00436ef0_FUN_00436ef0.md` |
| Annotated | `docs/reconstruction/raw/aa_00436ef0_FUN_00436ef0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Mem_FillDwordN_FromSrc_EaxEcxEdx.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00436ef0.cpp` |
| Function records | `functions/aa_00436ef0_FUN_00436ef0.md`, `functions/aa_00436ef0_Mem_FillDwordN_FromSrc_EaxEcxEdx.md` |
| Live | decompile ≡ bytes; 14+ callers; leaf |
| Pair | `Mem_FillDwordN_ReturnEnd` (`0x004651d0`) — different ABI |

---

## 3. Signature (sealed — bytes win)

```c
// Register ABI; bare RET; leaf
// Decompiler: void __fastcall (count ECX, src* EDX) + phantom in_EAX
void Mem_FillDwordN_FromSrc_EaxEcxEdx(
    uint32_t* dest /*EAX*/,
    int count /*ECX*/,
    uint32_t const* src /*EDX*/);
```

| Slot | Source | Conf |
|---|---|---|
| count | ECX | **High** |
| src* | EDX | **High** |
| dest* | EAX | **High** (phantom in decompiler; bytes + parent set EAX) |
| RET | bare `C3` | **High** |
| stack formals | **none** | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
if count == 0: return
loop:
  if dest != null: *dest = *src
  dest++
  count--
  if count != 0: goto loop
return
```

| Stage | Match | Conf |
|---|---|---|
| Zero-count early out | **Yes** (`TEST ECX` / `JBE`) | **High** |
| Null-safe store | **Yes** (`TEST EAX` / `JZ`) | **High** |
| Always advance dest | **Yes** | **High** |
| Re-read *src each iter | **Yes** (`MOV ESI,[EDX]`) | **High** |
| Leaf | **Yes** (0 callees) | **High** |

---

## 5. Gaps / open

1. Product English for non-vector call sites (many).
2. Whether any caller relies on post-call EAX = dest+count after null path.
3. Runtime / bit-exact / differential.

Fidelity pass seals full 23 B body, register ABI, null gate, and leaf classification. Residual product English on distant callers is non-blocking for the helper contract → **accept**.
