# Dual A/B report — W30-F OWN-ONLY (`0x004cda90`, `0x0051b8a0`)

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W30-F  
**Scope:** VAs `0x004cda90`, `0x0051b8a0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / parent ledgers.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `get_function_by_address` + `read_memory` (+ callers/callees/xrefs). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave30_partition_map.md` → **W30-F**.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004cda90` Client_InitPalantirViewBundle_Inferred | **accept-with-gaps** — three-slot factory CF/ABI/sizes/floats/sole caller sealed; product English open |
| `aa_0051b8a0` ObjectCsList_ClearDestroy_Inferred | **accept-with-gaps** — CS drain/throw/node layout/SharedBase+0xB0 ownership sealed; product English open |

---

## VA `0x004cda90` — sealed facts

1. **Body:** `0x004cda90`–`0x004cdc34` exclusive (**420 B** / `0x1A4`). Final **`C3`** after `ADD ESP,0x10`; pad `CC`.
2. **ABI:** **`__thiscall`/`__fastcall`**; ECX=`parent*`; no stack formals; returns **1** (`B0 01`); bare RET.
3. **Semantics:** factory on large client/core parent:
   - `operator_new(0x150)` + `FUN_0075ceb0` (GfxView / `gfxView.cpp`) → `parent+0xE890`.
   - `FUN_0075b3b0(0.5f)` → view`+0xF0`; far **1000.f** (`DAT_00a0f520`) or **500.f** (`DAT_00aaaa90`) by `parent+0x7d` → view`+0xF4`.
   - Optional Palantir desktop at `+0xE89C`: wire view, vcall `+0xC`, stamp `DAT_00afdef0` (`0xFF000000`).
   - `operator_new(0x198)` + `FUN_00492dd0(0, parent)` → `+0xE894`.
   - `operator_new(0xC8)` + `Class_009c7a1c_Ctor` (`FUN_00496f70`, W29-G) → `+0xE898`.
   - Cross-wire `view+4 = env`, `env+0xC0 = view`; `FUN_0048fc90(env, 1)`.
   - Publish `*(env+4)` into `DAT_00d1a54c` with `FUN_0074e200` disable/enable.
4. **Classification:** worker (factory / init method).
5. **Callers (1):** `FUN_00948530` @ `0x00948aad` (window init; `"Could not get Palantir desktop window."`).
6. **Xrefs:** 1.
7. **Related:** `Class_009c7a1c_Ctor` W29-G (this is its sole factory); GfxView ctor `FUN_0075ceb0`.
8. **Name:** `Client_InitPalantirViewBundle_Inferred` (Ghidra `FUN_004cda90`). Product demangle open.
9. **Decompile ≡ raw CF**; ABI/alloc sizes/floats sealed by `read_memory`.

### Gaps

- Product English / MSVC demangle for parent + env (`FUN_00492dd0`) types.  
- Labels for `+0x7d`, `DAT_00d1a54c`, `FUN_0074e200`.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004cda90_Client_InitPalantirViewBundle_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004cda90_Client_InitPalantirViewBundle_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004cda90_FUN_004cda90.md` |
| Annotated | `docs/reconstruction/raw/aa_004cda90_FUN_004cda90.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_InitPalantirViewBundle_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004cda90.cpp` |
| Function | `docs/reconstruction/functions/aa_004cda90_FUN_004cda90.md` |
| Function named | `docs/reconstruction/functions/aa_004cda90_Client_InitPalantirViewBundle_Inferred.md` |

---

## VA `0x0051b8a0` — sealed facts

1. **Body:** `0x0051b8a0`–`0x0051b99c` exclusive (**252 B** / `0xFC`); pad `CC`.
2. **ABI:** **`__thiscall`/`__fastcall`**; ECX=`list*`; no stack formals; void; frame **`C3` RET**.
3. **Semantics:** CS-protected list clear/destroy for Object SharedBase helper (`sizeof 0x2C`, vtbl `PTR_FUN_009ce154`):
   - `EnterCriticalSection(list+4)`.
   - If flag `list+0x28 ≠ 0`: Leave + throw **`0x80070005`** (`E_ACCESSDENIED`).
   - Drain head `list+0x1C`: next @ `node+8`, clear `node+4`, scalar-delete `vtbl[0](1)`.
   - Zero `+0x24/+0x20/+0x1C`; LeaveCS.
   - Does **not** free list object / DeleteCS (that is `FUN_0051d0e0` / `FUN_0051bf10`).
4. **Classification:** worker (list clear-destroy).
5. **Callers:** `Object_SharedBase_Dtor` `FUN_00518ec0` @ `0x00518f6e` (`mov ecx,[esi+0xB0]`); CODE @ `0x00514d30` (orphan body `0x00514d10`, same ECX, `ret 4`).
6. **Ctor context:** helper allocated in `Object_SharedBase_Ctor` (`new(0x2C)` + `InitializeCriticalSection` → `core+0xB0`).
7. **Name:** `ObjectCsList_ClearDestroy_Inferred` (Ghidra `FUN_0051b8a0`). Sibling family: `List_ClearDestroy` `0x0040dc40` (next@+0x10). Near twin: `FUN_0051bc90` (no `node+4=0`).
8. **Decompile ≡ raw CF**; CS/flag/throw/next sealed by `read_memory`.

### Gaps

- Product English / MSVC demangle for CS-list class.  
- Field English for `+0x20/+0x24`.  
- Node payload product type.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0051b8a0_ObjectCsList_ClearDestroy_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0051b8a0_ObjectCsList_ClearDestroy_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0051b8a0_FUN_0051b8a0.md` |
| Annotated | `docs/reconstruction/raw/aa_0051b8a0_FUN_0051b8a0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/ObjectCsList_ClearDestroy_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0051b8a0.cpp` |
| Function | `docs/reconstruction/functions/aa_0051b8a0_FUN_0051b8a0.md` |
| Function named | `docs/reconstruction/functions/aa_0051b8a0_ObjectCsList_ClearDestroy_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004cda90` | Port as client/core init after window create: three owned slots at `+0xE890/+0xE894/+0xE898`; GfxView first with near/far; optional desktop wire; cross-link before env phases; return 1. Pair with `Class_009c7a1c_Ctor` / GfxView ctor as separate units. |
| `0051b8a0` | Port as **list method** on SharedBase helper (`core+0xB0`), not on core this. Drain nodes under CS; throw if traversal flag; do **not** delete list/CS here. Call before scalar-delete of helper in SharedBase dtor. Keep distinct from `List_ClearDestroy` (`0040dc40`) and `ThreadSafeObjectList_Dtor`. |
| Pair with | `Class_009c7a1c_Ctor` (`0x00496f70`), `Object_SharedBase_Ctor`/`Dtor` (`0x00518940`/`0x00518ec0`), `List_ClearDestroy` (`0x0040dc40`), GfxView ctor `FUN_0075ceb0`. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product plates; `_Inferred` structural names only (Palantir/GfxView path evidence; ObjectCsList from SharedBase ownership + layout).

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
