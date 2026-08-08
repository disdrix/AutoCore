# Dual A/B report — WQ9R-F OWN `0x005194f0` + `0x005197b0` (WQ-009 residual)

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual **WQ9R-F**  
**Scope:** OWN ONLY VAs `0x005194f0`, `0x005197b0`. Trio + clean meaningful names + dual A/B.  
**Work item:** **WQ-009** residual skill-bank / cast residual callees (priority 93).  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / VERIFICATION_MATRIX / NAMING_REGISTRY / systems maps / parent ledgers.  
**Ghidra:** `batch_decompile` / `decompile_function` + `read_memory` + `analyze_function_complete` + callers/xrefs + call-site `get_assembly_context` + callee decompile. Capstone linear decode of owned body ranges for ABI. **No** `disassemble_bytes`. **No** Launcher.

**Programs open:** `autoassault.exe` only (dual A/B = fidelity vs adversarial reviews).

---

## Verdict

| Unit | Canonical | Verdict |
|------|-----------|---------|
| `aa_005194f0` | `Gfx_BindMatDiffuseAmbientEmissive_Inferred` | **accept-with-gaps** |
| `aa_005197b0` | `EnsureFactionsLookupLoaded` | **accept-with-gaps** |

Path A (fidelity): **accept-with-gaps** on both  
Path B (adversarial): **accept-with-gaps** on CF + ABI + string/xpath evidence; overclaims on product English / skill-bank domain for `005194f0` **rejected**

Never claim runtime **Confirmed** (no Launcher). Terminal coverage: **false**.

---

## Sealed facts

### Shared / partition note

1. Co-owned **only** by WQ9R-F partition assignment (adjacent residual VAs in the `0x00519xxx` bring-up / graphics band). **Not** a single product feature pair.
2. Live decompile **≡** 2026-07-23 raw scaffold bodies for both VAs.
3. Sibling residual (not owned): material apply caller `0x0051b310` (WQ9R-I); faction lookup `0x0051a120` (WQ9R-G); paint ensure `0x00519a30`; DB loader `0x007ce550` (`//tFactions/row`).

### `0x005194f0` — bind MatDiffuse / MatAmbient / MatEmissive triples

1. **Body:** `0x005194f0`–`0x00519657` exclusive (**359 B** / `0x167`; pad `CC`).
2. **ABI (bytes win):** **cdecl**, **two stack args**, **void** (`ADD ESP,8` at both call sites; final `RET`). Decompiler `undefined FUN_(void)` incomplete.
3. **Args:**
   - `shaderHost*` — dword vector at **`+0xc0` / `+0xc4`** (count = `(end-begin)>>2`).
   - `colorVec*` — float4 vector object with **begin `@+4`**, **end `@+8`**, stride **`0x10`** (count = `(end-begin)>>4`).
4. **Invariant:** `shaderCount * 3 == colorCount`; else `FUN_007a4480(0, "VOG_DEBUG_STOP")` (`0x00a15844`) and continue.
5. **Loop:** for each shader index `i`:
   - Require color slots through index `2 + 3*i` (exclusive bound via running `slotNeed`).
   - `effectThis = *(shaderHost+0xc0)[i] + 0x20`
   - `FUN_009700f0` thiscall: **ECX=`effectThis`**, push **float4\***, push name — **three** times:
     - `"MatDiffuse"` @ `0x00a2f8cc` → color `begin + i*0x30 + 0x00`
     - `"MatAmbient"` @ `0x00a2f8c0` → `begin + i*0x30 + 0x10`
     - `"MatEmissive"` @ `0x00a2f8b4` → `begin + i*0x30 + 0x20`
6. **Epilogue:** build stack float4 **`(0,0,0,1.0)`** (`g_flOne` @ `0x00a0f2a0` = `0x3f800000`); **`FUN_0051def0(colorVec, 0)`** resizes color vector to **length 0** (clear after bind).
7. **Callers (2):** `FUN_0051b310` @ `0051b345` (vtbl `+0x1cc` → `*(result+8)` host; colors at `this+0x144`); `FUN_004c5510` @ `004c5553` (host `*(this-0x27c)`, colors `this-0x20c`).
8. **Name:** `Gfx_BindMatDiffuseAmbientEmissive_Inferred` (**Inferred**). **Reject** scaffold `Named_VOG_DEBUG_STOP_005194f0`. Not a skill-bank cast unit (material/FX bind).
9. **Decompile hazards:** binder shown as `FUN_009700f0("Mat…", ptr)` without ECX `entry+0x20`; `FUN_0051def0(0,0,0,0,g_flOne)` hides **this=colorVec / size=0**.

### `0x005197b0` — ensure-load `tFactions` into global CNDHash

1. **Body:** `0x005197b0`–`0x00519a22` exclusive (**626 B** / `0x272`; pad `CC`).
2. **ABI:** **cdecl / no stack args**, void (call sites bare `CALL`; final `RET` after SEH restore).
3. **Bring-up sequence:**
   1. SEH frame (`LAB_009a3683`).
   2. **`CNDHash_Recreate`** `FUN_0051d290(4)` with **ECX = `0x00b04314`** (power **4** → 16 buckets).
   3. Zero temp vector `{begin,end,cap}`.
   4. **DB enter** `FUN_007e1d80` ECX=`*[0x00b0469c]`.
   5. **Load** `FUN_007ce550` (callee string **`//tFactions/row`**) → fills temp vector of **stride `0xc4`** rows.
   6. **DB leave** `FUN_007b7df0` ECX=`*[0x00b0469c]`.
   7. If status `< 0`: `FUN_007a4480(0, "VOG_DEBUG_STOP")`.
4. **Per-row (source `0xc4`):**
   - `id` @ `+0x00` (u32)
   - wide name A @ `+0x04` (null-checked; decompiler `== 0x40` is **false** — tests pointer at entry+4)
   - wide name B @ `+0x44`
   - Advance cursor by **`0x62` wchar = `0xc4` bytes**
5. **Materialize heap record `operator_new(100)` / `0x64`:**
   - `+0x00` id
   - `+0x04` MBCS string A (`WideCharToMultiByte` via `PTR_FUN_00af8c9c` code page; SSO buffer 128 or `malloc`)
   - `+0x24` MBCS string B
6. **Insert:** `FUN_0051e5d0` thiscall **ECX=`0x00b04314`**, key=`id`, value=`record*`, flag=`0` (CNDHash insert; duplicate → fail path residual).
7. **End:** when index ≥ count, free temp vector (`operator_delete` — decompiler **false** “does not return”); SEH restore; return. Empty begin → early return.
8. **Fail paths:** OOM → `FUN_004048e0(0x8007000e)`; `WideCharToMultiByte==0` → `FUN_004048c0` (Win32 last-error HRESULT throw).
9. **Callers (2):**
   - `FUN_0094a6a0` InitInstance @ `0094afc2` (boot table pack with XP/credits/paint ensures; gated by `client+0x31f5==0`).
   - `FUN_0051a120` @ `0051a132` when **`DAT_00b04320 == 0`** (lazy ensure before hash lookup).
10. **Name:** `EnsureFactionsLookupLoaded` (table name sealed via loader xpath `//tFactions/row`). **Reject** scaffold `Named_VOG_DEBUG_STOP_005197b0`.

---

## Gaps (both)

1. Product/PDB English method names; RTTI for shader host / color-vector owner types.
2. Full dual of binder `FUN_009700f0`, resize `FUN_0051def0`, loader `FUN_007ce550`, hash insert `FUN_0051e5d0` (summarized only).
3. Exact field English for faction wide strings A/B (display vs internal).
4. Whether hash count/`DAT_00b04320` is written only by insert path (outside this dual except Recreate zeroing).
5. Runtime / CE / bit-exact image verification.
6. `005194f0` domain is **graphics material bind**, not skill-bank cast — residual only by address partition under WQ-009 wave.

---

## Files

| Kind | `0x005194f0` | `0x005197b0` |
|------|--------------|--------------|
| Review A | `docs/reconstruction/reviews/A_aa_005194f0_Gfx_BindMatDiffuseAmbientEmissive_Inferred.md` | `…/A_aa_005197b0_EnsureFactionsLookupLoaded.md` |
| Review B | `docs/reconstruction/reviews/B_aa_005194f0_Gfx_BindMatDiffuseAmbientEmissive_Inferred.md` | `…/B_aa_005197b0_EnsureFactionsLookupLoaded.md` |
| Function named | `docs/reconstruction/functions/aa_005194f0_Gfx_BindMatDiffuseAmbientEmissive_Inferred.md` | `…/aa_005197b0_EnsureFactionsLookupLoaded.md` |
| Function FUN | `docs/reconstruction/functions/aa_005194f0_FUN_005194f0.md` | `…/aa_005197b0_FUN_005197b0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Gfx_BindMatDiffuseAmbientEmissive_Inferred.cpp` | `…/EnsureFactionsLookupLoaded.cpp` |
| Scaffold clean | `…/FUN_005194f0.cpp` | `…/FUN_005197b0.cpp` |
| Raw | `docs/reconstruction/raw/aa_005194f0_FUN_005194f0.md` | `…/aa_005197b0_FUN_005197b0.md` |
| Annotated | `docs/reconstruction/raw/aa_005194f0_FUN_005194f0.annotated.md` | `…/aa_005197b0_FUN_005197b0.annotated.md` |
| This report | `docs/agents/task-dual-ab-005194f0-005197b0-wq9rf-report.md` | |

Related (not owned): `FUN_0051b310` / `FUN_0051a120` / `FUN_007ce550` / `FUN_0051e5d0` / `FUN_009700f0` / `FUN_0051def0` / `FUN_004c5510` / InitInstance `FUN_0094a6a0`.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`.

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `005194f0` | When applying per-object material color banks: **three** float4 slots per shader entry (D/A/E) at stride **`0x30`**, bound by fixed names `MatDiffuse`/`MatAmbient`/`MatEmissive` through effect object **`entry+0x20`**. Assert `shaderN*3 == colorN`. **Clear** the color vector after bind (`resize(0)`). |
| `005197b0` | Client **faction id → {id, nameA, nameB}** hash must load from **`tFactions`** (`//tFactions/row`) into CNDHash @ **`0x00b04314`** before lookups (`FUN_0051a120`). Boot path always; lazy path when count/flag `DAT_00b04320==0`. Rows: id + two wide strings → MBCS heap records **0x64**. |
| Shared | Unrelated systems; do not merge ABIs. |

---

## Parent merge checklist (for integrator — not done here)

- [ ] VERIFICATION_MATRIX: `aa_005194f0`, `aa_005197b0`
- [ ] NAMING_REGISTRY + rename history for both canonical names
- [ ] `systems/skills-abilities.md` residual note (and/or graphics / factions note for true domains)
- [ ] WORK_QUEUE / RESUME / CHANGE_LOG / progress.json dual count

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.
- Seal tools: decompile + read_memory + function/xref/call-site helpers. **No** `disassemble_bytes`.
- Dual A (fidelity) + B (adversarial) filed per VA.
- Scaffold raw bodies preserved; WQ9R-F re-verify **appended** only.
- No invented product names beyond string/xpath evidence; `_Inferred` on material binder.
- Terminal coverage: **false** always.
