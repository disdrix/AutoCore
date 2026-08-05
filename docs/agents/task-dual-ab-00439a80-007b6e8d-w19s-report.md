# Dual A/B report — W19-S OWN-ONLY (`0x00439a80`, `0x007b6e8d`)

**Date:** 2026-07-29  
**Agent:** W19-S OWN-ONLY  
**Scope:** OWN ONLY VAs `0x00439a80`, `0x007b6e8d`. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / other parent ledgers.  
**Ghidra:** `decompile_function` + `read_memory` only. No `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict per VA

| Unit | Verdict |
|------|---------|
| `aa_00439a80` Client_ApplyPairRelativeTransform | **accept-with-gaps** — **EDI pair-ctx ABI, 8 callers, quat inverse + Mat4 project sealed; vtbl/product English open** |
| `aa_007b6e8d` NDXml_FinishLoadResult | **accept** — **outlined load epilogue; HRESULT log arg byte-sealed; VARIANT_BOOL + parseError + ret 8 sealed** |

---

## `aa_00439a80` — Client_ApplyPairRelativeTransform

### Sealed facts

1. **ABI:** EDI = 4-pointer pair context (`+0` objA*, `+4` optA*, `+8` objB*, `+0xc` optB*). Bare **`ret`** (`c3`). Body `0x00439a80`–`0x00439da3`. Frame: 16-align + `sub esp, 0x328`.

2. **Prologue bytes:** `mov ebx,[edi+0xc]`; `mov esi,[edi+4]` match decomp `unaff_EDI[3]` / `[1]`.

3. **CF:** dual optional-helper arms (null → vtbl+8 with id `-1`); objB seed `(0,0,0,1)` + vtbl `+0x14/+0x18/+0x34`; quaternion `|q|²` then inverse-conjugate when not near 0; `FUN_00972e50`; `FUN_0076f6e0` (`Math_Mat4TransformPoint3_Project`); compose; objB `vtbl+0x10(3,…)` ×2 + commit.

4. **Constants:** `0x00a240ec` = **1e-6f**; `0x00aaa640` = **-1e-6f**.

5. **Callers (8):** TeleportIn ctor, Respawn Update, `FUN_0096dc80`, `FUN_0096dc50`, `FUN_00855ff0`, `FUN_009784f0`, `FUN_00764180`, site `0x007644ba`. Parent-seed TeleportIn-only name **incomplete**.

6. **Name:** structural `Client_ApplyPairRelativeTransform`.

### Gaps

1. Product/PDB symbol.  
2. Vtbl slot English / exact C++ types.  
3. Sibling callee product names (`72cc0`/`72e50`/`73030`/`40cf90`/`40d1a0`).  
4. Runtime / bit-exact / differential — open.

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00439a80_Client_ApplyPairRelativeTransform.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00439a80_Client_ApplyPairRelativeTransform.md` |
| Function record | `docs/reconstruction/functions/aa_00439a80_Client_ApplyPairRelativeTransform.md` |
| Scaffold record | `docs/reconstruction/functions/aa_00439a80_FUN_00439a80.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_ApplyPairRelativeTransform.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_00439a80.cpp` |
| Raw | `docs/reconstruction/raw/aa_00439a80_FUN_00439a80.md` |
| Annotated | `docs/reconstruction/raw/aa_00439a80_FUN_00439a80.annotated.md` |

---

## `aa_007b6e8d` — NDXml_FinishLoadResult

### Sealed facts

1. **Role:** outlined epilogue of `NDXml_LoadDocumentFromPath` — sole CODE xref CALL `@ 0x007b6e6f`. Body `0x007b6e8d`–`0x007b6f81`.

2. **ABI:** uses **caller EBP**; **ESI = HRESULT**; returns bool in AL; epilogue **`ret 8`** (cleans parent thiscall stack args).

3. **Fail log:** if `ESI < 0`, log `"Failed to load XML file %s, failed with code %d"` with path `[ebp+0xc]` **and ESI** — decompiler omitted `push esi`; **sealed by entry bytes**.

4. **Parse path:** if `VARIANT_BOOL [ebp-0x28] != -1`: doc `vtbl+0xf0` `get_parseError`; dual-interface err `+0x20` url, `+0x24` reason, `+0x2c` line, `+0x30` linepos; log; `SysFreeString`×2; `Release`; return false.

5. **Success path:** return `ESI >= 0` (`setge al`). Both arms restore `ExceptionList` from `[ebp-0xc]`.

6. **Name:** structural `NDXml_FinishLoadResult`.

### Gaps

1. Product/PDB symbol (may be compiler-outlined tail of LoadDocumentFromPath).  
2. Runtime / differential — open.

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_007b6e8d_NDXml_FinishLoadResult.md` |
| Review B | `docs/reconstruction/reviews/B_aa_007b6e8d_NDXml_FinishLoadResult.md` |
| Function record | `docs/reconstruction/functions/aa_007b6e8d_NDXml_FinishLoadResult.md` |
| Scaffold record | `docs/reconstruction/functions/aa_007b6e8d_FUN_007b6e8d.md` |
| Clean | `docs/reconstruction/reconstructed-exact/NDXml_FinishLoadResult.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_007b6e8d.cpp` |
| Raw | `docs/reconstruction/raw/aa_007b6e8d_FUN_007b6e8d.md` |
| Annotated | `docs/reconstruction/raw/aa_007b6e8d_FUN_007b6e8d.annotated.md` |

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`

---

## AutoCore impact

### Pair relative transform (`0x00439a80`)

- Port as **EDI pair-context** helper, not a TeleportIn exclusive.
- Preserve **null-helper arms**, **quat inverse gate**, and **Math_Mat4TransformPoint3_Project** step.
- Do not invent product hardpoint names without further type recovery.

### XML finish load (`0x007b6e8d`)

- Keep as **shared load epilogue** (or inline at end of LoadDocumentFromPath with identical contract).
- Fail logs must include **HRESULT**; parse dumps only when **VARIANT_BOOL ≠ TRUE**.
- Return path must clean **8 stack bytes** to match retail grand-caller ABI.
