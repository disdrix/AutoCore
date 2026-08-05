# Review B (skeptical / adversarial): `aa_007203b0` CSoundManager_MarkStopByName_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_007203b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_007203b0_CSoundManager_MarkStopByName_Inferred.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Deletes / frees sound objects | | **Falsified** — only flags `+0x38` / clears `+0x1b0` |
| 2 | Case-sensitive name match | | **Falsified** — `_stricmp` |
| 3 | Scans full `+0x31c` slot table | | **Falsified** — only **2×2** pointers from **`+0x80`** |
| 4 | Always runs `FUN_0071ffc0` | | **Falsified** — only if `param_3 != 0` |
| 5 | Works when `this+0x10==0` | | **Falsified** — early return, no CS |
| 6 | Same as `00723b20` ID/name stop walk | | **Falsified** — different slot set / no `FUN_00723ab0` call |
| 7 | Unlocks on all paths after Enter | | **Sealed** — single Leave after loop; no early Leave skip |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Ready + CS | **High** | Race / no-op |
| Stop flags | **High** | Sounds never stop |
| Slot walk breadth | **High** | Missed channels if port widens wrongly |
| `FUN_0071ffc0` role | **Medium** | Extra teardown missing |

---

## 3. Cross-check against raw

```text
if (this+0x10 == 0) return
EnterCS(this+0x158)
if (param_3) FUN_0071ffc0(name)
// 2 iterations, each: check pi[2] and *pi for stricmp name@+0x48
// match → +0x38=1, +0x1b0=0
LeaveCS
```

---

## 4. Surviving contract for AutoCore

```
MarkStopByName(manager, name, doExtra):
  if not manager.ready: return
  lock
  if doExtra: extraStopByName(name)
  for each of 4 bank slots at manager+0x80:
    if slot.name equals name (ci): mark stopped
  unlock
```

**Port tests:**

* Must not free memory here.
* Must be case-insensitive.
* Must not scan `+0x31c` array (that is `00723b20`).

---

## 5. Open questions

1. Why only four bank slots vs full active list.
2. `FUN_0071ffc0` dual.

**Verdict:** **accept**
