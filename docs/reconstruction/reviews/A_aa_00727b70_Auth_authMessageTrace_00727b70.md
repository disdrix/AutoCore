# Review A (reconstruction fidelity): `aa_00727b70` Auth_authMessageTrace_00727b70

| Field | Value |
|---|---|
| **Stable ID** | `aa_00727b70` |
| **VA** | `0x00727b70` |
| **Canonical name** | `Auth_authMessageTrace_00727b70` |
| **System** | auth |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00727b70_Auth_authMessageTrace_00727b70.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Function record | `docs/reconstruction/functions/aa_00727b70_*.md` (or FUN_ twin) |
| Clean | `docs/reconstruction/reconstructed-exact/Auth_authMessageTrace_00727b70.cpp` |
| String / plate evidence | From clean header + body |

---

## 2. Purpose (from unit)

Inbound auth message tracer: format 'Receiving: %s <- %s(%s)' via FUN_0076cec0 then vog_LogMessage(authMessageTrace.h, line 0x12, level 1). Pair of send-side tracer at 0x00727c00. Debug/logging only — not protocol codec.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Format string Receiving: %s <- %s(%s) | **High** | Literal in clean ≡ raw |
| vog_LogMessage path authMessageTrace.h line 0x12 | **High** | String + line constant |
| SSO/heap string path via FUN_0067b1b0 size+0x18 gate | **High** | if size < 0x10 use inline else ptr |
| No packet mutation / no send | **High** | log-only CF |
| param_1 / param_2 are message-name / peer labels | **Medium** | format args; types not sealed |
| Control flow preserved clean ≡ raw scaffold | **High** | No modernization rewrite of CF |
| Bit-for-bit / runtime / differential | **Open** | Deferred |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| EH frame → build string → format → log → dtor string → restore EH | **Yes** |
| No invented modernization of SSO check | **Yes** |

---

## 5. Gaps

1. Exact identity of param_1/param_2 (opcode name vs direction vs peer) open.
2. FUN_0067b1b0 / FUN_0076cec0 types unresolved.

**Verdict:** **accept-with-gaps**
