# Review A (reconstruction fidelity): `aa_00575c00` Object_009d33c4_ScalarDeletingDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00575c00` |
| **VA** | `0x00575c00`–`0x00575c1e` exclusive (**30 B** / `0x1E`) |
| **Canonical name** | `Object_009d33c4_ScalarDeletingDtor` |
| **Ghidra name** | `FUN_00575c00` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W29-H) |
| **Counterpart** | `reviews/B_aa_00575c00_Object_009d33c4_ScalarDeletingDtor.md` |
| **System** | object / scalar deleting destructor |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` (full body). **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

MSVC **scalar deleting destructor** for derived family `PTR_FUN_009d33c4`:

1. Call `Object_009d33c4_CompleteDtor` (`FUN_00575350`).
2. If `(flags & 1) != 0`: `operator_delete(this)`.
3. Return `this`. **`RET 4`**.

Installed as **vtbl[0]** (`*(uint32_t*)0x009d33c4 == 0x00575c00`). Vtbl[1] empty stub `0x0056f570`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W29-H) | `docs/reconstruction/raw/aa_00575c00_FUN_00575c00.md` |
| Annotated | `docs/reconstruction/raw/aa_00575c00_FUN_00575c00.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/Object_009d33c4_ScalarDeletingDtor.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00575c00.cpp` |
| Function records | `functions/aa_00575c00_FUN_00575c00.md`, `functions/aa_00575c00_Object_009d33c4_ScalarDeletingDtor.md` |
| Complete dtor | `Object_009d33c4_CompleteDtor` `aa_00575350` (W28-M) |
| Live | decompile; 30 B hex; vtbl dword; no code callers |

---

## 3. Signature (sealed)

```c
// __thiscall; ECX=this; stack flags; returns this; RET 4
void *__thiscall Object_009d33c4_ScalarDeletingDtor(void *self, uint8_t flags);
```

| Formal | Source | Conf |
|---|---|---|
| self | ECX (`8B F1`) | **High** |
| flags | stack `[esp+4]` entry / `[esp+8]` after push esi; tested with `F6 44 24 08 01` | **High** |
| return | EAX = this | **High** |
| cleanup | `C2 04 00` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
push esi; mov esi, ecx
call Object_009d33c4_CompleteDtor
if (flags & 1): push esi; operator_delete; add esp,4
mov eax, esi; pop esi; ret 4
```

| Stage | Match | Conf |
|---|---|---|
| Complete dtor call | **Yes** | **High** |
| flags&1 free | **Yes** | **High** |
| operator_delete fall-through | **Yes** (bytes) | **High** |
| vtbl[0] | **Yes** | **High** |
| RET 4 | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

| Region | Note |
|---|---|
| Body | `56 8B F1 E8 48 F7 FF FF F6 44 24 08 01 74 09 56 E8 … 83 C4 04 8B C6 5E C2 04 00` |
| Complete dtor | `E8 48 F7 FF FF` → `call 0x00575350` |
| Vtbl slot | `0x009d33c4` → `00 5C 57 00` LE = `0x00575c00` |
| Size | **30 B** exclusive end `0x00575c1e` |

**No `disassemble_bytes` used.**

---

## 6. Gaps

- Product / MSVC demangled derived type name (shared with family).
- No array-deleting (`flags & 2`) path in this body — expected for scalar slot.
- Runtime / bit-exact / differential — open.

---

## 7. Verdict

CF, ABI, vtbl[0], and optional free sealed → **accept-with-gaps**.
