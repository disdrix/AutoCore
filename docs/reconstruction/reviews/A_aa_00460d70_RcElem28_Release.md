# Review A (reconstruction fidelity): `aa_00460d70` RcElem28_Release

| Field | Value |
|---|---|
| **Stable ID** | `aa_00460d70` |
| **VA** | `0x00460d70`–`0x00460d83` exclusive (**19 B**) |
| **Canonical name** | `RcElem28_Release` |
| **Ghidra name** | `FUN_00460d70` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W36-O) |
| **Counterpart** | `reviews/B_aa_00460d70_RcElem28_Release.md` |
| **System** | Per-element Release of shared resource `@+0x10` on RC-elem **0x1c** |
| **Evidence pass** | Live Ghidra `batch_decompile` / `decompile_function` + `analyze_function_complete` + `read_memory` (full body) + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Release the **shared resource pointer** stored at `elem+0x10`: decrement refcount; when it hits zero, transfer to the shared object's destroy slot (`vtbl+8`).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W36-O append) | `docs/reconstruction/raw/aa_00460d70_FUN_00460d70.md` |
| Annotated | `docs/reconstruction/raw/aa_00460d70_FUN_00460d70.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/RcElem28_Release.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_00460d70.cpp` |
| Function record | `docs/reconstruction/functions/aa_00460d70_RcElem28_Release.md` |
| Primary walker | W35-O `StdDestroyRange_RcElem28` (`0x00461780`) |
| Call sites | `0x00461362`, `0x00461753`, `0x00461789` (all `mov eax,cur; call`) |

---

## 3. Signature (sealed)

```c
// EAX=elem*, RET 0 or tail JMP [vtbl+8]
void RcElem28_Release(RcElem28* elem);
```

| Formal | Source | Conf |
|---|---|---|
| elem* | EAX (`MOV ECX,[EAX+0x10]`) | **High** |
| shared* | `[elem+0x10]` | **High** |
| refcount | `[shared+4]` via `ADD DWORD [ECX+4],-1` | **High** |
| destroy | `JMP [vtbl+8]` (`FF 62 08`) | **High** |
| RET 0 | `C3` when null or refcount>0 | **High** |

---

## 4. Control flow

| Stage | Match | Conf |
|---|---|---|
| load shared `@+0x10` | bytes ≡ decompile | **High** |
| null → ret | `TEST/JZ` | **High** |
| refcount-- | `ADD [ECX+4],-1` | **High** |
| non-zero → ret | `JNZ` | **High** |
| zero → tail JMP vtbl+8 | bytes win (not CALL) | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (19 B) — raw W36-O append.

```
8B 48 10 85 C9 74 0B 83 41 04 FF 75 05 8B 11 FF 62 08 C3
```

Pad `CC`.

---

## 6. Gaps

- Product/PDB shared-class English (vtbl identity open).
- Exact destroy contract of `vtbl+8` (delete this vs free vs custom) not dual-owned.
- Runtime / bit-exact.

---

## 7. Verdict

Minimal 19-byte leaf fully covered by bytes; ABI and refcount protocol sealed. Product vtbl open → **accept-with-gaps**.
