# Dual A/B report — `aa_004370b0` stoChunkReader_EnterChunkScope

**Date:** 2026-07-29  
**Scope:** OWN ONLY VA `0x004370b0`. Dual A/B + three-rep refine. Seal EnterChunkScope ABI, ChunkScope layout, ring wrap, OpenChunk okFlag.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / ledgers.  
**Ghidra:** `decompile_function` + `force_decompile` + `read_memory` (+ function meta / callees / callers / xrefs). No `disassemble_bytes`.  
**Programs open:** `autoassault.exe` only (dual A/B = fidelity vs adversarial reviews).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004370b0` stoChunkReader_EnterChunkScope | **accept-with-gaps** — ABI/scope/ring/okFlag sealed; absPos English + full ring entry open |

---

## Sealed facts

1. **ABI:** `__thiscall` — `ChunkScope* this` in **ECX**, stack **`stoChunkReader* reader`**, epilogue **`RET 4`**, return **scope\*** in **EAX**.

2. **Body:** `0x004370b0`–`0x0043711a`. Entry `56 8BF1 8B4C2408 57 890E E8…`. Tail **`C2 04 00`**.

3. **ChunkScope size `0x14`:**
   - `+0x00` reader\*  
   - `+0x04` absPos = `reader[+0x1c] + reader[+0x18]`  
   - `+0x08` okFlag **u8** (`setge` after OpenChunk; success iff signed ≥ 0)  
   - `+0x0c` tag FOURCC (`*ringEntry`)  
   - `+0x10` version (`*(ringEntry+8)`)

4. **Sole callee:** `stoChunkReader_OpenChunk` `0x0076a2c0` with **ECX = reader**.

5. **Ring (via `reader+0x4030`):** entries `+0x4034`, capacity `+0x4038`, base `+0x403c`, write `+0x4040`. Index = wrap`(write+base-1)`.

6. **CF:** linear after OpenChunk — always fills tag/version even if open failed; no SEH.

7. **Call sites:** `sub esp,0x14` (or larger) + `push reader` + `lea ecx, scope` + `call` (e.g. `FUN_0045e280`, `FUN_00989850`).

8. **Three-rep:** raw 2026-07-23 ≡ live decompile ≡ force_decompile 2026-07-29 ≡ body bytes.

9. **Name:** `stoChunkReader_EnterChunkScope` correct (plate + usage); **this** is scope, not reader.

---

## Gaps

1. Product English for `scope[+4]` (plate endPos vs body-start absolute).  
2. Full ring-entry layout beyond tag@0 / version@8 (sibling OpenChunk / leave).  
3. Ring contents when OpenChunk returns −1.  
4. Runtime live verification / bit-exact image diff.  
5. Leave pairing owned by `FUN_00769e40` / thunk `0x00437120` (not this VA).

---

## Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_004370b0_stoChunkReader_EnterChunkScope.md` | **accept-with-gaps** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_004370b0_stoChunkReader_EnterChunkScope.md` | **accept-with-gaps** |

---

## Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_004370b0_stoChunkReader_EnterChunkScope.md` |
| Review B | `docs/reconstruction/reviews/B_aa_004370b0_stoChunkReader_EnterChunkScope.md` |
| Function record | `docs/reconstruction/functions/aa_004370b0_stoChunkReader_EnterChunkScope.md` |
| Clean | `docs/reconstruction/reconstructed-exact/stoChunkReader_EnterChunkScope.cpp` |
| Raw (authoritative body + v2026-07-29 append) | `docs/reconstruction/raw/aa_004370b0_FUN_004370b0.md` |
| Annotated | `docs/reconstruction/raw/aa_004370b0_FUN_004370b0.annotated.md` |
| This report | `docs/agents/task-dual-ab-004370b0-stochunkreader-enterchunkscope-report.md` |

Sibling context (not owned): OpenChunk `0x0076a2c0`, leave `FUN_00769e40` `0x00769e40`, okFlag leave thunk `0x00437120`.

---
