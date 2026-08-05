# Review A (reconstruction fidelity): `aa_00780730` Profiler_TimerBlock_Ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00780730` |
| **VA** | `0x00780730` |
| **Canonical name** | `FUN_00780730` (Probable: `Profiler_TimerBlock_Ctor`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (QPF → µs divisor init) |
| **Counterpart** | `reviews/B_aa_00780730_Profiler_TimerBlock_Ctor.md` |
| **System** | client instrumentation / profiler internals |
| **Path context** | Sole caller zone ctor `FUN_00786280` @ `0x00786313` (`ESI = new(0x30)`) |
| **Verdict** | **accept** |

---

## 1. Purpose

**Construct a timer sample block** pre-allocated at **0x30** bytes, held in **`ESI`**:

1. Zero start QPC (`+0/+4`), accum (`+8/+c`), avg (`+0x18/+0x1c`), count (`+0x20`), last (`+0x24`), max (`+0x28`).
2. `QueryPerformanceFrequency` → temporary store at **`+0x10/+0x14`**.
3. `__alldiv(freq64, 1_000_000)` → replace `+0x10/+0x14` with **ticks per microsecond**.
4. Return **this** in **EAX** (`mov eax, esi`).

Consumers (not owned): start path preserves divisor and zeroes sample fields; accumulate divides deltas by divisor → **µs**.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00780730_FUN_00780730.md` (+ 2026-07-29 refresh) |
| Annotated | `docs/reconstruction/raw/aa_00780730_FUN_00780730.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00780730.cpp` |
| Named clean | `docs/reconstruction/reconstructed-exact/Profiler_TimerBlock_Ctor.cpp` |
| Function record | `docs/reconstruction/functions/aa_00780730_FUN_00780730.md` |
| Live decompile | Ghidra `decompile_function` @ `0x00780730` ≡ raw (`unaff_ESI`) |
| Body bytes | `read_memory` 68 B — `push 0x000F4240` (=1000000); `mov eax,esi; ret` |
| Caller | `FUN_00786280` @ `0x00786313` — `mov esi,eax` after `new(0x30)` |
| Sibling layout | QpcAccumulate `0x00780690`, StartZoneTimer `0x00785e00` duals |
| Xrefs | `get_xrefs_to` — **1** site |

**Not performed:** `disassemble_bytes`, Launcher, live QPF capture. **OWN VA.**

---

## 3. Signature (register ABI)

```c
// No stack formals. Timer block* in ESI. Returns this in EAX.
TimerBlock *Profiler_TimerBlock_Ctor(TimerBlock *self /* ESI */);
```

| Slot | Role | Evidence |
|---|---|---|
| `ESI` / `unaff_ESI` | Timer block* | Body stores via `[esi+…]`; caller `mov esi,eax` |
| Return `EAX` | Same pointer | `8b c6` = `mov eax,esi` before `ret` |
| Stack | none | `c3` not `ret N` |

Decompiler `void FUN_00780730(void)` is incomplete without ESI/EAX documentation (return type lost).

---

## 4. Layout (timer block 0x30)

| Offset | Field | Ctor |
|---|---|---|
| `+0x00/+0x04` | Start QPC | zero |
| `+0x08/+0x0c` | Accum ticks | zero |
| `+0x10/+0x14` | Divisor ticks/µs | **QPF/1e6** |
| `+0x18/+0x1c` | Average | zero |
| `+0x20` | Count | zero |
| `+0x24` | Last scaled µs | zero |
| `+0x28` | Max scaled µs | zero |

**Constant seal:** body `68 40 42 0f 00` = `push 0x000F4240` = **1_000_000**.

---

## 5. Control flow (sealed)

```
Profiler_TimerBlock_Ctor(timer /* ESI */):
  zero start, accum, avg, count, last, max
  QueryPerformanceFrequency(timer + 0x10)
  timer->divisor = __alldiv(QPF, 1_000_000)
  return timer  // EAX
```

Linear; no branches. Live decompile ≡ original raw.

---

## 6. Callers

| Site | Function | Role |
|---|---|---|
| `0x00786313` | `FUN_00786280` Zone ctor | Only xref; stores result at `zone+4` |

---

## 7. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| ESI this + EAX return | **High** | Body + sole caller |
| Divisor = QPF/1e6 | **High** | Imm `0xF4240` |
| Field zero set matches accumulate layout | **High** | Sibling duals |
| Scaled unit µs | **High** | Divisor definition |
| Alloc size 0x30 | **High** | Caller `operator_new(0x30)` |
| Product name | **Probable** | Behavior, not plate string |
| Runtime QPF value | **N/A** | Host-dependent |

---

## 8. Surviving contract (port)

```
// Client profiler timer block:
//   divisor = QueryPerformanceFrequency() / 1_000_000; // ticks per µs
//   sample fields start at 0; start QPC filled by StartZoneTimer
TimerBlock* Profiler_TimerBlock_Ctor(TimerBlock* self /* ESI */);
```

---

## 9. Open residual

1. Exact C++ class/member name in original source tree.
2. Whether `+0x2c` pad dword is ever used (alloc 0x30; body touches through +0x28 only).
3. Runtime / image bit-diff.

**Verdict:** **accept** — ABI, divisor math, and layout sealed for port framing.
