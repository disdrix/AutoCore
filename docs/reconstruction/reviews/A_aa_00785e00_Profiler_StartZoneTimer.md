# Review A (reconstruction fidelity): `aa_00785e00` Profiler_StartZoneTimer

| Field | Value |
|---|---|
| **Stable ID** | `aa_00785e00` |
| **VA** | `0x00785e00` |
| **Canonical name** | `FUN_00785e00` (Probable: `Profiler_StartZoneTimer`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (QPC start stamp / sample reset) |
| **Counterpart** | `reviews/B_aa_00785e00_Profiler_StartZoneTimer.md` |
| **System** | client instrumentation / profiler internals |
| **Path context** | Sole enter caller @ `0x00786a33` after FindOrCreate; create-thread path **inlines** same ops |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Start (or re-start) timing on a zone node** passed in **`EAX`**:

1. `zone->nestCount` at **`+0x3c`** += 1.
2. `timer = *(zone + 4)`.
3. Zero sample fields on timer: accum lo/hi, count, avg lo/hi, last, max (**does not** clear divisor at `+0x10/+0x14`).
4. `QueryPerformanceCounter` → timer start lo/hi at `+0/+4`.
5. Return void.

Paired stop/accumulate is `FUN_00780690` (ESI = timer) on leave — **not** owned here.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00785e00_FUN_00785e00.md` |
| Annotated | `docs/reconstruction/raw/aa_00785e00_FUN_00785e00.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00785e00.cpp` |
| Function record | `docs/reconstruction/functions/aa_00785e00_FUN_00785e00.md` |
| Live decompile | Ghidra `batch_decompile` @ `0x00785e00` ≡ raw (`in_EAX`) |
| Caller asm | `get_assembly_context` @ `0x00786a33` — `EAX` still zone from FindOrCreate |
| Twin logic | Inline duplicate in `FUN_007866e0` create path |
| Divisor init (framing) | `FUN_00780730` — `QueryPerformanceFrequency` then `/ 1000000` → **µs** scale |
| Xrefs | `get_bulk_xrefs` — only `0x00786a33` |

**Not performed:** `disassemble_bytes`, Launcher, live QPC. **OWN VA.**

---

## 3. Signature (register ABI)

```c
// No stack formals. Zone node in EAX on entry (MSVC register passthrough).
void Profiler_StartZoneTimer(Zone *zone /* EAX */);
```

| Slot | Role | Evidence |
|---|---|---|
| `EAX` / `in_EAX` | Zone node* | Enter: `MOV EDI,EAX` after find; `CALL 0x00785e00` with EAX unchanged until call |
| Return | void | Fallthrough to re-ensure slot |

Decompiler `void FUN_00785e00(void)` is correct only with **EAX** documented.

---

## 4. Layout (zone + timer)

### 4.1 Zone node

| Offset | Field | Evidence |
|---|---|---|
| `+0x04` | Timer sample block* | `pDVar1 = *(EAX+4)` |
| `+0x3c` | Nest / enter counter | `*(EAX+0x3c) += 1` |

### 4.2 Timer block (DWORD indices from decompile)

| Offset | Field | Start path |
|---|---|---|
| `+0x00/+0x04` | Start QPC lo/hi | **Written** from QPC |
| `+0x08/+0x0c` | Accum ticks lo/hi | **Zeroed** |
| `+0x10/+0x14` | Divisor (ticks/µs) | **Preserved** |
| `+0x18/+0x1c` | Running average | **Zeroed** |
| `+0x20` | Sample count | **Zeroed** |
| `+0x24` | Last scaled sample | **Zeroed** |
| `+0x28` | Max scaled sample | **Zeroed** |

Divisor origin (timer ctor `FUN_00780730`, framing):  
`QueryPerformanceFrequency` → `__alldiv(freq, 1000000)` → store; scaled samples are **microseconds**.

---

## 5. Control flow (sealed)

```
Profiler_StartZoneTimer(zone /* EAX */):
  *(int*)(zone + 0x3c) += 1
  t = *(Timer**)(zone + 4)
  t->accum = 0
  t->count = 0
  t->avg = 0
  t->last = 0
  t->max = 0
  // divisor untouched
  QueryPerformanceCounter(&t->start)
```

Live decompile ≡ raw. No branches.

---

## 6. Callers

| Site | Function | Role |
|---|---|---|
| `0x00786a33` | `Profiler_EnterNamedZone` | After FindOrCreate; `EAX` = zone |

Thread-slot create path inlines the same field ops (not a call).

---

## 7. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| EAX = zone | **High** | Enter asm |
| Nest `+0x3c`++ | **High** | First store |
| Timer via `+4` | **High** | Leave also uses `node+4` |
| Zeros listed fields; keeps divisor | **High** | Explicit stores; no write to [4]/[5] |
| QPC start stamp | **High** | API call |
| Scaled unit µs | **High** (via ctor) | `1000000` denom in `0x00780730` |
| Product name | **Probable** | Behavior |
| Nest meaning (depth vs enter count) | **Tentative** | Only ++ here; no -- in leave dual |

---

## 8. Surviving contract (port)

```
// Client instrumentation. On enter after find-or-create:
void Profiler_StartZoneTimer(Zone* z /* EAX */);
// Resets per-scope sample accumulators; stamps QPC; keeps frequency divisor.
```

---

## 9. Open residual

1. Who decrements nest `+0x3c` (if anyone).
2. Re-enter same zone without leave: zeros accum (exclusive time restarts).
3. Runtime / bit-exact.

**Verdict:** **accept-with-gaps** — start-timer ABI and field list dual-ready.
