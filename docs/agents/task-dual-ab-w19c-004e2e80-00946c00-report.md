# Dual A/B report — W19-C OWN `aa_004e2e80` + `aa_00946c00`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W19-C  
**Scope:** OWN VAs only: `0x004e2e80`, `0x00946c00`.  
**Excluded:** Parent ledgers (`WORK_QUEUE` / `RESUME` / `ACTIVE_WORK` / `CHANGE_LOG` / `COVERAGE_LEDGER`); Launcher.  
**Ghidra:** `decompile_function` + `read_memory` only. No `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict

| Unit | Structural name | Verdict |
|------|-----------------|---------|
| `aa_004e2e80` | `Mem_MoveDwordRange_ReturnEnd` | **accept** — 42 B `__stdcall` `ret 0xC`; dword-floor memmove + return end sealed |
| `aa_00946c00` | `Client_DispatchUiEventQueue` | **accept-with-gaps** — fastcall client queue dispatch CF sealed; product case enum residual |

---

## `aa_004e2e80` — sealed facts

1. **ABI:** `__stdcall` — stack `(srcBegin, srcEnd, dest)`; **`ret 0xC`**. Body `004e2e80`–`004e2eaa` (**42 B**).
2. **Algorithm:** `size = ((srcEnd-srcBegin)>>2)*4`; `memmove(dest,srcBegin,size)`; **return** `dest+size`.
3. **Sole callee:** `memmove` via IAT `0x009c652c`.
4. **Role:** generic POD dword-range relocate helper (30+ vector/list grow callers, incl. sector-map family `FUN_004e39d0`).
5. **Live decompile ≡ 2026-07-23 raw.**

---

## `aa_00946c00` — sealed facts

1. **ABI:** `__fastcall` — **ECX = client\***; void; large SEH/`__chkstk` frame. Body `00946c00`–`009483e6`.
2. **Queue:** `*(client+0xe04)` session; `[+0xe8bc,+0xe8c0)` stride **`0x138`**; type at **`entry+0x1c`** (int; denormal float cases in decompiler).
3. **CF:** non-empty gate → `FUN_007a69d0` → (full switch walk + `FUN_00406840`) **or** (scan type `0x1e` → `FUN_009430f0`).
4. **Sole caller:** `FUN_0094b520` (client tick, after `FUN_00944770`).
5. **Arms:** mission chrome/tips, vehicle park handbrake/longitudinal, sector packets `0x207a`/`0x20bf`, vendor sound, toasts, TFID UI, respawn, etc.
6. **Live decompile ≡ 2026-07-23 raw CF.**

---

## Gaps

### `aa_004e2e80`

1. Product/MSVC STL English name.  
2. Per-caller element-type recovery (not OWN).  
3. Runtime / bit-exact golden.

### `aa_00946c00`

1. Product English: function name + event type enum.  
2. Session/queue field product names (`+0xe04`, `+0xe8bc`).  
3. Per-case duals of unowned UI helpers.  
4. Enqueue path (who fills the queue) — not OWN.  
5. Runtime multi-event golden.

---

## Files

### `aa_004e2e80` `Mem_MoveDwordRange_ReturnEnd`

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_004e2e80_Mem_MoveDwordRange_ReturnEnd.md` |
| Review B | `docs/reconstruction/reviews/B_aa_004e2e80_Mem_MoveDwordRange_ReturnEnd.md` |
| Function record | `docs/reconstruction/functions/aa_004e2e80_Mem_MoveDwordRange_ReturnEnd.md` |
| Scaffold record | `docs/reconstruction/functions/aa_004e2e80_FUN_004e2e80.md` (superseded) |
| Clean | `docs/reconstruction/reconstructed-exact/Mem_MoveDwordRange_ReturnEnd.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_004e2e80.cpp` |
| Raw | `docs/reconstruction/raw/aa_004e2e80_FUN_004e2e80.md` |
| Annotated | `docs/reconstruction/raw/aa_004e2e80_FUN_004e2e80.annotated.md` |

### `aa_00946c00` `Client_DispatchUiEventQueue`

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00946c00_Client_DispatchUiEventQueue.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00946c00_Client_DispatchUiEventQueue.md` |
| Function record | `docs/reconstruction/functions/aa_00946c00_Client_DispatchUiEventQueue.md` |
| Scaffold record | `docs/reconstruction/functions/aa_00946c00_FUN_00946c00.md` (superseded) |
| Clean plate | `docs/reconstruction/reconstructed-exact/Client_DispatchUiEventQueue.cpp` |
| Scaffold clean (full body) | `docs/reconstruction/reconstructed-exact/FUN_00946c00.cpp` |
| Raw | `docs/reconstruction/raw/aa_00946c00_FUN_00946c00.md` |
| Annotated | `docs/reconstruction/raw/aa_00946c00_FUN_00946c00.annotated.md` |

### This report

`docs/agents/task-dual-ab-w19c-004e2e80-00946c00-report.md`

Absolute roots: `C:\Users\josh\Documents\GitHub\AutoCore\` + paths above.

---

## Tools used (both VAs)

- `ghidra-mcp__decompile_function`
- `ghidra-mcp__read_memory`
- `ghidra-mcp__get_function_by_address`
- `ghidra-mcp__get_function_callees` / `get_function_callers` / `get_xrefs_to`
- **Never** `disassemble_bytes`
- **Never** Launcher

---

## AutoCore impact

- **Mem helper:** port as stdcall memmove of dword-floored ranges returning write-end; do not use bare `ret` or raw byte-span size.
- **Client UI queue:** server does not need this dispatcher for wire correctness; useful for client-parity understanding of mission chrome flags, park inputs on UI events, and sector opcodes `0x207a` / `0x20bf` emitted from event types.
