# Review A (reconstruction fidelity): `aa_00401a40` Std_LengthError_CtorFromString

| Field | Value |
|---|---|
| **Stable ID** | `aa_00401a40` |
| **VA** | `0x00401a40`–`0x00401a90` |
| **Canonical name** | `Std_LengthError_CtorFromString` |
| **Prior scaffold** | `FUN_00401a40` |
| **Rejected misname** | `Named_CalleeOf_Named_CalleeOf_Auth_AuthServer_00401a40` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (MSVC length_error ctor) |
| **Counterpart** | `reviews/B_aa_00401a40_Std_LengthError_CtorFromString.md` |
| **System** | MSVC STL / exceptions |
| **Verdict** | **accept** — ABI/CF/RTTI sealed |

**Tools:** Ghidra `decompile_function` + `read_memory` + RTTI TypeDescriptor strings + callers. **No** `disassemble_bytes`. **No** Launcher. Own VA only.

---

## 1. Purpose

Leaf **constructor** for `std::length_error` from a `std::string` message. Parents construct a temporary string (`"vector<T> too long"`, `"map/set<T> too long"`, …), call this, then `_CxxThrowException` with ThrowInfo `DAT_00acc388`.

```
Std_LengthError_CtorFromString(this, msg) -> this
  SEH install
  logic_error(msg)   // FUN_00401aa0
  this->vtbl = length_error_vtbl  // PTR_FUN_009c7634
  return this
```

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Live decompile | `decompile_function` `0x00401a40` ≡ raw |
| Base decompile | `FUN_00401aa0` — `exception` + string @ `+0xc` + logic_error vtbl |
| Bytes | `read_memory` 64 B entry; epilogue `C2 04 00` |
| RTTI | `list_strings` / `read_memory` — `.?AVlength_error@std@@` @ `0x00af8bf0` |
| ThrowInfo | `DAT_00acc388` catchables → length_error / logic_error / exception |
| Sample caller | `StdVector_ThrowTooLong` `0x004540b0` (string → ctor → throw) |
| Clean | `reconstructed-exact/Std_LengthError_CtorFromString.cpp` |
| Function record | `functions/aa_00401a40_Std_LengthError_CtorFromString.md` |

---

## 3. Sealed residuals

### 3.1 ABI — **Confirmed**

| Fact | Evidence |
|---|---|
| Convention | **`__thiscall`**: `MOV ESI,ECX`; stack arg string* |
| Cleanup | **`RET 4`** (`C2 04 00`) |
| Return | `this` in EAX |
| Body | `0x00401a40`–`0x00401a90` |
| Sole callee | `FUN_00401aa0` |

```c
std::length_error* __thiscall
Std_LengthError_CtorFromString(std::length_error* this, const std::string* msg);
```

### 3.2 Control flow — **SEALED**

Live decompile **≡** 2026-07-23 raw. Single path: SEH → base ctor → vtbl install → return this.

### 3.3 Type identity — **Confirmed**

| Symbol | Address / evidence |
|---|---|
| `.?AVlength_error@std@@` | `0x00af8bf0` |
| `.?AVlogic_error@std@@` | `0x00af8bd0` |
| `.?AVexception@@` | `0x00af8bb8` |
| length_error vtbl | `PTR_FUN_009c7634` |
| logic_error vtbl (base) | `PTR_FUN_009c7628` |
| ThrowInfo | `DAT_00acc388` |

### 3.4 Misname rejection — **Confirmed**

Auto plate `Named_CalleeOf_Named_CalleeOf_Auth_AuthServer_00401a40` is an xref-seed artifact. Unit is a **global STL ctor** with 50+ callers across containers, not Auth-specific.

---

## 4. Gaps

1. Full length_error vtable slot English (`what`, dtor, …) — low priority.
2. Runtime throw golden.
3. Exact CRT string layout version — not required for ports that use managed exceptions.

---

## 5. Verdict

**accept** — complete leaf ctor; RTTI + ABI + CF sealed.
