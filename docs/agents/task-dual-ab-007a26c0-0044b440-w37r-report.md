# Dual A/B report — W37-R OWN `aa_007a26c0` + `aa_0044b440`

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual W37-R  
**Scope:** VAs `0x007a26c0`, `0x0044b440` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `batch_decompile` + `analyze_function_complete` + `get_function_by_address` + `get_xrefs_to` + `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wave37_partition_map.md` (W37-R).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_007a26c0` Palantir_ExtendedHost_Ctor_Inferred | **accept-with-gaps** — stack-self ABI, base→derived vtbl, `DAT_00d17958`, display stamps, 701 B sealed; product demangle / nested types open |
| `aa_0044b440` Xform_SetScaleXYZ_DetectUniform_Inferred | **accept-with-gaps** — thiscall leaf scale triple + uniform/revision/cache, 175 B + eps sealed; product xform type open |

---

## VA `0x007a26c0` — sealed facts

1. **Body:** `0x007a26c0`–`0x007a297D` exclusive (**701 B** / `0x2BD`; pad `CC`). Ghidra end `0x007a297c` undercounts by 1 (final `00` of `RET 4`).
2. **ABI:** **stack=`self*`** (`MOV ESI,[esp+0x18]`); **`RET 4`**; **EAX=self**. Not ECX-thiscall. Matches `Palantir_BaseCtor` family (W35-I).
3. **Semantics:**
   - SEH `LAB_009b0088`.
   - `FUN_007543b0(self)` — `Palantir_BaseCtor`.
   - `*self = PTR_FUN_00a97170` (derived host vtbl; overwrites base).
   - `FUN_00424bf0` with **EAX=`self+0xD8`**.
   - Field stamps: flags, **800×600** resolution, floats **0.01 / 1.0 / 0.1×3 / 64 / 15**, `PTR_LAB_00a9add0` @ `+0x1FC`.
   - `self+0x2D4 = FUN_004933f0()`; `+0x2D8=0`; `+0x2E1=1`.
   - **`DAT_00d17958 = self`** (distinct from base `DAT_00d1f058`).
   - `operator_new(0xA8)` → circular list head (white RGBA @ `+0xC..+0x17`, `+0x6C=0`) stored at `+0x2DC`.
   - Zero `+0x13C..+0x158`; return self.
4. **Classification:** worker (placement ctor).
5. **Callers (2):** `FUN_00948bd0` @ `0x00948c11`, `FUN_0094a6a0` @ `0x0094a883`.
6. **Callees:** `FUN_007543b0`, `FUN_00424bf0`, `FUN_004933f0`, `operator_new`.
7. **Name:** `Palantir_ExtendedHost_Ctor_Inferred` (Ghidra `FUN_007a26c0`; **Inferred**). **Reject** scaffold `Named_CalleeOf_Named_Client_InitInstance_007a26c0`.
8. **Decompile ≡ CF**; bytes correct ABI/`RET 4`/singleton. Full hex: raw W37-R append.

### Gaps

- RTTI / product demangle for `PTR_FUN_00a97170` type.  
- Product names for `FUN_00424bf0` / `FUN_004933f0` / `0xA8` node.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_007a26c0_Palantir_ExtendedHost_Ctor_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_007a26c0_Palantir_ExtendedHost_Ctor_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_007a26c0_FUN_007a26c0.md` |
| Annotated | `docs/reconstruction/raw/aa_007a26c0_FUN_007a26c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Palantir_ExtendedHost_Ctor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_007a26c0.cpp` |
| Function | `docs/reconstruction/functions/aa_007a26c0_FUN_007a26c0.md` |
| Function named | `docs/reconstruction/functions/aa_007a26c0_Palantir_ExtendedHost_Ctor_Inferred.md` |

---

## VA `0x0044b440` — sealed facts

1. **Body:** `0x0044b440`–`0x0044b4EF` exclusive (**175 B** / `0xAF`; pad `CC`).
2. **ABI:** **`__thiscall`**; ECX=`this` (xform/matrix subobject); stack **3× float**; **`RET 0x0C`**. Leaf (no CALLs).
3. **Semantics:**
   - If `x,y,z` all **exactly equal** stored `+0x9C/+0xA0/+0xA4` → return (no dirty).
   - Else store triple; **`+0xBC = 0xFFFFFFFF`**.
   - If `|x−y| ≤ eps` and `|x−z| ≤ eps` (`eps = DAT_00aaa620` ≈ **1e-5**): `+0xB8=0`, `+0xB4++`.
   - Else: `+0xB4++`, `+0xB8=1`.
4. **Classification:** leaf worker (scale write + uniform detect).
5. **Callers (3 fn / 4 sites):** `FUN_005b35a0` (`CVOGEnvironmentReflect_ctor`) @ `0x005b363a` with **(1,−1,1)** on `this+0x90`; `FUN_005a75f0` ×2; `FUN_0096b280` ×1.
6. **Callees:** none.
7. **Name:** `Xform_SetScaleXYZ_DetectUniform_Inferred` (Ghidra `FUN_0044b440`; **Inferred**). **Reject** scaffold `Named_CalleeOf_Named_CalleeOf_Drive_NDRiver_fx_0044b440`.
8. **Decompile ≡ CF**; bytes seal thiscall/`RET 0x0C`/eps. Full hex: raw W37-R append.

### Gaps

- Product type of xform subobject (`FUN_00972cc0` family).  
- Consumers of `+0xB4` / `+0xB8` / `+0xBC`.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0044b440_Xform_SetScaleXYZ_DetectUniform_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0044b440_Xform_SetScaleXYZ_DetectUniform_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0044b440_FUN_0044b440.md` |
| Annotated | `docs/reconstruction/raw/aa_0044b440_FUN_0044b440.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Xform_SetScaleXYZ_DetectUniform_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0044b440.cpp` |
| Function | `docs/reconstruction/functions/aa_0044b440_FUN_0044b440.md` |
| Function named | `docs/reconstruction/functions/aa_0044b440_Xform_SetScaleXYZ_DetectUniform_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `007a26c0` | Port as **derived Palantir host placement ctor**: stack self + `RET 4`; always call `Palantir_BaseCtor` first; overwrite vtbl; publish **`DAT_00d17958`** (not `DAT_00d1f058`); stamp 800×600 defaults; allocate list node `0xA8`. Pair with W35-I base + allocation callers. |
| `0044b440` | Port as **thiscall scale XYZ setter** on xform subobject: early-out on exact float equality; always invalidate `+0xBC` and bump `+0xB4` on change; uniform flag from pairwise eps (~1e-5). Used by env-reflect with (1,−1,1). |
| Shared | Independent units (no direct call edge). Both reject scaffold callee-of names. Avoid bare `undefined4` in clean (`uint32_t` / typed offsets). |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref helpers. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** (W37-R sections).  
- No invented product plates; `_Inferred` names from sealed CF + W35-I Palantir base pairing / xform caller context.  
- Rejected scaffold Client_InitInstance / Drive_NDRiver callee-of product roles.  
- Avoided bare `undefined4` in clean (`uint32_t` / offset helpers).
