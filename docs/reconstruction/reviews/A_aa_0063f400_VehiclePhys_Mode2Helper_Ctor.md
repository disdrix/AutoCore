# Review A (reconstruction fidelity): `aa_0063f400` VehiclePhys_Mode2Helper_Ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_0063f400` |
| **VA** | `0x0063f400`–`0x0063f4c6` |
| **Canonical name** | `VehiclePhys_Mode2Helper_Ctor` |
| **Ghidra name** | `FUN_0063f400` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W25-K) |
| **Counterpart** | `reviews/B_aa_0063f400_VehiclePhys_Mode2Helper_Ctor.md` |
| **System** | input-drive-control / vehicle phys mode |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory`; caller `005d4050` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Mode-2 helper **constructor**: fill 0x60-byte COM (vtable, refcount, FLT_MAX quads, unit floats, four blend constants), seed via `FUN_0063f330(this, *(host+0xc))`, return `this`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0063f400_FUN_0063f400.md` (+ W25-K append) |
| Annotated | `docs/reconstruction/raw/aa_0063f400_FUN_0063f400.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/VehiclePhys_Mode2Helper_Ctor.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0063f400.cpp` |
| Function record | `docs/reconstruction/functions/aa_0063f400_FUN_0063f400.md` |
| Caller | `VehiclePhys_SetModeHelper_Inferred` mode-2 path |
| Live | body 199 B; `C2 04 00`; float constants sealed |

---

## 3. Signature (sealed)

```c
// __thiscall RET 4; EAX = this
void* VehiclePhys_Mode2Helper_Ctor(void* this, void* physHost);
```

| Formal | Source | Conf |
|---|---|---|
| this | ECX → ESI; returns EAX | **High** |
| physHost | Stack[0x4]; `+0xc` → nested | **High** |
| cleanup | `RET 4` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

| Stage | Match | Conf |
|---|---|---|
| Write four blend floats +0x50..+0x5c | **Yes** | **High** |
| refcount +6 = 1 | **Yes** | **High** |
| vtable PTR_FUN_009e3ec0 | **Yes** | **High** |
| FLT_MAX ×4 at +0x10 and +0x30 | **Yes** | **High** |
| zero triple + 1.0 at +0x20/+0x40 families | **Yes** | **High** |
| FUN_0063f330(host+0xc) | **Yes** | **High** |
| return this | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

Prologue/constants:
```
f30f100518f7a000 ... 66c746060100 c706c03e9e00 ... 5ec20400
```

Floats: 0.01 / 0.005 / 0.1 / 0.2 / 1.0 / FLT_MAX sealed via `read_memory`.

---

## 6. Gaps

- Product English for blend constants and FLT_MAX fields.
- Full mode-2 vtable method names.
- Nested `FUN_0063f330` dual.
- Runtime / bit-exact EXE.
