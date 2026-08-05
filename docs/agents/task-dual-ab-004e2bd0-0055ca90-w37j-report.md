# Dual A/B report — W37-J OWN `aa_004e2bd0` + `aa_0055ca90`

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual W37-J  
**Scope:** VAs `0x004e2bd0`, `0x0055ca90` only. Dual A/B + artifacts (trio + function + A/B).  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `batch_decompile` / `analyze_function_complete` + `read_memory` + callers/xrefs + callee decompile. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wave37_partition_map.md` (W37-J).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004e2bd0` CNDHash_ReclaimAll_ValueOwning_009cb360 | **accept-with-gaps** — ABI/CF/stamp/value@+C/freelist/sole FreeBuckets caller sealed (94 B); product English open |
| `aa_0055ca90` CVOGEnvironmentDistort_BringUpParticleDistort_Inferred | **accept-with-gaps** — host+particle 0x198/0.2f/500.f/dds/fx/NormalMap sealed (434 B); child class English + binder residual |

---

## VA `0x004e2bd0` — sealed facts

1. **Body:** `0x004e2bd0`–`0x004e2c2e` exclusive (**94 B** / `0x5E`); pad `CC` after last instruction.
2. **ABI:** **`__thiscall`** (Ghidra `__fastcall` ECX); `MOV EBX,ECX`; no stack args; plain **`RET`** (`C3`); void.
3. **Role:** CNDHash **owning full-bucket reclaim** for freelist-class stamp **`009cb360`**:
   - for `i = 0 .. mask(+0x08)` **inclusive**
   - walk chain at `buckets[i]->head` (`*(bucket+4)`)
   - stamp `PTR_FUN_009cb360`; if `value(+0x0C)`: `(*vtbl)(1)` scalar-deleting destroy; null value
   - push node onto freelist `+0x20` (intrusive); clear head
4. **Does not:** zero `count(+0x0C)`; free table `+0x10`; free freelist storage; touch list ends.
5. **Callers (1):** `CNDHash_FreeBuckets_009cb45c` (`FUN_004bcca0`) @ `0x004bccaa` — sole static xref (W31-M).
6. **Callees:** virtual value dtor only (leaf FUN surface).
7. **Twin:** `FUN_004bcae0` @ `0x004bcae0` — stamp `009cb358`; value@+8 / next@+C (W37-G OWN). **Not interchangeable.**
8. **Name:** `CNDHash_ReclaimAll_ValueOwning_009cb360` (Ghidra `FUN_004e2bd0`). Parallel W18-J `…_ValueOwning_009cefec`. **Reject** scaffold Named_CalleeOf_VOG_DEBUG_STOP.
9. **Family:** FreeBuckets parent `004bcca0`; ReleaseNodes sibling `00413ea0` (same value@+C / next@+10 pattern).
10. **Decompile ≡ bytes** for loop/stamp/value delete/freelist/RET.  
    Full hex: `53555633c0578bd933ed8d9b000000008b4b108b14a98b7a043bf8742c8d49008bf78b4e0c3bc88b7f10c70660b39c0074088b016a01ff1033c03bf889460c8b4b20890e89732075d78b53108b0caa83c5018941043b6b0876b65f5e5d5bc3`
11. **Closes** W31-M residual “full value-ownership matrix inside reclaim FUN_004e2bd0 (not OWN)”.

### Gaps

- Product / PDB English beyond structural ReclaimAll / ValueOwning role.  
- Exact C++ type of owned payloads under stamp `009cb360`.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004e2bd0_CNDHash_ReclaimAll_ValueOwning_009cb360.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004e2bd0_CNDHash_ReclaimAll_ValueOwning_009cb360.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ W37-J append) | `docs/reconstruction/raw/aa_004e2bd0_FUN_004e2bd0.md` |
| Annotated | `docs/reconstruction/raw/aa_004e2bd0_FUN_004e2bd0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CNDHash_ReclaimAll_ValueOwning_009cb360.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004e2bd0.cpp` |
| Function | `docs/reconstruction/functions/aa_004e2bd0_FUN_004e2bd0.md` |
| Function named | `docs/reconstruction/functions/aa_004e2bd0_CNDHash_ReclaimAll_ValueOwning_009cb360.md` |

---

## VA `0x0055ca90` — sealed facts

1. **Body:** `0x0055ca90`–`0x0055cc42` exclusive (**434 B** / `0x1B2`); pad `CC`… then Enable `FUN_0055cc50` @ `0x0055cc50`.
2. **ABI:** **`__thiscall`**; `MOV ESI,ECX`; no stack args; SEH `LAB_009a4975`; plain **`RET`** after `ADD ESP,0x20`; void.
3. **Semantics:** particle-distort child bring-up on **`CVOGEnvironmentDistort`**:
   - Snapshot `DAT_00d1f058→+0x2c→+0x80/+0x84`
   - `operator_new(0x198)` + `FUN_00968a50` → **host+0x90**; child`+0x195`\|=**0x40**; child`+4`=host
   - Params: **0.2f** (`0x3e4ccccd` via `0075b3b0`), **500.0f** (`0x43fa0000` via `0075b390`), color **`0xff808000`** (`0075bf40`), clear/dirty flags, vcall child[+0x18](snapshot)
   - Material: **`Particle_Distort.dds`**, **`NDParticleDistortBlendNormal.fx`**, **`NormalMapTexture`**/`0xff808000`
   - **host+0x8C** ← child`+0x44`
4. **Classification:** **worker** (child factory + FX bind).
5. **Callers (1):** `CVOGEnvironmentDistort_Enable_Inferred` (`FUN_0055cc50`) @ `0x0055cc5f` — sole (W33-T).
6. **Host RTTI:** Confirmed on enable/ctor chain (W33-T): `.?AVCVOGEnvironmentDistort@@`.
7. **Name:** `CVOGEnvironmentDistort_BringUpParticleDistort_Inferred` (Ghidra `FUN_0055ca90`; **Inferred**). **Reject** bare `Gfx_NDParticleDistortBlendNormal` and Named_CalleeOf_* scaffold.
8. **Peer:** Reflect child `FUN_005b3420` (same 0x198 factory @ host+0x158; **no** Particle_Distort path).
9. **Decompile ≡ bytes** for alloc/params/strings/RET. Full 434 B hex in raw W37-J append.
10. **Closes** W33-T residual nested-work open **partially** (structural + product strings sealed; child class English still open).

### Gaps

- Product English for 0x198 particle child (`FUN_00968a50` / vtbl `00aa22a8`).  
- host+0x8C field meaning; material-binder object identity.  
- Retail OOM path: null child still OR-flags at +0x195 (crash-on-OOM).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0055ca90_CVOGEnvironmentDistort_BringUpParticleDistort_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0055ca90_CVOGEnvironmentDistort_BringUpParticleDistort_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ W37-J append) | `docs/reconstruction/raw/aa_0055ca90_FUN_0055ca90.md` |
| Annotated | `docs/reconstruction/raw/aa_0055ca90_FUN_0055ca90.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGEnvironmentDistort_BringUpParticleDistort_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0055ca90.cpp` |
| Function | `docs/reconstruction/functions/aa_0055ca90_FUN_0055ca90.md` |
| Function named | `docs/reconstruction/functions/aa_0055ca90_CVOGEnvironmentDistort_BringUpParticleDistort_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004e2bd0` | Port as **owning reclaim** (not FreeBuckets): destroy values via **vtbl(1)** at **node+0x0C**, freelist push at **+0x20**, clear heads for **0..mask inclusive**. Stamp **`009cb360`**. **Do not** zero count or free table here (parent FreeBuckets). **Do not** substitute twin `004bcae0` / stamp `009cb358` (value@+8). Pair with W31-M FreeBuckets `004bcca0`. |
| `0055ca90` | Port as **CVOGEnvironmentDistort particle-distort bring-up** (not full Enable): `new(0x198)`+ctor → **+0x90**, 0.2f/500.f/`0xff808000`, Particle_Distort.dds + NDParticleDistortBlendNormal.fx + NormalMapTexture, mirror **+0x8C←child+0x44**. Called only from Enable after HostBase ensure. Match retail null-new crash or document divergence. Do not treat as Reflect peer `005b3420` or process-singleton PhaseDistort. |

Shared: co-owned only by W37-J partition assignment; **different subsystems** (CNDHash reclaim vs VOGEnvironment particle FX). No shared callees.

---

## Sibling context (not owned)

| VA | Role |
|---|---|
| `0x004bcca0` | FreeBuckets parent of `004e2bd0` (W31-M) |
| `0x004bcae0` | Twin reclaim stamp `009cb358` (W37-G) |
| `0x004bcc60` | tableC FreeBuckets (W31-M) |
| `0x0055cc50` | Enable wrapper calling `0055ca90` (W33-T) |
| `0x00968a50` | Particle ctor 0x198 (W37-I) |
| `0x005b3420` | Reflect peer child bring-up (W37-M) |
| `0x0075bf40` | Diffuse/color helper (W37-L) |
| `0x00538200` | Medal ValueOwning reclaim parallel (W18-J) |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref helpers + callee decompile. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names without evidence; `_Inferred` / stamp-qualified structural names; body strings used where sealed.  
- Rejected Named_CalleeOf_* and incomplete Gfx-only plate for `0055ca90`.  
- Trio evidence: raw + annotated + clean (named) per VA; function records updated.
