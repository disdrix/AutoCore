# Review A (reconstruction fidelity): `aa_00575350` Object_009d33c4_CompleteDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00575350` |
| **VA** | `0x00575350`–`0x005753ba` exclusive (**106 B** / `0x6A`) |
| **Canonical name** | `Object_009d33c4_CompleteDtor` |
| **Ghidra name** | `FUN_00575350` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W28-M) |
| **Counterpart** | `reviews/B_aa_00575350_Object_009d33c4_CompleteDtor.md` |
| **System** | object / derived complete destructor |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` (full body). **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

MSVC **complete-object destructor** for derived object family `PTR_FUN_009d33c4`:

1. Install derived vtbl.
2. Free owned ptr @ `+0x1EC`; clear `+0x1F0`, `+0x1F1`.
3. Free buffer triple @ `+0x1F8`/`+0x1FC`/`+0x200`.
4. `StdList_Destroy_FreeHead` on **`this+0x1DC`**.
5. **Tail-jump** to `FUN_00518ec0` (Object shared-base dtor) with ECX=`this`.

Inheritance sealed by ctor twin `FUN_00575440` → `Object_SharedBase_Ctor` (`FUN_00518940`) then same vtbl. Scalar deleting wrapper `FUN_00575c00` is **vtbl[0]**.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W28-M) | `docs/reconstruction/raw/aa_00575350_FUN_00575350.md` |
| Annotated | `docs/reconstruction/raw/aa_00575350_FUN_00575350.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/Object_009d33c4_CompleteDtor.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00575350.cpp` |
| Function records | `functions/aa_00575350_FUN_00575350.md`, `functions/aa_00575350_Object_009d33c4_CompleteDtor.md` |
| Base | `Object_SharedBase_Ctor` `aa_00518940`; dtor body `FUN_00518ec0` |
| List peer | `StdList_Destroy_FreeHead` `aa_00497360` |
| Live | decompile; 106 B hex; vtbl slots; sole caller scalar-deleting |

---

## 3. Signature (sealed)

```c
// __thiscall; ECX=this; image ends in JMP FUN_00518ec0 (no local RET)
void __thiscall Object_009d33c4_CompleteDtor(void *self);
```

| Formal | Source | Conf |
|---|---|---|
| self | ECX (`8B F1`) | **High** |
| return | via base dtor | **High** |
| cleanup | `E9 …` tail-jmp (not `C2`/`C3` at body end) | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
*this = PTR_FUN_009d33c4
if p@+0x1EC: operator_delete(p); p=0; +0x1F0=0; +0x1F1=0
if begin@+0x1F8: operator_delete(begin); begin=end=cap=0
lea ecx, [this+0x1DC]; call StdList_Destroy_FreeHead
mov ecx, this; jmp FUN_00518ec0
```

| Stage | Match | Conf |
|---|---|---|
| Vtbl + owned free + flags | **Yes** | **High** |
| Buffer triple | **Yes** | **High** |
| List @ +0x1DC | **Yes** (LEA) | **High** |
| Tail-jmp base dtor | **Yes** | **High** |
| Object_SharedBase parent | **Yes** (ctor twin) | **High** |

---

## 5. Machine bytes (`read_memory`)

| Region | Note |
|---|---|
| Entry | `53 56 8B F1` … `C7 06 C4 33 9D 00` |
| Offsets | `+0x1EC`/`+0x1F0`/`+0x1F1`/`+0x1F8`/`+0x1DC` |
| List | `8D 8E DC 01 00 00` … `call 0x00497360` |
| Tail | `8B CE 5E 5B E9 06 3B FA FF` → `jmp 0x00518ec0` |
| Pad | `CC` after body |
| Size | **106 B** exclusive end `0x005753ba` |

**No `disassemble_bytes` used.**

---

## 6. Gaps

- Product / MSVC demangled derived type name.
- Semantics of `+0x1EC` payload and flag bytes.
- Full mid-field dictionary (base owns lower layout).
- Runtime / bit-exact / differential — open.

---

## 7. Verdict

CF, ABI, derived cleanup, list LEA, and base tail-jmp sealed → **accept-with-gaps**.
