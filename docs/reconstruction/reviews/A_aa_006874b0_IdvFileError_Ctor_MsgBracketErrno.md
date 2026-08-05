# Review A (reconstruction fidelity): `aa_006874b0` IdvFileError_Ctor_MsgBracketErrno

| Field | Value |
|---|---|
| **Stable ID** | `aa_006874b0` |
| **VA** | `0x006874b0`–`0x00687624` (**372 B**) |
| **Canonical name** | `IdvFileError_Ctor_MsgBracketErrno` |
| **Ghidra name** | `FUN_006874b0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W34-B) |
| **Counterpart** | `reviews/B_aa_006874b0_IdvFileError_Ctor_MsgBracketErrno.md` |
| **System** | SpeedTree / IDV `IdvFileError` |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` (full 372 B) + ThrowInfo/RTTI + caller sample. **No** `disassemble_bytes`. |
| **Verdict** | **accept** |

---

## 1. Purpose

Leaf **constructor** for product type **`IdvFileError`**. Builds bracketed message (optional `strerror`), calls base `FUN_00685b40`, installs IdvFileError vtbl. Parents throw with `DAT_00ac9e00`.

```
IdvFileError_Ctor_MsgBracketErrno(this, msg, include_errno) -> this
  part = include_errno ? strerror(*errno()) : ""
  built = msg + " [" + part + "]"
  FUN_00685b40(this, built)          // base + string @ +0x0c
  this->vtbl = PTR_FUN_009ead64
  return this                        // RET 8
```

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W34-B append) | `docs/reconstruction/raw/aa_006874b0_FUN_006874b0.md` |
| Annotated | `docs/reconstruction/raw/aa_006874b0_FUN_006874b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/IdvFileError_Ctor_MsgBracketErrno.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_006874b0.cpp` |
| Function record | `docs/reconstruction/functions/aa_006874b0_IdvFileError_Ctor_MsgBracketErrno.md` |
| RTTI | `.?AVIdvFileError@@` @ `0x00af5480`; `.?AVruntime_error@std@@` @ `0x00af5460`; `.?AVexception@@` @ `0x00af8bb8` |
| ThrowInfo | `DAT_00ac9e00` → CatchableTypeArray `0x00ac9df0` (n=3, size 0x28) |
| Sample caller | `FUN_00687e40` — `"malformed lod info"` + flag 0 → ctor → throw |
| Base | `FUN_00685b40` decompile |

---

## 3. Signature (sealed)

```c
// __thiscall; RET 8; returns this
IdvFileError* __thiscall IdvFileError_Ctor_MsgBracketErrno(
    IdvFileError* this,
    const std::string* msg,
    char include_errno);
```

| Formal | Source | Conf |
|---|---|---|
| this | ECX; `mov edi,ecx`; store `this` | **High** |
| msg | stack `[esp+…]` after frame; `FUN_00416490` lhs | **High** |
| include_errno | stack char; branch empty vs strerror | **High** |
| epilogue | `ADD ESP,0xA0; RET 8` | **High** |

---

## 4. Control flow (bytes authority)

| Stage | Match | Conf |
|---|---|---|
| empty vs strerror branch | Yes | **High** |
| `msg + " [" + part + "]"` via 00416490/00416410 | Yes | **High** |
| base `FUN_00685b40` then temps dtor | Yes | **High** |
| vtbl install `0x009ead64` | Yes (`C7 07 64 AD 9E 00`) | **High** |
| Body 372 B / RET 8 | Yes | **High** |

Live decompile **≡** 2026-07-23 raw CF. Full-body hex in raw W34-B append.

---

## 5. Type identity — **Confirmed**

| Symbol | Address / evidence |
|---|---|
| `.?AVIdvFileError@@` | `0x00af5480` |
| `.?AVruntime_error@std@@` | `0x00af5460` |
| `.?AVexception@@` | `0x00af8bb8` |
| IdvFileError vtbl | `PTR_FUN_009ead64` |
| Intermediate base vtbl | `PTR_FUN_009ea778` (via `FUN_00685b40`) |
| ThrowInfo | `DAT_00ac9e00` |
| Object size | `0x28` |

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker (exception ctor) |
| Callers | 20+ SpeedTree parse workers; 47 xrefs |
| Callees | `FUN_00685b40`, `FUN_00416490`, `FUN_00416410`, `_errno`, `strerror`, string ops |
| Related | scalar-dtor `FUN_00687630` (vtbl[0]) |

---

## 7. Gaps

1. Product method English on intermediate vtbl / `what()`.  
2. Full dual of base `FUN_00685b40` (not owned this partition).  
3. Runtime / bit-exact / differential — open.

---

## 8. Verdict

**accept** — ABI/CF/RTTI/ThrowInfo/message build sealed; residual gaps are non-blocking naming of nested base helpers.
