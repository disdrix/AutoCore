# Review A (reconstruction fidelity): `aa_00986070` PoolHost_Acquire0x40_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00986070` |
| **VA** | `0x00986070`–`0x00986124` inclusive (**181 B** / `0xB5`) |
| **Canonical name** | `PoolHost_Acquire0x40_Inferred` |
| **Ghidra name** | `FUN_00986070` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W33-R) |
| **Counterpart** | `reviews/B_aa_00986070_PoolHost_Acquire0x40_Inferred.md` |
| **System** | process pool host / HostBase aux |
| **Evidence pass** | Live Ghidra `batch_decompile` + `analyze_function_complete` + `get_function_by_address` + `read_memory` (full body + epilogue) + xrefs/callers + callee decompiles. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Acquire a **0x40** object from `*DAT_00d1f624` pool host: pop freelist last or `new(0x40)+FUN_0074e380`; always track-push via `FUN_004406e0`; return ptr. Sole consumer stores at HostBase `+4` when `(flags & 1)`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W33-R append) | `docs/reconstruction/raw/aa_00986070_FUN_00986070.md` |
| Annotated | `docs/reconstruction/raw/aa_00986070_FUN_00986070.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/PoolHost_Acquire0x40_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00986070.cpp` |
| Function records | `functions/aa_00986070_FUN_00986070.md`, `functions/aa_00986070_PoolHost_Acquire0x40_Inferred.md` |
| Sole caller | `HostBase_EnsureAuxPtrs_Inferred` (`0x00756320`, W32-Q) |
| Live | decompile + body hex; SEH `LAB_009af9d3`; ret @ `0x00986124` |

---

## 3. Signature (sealed)

```c
// Retail: EBX = pool host (*DAT_00d1f624); no stack formals; bare C3; EAX = obj*|0
void* PoolHost_Acquire0x40_Inferred(/* EBX */);
```

| Formal | Source | Conf |
|---|---|---|
| pool host | EBX (`unaff_EBX`; caller `mov ebx,[DAT_00d1f624]`) | **High** |
| return | EAX/EDI = result | **High** |
| epilogue | bare `C3` @ `0x00986124` | **High** |

---

## 4. Control flow (clean ≡ bytes; decompiler size arg corrected)

```
SEH LAB_009af9d3
begin = *(EBX+0x14); end = *(EBX+0x18)
if (begin==0 || (end-begin)>>2==0) {
  raw = operator_new(0x40)
  result = raw ? FUN_0074e380(raw) : 0
} else {
  result = *(end - 4)
  FUN_00456780( ((end-begin)>>2) - 1, EBX+0x10 )
}
FUN_004406e0(EBX, &result)   // push track vector @+4
return result
```

| Stage | Match | Conf |
|---|---|---|
| Body 181 B / pad CC | **Yes** | **High** |
| Empty → new 0x40 + ctor | **Yes** | **High** |
| Non-empty → pop last | **Yes** | **High** |
| Shrink size = old_size-1 | **Yes** (bytes; decompiler said 0) | **High** |
| Track push FUN_004406e0 | **Yes** (`lea esi,&result; mov eax,ebx`) | **High** |
| Sole caller HostBase ensure | **Yes** (1 xref) | **High** |
| 0x40 ctor chain | **Yes** (`FUN_0074e380` → `FUN_0043fdf0` → sentinel 0xC) | **High** |

---

## 5. Gaps

- Product demangle for pool host and 0x40 element class.
- Track vector @+4 English role (registry vs active set).
- Release path that returns objects to freelist @+0x14 (other VA).
- Runtime / bit-exact / differential.

---

## 6. Verdict

Fidelity pass seals EBX ABI, freelist pop-or-new, track push, body bounds, sole caller. Residual product English + release path → **accept-with-gaps**.
