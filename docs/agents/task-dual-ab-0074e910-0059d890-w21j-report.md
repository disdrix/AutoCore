# Dual A/B report — W21-J OWN-ONLY (`0x0074e910`, `0x0059d890`)

**Date:** 2026-07-29  
**Agent:** W21-J OWN-ONLY  
**Scope:** OWN ONLY VAs `0x0074e910`, `0x0059d890`. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / parent ledgers.  
**Ghidra:** `decompile_function` + `read_memory` (+ function meta / xrefs / complete analysis). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict per VA

| Unit | Verdict |
|------|---------|
| `aa_0074e910` AnimSlot_SetTime | **accept** — **clamp/wrap playhead CF, `ret 8`, field map sealed; product spelling residual** |
| `aa_0059d890` CVOGObjective_SetCompleteCount | **accept** — **`+0x164` store + `ret 4` sealed; CompleteCount via getter twin; parent load residual** |

---

## `aa_0074e910` — AnimSlot_SetTime

### Sealed facts

1. **Body:** `0x0074e910`–`0x0074e9c2` inclusive (**179** B). Exclusive end `0x0074e9c3`. Final clamp-path `eb aa`; following `cc` pad.

2. **ABI:** **ECX = anim slot***; stack **float time**, **float endOrDuration**; epilogue **`ret 8`** (`c2 08 00`).

3. **Layout:**  
   - `+0x44` playhead (in/out)  
   - `+0x40` stores `param_3`  
   - `+0x48` length (clamp max / fmod modulus)  
   - `+0x4c` mode (`0`=clamp, nonzero=wrap)  
   - `+0x3c` rate  
   - `+0x34` = `param_3 - time/rate`  
   - `+0x50`/`+0x68` forced `0`  
   - `+0x6c` final time copy  

4. **Algorithm:** store time+end; if mode0 clamp to `[0,+0x48]` else `_CIfmod` wrap (negative → `+ length`); recompute `+0x34`; clear caches; mirror time.

5. **Callees:** `_CIfmod` only (wrap). Constant `g_flZero` @ `0x00a0f518` = `0.0f`.

6. **Callers (16 xrefs / 14 named):** includes `Object_LoadOrReplaceAnimSlot` (`0x005828b0`), `AnimHost_SelectBlendSlot` (`0x005816a0`), plus visual anim load/tick family.

7. **Object context:** ctor `FUN_0074ed90` builds **`0x78`** slot; default `+0x4c=1` (wrap), rate `1.0`. Load path often writes mode **after** this call.

8. **Name:** structural `AnimSlot_SetTime`; product/PDB spelling residual.

### Gaps

1. Product/PDB symbol spelling.  
2. English labels for `param_3` / remaining `+0x34` / cache fields.  
3. Runtime / bit-exact / differential — open.  
4. Clean uses `std::fmod` as behavioral stand-in for retail `_CIfmod` (not bit-claimed).

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_0074e910_AnimSlot_SetTime.md` | **accept** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_0074e910_AnimSlot_SetTime.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_0074e910_AnimSlot_SetTime.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0074e910_AnimSlot_SetTime.md` |
| Function record | `docs/reconstruction/functions/aa_0074e910_AnimSlot_SetTime.md` |
| Scaffold alias record | `docs/reconstruction/functions/aa_0074e910_FUN_0074e910.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AnimSlot_SetTime.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_0074e910.cpp` |
| Raw | `docs/reconstruction/raw/aa_0074e910_FUN_0074e910.md` |
| Annotated | `docs/reconstruction/raw/aa_0074e910_FUN_0074e910.annotated.md` |

---

## `aa_0059d890` — CVOGObjective_SetCompleteCount

### Sealed facts

1. **Body:** `0x0059d890`–`0x0059d89c` (**13** B). Exclusive end `0x0059d89d`. Hex: `8b 44 24 04 89 81 64 01 00 00 c2 04 00`.

2. **CF:** `*(uint32*)(this+0x164) = arg;` — decompile ≡ raw ≡ live re-verify.

3. **ABI:** `__thiscall` ECX=objective; one stack dword; **`ret 4`**.

4. **Callees:** none. Classification: **stub**.

5. **Field:** **CompleteCount** — sealed by sibling getter `aa_0059d880` + XML dump `FUN_005468c0` (`<CompleteCount>`).

6. **Callers (1):** `FUN_00547050` @ `0x005478a9` (`push eax; call`).

7. **Distinct from** getter `0x0059d880` (`mov eax,[ecx+0x164]; ret`) and from anim `0x0074e910`.

8. **Name:** `CVOGObjective_SetCompleteCount` (structural pair with getter).

### Gaps

1. Product/PDB setter spelling.  
2. Full mission load/parse path in parent `FUN_00547050` (out of unit).  
3. Runtime / bit-exact / differential — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_0059d890_CVOGObjective_SetCompleteCount.md` | **accept** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_0059d890_CVOGObjective_SetCompleteCount.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_0059d890_CVOGObjective_SetCompleteCount.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0059d890_CVOGObjective_SetCompleteCount.md` |
| Function record | `docs/reconstruction/functions/aa_0059d890_CVOGObjective_SetCompleteCount.md` |
| Scaffold alias record | `docs/reconstruction/functions/aa_0059d890_FUN_0059d890.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGObjective_SetCompleteCount.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_0059d890.cpp` |
| Raw | `docs/reconstruction/raw/aa_0059d890_FUN_0059d890.md` |
| Annotated | `docs/reconstruction/raw/aa_0059d890_FUN_0059d890.annotated.md` |

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`

---

## AutoCore impact

### AnimSlot_SetTime (`0x0074e910`)

- Port only if client visual/anim parity is in scope; **not** sector combat/physics core.
- Preserve **mode `+0x4c`**: clamp vs wrap; do not hardcode one path.
- Preserve **`ret 8` / two floats** and zeroing of `+0x50`/`+0x68`.
- Keep formula `+0x34 = endOrDuration - time/rate` with rate at `+0x3c`.
- Load path may set mode **after** time apply — match call order.

### CVOGObjective_SetCompleteCount (`0x0059d890`)

- Port as **raw assign** to objective CompleteCount `+0x164` (pair with getter).
- **No** validation/clamp in this VA.
- Wire from mission/objective load (parent), not from complete-gate paths (those **read** via getter).
- Distinct ABI from getter: **`ret 4`** vs bare `ret`.

---

## This report

`docs/agents/task-dual-ab-0074e910-0059d890-w21j-report.md`
