# Review B (skeptical / adversarial): `aa_004048c0` Win32_ThrowLastErrorAsHresult_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004048c0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W22-G) |
| **Counterpart** | `reviews/A_aa_004048c0_Win32_ThrowLastErrorAsHresult_Inferred.md` |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only.

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Returns HRESULT to caller | **Falsified** — calls noreturn `FUN_004048e0`; no `ret` |
| 2 | Always packs FACILITY_WIN32 | **Falsified** — only when `(int)err > 0`; non-positive pass through |
| 3 | Is `_CxxThrowException` itself | **Falsified** — thin wrapper; throw leaf is `004048e0` |
| 4 | Reads a stack error code | **Falsified** — samples `GetLastError` only; no formals |
| 5 | Mission/XP/game logic | **Falsified** — CRT/COM failure path |
| 6 | Same as `_com_raise_error` (`007181c0`) | **Falsified** — different ABI (no formals; single last-error path) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| GetLastError + pack + throw | **High** | Silent Win32 fails become wrong exception type |
| Signed >0 gate | **High** | Double-pack already-HRESULT codes |
| Distinct from raw-param throw `004048e0` | **High** | Callers that already hold codes misrouted |
| Noreturn contract | **High** | Port would continue after fail |

---

## 3. Cross-check

```
raw: GetLastError; if >0 pack; FUN_004048e0
live: identical
bytes: call [009c6230]; test/jle; and 0xffff; or 0x80070000; push; call 004048e0
parent MbcsString_ConvertFromWide dual already labels this as GetLastError→HRESULT throw
```

---

## 4. Surviving contract for AutoCore

```
Win32_ThrowLastErrorAsHresult():
  err = GetLastError()
  if ((int)err > 0) err = (err & 0xffff) | 0x80070000
  throw C++ exception object carrying err   // via FUN_004048e0
```

Port Win32 fail arms as **hard throw** with FACILITY_WIN32 packing — do not return error codes from this helper.

---

## 5. Open questions

None blocking for call-site fail paths.

**Verdict:** **accept**
