# Dual A/B report — W21-O OWN-ONLY (`0x0074c9c0`, `0x0044e100`)

**Date:** 2026-07-29  
**Agent:** W21-O OWN-ONLY  
**Scope:** OWN ONLY VAs `0x0074c9c0`, `0x0044e100`. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory.  
**Ghidra:** `decompile_function` + `read_memory` only. No `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict per VA

| Unit | Verdict |
|------|---------|
| `aa_0074c9c0` Bounds_AccumulateTransformedLocal | **accept-with-gaps** — **ECX dest + ret12, gate, sphere merge×0.5, 8-corner AABB sealed; product English / matrix helper dual open** |
| `aa_0044e100` RbTree_AllocEmptyNode_0x30 | **accept** — **0x30 new, link zeros, flags +0x2c/+0x2d, EAX return, factory-only role sealed** |

---

## `aa_0074c9c0` — Bounds_AccumulateTransformedLocal

### Sealed facts

1. **ABI:** dest bounds in **ECX**; stack `xformRef`, `local`, `scaleSrc`; epilogue **`ret 12`**. Body `0x0074c9c0`–`0x0074ce55`.

2. **Early-out:** if `local[+0x2c] != 0`, no work.

3. **Pipeline:** `FUN_0044b5c0` → matrix; `FUN_0076f6e0` project center; scale radius via object `+0x9c..+0xa4` and flag `+0xb8`; merge sphere into dest; 8-corner AABB expand; `dest[+0x2c]=0`; `dest[+0x10]` XZ extent.

4. **Constant:** `DAT_00a0f298` = **0.5f** (sphere mid-factor).

5. **BoundsVolume map:** center `+0`, radius `+0xc`, xzExtent `+0x10`, aabbMin `+0x14`, aabbMax `+0x20`, gate `+0x2c`.

6. **Name:** structural `Bounds_AccumulateTransformedLocal`. Parent-seed TeleportIn-only name **misleading** (multi-caller mesh + events).

### Gaps

1. Product/PDB symbol.  
2. Full dual of `FUN_0044b5c0`.  
3. `DAT_00d1eb60` English.  
4. Bit-exact AABB float-select micro-order.  
5. Runtime / bit-exact / differential — open.

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_0074c9c0_Bounds_AccumulateTransformedLocal.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0074c9c0_Bounds_AccumulateTransformedLocal.md` |
| Function record | `docs/reconstruction/functions/aa_0074c9c0_Bounds_AccumulateTransformedLocal.md` |
| Scaffold record | `docs/reconstruction/functions/aa_0074c9c0_FUN_0074c9c0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Bounds_AccumulateTransformedLocal.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_0074c9c0.cpp` |
| Raw | `docs/reconstruction/raw/aa_0074c9c0_FUN_0074c9c0.md` |
| Annotated | `docs/reconstruction/raw/aa_0074c9c0_FUN_0074c9c0.annotated.md` |

---

## `aa_0044e100` — RbTree_AllocEmptyNode_0x30

### Sealed facts

1. **Body:** `0x0044e100`–`0x0044e136`; bare **`ret`**.

2. **CF:** `operator_new(0x30)`; zero `+0/+4/+8`; `+0x2c=1`, `+0x2d=0`; return pointer in **EAX** (decomp `void` is surface).

3. **Role:** empty RB-tree **node seed** only — **no** self-links / size / value ctor. Header callers (e.g. Profiler_Zone_Ctor) set `+0x2d=1` and self-link.

4. **Sibling:** `aa_00439770` same CF at size **0x18** (flags at `+0x14/+0x15`).

5. **Name:** structural `RbTree_AllocEmptyNode_0x30`. InitInstance parent-seed **incomplete**.

### Gaps

1. Product/PDB / value_type for 0x30 payload.  
2. Exhaustive map-family census (0x18 vs 0x30).  
3. OOM null-new path.  
4. Runtime / bit-exact / differential — open.

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_0044e100_RbTree_AllocEmptyNode_0x30.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0044e100_RbTree_AllocEmptyNode_0x30.md` |
| Function record | `docs/reconstruction/functions/aa_0044e100_RbTree_AllocEmptyNode_0x30.md` |
| Scaffold record | `docs/reconstruction/functions/aa_0044e100_FUN_0044e100.md` |
| Clean | `docs/reconstruction/reconstructed-exact/RbTree_AllocEmptyNode_0x30.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_0044e100.cpp` |
| Raw | `docs/reconstruction/raw/aa_0044e100_FUN_0044e100.md` |
| Annotated | `docs/reconstruction/raw/aa_0044e100_FUN_0044e100.annotated.md` |

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`

---

## AutoCore impact

### Bounds accumulate (`0x0074c9c0`)

- Port as **transform + scale + merge**, not a simple AABB copy.
- Keep **ECX dest** calling convention when matching client call sites.
- Honor **gate +0x2c** no-op and **0.5f** sphere merge; do not invent TeleportIn-only behavior.
- Dest layout `center/radius/aabb/gate/xzExtent` must stay consistent for mesh attach / special-event paths.

### RB node factory (`0x0044e100`)

- Treat as **seed factory** only — pair with caller self-link + `isnil=1` + size 0.
- Distinct from `0x00439770` (0x18) by **size and flag offsets** only.
- Do not invent value construction or map insert inside this VA.
