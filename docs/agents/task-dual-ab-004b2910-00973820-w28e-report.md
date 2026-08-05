# Dual A/B report — W28-E OWN `aa_004b2910` + `aa_00973820`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W28-E  
**Scope:** VAs `0x004b2910`, `0x00973820` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `get_function_by_address` + `read_memory` (+ callers/callees/xrefs). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave28_partition_map.md`

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004b2910` Color_LerpU8x3_Inferred | **accept-with-gaps** — CF + cdecl plain-ret + 3-ch ROUND lerp sealed; product slot English open |
| `aa_00973820` Color_PackFloat4_Scale255_Inferred | **accept-with-gaps** — CF + ret4 + ECX dest + ×255 sealed; nested packer dual open |

---

## VA `0x004b2910` — sealed facts

1. **Body:** `0x004b2910`–`0x004b29cd` (**190 B / `0xBE`**).
2. **ABI:** **cdecl** stack `(float t, uint8_t* out, uint8_t* from, uint8_t* to)`; epilogue **plain `RET`** (`C3`); void. Callers `add esp, 0x10`.
3. **Classification:** **leaf** (ROUND/FPU only; no `E8` callees).
4. **Semantics:** `out[i] = from[i] + ROUND((to[i]−from[i]) * t)` for **i ∈ {2,1,0}** only (no alpha).
5. **Caller (1 fn / 3 sites):** `ObjectMotion_ApplyStageParams_Inferred` (`FUN_004b2b90`) @ `0x004b2df5`, `0x004b2e52`, `0x004b313d`.
6. **Roles at call sites:** dirty RNG color between stage endpoints; continuous progress lerp baseline→end into slot color.
7. **Name:** `Color_LerpU8x3_Inferred` (Ghidra `FUN_004b2910`).
8. **Decompile ≡ bytes** for CF (live 2026-07-29 ≡ raw 2026-07-23).

### Gaps

- Product English / Torque original name.  
- Stage/slot three-byte color field labels.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004b2910_Color_LerpU8x3_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004b2910_Color_LerpU8x3_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004b2910_FUN_004b2910.md` |
| Annotated | `docs/reconstruction/raw/aa_004b2910_FUN_004b2910.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Color_LerpU8x3_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004b2910.cpp` |
| Function | `docs/reconstruction/functions/aa_004b2910_FUN_004b2910.md` |
| Function named | `docs/reconstruction/functions/aa_004b2910_Color_LerpU8x3_Inferred.md` |

---

## VA `0x00973820` — sealed facts

1. **Body:** `0x00973820`–`0x00973872` (**83 B / `0x53`**; pad `CC` after ret).
2. **ABI:** **ECX** = dest packed-color buffer; stack `(float *src4)`; epilogue **`ret 4`** (`C2 04 00`); void. (Decompiler surface drops ECX; restored from `mov eax,ecx` + call sites.)
3. **Classification:** **worker** (1 callee).
4. **Callee:** `FUN_00973590` — clamp+ROUND pack into EAX=dest.
5. **Constant (`read_memory`):** `DAT_00aaa6f8` @ `0x00aaa6f8` = `00 00 7F 43` = **255.0f**.
6. **Semantics:** `PackClamp(src[i] * 255.0f)` for i=0..3 into ECX buffer.
7. **Callers (4 fns / 9 xrefs):** `FUN_004b18f0` (child+0x34), `FUN_005b36f0` (fog), `FUN_005e1fc0`, `FUN_008e4430` (difficulty colors).
8. **Name:** `Color_PackFloat4_Scale255_Inferred` (Ghidra `FUN_00973820`).
9. **Decompile ≡ raw** for scale CF; **bytes supersede** decompiler ABI (ECX dest).

### Gaps

- Product English / PDB name.  
- Nested `FUN_00973590` full dual (channel map probable BGRA-style from its decompile).  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00973820_Color_PackFloat4_Scale255_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00973820_Color_PackFloat4_Scale255_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00973820_FUN_00973820.md` |
| Annotated | `docs/reconstruction/raw/aa_00973820_FUN_00973820.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Color_PackFloat4_Scale255_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00973820.cpp` |
| Function | `docs/reconstruction/functions/aa_00973820_FUN_00973820.md` |
| Function named | `docs/reconstruction/functions/aa_00973820_Color_PackFloat4_Scale255_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004b2910` | Port as U8×3 ROUND lerp; **not** float RGB and **not** 4-channel. Preserve channel order **2→1→0**. cdecl + plain ret. Sole consumer ApplyStageParams. |
| `00973820` | Port with **ECX dest** + stack float4 + **ret 4**. Always scale by **255.0f** before clamp-pack. Do not treat as matrix helper; do not drop ECX because decompiler omitted it. |

---

## Sibling context (not owned)

| VA | Role |
|---|---|
| `0x004b2b90` | `ObjectMotion_ApplyStageParams_Inferred` (W27-E) — sole caller of `004b2910` |
| `0x004b18f0` | `ObjectMotion_SyncChildPoseHF_Inferred` (W27-F) — packs color via `00973820` → child+0x34 |
| `0x00973590` | nested clamp-pack (dest via EAX) |
| `0x00973690` | sibling color helper (0.75 arg at SyncChildPoseHF) |
| `0x00aaa6f8` | 255.0f scale constant |
| `0x00aef980` | static float4 `{0,0,0,1}` black pack source |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + get_function_by_address + read_memory (+ callers/callees/xrefs).  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names; structural `_Inferred` only.  
- Avoid bare `undefined4` in clean (use `uint8_t` / `float`).
