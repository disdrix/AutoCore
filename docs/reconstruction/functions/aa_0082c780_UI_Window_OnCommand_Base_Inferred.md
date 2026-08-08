# Function record: UI_Window_OnCommand_Base_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0082c780` |
| **Canonical name** | `UI_Window_OnCommand_Base_Inferred` (**Inferred** structural) |
| **Ghidra symbol** | `FUN_0082c780` |
| **Address** | `0x0082c780`–`0x0082c7eb` inclusive last (**108 B** / `0x6C`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **Body** | 70000 dismiss {8,0xb,0xe} → `FUN_0090d400`; else child forward `vtbl+0x338`; else 0; **`RET 8`** |
| **System** | UI OnCommand base (partition host: inventory-transfer) |
| **Agent** | R11-027 OWN-ONLY dual 2026-08-05 |
| **Completion status** | Dual sealed (A/B **accept-with-gaps**) |
| **Terminal** | **false** |

## Purpose

Base **UI window OnCommand** worker:

1. **Dismiss path:** `cmdId == 70000` and `cmdClass ∈ {8, 0xb, 0xe}` → load child `@+0x2b0` into EDI, call `FUN_0090d400` (ESI=self), return 1.
2. **Forward path:** if `this.vtbl+0xd8()` and child `@+0x2b0` ≠ 0 → `child.vtbl+0x338(cmdClass, cmdId)`.
3. **Miss:** return 0.

Used as base by dualed `UI_Window_OnCommand_Class8_Inferred` (`0x0082f510`) and residual sibling `FUN_00830aa0`. DATA vtable entry `@0x00a732a4`.

## Signature

```c
// __thiscall ECX=this; stack: cmdClass, cmdId; RET 8
// Returns handled flag (0 / 1 / child OnCommand result)
uint32_t __thiscall UI_Window_OnCommand_Base_Inferred(
    int* self,
    int cmdClass,
    int cmdId);
```

## Layout / constants

| Item | Value |
|---|---|
| cmdId sentinel | **70000** (`0x11170`) |
| cmdClass set (dismiss) | **8, 0xb, 0xe** |
| child field | **`this+0x2b0`** |
| predicate slot | **`this.vtbl+0xd8`** |
| OnCommand slot | **`child.vtbl+0x338`** |
| DATA vtable | **`0x00a732a4`** |

## Call graph

| Role | Target |
|---|---|
| **Direct callee** | `FUN_0090d400` @ `0x0090d400` (dismiss; ESI/EDI convention) |
| **Indirect** | `vtbl+0xd8`, `vtbl+0x338` |
| **Named callers** | `UI_Window_OnCommand_Class8_Inferred` (`0x0082f510`); `FUN_00830aa0` |
| **Other CALL** | `0082de0c`, `00831272`, `00831821`, `00832b41` |
| **DATA** | `0x00a732a4` |
| **Partition parent** | `0x0082f510` (wave score / dualed Class8 specialization) |

## Evidence summary

- Live decompile ≡ raw CF; epilogue `RET 8` via `read_memory` / disasm (`C2 08 00`).
- Immediates 70000 + class set + offsets sealed in body hex.
- Parent dual WQ8R-F already documents fallback/dead-vehicle divert into this VA as Base_OnCommand.
- Not inventory grid transfer despite partition label.

## Artifacts

- Clean: `docs/reconstruction/reconstructed-exact/UI_Window_OnCommand_Base_Inferred.cpp`
- Scaffold twin: `docs/reconstruction/reconstructed-exact/FUN_0082c780.cpp`
- Raw: `docs/reconstruction/raw/aa_0082c780_FUN_0082c780.md`
- Annotated: `docs/reconstruction/raw/aa_0082c780_FUN_0082c780.annotated.md`
- Review A: `docs/reconstruction/reviews/A_aa_0082c780_UI_Window_OnCommand_Base_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_0082c780_UI_Window_OnCommand_Base_Inferred.md`
- Ghidra FUN record: `docs/reconstruction/functions/aa_0082c780_FUN_0082c780.md`
- Report: `docs/agents/task-dual-ab-0082c780-r11-report.md`

## Gaps

1. Product/RTTI window class for `0x00a732a4`.
2. English for `vtbl+0xd8` and `+0x2b0`.
3. Dual of `FUN_0090d400` / `FUN_00830aa0` (not OWN).
4. Unnamed call-site enclosures.
5. Runtime / bit-exact / differential.
