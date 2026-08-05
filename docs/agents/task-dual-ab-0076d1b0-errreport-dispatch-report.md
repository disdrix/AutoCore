# Dual A/B — `aa_0076d1b0` errReport_Dispatch

**Date:** 2026-07-29  
**Wave:** W17-F OWN-ONLY  
**Owned VA:** `0x0076d1b0` only  
**Tools:** Ghidra `decompile_function` / `read_memory` (+ light callees `0x0076d140`, `0x0076d020`; no `disassemble_bytes`; no Launcher; no parent ledger edits)  
**Verdict:** **accept-with-gaps**

---

## Sealed facts

### Role

| Fact | Evidence |
|---|---|
| errReport **dispatcher** under `vog_LogMessage` | call @ `0x00996dd6`; crash string `errReport::…` |
| Severity in **EDI**; labels `@ 0x00afa2c0` | `mov ebp,[edi*4+0x00afa2c0]`; strings DEBUG…FATAL |
| 3 stack args: sourceFile, line, message | caller `add esp,0xC` + stack loads |
| Default sink when **`mgr+8==0`** | `FUN_0076d020` + ESI=sourceFile |
| Else max-vote handlers (`vtbl+4`, threshold `@ handler+4`) | 5-arg push sequence |
| Return **≥2** kept; else **severity>4 → 3** | `cmp ebx,2` / `cmp edi,4` |
| Return **3** ⇒ abort at wrapper | sibling dual `vog_LogMessage` |
| ABI **cdecl**, **`ret`**, body **`0076d1b0`–`0076d245`** | hex tail `C3` |

### Signature

```c
// Retail: severity in EDI; stack (sourceFile, line, message)
// Portable: severity explicit
int errReport_Dispatch(const char* sourceFile, int line, int severity, const char* message);
// Name INFERRED from errReport:: strings + role
```

### Severity labels

| EDI | Label |
|---|---|
| 0 | `DEBUG` |
| 1 | `INFO` |
| 2 | `WARNING` |
| 3 | `ERROR` |
| 4 | `ASSERTION FAILED` |
| 5 | `FATAL` |

### Algorithm (authoritative)

```
label = SeverityTable[EDI]
mgr = FUN_0076d140()
if mgr[+8]==0:
    maxVote = FUN_0076d020(line, EDI, label, message)  // ESI=sourceFile
else:
    reverse-walk list mgr[+4]
    for handler with EDI >= handler[+4]:
        maxVote = max(maxVote, handler->vtbl[+4](file,line,EDI,label,msg))
if maxVote >= 2: return maxVote
if EDI > 4: return 3
return maxVote
```

### Decomp defects closed

1. Arity **3+EDI** (raw showed 2).
2. Default sink **4 stack + ESI** (raw unary).
3. Handler call **5 args** (raw 2).
4. Label table entry sealed.

### Call surface

| Metric | Value |
|---|---|
| Xrefs | **~44** |
| Named callers | `vog_LogMessage`, graphics/error assert paths |

### Port implication

Fatal gate stays at wrapper (`status==3`). Installed-handler mode **skips** default sink. Do not collapse return codes to bool — **2** is non-abort.

---

## Gaps

1. Handler registration / product interface (`FUN_0076d250` residual).
2. `mgr+8` field exact type.
3. Return-2 semantic.
4. OOB severity (>5).
5. Runtime / bit-exact verification.
6. Full `FUN_0076d020` format composition (not owned).

---

## Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_0076d1b0_errReport_Dispatch.md` | accept-with-gaps |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_0076d1b0_errReport_Dispatch.md` | accept-with-gaps |

---

## Files touched / authoritative

| Role | Absolute path |
|---|---|
| Dual A | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reviews\A_aa_0076d1b0_errReport_Dispatch.md` |
| Dual B | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reviews\B_aa_0076d1b0_errReport_Dispatch.md` |
| Function record | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\functions\aa_0076d1b0_errReport_Dispatch.md` |
| Raw | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\raw\aa_0076d1b0_FUN_0076d1b0.md` |
| Annotated | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\raw\aa_0076d1b0_FUN_0076d1b0.annotated.md` |
| Clean | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reconstructed-exact\errReport_Dispatch.cpp` |
| This report | `C:\Users\josh\Documents\GitHub\AutoCore\docs\agents\task-dual-ab-0076d1b0-errreport-dispatch-report.md` |

Legacy scaffold (superseded for dual):  
`functions/aa_0076d1b0_FUN_0076d1b0.md`,  
`reconstructed-exact/FUN_0076d1b0.cpp` — prefer **errReport_Dispatch** paths.

Closes residual called out by sibling dual `aa_00996dc0` (`vog_LogMessage`) for dispatcher policy.
