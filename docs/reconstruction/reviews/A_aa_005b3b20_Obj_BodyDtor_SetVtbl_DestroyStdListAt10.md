# Review A (reconstruction fidelity): `aa_005b3b20` Obj_BodyDtor_SetVtbl_DestroyStdListAt10

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b3b20` |
| **VA** | `0x005b3b20`–`0x005b3b2e` (**14 B**) |
| **Canonical name** | `Obj_BodyDtor_SetVtbl_DestroyStdListAt10` |
| **Ghidra name** | `FUN_005b3b20` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W28-N) |
| **Counterpart** | `reviews/B_aa_005b3b20_Obj_BodyDtor_SetVtbl_DestroyStdListAt10.md` |
| **System** | host object / MSVC std::list member dtor |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` (full body) + `get_bulk_xrefs` + ctor/scalar assembly context. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

MSVC **body destructor** for a host object with final vtbl `PTR_FUN_009d95b4`:

1. Store final vtbl at `*this`.
2. Destroy embedded circular `std::list` shell at `this+0x10` via tail into `StdList_Destroy_FreeHead`.

Invoked only from scalar-deleting dtor `FUN_005b44d0` (vtbl[0]).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W28-N) | `docs/reconstruction/raw/aa_005b3b20_FUN_005b3b20.md` |
| Annotated | `docs/reconstruction/raw/aa_005b3b20_FUN_005b3b20.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Obj_BodyDtor_SetVtbl_DestroyStdListAt10.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_005b3b20.cpp` |
| Function record | `docs/reconstruction/functions/aa_005b3b20_Obj_BodyDtor_SetVtbl_DestroyStdListAt10.md` |
| List destroy | `aa_00497360` StdList_Destroy_FreeHead (W27-K accept) |
| Live | decompile incomplete for tail; **bytes seal** |

---

## 3. Signature (sealed)

```c
// ECX = this*; bare RET via tail JMP into StdList_Destroy_FreeHead
void __fastcall Obj_BodyDtor_SetVtbl_DestroyStdListAt10(void *self);
```

| Formal | Source | Conf |
|---|---|---|
| self | ECX | **High** |
| return | void (tail) | **High** |
| cleanup | JMP (no local RET) | **High** |

---

## 4. Control flow (clean ≡ **bytes**; decompile incomplete)

```
[ecx] = 0x009d95b4          ; final vtbl
ecx += 0x10                 ; embedded list object
jmp StdList_Destroy_FreeHead
```

| Stage | Match | Conf |
|---|---|---|
| Vtbl store | **Yes** | **High** |
| this+0x10 list base | **Yes** (bytes + ctor LEA) | **High** |
| Tail to list destroy | **Yes** (rel32 → 00497360) | **High** |
| Ghidra CALL+RET display | **No** — superseded by bytes | — |

---

## 5. Machine bytes (`read_memory`)

Full body hex (14 B):
```
c701b4959d0083c110e93238eeff
```

| Feature | Encoding |
|---|---|
| Vtbl imm | `C7 01 B4 95 9D 00` |
| List offset | `83 C1 10` |
| Tail | `E9 32 38 EE FF` → `0x00497360` |
| Pad | `CC CC` |

**No `disassemble_bytes` used.**

---

## 6. Gaps

- Product English class name (no plate; vtbl rdata adjacency is shader text).
- Full host field map outside list member (ctor-owned).
- Runtime differential — open.

---

## 7. Verdict

**accept-with-gaps** — body dtor CF/ABI/bytes sealed; product class name residual gap only.
