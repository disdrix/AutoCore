# Dual A/B report — W37-N OWN `aa_00735390` + `aa_0075eff0`

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual W37-N  
**Scope:** VAs `0x00735390`, `0x0075eff0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `batch_decompile` / `decompile_function` + `read_memory` + `analyze_function_complete` + callers/xrefs + callee decompile (`FUN_00465d70`) + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wave37_partition_map.md` (W37-N).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00735390` PalantirSub10_OwnedElem_CompleteDtor_Inferred | **accept-with-gaps** — stdcall RET 4 + COM@+0x48 + EBX vec@+0x70C + two strings sealed (115 B); product class English open |
| `aa_0075eff0` GfxDevice_Reset | **accept-with-gaps** — product gfxDevice Reset / EAX+RET12 / 0\|−1 / factory fail plate sealed (1391 B); unowned helpers + full field English open |

---

## VA `0x00735390` — sealed facts

1. **Body:** `0x00735390`–`0x00735403` exclusive (**115 B** / `0x73`; pad `CC` then next).
2. **ABI:** **stdcall** 1 stack formal (`elem*`); **`RET 4`** (`C2 04 00`); void. SEH `LAB_009ab754` (state 2 → 0 → −1). **Not** thiscall.
3. **Semantics (complete dtor):**
   - If COM at **`elem+0x48`**: **Release** via **vtbl[+8]**; null slot.
   - **`LEA EBX,[elem+0x70C]`**; **`FUN_00465d70`** — EBX-this vector tidy (stride **0x24** elems via `FUN_00481d80`, then `operator_delete` buffer). Decompiler shows bare call; **bytes + callee `unaff_EBX` win**.
   - Destroy **`std::string` @ +0x1C**, then **@ +0** (IAT `@0x009c62f4`).
4. **Layout span:** ≥ **0x71C** (through vector triad at +0x70C).
5. **Classification:** **worker** (complete dtor; host free is caller’s).
6. **Callers (1):** `FUN_00964d00` `PalantirSub10_DestroyOwnedPtrVecAndComUninit` (W35-J) @ `0x00964d37` — `PUSH elem; CALL`; then `operator_delete(elem)`.
7. **Callees:** COM Release vcall; `FUN_00465d70`; IAT `~basic_string` ×2.
8. **Name:** `PalantirSub10_OwnedElem_CompleteDtor_Inferred` (Ghidra `FUN_00735390`; **Inferred** structural from sole Palantir+0x10 consumer). Reject invented product class English.
9. **Family:** closes W35-J residual element dual under Palantir nested `+0x10` teardown chain.
10. **Decompile ≢ bytes** on stdcall / EBX formal; **bytes win**.  
    Full hex (115 B): raw W37-N append.

### Gaps

- Product C++ class English for element / COM iface / 0x24 vector payload.  
- Matching ctor / populate into Palantir+0x10 vec.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00735390_PalantirSub10_OwnedElem_CompleteDtor_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00735390_PalantirSub10_OwnedElem_CompleteDtor_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00735390_FUN_00735390.md` |
| Annotated | `docs/reconstruction/raw/aa_00735390_FUN_00735390.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/PalantirSub10_OwnedElem_CompleteDtor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00735390.cpp` |
| Function | `docs/reconstruction/functions/aa_00735390_FUN_00735390.md` |
| Function named | `docs/reconstruction/functions/aa_00735390_PalantirSub10_OwnedElem_CompleteDtor_Inferred.md` |

---

## VA `0x0075eff0` — sealed facts

1. **Body:** `0x0075eff0`–`0x0075f55f` exclusive (**1391 B** / `0x56F`).
2. **ABI:** **EAX** = present-param seed; stack **`(GfxDevice* device, uint32_t arg_b0, uint8_t flag5)`**; **`RET 12`** (`C2 0C 00`); **EAX out** = **0** success / **0xFFFFFFFF** failure. Entry `SUB ESP,0x38`; `MOV EBX,EAX`.
3. **Sole caller ABI** (`Palantir_ResetDevice` @ `0x00754480`, W35-K):  
   **EAX = Palantir+8**; stack **`([Palantir+0x28], [Palantir+0xB0], byte[Palantir+5])`**.
4. **Semantics (product `gfxDevice.cpp` Device Reset):**
   - Optional `DAT_00d1f614` memory accounting teardown from device dims @ **+0x2B8** family.
   - Build **14-dword** present local from **device+0x2B8** + **\*EAX / EAX[1]** + stack2/3; `FUN_0075e710`.
   - Log **`Beginning shutdown for Device Reset()`** (line **0x1FE**).
   - Shutdown cascade (IB/VB/view/effect/list helpers); Release COMs / default surfaces `device[2]`/`device[3]`.
   - **`IDirect3DDevice9::Reset`** via **`(*device)->vtbl[+0x40](device, &present)`**.
   - **Success:** factory Reset chain — fail strings IB/VB/Texture/gfxBufferedViews/Effect/Stats/GlobalEffect (lines **0x236..0x248**) → log + **−1**; full success → caps, surfaces, publish `DAT_00d1f048`, log **`Device Reset() complete`** (**0x270**), `device[0x1e9]=0`, return **0**.
   - **Reset fail:** D3D HRESULT product ERROR map via `FUN_0076c130`; **`TestCooperativeLevel`** `vtbl[+0x0C]`; return **−1**.
5. **Classification:** **worker** (device reset implementation).
6. **Callers (1):** `FUN_00754480` `Palantir_ResetDevice` @ `0x00754498`.
7. **Callees:** `FUN_0075e710`, factory Reset helpers, `vog_LogMessage`, `FUN_0076c130`, accounting helpers, D3D vcalls.
8. **Name:** `GfxDevice_Reset` (Ghidra `FUN_0075eff0`; **product** from path + Reset strings). Reject bare scaffold-only plate.
9. **Family:** closes W35-K residual nested device-reset dual; parent keeps retry/Sleep policy.
10. **Decompile ≢ bytes** on EAX formal display; **caller + entry `MOV EBX,EAX` + RET 12 win**.  
    Body bounds + entry/exit hex: raw W37-N append.

### Gaps

- Full GfxDevice / PresentParams product field English.  
- Unowned factory Reset helper duals.  
- Success-path accounting reverse multiplies look partially zeroed in decompile — do not overclaim bit-exact telemetry without runtime.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0075eff0_GfxDevice_Reset.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0075eff0_GfxDevice_Reset.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0075eff0_FUN_0075eff0.md` |
| Annotated | `docs/reconstruction/raw/aa_0075eff0_FUN_0075eff0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GfxDevice_Reset.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0075eff0.cpp` |
| Function | `docs/reconstruction/functions/aa_0075eff0_FUN_0075eff0.md` |
| Function named | `docs/reconstruction/functions/aa_0075eff0_GfxDevice_Reset.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00735390` | Port as **stdcall complete dtor** for **Palantir+0x10 owned-ptr elements**: Release COM@**+0x48**, tidy **0x24-stride** vector @**+0x70C** (`FUN_00465d70` EBX-this), destroy strings @**+0x1C** then **+0**. **RET 4**. Do **not** free the element (parent `operator_delete`). Do **not** use thiscall. Pair with W35-J `PalantirSub10_DestroyOwnedPtrVecAndComUninit`. |
| `0075eff0` | Port as **`GfxDevice_Reset`**: **EAX** present seed (**Palantir+8**) + stdcall **`(device*, arg_b0, flag5)`** + **RET 12** + return **0/−1**. Implement shutdown → **IDirect3DDevice9::Reset** → factory rebuild → caps/surfaces/globals. Keep Palantir retry/**Sleep(1000)** in **`Palantir_ResetDevice`**, not here. Do **not** drop EAX formal. |

Shared context (not co-owned beyond partition): both sit on the **Palantir** client graphics lifecycle — element teardown under nested `+0x10` vs device Reset nested under `Palantir::ResetDevice`. Different subsystems (COM/string element vs D3D device). Closes prior residuals called out in W35-J / W35-K.

| Prior residual | This dual |
|---|---|
| W35-J: element dual `FUN_00735390` open | **sealed** (accept-with-gaps) |
| W35-K: nested `FUN_0075eff0` open | **sealed** (accept-with-gaps) |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref helpers + callee decompile + assembly_context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names without evidence; `_Inferred` for structural element dtor; product **`GfxDevice_Reset`** from path/strings.  
- Avoided bare `undefined4` in clean contracts (used `uint32_t` / explicit pointers / documented CF).
