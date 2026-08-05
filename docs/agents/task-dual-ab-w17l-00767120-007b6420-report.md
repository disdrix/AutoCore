# Dual A/B report — W17-L OWN-ONLY

**Date:** 2026-07-29  
**Agent:** W17-L  
**Workspace:** `C:\Users\josh\Documents\GitHub\AutoCore`  
**Module:** `autoassault.exe` base `0x400000`  
**OWN VAs:** `0x00767120`, `0x007b6420`  
**Excluded:** Launcher; parent ledger edits (`COVERAGE_LEDGER`, `WORK_QUEUE`, `RESUME`, `ACTIVE_WORK`, `CHANGE_LOG`, partition map).  
**Ghidra:** `decompile_function` + `force_decompile` + `read_memory` + basic pcode + `analyze_function_complete` + `get_assembly_context`. **No** `disassemble_bytes`.

---

## Verdicts

| Unit | VA | Inferred name | Verdict |
|------|-----|---------------|---------|
| `aa_00767120` | `0x00767120`–`0x0076715c` | `stoChunkReader_SoftSkipIfBitSet` | **accept-with-gaps** |
| `aa_007b6420` | `0x007b6420`–`0x007b644f` | `Path_GetFileName` | **accept** |

Three-rep: **not required** for either (decompile ≡ force_decompile; bytes/pcode agree).

---

## `aa_00767120` — stoChunkReader_SoftSkipIfBitSet

### Sealed facts

1. **ABI:** `__fastcall` this-style; **ECX = stoChunkReader\***; plain **RET**; **leaf**.
2. **Return:** bool 0/1 in EAX; callers `TEST AL,AL`.
3. **Algorithm:** if `reader[+0]==0` → false (`XOR AL,AL`); else bit-test against bitset base `reader[+8]` with formula  
   `base' = base + (id>>5)*4`, `idx = (id&0x1f)-1`, mask bit `idx&31` in dword at `base'+(idx>>5)*4`.
4. **Role:** soft-skip after `stoChunkReader_EnterChunkScope` — nonzero → unserialize returns **0** (not −1).
5. **Callers (4):** `FUN_00739c80`, `gfxGeometryPiece_Unserialize`, `gfxVertexBufferImpl_Unserialize`, `FUN_009991b0`.
6. **Dual decompile identical**; body hex sealed in raw append.

### Gaps

- Product English for `reader[+0]` / `reader[+8]`.
- `id & 0x1f == 0` underflow edge.
- Studio symbol (name **INFERRED**).

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00767120_FUN_00767120.md` |
| Annotated | `docs/reconstruction/raw/aa_00767120_FUN_00767120.annotated.md` |
| Function record | `docs/reconstruction/functions/aa_00767120_FUN_00767120.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00767120.cpp` |
| Named clean | `docs/reconstruction/reconstructed-exact/stoChunkReader_SoftSkipIfBitSet.cpp` |
| Review A | `docs/reconstruction/reviews/A_aa_00767120_stoChunkReader_SoftSkipIfBitSet.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00767120_stoChunkReader_SoftSkipIfBitSet.md` |

---

## `aa_007b6420` — Path_GetFileName

### Sealed facts

1. **ABI:** path in **EDI**; return `char*` in **EAX**; plain **RET**.
2. **Callee:** `strrchr` via IAT `0x009c662c` (twice: `'\\'` then `'/'`).
3. **Algorithm:** if no separators → return path; else return **one past max(last `\`, last `/`)**.
4. **No** allocation, **no** extension strip. Result aliases into input.
5. **22 xrefs**; callers include `NDUIWindow_LoadInterfaceFile`, `NDXml_LoadDocumentFromPath`, `FUN_007b6450`.
6. **Dual decompile identical**; body hex sealed in raw append.

### Gaps

- Studio symbol only (**INFERRED** `Path_GetFileName`).

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_007b6420_FUN_007b6420.md` |
| Annotated | `docs/reconstruction/raw/aa_007b6420_FUN_007b6420.annotated.md` |
| Function record | `docs/reconstruction/functions/aa_007b6420_FUN_007b6420.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_007b6420.cpp` |
| Named clean | `docs/reconstruction/reconstructed-exact/Path_GetFileName.cpp` |
| Review A | `docs/reconstruction/reviews/A_aa_007b6420_Path_GetFileName.md` |
| Review B | `docs/reconstruction/reviews/B_aa_007b6420_Path_GetFileName.md` |

---

## AutoCore impact (brief)

- **Soft-skip ≠ hard fail** in gfx unserialize ports.
- Path resolution must honor both `\` and `/` separators; treat return as alias into path buffer.
