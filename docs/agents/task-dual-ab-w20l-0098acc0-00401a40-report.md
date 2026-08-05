# Dual A/B report — W20-L OWN-ONLY (`0x0098acc0`, `0x00401a40`)

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W20-L  
**Workspace:** `C:\Users\josh\Documents\GitHub\AutoCore`  
**Module:** `autoassault.exe` base `0x400000`  
**Owned VAs:** `0x0098acc0`, `0x00401a40` **only**  
**Tools:** Ghidra `decompile_function` + `read_memory` (+ function meta / callers / callees / RTTI strings). **No** `disassemble_bytes`. **No** Launcher. **No** parent ledger edits (`ACTIVE_WORK` / `CHANGE_LOG` / `COVERAGE_LEDGER` / `WORK_QUEUE` / `RESUME`).

---

## Verdicts

| VA | Canonical name | Verdict |
|---|---|---|
| `0x0098acc0` | `NDAssetImage_FlipHorizontal` | **accept-with-gaps** |
| `0x00401a40` | `Std_LengthError_CtorFromString` | **accept** |

---

## VA `0x0098acc0` — NDAssetImage_FlipHorizontal

### Sealed facts

1. **ABI:** **this in EDI**; no stack formals; frame `SUB ESP,0x10`; return **AL** 0/1; plain **`RET` (`C3`)**. Body `0x0098acc0`–`0x0098ae77`.
2. **Role:** **Horizontal flip** of `NDAssetImage` for TGA image-descriptor **bit4** (right→left). Sibling of `NDAssetImage_FlipVertical` `0x004332e0` (bit5 + 32bpp at LoadTGA).
3. **CF:**
   ```
   if this+4 == 0: return 0
   tmp = operator_new(0x1b8); if !tmp: return 0
   tmp.vtbl = PTR_FUN_00a9bcac
   FUN_004320d0(); FUN_00432260(this,0,0,1)
   bpp = *(short*)(this+0x16)
   lastPxOff = ((bpp==0x18)*2 + 1) * (width - 1)
   reverse-copy this+0x34 → tmp+0x34  (8: bytes; 24: RGB triplets; else helpers)
   FUN_00433390(); FUN_00432580(this); destroy tmp; return 1
   ```
4. **Fields (Confirmed):** `+0x04` gate; `+0x0c` width px; `+0x10` height; `+0x16` bpp; `+0x30` pitch; `+0x34` raw pixels; `+0x1b0` working (post helpers).
5. **Caller:** sole direct — `NDAssetImage_LoadTGA` `0x004347d0`.
6. **Live decompile ≡** 2026-07-23 raw (no CF delta).
7. **Rename:** scaffold `FUN_0098acc0` → `NDAssetImage_FlipHorizontal`.

### Gaps

1. Product English for `FUN_004320d0` / `FUN_00432260` / `FUN_00433390` / `FUN_00432580` / pixel helpers (not OWN).  
2. Dual-buffer product model (`+0x34` vs `+0x1b0`).  
3. Runtime TGA bit4 golden.  
4. PDB method symbol.

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_0098acc0_NDAssetImage_FlipHorizontal.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0098acc0_NDAssetImage_FlipHorizontal.md` |
| Function record | `docs/reconstruction/functions/aa_0098acc0_NDAssetImage_FlipHorizontal.md` |
| Scaffold record | `docs/reconstruction/functions/aa_0098acc0_FUN_0098acc0.md` (superseded) |
| Clean | `docs/reconstruction/reconstructed-exact/NDAssetImage_FlipHorizontal.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_0098acc0.cpp` |
| Raw named | `docs/reconstruction/raw/aa_0098acc0_NDAssetImage_FlipHorizontal.md` |
| Annotated named | `docs/reconstruction/raw/aa_0098acc0_NDAssetImage_FlipHorizontal.annotated.md` |
| Raw scaffold + re-verify append | `docs/reconstruction/raw/aa_0098acc0_FUN_0098acc0.md` |

**Sibling context (not owned):** `NDAssetImage_LoadTGA` `0x004347d0`; `NDAssetImage_FlipVertical` `0x004332e0`; helpers `FUN_004320d0` / `FUN_00432260` / `FUN_00433390` / `FUN_00432580`.

---

## VA `0x00401a40` — Std_LengthError_CtorFromString

### Sealed facts

1. **ABI:** **`__thiscall`** — ECX = `this`, stack = `const std::string*`; return `this`; **`RET 4`**. Body `0x00401a40`–`0x00401a90`.
2. **Role:** **`std::length_error::length_error(std::string const&)`** — MSVC STL length-overflow exception ctor.
3. **CF:** SEH install → `FUN_00401aa0(msg)` (logic_error + embed string @ `this+0xc`, vtbl `009c7628`) → set vtbl **`PTR_FUN_009c7634`** → return this.
4. **RTTI (Confirmed):** `.?AVlength_error@std@@` @ `0x00af8bf0`; hierarchy with `.?AVlogic_error@std@@`, `.?AVexception@@`.
5. **Throw pairing:** parents `_CxxThrowException(..., &DAT_00acc388)`; object size **0x28**.
6. **Callers:** 50+ including `StdVector_ThrowTooLong` `0x004540b0` (`"vector<T> too long"`), map/set `"map/set<T> too long"` paths.
7. **Live decompile ≡** 2026-07-23 raw (no CF delta).
8. **Rename:** scaffold `FUN_00401a40`; **reject** false Auth-seed `Named_CalleeOf_Named_CalleeOf_Auth_AuthServer_00401a40`.

### Gaps

1. Full vtable slot English at `009c7634`.  
2. Runtime throw golden (optional).  
3. CRT string layout version detail.

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00401a40_Std_LengthError_CtorFromString.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00401a40_Std_LengthError_CtorFromString.md` |
| Function record | `docs/reconstruction/functions/aa_00401a40_Std_LengthError_CtorFromString.md` |
| Scaffold record | `docs/reconstruction/functions/aa_00401a40_FUN_00401a40.md` (superseded) |
| Clean | `docs/reconstruction/reconstructed-exact/Std_LengthError_CtorFromString.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_00401a40.cpp` |
| False-name plate | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_CalleeOf_Auth_AuthServer_00401a40.cpp` (superseded redirect) |
| Raw named | `docs/reconstruction/raw/aa_00401a40_Std_LengthError_CtorFromString.md` |
| Annotated named | `docs/reconstruction/raw/aa_00401a40_Std_LengthError_CtorFromString.annotated.md` |
| Raw scaffold + re-verify append | `docs/reconstruction/raw/aa_00401a40_FUN_00401a40.md` |

**Sibling context (not owned):** `FUN_00401aa0` logic_error base; `FUN_00401880` dtor; `StdVector_ThrowTooLong` `0x004540b0`.

---

## Dual A/B summary

| VA | Review A | Review B | Agreement |
|---|---|---|---|
| `0x0098acc0` | accept-with-gaps | accept-with-gaps | Horizontal CF/ABI/bpp sealed; reject vertical / ECX-this; dual-buffer residual |
| `0x00401a40` | accept | accept | length_error RTTI/ABI/CF sealed; reject Auth misname / runtime_error |

---

## Evidence tools used (both VAs)

- `ghidra-mcp__decompile_function`
- `ghidra-mcp__read_memory` (entry + tails; RTTI / ThrowInfo cluster)
- `ghidra-mcp__get_function_by_address` (body bounds)
- `ghidra-mcp__get_function_callers` / `get_function_callees`
- `ghidra-mcp__list_strings` (length_error / logic_error RTTI)
- Context decompiles of callers / helpers (**read-only**, no writes outside owned VAs)

**Not used:** `disassemble_bytes`, Launcher, parent ledgers.

---

## AutoCore impact

- **TGA / map assets:** when loading right-origin TGA (descriptor bit4), apply **horizontal** flip of raw pixels (8bpp byte reverse, 24bpp triplet reverse, other via helpers) then install into `NDAssetImage`. Pair with existing **FlipVertical** only for top-origin **32bpp** as LoadTGA does. Field map: width `+0xc`, pitch `+0x30`, raw `+0x34` (not FlipVertical’s pitch-at-`+0xc` alone).
- **Containers / STL ports:** max-size overflow should throw a **length_error-class** managed exception (plate strings `"vector<T> too long"` / `"map/set<T> too long"`). Do not invent Auth-specific semantics for `0x00401a40`.

---

## This report

`docs/agents/task-dual-ab-w20l-0098acc0-00401a40-report.md`

Absolute roots: `C:\Users\josh\Documents\GitHub\AutoCore\` + paths above.
