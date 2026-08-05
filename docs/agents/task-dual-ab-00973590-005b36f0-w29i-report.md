# Dual A/B report — W29-I OWN-ONLY (`0x00973590`, `0x005b36f0`)

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W29-I  
**Scope:** OWN ONLY VAs `0x00973590`, `0x005b36f0`. Dual A/B + artifacts (trio + function + A/B).  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave29_partition_map.md`  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / parent ledgers.  
**Ghidra:** `decompile_function` + `read_memory` (+ `analyze_function_complete` / `get_function_by_address` / xrefs / `search_byte_patterns` / `audit_globals_in_function`). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict per VA

| Unit | Verdict |
|------|---------|
| `aa_00973590` Color_ClampRoundPackBGRA_Inferred | **accept** — leaf clamp+ROUND pack; EAX dest; ret 0x10; BGRA map sealed |
| `aa_005b36f0` Env_ApplyFogShaderAndReflect_Inferred | **accept-with-gaps** — vtbl[1] fog+reflect apply CF sealed; product class open |

---

## `aa_00973590` — Color_ClampRoundPackBGRA_Inferred

### Sealed facts

1. **Body:** `0x00973590`–`0x00973680` exclusive (**240 B / `0xF0`**). Pad `CC` after epilogue.

2. **ABI:** **EAX** = `uint8_t *dest`; stack four floats; void; **`add esp,0xC; ret 0x10`**.

3. **Classification:** **leaf** (FPU ROUND/`fistp` only; no callees).

4. **Algorithm:**
   ```
   dest[2] = clamp_u8(ROUND(f0))
   dest[1] = clamp_u8(ROUND(f1))
   dest[0] = clamp_u8(ROUND(f2))
   dest[3] = clamp_u8(ROUND(f3))
   ```
   BGRA memory when args are RGBA.

5. **Decompile gap:** mid-channel out-of-range pointer *labels* may alias stack slots — **bytes win**; clamp semantics still 0..255.

6. **Callers (20 code xrefs):** includes `FUN_00973820` (W28-E scale pack), `FUN_00973690` (W28-F ARGB lerp), `FUN_008e4430`, `FUN_0073d200`×5, `FUN_00973770`, `FUN_00973880`, `FUN_00923c50`, …

7. **Name:** structural `Color_ClampRoundPackBGRA_Inferred`. Closes nested-packer gap left open by W28-E/F.

### Gaps

1. Product / PDB English.  
2. Runtime / bit-exact / differential — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_00973590_Color_ClampRoundPackBGRA_Inferred.md` | **accept** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_00973590_Color_ClampRoundPackBGRA_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00973590_Color_ClampRoundPackBGRA_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00973590_Color_ClampRoundPackBGRA_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_00973590_Color_ClampRoundPackBGRA_Inferred.md` |
| Scaffold alias record | `docs/reconstruction/functions/aa_00973590_FUN_00973590.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Color_ClampRoundPackBGRA_Inferred.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_00973590.cpp` |
| Raw | `docs/reconstruction/raw/aa_00973590_FUN_00973590.md` |
| Annotated | `docs/reconstruction/raw/aa_00973590_FUN_00973590.annotated.md` |

---

## `aa_005b36f0` — Env_ApplyFogShaderAndReflect_Inferred

### Sealed facts

1. **Body:** `0x005b36f0`–`0x005b3992` exclusive (**674 B / `0x2A2`**). Final **`ret 4`**; pad `CC`.

2. **ABI:** thiscall ECX=`this`; one stack arg; returns **0** / **-1**; **`ret 4`**.

3. **Dispatch:** **vtbl[1]** of `PTR_FUN_009d95a0` @ `0x009d95a4` (byte search). **0** direct CALL xrefs. Ctor `FUN_005b35a0` / dtor `FUN_005b3670` install vtbl.

4. **Algorithm (high level):**
   ```
   if (!this+0x15c || !*(ctx+0xe4f8)) return -1
   if (this+0x80):
     bind gFogEnable/Start/End/Color from this+0x164
     Color_PackFloat4_Scale255 on color@+0x60
     refresh reflect vectors at *(this+0x158)+8
   return 0
   ```

5. **Strings:** `"gFogEnable"`, `"gFogStart"`, `"gFogEnd"`, `"gFogColor"`.

6. **Callees (selected):** `FUN_0074f1b0`, `FUN_00442d50`, `FUN_00973820`, `FUN_004cd220`, `FUN_005b39d0`, `FUN_0099b8a0`, …

7. **Name:** structural `Env_ApplyFogShaderAndReflect_Inferred`. Do **not** seal product class as `CVOGEnvironmentReflect` from adjacent RTTI string + flag bytes.

### Gaps

1. Product English class / method name.  
2. Nested helper duals and reflect field labels.  
3. Runtime / bit-exact / differential — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_005b36f0_Env_ApplyFogShaderAndReflect_Inferred.md` | **accept-with-gaps** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_005b36f0_Env_ApplyFogShaderAndReflect_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_005b36f0_Env_ApplyFogShaderAndReflect_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_005b36f0_Env_ApplyFogShaderAndReflect_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_005b36f0_Env_ApplyFogShaderAndReflect_Inferred.md` |
| Scaffold alias record | `docs/reconstruction/functions/aa_005b36f0_FUN_005b36f0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Env_ApplyFogShaderAndReflect_Inferred.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_005b36f0.cpp` |
| Raw | `docs/reconstruction/raw/aa_005b36f0_FUN_005b36f0.md` |
| Annotated | `docs/reconstruction/raw/aa_005b36f0_FUN_005b36f0.annotated.md` |

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`

---

## AutoCore impact

### Color_ClampRoundPackBGRA_Inferred (`0x00973590`)

- Port as **shared leaf packer**: EAX dest, four floats, **ret 0x10**, ROUND+clamp 0..255.
- Preserve **BGRA** store order (do not write RGBA as `[0]=r`).
- Reuse from `Color_PackFloat4_Scale255` and `Color_LerpPackedARGB` — do not reimplement clamp in wrappers.
- Closes W28-E/F “nested `FUN_00973590` dual open” gap.

### Env_ApplyFogShaderAndReflect_Inferred (`0x005b36f0`)

- Port as **virtual method** on host with vtbl `009d95a0`, not a free function.
- Preserve gate (**-1**) vs work-flag skip (still **0**).
- Fog color path must call sealed scale-255 packer (which calls this wave’s pack leaf).
- Do not invent product class name from `CVOGEnvironmentReflect` RTTI adjacency alone.

---

## Notes

- Tools used: `decompile_function`, `batch_decompile`, `analyze_function_complete`, `read_memory`, `get_function_by_address`, `get_xrefs_to` / `get_bulk_xrefs`, `search_byte_patterns`, `audit_globals_in_function`. **No** `disassemble_bytes`. **No** Launcher. **No** parent ledger edits.
- Partition ownership: W29-I only for these two VAs.
- Scaffold raw bodies preserved; re-verify **appended** only.
