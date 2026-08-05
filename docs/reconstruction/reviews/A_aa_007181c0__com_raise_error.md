# Review A (reconstruction fidelity): `aa_007181c0` `_com_raise_error`

| Field | Value |
|---|---|
| **Stable ID** | `aa_007181c0` |
| **VA** | `0x007181c0` |
| **Body span** | `007181c0`–`007181eb` |
| **Canonical name** | `_com_raise_error` |
| **Ghidra name** | `FUN_007181c0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual W16-P) |
| **Counterpart** | `reviews/B_aa_007181c0__com_raise_error.md` |
| **System** | `crt-com` / MSVC COM support |
| **Live tools** | Ghidra `decompile_function` + `read_memory` + `get_function_callers` (no `disassemble_bytes`) |
| **Verdict** | **accept** |

---

## 1. Purpose

**Non-returning** MSVC COM raise leaf — standard `_com_raise_error(HRESULT hr, IErrorInfo* perrinfo)`:

1. Allocate 16-byte stack `_com_error`.
2. Call `_com_error::_com_error(this, hr, perrinfo, fAddRef=false)` @ `0x007181f0`.
3. `_CxxThrowException(&object, &ThrowInfo_DAT_00acc2c0)` → `0x006a3d60`.

Indirect implementation behind `PTR_FUN_00af8b20` for `_com_issue_error` / `_com_issue_errorex`. **Not game domain.**

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_007181c0_FUN_007181c0.md` (+ 2026-07-29 live append) |
| Annotated | `docs/reconstruction/raw/aa_007181c0_FUN_007181c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_007181c0.cpp` |
| Function record | `docs/reconstruction/functions/aa_007181c0_FUN_007181c0.md` |
| Sibling ctor dual | `reviews/A_aa_007181f0__com_error.md` |
| Sibling dtor dual | `reviews/A_aa_007182e0__com_error_dtor.md` |
| Issue wrappers | `reviews/A_aa_00717f00__com_issue_error.md`, `A_aa_00717f20__com_issue_errorex.md` |
| Live decompile | Ghidra `decompile_function` @ `0x007181c0` |
| Bytes | `read_memory` 64 B @ `0x007181c0` |
| ThrowInfo | `read_memory` @ `0x00acc2c0` |
| Raise PTR | `read_memory` @ `0x00af8b20` → `0x007181c0` |
| Callers | `get_function_callers` → `_com_issue_error`, `_com_issue_errorex` |

**Not performed:** `disassemble_bytes`, Launcher, runtime throw golden.

---

## 3. Assembly-sealed body (`read_memory` @ `0x007181c0`)

```text
007181c0  55              push ebp
007181c1  8BEC            mov  ebp, esp
007181c3  83EC10          sub  esp, 0x10           ; _com_error local
007181c6  6A00            push 0                   ; fAddRef = false
007181c8  8B450C          mov  eax, [ebp+0xC]      ; IErrorInfo*
007181cb  50              push eax
007181cc  8B4D08          mov  ecx, [ebp+8]        ; HRESULT
007181cf  51              push ecx
007181d0  8D4DF0          lea  ecx, [ebp-0x10]     ; this = &local
007181d3  E818000000      call _com_error ctor     ; → 0x007181f0
007181d8  68C0C2AC00      push 0x00acc2c0          ; ThrowInfo*
007181dd  8D55F0          lea  edx, [ebp-0x10]
007181e0  52              push edx                 ; pExceptionObject
007181e1  E87ABBF8FF      call _CxxThrowException  ; → 0x006a3d60
007181e6  8BE5            mov  esp, ebp            ; dead after throw
007181e8  5D              pop  ebp
007181e9  C20800          ret  8                   ; stdcall 2 args
; CC pad → _com_error @ 007181f0
```

Hex (body through `ret 8`):

```
558bec83ec106a008b450c508b4d08518d4df0e81800000068c0c2ac008d55f052e87abbf8ff8be55dc20800
```

| Claim | Evidence | Conf |
|---|---|---|
| Body size **44 bytes** | `read_memory` + `CC` pad | **Confirmed** |
| Two stack formals; `ret 8` | epilogue `C2 08 00` | **Confirmed** |
| `fAddRef = false` | imm `push 0` before ctor | **Confirmed** |
| Ctor @ `0x007181f0` | rel32 from `007181d3` | **Confirmed** |
| ThrowInfo fixed `DAT_00acc2c0` | imm `push 0x00acc2c0` | **Confirmed** |
| Unwind dtor `0x007182e0` | ThrowInfo +4 | **High** |
| `_CxxThrowException` @ `0x006a3d60` | rel32 from `007181e1` | **Confirmed** |
| Raise PTR → this VA | `00af8b20` dword `007181c0` | **Confirmed** |
| Clean ≡ raw ≡ live | three-rep | **Confirmed** |
| Not game domain | CRT COM | **Confirmed** |

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Role = `_com_raise_error` | **High** | PTR + issue_error wrappers; not Ghidra library-single-match plate on this VA |
| Signature stdcall (hr, IErrorInfo*) | **Confirmed** | bytes |
| fAddRef false polarity | **Confirmed** | |
| Throw object type = `_com_error` | **High** | ctor + ThrowInfo.unwind = dtor dualed @ `007182e0` |
| Full catchable-type RTTI English | **Medium** | array ptr sealed; string not walked |
| Port for AutoCore sector/auth | **N/A** | client COM only — map to error returns |

---

## 5. Call graph (this unit)

**Callees:**

| Symbol | VA |
|---|---|
| `_com_error::_com_error(long, IErrorInfo*, bool)` | `0x007181f0` |
| `_CxxThrowException` | `0x006a3d60` |

**Callers (via `PTR_FUN_00af8b20`):**

| Symbol | VA |
|---|---|
| `_com_issue_error` | `0x00717f00` |
| `_com_issue_errorex` | `0x00717f20` |

---

## 6. Gaps

1. Full CatchableType / `type_info` string under `0x00acc2b8` / `0x00acc29c`.
2. Runtime throw/catch golden deferred.
3. Whether anything rewrites `PTR_FUN_00af8b20` at runtime (hook surface; not observed here).

**Verdict:** **accept** — CF Confirmed; library raise leaf sealed; no game-logic port required.
