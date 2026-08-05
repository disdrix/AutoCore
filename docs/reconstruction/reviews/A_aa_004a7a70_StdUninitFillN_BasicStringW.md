# Review A (reconstruction fidelity): `aa_004a7a70` StdUninitFillN_BasicStringW

| Field | Value |
|---|---|
| **Stable ID** | `aa_004a7a70` |
| **VA** | `0x004a7a70`–`0x004a7aa0` (**48 B**) |
| **Canonical name** | `StdUninitFillN_BasicStringW` |
| **Ghidra name** | `FUN_004a7a70` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W36-S) |
| **Counterpart** | `reviews/B_aa_004a7a70_StdUninitFillN_BasicStringW.md` |
| **System** | MSVC `_Uninit_fill_n` wrapper / `basic_string<wchar_t>` stride `0x1c` |
| **Evidence pass** | Live Ghidra `batch_decompile` + function extent + xrefs/callees + `read_memory` (full 48 B) + nested `FUN_004a74f0` decompile. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Thin thiscall wrapper: fill `count` uninitialized wstring slots from one `value`, return dest-end. Loop body is nested `FUN_004a74f0`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W36-S append) | `docs/reconstruction/raw/aa_004a7a70_FUN_004a7a70.md` |
| Annotated | `docs/reconstruction/raw/aa_004a7a70_FUN_004a7a70.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdUninitFillN_BasicStringW.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_004a7a70.cpp` |
| Function record | `docs/reconstruction/functions/aa_004a7a70_StdUninitFillN_BasicStringW.md` |
| Nested | `FUN_004a74f0` decompile (fill loop; unowned) |
| Char twin | `StdUninitFillN_BasicString` (`0x00430390`, W33-G) |
| Parent | `StdVector_InsertN_BasicStringW` (W34-R) hole arm |
| Live | decompile ≡ bytes; `C2 0C 00`; call → `0x004a74f0` |

---

## 3. Signature (sealed)

```c
// thiscall ECX=alloc; stack dest*, count, value*; RET 0x0C
BasicStringW_0x1c* __thiscall StdUninitFillN_BasicStringW(
    void* alloc,
    BasicStringW_0x1c* dest,
    int count,
    const BasicStringW_0x1c* value);
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
| `FUN_004a74f0(dest,count,value,alloc,value)` | relative call +5 pushes | **High** |
| `ADD ESP, 0x14` | bytes | **High** |
| `EAX = dest + count*0x1c` | `*8-*1` then `*4` lea | **High** |
| `RET 0x0C` | `C2 0C 00` | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (48 B) — see raw W36-S append.

```
8b44240c568b74240c578b7c240c50518b4c241c515657e864faffff8d14f5000000002bd683c4148d04975f5ec20c00
```

Entry: `8B 44 24 0C 56 …`.  
Epilogue: `5F 5E C2 0C 00`.

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker (STL helper wrapper) |
| Callers | **only** insert-n hole arm @ `0x004a7d4a` |
| Callees | `FUN_004a74f0` |

Note: parent **grow** fills via `FUN_004a74f0` directly (no wrapper). Char twin `00430390` was used at both grow and in-place sites.

---

## 7. Gaps

- Product demangle / exact allocator formal English for ECX.
- Nested `FUN_004a74f0` SEH/product plate (not owned; W36-R).
- Runtime / bit-exact / differential.

---

## 8. Verdict

Wrapper ABI/CF/`*0x1c` return sealed. Nested fill product open → **accept-with-gaps**.
