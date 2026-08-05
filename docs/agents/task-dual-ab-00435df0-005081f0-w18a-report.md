# Dual A/B report — W18-A OWN-ONLY (`0x00435df0`, `0x005081f0`)

**Date:** 2026-07-29  
**Agent:** W18-A OWN-ONLY  
**Scope:** OWN ONLY VAs `0x00435df0`, `0x005081f0`. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory.  
**Ghidra:** `decompile_function` + `read_memory` only. No `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict per VA

| Unit | Verdict |
|------|---------|
| `aa_00435df0` stoChunkStreamWindow_Ensure | **accept-with-gaps** — **thiscall+ret4, three-arm slide/full ensure, window map, memmove+Seek/Read sealed; product English open** |
| `aa_005081f0` CVOGHBBase_EmptyVFunc | **accept** — **1-byte `c3` nop leaf sealed; base vtbl+0x14 default + multi-caller nop** |

---

## `aa_00435df0` — stoChunkStreamWindow_Ensure

### Sealed facts

1. **ABI:** `int32_t __thiscall Ensure(StoStreamWindow* this, int32_t absPos)` — **ECX=window**, stack arg absPos, epilogue **`ret 4`**. Body `0x00435df0`–`0x00435f24`.

2. **Return:** decompiler shows `void`; callers (ReadHeader16, bulk read, typed readers) treat **EAX signed** — last source **Read** (`*pSource.vtbl+0x14`) status.

3. **Window layout:** `+0 pSource*`, `+4 cursor→0`, `+8 base→absPos`, `+c available`, `+10 capacity`, `+14 streamEnd` (name Probable), `+18 buffer`.

4. **Three arms:**  
   - **A** `base <= abs < base+avail`: memmove keep-suffix; Seek(abs+keep); Read tail.  
   - **B** backward within capacity: memmove shift; Seek(abs); Read front gap.  
   - **C** full: Seek(abs); Read full available.

5. **Source vtbl (INFERRED English):** `+4` Seek-like `(pos,0)` result discarded; `+0x14` Read-like `(dst,size)` return status.

6. **Callee:** CRT `memmove` via IAT `0x009c652c`.

7. **Name:** structural `stoChunkStreamWindow_Ensure` (sibling readers call it ensure/refill). Parent-seed gfxBody-only name **misleading**.

### Gaps

1. Product/PDB symbol.  
2. Exact `streamEnd` (+0x14) when length unknown.  
3. Seek failure visibility (discarded).  
4. Runtime / bit-exact / differential — open.

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00435df0_stoChunkStreamWindow_Ensure.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00435df0_stoChunkStreamWindow_Ensure.md` |
| Function record | `docs/reconstruction/functions/aa_00435df0_stoChunkStreamWindow_Ensure.md` |
| Clean | `docs/reconstruction/reconstructed-exact/stoChunkStreamWindow_Ensure.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_00435df0.cpp` |
| Raw | `docs/reconstruction/raw/aa_00435df0_FUN_00435df0.md` |
| Annotated | `docs/reconstruction/raw/aa_00435df0_FUN_00435df0.annotated.md` |

---

## `aa_005081f0` — CVOGHBBase_EmptyVFunc

### Sealed facts

1. **Body:** `0x005081f0` = **`c3` (`ret`)** only. Exclusive end `0x005081f1`. Following `cc` is pad.

2. **CF:** empty `return;` — decompile ≡ raw ≡ live re-verify.

3. **ABI:** bare `ret` (not `ret n`). Ignores ECX and any stack args.

4. **Callees:** none. Classification: **stub**.

5. **Roles (xref, not body):**  
   - Base HB vtbl `0x009cdab0` **slot +0x14** = this.  
   - Tail-jmp target from subclass OnEnds (e.g. OKToCastAgain `0x0051e3c6`).  
   - Other CALL/DATA sites as shared nop.

6. **Not this VA:** mass `EmptyRet` `0x0056f570`; neighbor empty `0x005081e0` (base `vtbl+0x10`); Stop body `0x005081d0`.

7. **Name:** `CVOGHBBase_EmptyVFunc` (structural). Parent-seed OKToCastAgain-only name **incomplete**. Slot English “OnEnd” for +0x14 is **inferred / contested** with Stop’s +0x10 label — **behavior sealed as empty** regardless.

### Gaps

1. Original PDB/compiler symbol.  
2. Exhaustive DATA-slot census.  
3. Runtime / bit-exact / differential — open.

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_005081f0_CVOGHBBase_EmptyVFunc.md` |
| Review B | `docs/reconstruction/reviews/B_aa_005081f0_CVOGHBBase_EmptyVFunc.md` |
| Function record | `docs/reconstruction/functions/aa_005081f0_CVOGHBBase_EmptyVFunc.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBBase_EmptyVFunc.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_005081f0.cpp` |
| Raw | `docs/reconstruction/raw/aa_005081f0_FUN_005081f0.md` |
| Annotated | `docs/reconstruction/raw/aa_005081f0_FUN_005081f0.annotated.md` |

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`

---

## AutoCore impact

### Ensure (`0x00435df0`)

- Port as **sliding-window reposition + fill**, not a simple “read N more bytes” helper.
- Keep **three arms**; callers pass **`base+cursor`** when short.
- Surface **signed Read status**; do not invent Seek-error branches retail omits.
- Window fields `cursor/base/available/capacity/buffer` must match sibling ReadHeader16 map.

### EmptyVFunc (`0x005081f0`)

- Treat as **shared nop** — do not invent detach, free, cast-flag, or list work at this address.
- Base HB `vtbl+0x14` may collapse to empty; real OnEnd overrides are **other VAs**.
- Distinct from `EmptyRet` `0x0056f570` and neighbor empty `0x005081e0`.
