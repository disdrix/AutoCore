# Dual A/B report — WQ9K-F OWN-ONLY (`0x0078ca80`, `0x007b5be0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **WQ9K-F**  
**Scope:** VAs `0x0078ca80`, `0x007b5be0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers.  
**Ghidra:** `batch_decompile` / `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + RTTI COL. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wq009_depth8_partition_map.md` → **WQ9K-F**.  
**Work item:** WQ-009 depth-8 residual dual seal (UI base/nested complete dtors — CNDUIWndBuffered + CNDUIWindow).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0078ca80` CNDUIWndBuffered_CompleteDtor | **accept-with-gaps** — complete CF/ABI/vtbl/RTTI/nested+0x2A8 free-null/base chain sealed; helper English open |
| `aa_007b5be0` CNDUIWindow_CompleteDtor | **accept-with-gaps** — complete CF/ABI/vtbl/RTTI/owner-debug/free-null/nested CS/base sealed; helper/slot English open |

Path A (fidelity): both **accept-with-gaps**.  
Path B (adversarial): scalar/vector/host-free/cdecl/false-noreturn/wrong-class claims **falsified**; product RTTI sealed for both.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x0078ca80` — sealed facts

1. **Body:** `0x0078ca80`–`0x0078caef` inclusive (**112 B** / `0x70`); next ctor `0x0078caf0`.
2. **ABI:** **`__thiscall`**; ECX = this; SEH `LAB_009b3fee`; bare **`RET`** (`C3`); **void**. Entry `MOV ESI,ECX`.
3. **Semantics:** MSVC **complete destructor** for **CNDUIWndBuffered**:
   - Install vtbl **`PTR_FUN_00a99f74`**.
   - `FUN_007a8580` then `FUN_0078c3d0` (thiscall).
   - If nested `@+0x2A8` (`this[0xAA]`) non-null: call nested `vtbl[0](1)` (scalar-delete owned HostBase).
   - **Always** `*(this+0x2A8) = 0`.
   - Base `FUN_007b5be0(this)` — CNDUIWindow complete.
4. **Classification:** worker (complete dtor body).
5. **Callers (code):** `FUN_00834520` / `CWndVehicle_CompleteDtor` @ `0x0083459c`; scalar `FUN_004293f0`; `FUN_00856380`; EH unwinds.
6. **RTTI:** COL `@0x00a99f70` → `0x00ab8280` → type_info `0x00afe4d0` → **`.?AVCNDUIWndBuffered@@`**.
7. **Name:** `CNDUIWndBuffered_CompleteDtor` (Ghidra `FUN_0078ca80`). Product demangle **sealed** (matches ctor twin vtbl/RTTI).
8. **Decompile ≡ raw CF**; full 112 B hex sealed via `read_memory`.

### Gaps

- Helper `FUN_007a8580` / `FUN_0078c3d0` product English.  
- Nested HostBase product type name at `+0x2A8`.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0078ca80_CNDUIWndBuffered_CompleteDtor.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0078ca80_CNDUIWndBuffered_CompleteDtor.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0078ca80_FUN_0078ca80.md` |
| Annotated | `docs/reconstruction/raw/aa_0078ca80_FUN_0078ca80.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CNDUIWndBuffered_CompleteDtor.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0078ca80.cpp` |
| Function | `docs/reconstruction/functions/aa_0078ca80_FUN_0078ca80.md` |
| Function named | `docs/reconstruction/functions/aa_0078ca80_CNDUIWndBuffered_CompleteDtor.md` |

---

## VA `0x007b5be0` — sealed facts

1. **Body:** `0x007b5be0`–`0x007b5dcc` inclusive (**493 B** / `0x1ED`); `CC` pad then next.
2. **ABI:** **`__thiscall`**; ECX = this; SEH `LAB_009b325c`; bare **`RET`** (`C3`); **void**. Entry `MOV ESI,ECX`.
3. **Semantics:** MSVC **complete destructor** for **CNDUIWindow**:
   - Install vtbl **`PTR_FUN_00a960ac`**.
   - If owner cookie `@+0x2B0`: debug `VOG_DEBUG_STOP` + owner filename warn (`+0x284`).
   - Decrement live window counter `_DAT_00d17954`.
   - If owned child `@+0x2B4` and flag `@+0xBD`: vcall `[+0xC](1)`; null both.
   - Shared helpers `FUN_007a8580` / `FUN_007aec70` / `FUN_007aff00`.
   - Free owned blocks (`+0x28C` via `FUN_00797d70`+delete; `+0x2B8` delete; string slots delete[]; 11× `@+0x45C`).
   - Nested `@+0x1E8`: dual `FUN_00424060` with vtbls `00a964b8`/`00a964ac`; `DeleteCriticalSection(+0x1EC)`.
   - Super-base `FUN_00759de0(this)`.
4. **Classification:** worker (complete dtor body).
5. **Callers (sample):** `FUN_0078ca80` (buffered complete); `FUN_00832fa0` / `CWndWaypointIcon_CompleteDtor`; scalar `FUN_00423e50`; 50+ UI/EH.
6. **RTTI:** COL `@0x00a960a8` → `0x00ab75c8` → type_info `0x00afe1ac` → **`.?AVCNDUIWindow@@`**.
7. **Name:** `CNDUIWindow_CompleteDtor` (Ghidra `FUN_007b5be0`). Product demangle **sealed** (closes prior scaffold `Named_VOG_DEBUG_STOP_007b5be0`).
8. **Decompile ≡ raw CF**; Ghidra false-noreturn on `operator_delete` corrected via full disasm + epilogue bytes.

### Gaps

- Helper / super-base product English (`FUN_007a8580` family, `FUN_00759de0`, nested `00424060`).  
- Slot layout English (string fields / 11-element array).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_007b5be0_CNDUIWindow_CompleteDtor.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_007b5be0_CNDUIWindow_CompleteDtor.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_007b5be0_FUN_007b5be0.md` |
| Annotated | `docs/reconstruction/raw/aa_007b5be0_FUN_007b5be0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CNDUIWindow_CompleteDtor.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_007b5be0.cpp` |
| Function | `docs/reconstruction/functions/aa_007b5be0_FUN_007b5be0.md` |
| Function named | `docs/reconstruction/functions/aa_007b5be0_CNDUIWindow_CompleteDtor.md` |

---

## Chain context (not dualled beyond OWN; evidence only)

```text
CWndVehicle_ScalarDeletingDtor (0x004160d0)                 [WQ9I-F sealed]
  └─ CWndVehicle_CompleteDtor (0x00834520)                  [WQ9J-B sealed]
        ├─ nested notify @ +0x2A8 + FUN_00833d50
        └─ CNDUIWndBuffered_CompleteDtor (0x0078ca80)       [OWN WQ9K-F]
              ├─ nested HostBase scalar @ +0x2A8
              └─ CNDUIWindow_CompleteDtor (0x007b5be0)      [OWN WQ9K-F]
                    └─ FUN_00759de0 super-base               [not OWN]
  Ctor twins: CNDUIWndBuffered 0x0078caf0; CNDUIWindow 0x007b5dd0

CWndWaypointIcon_CompleteDtor (0x00832fa0)                 [WQ9J-B sealed]
  └─ CNDUIWindow_CompleteDtor (0x007b5be0)                  [OWN WQ9K-F] (direct)
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-0078ca80-007b5be0-wq9kf-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0078ca80` | Port as **complete dtor only** for **CNDUIWndBuffered**: install `PTR_FUN_00a99f74`; helpers; scalar-delete nested `@+0x2A8`; always null field; base `FUN_007b5be0`. **Do not** free host. Pair with scalar `0x004293f0`. |
| `007b5be0` | Port as **complete dtor only** for **CNDUIWindow**: install `PTR_FUN_00a960ac`; owner-debug; live-count--; free owned slots + nested CS; super-base `FUN_00759de0`. **Do not** free host. Pair with scalar `0x00423e50`. |
| Pair with | CWndVehicle / CWndWaypointIcon complete (WQ9J-B); ctors W34-T / `007b5dd0`; super-base residual `00759de0`. |
| Naming | Product RTTI seals both names. Parent may retire scaffold `Named_VOG_DEBUG_STOP_007b5be0`. |

---

## Parent merge handoff (not done here)

Per partition map, parent should lockstep for both VAs:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history (`CNDUIWndBuffered_CompleteDtor`, `CNDUIWindow_CompleteDtor`; optional scaffold alias retire)  
- systems note (UI windows — not skill domain)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN pair).

---

## Process

- OWN VAs only (`0x0078ca80`, `0x007b5be0`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + disassemble_function + read_memory + xrefs + RTTI COL. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- Clean sources use product RTTI names.  
- Odd behavior preserved: always-null `+0x2A8`; owner-debug side-path; false-noreturn on `operator_delete`; live-count decrement.  
- Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
