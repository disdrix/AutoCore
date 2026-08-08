# Review A (reconstruction fidelity): `aa_0082c780` UI_Window_OnCommand_Base_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0082c780` |
| **VA** | `0x0082c780`–`0x0082c7eb` inclusive last (**108 B** / `0x6C`) |
| **Canonical name** | `UI_Window_OnCommand_Base_Inferred` |
| **Ghidra symbol** | `FUN_0082c780` |
| **Review date** | `2026-08-05` (R11-027 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_0082c780_UI_Window_OnCommand_Base_Inferred.md` |
| **System** | UI OnCommand base (partition: inventory-transfer) |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs/callees. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Base **UI window OnCommand** leaf used by dualed class-8 specialization `UI_Window_OnCommand_Class8_Inferred` (`0x0082f510`) and sibling command handlers:

1. If **cmdId == 70000** and **cmdClass ∈ {8, 0xb, 0xe}**: load child `@+0x2b0` into EDI, call dismiss helper `FUN_0090d400` (ESI=self), return **1**.
2. Else if `this.vtbl+0xd8()` and child `@+0x2b0` non-null: **forward** `child.vtbl+0x338(cmdClass, cmdId)`.
3. Else return **0**.

```text
UI_Window_OnCommand_Base_Inferred(this, cmdClass, cmdId):
  if cmdId==70000 && cmdClass in {8,0xb,0xe}:
    EDI=this[+0x2b0]; FUN_0090d400(); return 1
  if this.vtbl+0xd8() && this[+0x2b0]:
    return child.vtbl+0x338(cmdClass, cmdId)
  return 0
  // RET 8
```

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ R11-027 re-verify) | `docs/reconstruction/raw/aa_0082c780_FUN_0082c780.md` |
| Annotated | `docs/reconstruction/raw/aa_0082c780_FUN_0082c780.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/UI_Window_OnCommand_Base_Inferred.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_0082c780.cpp` |
| Function record | `docs/reconstruction/functions/aa_0082c780_UI_Window_OnCommand_Base_Inferred.md` |
| Live body | `disassemble_function` + `read_memory` @ `0x0082c780`; epilogue `C2 08 00` |
| Parent dual | `UI_Window_OnCommand_Class8_Inferred` @ `0x0082f510` (WQ8R-F) |
| DATA slot | `read_memory` `@0x00a732a4` = `80 c7 82 00` → `0x0082c780` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Live decompile ≡ 2026-07-23 raw CF | **Confirmed** | R11-027 re-decompile |
| Body 108 B + three `RET 8` exits | **Confirmed** | disasm + hex `C2 08 00` |
| `__thiscall` + stack (cmdClass, cmdId) | **Confirmed** | ESI=ECX; EDI=class; EBX=id |
| cmdId imm **70000** (`0x11170`) | **Confirmed** | `CMP EBX,0x11170` |
| Class gate **8 / 0xb / 0xe** | **Confirmed** | three `CMP EDI` / `JZ` to dismiss |
| Dismiss path loads EDI=`[+0x2b0]` then `CALL FUN_0090d400` | **Confirmed** | disasm @ `0082c7d9`/`0082c7df` |
| Forward via `vtbl+0xd8` + child `vtbl+0x338` | **Confirmed** | `CALL [EAX+0xd8]` / `CALL [EDX+0x338]` |
| Field **`+0x2b0`** (decompiler `[0xac]`) | **Confirmed** | `CMP [ESI+0x2b0]` / `MOV ECX,[ESI+0x2b0]` |
| DATA vtable entry `0x00a732a4` | **Confirmed** | xrefs + dword read |
| Named callers Class8 + `FUN_00830aa0` | **Confirmed** | analyze callers + xrefs |
| Product / RTTI window class English | **Open** | `_Inferred` |
| Product names for `+0xd8` / `+0x2b0` / `FUN_0090d400` | **Open** | |
| Runtime / bit-exact / differential | **Open** | no Launcher |

---

## 4. Control flow: raw ≡ live ≡ bytes

| Stage | Match |
|---|---|
| 70000 + class set → dismiss + return 1 | **Yes** |
| Predicate `vtbl+0xd8` | **Yes** |
| Child null check `@+0x2b0` | **Yes** |
| Forward `vtbl+0x338(class,id)` | **Yes** |
| Fallthrough return 0 | **Yes** |
| No invented inventory packets | **Yes** |

---

## 5. Naming gate

| Evidence | Present? |
|---|---|
| OnCommand ABI (`RET 8`, class+id) shared with dualed Class8 | **Yes** |
| 70000 sentinel + class set {8,0xb,0xe} | **Yes** |
| Child forward via known UI slot `vtbl+0x338` | **Yes** |
| Parent dual names this "Base_OnCommand" | **Yes** (WQ8R-F A review) |
| Product/PDB English | **No** |

**Decision:** promote **`UI_Window_OnCommand_Base_Inferred`**. Reject inventory-transfer packet/grid names; reject pure "always forward" / "always dismiss" collapses; keep `_Inferred`.

---

## 6. Gaps

1. Product / RTTI class for vtable containing `0x00a732a4`.
2. English for predicate `vtbl+0xd8` and field `+0x2b0`.
3. Dual of dismiss helper `FUN_0090d400` and sibling `FUN_00830aa0` (not OWN).
4. Unnamed CALL sites `0082de0c` / `00831272` / `00831821` / `00832b41` enclosure recovery.
5. Runtime / bit-exact.

**Verdict:** **accept-with-gaps**
