# Dual A/B report — W20-I OWN `aa_00542790` + `aa_005408f0`

**Date:** 2026-07-29  
**Scope:** OWN ONLY VAs `0x00542790`, `0x005408f0`. Dual A/B + artifacts.  
**Agent:** W20-I  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledgers.  
**Ghidra:** `decompile_function` + `read_memory` only. No `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdicts

| Unit | Verdict |
|------|---------|
| `aa_00542790` FxCache_ApplyWithNfxEnsure | **accept-with-gaps** — SEH thiscall `ret 0x1c`, gate, nfx master ensure, vtbl apply / transform fallback sealed |
| `aa_005408f0` FxCache_EnsureMasterAndResolve | **accept-with-gaps** — thiscall `ret 0x0c`, inline hash, master gate + SkillDef→LoadMaster, resolve sealed; 004a16d0 this=value+4 |

---

## Sealed facts — `aa_00542790` (0x00542790)

1. **ABI:** `__thiscall` — **ECX = host\*** (`hash @ +0xf0c`), **7 stack args**, **`ret 0x1c`**.

2. **Body:** `0x00542790`–`0x00542a8c` (**764 bytes**); MSVC SEH (`LAB_009a40df`).

3. **Gate:** `*(DAT_00d1f050 + 0x6c) == 0` → **return 0**.

4. **Algorithm:** snapshot transforms (`param_6/7 +0x160` or `DAT_009d00a8`) → `CNDHash_LookupByKey` → if `value+0x0a==0` SkillDef name + append **`_nfx.xml`** (`0x009ca184`) + open + strip + `FxMaster_LoadMasterFromXML` → resource open → `FUN_004a16d0` → entity **`vtbl[+0x238]`** or `FUN_00545d70` fallback → return **1/0**.

5. **Name:** `FxCache_ApplyWithNfxEnsure` — role-sealed **INFERRED**. Ghidra: `FUN_00542790`.

6. **Callers:** `FUN_00512d10`, `FUN_005c74e0` (`CLoadNode::_initSpecialFX`).

### Gaps (`00542790`)

1. Product/PDB English (host, vtbl method, transform fields).  
2. Duals of path/resource helpers (not OWN).  
3. Runtime / bit-exact / differential — open.

---

## Sealed facts — `aa_005408f0` (0x005408f0)

1. **ABI:** `__thiscall` — **ECX = host\***, **3 stack args** `(key, eventA, eventB)`, **`ret 0x0c`**.

2. **Body:** `0x005408f0`–`0x005409b1` (**193 bytes**).

3. **Algorithm:** **inline** CNDHash walk on `*(this+0xf0c)` (not a call) → miss 0 → if `value+0x0a==0` SkillDefMap find + `FUN_00540090` + `FxMaster_LoadMasterFromXML` → `FUN_004a16d0`.

4. **Decompiler correction:** `FUN_004a16d0` **this** is **`value+4`** (`lea ecx,[esi+4]`), not `eventA`.

5. **Name:** `FxCache_EnsureMasterAndResolve` — role-sealed **INFERRED**. Ghidra: `FUN_005408f0`.

6. **Callers:** `FUN_00512d10`, `FUN_00578b30`.

### Gaps (`005408f0`)

1. Product/PDB English.  
2. Dual of `FUN_004a16d0` / host type name.  
3. Runtime / bit-exact / differential — open.

---

## Files

### `aa_00542790`

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00542790_FxCache_ApplyWithNfxEnsure.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00542790_FxCache_ApplyWithNfxEnsure.md` |
| Function record | `docs/reconstruction/functions/aa_00542790_FxCache_ApplyWithNfxEnsure.md` |
| Scaffold record | `docs/reconstruction/functions/aa_00542790_FUN_00542790.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FxCache_ApplyWithNfxEnsure.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_00542790.cpp` |
| Raw (authoritative + re-verify) | `docs/reconstruction/raw/aa_00542790_FUN_00542790.md` |
| Annotated | `docs/reconstruction/raw/aa_00542790_FUN_00542790.annotated.md` |

### `aa_005408f0`

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_005408f0_FxCache_EnsureMasterAndResolve.md` |
| Review B | `docs/reconstruction/reviews/B_aa_005408f0_FxCache_EnsureMasterAndResolve.md` |
| Function record | `docs/reconstruction/functions/aa_005408f0_FxCache_EnsureMasterAndResolve.md` |
| Scaffold record | `docs/reconstruction/functions/aa_005408f0_FUN_005408f0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FxCache_EnsureMasterAndResolve.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_005408f0.cpp` |
| Raw (authoritative + re-verify) | `docs/reconstruction/raw/aa_005408f0_FUN_005408f0.md` |
| Annotated | `docs/reconstruction/raw/aa_005408f0_FUN_005408f0.annotated.md` |

### Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00542790-005408f0-w20i-report.md` |

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`

---

## AutoCore impact

- **`FxCache_EnsureMasterAndResolve`:** client ensure/lookup only. Ports that need “is FX ready + get handle” without entity attach use this shape. Do **not** pass event id as FxMaster `this`; use cache value `+4`. LoadMaster failure does **not** abort resolve in retail CF.
- **`FxCache_ApplyWithNfxEnsure`:** full attach path for live resource subsystem + optional entity vtbl. Do **not** omit `DAT_00d1f050+0x6c` gate. Prefer structural separation from the lighter ensure path (as `FUN_00512d10` already branches).
- Both share SkillDefMap + `FxMaster_LoadMasterFromXML` + host hash `+0xf0c` family with other skill/FX duals — keep map header vs category-cooldown map distinction from `SkillDefMap_GetGlobal` dual.

---

## Tools used

- `ghidra-mcp__decompile_function` (owned VAs + callers/callees context)
- `ghidra-mcp__read_memory` (entry/exit/constants)
- `ghidra-mcp__get_function_by_address`
- `ghidra-mcp__get_function_callers` / `analyze_function_complete`
- No `disassemble_bytes`. No Launcher. No parent ledger edits.
