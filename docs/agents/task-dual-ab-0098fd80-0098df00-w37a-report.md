# Dual A/B report — W37-A OWN `aa_0098fd80` + `aa_0098df00`

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual W37-A  
**Scope:** VAs `0x0098fd80`, `0x0098df00` only (wave36 residual on second). Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress.json / NAMING_REGISTRY.  
**Ghidra:** `decompile_function` + `read_memory` + `analyze_function_complete` + `get_function_by_address` + `get_function_xrefs` + caller `FUN_0073c810` decompile. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wave37_partition_map.md` (W37-A).  
**Terminal coverage:** **false** (agent report; no runtime/diff claim).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0098fd80` PalToolNoMap_Host0x30_MaterialSlot0x28_Init_Inferred | **accept-with-gaps** — stack host, sole caller, +0x28, plate/params, float packs sealed; product English + helper thiscall open |
| `aa_0098df00` PalToolNoMap_Host0x40_MaterialAndShadowVolInit_Inferred | **accept-with-gaps** — EAX host, three stages, sole caller, slots/colors sealed; dual-shadow product role + helper depth open |

---

## VA `0x0098fd80` — sealed facts

1. **Body:** Ghidra `0x0098fd80`–`0x0098fee9`. Live decompile **≡** 2026-07-23 raw (no CF delta).
2. **ABI:** stack **`host*`**; **not** ECX-thiscall. Returns constant **0**.
3. **Semantics:**
   - Bind `PalToolMaterialNoMap.fx` (`FUN_00989e00` + `FUN_009701d0`).
   - Material holder at **`host+0x28`**.
   - `DepthBias` ← **0.001f** (`g_flMsToSeconds_Inferred` @ `0x00a0f72c` — shared pool name, numeric only).
   - `GhostAlpha` ← **0.1f** (`g_flMultiKillCountBlend` @ `0x00a0f730`).
   - `MatDiffuse` / `MatSpecular` / `MatEmissive` via null→`-1` else `FUN_00752370` + `FUN_0096fff0` when handle ≥ 0.
   - Emissive RGBA **(1.0, 0.4, 0.4, 1.0)** (`g_flOne`, `DAT_00a0f720`×2, `g_flOne`); `DAT_00a0f720` = `cd cc cc 3e`.
   - `FUN_0073d940` refcount-swap (vtbl+4 first-acquire / vtbl+8 release).
4. **Classification:** worker.
5. **Callers (1):** `FUN_0073c810` @ `0x0073cac3` — `new(0x30)` + `FUN_00457ac0` + zero `+0x28` → HostPtrTable12 **slot9**.
6. **Callees:** `FUN_00989e00`, `FUN_009701d0`, `FUN_00442640`, `FUN_00752370`, `FUN_0096fff0`, `FUN_0073d940`.
7. **Name:** `PalToolNoMap_Host0x30_MaterialSlot0x28_Init_Inferred` (Ghidra `FUN_0098fd80`; **Inferred**). Plate alias `Gfx_PalToolMaterialNoMap_0098fd80` is incomplete as sole surface.

### Gaps

- Product/PDB host class English.  
- Helper thiscall ECX recovery for `FUN_009701d0` / `FUN_00442640`.  
- Unowned callee full contracts.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0098fd80_PalToolNoMap_Host0x30_MaterialSlot0x28_Init_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0098fd80_PalToolNoMap_Host0x30_MaterialSlot0x28_Init_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0098fd80_FUN_0098fd80.md` |
| Annotated | `docs/reconstruction/raw/aa_0098fd80_FUN_0098fd80.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/PalToolNoMap_Host0x30_MaterialSlot0x28_Init_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0098fd80.cpp` |
| Function | `docs/reconstruction/functions/aa_0098fd80_FUN_0098fd80.md` |

---

## VA `0x0098df00` — sealed facts

1. **Body:** Ghidra `0x0098df00`–`0x0098e29f`. Live decompile **≡** 2026-07-23 raw (no CF delta).
2. **ABI:** host in **EAX** (`in_EAX`); **no** stack formal at call site. Returns constant **0**.
3. **Semantics (three stages):**
   - **`+0x28`** `PalToolMaterialNoMap.fx`: DepthBias 0.001, GhostAlpha 0.1, MatDiffuse/Specular/Emissive RGBA **(1.0, 0.2, 0.2, 1.0)** (`DAT_00a0f70c`=0.2f).
   - **`+0x30`** `PalVisibleShadowVolume.fx`: SolidColor **(0,1,0,0.5)**, WireColor **(0,1,0,0.5)** (`DAT_00a0f298`=0.5f; ADV 2026-08-04 corrected stage-2 wire from false blue claim).
   - **`+0x38`** `PalVisibleShadowVolume.fx`: SolidColor **(0,0,1,0.5)**, WireColor **(0,0,1,0.5)**.
   - Each stage: null→`-1` param handles; `FUN_0073d940` refcount-swap.
4. **Classification:** worker.
5. **Callers (1):** `FUN_0073c810` @ `0x0073cb1b` — `new(0x40)` + `FUN_00457b30` + zero three holders → HostPtrTable12 **slot10**.
6. **Callees:** same set as `0098fd80` (multi-stage).
7. **Name:** `PalToolNoMap_Host0x40_MaterialAndShadowVolInit_Inferred` (Ghidra `FUN_0098df00`; **Inferred**). Reject plate-only `Gfx_PalToolMaterialNoMap_0098df00` as complete surface.

### Gaps

- Product/PDB host English; dual-shadow-volume design intent.  
- Helper thiscall ECX recovery.  
- Unowned callee full contracts.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0098df00_PalToolNoMap_Host0x40_MaterialAndShadowVolInit_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0098df00_PalToolNoMap_Host0x40_MaterialAndShadowVolInit_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0098df00_FUN_0098df00.md` |
| Annotated | `docs/reconstruction/raw/aa_0098df00_FUN_0098df00.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/PalToolNoMap_Host0x40_MaterialAndShadowVolInit_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0098df00.cpp` |
| Function | `docs/reconstruction/functions/aa_0098df00_FUN_0098df00.md` |

---

## Cross-unit notes

- Both are nested post-ctors of the same HostPtrTable12 bootstrap (`FUN_0073c810`), consecutive slot9 then slot10.
- Both use the same PalTool helper ladder; **do not** merge contracts: different host sizes (0x30 vs 0x40), different emissive constants (0.4 vs 0.2), and only `0098df00` owns shadow-volume stages.
- Shared float pool symbols must be treated as **numeric constants**, not product English for shader params.

---

## Status summary

| VA | Duals written | Verdict |
|----|---------------|---------|
| `0x0098fd80` | **yes** (A+B) | accept-with-gaps |
| `0x0098df00` | **yes** (A+B) | accept-with-gaps |

**Report path:** `docs/agents/task-dual-ab-0098fd80-0098df00-w37a-report.md`
