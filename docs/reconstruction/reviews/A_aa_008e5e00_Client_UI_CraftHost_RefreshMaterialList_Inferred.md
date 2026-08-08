# Review A (reconstruction fidelity): `aa_008e5e00` Client_UI_CraftHost_RefreshMaterialList_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008e5e00` |
| **VA** | `0x008e5e00`–`0x008e6386` inclusive (**1415 B** / `0x587`) |
| **Canonical name** | `Client_UI_CraftHost_RefreshMaterialList_Inferred` |
| **Ghidra name** | `FUN_008e5e00` |
| **Prior names** | `Named_CalleeOf_Client_RefreshOpenMissionUiWindows_008e5e00` (scaffold; retired) |
| **Review date** | `2026-08-05` (R10-015 dual seal) |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY R10-015) |
| **Counterpart** | `reviews/B_aa_008e5e00_Client_UI_CraftHost_RefreshMaterialList_Inferred.md` |
| **System** | inventory-transfer — craft/RE host material list refresh |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

**Tools:** decompile + disassemble_function + read_memory + analyze/xrefs/assembly_context. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Refresh the craft/RE host **material/candidate list** at `host+0x754` by clearing it and re-populating from:

1. Vehicle cargo grid (`char+0x250` → `+0x2b0`) — plain item names  
2. Locker grid (`char+0xcbc`) when UI flag `DAT_00d1b644+0xf5` — names prefixed `[L]`  
3. Equip TFID table (`char+0x5a0`, count `FUN_00522000`) via `CVOGReaction_ResolveObjectTarget` — names prefixed `[M]`

Then restore prior selection, zero `list+0x568`, and if the selection TFID changed call dualed `Client_UI_CraftHost_BindObjectByTfid_Inferred` (`0x008e5ce0`). If list state `vtbl+0x490` changed, call `FUN_007fbd30`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ R10-015 append) | `docs/reconstruction/raw/aa_008e5e00_FUN_008e5e00.md` |
| Annotated | `docs/reconstruction/raw/aa_008e5e00_FUN_008e5e00.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_UI_CraftHost_RefreshMaterialList_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_008e5e00.cpp` |
| Function record | `docs/reconstruction/functions/aa_008e5e00_Client_UI_CraftHost_RefreshMaterialList_Inferred.md` |
| Live | full disasm; entry/exit hex; strings `[M]`/`[L]`/`%s %s`; 2 CALL xrefs with assembly_context |
| Not performed | `disassemble_bytes`, Launcher, bit-exact, runtime |

---

## 3. Signature (sealed)

```c
// EDI = craft/UI host*; no stack args; void; RET 0 (C3)
void Client_UI_CraftHost_RefreshMaterialList_Inferred(/* host in EDI */);
```

| Formal | Source | Conf |
|---|---|---|
| host | **EDI** at entry (`CMP [EDI+0x754]`; callers keep host in EDI through refresh chain) | **High** |
| stack args | none (plain `RET` / `C3`; no `RET n`) | **High** |
| return | void (no EAX contract) | **High** |
| cleanup | **`RET`** (`C3` at `0x008e6386`) | **High** |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match | Conf |
|---|---|---|
| Early-out `host+0x754==0` | Yes | **High** |
| Snapshot +0x490 / +0x49c / +0x44c | Yes | **High** |
| Invalid TFID `(lo&hi)==-1` → bound object TFID | Yes (asm fixes decompiler) | **High** |
| Clear list +0x458 | Yes | **High** |
| Cargo walk + bit-19 filter-in | Yes | **High** |
| Locker walk + `[L]` prefix + flag gate | Yes | **High** |
| Equip table + `[M]` + ResolveObjectTarget | Yes | **High** |
| Restore +0x448 / zero +0x568 / +0x498 | Yes | **High** |
| Selection change → `FUN_008e5ce0` stdcall | Yes (`PUSH hi; PUSH lo; PUSH EDI`) | **High** |
| snapA change → `FUN_007fbd30` | Yes | **High** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| EDI-host, plain RET | **High** | prologue + exit + callers |
| `(lo&hi)==-1` sentinel | **High** | asm AND/CMP; matches dualed parent |
| `[M]` / `[L]` string prefixes | **High** | `read_memory` |
| Cargo / locker / equip three sources | **High** | offsets + paths |
| Calls dualed `008e5ce0` on selection change | **High** | stdcall triple |
| `+0x17c` bit 19 product English | **Open** | filter-in here; parent dual “Broken” filter-out |
| Craft host product class name | **Inferred** | from dualed sibling/parent chain |
| `FUN_00522000` / `FUN_008e4430` / iterators | **Tentative** | unowned residuals |

---

## 6. Gaps

1. Product RTTI demangle for host / list widget.  
2. Product meaning of `+0x17c` bit 19 (polarity vs parent dual).  
3. Residual helper English (`FUN_008e4430`, `FUN_00522000`, `FUN_007fbd30`, map iterators).  
4. Exact display semantics of `[M]` / `[L]` tags beyond equip/locker path.  
5. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**
