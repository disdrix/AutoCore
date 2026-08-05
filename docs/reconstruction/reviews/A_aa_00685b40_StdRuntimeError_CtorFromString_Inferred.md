# Review A (reconstruction fidelity): `aa_00685b40` StdRuntimeError_CtorFromString_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00685b40` |
| **VA** | `0x00685b40`–`0x00685b93` (**83 B**) |
| **Canonical name** | `StdRuntimeError_CtorFromString_Inferred` (**Inferred**) |
| **Ghidra name** | `FUN_00685b40` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W37-B) |
| **Counterpart** | `reviews/B_aa_00685b40_StdRuntimeError_CtorFromString_Inferred.md` |
| **System** | MSVC exception hierarchy / IdvFileError base |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` (83 B) + `analyze_function_complete` + xrefs; nested caller dual W34-B IdvFileError |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra decompile + `read_memory` only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

Construct intermediate exception+string object: base `exception` ctor, install intermediate vtbl `PTR_FUN_009ea778`, copy message string at `this+0x0c`. Base step for `IdvFileError`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00685b40_FUN_00685b40.md` (+ W37-B live seal) |
| Annotated | `docs/reconstruction/raw/aa_00685b40_FUN_00685b40.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdRuntimeError_CtorFromString_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00685b40.cpp` |
| Function record | `docs/reconstruction/functions/aa_00685b40_FUN_00685b40.md` |
| Named record | `docs/reconstruction/functions/aa_00685b40_StdRuntimeError_CtorFromString_Inferred.md` |
| Caller dual | `IdvFileError_Ctor_MsgBracketErrno` W34-B **accept** |
| Related | dtor `00685ba0`; scalar-dtor `00685c00` (vtbl[0]); `what` `004018e0` (vtbl[1]) |

---

## 3. Signature (sealed)

```c
// __thiscall; ECX=this; stack const basic_string*; RET 0x4; returns this
void* __thiscall StdRuntimeError_CtorFromString_Inferred(
    void* self /*ECX*/,
    const void* msg /*stack*/);
```

| Slot | Source | Conf |
|---|---|---|
| self | **ECX** → ESI | **High** |
| msg | Stack (`[esp+0x18]` in frame) | **High** |
| RET | **`C2 04 00`** | **High** |
| return | EAX = ESI = this | **High** |
| body | **83 B** / `0x53` | **High** |

Full hex: raw W37-B append (83 B).

---

## 4. Control flow (clean ≡ bytes / decompile)

| Stage | Match | Conf |
|---|---|---|
| SEH `LAB_009a9fd9` | **Yes** | **High** |
| `exception::exception(this)` | **Yes** | **High** |
| `*this = PTR_FUN_009ea778` | **Yes** (`C7 06 78 A7 9E 00`) | **High** |
| `basic_string` copy @ `this+0x0c` | **Yes** (`lea ecx,[esi+0xc]`) | **High** |
| return this; ret 4 | **Yes** | **High** |

---

## 5. Gaps

- Independent COL/RTTI seal of `009ea778` → `.?AVruntime_error@std@@` (probable via catchables; not walked this pass).  
- Product English on vtbl slots beyond structural dtor/`what`.  
- Runtime / bit-exact.

---

## Verdict

83 B base ctor fully sealed for ABI + layout; product type name **Inferred**. **accept-with-gaps**.
