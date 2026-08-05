# Review B (skeptical / adversarial): `aa_00781c30` Net_GhostConnection

| Field | Value |
|---|---|
| **Stable ID** | `aa_00781c30` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00781c30_Net_GhostConnection.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Per-object field unpack | Falsified — connection hub |
| 2 | Auth login only | Falsified — ghost connection path |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Connection vs object role | High | Mis-port layer |
| Write helper order | Medium | Scope desync |

---

## 3. Cross-check against raw

```
GhostConnection hub: bitstream writes + connection callees.
Not UnpackGhostUpdate; residual FUN names.
```

---

## 4. Surviving contract for AutoCore

```
Ghost connection lifecycle for AutoCore TNL/net layer mapping.
```

---

## 5. Open questions

1. Map to TNL.NET GhostConnection methods.
2. Document param_2/param_3 roles from call sites.

**Verdict:** **accept-with-gaps**
