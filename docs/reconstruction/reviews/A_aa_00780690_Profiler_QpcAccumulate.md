# Review A (reconstruction fidelity): `aa_00780690` Profiler_QpcAccumulate

| Field | Value |
|---|---|
| **Stable ID** | `aa_00780690` |
| **VA** | `0x00780690` |
| **Canonical name** | `FUN_00780690` (Probable: `Profiler_QpcAccumulate`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (QPC delta → timer stats) |
| **Counterpart** | `reviews/B_aa_00780690_Profiler_QpcAccumulate.md` |
| **System** | client instrumentation / profiler internals |
| **Path context** | Leave `0x00786990` @ `0x007869b4` (`ESI = node+4` timer); also `0x00786116` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Stop one sample window on a timer block** held in **`ESI`**:

1. `QueryPerformanceCounter` → now.
2. `delta64 = now - timer->start` (`+0/+4`).
3. `timer->accum64` (`+8/+c`) += delta.
4. `last = __alldiv(delta64, divisor64)` → `timer+0x24`.
5. If `last > max` (`+0x28`) → update max.
6. `count` (`+0x20`) += 1.
7. If count ≠ 0: `avg64 = __alldiv(accum64, count)` → `+0x18/+0x1c`.
8. Return void (does **not** rewrite start QPC; does **not** touch zone hierarchical total — leave does that via second `__alldiv` on accum/div).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00780690_FUN_00780690.md` |
| Annotated | `docs/reconstruction/raw/aa_00780690_FUN_00780690.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00780690.cpp` |
| Function record | `docs/reconstruction/functions/aa_00780690_FUN_00780690.md` |
| Live decompile | Ghidra `batch_decompile` @ `0x00780690` ≡ raw (`unaff_ESI`) |
| Leave asm | `get_assembly_context` @ `0x007869b4` — `MOV ESI,[EDI+4]` then call |
| Alt site | `0x00786116` — same `MOV ESI,[EDI+4]` pattern |
| Divisor init | `FUN_00780730`: QPF / `1000000` → **µs** |
| Leave hierarchical | After return, leave `__alldiv(accum, div)` → `node+0x28 +=` |
| Xrefs | `get_bulk_xrefs` — leave + `0x00786116` |

**Not performed:** `disassemble_bytes`, Launcher, live counter capture. **OWN VA.**

---

## 3. Signature (register ABI)

```c
// No stack formals. Timer sample block* in ESI.
void Profiler_QpcAccumulate(TimerBlock *timer /* ESI */);
```

| Slot | Role | Evidence |
|---|---|---|
| `ESI` / `unaff_ESI` | Timer block (`zone+4`) | Leave: `MOV ESI,[EDI+4]` @ `0x007869ae` |
| Return | void | Fallthrough to leave’s hierarchical add |

---

## 4. Timer layout (sealed with leave dual)

| Offset | Field | Role here |
|---|---|---|
| `+0x00/+0x04` | Start QPC | Subtract from now |
| `+0x08/+0x0c` | Accum ticks | += delta |
| `+0x10/+0x14` | Divisor (ticks/µs) | Denom for last sample |
| `+0x18/+0x1c` | Average (64-bit) | accum / count |
| `+0x20` | Count | ++ |
| `+0x24` | Last scaled (µs) | delta / div |
| `+0x28` | Max scaled (µs) | max(last) |

**Unit:** divisor from ctor = `QueryPerformanceFrequency / 1_000_000` ⇒ scaled fields are **microseconds**.

---

## 5. Control flow (sealed)

```
Profiler_QpcAccumulate(timer /* ESI */):
  now = QueryPerformanceCounter()
  delta = now - timer->startQpc
  timer->accum += delta
  last = delta / timer->divisor          // __alldiv 64/64 → 32
  timer->last = last
  if last > timer->max: timer->max = last
  timer->count += 1
  if timer->count != 0:
    timer->avg = timer->accum / timer->count   // 64-bit result
```

Live decompile ≡ raw. Branches: max update; avg only if count≠0 (always true after ++ unless wrap to 0).

### 5.1 Leave consumer (framing)

```
007869ae  MOV ESI, [EDI+4]
007869b4  CALL FUN_00780690
007869b9  MOV EAX, [EDI+4]
          ; push div hi/lo, accum hi/lo
007869cc  CALL __alldiv
007869d1  ADD [EDI+0x28], EAX    ; hierarchical total on ZONE, not timer max
```

---

## 6. Callers

| Site | Function | Role |
|---|---|---|
| `0x007869b4` | `Profiler_Leave` | Stop current zone timer |
| `0x00786116` | (profiler sibling path) | Same ESI=timer convention |

---

## 7. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| ESI = timer block | **High** | Both call sites |
| Accum += QPC delta | **High** | ADD/ADC |
| last = delta/div; max track | **High** | Body |
| count++; avg = accum/count | **High** | Body |
| Scaled unit µs | **High** | ctor `0x00780730` |
| Does not set zone `+0x28` | **High** | Leave separate |
| Does not refresh start | **High** | No store to [0]/[1] |
| Product name | **Probable** | Behavior |
| Count wrap avg skip | **Tentative** | Theoretical only |
| Full identity of second caller | **Med** | Framed not dualed |

---

## 8. Surviving contract (port)

```
// Client instrumentation. Leave path:
//   ESI = zone->timer; Profiler_QpcAccumulate();
//   zone->hierarchicalTotal += accum / divisor;  // leave body
void Profiler_QpcAccumulate(TimerBlock* t /* ESI */);
```

---

## 9. Open residual

1. Second caller `0x00786116` full dual (OWN was this VA only).
2. Whether start is refreshed elsewhere for multi-sample without leave.
3. Runtime / bit-exact vs QPC.

**Verdict:** **accept-with-gaps** — QPC accumulate ABI + math dual-ready for leave.
