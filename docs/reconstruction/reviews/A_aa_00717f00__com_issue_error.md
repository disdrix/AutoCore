# Review A (reconstruction fidelity): `aa_00717f00` `_com_issue_error`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00717f00` |
| **VA** | `0x00717f00` |
| **Canonical name** | `_com_issue_error` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00717f00__com_issue_error.md` |
| **System** | `crt-com` / MSVC COM support (library) |
| **Live tools** | Ghidra `decompile_function` + `read_memory` + callers |
| **Verdict** | **accept** (library wrapper sealed; not game logic) |

---

## 1. Purpose

MSVC COM helper: raise a COM failure for HRESULT `hr` with **no** `IErrorInfo` context. Body is a one-liner trampoline into the raise implementation via IAT/pointer `PTR_FUN_00af8b20` with second arg **NULL**.

Ghidra library match: **Visual Studio 2003/2005 Debug** `void __stdcall _com_issue_error(long)`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00717f00__com_issue_error.md` |
| Annotated | `docs/reconstruction/raw/aa_00717f00__com_issue_error.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/_com_issue_error.cpp` |
| Function record | `docs/reconstruction/functions/aa_00717f00__com_issue_error.md` |
| Live declassify | Ghidra name `_com_issue_error`, class **wrapper** |
| Raise target | `PTR_FUN_00af8b20` → `0x007181c0` (`FUN_007181c0`) |

---

## 3. Seal: body bytes (High)

`read_memory` @ `0x00717f00` (body through ret; then `CC` pad to sibling):

```
00717f00  55              push ebp
00717f01  8B EC           mov  ebp, esp
00717f03  6A 00           push 0              ; IErrorInfo* = NULL
00717f05  8B 45 08        mov  eax, [ebp+8]   ; hr
00717f08  50              push eax
00717f09  FF 15 20 8B AF 00  call dword ptr [PTR_FUN_00af8b20]
00717f0f  5D              pop  ebp
00717f10  C2 04 00        ret  4              ; __stdcall 1 arg
; 00717f13..00717f1f  CC padding → next fn _com_issue_errorex
```

Hex: `558bec6a008b450850ff15208baf005dc20400`

| Claim | Evidence | Conf |
|---|---|---|
| Body size **19 bytes** (`00717f00`–`00717f12`) | `read_memory` | **High** |
| `__stdcall` one `long` formal; `ret 4` | `C2 04 00` + `[ebp+8]` | **High** |
| Second arg to raise always **0** | `push 0` before call | **High** |
| Indirect call via `00af8b20` | `FF 15 20 8B AF 00` | **High** |
| Slot points at `0x007181c0` | `read_memory` @ `00af8b20` → `c0 81 71 00` | **High** |
| No game globals / no side effects beyond raise | leaf wrapper | **High** |
| Clean ≡ raw ≡ live | three-rep | **High** |

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Name `_com_issue_error` | **Confirmed** | Ghidra library single-match |
| Signature `void __stdcall _com_issue_error(long hr)` | **Confirmed** | bytes + symbol |
| Forwards to raise(hr, NULL) | **High** | body sealed |
| Not AutoAssault game code | **Confirmed** | CRT/COM support |
| Exact raise implementation (`_com_raise_error` semantics) | **Probable** | callee `FUN_007181c0` not dualed here |
| Port needed for server | **N/A** | client COM error path only |

---

## 5. Callers (sample)

Ghidra lists many (30+ page window): COM wrappers / DB helpers including `DB_ReadPowerPlantSpecific` `0x007f4c50`, clusters under `0x007b*` / `0x007c*`, and internal `FUN_00717fb0` / `FUN_00718082`. All treat this as HRESULT failure funnel — **not** game mission/skill logic.

---

## 6. Gaps

1. Full dual of `FUN_007181c0` raise body (throw / longjmp / `_com_error` ctor) — out of unit.
2. Whether Debug vs Release CRT variant differs (Ghidra match notes Debug libraries).
3. Runtime / bit-exact deferred.

**Verdict:** **accept** — sealed library wrapper; dual complete for OWN unit.
