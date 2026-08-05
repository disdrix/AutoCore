# Review A (reconstruction fidelity): `aa_0076d1b0` errReport_Dispatch

| Field | Value |
|---|---|
| **Stable ID** | `aa_0076d1b0` |
| **VA** | `0x0076d1b0` |
| **Canonical name** | `errReport_Dispatch` |
| **System** | diagnostics / errReport |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (fidelity) |
| **Counterpart** | `reviews/B_aa_0076d1b0_errReport_Dispatch.md` |
| **Live tools** | Ghidra `decompile_function` + `read_memory` (no `disassemble_bytes`) |
| **Program** | `autoassault.exe` only |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Core **errReport dispatch** under `vog_LogMessage`. Resolves severity labels, either runs the **default sink** or **max-votes** registered handlers, then applies the **FATAL+ → 3** abort policy that the wrapper turns into `VOGCRASH.txt` / process exit.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Live decompile | `batch_decompile` @ `0x0076d1b0` (+ light `0x0076d140`, `0x0076d020`) |
| Body bytes | `read_memory(0x0076d1b0, 256)` — body ends `C3` @ `0x0076d245` |
| Severity table | `read_memory(0x00afa2c0, 64)` + string bytes at label targets |
| Function meta | Body `0076d1b0`–`0076d245` |
| Callers | includes `vog_LogMessage` @ `0x00996dd6` |
| Sibling dual | `A/B_aa_00996dc0_vog_LogMessage` (wrapper residual closed here) |
| Raw / annotated / clean | `raw/aa_0076d1b0_*`, `reconstructed-exact/errReport_Dispatch.cpp` |

---

## 3. Seal: body (`read_memory` @ `0x0076d1b0`)

Body **`0x0076d1b0`–`0x0076d245`**.

### ABI

| Item | Machine | Conf |
|---|---|---|
| Convention | **cdecl**, plain **`ret` (`C3`)** | **High** |
| Stack | sourceFile, line, message | **High** (caller `add esp,0xC` + loads) |
| EDI | severity (indexes label table) | **High** |
| EBP after entry | severity label `const char*` | **High** |
| Return | int status; **3** = abort at wrapper | **High** |

### Severity labels (`0x00afa2c0`)

| EDI | String VA | Text |
|---|---|---|
| 0 | `0x00a28b7c` | `DEBUG` |
| 1 | `0x00a9d054` | `INFO` |
| 2 | `0x00a9d04c` | `WARNING` |
| 3 | `0x00a9d044` | `ERROR` |
| 4 | `0x00a9d030` | `ASSERTION FAILED` |
| 5 | `0x00a9d028` | `FATAL` |

### Algorithm (authoritative)

```
label = SeverityTable[EDI]
mgr = FUN_0076d140()   // &DAT_00d1f888
maxVote = 0

if mgr[+8] == 0:
    // ESI = sourceFile
    maxVote = FUN_0076d020(line, EDI, label, message)
else:
    reverse-walk list at mgr[+4]
    for each handler where EDI >= handler[+4]:
        vote = handler->vtbl[+4](sourceFile, line, EDI, label, message)
        maxVote = max(maxVote, vote)

if maxVote >= 2: return maxVote
if EDI > 4: return 3        // FATAL+
return maxVote
```

### Decomp defects closed

1. Arity **3+EDI**, not 2.
2. Default sink **4 stack + ESI**, not unary `param_2`.
3. Handler call **5 args**, not 2.
4. Label table entry at function start: `mov ebp,[edi*4+0x00afa2c0]`.

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF + return policy | **High** | machine `cmp ebx,2` / `cmp edi,4` |
| Severity table strings | **High** | `read_memory` |
| Default vs handler branch on `mgr+8` | **High** | |
| Wrapper abort on return 3 | **High** | sibling dual |
| Handler product types | **Tentative** | list node layout MSVC-like |
| Return code 2 meaning | **Open** | not abort at wrapper |
| Clean bit-exact EDI plumbing | **Open** | C clean uses comments for EDI |

---

## 5. Gaps

1. Handler registration dual (`FUN_0076d250` et al.).
2. Who sets `mgr+8` in retail play.
3. OOB severity (>5) behavior (no bounds check here).
4. Exact `FUN_0076d020` format-string arg order (light touch only).
5. Runtime / differential.

---

## 6. Port implication

```
status = Dispatch(file, line, severity, message);
if (status == 3) HardAbort(); // match vog_LogMessage
// else continue; logging side effects are inside dispatch/handlers
```

Map severity enum 0..5 to DEBUG..FATAL. Default sink should still run when no handlers installed.

**Verdict:** **accept-with-gaps**
