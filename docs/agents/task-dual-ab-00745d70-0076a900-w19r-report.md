# Dual A/B report — W19-R OWN `0x00745d70` + `0x0076a900`

**Date:** 2026-07-29  
**Scope:** OWN ONLY VAs `0x00745d70`, `0x0076a900`. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER.  
**Ghidra:** `decompile_function` + `read_memory` (+ complete analysis / callers / callees). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict per VA

| Unit | Verdict |
|------|---------|
| `aa_00745d70` `NDResource_Ctor` | **accept-with-gaps** — ABI + 0x3c layout + CS/vtbl sealed; product spelling / optionalSrc virtual open |
| `aa_0076a900` `stoChunkReader_PeekChunkTag` | **accept-with-gaps** — ESI this + peek restore + mode paths sealed; plate name / full ring undo open |

---

## `0x00745d70` — NDResource_Ctor

### Sealed facts

1. **Body** `0x00745d70`–`0x00745dec`; **125 B**; in-place ctor.
2. **ABI:** **EDX = typeToken**; stack **this**, **nameKey***, **optionalSrc***; **`RET 0xC`**; returns **this**.
3. **Algorithm:** `*this = PTR_FUN_00aa1d40`; `+4=*nameKey`; zeros; `+0xc=EDX`; `+0x18=-1`; `InitializeCriticalSection(+0x20)`; `*(u8*)(+0x38)=1`; if optionalSrc: `+0x14 = src->vtbl[+4]()`.
4. **Bytes ≡ decompile** (hex in raw append).
5. **Callers (7):** `NDResourceCache_LookupOrCreate` (default `new(0x3c)` then patch `PTR_FUN_00a9e850`), `FUN_0044e560`, `FUN_00970c00`, `FUN_0043b910`, `FUN_00732e80`, `FUN_00995f60`, `FUN_0073b9a0`.
6. **Sibling dtor pattern:** `FUN_00745ff0` (same base vtbl, `DeleteCriticalSection`).

### Gaps

1. Product C++ class spelling (NDResource family High).  
2. optionalSrc `vtbl+4` English meaning.  
3. Runtime / bit-exact / image diff.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_00745d70_NDResource_Ctor.md` | **accept-with-gaps** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_00745d70_NDResource_Ctor.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00745d70_NDResource_Ctor.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00745d70_NDResource_Ctor.md` |
| Function record | `docs/reconstruction/functions/aa_00745d70_NDResource_Ctor.md` |
| Scaffold alias record | `docs/reconstruction/functions/aa_00745d70_FUN_00745d70.md` |
| Clean | `docs/reconstruction/reconstructed-exact/NDResource_Ctor.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_00745d70.cpp` |
| Raw | `docs/reconstruction/raw/aa_00745d70_FUN_00745d70.md` |
| Annotated | `docs/reconstruction/raw/aa_00745d70_FUN_00745d70.annotated.md` |

---

## `0x0076a900` — stoChunkReader_PeekChunkTag

### Sealed facts

1. **Body** `0x0076a900`–`0x0076aac9`; **458 B**.
2. **ABI:** **this in ESI** (not ECX); **0 stack args**; plain **`RET`**; **EAX = FOURCC** or 0.
3. **Algorithm:** save cursor (`+0x1c++0x18`) + pending (`+0x404c`); mode `+0x4044` **0** → `OpenChunk` + ring tag (`FUN_00436220`) + nest--; mode **1** → require `"CHUNK"` + 4-char BE pack; restore cursor + pending; return tag.
4. **Bytes ≡ decompile** (full hex in raw append).
5. **Callers (11):** `effEffect_Unserialize` (`cmp eax,'PARM'`), `phyBoneSharedData_unserialize`, `FUN_00437b00`, `FUN_00437c90`, `FUN_0044fe10`, `FUN_0073eb40`, `FUN_0095dae0`, `FUN_0095dc70`, `FUN_0095f560`, `FUN_00960f80`, `FUN_009615c0`.
6. **Sibling:** `stoChunkReader_OpenChunk` `0x0076a2c0` (consume; this **ECX**).

### Gaps

1. Product English name (plate absent).  
2. Nest-- vs full ring element free.  
3. Nested callee product names (`FUN_00767840`, `FUN_00769b70`, `FUN_00436220`).  
4. Runtime / bit-exact / image diff.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_0076a900_stoChunkReader_PeekChunkTag.md` | **accept-with-gaps** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_0076a900_stoChunkReader_PeekChunkTag.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_0076a900_stoChunkReader_PeekChunkTag.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0076a900_stoChunkReader_PeekChunkTag.md` |
| Function record | `docs/reconstruction/functions/aa_0076a900_stoChunkReader_PeekChunkTag.md` |
| Scaffold alias record | `docs/reconstruction/functions/aa_0076a900_FUN_0076a900.md` |
| Clean | `docs/reconstruction/reconstructed-exact/stoChunkReader_PeekChunkTag.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_0076a900.cpp` |
| Raw | `docs/reconstruction/raw/aa_0076a900_FUN_0076a900.md` |
| Annotated | `docs/reconstruction/raw/aa_0076a900_FUN_0076a900.annotated.md` |
| Prior named scaffold | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_gfxBodyMassageMachine_0076a900.cpp` (superseded by Peek name) |

---

## AutoCore impact

- **NDResource default instances:** ports that allocate cache miss objects must run this ctor layout (CS + ready flag + key/type slots) before installing the default vtbl — not a bare zero-fill.
- **Chunk unserialize:** tag lookahead is a dedicated **peek** with ESI this; do not call `OpenChunk` expecting non-destructive behavior. Binary vs text mode gates differ slightly from OpenChunk (peek text requires mode **== 1**, not merely non-zero).
- Keep ESI vs ECX conventions distinct across the stoChunkReader API surface.

---

## This report

`docs/agents/task-dual-ab-00745d70-0076a900-w19r-report.md`
