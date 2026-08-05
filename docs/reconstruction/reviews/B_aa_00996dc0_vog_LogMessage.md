# Review B (skeptical / adversarial): `vog_LogMessage` @ `0x00996dc0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00996dc0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00996dc0_vog_LogMessage.md` |
| **Live tools** | Ghidra `decompile_function` + `read_memory` (no `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** on this wrapper CF/ABI; **needs-more-evidence** on dispatcher policy / varargs myth |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | `vog_LogMessage` is a full printf-style logger (`fmt, ...`) | **Overstated** — this body never walks a `va_list`; sealed call sites pass a finished string as arg4 |
| 2 | All four formals feed `FUN_0076d1b0` equally | **Falsified shape** — stack gets file/line/message only; **severity rides EDI** into the sink |
| 3 | Non-fatal path still writes/logs in this function | **Falsified** — non-3 return is pure epilogue |
| 4 | Fatal path always writes `VOGCRASH.txt` | **Partially falsified** — fopen can fail; still raise+ExitProcess |
| 5 | Return value of `vog_LogMessage` is meaningful | **Falsified** — void; fatal path never returns |
| 6 | Scaffold clean is modernized / CF-rewritten | **Falsified** — CF matches raw/machine; only type-width comments differ |
| 7 | Name `vog_LogMessage` is wrong | **Survives** — plate + symbol + ubiquitous call-site pattern |
| 8 | Dispatcher return 3 is the only abort trigger | **Survives for this unit** — only `cmp eax,3` branch; **policy** of when 3 is produced is callee-owned residual |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| cdecl 4-arg wrapper + `ret` | **High** | Wrong server assert shim / crash semantics |
| Abort on dispatcher==3 | **High** | Miss process-kill edge in ports |
| Crash file + EH_Abort format | **High** | Forensic tooling mismatch |
| Severity via EDI into sink | **High** (this setup) | Mis-port of custom call shape if reimplementing sink only |
| Non-fatal = no-op wrapper | **High** | False expectation of console/file log here |
| True varargs at this entry | **Low / Tentative** | Over-engineering a va_list API nobody uses here |
| Full meaning of return codes ≠3 | **Open** | Need `FUN_0076d1b0` dual |
| Clean as bit-exact retail | **Open** | Scaffold only |

---

## 3. Surviving contract for AutoCore

```
void vog_LogMessage(const char* sourceFile, int line, int severity, const char* message)
{
  // custom handoff: severity in EDI for FUN_0076d1b0
  int status = errReport_Dispatch(sourceFile, line, message, /*edi*/ severity);
  if (status == 3) {
    FILE* f = fopen("c:\\VOGCRASH.txt", "w");
    if (f) {
      fprintf(f, "errReport::Massive failure EH_Abort: F:%s l:%d s:%d d:%s\n",
              sourceFile, line, severity, message);
      fclose(f);
    }
    raise(SIGABRT);      // 0x16
    ExitProcess(3);      // noreturn
  }
  // else: return; non-fatal logging (if any) is entirely inside the dispatcher
}
```

**Port guidance:**

- Treat this as a **thin fatal-gate wrapper**, not the real logger.
- Server/dev ports: map severity≥fatal (or dispatcher vote 3) to process abort **or** a controlled hard-fail; do **not** invent local printf in this shim.
- Do not assume every retail call is fatal — hundreds of sites use severity 1/etc. and continue.
- Source-path strings at call sites remain the best RE naming evidence; this unit is the funnel, not the catalog.

---

## 4. What would change the verdict

1. Live proof of a call site that pushes true varargs consumed **inside** `0x00996dc0` (would force plate update; machine currently denies).
2. Sealed dual of `FUN_0076d1b0` proving non-3 returns have side effects **visible only via this wrapper** (would revise “silent non-fatal” claim for the *pipeline*, not this body).
3. Machine proof that severity is **not** required in EDI (would rewrite ABI note) — current callee entry indexes `[edi*4+0x00afa2c0]`.

---

## 5. Open questions

1. Handler table / install path for `FUN_0076d1b0` (sibling).
2. Severity enum labels beyond “int fed to fprintf and EDI index”.
3. Whether `ExitProcess(3)` is ever replaced in patches / debuggers.
4. Runtime capture of VOGCRASH.txt contents under forced severity-3.

**Verdict:** **accept-with-gaps** on this wrapper CF/ABI; **needs-more-evidence** on dispatcher policy / varargs myth — safe as AutoCore diagnostics map for the **fatal gate**; do not treat as complete errReport system without `FUN_0076d1b0`.
