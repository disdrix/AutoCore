# Review A (reconstruction fidelity): `aa_00434b30` NDAssetImage_DecodeTgaRleRow_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00434b30` |
| **VA** | `0x00434b30` |
| **Body** | `0x00434b30`–`0x00434d99` (617 / `0x269` bytes) |
| **Canonical name** | `NDAssetImage_DecodeTgaRleRow_Inferred` |
| **Ghidra name** | `FUN_00434b30` |
| **Review date** | `2026-07-29` (W22-P dual seal) |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual) |
| **Counterpart** | `reviews/B_aa_00434b30_NDAssetImage_DecodeTgaRleRow_Inferred.md` |
| **System** | `gfx-asset` / `NDAssetImage` / TGA RLE row |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (no `disassemble_bytes`). Supporting: `analyze_function_complete`, callers, callees, `get_assembly_context`, jump-table `read_memory`.

---

## 1. Purpose

**One-row TGA RLE decoder.** Consumes packetized RLE/raw runs from an abstract stream, expands into the current row buffer by bpp (8/15/16/24/32), returns AL carry state so the next row can resume a split packet. Sole caller: sealed `NDAssetImage_LoadTGA` RLE path.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00434b30_FUN_00434b30.md` (+ W22-P re-verify) |
| Annotated | `docs/reconstruction/raw/aa_00434b30_FUN_00434b30.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/NDAssetImage_DecodeTgaRleRow_Inferred.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_00434b30.cpp` |
| Function record | `docs/reconstruction/functions/aa_00434b30_FUN_00434b30.md` |
| Live decompile | `0x00434b30` |
| Bytes | `read_memory` prologue / mid / epilogue + tables `@0x00434d9c` / `@0x00434db0` |
| Call site | `0x00434a34` in `NDAssetImage_LoadTGA` |

---

## 3. Byte / ABI seal

| Claim | Confidence | Evidence |
|---|---|---|
| Body 617 B ends `RET 0x18` | **Confirmed** | Ghidra body; epilogue `C2 18 00` |
| `ECX` = stream (`EBX` save) | **Confirmed** | prologue `8B D9`; call sites `MOV ECX, stream` |
| 6 stack formals | **Confirmed** | `RET 0x18`; LoadTGA push sequence |
| Return **AL** = `param_7` state | **Confirmed** | epilogue `8A 45 1C`; caller `MOV [ebp-0x2c], AL` |
| SEH frame `LAB_009bccc0` | **Confirmed** | prologue `6A FF 68 C0 CC 9B 00` |
| bpp jump tables | **Confirmed** | `read_memory` `@0x00434d9c` / `@0x00434db0` |
| RLE len = `pkt-0x7F` | **Confirmed** | decompile; standard TGA when high bit set |
| Raw len = `pkt+1` | **Confirmed** | decompile |
| Cross-row leftover + stream rewind | **Confirmed** | `vtbl+0x14` then `vtbl+0x10(pos,0)` when `param_7!=0xFF` after RLE |
| 24bpp dest advance ×3 | **Confirmed** | `*(short*)(param_2+0x16)==0x18` branch |
| Sole caller LoadTGA | **Confirmed** | xrefs / complete analysis |
| Live decompile ≡ raw body | **Confirmed** | 2026-07-29 re-verify |

---

## 4. Control flow: clean ≡ raw ≡ bytes

| Stage | Match |
|---|---|
| `i>=width` → return state | **Yes** |
| `state==0xFF` read packet else resume | **Yes** |
| RLE vs raw high-bit split | **Yes** |
| bpp switch 8/15/16/24/32 | **Yes** |
| 32bpp RGB + `FUN_00433280(A)` | **Yes** |
| Raw path → `FUN_00434dd0` | **Yes** |
| Pitch advance 3 vs 1 | **Yes** |
| Invented formats / free / lock | **None** |

---

## 5. Gaps

1. Product/CRT symbol — open (`_Inferred`).
2. Stream slot English (`vtbl+0x10(pos,0)` absolute vs skip mode).
3. Dual of `FUN_00434dd0` / full `FUN_00433280` register ABI (out of OWN scope).
4. `param_6` semantic beyond forward to raw helper.
5. Runtime / bit-exact / image diff — open.

**Verdict:** **accept-with-gaps**

---

## Checklist

| Check | Result |
|---|---|
| Clean CF matches raw / live decompile | **Pass** |
| ABI `RET 0x18` + AL state | **Pass** |
| TGA RLE math sealed | **Pass** |
| bpp table sealed | **Pass** |
| Sole caller named | **Pass** |
| Product name | **Open** |
| Verdict | **accept-with-gaps** |
