# Review B (skeptical / adversarial): `aa_00553dd0` WorldClock_GetQuarterPhase01_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00553dd0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` |
| **Counterpart** | `reviews/A_aa_00553dd0_WorldClock_GetQuarterPhase01_Inferred.md` |
| **Verdict** | **accept-with-gaps** on math/ABI; product name residual open |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Same object/role as `Skill_AccuracyHitCheck` (`+0x24` accuracy) | Different VA/body; accuracy uses skill thiscall + roll; this uses time64 | **Falsified for identity** (shared only global `-1.0` sentinel) |
| 2 | Full day-of-year phase 0..1 | Uses **only** `tm_min`/`tm_sec` (hour-local), not `tm_hour`/`tm_yday` | **Falsified as full-day** — **quarter of hour** |
| 3 | Scale is ms→s only | Primary scale is **1/900**; ms→s only on sub-second branch | **Survives as dual scales** |
| 4 | `__stdcall` with stack clock ptr | `mov esi,ecx`; bare `ret` | **Falsified** — ECX host |
| 5 | Always recomputes from wall clock | Early return when `+0x24 != -1` | **Falsified as always** |
| 6 | default switch still scales | default skips `* 1/900` (goto after scale) | **Survives** — default phase stays 0 before sub-second |
| 7 | Return via EAX | float10 / FPU path; early `fld` | **ST0 sealed** |
| 8 | Modes 0..3 are sealed product “dawn/day/dusk/night” | Only math offsets proven; caller remaps again | **English open**; math sealed |
| 9 | Multiple callers in skill graph | `get_function_callers` → only `FUN_004912c0` | **Sole caller sealed** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Quarter-hour math + 1/900 | **High** | Wrong env blend timing |
| Cache -1.0 / +0x24 | **High** | Force recompute always |
| Not skill accuracy | **High** | Mis-port combat |
| Mode English | **Open** | Doc only |
| Product symbol | **Open** | Doc only |
| Runtime | **Open** | Unverified live |

---

## 3. Surviving contract

```
phase = WorldClock_GetQuarterPhase01(clock)
  if clock.f32[+0x24] != -1.0: return clock.f32[+0x24]
  secOfHour = localtime(now - clock.i64[+0x160]).(min*60+sec)
  phase = (secOfHour - {0,900,1800,2700}[mode]) / 900   // mode=clock+0x154
  // + optional sub-second from g_dwClientTickMs
  return clamp(phase, 0, 1)
```

Caller `FUN_004912c0` remaps phase by same mode into light curve.

---

## 4. Residual uncertainty

| # | Item | Blocks rename seal? |
|---|---|---|
| R1 | Product name | No (`_Inferred`) |
| R2 | Mode English | No |
| R3 | Writer of `+0x160` / `+0x24` | No for getter CF |
| R4 | Runtime / bit-exact | No |

**Verdict:** **accept-with-gaps**.
