# Review A (reconstruction fidelity): `aa_00497c80` ListTrackedCtx_ClearDestroyAndReset_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00497c80` |
| **VA** | `0x00497c80`–`0x00497cf0` inclusive (**113 B** / `0x71`) |
| **Canonical name** | `ListTrackedCtx_ClearDestroyAndReset_Inferred` |
| **Ghidra name** | `FUN_00497c80` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W33-R) |
| **Counterpart** | `reviews/B_aa_00497c80_ListTrackedCtx_ClearDestroyAndReset_Inferred.md` |
| **System** | Palantir env child / list-tracked ctx |
| **Evidence pass** | Live Ghidra `batch_decompile` + `analyze_function_complete` + `get_function_by_address` + `read_memory` (full body) + xrefs/callers + callee decompiles. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Thiscall clear-destroy-reset of the **0xC8** list-tracked context: free all non-null bank entries, zero bank, zero dims, free/zero grid @`+0xB8`, flag=1, return 1. Used before reconfigure and from map-load / ApplyDefaultScalars paths.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W33-R append) | `docs/reconstruction/raw/aa_00497c80_FUN_00497c80.md` |
| Annotated | `docs/reconstruction/raw/aa_00497c80_FUN_00497c80.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/ListTrackedCtx_ClearDestroyAndReset_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00497c80.cpp` |
| Function records | `functions/aa_00497c80_FUN_00497c80.md`, `functions/aa_00497c80_ListTrackedCtx_ClearDestroyAndReset_Inferred.md` |
| Ctor twin | `ListTrackedCtx_Ctor_Inferred` (`0x00497920`, W32-P) |
| Live | decompile CF + body hex; entry `56 8B F1`…`B0 01 5E C3` |

---

## 3. Signature (sealed)

```c
// ECX=self; bare ret; AL=1
uint8_t __thiscall ListTrackedCtx_ClearDestroyAndReset_Inferred(uint8_t* self);
```

| Formal | Source | Conf |
|---|---|---|
| self | ECX (`56 8B F1`) | **High** |
| return | AL=1 (`B0 01`) | **High** |
| epilogue | bare `C3` | **High** |

---

## 4. Control flow (clean ≡ bytes; decompiler corrected)

```
while (*(this+0x10) >= 1) {
  count = --*(this+0x10)
  entry = *(this + count*4 + 0x14)
  if (entry) { FUN_00497900(entry); operator_delete(entry); }
}
FUN_00788db0(this+0x14, 0xA0)
*(this+4)=0; *(this+8)=0
FUN_007874b0(this+0xB8, 0, 0)   // thiscall
*(this+0xC)=0
*this = 1
return 1
```

| Stage | Match | Conf |
|---|---|---|
| Body 113 B / pad CC | **Yes** (`read_memory`) | **High** |
| Thiscall ECX | **Yes** | **High** |
| Loop continues after delete | **Yes** (bytes `jg` back) | **High** |
| Bank zero 0xA0 @+0x14 | **Yes** | **High** |
| Grid reset thiscall +0xB8 | **Yes** (`lea ecx,[esi+0xB8]`) | **High** |
| Layout match W32-P ctor | **Yes** (+0x10 count, +0x14 bank, +0xB8 grid) | **High** |
| 6 callers | **Yes** (analyze_function_complete) | **High** |

---

## 5. Gaps

- Product/PDB class demangle for 0xC8 ctx and bank entry objects.
- Entry payload beyond `FUN_00497900` (0x28 × 0xD0 at +0x20).
- Flag@+0 polarity vs readers.
- Runtime / bit-exact / differential.

---

## 6. Verdict

Fidelity pass seals ABI, body bounds, corrected loop CF, bank free path, and grid reset. Residual product English → **accept-with-gaps**.
