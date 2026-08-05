# Dual A/B report — W35-K OWN `aa_00754480` + `aa_0045f360`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W35-K  
**Scope:** VAs `0x00754480`, `0x0045f360` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `batch_decompile` / `decompile_function` + `analyze_function_complete` + `read_memory` + xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** wave35 (W35-K).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00754480` Palantir_ResetDevice | **accept-with-gaps** — product ResetDevice / ECX this / 0|-1 / retry+Sleep / success vcall sealed; nested `FUN_0075eff0` open |
| `aa_0045f360` StdUninitCopy_Pod28 | **accept-with-gaps** — EAX/ECX/EDI ABI / 0x1c / 7-dword leaf sealed; product T English open |

---

## VA `0x00754480` — sealed facts

1. **Body:** `0x00754480`–`0x007544E0` exclusive (**96 B** / `0x60`; pad `CC` then next).
2. **ABI:** **ECX=`Palantir*`** (`MOV ESI,ECX`); no stack formals; bare **`RET`** (`C3`); **EAX** = `0` success / `0xFFFFFFFF` failure.
3. **Semantics (product `Palantir::ResetDevice`):**
   - Call nested **`FUN_0075eff0`** with **EAX=`this+8`**, stack **`([this+0x28], [this+0xB0], byte[this+5])`**.
   - **Failure (`hr < 0`):** `vog_LogMessage(Palantir.cpp, 0x184, 0, "Palantir::ResetDevice failed. Will try again in 1000 msec. ")`; **`byte[this+6]=1`**; **`Sleep(1000)`** (IAT `@0x009c61a8`); return **-1**.
   - **Success:** **`byte[this+6]=0`**; thiscall **`ECX=*(this+0x2C)`**, push **`this+8`**, **`CALL [vtbl+8]`**; return **0**.
4. **Classification:** worker.
5. **Callers:** `FUN_007a3c80` @ `0x007a3c84` (direct); **vtbl[1]** of `PTR_FUN_00a9f76c` (W34-K peer complete dtor family).
6. **Callees:** `FUN_0075eff0`, `vog_LogMessage`, IAT `Sleep`.
7. **Name:** `Palantir_ResetDevice` (Ghidra `FUN_00754480`; **product** from log method name + path).
8. **Decompile ≢ bytes** on nested **`EAX=this+8`** setup into device reset; **bytes win**.  
   Full hex: raw W35-K append.

### Gaps

- Nested dual for `FUN_0075eff0` (gfxDevice Reset body).  
- Product type of `*(this+0x2C)` / semantics of `+5` / `+0xB0`.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00754480_Palantir_ResetDevice.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00754480_Palantir_ResetDevice.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00754480_FUN_00754480.md` |
| Annotated | `docs/reconstruction/raw/aa_00754480_FUN_00754480.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Palantir_ResetDevice.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00754480.cpp` |
| Function | `docs/reconstruction/functions/aa_00754480_FUN_00754480.md` |
| Function named | `docs/reconstruction/functions/aa_00754480_Palantir_ResetDevice.md` |
| Scratch | `docs/reconstruction/tmp/a_00754480.md` |

---

## VA `0x0045f360` — sealed facts

1. **Body:** `0x0045f360`–`0x0045f3AC` exclusive (**76 B** / `0x4C`; pad `CC` then next).
2. **ABI:** **EAX=dst**, **ECX=src_begin**, **EDI=src_end** (EDI live-in, not saved); bare **`RET`** (`C3`); **EAX out** = advanced dst end (`dst + n*0x1c`).
3. **Semantics:** MSVC-style **trivial uninitialized_copy** for POD elem size **0x1c** (7 dwords):
   - Empty range (`src_begin == src_end`) → early out, EAX unchanged.
   - Loop: if dst ≠ null, copy 7 dwords; advance src/dst by **0x1c**.
   - Null dst skips stores but still advances cursors.
4. **Classification:** **leaf** (no callees).
5. **Callers (4, sole parent):** `StdVector_InsertN_Pod28` (`FUN_0045cd30`, W34-P) @ `0x0045ce99`, `0x0045cecc`, `0x0045cf83`, `0x0045cfe0`.
6. **Name:** `StdUninitCopy_Pod28` (Ghidra `FUN_0045f360`; **Inferred** structural). Reject scaffold `Named_CalleeOf_*anmTrackMaster*`.
7. **Decompile ≢ bytes** on void / single formal; **bytes + parent sites win** (EAX/EDI formals + EAX-as-end).  
   Full hex: raw W35-K append.

### Gaps

- Product/PDB T English for Pod28 element.  
- Sibling fill-n `FUN_0045f150` not dual-owned.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0045f360_StdUninitCopy_Pod28.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0045f360_StdUninitCopy_Pod28.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0045f360_FUN_0045f360.md` |
| Annotated | `docs/reconstruction/raw/aa_0045f360_FUN_0045f360.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdUninitCopy_Pod28.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0045f360.cpp` |
| Function | `docs/reconstruction/functions/aa_0045f360_FUN_0045f360.md` |
| Function named | `docs/reconstruction/functions/aa_0045f360_StdUninitCopy_Pod28.md` |
| Scratch | `docs/reconstruction/tmp/a_0045f360.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00754480` | Port as **`Palantir::ResetDevice`**: **ECX=this**, bare RET, return **0/-1**. On fail: log product string, set **`this+6=1`**, **Sleep(1000)**. On success: clear flag; notify **`*(this+0x2C)`** via **vtbl[+8]** with **`this+8`**. Nested device reset is **`FUN_0075eff0`** (unowned) with **EAX=this+8** + stack device args. Do **not** treat as dtor. |
| `0045f360` | Port as **trivial uninit-copy stride 0x1c**: retail **EAX=dst, ECX=src_begin, EDI=src_end**; return **dst_end** in EAX. 7-dword POD only. Do **not** use as single-arg fastcall; do **not** run string/RC ctors; pair with **Pod28** insert-n (W34-P), not RcElem28/BasicString. |

Shared / related context (not owned this dual):

| VA / item | Role |
|---|---|
| `0x00754320` | `Palantir_CompleteDtor` (W34-K) — same vtbl family |
| `PTR_FUN_00a9f76c` | Palantir vtbl: [0] scalar dtor, **[1] ResetDevice** |
| `0x0075eff0` | gfx device Reset implementation (unowned) |
| `0x007a3c80` | wrapper: ResetDevice + broadcast `0x801B` on success |
| `0x0045cd30` | `StdVector_InsertN_Pod28` (W34-P) — sole parent of Pod28 uninit-copy |
| `0x0045f150` | sibling fill-n (unowned) |

Closes: product Palantir ResetDevice plate (vtbl[1] residual from W34-K) + Pod28 trivial uninit-copy leaf residual under W34-P insert-n.

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + xrefs. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- Product name used only with log evidence (`Palantir::ResetDevice`); Pod28 helper keeps structural name.  
- Avoided bare `undefined4` in clean (`uint32_t` / explicit structs).
