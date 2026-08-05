# Review B (skeptical / adversarial): `aa_0076c270` Timer_CalibrateTscPerSec

| Field | Value |
|---|---|
| **Stable ID** | `aa_0076c270` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0076c270_Timer_CalibrateTscPerSec.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `force_decompile` + `read_memory` (body + globals + caller prologues). No `disassemble_bytes`. Own VA `0x0076c270` only.

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Returns scale in EAX/EDX to caller | Stores to globals then plain RET; callers re-load globals | **Falsified** as return-value API — **global side effects** |
| 2 | Fixed busy-loop iteration count | Wait is QPC threshold `start+(freq>>4)` | **Falsified** — **time-based ~1/16 s** |
| 3 | Uses `Sleep` / `SleepEx` | Only QPC + rdtsc in spin | **Falsified** — busy wait |
| 4 | Scale is QPC frequency | Formula multiplies Δtsc by QPF then divides by Δqpc | **Falsified** — **TSC Hz**, not QPF |
| 5 | Scale is TSC / QPC ratio only (no *freq) | `__allmul(Δtsc, freq)` before div | **Falsified omission** — includes `* freq` |
| 6 | Ready flag is dword | `C6 05 … 01` byte store | **Falsified** — **u8** at `DAT_00d1a530` |
| 7 | Multiple calibration sites always re-run | Both callers `cmp byte [d1a530],0` | **Falsified always** — **lazy once** |
| 8 | Has stack args / thiscall | `sub esp,28` locals only; plain RET | **Falsified** — **nullary** |
| 9 | Three-rep diverges | live ≡ force ≡ raw ≡ key bytes | **Falsified** |
| 10 | Writes only lo dword of scale | `mov [d1a538],eax` + `mov [d1a53c],edx` | **Falsified** — **full u64** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Nullary void + global outputs | **High** | Wrong timer init port |
| Wait = freq>>4 QPC ticks | **High** | Too short/long calibrate |
| scale = (Δtsc*freq)/Δqpc | **High** | Seconds off by huge factor |
| Flag u8 @ d1a530; scale u64 @ d1a538 | **High** | Lazy init never fires / wrong width |
| Only 2 callers, both lazy | **High** | Missed re-cal path (none in xrefs) |
| Product English | **Probable** | Doc-only |
| Thread safety | **Open** | Double calibrate race |
| Runtime / bit-exact | **Open** | Live timing noise |

---

## 3. Cross-check against raw + bytes

```
raw / live / force:
  QPF; QPC0; rdtsc0
  target = qpc0 + (freq>>4)
  do { QPC1; rdtsc1 } while qpc1 < target
  scale = (Δtsc * freq) / Δqpc
  store scale lo/hi; flag=1

bytes:
  FF15 …61 9C 00   QPF IAT
  FF15 …61 9C 00   QPC IAT (×2: start + spin)
  0F31             rdtsc (start + spin)
  0FACF504 C1EE04  shrd/shr 4
  E8… __allmul / __aulldiv
  A338A5D100  89153CA5D100  C60530A5D10001
  5B 83C428 C3

callers:
  cmp byte [d1a530],0 / jnz / call 76c270
```

**No conflict** on owned CF. Hardware timing variance not sealed.

---

## 4. Surviving contract for AutoCore

```csharp
// Timer_CalibrateTscPerSec @ 0x0076c270
// nullary; writes g_tscPerSec (u64) + g_tscScaleReady (byte)

void CalibrateTscPerSec()
{
    QueryPerformanceFrequency(out long freq);
    QueryPerformanceCounter(out long q0);
    ulong t0 = Rdtsc();
    long target = q0 + (freq >> 4);
    long q1;
    ulong t1;
    do {
        QueryPerformanceCounter(out q1);
        t1 = Rdtsc();
    } while (q1 < target);
    ulong scale = (t1 - t0) * (ulong)freq / (ulong)(q1 - q0);
    g_tscPerSec = scale;       // DAT_00d1a538:53c
    g_tscScaleReady = 1;       // DAT_00d1a530
}
```

---

## 5. Gaps that survive attack

1. Product English name.
2. Concurrent first-call races.
3. No live measured scale / wait duration.
4. Bit-exact open.

**Verdict:** adversarial pass does not overturn A. **accept-with-gaps.**
