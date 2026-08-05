# Review A (reconstruction fidelity): `aa_0076c130` Debug_OutputDebugStringFmt_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0076c130` |
| **VA** | `0x0076c130`–`0x0076c16b` exclusive (**59 B** / `0x3B`) |
| **Canonical name** | `Debug_OutputDebugStringFmt_Inferred` (**Inferred**) |
| **Ghidra name** | `FUN_0076c130` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W38-Y) |
| **Counterpart** | `reviews/B_aa_0076c130_Debug_OutputDebugStringFmt_Inferred.md` |
| **System** | debug / OutputDebugString varargs |
| **Evidence pass** | Live Ghidra `batch_decompile` + `read_memory` (59 B full) + `analyze_function_complete` + 78 xrefs + multi-caller `ADD ESP` cleanup. **No** `disassemble_bytes`. |
| **Verdict** | **accept** |

---

## 1. Purpose

Printf-style **debug emit** to the Windows debugger:

1. Reject null format (no-op).
2. Format into a **2048-byte** stack buffer with **`_vsnprintf`**.
3. **`OutputDebugStringA`** the buffer.

Universal utility (D3D errors, voice, login, packs) — not domain-specific.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W38-Y append) | `docs/reconstruction/raw/aa_0076c130_FUN_0076c130.md` |
| Annotated | `docs/reconstruction/raw/aa_0076c130_FUN_0076c130.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Debug_OutputDebugStringFmt_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_0076c130.cpp` |
| Function record | `docs/reconstruction/functions/aa_0076c130_FUN_0076c130.md` |
| Named record | `docs/reconstruction/functions/aa_0076c130_Debug_OutputDebugStringFmt_Inferred.md` |
| Live | decompile CF ≡ scaffold; body 59 B; IAT calls sealed |

---

## 3. Signature (sealed)

```c
// cdecl varargs; void; plain RET (C3); caller cleans
void Debug_OutputDebugStringFmt_Inferred(const char *format, ...);
```

| Formal | Source | Conf |
|---|---|---|
| format | `MOV EAX,[ESP+4]` | **High** |
| va_list | post-frame `LEA` of original `[ESP+8]` into `_vsnprintf` | **High** |
| buffer size | `SUB ESP,0x800` + push `0x800` | **High** |
| null gate | `TEST EAX` / `JZ` epilogue | **High** |
| epilogue | `ADD ESP,0x800; RET` | **High** |
| return | void (no EAX write) | **High** |

---

## 4. Control flow (decompile + bytes authority)

```
format = [ESP+4]
SUB ESP, 0x800
if format == 0: goto epilogue
_vsnprintf(buf, 0x800, format, &vararg0)
OutputDebugStringA(buf)
epilogue:
ADD ESP, 0x800
RET
```

| Stage | Match | Conf |
|---|---|---|
| Frame 0x800 | Yes | **High** |
| Null skip | Yes | **High** |
| vsnprintf + ODS order | Yes | **High** |
| cdecl cleanup by callers | Yes (`ADD ESP,4/8/C/20`) | **High** |

---

## 5. Gaps (accepted)

- Product/PDB English.
- Runtime / bit-exact Confirmed.

---

## 6. Verdict rationale

Body is tiny, fully byte-sealed, CF trivial, ABI confirmed by dozens of call sites. Structural name is accurate; no conflicting product string on the function itself. **accept**.
