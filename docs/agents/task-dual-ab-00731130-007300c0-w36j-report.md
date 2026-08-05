# Dual A/B report — W36-J OWN `aa_00731130` + `aa_007300c0`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W36-J  
**Scope:** VAs `0x00731130`, `0x007300c0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `batch_decompile` / `decompile_function` + `read_memory` + `analyze_function_complete` + `get_function_by_address` + callers/xrefs/bulk xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave36_partition_map.md` (W36-J).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00731130` PalToolNoMap_Host0x44_DualChannelInit_Inferred | **accept-with-gaps** — 718 B / RET4 / dual +0x34+0x3c ladder / plate strings / sole caller sealed; product English + unowned helpers open |
| `aa_007300c0` PalToolNoMap_Host0x34_MeshBuildUpload_Inferred | **accept-with-gaps** — 2040 B / RET4 / SEH / material+0x24 / counts+flag / 0|-1 returns / sole caller sealed; second-path decompiler alias + product English open |

---

## VA `0x00731130` — sealed facts

1. **Body:** `0x00731130`–`0x007313fd` (**718 B** / `0x2CE`; pad `CC CC` then `FUN_00731400`).
2. **ABI:** stack **`host*`**; **`RET 4`**; returns OR of statuses in EAX. **Not** ECX-thiscall.
3. **Semantics:** dual-channel PalTool no-map material init on HostPtrTable12 **slot5** host:
   - Channel 0 material slot **`host+0x34`**, channel 1 **`host+0x3c`**.
   - Each channel: bind `"PalToolMaterialNoMap.fx"` (`FUN_00989e00` + `FUN_009701d0`); set MatDiffuse / MatAmbient / MatSpecular / MatEmissive via `FUN_00752370` + `FUN_0096fff0` (missing → `0xFFFFFFFF`); `FUN_004246a0`; `FUN_0073d940` refcount swap; `FUN_00730b50(host, ch)`.
   - Return bitwise OR of all intermediate statuses.
4. **Host span:** bootstrap **`new(0x44)`** (W35-E); slots require ≥ `0x40`.
5. **Classification:** **worker** (post-ctor init).
6. **Callers (1):** `FUN_0073c810` @ `0x0073c9ad` — after `FUN_00457720` on slot5 object.
7. **Callees:** `FUN_00989e00`, `FUN_009701d0`, `FUN_00752370`, `FUN_0096fff0`, `FUN_004246a0`, `FUN_0073d940`, `FUN_00730b50`.
8. **Name:** `PalToolNoMap_Host0x44_DualChannelInit_Inferred` (Ghidra `FUN_00731130`; **Inferred**). **Reject** scaffold `Gfx_PalToolMaterialNoMap_00731130` as incomplete.
9. **Decompile ≡ bytes** for dual offsets, strings, `RET 4`, OR-return. Full 718 B hex in raw W36-J append.

### Gaps

- Product/PDB English for 0x44 host class.  
- Full contracts of unowned callees (`FUN_00730b50`, material helpers).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00731130_PalToolNoMap_Host0x44_DualChannelInit_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00731130_PalToolNoMap_Host0x44_DualChannelInit_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00731130_FUN_00731130.md` |
| Annotated | `docs/reconstruction/raw/aa_00731130_FUN_00731130.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/PalToolNoMap_Host0x44_DualChannelInit_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00731130.cpp` |
| Function | `docs/reconstruction/functions/aa_00731130_FUN_00731130.md` |
| Function named | `docs/reconstruction/functions/aa_00731130_PalToolNoMap_Host0x44_DualChannelInit_Inferred.md` |

---

## VA `0x007300c0` — sealed facts

1. **Body:** `0x007300c0`–`0x007308b7` (**2040 B** / `0x7F8`; pad `CC` then `FUN_00730910`).
2. **ABI:** stack **`host*`**; **`RET 4`**; SEH **`LAB_009b1eb6`**; returns **0** success / **0xFFFFFFFF** failure. **Not** ECX-thiscall.
3. **Semantics:** mesh build/upload for HostPtrTable12 **slot6** host (`new(0x34)` inline multi-vtbl):
   - Local mesh workspaces (`FUN_00981310` / `FUN_009813a0`, `FUN_0098ef00` / `FUN_0098f2b0`).
   - Bind `"PalToolMaterialNoMap.fx"` + MatDiffuse/Ambient/Specular/Emissive into **`host+0x24`**; `FUN_0073d940` refcount swap.
   - Stride 0x10 or 0x20 from material child flag `@(*mat+0x14)+0x10`.
   - **`host+0x20`** ← vert vector len/0x24/3; **`host+0x1c`** ← index vector len/6; **`host+0x2c = 4`**.
   - VB: `FUN_00414bc0(0x152)` + `FUN_00414c20`; Lock vtbl+0x2c flag **0x800**; memcpy; unlock helpers; IB via `FUN_0044b9c0` / `FUN_0044ba80` / `FUN_0044bbc0(..., host+0x14, 0)`; companion second geometry path.
4. **Host span:** bootstrap **0x34**.
5. **Classification:** **worker** (post-ctor build/upload).
6. **Callers (1):** `FUN_0073c810` @ `0x0073c9f5`.
7. **Callees:** mesh/material/VB family listed in function record (`FUN_009813*`, `FUN_0098*`, `FUN_00752370`, `FUN_0096fff0`, `FUN_0073d940`, `FUN_00414*`, `FUN_0044b*`, `FUN_00457a00`, `operator_delete`, …).
8. **Name:** `PalToolNoMap_Host0x34_MeshBuildUpload_Inferred` (Ghidra `FUN_007300c0`; **Inferred**). **Reject** scaffold `Gfx_PalToolMaterialNoMap` as incomplete.
9. **Decompile ≡ bytes** for SEH prologue, material+0x24, counts, RET 4, return codes. Full 2040 B hex omitted for size; range sealed by `get_function_by_address` + prologue/epilogue `read_memory`.

### Gaps

- Second geometry block decompiler stack aliasing (`piRam00000010` family).  
- Product English for 0x34 multi-vtbl host.  
- Exact vertex (0x24) / index (6) packing.  
- Unowned helper full contracts.  
- Clean is structural (raw authoritative for full SEH branch order).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_007300c0_PalToolNoMap_Host0x34_MeshBuildUpload_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_007300c0_PalToolNoMap_Host0x34_MeshBuildUpload_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_007300c0_FUN_007300c0.md` |
| Annotated | `docs/reconstruction/raw/aa_007300c0_FUN_007300c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/PalToolNoMap_Host0x34_MeshBuildUpload_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_007300c0.cpp` |
| Function | `docs/reconstruction/functions/aa_007300c0_FUN_007300c0.md` |
| Function named | `docs/reconstruction/functions/aa_007300c0_PalToolNoMap_Host0x34_MeshBuildUpload_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00731130` | Port as **stdcall** dual-channel PalTool no-map init on **0x44** host: material ptrs at **+0x34** and **+0x3c**; OR-combined status return; **`RET 4`**. Pair with W35-E HostPtrTable12 slot5 (`new(0x44)` + `FUN_00457720`). Do **not** model as thiscall. Do **not** collapse to single material. |
| `007300c0` | Port as **stdcall** mesh build/upload on **0x34** host: material at **+0x24**; counts **+0x1c/+0x20**; flag **+0x2c=4**; VB format **0x152**; Lock **0x800**; return **0/-1**. Pair with W35-E slot6 inline multi-vtbl. Ignore decompiler `piRam*` absolute aliases. Prefer raw decompile for full SEH order. |

Shared: both bind plate **`PalToolMaterialNoMap.fx`** and Mat* params; both sole-called from the same HostPtrTable12 bootstrap (slots 5 and 6). Co-owned only by W36-J partition assignment; different host sizes and depth (dual-channel init vs full mesh upload).

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref helpers. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names without evidence; `_Inferred` structural names only.  
- Rejected incomplete scaffold `Gfx_PalToolMaterialNoMap*` plates as sole names.  
- Avoided bare `undefined4` in clean (used `uint32_t` / explicit pointers).
