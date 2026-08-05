# Review A (reconstruction fidelity): `aa_004975e0` Class_009c7a1c_ScalarDeletingDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_004975e0` |
| **VA** | `0x004975e0`–`0x004975fe` exclusive (**30 B** / `0x1E`) |
| **Canonical name** | `Class_009c7a1c_ScalarDeletingDtor` |
| **Ghidra name** | `FUN_004975e0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W29-F) |
| **Counterpart** | `reviews/B_aa_004975e0_Class_009c7a1c_ScalarDeletingDtor.md` |
| **System** | class / MSVC scalar-deleting destructor |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` (full 30 B) + vtbl dword @ `0x009c7a1c`. **No** `disassemble_bytes`. |
| **Verdict** | **accept** |

---

## 1. Purpose

MSVC **scalar-deleting destructor** for vtbl family `PTR_FUN_009c7a1c` (**vtbl[0]**):

1. Always run complete body `Class_009c7a1c_CompleteDtor` (`FUN_004970b0`).
2. If `(flags & 1)`, `operator_delete(this)`.
3. Return `this`; `RET 4`.

Complete body and element dtor are **separate** VAs (`0x004970b0`, `0x005b8000`).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W29-F) | `docs/reconstruction/raw/aa_004975e0_FUN_004975e0.md` |
| Annotated | `docs/reconstruction/raw/aa_004975e0_FUN_004975e0.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/Class_009c7a1c_ScalarDeletingDtor.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004975e0.cpp` |
| Function records | `functions/aa_004975e0_FUN_004975e0.md`, `functions/aa_004975e0_Class_009c7a1c_ScalarDeletingDtor.md` |
| Body twin | `Class_009c7a1c_CompleteDtor` `aa_004970b0` (W28-M accept-with-gaps) |
| Live | decompile ≡ raw; full 30 B hex; vtbl[0]=`0x004975e0` |

---

## 3. Signature (sealed)

```c
// __thiscall; ECX=this; stack flags; RET 4; EAX=this
void* __thiscall Class_009c7a1c_ScalarDeletingDtor(void* self, uint8_t flags);
```

| Formal | Source | Conf |
|---|---|---|
| self | ECX (`56 8B F1`) | **High** |
| flags | `[esp+8]` bit0 | **High** |
| return | EAX = ESI = self | **High** |
| cleanup | `C2 04 00` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
ESI = this
call Class_009c7a1c_CompleteDtor   // FUN_004970b0
if (flags & 1):
  operator_delete(this)
return this                         // RET 4
```

| Stage | Match | Conf |
|---|---|---|
| Save this / call body | **Yes** | **High** |
| flags bit0 gate | **Yes** (`F6 44 24 08 01` / `74 09`) | **High** |
| optional delete + ret 4 | **Yes** | **High** |
| Live decompile ≡ scaffold raw | **Yes** | **High** |
| False noreturn on delete | **Ignored** (bytes fall-through) | **High** |

---

## 5. Machine bytes (`read_memory`)

| Region | Hex / note |
|---|---|
| Full body | `56 8B F1 E8 C8 FA FF FF F6 44 24 08 01 74 09 56 E8 2D 22 FF FF 83 C4 04 8B C6 5E C2 04 00` |
| Pad | `CC CC` after body |
| Body call | `E8 C8 FA FF FF` @ `0x004975e3` → `0x004970b0` |
| Vtbl[0] | dword @ `0x009c7a1c` = `0x004975e0` |

**No `disassemble_bytes` used.**

---

## 6. Call surface

| Direction | Detail |
|---|---|
| Xrefs | DATA from `PTR_FUN_009c7a1c` only |
| Callees | `FUN_004970b0`, `operator_delete` |
| Classification | worker (scalar-deleting wrapper) |

---

## 7. Confidence

| Claim | Level |
|---|---|
| ABI / CF / scalar-delete pattern | **High** |
| Class family via vtbl + body twin | **High** |
| Product English / demangle | **Low** (naming only) |
| Runtime / bit-exact | **Open** |

---

## 8. Gaps

1. Product English / MSVC demangle for type behind `PTR_FUN_009c7a1c`.
2. Runtime hit verification.

---

## Verdict

**accept** — leaf scalar-deleting wrapper fully sealed by full-body bytes + dual-sealed complete body twin (W28-M) + vtbl[0] dword.
