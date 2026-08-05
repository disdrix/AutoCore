# Review B (skeptical / adversarial): `aa_0076c330` Timer_GetTimeSeconds_Rdtsc

| Field | Value |
|---|---|
| **Stable ID** | `aa_0076c330` |
| **VA** | `0x0076c330` |
| **Canonical name** | `Timer_GetTimeSeconds_Rdtsc` / `FUN_0076c330` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W16-R) |
| **Counterpart** | `reviews/A_aa_0076c330_Timer_GetTimeSeconds_Rdtsc.md` |
| **System** | timer / util |
| **Verdict** | **accept-with-gaps** — agree with A on CF/ABI; reject wrong-unit / wrong-sibling merges |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Returns integer tick count | x87 return; callers `fstp dword` float | **Falsified** as int |
| 2 | Returns milliseconds | quot is `tsc/scale` with scale = ticks/**second** from QPF calibrate | **Falsified** |
| 3 | Direct `QueryPerformanceCounter` | Body is `rdtsc` + scale only; QPC only inside calibrator | **Falsified** |
| 4 | Same as `FUN_0076c3c0` | Sibling is object-relative Δtsc × per-object scale; different VA/ABI | **Falsified** merge |
| 5 | Always calibrated before any call without check | Flag gate real; first call pays calibrate | **Falsified** as unconditional |
| 6 | Takes `this` / zone object | 0 args; no ECX use for object | **Falsified** |
| 7 | Scale is compile-time constant | Globals zero in image; written by `FUN_0076c270` | **Falsified** |
| 8 | clean invents math | Expression matches live decompile | **Survives** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Seconds as f80 ST0 | **High** | 1000× timing bugs if treated as ms |
| Lazy init + scale globals | **High** | First-call hang/zero-div if skip calibrate |
| Cross-cutting util (not skills/physics) | **High** | Wrong system ownership |
| Rem 32-bit exactness forever | **Probable** | Tiny frac error only in edge TSC |
| Product name | **Open** | Doc only |
| Thread-safe init | **Open / weak** | Dual init race on multi-thread first use |

---

## 3. Cross-check against raw / live / bytes

```
decompile_function ≡ frozen raw CF
bytes: cmp [d1a530]; call 76c270; rdtsc; call __aulldiv; fild/fdivp/faddp; ret
calibrator 76c270: QPF/QPC + rdtsc loop → store d1a538/d1c; d1a530=1
NDResource dual: call 76c330; fstp dword [obj+0x1c]  → float seconds stamp
```

### Merge traps

- Do **not** fold into `FUN_0076c3c0` (zone/object timer).
- Do **not** replace with raw QPC in ports without matching calibrate semantics (game expects TSC scale path).
- Do **not** assume re-calibration — flag stays set.

---

## 4. Surviving contract for AutoCore

```
// Port contract (behavior):
seconds_f = Timer_GetTimeSeconds_Rdtsc()
  ensure g_tscPerSec calibrated once (QPC vs RDTSC)
  return rdtsc() / g_tscPerSec   as floating seconds

AutoCore must NOT:
  - return ms/us without documenting scale change
  - skip lazy calibrate (div0 / nonsense)
  - treat as object method
  - share implementation with FUN_0076c3c0 without ABI proof
```

---

## 5. CF challenge of Review A

| A claim | B position |
|---|---|
| Lazy init + rdtsc + aulldiv + f80 | **Agree Confirmed** |
| Units = seconds | **Agree High** |
| accept-with-gaps | **Agree** |
| Product English open | **Agree** |

---

## 6. Open questions

1. PDB / string name.
2. Multi-core TSC sync assumptions on period hardware (historical client).
3. Full dual of `aa_0076c270` calibrator.
4. Live capture of returned values vs wall clock.

**Verdict:** **accept-with-gaps** — agree with A; block ms/QPC-direct/sibling-merge mistakes.
