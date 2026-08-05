# OWN-ONLY dual agent report — W22-Q

| Field | Value |
|---|---|
| Agent | W22-Q |
| Workspace | `C:\Users\josh\Documents\GitHub\AutoCore` |
| Module | `autoassault.exe` base `0x400000` |
| Owned VAs | `0x004323e0`, `0x007689e0` |
| Tools | Ghidra `decompile_function` + `read_memory` only (no `disassemble_bytes`) |
| Launcher | **not** started |
| Parent ledger | **not** edited |
| Date | 2026-07-29 |

---

## VA `0x004323e0` — CxImage_Create

| Field | Value |
|---|---|
| Ghidra | `FUN_004323e0` |
| Canonical | `CxImage_Create` (**High** — plate strings) |
| Body | `0x004323e0`–`0x0043255f` (last `ret 0xc`; Ghidra range to `0x00432575`) |
| Role | CxImage buffer create: bpp→bits, MAX_MEMORY, malloc header+palette+bits, install bits ptr |
| ABI | EBX=`this`, EAX=height, stack `(width,bpp,type)`, **`ret 12`** |
| Callers | TGA / BMP / PNG / WBMP loaders (`NDAssetImage_LoadTGA`, …) |
| Callees | `FUN_004321b0`, `malloc`, `FUN_00433490`, `FUN_004331d0` |
| Live ≡ raw | Yes |
| **Verdict** | **accept-with-gaps** |

### Artifacts

- `docs/reconstruction/raw/aa_004323e0_FUN_004323e0.md`
- `docs/reconstruction/raw/aa_004323e0_FUN_004323e0.annotated.md`
- `docs/reconstruction/reconstructed-exact/CxImage_Create.cpp`
- `docs/reconstruction/reconstructed-exact/FUN_004323e0.cpp`
- `docs/reconstruction/functions/aa_004323e0_CxImage_Create.md`
- `docs/reconstruction/functions/aa_004323e0_FUN_004323e0.md`
- `docs/reconstruction/reviews/A_aa_004323e0_CxImage_Create.md`
- `docs/reconstruction/reviews/B_aa_004323e0_CxImage_Create.md`

---

## VA `0x007689e0` — stoChunkReader_TextReadU32

| Field | Value |
|---|---|
| Ghidra | `FUN_007689e0` |
| Canonical | `stoChunkReader_TextReadU32` (**Inferred** — text peer of `stoChunkReader_ReadU32`) |
| Body | `0x007689e0`–`0x00768c50` |
| Role | Text-mode uint32 token read: scan/pushback → parse → 0/−1; past-end `}` handling |
| ABI | EDI=`reader`, stack `uint32_t* out`, **`ret 4`** |
| Peer | Binary `stoChunkReader_ReadU32` @ `0x00437050` via dispatcher `FUN_00436900` (`reader+0x4044`) |
| Callers | Mode dispatcher + OpenChunk + many unserializers |
| Callees | `FUN_00435df0`, `FUN_00767600`, `FUN_00436250`, `FUN_0076cec0`, `vog_LogMessage`, STL string, `isspace` |
| Live ≡ raw | Yes |
| **Verdict** | **accept-with-gaps** |

### Artifacts

- `docs/reconstruction/raw/aa_007689e0_FUN_007689e0.md`
- `docs/reconstruction/raw/aa_007689e0_FUN_007689e0.annotated.md`
- `docs/reconstruction/reconstructed-exact/stoChunkReader_TextReadU32.cpp`
- `docs/reconstruction/reconstructed-exact/FUN_007689e0.cpp`
- `docs/reconstruction/functions/aa_007689e0_stoChunkReader_TextReadU32.md`
- `docs/reconstruction/functions/aa_007689e0_FUN_007689e0.md`
- `docs/reconstruction/reviews/A_aa_007689e0_stoChunkReader_TextReadU32.md`
- `docs/reconstruction/reviews/B_aa_007689e0_stoChunkReader_TextReadU32.md`

---

## Notes

- No Launcher. No parent ledger / `ACTIVE_WORK` / partition map edits.
- Did not write artifacts for non-owned helpers (`004321b0`, `00433490`, `004331d0`, `00435df0`, `00767600`, `00436250`, `0076cec0`, `00436900`, …).
- Named clean plates preferred over 2026-07-23 auto scaffolds; FUN_* / Named_* aliases updated to point at sealed CF.
- Prior raw bodies preserved; W22-Q live seal sections appended only.
