# Review A (reconstruction fidelity): `aa_005b44d0` Obj_009d95b4_ScalarDeletingDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b44d0` |
| **VA** | `0x005b44d0`–`0x005b44ee` exclusive (**30 B** / `0x1E`) |
| **Canonical name** | `Obj_009d95b4_ScalarDeletingDtor` |
| **Ghidra name** | `FUN_005b44d0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W30-N) |
| **Counterpart** | `reviews/B_aa_005b44d0_Obj_009d95b4_ScalarDeletingDtor.md` |
| **System** | host object / MSVC scalar-deleting destructor |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` (full 30 B) + vtbl dword @ `0x009d95b4` + bulk xrefs. **No** `disassemble_bytes`. |
| **Verdict** | **accept** |

---

## 1. Purpose

MSVC **scalar-deleting destructor** for vtbl family `PTR_FUN_009d95b4` (**vtbl[0]**):

1. Always run body `Obj_BodyDtor_SetVtbl_DestroyStdListAt10` (`FUN_005b3b20`).
2. If `(flags & 1)`, `operator_delete(this)`.
3. Return `this`; `RET 4`.

Body dtor is a **separate** VA (`0x005b3b20`, W28-N sealed).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W30-N) | `docs/reconstruction/raw/aa_005b44d0_FUN_005b44d0.md` |
| Annotated | `docs/reconstruction/raw/aa_005b44d0_FUN_005b44d0.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/Obj_009d95b4_ScalarDeletingDtor.cpp` |
| Clean scaffold | `docs/reconstruction/reconstructed-exact/FUN_005b44d0.cpp` |
| Function records | `functions/aa_005b44d0_FUN_005b44d0.md`, `functions/aa_005b44d0_Obj_009d95b4_ScalarDeletingDtor.md` |
| Body twin | `Obj_BodyDtor_SetVtbl_DestroyStdListAt10` `aa_005b3b20` (W28-N accept-with-gaps) |
| Live | decompile ≡ raw; full 30 B hex; vtbl[0]=`0x005b44d0` |

---

## 3. Signature (sealed)

```c
// __thiscall; ECX=this; stack flags; RET 4; EAX=this
void* __thiscall Obj_009d95b4_ScalarDeletingDtor(void* self, uint8_t flags);
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
call Obj_BodyDtor_SetVtbl_DestroyStdListAt10   // FUN_005b3b20
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
| Full body | `56 8B F1 E8 48 F6 FF FF F6 44 24 08 01 74 09 56 E8 3D 53 ED FF 83 C4 04 8B C6 5E C2 04 00` |
| Pad | `CC CC` after body |
| Body call | `E8 48 F6 FF FF` @ `0x005b44d3` → `0x005b3b20` |
| Vtbl[0] | dword @ `0x009d95b4` = `0x005b44d0` |

**No `disassemble_bytes` used.**

---

## 6. Call surface

| Direction | Detail |
|---|---|
| Xrefs | DATA from `PTR_FUN_009d95b4` only |
| Callees | `FUN_005b3b20`, `operator_delete` |
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

1. Product English / MSVC demangle for type behind `PTR_FUN_009d95b4`.
2. Runtime hit verification.

---

## Verdict

**accept** — leaf scalar-deleting wrapper fully sealed by full-body bytes + dual-sealed body twin (W28-N) + vtbl[0] dword.
