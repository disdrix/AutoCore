# Review B (skeptical / adversarial): `aa_00723b20` CSoundManager_StopMatchingSounds_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00723b20` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00723b20_CSoundManager_StopMatchingSounds_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | This is play/queue | | **Falsified** — only `_stopSound` |
| 2 | Scans bank at `+0x80` only | | **Falsified** — full table **`+0x31c`** / count **`+0x210`** |
| 3 | Wildcard is `idLo==0 && idHi==0` | | **Falsified** — **`(idLo & idHi) == 0xFFFFFFFF`** (both all-bits, or their AND — sealed as written) |
| 4 | Stops without enable check | | **Falsified** — `this+600` gate |
| 5 | Returns count stopped | | **Falsified** — returns **0** |
| 6 | Same as `MarkStopByName` | | **Falsified** — different slot set; calls `_stopSound` |
| 7 | Name match is `_stricmp` | | **Falsified** — **case-sensitive** bytewise loop (no `_stricmp`) |
| 8 | `_stopSound` identity | string | **Sealed** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Table + count | **High** | Miss stops |
| Wildcard predicate | **High** | Wrong branch |
| Case-sensitive name | **High** | Port using stricmp diverges |
| `_stopSound` callee | **High** | No effect |
| `+0x37` rewrite | **Medium** | Partial stops |

---

## 3. Cross-check against raw

```text
if (this+600==0) return 0
if ((param_2 & param_3) == 0xffffffff) {
  // name-required scan; match slot+0x48 → FUN_00723ab0
} else {
  // match ids +0x40/+0x44 and +0x35; optional name; FUN_00723ab0
}
return 0
```

Note: decompiler uses `param_2 & param_3` (bitwise AND), not equality of each to -1 independently — **attack:** “both must be -1” is **stronger** than AND; if only one is -1 and other 0, AND is 0, not wildcard. Sealed as **AND == 0xFFFFFFFF** (typically both 0xFFFFFFFF).

---

## 4. Surviving contract for AutoCore

```
StopMatchingSounds(manager, idLo, idHi, flagA, name, force):
  if !manager.enabled: return 0
  if wildcard(idLo, idHi):
    stop each active slot with matching name (force can relax +0x36)
  else:
    stop each slot matching id pair + flagA (+ optional name rules)
  return 0
```

**Port tests:**

* Must call `_stopSound` not free.
* Name compares case-sensitive.
* Wildcard only when AND of ids is all-ones.

---

## 5. Open questions

1. `slot+0x3a` “flagged to start playing” interaction (log text in `_stopSound`).
2. Suffix path product meaning.

**Verdict:** **accept-with-gaps**
