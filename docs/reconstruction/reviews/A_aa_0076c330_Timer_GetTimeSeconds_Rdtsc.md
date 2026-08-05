# Review A (reconstruction fidelity): `aa_0076c330` Timer_GetTimeSeconds_Rdtsc

| Field | Value |
|---|---|
| **Stable ID** | `aa_0076c330` |
| **VA** | `0x0076c330` |
| **Canonical name (Ghidra)** | `FUN_0076c330` |
| **Proposed name** | `Timer_GetTimeSeconds_Rdtsc` (**High** role; product English open) |
| **Prior scaffold alias** | `Named_CalleeOf_Named_assManager_0076c330` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — W16-R) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live decompile) |
| **Counterpart** | `reviews/B_aa_0076c330_Timer_GetTimeSeconds_Rdtsc.md` |
| **System** | timer / util (cross-cutting) |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Nullary float timer leaf:** ensure TSC frequency is calibrated, read `rdtsc`, divide by the 64-bit scale in `DAT_00d1a538:DAT_00d1a53c`, return **seconds** as x87 `float80` on ST0.

Used wherever the client needs a cheap float “now” (resource last-acquire stamps, manager clocks, zone/helper ages). **Not** QPC-direct, **not** the object-relative zone helper at `0x0076c3c0`.

### Control flow (summary)

1. If `DAT_00d1a530 == 0` → `FUN_0076c270()` (QPC + rdtsc calibrate → scale globals; flag = 1).
2. Load scale hi/lo; `rdtsc`.
3. `quot = __aulldiv(tsc_lo, tsc_hi, scale_lo, scale_hi)`.
4. Fractional term from remainder ÷ unsigned scale (MSVC u64→f80 idiom on scale high dword).
5. ST0 = `quot + frac`; `ADD ESP,0x10; RET`.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `decompile_function` @ `0x0076c330` |
| Calibrator | `decompile_function` @ `0x0076c270` |
| Bytes | `read_memory` 160 B @ `0x0076c330` (rdtsc, globals, `__aulldiv`, x87 epilogue) |
| Globals | `read_memory` 32 B @ `0x00d1a530` (static zeros) |
| Callers | `get_function_callers` / `get_xrefs_to` |
| Callees | `get_function_callees` → `FUN_0076c270`, `__aulldiv` |
| Downstream dual | `A\|B_aa_00745ee0_NDResource_AcquireInnerObject` (timer → `fstp float`) |
| Raw / annotated / clean | `docs/reconstruction/raw|reconstructed-exact` for `aa_0076c330` |
| Function record | `docs/reconstruction/functions/aa_0076c330_FUN_0076c330.md` |

**This pass:** live decompile + read_memory + callers/callees. **Not performed:** `disassemble_bytes`, Launcher, runtime capture, parent ledger edits.

---

## 3. Signature

```c
// cdecl — no stack args; result in ST0
float10 /* x87 long double */ Timer_GetTimeSeconds_Rdtsc(void);
// Ghidra: float10 FUN_0076c330(void)
```

| Claim | Evidence | Conf |
|---|---|---|
| 0 args / plain `RET` | epilogue `ADD ESP,10; RET` | **High** |
| Return float80 on ST0 | x87 `fild/fdivp/faddp` chain; callers `fstp dword` | **High** |
| Lazy init flag `DAT_00d1a530` | `cmp byte [d1a530],0` / `call 76c270` | **High** |
| Scale `DAT_00d1a538:53c` | loads + calibrator stores | **High** |

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF: flag → calibrate → rdtsc → aulldiv → f80 return | **High** | live ≡ raw |
| Scale = TSC ticks per second | **High** | calibrator uses QPF × Δtsc/Δqpc |
| Units = **seconds** | **High** | quot is full seconds; callers treat as time |
| clean ≡ raw CF | **High** | refined scaffold preserves expression |
| Product English | **Open** | no string/RTTI on body |
| 32-bit rem approximation always exact | **Probable** | MSVC low-part rem; fine for normal uptime |
| Thread-safe first init | **Open** | no lock around flag/scale |

---

## 5. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Lazy `FUN_0076c270` | Yes |
| `rdtsc` | Yes |
| `__aulldiv` with scale globals | Yes |
| rem / u64→f80 / quot+frac | Yes (decomp expression) |
| No branches beyond init | Yes |

### Recovered contract

```
Timer_GetTimeSeconds_Rdtsc():
  if !g_tscScaleReady: CalibrateTscPerSec()   // FUN_0076c270
  tsc = rdtsc()
  quot = tsc / g_tscPerSec                     // __aulldiv
  return (f80)quot + (f80)rem / (f80)g_tscPerSec
```

---

## 6. Callers / callees

| Callee | Role |
|---|---|
| `FUN_0076c270` | One-shot QPC/RDTSC calibration → scale + flag |
| `__aulldiv` `0x009a0370` | u64÷u64 |
| `rdtsc` | TSC |

| Caller (sample) | Role |
|---|---|
| `NDResource_AcquireInnerObject` | last-touch float @ `+0x1c` |
| `FUN_007b7000`, `FUN_0066ff20`, `FUN_00670fc0`, … | now/age stamps |
| `FUN_00970bb0` / `00970e50` / `00971480` / `00971ea0` | related clocks |

---

## 7. Gaps / open

1. Product / PDB name.
2. Dual seal of calibrator `aa_0076c270` (OWN of other agent if claimed).
3. Whether any caller expects **milliseconds** (none observed; `fstp float` seconds fits age math).
4. Concurrent first-call races.
5. Runtime / bit-exact open.

**Verdict:** CF + ABI + role sealed. **accept-with-gaps.**
