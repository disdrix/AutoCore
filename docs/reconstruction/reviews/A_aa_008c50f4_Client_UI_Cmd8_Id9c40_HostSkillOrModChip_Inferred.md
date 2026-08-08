# Review A (reconstruction fidelity): `aa_008c50f4` Client_UI_Cmd8_Id9c40_HostSkillOrModChip_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008c50f4` |
| **VA** | `0x008c50f4` |
| **Canonical name** | `Client_UI_Cmd8_Id9c40_HostSkillOrModChip_Inferred` |
| **Review date** | `2026-08-05` (gap-close dual OWN-ONLY) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_008c50f4_Client_UI_Cmd8_Id9c40_HostSkillOrModChip_Inferred.md` |
| **System** | skills-abilities / input-drive-control (UI command) |
| **Live tools** | Ghidra `decompile_function`, `analyze_function_complete`, `read_memory`, callers/xrefs (no `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

UI OnCommand specialized body for command pair **`(class=8, id=0x9c40)`**: dispatch either host hardpoint skill cast or mod-chip use based on local player flags, then optionally refresh a child float widget at `self+0x514`. Always reports handled (`AL=1`).

Closes inventory gap for live Ghidra VA `0x008c50f4` (parent of dualed `aa_008c4fc0`; co-caller of dualed `aa_0091f6b0`).

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | Ghidra `decompile_function(0x008c50f4)` 2026-08-05 |
| Body + gate bytes | `read_memory` @ `0x008c50d0` (154 B) / body 118 B @ `0x008c50f4` |
| Function meta | `analyze_function_complete` — worker; callees `FUN_008c4fc0`,`FUN_0091f6b0`; 0 CALL callers; xref JZ `0x008c50e5` |
| Globals audit | `DAT_00d1b6d8`, `DAT_00d1b778` |
| Sibling duals | `aa_008c4fc0` host cast; `aa_0091f6b0` TryUseModChip |
| Raw / annotated / clean | gap-close trio |

**Not performed:** `disassemble_bytes`; Launcher; parent ledgers.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body bounds `0x008c50f4`–`0x008c516A` (118 B) | **Confirmed** | `RET 8` then `CC` pad |
| No CALL callers; entry via JZ from `0x008c50e5` | **Confirmed** | xrefs + callers empty |
| Gate matches `(cmdClass=8, cmdId=0x9c40)` | **Confirmed** | imm `0x9c40`, `cmp ecx,8` |
| Gate `PUSH ESI; MOV ESI,ECX` → body `POP ESI; RET 8` | **Confirmed** | bytes |
| `unaff_ESI` = UI `this` | **Confirmed** | gate ABI |
| Return constant 1 | **Confirmed** | `MOV AL,1` |
| Host path: `+0x6b8 && !+0x6b9` → `0x008c4fc0` | **Confirmed** | decomp ≡ bytes call site |
| Else mod-chip: `DAT_00d1b778` + vtbl`+0x3d8` → `0x0091f6b0` | **Confirmed** | EDX load + call |
| Optional `self+0x514` float get `+0x3c8` / set `+0x3b0` | **Confirmed** | decomp ≡ bytes |
| Name `_Inferred` (no product string) | **High** role / **Open** PDB | |
| Product UI class / vtable slot of gate | **Open** | |
| Widget type / why get-then-set | **Open** | |
| Runtime / bit-exact | **Open** | |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Null player → still return 1 | **Yes** |
| Host flag pair → cast leaf | **Yes** |
| Else UI probe → mod-chip | **Yes** |
| Widget refresh after either branch | **Yes** |
| Always return true / RET 8 | **Yes** |
| No invented opcodes | **Yes** |

### Sealed CF sketch

```
// ESI=self (gate); stack still holds (cmdClass, cmdId) for RET 8
if player:
  if player[+0x6b8] && !player[+0x6b9]:
    Client_CastFirstHardpointSkillFlag200_Inferred()
  else if DAT_00d1b778 && vtbl+0x3d8():
    Client_Input_TryUseModChip(EDX=DAT_00d1b778)
  if self[+0x514]:
    f = widget.vtbl+0x3c8(); widget.vtbl+0x3b0(f)
return 1
```

---

## 5. Gaps

1. Product / PDB name for this UI handler and owning class.
2. DATA vtable entry that points at gate `0x008c50d0` (or equivalent dispatcher).
3. Exact product meaning of `(8, 0x9c40)` in this dialog (elsewhere `0x9c40` ≈ close).
4. Type of `DAT_00d1b778` and semantics of `vtbl+0x3d8`.
5. Type of `self+0x514` widget; purpose of float get→set.
6. Runtime path capture; bit-exact.

---

## 6. Verdict rationale

Structural CF, ABI (ESI this + RET 8), callees, and flag gates are sealed from decompile + bytes. Product English and full UI ownership remain open → **accept-with-gaps** (not reject: role and contract are port-usable).
