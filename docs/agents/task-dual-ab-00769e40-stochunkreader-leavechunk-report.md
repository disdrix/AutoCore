# Dual A/B report — `aa_00769e40` stoChunkReader_LeaveChunk

**Date:** 2026-07-29  
**Scope:** OWN ONLY VA `0x00769e40`. Dual A/B + three-rep refine. Seal LeaveChunk ABI, binary end seek, text brace leave, ring pop, sticky.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / ledgers.  
**Ghidra:** `decompile_function` + `read_memory` (+ function meta / callees / callers / xrefs). No `disassemble_bytes`.  
**Programs open:** `autoassault.exe` only (dual A/B = fidelity vs adversarial reviews).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00769e40` stoChunkReader_LeaveChunk | **accept-with-gaps** — leave CF/ABI/ring/sticky sealed; entry+0x10 English + tokenizer product open |

---

## Sealed facts

1. **ABI:** `__fastcall`/`__thiscall`-style — `stoChunkReader* this` in **ECX**, **no stack args**, plain **`RET`**, return sticky in **EAX** (`0` / `0xffffffff`).

2. **Body:** `0x00769e40`–`0x00769fcc`. SEH `LAB_009affc2`. Entry `6A FF 64 A1… 8B F1`.

3. **Sticky `+0x402c`:** cleared to **0** at entry; failures **OR** `0xffffffff` (bytes `or [esi+0x402c],eax`).

4. **Mode `+0x4044`:** `0` binary seek; `!=0` text brace walk (matches OpenChunk / readF32Array).

5. **Binary path:** ring index wrap `(write+base-1)`; load **`entry+0x10`** end absolute; invalid vs sign/`+0x28` → sticky fail; else reposition `+0x18/+0x1c/+0x20`.

6. **Text path:** depth starts at **1**; `FUN_00767840(this,1)` + `{`/`}` balance; on sticky < 0 log `stoChunk.cpp:0x20d` `"Could not find end of text chunk"` and **return −1 without ring pop**.

7. **Ring pop (success paths):** if `write(+0x4040)!=0` then `--write`; if write==0 clear `base(+0x403c)`.

8. **Three-rep:** raw 2026-07-23 ≡ live decompile 2026-07-29; OR-sticky clarified vs assign-looking decompile.

9. **Name:** `stoChunkReader_LeaveChunk` (reader method). Scope okFlag gate is sibling thunk `0x00437120`, not this VA.

10. **Call surface:** inventory **196** xrefs; Unserialize leave half across geometry/effects/physics/KEYR readers.

---

## Gaps

1. Product English for ring entry `+0x10` (endAbs) and `this+0x28` limit.  
2. Full ring-entry 0x14 product layout (OpenChunk sibling).  
3. Tokenizer `FUN_00767840` product dual (not owned).  
4. Runtime live verification / bit-exact image diff.  
5. Exhaustive per-caller leave-vs-thunk catalog (parent residual).

---

## Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_00769e40_stoChunkReader_LeaveChunk.md` | **accept-with-gaps** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_00769e40_stoChunkReader_LeaveChunk.md` | **accept-with-gaps** |

---

## Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00769e40_stoChunkReader_LeaveChunk.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00769e40_stoChunkReader_LeaveChunk.md` |
| Function record | `docs/reconstruction/functions/aa_00769e40_stoChunkReader_LeaveChunk.md` |
| Clean | `docs/reconstruction/reconstructed-exact/stoChunkReader_LeaveChunk.cpp` |
| Raw (authoritative body + v2026-07-29 append) | `docs/reconstruction/raw/aa_00769e40_FUN_00769e40.md` |
| Annotated | `docs/reconstruction/raw/aa_00769e40_FUN_00769e40.annotated.md` |
| This report | `docs/agents/task-dual-ab-00769e40-stochunkreader-leavechunk-report.md` |

Sibling context (not owned): EnterChunkScope `0x004370b0`, OpenChunk `0x0076a2c0`, okFlag leave thunk `0x00437120`, tokenizer `0x00767840`.

---

## AutoCore impact

- Client asset Unserialize leave must seek binary streams to **chunk end** then pop ring; text streams balance braces first.
- Sticky is **signed** success (`>=0`) / fail (`<0`); match OpenChunk sticky protocol.
- Ports must **not** pop the ring when text leave early-fails with the log path.
- Do not implement leave as ChunkScope thiscall — that ABI is Enter; leave body is reader thiscall.
