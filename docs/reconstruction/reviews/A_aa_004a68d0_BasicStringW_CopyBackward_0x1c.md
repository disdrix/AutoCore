# Review A (reconstruction fidelity): `aa_004a68d0` BasicStringW_CopyBackward_0x1c

| Field | Value |
|---|---|
| **Stable ID** | `aa_004a68d0` |
| **VA** | `0x004a68d0`–`0x004a6902` (**51 B**) |
| **Canonical name** | `BasicStringW_CopyBackward_0x1c` (**Inferred**) |
| **Ghidra name** | `FUN_004a68d0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W36-T) |
| **Counterpart** | `reviews/B_aa_004a68d0_BasicStringW_CopyBackward_0x1c.md` |
| **System** | MSVC `basic_string<wchar_t>` free `copy_backward` helper |
| **Evidence pass** | Live Ghidra `batch_decompile` + `read_memory` + `analyze_function_complete` + xrefs; 1 caller / 1 xref; IAT-only callee. **No** `disassemble_bytes`. |
| **Verdict** | **accept** |

---

## 1. Purpose

Free reverse-assign over half-open range `[first, last)` of live `basic_string<wchar_t>` elements into a destination ending at `dest_end` (element stride **0x1c**). Implements mid-insert tail shift for `StdVector_InsertN_BasicStringW`.

**Not** forward `std::copy`, **not** POD memmove, **not** uninitialized construct, **not** fill.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004a68d0_FUN_004a68d0.md` (+ 2026-07-29 W36-T append) |
| Annotated | `docs/reconstruction/raw/aa_004a68d0_FUN_004a68d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/BasicStringW_CopyBackward_0x1c.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004a68d0.cpp` |
| Function record | `docs/reconstruction/functions/aa_004a68d0_FUN_004a68d0.md` |
| Named record | `docs/reconstruction/functions/aa_004a68d0_BasicStringW_CopyBackward_0x1c.md` |
| Live | decompile ≡ raw CF; full body hex; bare RET; EAX return; 1 xref |

**Not performed:** Launcher, runtime, ledgers.

---

## 3. Signature (sealed)

```c
// cdecl; 3 stack args; plain RET; returns final dest*
BasicStringW_0x1c* BasicStringW_CopyBackward_0x1c(
    BasicStringW_0x1c* first    /*stack → EBX*/,
    BasicStringW_0x1c* last     /*stack → ESI*/,
    BasicStringW_0x1c* dest_end /*stack → EDI*/);
```

| Slot | Source | Conf |
|---|---|---|
| first | stack (`MOV EBX,[ESP+8]`) | **High** |
| last | stack (`MOV ESI,[ESP+10]`) | **High** |
| dest_end | stack (`MOV EDI,[ESP+18]`) | **High** |
| return | **EAX** (`MOV EAX,EDI` / empty path load) | **High** |
| cleanup | bare `RET` (`C3`) | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
if first == last: return dest_end
do:
  last -= 0x1c; dest_end -= 0x1c
  operator=(dest_end, last) via IAT [0x009c63bc]
while last != first
return dest_end
```

Callee: IAT dword `0x009c63bc` → `0x006ec314`. Sole caller `0x004a7dbf` immediately followed by fill `004a68a0` @ `0x004a7dcc`.

---

## 5. Fidelity checks

| Check | Result |
|---|---|
| Decompile ≡ raw CF | **Pass** |
| Body size | **51 B** sealed (matches char twin `00431790`) |
| Reverse walk | `SUB ESI/EDI, 0x1C` before each assign |
| Empty path | returns original dest_end in EAX |
| Char twin | `0x00431790` same algorithm |

---

## 6. Gaps

- Product/MSVC demangle English.  
- Runtime / bit-exact under overlap edges.

---

## 7. Verdict

Fidelity pass seals ABI/CF/stride/IAT/return → **accept**.
