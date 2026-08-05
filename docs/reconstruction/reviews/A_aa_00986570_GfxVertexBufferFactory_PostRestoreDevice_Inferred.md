# Review A (reconstruction fidelity): `aa_00986570` GfxVertexBufferFactory_PostRestoreDevice_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00986570` |
| **VA** | `0x00986570` |
| **Body** | `0x00986570`–`0x00986752` exclusive (**482** B) |
| **Canonical name** | `GfxVertexBufferFactory_PostRestoreDevice_Inferred` |
| **Ghidra name** | `FUN_00986570` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_00986570_GfxVertexBufferFactory_PostRestoreDevice_Inferred.md` |
| **System** | graphics / VB factory device Reset |
| **Live tools** | Ghidra `decompile_function`, `batch_decompile`, `read_memory`, `analyze_function_complete`, xrefs/callers, callee decompile (**no** `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Post-`Reset` recreate of factory-tracked DEFAULT-pool vertex buffers and optional surface-restore callbacks.

```c
// EAX = factory*; plain RET; HRESULT
int GfxVertexBufferFactory_PostRestoreDevice_Inferred(void);
```

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean | `aa_00986570_*` + named clean |
| Live decompile | ≡ raw CF |
| Body | `read_memory 0x00986570` length 482; plain `RET`; pad `CC` |
| Callees | `FUN_00746640`, errReport/log/CRT abort |
| Callers | `FUN_0075eff0` @ `0x0075f2a1` only |
| Peers | PreRestore `FUN_009864e0`; IB PostRestore `FUN_00985610` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| EAX = this (not ECX) | **Confirmed** | `MOV EDX,[EAX+0x14]` entry |
| Plain RET / HRESULT 0 on success | **Confirmed** | `XOR EAX,EAX` + `RET` |
| Map head at +0x14; skip flags &0x28 @+0xE | **Confirmed** | decompile ≡ bytes |
| Slot stride 0x20; recreate via FUN_00746640 | **Confirmed** | `ADD EDI,0x20`; 5-arg call |
| Product PostRestoreDevice role | **Confirmed** | sealed string + Reset caller fail plate |
| Exact MSVC map / VB C++ types | Inferred / Open | unowned |
| Product demangle exact | Inferred | `_Inferred` |

---

## 4. Gaps (non-blocking)

- Full typed VB object / pool map value layout beyond used fields.
- Unowned `FUN_00746640` product plate (CreateVertexBuffer path sealed by its own strings).
- Runtime / bit-exact / differential.

---

## 5. Verdict rationale

CF, ABI (EAX-this), HRESULT, pool-flag skip, recreate call, EH_Abort path, and surface-callback log-only behavior are sealed from decompile ≡ body hex + product strings. Residual gaps are unowned callees/types and demangle English only → **accept-with-gaps**.
