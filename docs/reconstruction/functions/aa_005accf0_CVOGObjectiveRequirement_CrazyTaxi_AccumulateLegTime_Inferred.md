# Function record: CVOGObjectiveRequirement_CrazyTaxi_AccumulateLegTime_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005accf0` |
| **Canonical name** | `CVOGObjectiveRequirement_CrazyTaxi_AccumulateLegTime_Inferred` |
| **Ghidra name** | `FUN_005accf0` |
| **Address** | `0x005accf0` |
| **Body range** | `0x005accf0`–`0x005acee7` exclusive (**503** B / `0x1F7`); Ghidra plate max `005acee6`; pad `CC` → `0x005acef0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `CVOGObjectiveRequirement_CrazyTaxi` time-budget leg accumulation |
| **Completion status** | **Sealed** — dual A/B **accept-with-gaps** (W30-M 2026-07-29) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_005accf0_CVOGObjectiveRequirement_CrazyTaxi_AccumulateLegTime_Inferred.md`, `reviews/B_aa_005accf0_CVOGObjectiveRequirement_CrazyTaxi_AccumulateLegTime_Inferred.md` |
| **Last reviewed** | `2026-07-29` |

## Alias

- `FUN_005accf0`
- RTTI type family: `.?AVCVOGObjectiveRequirement_CrazyTaxi@@`

## Purpose

Accumulate a CrazyTaxi **leg time budget**: Euclidean distance between source pose and destination stop (TFID at `this+0x4c`), divide by continent/map scale float, multiply by TimeLimit **Percent** from Val12 map at `this+0x8c` (keyed by stop count), add into running float; if `stopsKey < 1` also add **5.0f** (`DAT_00aaa688`).

## Signature

```c
float __thiscall AccumulateLegTime( // x87 float10 in decomp
    CVOGObjectiveRequirement_CrazyTaxi* this,  // ECX
    Actor* actor,       // stack+4  — scale + optional GetPos
    int stopsKey,       // stack+8  — TimeLimit map key
    float acc,          // stack+0xC — running total
    int fromIndex,      // stack+0x10 — <0 → actor pos; else TFID index
    int toIndex);       // stack+0x14 — dest TFID index
// RET 0x14
```

## Algorithm

1. Load map **scale** float via `actor+0x250` → … → `+0x634`.
2. Source pose: if `fromIndex < 0` vcall actor GetPos (`vtbl+0x1a0`); else resolve TFID `this+0x4c[fromIndex]` via `FUN_004bb1c0` and read pos `@ dual+0x84`.
3. Dest: resolve `this+0x4c[toIndex]`; if null, skip distance block.
4. Δpos → `SQRT`; Val12 lower-bound walk on TimeLimit map (`this+0x8c`, isnil@+0x19, key@+0x0C); if result ≠ begin, `StdTree_Dec_Val12`; if result == head then `dist/scale` else `(dist/scale)*Percent@+0x14`.
5. `acc += dist'`; if `stopsKey < 1` then `acc += 5.0f`; return `acc`.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005accf0_FUN_005accf0.md`
- Annotated: `docs/reconstruction/raw/aa_005accf0_FUN_005accf0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGObjectiveRequirement_CrazyTaxi_AccumulateLegTime_Inferred.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_005accf0.cpp`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-005aed20-005accf0-w30m-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | `FUN_004bb1c0` (Object_ResolveFromTFID family, W18-T); `FUN_005ae050` StdTree_Dec_Val12; `SQRT`; actor vtbl `+0x1a0` |
| **Callers** | **None static** — full-image E8 + absolute pointer scan found zero refs (dead or dynamic-only) |

## Confidence

| Claim | Level |
|---|---|
| Control flow + live ≡ raw | **High** |
| `ret 0x14` + thiscall | **High** (bytes) |
| CrazyTaxi layout +0x4c / +0x8c | **High** (ctor + XML dump) |
| Scale / Percent multiply | **High** |
| Product English name | **Inferred** |
| Bracket (floor vs exact) product intent | **Tentative** |
| Static callers | **None found** |
| Runtime / differential | Open |

## Related

- TimeLimit map insert: `aa_005aed20` (this dual)
- Val12 Dec: `aa_005ae050` (W29-E)
- TFID resolve: `aa_004bb1c0` / W18-T
- CrazyTaxi ctor: `FUN_005adb20`; XML dump: `FUN_005acf10`
