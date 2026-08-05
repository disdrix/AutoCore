# Dual A/B report — W18-G OWN (`aa_0076cf00`, `aa_00720670`)

**Date:** 2026-07-29  
**Scope:** OWN ONLY VAs `0x0076cf00`, `0x00720670`. Dual A/B seal.  
**Agent:** W18-G  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledgers.  
**Ghidra:** `decompile_function` + `read_memory` + function meta / xrefs / callers / callees (no `disassemble_bytes`).  
**Image base:** `0x400000` (`autoassault.exe`).

---

## Verdicts

| Unit | Canonical name | Verdict |
|------|----------------|---------|
| `aa_0076cf00` / `0x0076cf00` | `Profiler_ScopeEnter` | **accept** |
| `aa_00720670` / `0x00720670` | `CSoundManager_RequestPlay` | **accept-with-gaps** |

---

## Sealed facts — `0x0076cf00` Profiler_ScopeEnter

1. **Role:** Profiler **named-scope enter stub** (instrumentation). High fan-in (~120 xrefs).
2. **Body span:** `0x0076cf00` – `0x0076cf05` (6 bytes).
3. **Body bytes:** `8B 41 04 C2 04 00` = `mov eax,[ecx+4]` ; **`ret 4`**.
4. **ABI:** **ECX** = profiler context (`*DAT_00d1f040` at call sites); **stack0** = `const char*` zone name (**unread**); **EAX** = `*(ctx+4)` timer*; **`ret 4`**.
5. **Leave sibling:** `FUN_0076cef0` @ `0x0076cef0` = bare **`ret`** (`c3`).
6. **Layout link:** Zone ctor dual stores timer at **+4** (`Profiler_TimerBlock_Ctor`).
7. **Three-rep:** raw 2026-07-23 ≡ live decompile ≡ body bytes; call-site global+name pattern sealed via `read_memory`.

### Gaps

- Product C++ plate name.
- Full type of `*DAT_00d1f040` beyond timer at +4.
- Runtime / bit-exact.

---

## Sealed facts — `0x00720670` CSoundManager_RequestPlay

1. **Role:** **Thread-safe enqueue** of **0xC8-byte** sound play request onto manager vector.
2. **Body span:** `0x00720670` – `0x0072071a`.
3. **ABI:** **ECX** = `CSoundManager*`; stack **0xC8** by value; **`ret 0xC8`**; void.
4. **Lock:** `Enter/LeaveCriticalSection(this+0x170)` (matches ctor dual).
5. **Request tail:** mode **int @ +0xB8**; compactFlag **u8 @ +0xBC** (entry ESP `+0xBC` / `+0xC0`).
6. **Sticky flags:** mode 1→`+0x13`, 2→`+0x14`, 5→`+0x15` set to 1.
7. **Compact:** `FUN_00720090(this)` only if compactFlag≠0 and mode ∈ {1,2}.
8. **Enqueue always:** `FUN_004804d0(this+0x70, &req)` — 200-byte vector elements.
9. **Xrefs (7):** including NDSpecialFX activate list `FUN_004b6fc0`, `FUN_00720b50`, etc.
10. **Three-rep:** raw ≡ live decompile ≡ epilogue `c2 c8 00` + CS/mode paths.

### Gaps

- Product method English.
- Mode 1/2/5 + sticky-byte English.
- Full play-request POD (path/gain/3D/…).
- Drain path for `+0x70` queue; full duals of compact/vector helpers.
- Runtime / bit-exact.

---

## Dual A/B

| VA | Review A | Review B | Verdict |
|---|---|---|---|
| `0x0076cf00` | `reviews/A_aa_0076cf00_Profiler_ScopeEnter.md` | `reviews/B_aa_0076cf00_Profiler_ScopeEnter.md` | **accept** |
| `0x00720670` | `reviews/A_aa_00720670_CSoundManager_RequestPlay.md` | `reviews/B_aa_00720670_CSoundManager_RequestPlay.md` | **accept-with-gaps** |

---

## Files

### `aa_0076cf00` / `Profiler_ScopeEnter`

| Kind | Path |
|------|------|
| Review A | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reviews\A_aa_0076cf00_Profiler_ScopeEnter.md` |
| Review B | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reviews\B_aa_0076cf00_Profiler_ScopeEnter.md` |
| Function record | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\functions\aa_0076cf00_FUN_0076cf00.md` |
| Named function record | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\functions\aa_0076cf00_Profiler_ScopeEnter.md` |
| Clean named | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reconstructed-exact\Profiler_ScopeEnter.cpp` |
| Clean FUN_* | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reconstructed-exact\FUN_0076cf00.cpp` |
| Raw | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\raw\aa_0076cf00_FUN_0076cf00.md` |
| Annotated | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\raw\aa_0076cf00_FUN_0076cf00.annotated.md` |

### `aa_00720670` / `CSoundManager_RequestPlay`

| Kind | Path |
|------|------|
| Review A | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reviews\A_aa_00720670_CSoundManager_RequestPlay.md` |
| Review B | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reviews\B_aa_00720670_CSoundManager_RequestPlay.md` |
| Function record | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\functions\aa_00720670_FUN_00720670.md` |
| Named function record | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\functions\aa_00720670_CSoundManager_RequestPlay.md` |
| Clean named | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reconstructed-exact\CSoundManager_RequestPlay.cpp` |
| Clean FUN_* | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reconstructed-exact\FUN_00720670.cpp` |
| Raw | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\raw\aa_00720670_FUN_00720670.md` |
| Annotated | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\raw\aa_00720670_FUN_00720670.annotated.md` |

### Report

| Kind | Path |
|------|------|
| This report | `C:\Users\josh\Documents\GitHub\AutoCore\docs\agents\task-dual-ab-w18g-0076cf00-00720670-report.md` |

---

## AutoCore impact

- **`0x0076cf00`:** **No server port** — client profiler stub. Keep ignoring in physics/AI ports (name still appears in decompiles; body is return-timer-only).
- **`0x00720670`:** **No mandatory server port** — client `CSoundManager` play enqueue. If client audio parity ever needed: 0xC8 request, CS `+0x170`, vector `+0x70`, sticky mode flags.
