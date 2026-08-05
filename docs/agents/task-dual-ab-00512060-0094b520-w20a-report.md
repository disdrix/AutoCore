# Dual A/B report — W20-A OWN-ONLY (`0x00512060`, `0x0094b520`)

**Date:** 2026-07-29  
**Agent:** W20-A OWN-ONLY  
**Scope:** OWN ONLY VAs `0x00512060`, `0x0094b520`. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory.  
**Ghidra:** `decompile_function` + `read_memory` only. No `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict per VA

| Unit | Verdict |
|------|---------|
| `aa_00512060` CVOGHB_TargetingLink_complete_dtor_Inferred | **accept** — **11-byte complete dtor sealed: vtbl `009cdfb0` + tail jmp base `FUN_00508390`; not scalar** |
| `aa_0094b520` Client_AppFrameTick | **accept-with-gaps** — **ECX client frame body of sole pump caller; gates + ordered fan-out sealed; product flag/callee English open** |

---

## `aa_00512060` — CVOGHB_TargetingLink_complete_dtor_Inferred

### Sealed facts

1. **Body:** `0x00512060`–`0x0051206a` (11 B). Exclusive end `0x0051206b`. Following `cc` is pad.

2. **Bytes:** `c7 01 b0 df 9c 00 e9 25 63 ff ff`  
   - `mov dword ptr [ecx], 0x009cdfb0`  
   - **tail `jmp`** `FUN_00508390` @ `0x00508390` (rel from next-IP `0x0051206b`).

3. **Decompile ≡ raw:** write family vtbl then `FUN_00508390()` (call form; machine is tail).

4. **ABI:** `__thiscall`/`__fastcall` shape — **ECX = this**. No stack cleanup in this body.

5. **Base path (context):** `FUN_00508390` sets vtbl `009cdab0` and may `FUN_005085b0` detach when owner link present.

6. **Callers:**  
   - Scalar deleting `FUN_00512070` CALL @ `0x00512073`  
   - `thunk_FUN_00512060` @ `0x0051b890` JMP  

7. **Name:** structural `CVOGHB_TargetingLink_complete_dtor_Inferred` (family from ctor dual; RTTI/product open → `_Inferred`). **Not** the scalar wrapper.

### Gaps

1. Product/PDB mangled symbol.  
2. Runtime / bit-exact / differential — open.

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00512060_CVOGHB_TargetingLink_complete_dtor_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00512060_CVOGHB_TargetingLink_complete_dtor_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_00512060_CVOGHB_TargetingLink_complete_dtor_Inferred.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHB_TargetingLink_complete_dtor_Inferred.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_00512060.cpp` |
| Raw | `docs/reconstruction/raw/aa_00512060_FUN_00512060.md` |
| Annotated | `docs/reconstruction/raw/aa_00512060_FUN_00512060.annotated.md` |

---

## `aa_0094b520` — Client_AppFrameTick

### Sealed facts

1. **Body:** `0x0094b520`–`0x0094b9b5` (exclusive end `0x0094b9b6`). Large SEH + chkstk frame (`mov eax,0x186a4` / `add esp,0x186b0`).

2. **ABI:** `__fastcall`/`__thiscall` — **ECX = client\*** (`mov edi,ecx`); bare `ret`; **always returns 1**.

3. **Sole caller:** `FUN_0094b9c0` @ `0x0094b9e4` — Win32 `PeekMessage` pump loop calls this each iteration.

4. **Outer gates (ordered):**  
   - `client+0x13` master enable  
   - timer nest A on `DAT_00d09874+0x25` / QPC `+0x170`  
   - `client+0xf40 != 0`  
   - timer nest B `+0x27` / QPC `+0x180`  
   - `FUN_0093a5c0(0)` focus/UI poll — **non-zero skips frame body**

5. **Inner flags:** `+0xa1` suppresses several paths; `+0xb7` enables sim/focus cluster (includes `CVOGHBList_Tick(client+0xd38,0)`); session root `+0xe04` for load-queue / session ticks.

6. **Named sealed callees in body:** FocusGate `0x0093a5c0`, `CVOGHBList_Tick`, `Client_DispatchUiEventQueue` `0x00946c00` (after `FUN_00944770`).

7. **Strings:** `..\logs\frametime.txt` @ `0x00a2cfc0`; `LoadQueue test, focus = %d` @ `0x00a2cfdc` — diagnostic / test arms, **not** whole-function name evidence.

8. **Name:** structural `Client_AppFrameTick`. Reject auto `Named_frametime_txt` as primary.

### Gaps

1. Product/PDB name; English for client flag fields.  
2. Full product map of nested still-FUN callees.  
3. Profile bucket ID English; exact product meaning of imm `0x3b888889`.  
4. Runtime / bit-exact / differential — open.

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_0094b520_Client_AppFrameTick.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0094b520_Client_AppFrameTick.md` |
| Function record | `docs/reconstruction/functions/aa_0094b520_Client_AppFrameTick.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_AppFrameTick.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_0094b520.cpp` |
| Raw | `docs/reconstruction/raw/aa_0094b520_FUN_0094b520.md` |
| Annotated | `docs/reconstruction/raw/aa_0094b520_FUN_0094b520.annotated.md` |

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`

---

## AutoCore impact

### Complete dtor (`0x00512060`)

- Port as **complete dtor only**: restore family vtbl `009cdfb0`, then base detach path (`FUN_00508390` → possible list unlink).
- Do **not** put `operator_delete` or `flags&1` here — that is scalar `0x00512070`.
- Derived PlayerTargetingLink scalar shares this body via thunk `0x0051b890`.

### App frame tick (`0x0094b520`)

- Client-only main-loop **frame body** under message pump; not a server sector tick.
- Preserve gate nesting: master → `+0xf40` → focus poll(0) → ordered subsystems.
- Do not treat frametime file I/O or LoadQueue log as mandatory every frame.
- Wire HB list via `client+0xd38` with forced delta **0**; UI events via `Client_DispatchUiEventQueue` after `FUN_00944770`.
