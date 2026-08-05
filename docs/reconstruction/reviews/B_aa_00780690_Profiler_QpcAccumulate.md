# Review B (skeptical / adversarial): `aa_00780690` Profiler_QpcAccumulate

| Field | Value |
|---|---|
| **Stable ID** | `aa_00780690` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00780690_Profiler_QpcAccumulate.md` |
| **Verdict** | **accept-with-gaps** on CF; reject listed false claims |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | No arguments / pure free void | Decompiler `unaff_ESI`; leave sets **ESI = [node+4]** | **Falsified** “no arg” |
| 2 | ECX/thiscall timer | ESI only; ECX free for leave | **Falsified** |
| 3 | Updates zone hierarchical `node+0x28` | Only timer fields; leave adds hierarchical after return | **Falsified** |
| 4 | last sample uses timer `+0x28` as hierarchical | Timer `+0x28` is **max**; zone `+0x28` is hierarchical on leave | **Falsified** conflation |
| 5 | Divides by raw QPF without scale | Divisor pre-scaled QPF/1e6 in ctor | **Misleading** if claimed “raw ticks out” |
| 6 | Mission timing helper | Stats only; leave is instrumentation pop | **Falsified** |
| 7 | Resets start QPC for next interval | No write to start fields | **Falsified** |
| 8 | Unique to leave | Second xref `0x00786116` same ESI pattern | **Falsified** unique |
| 9 | Scaffold clean without ESI note is safe | Silent wrong object | **Overstated** |
| 10 | Bit-exact / runtime | Static dual | **Fail** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ESI timer ABI | **High** | Corrupt random memory |
| Accum / last / max / count / avg math | **High** | Bad profiler UI numbers |
| µs unit via divisor | **High** | 1000× scale errors |
| Separation from zone hierarchical add | **High** | Double-count or miss totals |
| Start not refreshed | **High** | Misread as multi-sample loop |
| Second caller full CF | **Med** | Other leave-like path |

---

## 3. Cross-check

| Item | Result |
|---|---|
| Raw ≡ live decompile | **Yes** |
| Leave ESI setup | `MOV ESI,[EDI+4]` immediately before call |
| Alt site ESI | `MOV ESI,[EDI+4]` @ `0x00786113` |
| Leave post-call uses accum+div not last | Pushes `+8/+c` and `+10/+14` into `__alldiv` |

**Attack on “leave uses last @+0x24 for hierarchical”:** **Falsified** by leave dual assembly.

---

## 4. Surviving contract for AutoCore

```
// ESI = timer from zone+4
// delta_us = (now - start) / (QPF/1e6)
// accum_ticks += (now - start); last/max/avg updated
// zone hierarchical total is NOT this function
```

**Falsified port mistakes:**

- Calling without ESI timer.
- Writing hierarchical total inside this VA.
- Treating max @ timer+0x28 as zone total.
- Emitting “seconds” without checking divisor scale.

---

## 5. Open questions

1. Full body dual for caller `0x00786116`’s parent function.
2. Signed compare on max (`(int)max < (int)last`) with large µs values.
3. Count overflow to 0 and avg skip.
4. Runtime QPC vs wall-clock correlation.

**Verdict:** **accept-with-gaps** — accumulate math sealed; leave + one sibling consumer.
