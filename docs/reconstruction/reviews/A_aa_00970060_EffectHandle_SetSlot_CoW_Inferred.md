# Review A (reconstruction fidelity): `aa_00970060` EffectHandle_SetSlot_CoW_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00970060` |
| **VA** | `0x00970060`–`0x009700a8` (**73 B** / `0x49`); pad `CC`×7; next @ `0x009700b0` |
| **Canonical name** | `EffectHandle_SetSlot_CoW_Inferred` (**Inferred**); Ghidra `FUN_00970060` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_00970060_EffectHandle_SetSlot_CoW_Inferred.md` |
| **System** | graphics / device-effect parameter slot bind |
| **Live tools** | Ghidra `batch_decompile`, `analyze_function_complete`, `read_memory`, xrefs, `get_assembly_context`, callees `0096fdf0`/`007528f0`/`00448fc0`, caller `0075bf40` (no `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** — ABI/CF sealed; product effect English + fail-path rarity open |
| **Dual status** | **Present (W38-P)** |

---

## 1. Purpose

On an **effect handle** (ESI = address of effect pointer slot):

```
cowed  = FUN_0096fdf0(handle)                 // CoW if binder shared (rc@+4 > 1)
status = FUN_007528f0(*handle, index, res)    // set/clear param slot; -1 if index < 0
if (status == -1 && cowed && *handle) {
  parent = (*handle)->field_0x18 || *handle;
  if (parent != *handle)
    FUN_00448fc0(handle, parent);             // rebind outer handle to parent
}
return status;  // 0 or -1
```

Primary sealed consumer: `GfxView_SetDiffuseColor_ClearDiffuseTex_Inferred` (`0x0075bf40`) resolves `"DiffuseTexture"` → index, then `FUN_00970060(index, 0)` with `ESI = this+0x134`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Fresh decompile | Ghidra `batch_decompile` `0x00970060` |
| Complete analysis | worker; 11 xrefs; 8 callers; callees listed |
| Machine | `read_memory` → body **73 B** then `CC` |
| CoW helper | `decompile` + bytes `0x0096fdf0` |
| Set-slot | `decompile` + bytes `0x007528f0` (early `-1` if index\<0) |
| Rc assign | `decompile` `0x00448fc0` |
| Caller | `0075bf40` dual (W37-L); `lea esi,[edi+0x134]` |
| Wrapper | `00970140` — `mov esi,ecx` then call |
| Scaffold | `raw/aa_00970060_*` |

**Not performed:** Launcher, runtime golden, dual of callees, parent ledger edits.

---

## 3. Machine seal (`read_memory`)

| Claim | Evidence | Conf |
|---|---|---|
| Save EBX/EDI; `mov ecx,esi` for CoW | `53 57 8b ce` | **Confirmed** |
| Call `0096fdf0`; save AL→BL | `e8 87 fd ff ff` / `8a d8` | **Confirmed** |
| Load args from `[esp+0xc]/` `[esp+0x10]` | after 2 pushes | **Confirmed** |
| `mov ecx,[esi]` then push res,index; call `007528f0` | `8b 0e` … `e8 74 28 de ff` | **Confirmed** |
| Compare result to `-1` | `83 ff ff` | **Confirmed** |
| Gate on BL (cowed) and `*esi` | `84 db` / `8b 06 85 c0` | **Confirmed** |
| Parent = `[obj+0x18]` or self | `8b 48 18` / `8b c8` | **Confirmed** |
| `push parent; mov ecx,esi; call 00448fc0` | `51 8b ce e8 1e 8f ad ff` | **Confirmed** |
| `mov eax,edi; pop edi; pop ebx; ret 8` | `8b c7 5f 5b c2 08 00` | **Confirmed** |
| Body 73 B | end @ `0x009700a8` | **Confirmed** |

Full hex (73 B):

```
53578bcee887fdffff8b54240c8b0e8ad88b4424105052e87428deff8bf883ffff751f84db741b8b0685c074158b481885c975028bc83bc87408518bcee81e8fadff8bc75f5bc20800
```

---

## 4. ABI / this-wiring

| Item | Value |
|---|---|
| This | **ESI** = `EffectHandle*` (not ECX) |
| Stack | `(slotIndex, resource*)` |
| Cleanup | **`ret 8`** |
| Return | **EAX** status (`0` / `-1`) |

Caller proof (`0075bf40`): `lea esi,[edi+0x134]` remains live across `call 00970060`.  
Caller proof (`00970140`): `mov esi,ecx` at entry.

---

## 5. Residual gaps

1. Product class English for effect / binder (`PTR_FUN_00a9f9c4` family).  
2. Whether fail-path parent rebind is hit in shipping paths (callers usually gate index≥0).  
3. Full semantics of `007528f0` slot table (owned elsewhere).  
4. Runtime / bit-exact / differential.

---

## 6. Verdict

**accept-with-gaps** — machine CF/ABI sealed; product names and live fail-path frequency open.
