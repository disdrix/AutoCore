# Dual A/B report — `aa_007999c0` NDXml_OpenTaggedDocument

**Date:** 2026-07-29  
**Scope:** OWN ONLY VA `0x007999c0`. Dual A/B + three-rep refine. Seal NDXml open-by-path+tag ABI, fields, CF.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / ledgers.  
**Ghidra:** `decompile_function` + `read_memory` (+ function meta / callees / callers / xrefs). No `disassemble_bytes`.  
**Programs open:** `autoassault.exe` only (dual A/B = fidelity vs adversarial reviews).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_007999c0` NDXml_OpenTaggedDocument | **accept-with-gaps** — ABI/CF/fields sealed; COM IDL names gapped |

---

## Sealed facts

1. **ABI:** `__thiscall` — `this` in ECX, stack **`char *pszPath`**, **`char *pszTag`** (nullable), epilogue **`RET 8`**, return **`int` in EAX** (**0** success, **1** fail / empty).

2. **Decompiler phantom:** signature shows unused `param_3` between path and tag — **not real**; only two stack args (call-site pushes + RET 8).

3. **Path ownership:** if `this+0x10` non-null → `delete[]`; `new[]` `strlen(path)+1`; strcpy; store at `+0x10`.

4. **Load:** `loader = FUN_007b6a20()` (singleton `&DAT_00d20c38`); `NDXml_LoadDocumentFromPath(loader, *(this+4), path)`; false → **return 1**.

5. **Tag bind:** NULL tag → NULL BSTR; else `FUN_004234e0(tag, -1)` ANSI→BSTR; NULL BSTR → **`FUN_004048e0(0x8007000E)` noreturn**.

6. **COM:** `doc = *(this+4)`; `hr = doc->vtbl[+0xdc](doc, bstr, &*(this+8))`; if `hr==0`, `hr = node->vtbl[+0x20](node, this+0xc)`; if `*(int*)(this+0xc) < 1` → `hr = 1`; `SysFreeString(bstr)`; return `hr`.

7. **Layouts sealed (fields this unit touches):**
   - `+0x04` document  
   - `+0x08` bound interface (out)  
   - `+0x0c` count (out)  
   - `+0x10` owned path  

8. **Body:** `0x007999c0`–`0x00799ae0`. Entry `64A1…6AFF68…8BF18B4610…`. Tails both **`C2 08 00`**.

9. **Callers (6 xrefs):** UI (`"XML"`), SpecialFX (`"NDSpecialFX"`), plus `FUN_004a6390` / `004a6670` / `00547920` / `005abba0`.

10. **Name:** `NDXml_OpenTaggedDocument` correct (path open + tag bind, not load-only).

---

## Gaps

1. MSXML/custom **IDL names** for vtable `+0xdc` / `+0x20` (offsets sealed only).  
2. Full NDXml object size / any fields beyond `+0x00..+0x10`.  
3. Whether callers ever depend on HRESULT ∉ `{0,1}`.  
4. Runtime live verification / bit-exact image diff.  
5. Ghidra prototype still `void` — display of caller args unreliable without bytes.

---

## Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_007999c0_NDXml_OpenTaggedDocument.md` | **accept-with-gaps** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_007999c0_NDXml_OpenTaggedDocument.md` | **accept-with-gaps** |

---

## Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_007999c0_NDXml_OpenTaggedDocument.md` |
| Review B | `docs/reconstruction/reviews/B_aa_007999c0_NDXml_OpenTaggedDocument.md` |
| Function record | `docs/reconstruction/functions/aa_007999c0_NDXml_OpenTaggedDocument.md` |
| Clean | `docs/reconstruction/reconstructed-exact/NDXml_OpenTaggedDocument.cpp` |
| Raw (authoritative body + v2026-07-29 append) | `docs/reconstruction/raw/aa_007999c0_NDXml_OpenTaggedDocument.md` |
| Annotated | `docs/reconstruction/raw/aa_007999c0_NDXml_OpenTaggedDocument.annotated.md` |
| This report | `docs/agents/task-dual-ab-007999c0-ndxml-opentaggeddocument-report.md` |

Sibling context (not owned): ctor `FUN_00799940` `0x00799940`, cleanup `FUN_007989b0`, load `NDXml_LoadDocumentFromPath` `0x007b6c70`.

---
