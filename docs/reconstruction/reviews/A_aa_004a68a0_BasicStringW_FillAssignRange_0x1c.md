# Review A (reconstruction fidelity): `aa_004a68a0` BasicStringW_FillAssignRange_0x1c

| Field | Value |
|---|---|
| **Stable ID** | `aa_004a68a0` |
| **VA** | `0x004a68a0`–`0x004a68c6` (**39 B**) |
| **Canonical name** | `BasicStringW_FillAssignRange_0x1c` (**Inferred**) |
| **Ghidra name** | `FUN_004a68a0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W36-T) |
| **Counterpart** | `reviews/B_aa_004a68a0_BasicStringW_FillAssignRange_0x1c.md` |
| **System** | MSVC `basic_string<wchar_t>` range assign-fill |
| **Evidence pass** | Live Ghidra `batch_decompile` + `read_memory` (128 B) + `analyze_function_complete` + xrefs; 2 callers / 2 xrefs; IAT-only callee. **No** `disassemble_bytes`. |
| **Verdict** | **accept** |

---

## 1. Purpose

MSVC-style **range fill by assign** on live `basic_string<wchar_t>` slots (elem **0x1c**):

```
for (cur = first; cur != last; cur += 0x1c)
  operator=(cur, value);
```

Sole parent: `StdVector_InsertN_BasicStringW` (`0x004a7ad0`) uses this for in-place hole fill after hole-open / mid-shift (W34-R).

**Not** uninitialized fill (ctor), **not** count-N fill_n, **not** range-to-range copy, **not** POD memmove.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004a68a0_FUN_004a68a0.md` (+ 2026-07-29 W36-T append) |
| Annotated | `docs/reconstruction/raw/aa_004a68a0_FUN_004a68a0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/BasicStringW_FillAssignRange_0x1c.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004a68a0.cpp` |
| Function record | `docs/reconstruction/functions/aa_004a68a0_FUN_004a68a0.md` |
| Named record | `docs/reconstruction/functions/aa_004a68a0_BasicStringW_FillAssignRange_0x1c.md` |
| Live | decompile ≡ raw CF; full body hex; bare RET; 2 xrefs in parent only |

**Not performed:** Launcher, runtime, ledgers.

---

## 3. Signature (sealed)

```c
// cdecl; 3 stack args; plain RET; void
void BasicStringW_FillAssignRange_0x1c(
    BasicStringW_0x1c* first  /*stack*/,
    BasicStringW_0x1c* last   /*stack*/,
    const BasicStringW_0x1c* value /*stack*/);
```

| Slot | Source | Conf |
|---|---|---|
| first | stack (`MOV ESI,[ESP+8]` after push) | **High** |
| last | stack (`MOV EDI,[ESP+10]`) | **High** |
| value | stack (`MOV EBX,[ESP+18]`) | **High** |
| cleanup | bare `RET` (`C3`) | **High** |
| thiscall plate | **reject** (ECX only for nested operator=) | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
if first == last: return
loop:
  operator=(first, value) via IAT [0x009c63bc]
  first += 0x1c
  until first == last
```

Callee: IAT dword `0x009c63bc` → `0x006ec314` (wstring assign). Parent call sites push 3 args and clean with `ADD ESP,0xC` (or combined cleanup).

---

## 5. Fidelity checks

| Check | Result |
|---|---|
| Decompile ≡ raw CF | **Pass** (live 2026-07-29 ≡ raw 2026-07-23) |
| Body size | **39 B** sealed by hex end at `C3` then `CC` pad |
| Stride | `ADD ESI, 0x1C` imm |
| Element type | wstring (IAT + parent `InsertN_BasicStringW`) |
| Char twin | `0x00431450` same 39 B shape |

---

## 6. Gaps

- Product/MSVC demangle English.  
- Runtime / bit-exact / differential.

---

## 7. Verdict

Fidelity pass seals ABI/CF/stride/IAT/callers → **accept**.
