# Dual A/B report — W36-N OWN `aa_00461720` + `aa_00965ab0`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W36-N  
**Scope:** VAs `0x00461720`, `0x00965ab0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `batch_decompile` / `decompile_function` + `read_memory` + `analyze_function_complete` + callers/xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave36_partition_map.md` (W36-N).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00461720` StdVector_EraseRange_RcElem28 | **accept-with-gaps** — stdcall 4 formals / RET 0x10 / stride 0x1c move+destroy sealed; product T + nested move/Release open |
| `aa_00965ab0` MeshWeightDebugOverlay_Update | **accept-with-gaps** — stdcall self / RET 4 / fade CF / resize+push UI domain sealed; product class + full draw body open |

---

## VA `0x00461720` — sealed facts

1. **Body:** `0x00461720`–`0x0046177F` exclusive (**95 B** / `0x5F`; pad `CC` then `FUN_00461780`). Ghidra end `0046177e` — **bytes win**.
2. **ABI:** Stack **stdcall** formals **`vec*`, `outIt*`, `first`, `last`**, **`RET 0x10`**. EBP holds vec; EAX/EDX load first/last at entry.
3. **Semantics:** MSVC-style **`vector::erase(first, last)`** for non-trivial T size **0x1c**:
   - Equal range: `*outIt = first; return outIt`.
   - Else: `FUN_00461e60` RC move-assign **`[last, end)` → `first`** (EAX=dest); destroy leftover **`[new_end, old_end)`** via `FUN_00460d70` stride **0x1c**; publish **`end = new_end`**; `*outIt = first`.
4. **Classification:** worker.
5. **Callers (1):** `FUN_004611e0` (`StdVector_Resize_RcElem28`) @ `0x00461293` (shrink).
6. **Name:** `StdVector_EraseRange_RcElem28` (Ghidra `FUN_00461720`; **Inferred** structural). Reject scaffold `Named_CalleeOf_*gfxDevice*`.
7. **Decompile ≡ bytes** for CF; **bytes win** on `RET 0x10` and stack formals.  
   Full hex: raw W36-N append (95 B).

### Gaps

- Product/PDB T English.  
- Nested `FUN_00461e60` / `FUN_00460d70` not dual-owned.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00461720_StdVector_EraseRange_RcElem28.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00461720_StdVector_EraseRange_RcElem28.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00461720_FUN_00461720.md` |
| Annotated | `docs/reconstruction/raw/aa_00461720_FUN_00461720.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_EraseRange_RcElem28.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00461720.cpp` |
| Function | `docs/reconstruction/functions/aa_00461720_FUN_00461720.md` |
| Function named | `docs/reconstruction/functions/aa_00461720_StdVector_EraseRange_RcElem28.md` |

---

## VA `0x00965ab0` — sealed facts

1. **Body:** `0x00965ab0`–`0x0096650A` exclusive (**2650 B** / `0xA5A`; pad `CC…` then next @ `0x00966510`). Ghidra end `00966509` — **bytes win**.
2. **ABI:** Stack **`self*`** (`[ebp+8]` → **EDI**), SEH frame, **stdcall `RET 4`** (sole parent pushes and does not clean).
3. **Semantics:** **Mesh weight debug overlay update** (gfx-device-owned object @ `device+0x7A0`):
   - dt from `FUN_0076c3c0` vs `@+0x30`; rate **−0.005f** (`0x00aaa9f4`) if `@+0x40==0` else **+0.005f** (`g_flHardKillInterpolate`); clamp progress `@+0x48` to **[0,1]**.
   - progress==0 → UI vtbl+4 early out.
   - dirty (`@+0x41`) or mid-fade → rebuild: nest UI on `@+0x34`; alpha = progress×**255**; empty mesh vec `@+0x5c/+0x60` (stride **0xC**) → placeholder; else **`StdVector_Resize_RcElem28`** @ `0x00965f47` then foreach mesh/mode sprintf lines (`Max Weights Per Vertex`, `TM/RM` Static/Normal) and **`FUN_00460f90`** push_back with RC font `@+0x3c`; layout; clear dirty.
4. **Classification:** worker (large domain UI).
5. **Callers (1):** `FUN_0075fb90` @ `0x0075fc18` (BeginScene path; `gfxDevice.cpp` residual).
6. **Name:** `MeshWeightDebugOverlay_Update` (Ghidra `FUN_00965ab0`; **Inferred** domain). Reject scaffold long `Named_CalleeOf_*gfxDevice*`.
7. **Decompile** seals CF/strings/callees; **bytes win** on entry EDI/self, body bounds, resize call target. Clean is **structural** (not full 2.6 KB line port).

### Gaps

- Product/PDB class English.  
- Full draw/layout callee contracts.  
- Mesh-entry struct beyond used fields/stride.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00965ab0_MeshWeightDebugOverlay_Update.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00965ab0_MeshWeightDebugOverlay_Update.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00965ab0_FUN_00965ab0.md` |
| Annotated | `docs/reconstruction/raw/aa_00965ab0_FUN_00965ab0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/MeshWeightDebugOverlay_Update.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00965ab0.cpp` |
| Function | `docs/reconstruction/functions/aa_00965ab0_FUN_00965ab0.md` |
| Function named | `docs/reconstruction/functions/aa_00965ab0_MeshWeightDebugOverlay_Update.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00461720` | Port as **RC-elem28 erase-range**: stdcall **`vec*, outIt*, first, last`**, **`RET 0x10`**. Move-assign tail with RC `@+0x10`, then Release leftover stride **0x1c**. Do **not** free the buffer or treat as destroy-only (`00461780`) or POD memmove erase. |
| `00965ab0` | Port as **mesh-weight debug overlay tick**: stdcall **`self*`**, **`RET 4`**. Fade ±0.005; rebuild RC UI lines via sealed resize + push_back; domain is debug overlay under gfx BeginScene — not core combat/device. |

Shared context (not owned):

| VA | Role |
|---|---|
| `0x004611e0` | `StdVector_Resize_RcElem28` (W35-Q) — sole erase parent; overlay resize callee |
| `0x00461780` | `StdDestroyRange_RcElem28` (W35-O) — destroy-only sibling |
| `0x004617a0` | `StdVector_InsertN_RcElem28` (W34-P) |
| `0x00461e60` | RC move-assign range (erase callee) |
| `0x00460d70` | per-elem Release leaf |
| `0x00460f90` | push_back RC-elem28 (overlay lines) |
| `0x0075fb90` | gfx BeginScene parent of overlay |
| `0x0076c3c0` | time base |

Together they close the **erase-range shrink engine** under RC resize and the **sole high-level consumer** of that resize (mesh-weight debug overlay), completing the W36-N pair linking container primitive ↔ gfx UI domain.

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref helpers. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product plates; `_Inferred` names only (`StdVector_EraseRange_RcElem28` from RC family; `MeshWeightDebugOverlay_Update` from strings + parent).  
- Avoided bare `undefined4` in clean (`uint32_t` / explicit structs).
