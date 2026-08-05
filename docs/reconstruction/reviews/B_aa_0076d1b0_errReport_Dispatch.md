# Review B (skeptical / adversarial): `errReport_Dispatch` @ `0x0076d1b0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_0076d1b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0076d1b0_errReport_Dispatch.md` |
| **Live tools** | Ghidra `decompile_function` + `read_memory` (no `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Raw decomp signature (2 args) is complete | **Falsified** — machine uses 3 stack args + EDI severity |
| 2 | Default path is `FUN_0076d020(param_2)` only | **Falsified** — 4 pushes + ESI=sourceFile |
| 3 | Handler virtual takes 2 args | **Falsified** — 5 pushes before `call [edx+4]` |
| 4 | Severity “table” holds integers | **Falsified** — six `const char*` labels (`DEBUG`…`FATAL`) |
| 5 | Any severity ≥ some threshold always returns 3 | **Partially falsified** — only **EDI > 4** forces 3 when maxVote < 2; handlers returning ≥2 override with their value (may be 2, not 3) |
| 6 | Empty handler list with `mgr+8!=0` still runs default sink | **Falsified** — empty list jumps to policy with maxVote=0 (no `FUN_0076d020`) |
| 7 | Name `errReport_Dispatch` is product-accurate | **Survives as INFERRED** — crash string uses `errReport::`; method name not on body |
| 8 | Scaffold clean was already correct | **Falsified** — pre-dual clean mirrored broken decomp arity |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| 3-arg + EDI ABI | **High** | Wrong assert/log port; severity loss |
| Label table | **High** | Wrong log prefixes |
| Return policy (`>=2` / `>4→3`) | **High** | Miss or over-abort |
| Default sink custom ESI ABI | **High** (this call site) | Broken default log line |
| Handler list walk direction | **High** enough for CF | Order of multi-handler votes only |
| Product handler interface | **Low** | Type registry only |
| Clean as bit-exact C | **Open** | EDI cannot be a C formal without extension |

---

## 3. Surviving contract for AutoCore

```
// Severity labels @ 0x00afa2c0
// 0 DEBUG, 1 INFO, 2 WARNING, 3 ERROR, 4 ASSERTION FAILED, 5 FATAL

int errReport_Dispatch(const char* file, int line, int severity, const char* msg)
{
  const char* label = SeverityLabels[severity]; // table; OOB not checked in retail
  int maxVote = 0;
  auto* mgr = GetErrReportManager(); // FUN_0076d140 → DAT_00d1f888

  if (mgr->flags_or_count_at_8 == 0) {
    maxVote = DefaultSink(file, line, severity, label, msg); // FUN_0076d020
  } else {
    for (handler : mgr->handlers) { // reverse circular list
      if (severity >= handler->minSeverity) {
        maxVote = max(maxVote,
          handler->Report(file, line, severity, label, msg)); // vtbl+4
      }
    }
  }

  if (maxVote >= 2) return maxVote;
  if (severity > 4) return 3; // FATAL+
  return maxVote;
}
```

**Port guidance:**

- Keep **fatal gate** at the wrapper (`status == 3`), not inside every log site.
- Do **not** assume default sink always runs — installed-handler mode skips it.
- Severity **4** (`ASSERTION FAILED`) does **not** auto-return 3 from this unit’s final policy (`>4` only); default sink itself may still return 3 when severity ≥ 4 (light-touch `FUN_0076d020`).
- Return **2** is a first-class non-abort vote — do not collapse to bool.

---

## 4. What would change the verdict

1. Machine proof of different table base / severity remap (would rewrite labels).
2. Handler install dual showing different payload offset than `node+8`.
3. Live call with EDI>5 (OOB) and observed behavior.
4. Product PDB/string naming this method (name only).

---

## 5. Open questions

1. `mgr+8` field exact type (bool “has handlers” vs count).
2. Full `FUN_0076d020` format composition (owned residual).
3. Whether any retail handler returns 2 under normal play.
4. Thread-safety of list walk (none visible here).

**Verdict:** **accept-with-gaps** — ABI/CF/policy **High**; handler product types + return-2 semantic residual.
