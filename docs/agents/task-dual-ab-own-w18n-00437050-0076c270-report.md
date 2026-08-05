# Dual A/B report — W18-N OWN (`aa_00437050`, `aa_0076c270`)

**Date:** 2026-07-29  
**Scope:** OWN ONLY VAs `0x00437050`, `0x0076c270`. Dual A/B + three-rep refine.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledgers.  
**Ghidra:** `decompile_function` + `force_decompile` + `read_memory` (+ function meta / callees / callers / xrefs). No `disassemble_bytes`.  
**Programs open:** `autoassault.exe` only (dual A/B = fidelity vs adversarial reviews).  
**Image base:** `0x400000`.

---

## Verdicts

| Unit | Canonical name | Verdict |
|------|----------------|---------|
| `aa_00437050` / `0x00437050` | `stoChunkReader_ReadU32` | **accept-with-gaps** |
| `aa_0076c270` / `0x0076c270` | `Timer_CalibrateTscPerSec` | **accept-with-gaps** |

---

## Sealed facts — `0x00437050` ReadU32

1. **ABI:** reader in **EAX**; stack **`uint32_t* out`**; epilogue **`RET 4`**; return **0** / **−1**.
2. **Body:** `0x00437050`–`0x00437095`.
3. **Window remap:** `mov esi,eax; add esi,0x14` → stream window @ **reader+0x14** (same layout as ReadHeader16).
4. **Gate:** if `available < cursor+4` → `FUN_00435df0(window, base+cursor)` thiscall; fail if hr&lt;0 or `available < 4`.
5. **Copy:** one LE dword from `window+0x18+cursor` → `*out`; `cursor += 4`.
6. **Window fields:** `+0x04` cursor, `+0x08` base, `+0x0c` available, `+0x18` buffer (reader `+0x18/+0x1c/+0x20/+0x2c`).
7. **Role:** binary 4-byte peer of text `FUN_007689e0`; dispatcher `FUN_00436900` gates on `reader+0x4044`.
8. **Three-rep:** raw 2026-07-23 ≡ live decompile ≡ force_decompile ≡ body/call-site bytes.

### Gaps

- Product English plate name / U32 vs I32 signedness.
- Full ensure contract (`FUN_00435df0` — not owned).
- Runtime / bit-exact image diff.

---

## Sealed facts — `0x0076c270` CalibrateTscPerSec

1. **ABI:** nullary; plain **`RET`**; void (writes globals only).
2. **Body:** `0x0076c270`–`0x0076c322`.
3. **Samples:** `QueryPerformanceFrequency`, start `QueryPerformanceCounter` + `rdtsc`.
4. **Wait:** spin until QPC ≥ start + **`(freq >> 4)`** (~1/16 second); re-sample rdtsc each iter.
5. **Math:** `scale = (Δtsc * freq) / Δqpc` via `__allmul` (`0x006a3fb0`) / `__aulldiv` (`0x009a0370`).
6. **Globals:** `DAT_00d1a538:53c` = scale u64 (TSC ticks/sec); `DAT_00d1a530` = **u8** ready flag set to 1. Image zeros.
7. **Callers:** lazy only — `FUN_0076c330` @ `0x0076c33c`, `FUN_0076c500` @ `0x0076c52f` (both `cmp byte [d1a530],0`).
8. **Three-rep:** raw 2026-07-23 ≡ live decompile ≡ force_decompile ≡ body/caller bytes.

### Gaps

- Product English plate name.
- Thread-safe first init (no lock).
- Runtime measured scale / wait; bit-exact image diff.

---

## Dual A/B

| VA | Review A | Review B | Verdict |
|---|---|---|---|
| `0x00437050` | `reviews/A_aa_00437050_stoChunkReader_ReadU32.md` | `reviews/B_aa_00437050_stoChunkReader_ReadU32.md` | **accept-with-gaps** |
| `0x0076c270` | `reviews/A_aa_0076c270_Timer_CalibrateTscPerSec.md` | `reviews/B_aa_0076c270_Timer_CalibrateTscPerSec.md` | **accept-with-gaps** |

---

## Files

### `aa_00437050` / `stoChunkReader_ReadU32`

| Kind | Path |
|------|------|
| Review A | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reviews\A_aa_00437050_stoChunkReader_ReadU32.md` |
| Review B | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reviews\B_aa_00437050_stoChunkReader_ReadU32.md` |
| Function record | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\functions\aa_00437050_stoChunkReader_ReadU32.md` |
| Function alias | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\functions\aa_00437050_FUN_00437050.md` |
| Clean named | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reconstructed-exact\stoChunkReader_ReadU32.cpp` |
| Clean FUN_* | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reconstructed-exact\FUN_00437050.cpp` |
| Raw | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\raw\aa_00437050_FUN_00437050.md` |
| Annotated | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\raw\aa_00437050_FUN_00437050.annotated.md` |

### `aa_0076c270` / `Timer_CalibrateTscPerSec`

| Kind | Path |
|------|------|
| Review A | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reviews\A_aa_0076c270_Timer_CalibrateTscPerSec.md` |
| Review B | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reviews\B_aa_0076c270_Timer_CalibrateTscPerSec.md` |
| Function record | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\functions\aa_0076c270_Timer_CalibrateTscPerSec.md` |
| Function alias | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\functions\aa_0076c270_FUN_0076c270.md` |
| Clean named | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reconstructed-exact\Timer_CalibrateTscPerSec.cpp` |
| Clean FUN_* | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reconstructed-exact\FUN_0076c270.cpp` |
| Raw | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\raw\aa_0076c270_FUN_0076c270.md` |
| Annotated | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\raw\aa_0076c270_FUN_0076c270.annotated.md` |

### This report

`C:\Users\josh\Documents\GitHub\AutoCore\docs\agents\task-dual-ab-own-w18n-00437050-0076c270-report.md`

---

## Sibling context (not owned)

| VA | Role |
|---|---|
| `0x00435df0` | stream-window ensure/refill (callee of ReadU32) |
| `0x004368b0` | `stoChunkStreamWindow_ReadHeader16` (16 B sibling) |
| `0x00436900` | mode dispatcher (binary → ReadU32 / text → `FUN_007689e0`) |
| `0x007689e0` | text-mode dword/version peer |
| `0x0076a2c0` | `stoChunkReader_OpenChunk` (binary call site) |
| `0x0076c330` | `Timer_GetTimeSeconds_Rdtsc` (lazy calibrator consumer) |
| `0x0076c500` | timer object init (lazy calibrator consumer) |
| `0x00d1a530` / `538` / `53c` | ready flag + scale u64 globals |

---
