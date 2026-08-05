# Review A (reconstruction fidelity): `aa_0076c270` Timer_CalibrateTscPerSec

| Field | Value |
|---|---|
| **Stable ID** | `aa_0076c270` |
| **VA** | `0x0076c270`–`0x0076c322` |
| **Canonical name** | `Timer_CalibrateTscPerSec` |
| **Prior scaffold** | `FUN_0076c270` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction fidelity — OWN-ONLY W18-N |
| **Counterpart** | `reviews/B_aa_0076c270_Timer_CalibrateTscPerSec.md` |
| **System** | `timer` / util |
| **Verdict** | **accept-with-gaps** — nullary ABI, wait=freq>>4, scale formula, globals sealed; product English + concurrency open |

**Tools:** Ghidra `decompile_function` + `force_decompile` + `read_memory` (body + globals + caller prologues) + function meta / callers / callees / xrefs. No `disassemble_bytes`. Own VA only. No ledgers. No Launcher.

---

## 1. Purpose

**Nullary calibrator leaf:** measure TSC rate against QPC for ~1/16 second, store 64-bit ticks-per-second scale and set ready flag. Consumed by `Timer_GetTimeSeconds_Rdtsc` (`0x0076c330`) and timer-object init (`0x0076c500`).

### Control flow (summary)

1. `QueryPerformanceFrequency(&freq)`
2. `QueryPerformanceCounter(&qpc0)`; `tsc0 = rdtsc()`
3. `target = qpc0 + (freq >> 4)`
4. Loop: sample QPC + rdtsc until `qpc >= target`
5. `scale = (Δtsc * freq) / Δqpc` via `__allmul` / `__aulldiv`
6. `DAT_00d1a538:53c = scale`; `DAT_00d1a530 = 1`

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0076c270_FUN_0076c270.md` (+ v2026-07-29 append) |
| Annotated | `docs/reconstruction/raw/aa_0076c270_FUN_0076c270.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Timer_CalibrateTscPerSec.cpp` |
| Function record | `docs/reconstruction/functions/aa_0076c270_Timer_CalibrateTscPerSec.md` |
| Live decompile | `decompile_function` `0x0076c270` — **≡** raw |
| Force decompile | `force_decompile` `0x0076c270` — **≡** live |
| Live bytes | `read_memory` 180 B @ `0x0076c270` (ends `C3`) |
| Globals | `read_memory` 16 B @ `0x00d1a530` (zeros) |
| Callers | `0x0076c330` lazy gate; `0x0076c500` lazy gate |
| Sibling dual | `A/B_aa_0076c330_Timer_GetTimeSeconds_Rdtsc` |

---

## 3. Sealed residuals

### 3.1 ABI — **SEALED**

| Fact | Evidence |
|---|---|
| Args | none |
| Epilogue | `POP EBX; ADD ESP,0x28; RET` (`C3`) |
| Return | void (EAX/EDX hold scale only transiently before store) |
| Body | `0x0076c270`–`0x0076c322` |

```c
void Timer_CalibrateTscPerSec(void);
```

### 3.2 Wait window — **SEALED**

```
shrd lo, hi, 4 / shr hi, 4   → freq >> 4
target = qpc_start + (freq >> 4)
spin while qpc_now < target (unsigned 64-bit compare)
```

| Fact | Confidence |
|---|---|
| Shift amount 4 → 1/16 of QPF rate | **High** |
| Compare is 64-bit (hi then lo) | **High** |
| rdtsc sampled every spin iteration | **High** |

### 3.3 Scale formula — **SEALED**

```
scale = (Δtsc * freq) / Δqpc   // __allmul then __aulldiv
```

| Fact | Confidence |
|---|---|
| Δtsc = tsc_end − tsc_start (borrow-correct) | **High** |
| Δqpc = qpc_end − qpc_start (borrow-correct) | **High** |
| Result ≈ TSC Hz (ticks per second) | **High** |
| Written to `DAT_00d1a538` (lo) + `DAT_00d1a53c` (hi) | **High** |
| Flag byte `DAT_00d1a530 = 1` | **High** |

### 3.4 Callers — **SEALED** (lazy only)

Both known callers gate on `DAT_00d1a530 == 0` before calling. No other xrefs.

### 3.5 Three-rep — **SEALED**

raw 2026-07-23 ≡ live decompile ≡ force_decompile ≡ body-byte CF.

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF + formula + globals | **High** | three-rep |
| Nullary plain RET | **High** | bytes |
| Scale units = TSC/sec | **High** | used as divisor for seconds |
| Wait ≈ 1/16 s | **High** | freq>>4 |
| Product English | **Probable** | name family with GetTimeSeconds |
| Thread-safe first init | **Open** | no lock |
| Runtime / bit-exact | **Open** | not run |

---

## 5. Gaps / open

1. Product / PDB name.
2. Concurrent first-call races.
3. No re-calibration path observed after flag=1.
4. Runtime measurement of actual wait / scale on live hardware.
5. Bit-exact image diff.

**Verdict:** CF + ABI + scale math + globals sealed. **accept-with-gaps.**
