# Dual A/B report — W17-R OWN (`aa_00767070`, `aa_004368b0`)

**Date:** 2026-07-29  
**Scope:** OWN ONLY VAs `0x00767070`, `0x004368b0`. Dual A/B + three-rep refine.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledgers.  
**Ghidra:** `decompile_function` + `read_memory` (+ function meta / callees / callers / xrefs). No `disassemble_bytes`.  
**Programs open:** `autoassault.exe` only (dual A/B = fidelity vs adversarial reviews).  
**Image base:** `0x400000`.

---

## Verdicts

| Unit | Canonical name | Verdict |
|------|----------------|---------|
| `aa_00767070` / `0x00767070` | `stoChunkWriter_WriteTextIndent` | **accept-with-gaps** |
| `aa_004368b0` / `0x004368b0` | `stoChunkStreamWindow_ReadHeader16` | **accept-with-gaps** |

---

## Sealed facts — `0x00767070` WriteTextIndent

1. **ABI:** writer in **ESI**; no stack args; plain **`RET`**; return sticky **status** (`writer+0x04`) in **EAX**.
2. **Body:** `0x00767070`–`0x0076709d`.
3. **Math:** `count = depth(+0x18) * 4`; `textCol(+0x20) = count`; write **`count`** single spaces.
4. **DAT:** `0x00a2a000` = `" "` (`20 00 00 00…`).
5. **Write:** stream `vtbl+0x18`(buf, len=1); sticky `status |=`.
6. **Caller:** sole `stoChunkWriter_WriteFormatted` @ `0x007671ba` when `textCol==0`.
7. **Three-rep:** raw 2026-07-23 ≡ live decompile ≡ body/call-site bytes.

### Gaps

- Product English plate name.
- Runtime / bit-exact image diff.

---

## Sealed facts — `0x004368b0` ReadHeader16

1. **ABI:** stream **window** in **ESI**, **out u32[4]** in **EDI**; plain **`RET`**; return **0** / **−1**.
2. **Body:** `0x004368b0`–`0x004368f9`.
3. **Gate:** if `available < cursor+0x10` → `FUN_00435df0(window, base+cursor)` thiscall; fail if hr&lt;0 or `available < 0x10`.
4. **Copy:** 4 dwords from `window+0x18+cursor` → `*EDI`; `cursor += 0x10`.
5. **Window fields:** `+0x04` cursor, `+0x08` base, `+0x0c` available, `+0x18` buffer.
6. **Caller:** sole `stoChunkReader_OpenChunk` binary path (`lea esi,[reader+0x14]; lea edi, header`).
7. **Three-rep:** raw 2026-07-23 ≡ live decompile ≡ body/call-site bytes.

### Gaps

- Product English plate name.
- Full ensure contract (`FUN_00435df0` — not owned).
- Runtime / bit-exact image diff.

---

## Dual A/B

| VA | Review A | Review B | Verdict |
|---|---|---|---|
| `0x00767070` | `reviews/A_aa_00767070_stoChunkWriter_WriteTextIndent.md` | `reviews/B_aa_00767070_stoChunkWriter_WriteTextIndent.md` | **accept-with-gaps** |
| `0x004368b0` | `reviews/A_aa_004368b0_stoChunkStreamWindow_ReadHeader16.md` | `reviews/B_aa_004368b0_stoChunkStreamWindow_ReadHeader16.md` | **accept-with-gaps** |

---

## Files

### `aa_00767070` / `stoChunkWriter_WriteTextIndent`

| Kind | Path |
|------|------|
| Review A | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reviews\A_aa_00767070_stoChunkWriter_WriteTextIndent.md` |
| Review B | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reviews\B_aa_00767070_stoChunkWriter_WriteTextIndent.md` |
| Function record | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\functions\aa_00767070_stoChunkWriter_WriteTextIndent.md` |
| Function alias | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\functions\aa_00767070_FUN_00767070.md` |
| Clean named | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reconstructed-exact\stoChunkWriter_WriteTextIndent.cpp` |
| Clean FUN_* | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reconstructed-exact\FUN_00767070.cpp` |
| Raw | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\raw\aa_00767070_FUN_00767070.md` |
| Annotated | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\raw\aa_00767070_FUN_00767070.annotated.md` |

### `aa_004368b0` / `stoChunkStreamWindow_ReadHeader16`

| Kind | Path |
|------|------|
| Review A | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reviews\A_aa_004368b0_stoChunkStreamWindow_ReadHeader16.md` |
| Review B | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reviews\B_aa_004368b0_stoChunkStreamWindow_ReadHeader16.md` |
| Function record | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\functions\aa_004368b0_stoChunkStreamWindow_ReadHeader16.md` |
| Function alias | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\functions\aa_004368b0_FUN_004368b0.md` |
| Clean named | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reconstructed-exact\stoChunkStreamWindow_ReadHeader16.cpp` |
| Clean FUN_* | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reconstructed-exact\FUN_004368b0.cpp` |
| Raw | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\raw\aa_004368b0_FUN_004368b0.md` |
| Annotated | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\raw\aa_004368b0_FUN_004368b0.annotated.md` |

### This report

`C:\Users\josh\Documents\GitHub\AutoCore\docs\agents\task-dual-ab-own-w17r-00767070-004368b0-report.md`

---

## Sibling context (not owned)

| VA | Role |
|---|---|
| `0x00767160` | `stoChunkWriter_WriteFormatted` (sole caller of indent) |
| `0x0076a2c0` | `stoChunkReader_OpenChunk` (sole caller of ReadHeader16) |
| `0x00435df0` | stream-window ensure/refill (callee of ReadHeader16) |
| `0x007673a0` / `0x00767460` | EndChunk / BeginChunk (writer depth/textCol layout) |

---
