# Review B (skeptical / adversarial): `aa_007a4480` NDError_Log

| Field | Value |
|---|---|
| **Stable ID** | `aa_007a4480` |
| **Review type** | Skeptical / adversarial (OWN-ONLY dual B) |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_007a4480_NDError_Log.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Function **is** `VOG_DEBUG_STOP` / hard stop helper | Body never references that string; only logs when enable==1 | **Falsified as name** — string is caller arg; gate makes common `(0,"VOG_DEBUG_STOP")` a **no-op** |
| 2 | Always logs every call | Gate `CMP …,1` / `TEST fmt` before any call | **Falsified** — skip path returns without callees |
| 3 | `DebugBreak` / `abort` / throw | Epilogue is stack restore + `RET` only | **Falsified** — no trap/exception in body |
| 4 | `__stdcall` / callee cleans varargs | Plain `RET`; caller must clean | **Falsified** — **`__cdecl`** |
| 5 | Fixed arity (2 args only) | `_vsnprintf` takes `&stack+0xC` as va_list | **Falsified** — **varargs** after fmt |
| 6 | `param_1` is bool-any-nonzero | Exact compare to **1** (`'\x01'`) | **Clarify** — `-1`/`2`/etc. **do not** log |
| 7 | Stack buffer size wrong (e.g. 0x100) | `SUB ESP,0x800` + push `0x800` | **Sealed** 2048 |
| 8 | Line number is hex-as-decimal typo | Immediate `PUSH 0x65` = 101 decimal | **Sealed** line **101** |
| 9 | Path string is different source file | `read_memory` `0x00a97124` = `...\libND\NDError.cpp` | **Sealed** |
| 10 | Dual decompiles disagree | `decompile_function` ≡ `force_decompile` | **No conflict** — third-rep **not required** |
| 11 | Returns status code | No EAX setup before `RET` | **void** (complete-analysis “undefined return” is noise for void) |
| 12 | Sibling thunk at `+0x60` is part of this unit | Own-only: next `CC` pad then unrelated prolog at `0x007a44e0` | **Out of scope** for body seal |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| enable==1 gate | **High** | Treating debug no-ops as fatal assert |
| No hard-stop | **High** | Over-engineering crash handlers on port |
| Varargs / cdecl | **High** | Stack corruption if stdcall assumed |
| Buffer 0x800 | **High** | Truncation mismatch |
| Fixed path/line/level | **High** | Wrong log provenance in tools |
| Level `3` product meaning | **Medium** | Mis-label severity in UI |
| Whether **any** retail path uses enable=1 | **Medium** (callers not owned) | Assuming logger is always dead code |
| CRT exactness of `_vsnprintf` null-termination | **Medium** | Edge-case string length |

---

## 3. Cross-check: decompile vs bytes vs pcode

| Step | Decompile | Bytes / pcode |
|---|---|---|
| Frame | `local_800[2048]` | `SUB ESP,0x800` |
| enable check | `param_1 == '\x01'` | `INT_EQUAL stack+4, 1` → `CBRANCH` skip |
| null fmt | `param_2 != 0` | `INT_NOTEQUAL stack+8, 0` → `CBRANCH` skip |
| format | `_vsnprintf(buf,0x800,fmt,&va)` | CALL IAT `0x009c64b4`; va `PTRSUB ESP,0xc` (adjusted) |
| log | `vog_LogMessage(path,0x65,3,buf)` | PUSH path `0x00a97124`, `0x65`, `3`, buf |
| return | `return` | `ADD ESP,0x800; RET` |

**Consensus:** three independent views (decompile×2, bytes, basic pcode) — **accept**.

---

## 4. Surviving contract for AutoCore

```csharp
// Behavior-exact: conditional ND error log (libND/NDError.cpp:101)
// NOT a stop / assert-abort / MessageBox.

static void NDError_Log(byte enable, string? fmt, params object[] args)
{
    // retail always builds 0x800 frame; ports may elide when enable!=1 for perf
    if (enable != 1 || fmt == null)
        return;

    // _vsnprintf(local, 0x800, fmt, va)
    string msg = string.Format(CultureInfo.InvariantCulture, fmt, args);
    if (msg.Length >= 0x800)
        msg = msg.Substring(0, 0x7FF); // CRT truncation nuance: port policy

    vog_LogMessage(
        @"C:\vog\1_code\vog_14_117_branch\libND\NDError.cpp",
        line: 0x65,   // 101
        level: 3,
        msg);
}
```

**Port traps to reject:**

- Mapping every `FUN_007a4480(0,"VOG_DEBUG_STOP")` to `Debug.Assert(false)` / `throw`.
- Treating `enable` as C truthiness (`if (enable)`).
- Renaming the **function** to `VOG_DEBUG_STOP`.
- Assuming stdcall / fixed 2-arg only (varargs sites exist).
- Inventing process termination inside this VA.

**Acceptable port policy (document as policy, not retail body):**

- Drop enable==0 call sites entirely (dead).
- Or keep as structured log only when a server-side “verbose diagnostics” flag maps to enable=1.

---

## 5. Residual (explicitly not sealed here)

1. Full enumeration of enable==1 call sites (parent residual; ~1921 xrefs).
2. Semantics of `vog_LogMessage` level `3` (callee, not this VA).
3. Whether debug builds used a different `NDError` that did hard-stop (not this image).
4. Bit-for-bit / live runtime capture of log output.
5. Next function after pad (`0x007a44e0`) — separate unit.
