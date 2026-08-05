# Dual A/B report — W38-AB OWN `aa_0096c8e0` + `aa_0096e8e0`

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual W38-AB  
**Scope:** VAs `0x0096c8e0`, `0x0096e8e0` only. Dual A/B + artifacts (trio + function + A/B).  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / parent ledgers.  
**Ghidra:** `batch_decompile` / `decompile_function` + `analyze_function_complete` + `get_function_by_address` + callers/xrefs/callees + `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wave38_partition_map.md` (W38-AB).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0096c8e0` EffTextureImpl_ReleaseGpu_Unaccount_Inferred | **accept-with-gaps** — thiscall release+unaccount; COM trio; stats banks mirror create sealed; product flag English open |
| `aa_0096e8e0` EffTextureFactory_ReCreateDefaultPool_Inferred | **accept-with-gaps** — RET 4 / list ReCreate DEFAULT-pool / factory.cpp:0x159 sealed; create dual + `0x3000` role open |

---

## VA `0x0096c8e0` — sealed facts

1. **Body:** `0x0096c8e0`–`0x0096ca5a` exclusive (**378 B** / `0x17A`; pad `CC` then `FUN_0096ca60`).
2. **ABI:** **`__thiscall`**; ECX=`EffTextureImpl*`; plain **`RET`** (`C3`); void.
3. **Semantics:** GPU **release + stats unaccount** for an effect-texture impl:
   - If `+0x10` (primary D3D resource) non-null: reverse memory/count on optional `DAT_00d1f614` by flag/type bank (mirror inverse of account path in `FUN_0096cad0`).
   - Flags `+0x2c`: bit **`0x1000`** selects size helper `FUN_0096c810` vs `FUN_0096c730`; low nibble **`2`=cube**, **`4`=volume**, else 2D; RT path when `+0x14!=0` (+ optional depth `+0x18` via `FUN_0096bb20`).
   - Always **`IUnknown::Release` + null** on `+0x10`, `+0x14`, `+0x18` (vtbl[+8]).
4. **Classification:** worker.
5. **Callers (6 / 7 xrefs):** `FUN_0075eff0` (`GfxDevice_Reset`), `FUN_0096cad0`, `FUN_0096ca60`, `FUN_0096d100`, `FUN_0048ed90`, `FUN_009686e0`.
6. **Callees:** `FUN_0096c730`, `FUN_0096c810`, `FUN_0096bb20`, COM Release ×3.
7. **Name:** `EffTextureImpl_ReleaseGpu_Unaccount_Inferred` (Ghidra `FUN_0096c8e0`; **Inferred** structural). **Reject** scaffold `Named_CalleeOf_Named_gfxDevice_0096c8e0`.
8. **Decompile ≡ bytes** for CF/ABI/offsets/RET. Full hex: raw W38-AB append (378 B).  
   Reset call-site `0x0075f110`: `mov ecx,[esi+8]; cmp [ecx+0x30],0; call`.

### Gaps

- Product/MSVC demangle method English.  
- Product labels for flag `0x1000` / managed-vs-default counter banks.  
- Nested size-helper duals (`0096c730` / `0096c810` / `0096bb20`) and full create dual (`0096cad0`).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0096c8e0_EffTextureImpl_ReleaseGpu_Unaccount_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0096c8e0_EffTextureImpl_ReleaseGpu_Unaccount_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0096c8e0_FUN_0096c8e0.md` |
| Annotated | `docs/reconstruction/raw/aa_0096c8e0_FUN_0096c8e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/EffTextureImpl_ReleaseGpu_Unaccount_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0096c8e0.cpp` |
| Function | `docs/reconstruction/functions/aa_0096c8e0_FUN_0096c8e0.md` |
| Function named | `docs/reconstruction/functions/aa_0096c8e0_EffTextureImpl_ReleaseGpu_Unaccount_Inferred.md` |

---

## VA `0x0096e8e0` — sealed facts

1. **Body:** `0x0096e8e0`–`0x0096e9e4` exclusive (**260 B** / `0x104`; pad `CC` then `FUN_0096e9f0`).
2. **ABI:** stack **`factory*`**; returns **hr** in EAX; **`RET 0x04`** (`C2 04 00`). SEH `LAB_009b09a1`. **Not** thiscall.
3. **Semantics:** **effTextureFactory ReCreate** for DEFAULT-pool entries after device Reset:
   - Walk circular list head at `factory+0x8` (node value @ `+8` = `effTextureImpl*`).
   - For each impl with **`+0x30 == 0`** (same gate as Reset pre-release):
     - If `(flags@+0x2c & 0x3000)==0`: **`FUN_0096cad0`** thiscall recreate (create body starts with `FUN_0096c8e0`).
     - Else: **Release** interface at `impl+0x4c`.
     - On **`hr < 0`**: `FUN_0096a630` → format `"Failure on ReCreate() of effTextureImpl %s at <%x>"` → `vog_LogMessage(effTextureFactory.cpp, 0x159, 5, …)` → return hr.
4. **Classification:** worker.
5. **Callers (1):** `FUN_0075eff0` (`GfxDevice_Reset`) @ `0x0075f2c2` only — `push [device+0x754]; call`; fail plate `"Failed to Reset() device on Texture Factory"`.
6. **Callees:** `FUN_0096cad0`, vtbl[+8] on `+0x4c`, `FUN_0096a630`, `FUN_0076cec0`, `vog_LogMessage`, IAT `~basic_string`.
7. **Name:** `EffTextureFactory_ReCreateDefaultPool_Inferred` (Ghidra `FUN_0096e8e0`; **Inferred**). **Reject** bare scaffold `Named_effTextureFactory_0096e8e0` as sole product plate.
8. **Decompile ≡ bytes** for CF/ABI/list/RET. Full hex: raw W38-AB append (260 B).

### Gaps

- Product/MSVC demangle.  
- Product role of flag `0x3000` / interface at `+0x4c`.  
- Nested `FUN_0096cad0` dual (formal order from its call-site bytes).  
- Runtime under live device Reset.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0096e8e0_EffTextureFactory_ReCreateDefaultPool_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0096e8e0_EffTextureFactory_ReCreateDefaultPool_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0096e8e0_FUN_0096e8e0.md` |
| Annotated | `docs/reconstruction/raw/aa_0096e8e0_FUN_0096e8e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/EffTextureFactory_ReCreateDefaultPool_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0096e8e0.cpp` |
| Function | `docs/reconstruction/functions/aa_0096e8e0_FUN_0096e8e0.md` |
| Function named | `docs/reconstruction/functions/aa_0096e8e0_EffTextureFactory_ReCreateDefaultPool_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0096c8e0` | Port as **effTextureImpl GPU release + stats unaccount**: thiscall; if primary live, reverse `DAT_00d1f614` banks by type/flag; always Release+null `+0x10/+0x14/+0x18`. Do **not** treat as full dtor or as a gfxDevice method. Nested size helpers keep EDI/ESI custom ABI. |
| `0096e8e0` | Port as **factory ReCreate DEFAULT-pool list** after device Reset: stack factory **RET 4**; gate `+0x30==0`; recreate via create worker (which releases first); early-out on hr<0 with factory.cpp:0x159 plate. Do **not** merge with Reset pre-release walk or env-sector ReCreate helpers. |
| Pair with | `GfxDevice_Reset` (`0x0075eff0`); create `FUN_0096cad0`; size helpers `0096c730`/`0096c810`/`0096bb20`; IB/VB/Effect/BufferedView Reset siblings; stats host `DAT_00d1f614`. |

Shared context (not owned):

| VA | Role |
|---|---|
| `0x0075eff0` | `GfxDevice_Reset` — sole factory ReCreate caller; also pre-releases via `0096c8e0` |
| `0x0096cad0` | Create/recreate — first line is `FUN_0096c8e0` |
| `0x0096c730` / `0x0096c810` / `0x0096bb20` | Size estimators used for unaccount |
| `DAT_00d1f614` | Optional global texture mem/count stats host |

### Stats bank cheat-sheet (`DAT_00d1f614` offsets)

| Path | Count | Bytes |
|---|---|---|
| 2D | `+0x350` | `+0x398` |
| cube | `+0x358` | `+0x3a0` |
| volume | `+0x360` | `+0x3a8` |
| RT | `+0x364` | `+0x3ac` |
| depth | `+0x368` | `+0x3b0` |
| alt 2D (`0x1000`) | `+0x34c` | `+0x394` |
| alt cube | `+0x354` | `+0x39c` |
| alt volume | `+0x35c` | `+0x3a4` |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + xrefs (+ call-site bytes). **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only (W38-AB sections + full hex).  
- No invented product plates; structural `_Inferred` names only.  
- Rejected gfxDevice-callee and bare factory scaffold plates as sole names.  
- Avoided bare `undefined4` in cleans (`uint8_t` / explicit partial structs).
