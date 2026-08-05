# Dual A/B report — W35-R OWN-ONLY (`0x0075f7f0`, `0x0074e380`)

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W35-R  
**Scope:** OWN ONLY VAs `0x0075f7f0`, `0x0074e380`. Dual A/B + artifacts (trio + function + A/B).  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave35_partition_map.md` → **W35-R**.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / parent ledgers.  
**Ghidra:** `batch_decompile` / `get_function_by_address` / `get_function_xrefs` / `get_function_callees` / `read_memory` (+ sole-caller decompile for wiring). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict per VA

| Unit | Verdict |
|------|---------|
| `aa_0075f7f0` GfxDevice_Ctor_Inferred | **accept-with-gaps** — ECX=d3d9 + stack self/device RET 8; 0x7b0 host; zero banks + 14 subsystem slots; sole gfxAdapter CreateDevice caller sealed; product/slot English open |
| `aa_0074e380` HostAux40_Ctor_Inferred | **accept-with-gaps** — stack-self RET 4; 0x40 layout; NestedHash0xC @+0x14; sole PoolHost freelist-miss caller sealed; product English open |

---

## `aa_0075f7f0` — GfxDevice_Ctor_Inferred

### Sealed facts

1. **Body:** `0x0075f7f0`–`0x0075fb87` exclusive (**919 B** / `0x397`). Final **`C2 08 00`** (`ret 0x08`); pad `CC`.

2. **ABI:** **ECX = `IDirect3D9*`** (not the constructed object); stack **self\*** (`0x7b0`), **device9\***; returns **self**. Confirmed by entry `8B 6C 24 24` / `89 45 00` / `89 4D 04` + epilogue `C2 08 00`.

3. **Header:** `*self = device9`; `self+4 = d3d9` then **AddRef** (`vtbl+4`); zero `+8/+c/+10`. Publish **`DAT_00d1f044 = self`**.

4. **Zero banks:**  
   - `+0x14` and `+0x144`: **0x4c** dwords (**0x130** = D3DCAPS9)  
   - `+0x2B8`: **0xe** dwords (**0x38** = D3DPRESENT_PARAMETERS)  
   - `+0x2F0`: **0x113** dwords  
   - mid cluster `@+0x774…`  
   Live caps/params are **copied by sole caller after return**.

5. **Subsystem slots** (`operator_new` + optional init; null-safe):

| Slot | Off | Size | Note |
|---|---|---|---|
| `0x1cf` | `+0x73C` | `0x20` | `DAT_00d1f624` **PoolHost** shell |
| `0x1d0` | `+0x740` | `0xC4` | `FUN_0073bfd0` |
| `0x1d1` | `+0x744` | `0x5C` | `DAT_00d1f630` |
| `0x1d2` | `+0x748` | `1` | `DAT_00d1f654` bare |
| `0x1d3` | `+0x74C` | `0x20` | `FUN_00986d40` |
| `0x1d4` | `+0x750` | `0x20` | `FUN_00985df0` |
| `0x1d5` | `+0x754` | `0x34` | `FUN_0096eec0` |
| `0x1d6` | `+0x758` | `0x28` | `DAT_00d1f628` + NestedHash **0x30** (W34-F) |
| `0x1d7` | `+0x75C` | `0x20` | `FUN_00966f70` |
| `0x1d8` | `+0x760` | `0x150` | `FUN_00969df0` |
| `0x1d9` | `+0x764` | `0x48` | `FUN_0073e3a0` |
| `0x1da` | `+0x768` | `0x5C` | `FUN_0073c150` |
| `0x1db` | `+0x76C` | `0x10` | `DAT_00d1f620` |
| `0x1dc` | `+0x770` | `0x1C` | `FUN_00987260` |

6. **Classification:** complete worker (device-host ctor / factory placement).

7. **Callers (1):** `FUN_00735c90` @ `0x00736489` — `operator_new(0x7b0)` then this; log plate `gfxAdapter.cpp`.

8. **Related:** W34-F NestedHash 0x30; W33-R PoolHost @ `DAT_00d1f624`; this dual’s HostAux40 via that pool.

9. **Name:** `GfxDevice_Ctor_Inferred` (Ghidra `FUN_0075f7f0`). **Reject** scaffold driver-version parent-seed alias.

10. **Decompile ≡ raw CF**; ABI/size sealed by `read_memory` + sole caller.

### Gaps

1. Product/MSVC demangle for gfx device class and each subsystem ctor.  
2. `FUN_00966690` early-init English.  
3. Runtime / bit-exact / differential — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_0075f7f0_GfxDevice_Ctor_Inferred.md` | **accept-with-gaps** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_0075f7f0_GfxDevice_Ctor_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_0075f7f0_GfxDevice_Ctor_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0075f7f0_GfxDevice_Ctor_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_0075f7f0_GfxDevice_Ctor_Inferred.md` |
| Scaffold record | `docs/reconstruction/functions/aa_0075f7f0_FUN_0075f7f0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GfxDevice_Ctor_Inferred.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_0075f7f0.cpp` |
| Raw (+ W35-R append) | `docs/reconstruction/raw/aa_0075f7f0_FUN_0075f7f0.md` |
| Annotated | `docs/reconstruction/raw/aa_0075f7f0_FUN_0075f7f0.annotated.md` |

---

## `aa_0074e380` — HostAux40_Ctor_Inferred

### Sealed facts

1. **Body:** `0x0074e380`–`0x0074e3d6` exclusive (**86 B** / `0x56`). Final **`C2 04 00`** (`ret 0x04`); pad `CC`.

2. **ABI:** stack **self\*** placement ctor; **not** ECX-thiscall; returns **self**. Confirmed `8B 74 24 14` + `C2 04 00`.

3. **Layout (0x40):**  
   - `+0x00` = **`g_flOne`** (`1.0f` @ `0x00a0f2a0` = `0000803f`)  
   - `+0x04` = **unwritten**  
   - `+0x08` / `+0x0c` / `+0x10` = 0  
   - `+0x14`…`+0x3b` = **`NestedHash_Ctor_Sentinel0xC`** (W34-F)  
   - `+0x3c` = 0

4. **SEH:** `LAB_009ad9f3`.

5. **Classification:** worker (host-aux element ctor).

6. **Callers (1):** `PoolHost_Acquire0x40_Inferred` (`0x00986070`) @ `0x009860f0` — freelist miss: `operator_new(0x40)` + this. Upstream: `HostBase_EnsureAuxPtrs` stores result at **`host+4`** when `(flags & 1)`.

7. **Related:** peer `HostAux14_Ctor_Inferred` (`0x00442c80`, host+8); NestedHash 0xC (W34-F); PoolHost (W33-R); HostBase ensure (W32-Q).

8. **Name:** `HostAux40_Ctor_Inferred` (Ghidra `FUN_0074e380`). **Reject** scaffold VOG_DEBUG parent-seed alias.

9. **Decompile ≡ raw CF**; ABI/layout sealed by `read_memory`.

### Gaps

1. Product English for 0x40 aux / float head.  
2. NestedHash product English (open under W34-F).  
3. Runtime / bit-exact / differential — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_0074e380_HostAux40_Ctor_Inferred.md` | **accept-with-gaps** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_0074e380_HostAux40_Ctor_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_0074e380_HostAux40_Ctor_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0074e380_HostAux40_Ctor_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_0074e380_HostAux40_Ctor_Inferred.md` |
| Scaffold record | `docs/reconstruction/functions/aa_0074e380_FUN_0074e380.md` |
| Clean | `docs/reconstruction/reconstructed-exact/HostAux40_Ctor_Inferred.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_0074e380.cpp` |
| Raw (+ W35-R append) | `docs/reconstruction/raw/aa_0074e380_FUN_0074e380.md` |
| Annotated | `docs/reconstruction/raw/aa_0074e380_FUN_0074e380.annotated.md` |

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-0075f7f0-0074e380-w35r-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0075f7f0` | Port as **gfx device host placement ctor**: ECX=**IDirect3D9\*** (AddRef into `+4`), stack **self (0x7b0)** + **device9**, **RET 8**. Zero caps/present banks here; caller fills them. Must seed **`DAT_00d1f624` PoolHost** and NestedHash 0x30 slot. Do **not** treat ECX as self. |
| `0074e380` | Port as **0x40 host-aux placement ctor** (stack self, **RET 4**): float `1.0` @+0; leave +4; NestedHash0xC @+0x14; zero +8/+c/+10/+3c. Used only on pool freelist miss; stored at **host+4**. Do **not** unify with HostAux14 (0x14 / host+8). |

### Shared context (not owned)

| VA | Role |
|---|---|
| `0x00735c90` | gfxAdapter CreateDevice path — sole GfxDevice factory |
| `0x00986070` | `PoolHost_Acquire0x40_Inferred` (W33-R) — sole HostAux40 caller |
| `0x00756320` | `HostBase_EnsureAuxPtrs_Inferred` (W32-Q) — host+4 consumer |
| `0x0043fdf0` | `NestedHash_Ctor_Sentinel0xC_Inferred` (W34-F) — HostAux40 embed |
| `0x00463bd0` | `NestedHash_Ctor_Sentinel0x30_Inferred` (W34-F) — GfxDevice slot |
| `0x00442c80` | `HostAux14_Ctor_Inferred` (W33-S) — peer host+8 aux |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + function/xref helpers + `read_memory`. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names without evidence; structural `_Inferred` names only (`GfxDevice_Ctor_*`, `HostAux40_Ctor_*`).  
