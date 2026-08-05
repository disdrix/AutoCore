# Review A (reconstruction fidelity): `aa_005b3f60` Obj_DefaultCtor_SetVtbl_EmptyListAt10_ZeroF4At20

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b3f60` |
| **VA** | `0x005b3f60`–`0x005b3f9a` (**58 B**) |
| **Canonical name** | `Obj_DefaultCtor_SetVtbl_EmptyListAt10_ZeroF4At20` |
| **Ghidra name** | `FUN_005b3f60` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W30-O) |
| **Counterpart** | `reviews/B_aa_005b3f60_Obj_DefaultCtor_SetVtbl_EmptyListAt10_ZeroF4At20.md` |
| **System** | host object / MSVC default ctor |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` (full body) + `get_bulk_xrefs` + `get_assembly_context` on callers. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

MSVC **default constructor** for a **0x30**-byte host object with vtbl `PTR_FUN_009d95b4`:

1. Store vtbl at `*this`.
2. Init empty circular list at `this+0x10` (sentinel buy `FUN_005b43b0`; head @ `+0x14`, size @ `+0x18`).
3. Zero four floats at `this+0x20..+0x2c`.
4. Return `this`.

Live path: `operator_new(0x30)` then this ctor; populate is **separate** (`FUN_005b3fa0` / `FUN_005b42f0`).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W30-O) | `docs/reconstruction/raw/aa_005b3f60_FUN_005b3f60.md` |
| Annotated | `docs/reconstruction/raw/aa_005b3f60_FUN_005b3f60.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Obj_DefaultCtor_SetVtbl_EmptyListAt10_ZeroF4At20.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_005b3f60.cpp` |
| Function record | `docs/reconstruction/functions/aa_005b3f60_Obj_DefaultCtor_SetVtbl_EmptyListAt10_ZeroF4At20.md` |
| Body dtor peer | `aa_005b3b20` (W28-N accept-with-gaps) |
| Live | decompile omits list-base LEA naming; **bytes seal** |

---

## 3. Signature (sealed)

```c
// ECX = this*; returns this in EAX; bare RET
void * __fastcall Obj_DefaultCtor_SetVtbl_EmptyListAt10_ZeroF4At20(void *self);
```

| Formal | Source | Conf |
|---|---|---|
| self | ECX | **High** |
| return | EAX = this | **High** |
| cleanup | `C3` | **High** |

---

## 4. Control flow (clean ≡ **bytes**)

```
[esi] = 0x009d95b4
edi = esi+0x10
call FUN_005b43b0          ; ECX=edi
[edi+4] = eax              ; head
[edi+8] = 0                ; size
[esi+0x20..0x2c] = 0.0f    ; xorps + movss ×4
eax = esi; ret
```

| Stage | Match | Conf |
|---|---|---|
| Vtbl store | **Yes** | **High** |
| List base +0x10 | **Yes** (LEA + dtor twin) | **High** |
| Head/size | **Yes** | **High** |
| F4 zero via movss | **Yes** | **High** |
| Size 0x30 from callers | **Yes** (`PUSH 0x30`) | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (58 B):
```
568bf1578d7e108bcfc706b4959d00e83c0400000f57c0894704c74708000000005ff30f114620f30f114624f30f114628f30f11462c8bc65ec3
```

| Feature | Encoding |
|---|---|
| Vtbl imm | `C7 06 B4 95 9D 00` |
| List LEA | `8D 7E 10` |
| Call buy | `E8 3C 04 00 00` → `0x005b43b0` |
| Head/size | `89 47 04` / `C7 47 08 00…` |
| F4 zero | `0F 57 C0` + four `F3 0F 11 46 xx` |
| Ret | `8B C6 5E C3` |

**No `disassemble_bytes` used.**

---

## 6. Gaps

- Product English class name (shader text adjacent to vtbl, not plate).
- Unwritten fields `+0x04..+0x0C`, `+0x1C`.
- Runtime differential — open.

---

## 7. Verdict

**accept-with-gaps** — default-ctor CF/ABI/bytes/callers sealed; product class residual gap.
