# Review A (reconstruction fidelity): `aa_00727c00` Auth_authMessageTrace

| Field | Value |
|---|---|
| **Stable ID** | `aa_00727c00` |
| **VA** | `0x00727c00` |
| **Canonical name** | `Auth_authMessageTrace` |
| **System** | auth |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00727c00_Auth_authMessageTrace.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Function record | `docs/reconstruction/functions/aa_00727c00_*.md` (or FUN_ twin) |
| Clean | `docs/reconstruction/reconstructed-exact/Auth_authMessageTrace.cpp` |
| String / plate evidence | From clean header + body |

---

## 2. Purpose (from unit)

Outbound auth message tracer: format 'Sending: %s -> %s(%s)' then vog_LogMessage(authMessageTrace.h, line 0xd, level 1). Mirror of receive tracer 0x00727b70. Called from AuthClient Send* paths. Debug/logging only.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Format string Sending: %s -> %s(%s) | **High** | Literal |
| vog_LogMessage path authMessageTrace.h line 0xd | **High** | String + constant |
| Identical SSO/heap string gate as receive twin | **High** | shared pattern |
| No packet mutation | **High** | log-only |
| Canonical clean name Auth_authMessageTrace (addr twin Auth_authMessageTrace_00727c00) | **High** | file plate |
| Control flow preserved clean ≡ raw scaffold | **High** | No modernization rewrite of CF |
| Bit-for-bit / runtime / differential | **Open** | Deferred |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| EH → string → format → log → dtor → restore | **Yes** |
| CF ≡ receive twin except format string + log line | **Yes** |

---

## 5. Gaps

1. param_1/param_2 roles not sealed beyond format args.
2. Whether every Send* path uses this open at call-graph level.

**Verdict:** **accept-with-gaps**
