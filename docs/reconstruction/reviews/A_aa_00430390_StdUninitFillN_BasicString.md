# Review A (reconstruction fidelity): `aa_00430390` StdUninitFillN_BasicString

| Field | Value |
|---|---|
| **Stable ID** | `aa_00430390` |
| **VA** | `0x00430390`–`0x004303c0` (**48 B**) |
| **Canonical name** | `StdUninitFillN_BasicString` |
| **Ghidra name** | `FUN_00430390` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W33-G) |
| **Counterpart** | `reviews/B_aa_00430390_StdUninitFillN_BasicString.md` |
| **System** | MSVC `_Uninit_fill_n` wrapper / `basic_string` stride `0x1c` |
| **Evidence pass** | Live Ghidra `batch_decompile` + `analyze_function_complete` + `read_memory` (full 48 B) + xrefs. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Thin thiscall wrapper: fill `count` uninitialized string slots from one `value`, return dest-end. Loop body is nested `FUN_00431700`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W33-G append) | `docs/reconstruction/raw/aa_00430390_FUN_00430390.md` |
| Annotated | `docs/reconstruction/raw/aa_00430390_FUN_00430390.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdUninitFillN_BasicString.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_00430390.cpp` |
| Function record | `docs/reconstruction/functions/aa_00430390_StdUninitFillN_BasicString.md` |
| Nested | `FUN_00431700` decompile (fill loop; unowned) |
| Parent | `StdVector_InsertN_BasicString` (W32-B) |
| Live | decompile ≡ bytes; `C2 0C 00`; call → `0x00431700` |

---

## 3. Signature (sealed)

```c
// thiscall ECX=alloc; stack dest*, count, value*; RET 0x0C
BasicString_0x1c* __thiscall StdUninitFillN_BasicString(
    void* alloc,
    BasicString_0x1c* dest,
    int count,
    const BasicString_0x1c* value);
```

| Formal | Source | Conf |
|---|---|---|
| alloc | ECX | **High** (presence) |
| dest / count / value | stack; `RET 0x0C` | **High** |
| return dest+count*0x1c | lea math | **High** |

---

## 4. Control flow

| Stage | Match | Conf |
|---|---|---|
| Load value, count, dest | entry bytes | **High** |
| `FUN_00431700(dest,count,value,alloc,value)` | relative call +5 pushes | **High** |
| `ADD ESP, 0x14` | bytes | **High** |
| `EAX = dest + count*0x1c` | `*8-*1` then `*4` lea | **High** |
| `RET 0x0C` | `C2 0C 00` | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (48 B) — see raw W33-G append.

Entry: `8B 44 24 0C 56 …`.  
Epilogue: `5F 5E C2 0C 00`.

---

## 6. Gaps

- Product demangle / exact allocator formal English for ECX.
- Nested `FUN_00431700` SEH/product plate (not owned).
- Runtime / bit-exact / differential.

---

## 7. Verdict

Wrapper ABI/CF/`*0x1c` return sealed. Nested fill product open → **accept-with-gaps**.
