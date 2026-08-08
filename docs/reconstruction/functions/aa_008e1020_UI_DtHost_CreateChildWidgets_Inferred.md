# Function record: UI_DtHost_CreateChildWidgets_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008e1020` |
| **Canonical name** | `UI_DtHost_CreateChildWidgets_Inferred` |
| **Ghidra name** | `FUN_008e1020` |
| **Address** | `0x008e1020` |
| **Body range** | `0x008e1020`–`0x008e17be` inclusive (**1951 B** / `0x79F`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | inventory-transfer — dt 2d host CreateChildWidgets* |
| **Completion status** | **partial** — dual A/B **accept-with-gaps**; CF/ABI/vtbl/XML/slots/tabs sealed; product demangle + residual helpers + runtime open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_008e1020_UI_DtHost_CreateChildWidgets_Inferred.md`, `reviews/B_aa_008e1020_UI_DtHost_CreateChildWidgets_Inferred.md` (2026-08-05 R13-014) |
| **Last reviewed** | `2026-08-05` |

## Alias

- `FUN_008e1020`
- Virtual slot @ `0x00a3c3a0` (product ordinal open)

## Purpose

Virtual CreateChildWidgets for the dt 2d host: prep host, allocate/skin/attach the full `i_d_dt_2d_*` chrome tree (backgrounds, frames, title/icon/cover, instructions, close button, crafting + disciplines tabs), optionally apply a global string path, and fire host post-build vtbls.

## Signature

```c
void __thiscall UI_DtHost_CreateChildWidgets_Inferred(void *host); // ECX=host; RET 0
```

## Algorithm

```
FUN_00792600(host)
for each chrome child:
  p = new(size); p = p ? Ctor(p) : 0
  host.attach(p); p.load_xml(path); optional show/alpha; host[slot]=p
  optional z-order bump (+0x68/+0x70/+0x74 + vtbl+0x3f4)
// note: +0x530 written twice (title then icon)
// icon_cover via host.vtbl+0x404
tabs +0x54c crafting (unselected + MoveToFront) / +0x550 disciplines (selected)
optional DAT_00d1b8a8 path -> host.vtbl+0x114 + FUN_007fca10
host.vtbl+0x448(); host.vtbl+0x34c()
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_008e1020_FUN_008e1020.md`
- Annotated: `docs/reconstruction/raw/aa_008e1020_FUN_008e1020.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/UI_DtHost_CreateChildWidgets_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_008e1020.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_008e1020_FUN_008e1020.md`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-008e1020-r13-report.md`

## Callers / callees

| Direction | VA | Name / role |
|---|---|---|
| Dispatch | `0x00a3c3a0` | vtbl DATA -> this |
| Callee | `0x00792600` | residual host prep |
| Callee | `0x00489892` | `operator_new` |
| Callee | `0x007b5dd0` | CNDUIWindow base ctor |
| Callee | `0x00864f20` | fx pane ctor (0x4BC) |
| Callee | `0x0079c860` | close button ctor (0x4CC) |
| Callee | `0x008230b0` | tab window ctor (0x81C) |
| Callee | `0x00822cb0` | `UI_TabChrome_SetSelected_Inferred` [dualed R12-002] |
| Callee | `0x00756c90` | `UI_Widget_MoveToFrontInParentGroup_Inferred` [dualed R12-003 / parent] |
| Callee | `0x007fca10` | optional global path helper |
| Related | `0x008e6b50` | dualed craft CreateChildWidgets family (`i_d_craft_2d_*`) |
| Related | `0x008847f0` | dualed trade CreateChildWidgets family |

## Confidence

| Claim | Level |
|---|---|
| Control flow + thiscall RET 0 | **High** |
| Virtual DATA dispatch | **High** |
| XML family dt 2d + slot map | **High** |
| Tab crafting/disciplines pair | **High** |
| Product class demangle | **Open** |
