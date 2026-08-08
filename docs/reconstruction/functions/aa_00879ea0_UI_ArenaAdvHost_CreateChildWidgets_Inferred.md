# Function record: UI_ArenaAdvHost_CreateChildWidgets_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00879ea0` |
| **Canonical name** | `UI_ArenaAdvHost_CreateChildWidgets_Inferred` |
| **Ghidra name** | `FUN_00879ea0` |
| **Address** | `0x00879ea0` |
| **Body range** | `0x00879ea0`–`0x0087b38a` inclusive (**5355 B** / `0x14EB`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | inventory-transfer — arena advanced host CreateChildWidgets* (UI chrome; no inventory wire) |
| **Completion status** | **partial** — dual A/B **accept-with-gaps**; CF/ABI/vtbl/XML/slots/tabs/tail sealed; product demangle + residual helpers + runtime open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_00879ea0_UI_ArenaAdvHost_CreateChildWidgets_Inferred.md`, `reviews/B_aa_00879ea0_UI_ArenaAdvHost_CreateChildWidgets_Inferred.md` (2026-08-05 R13-011) |
| **Last reviewed** | `2026-08-05` |

## Alias

- `FUN_00879ea0`
- Plate residual: `UI_arena_adv_bg_combo_boxes` (single XML path — **not** canonical)
- Virtual slot @ `0x00a59500` (product ordinal open)

## Purpose

Virtual CreateChildWidgets for the Arena Advanced host: clear host `+0x524`, prep host, build full `i_d_arena_adv_*` child tree (backgrounds, action buttons, match setup edits, radios, currency edits, close/instructions/dividers, three tabs, match size/type combos), collapse inactive tabs via dualed helpers, residual post-build, host refresh.

## Signature

```c
void __thiscall UI_ArenaAdvHost_CreateChildWidgets_Inferred(void *host); // ECX=host; RET 0
```

## Algorithm

```
host[+0x524] = 0
FUN_00792600(host)
for each chrome child in i_d_arena_adv_*:
  p = new(size); p = p ? Ctor(p) : 0
  host.attach(p)          // vtbl+0xa8
  p.load_xml(path)        // vtbl+0x28
  optional id / edit flags / radio group
  host[slot] = p
// tabs:
//   +0x630 console  id 0x9c48 : TabChrome_SetSelected(force) + MoveToFront
//   +0x634 tournament id 0x9c49 : same
//   +0x638 advanced id 0x9c4a : TabChrome_SetSelected(force) + child vtbl+0x94
// combos +0x598 type / +0x594 size; both vtbl+0x94
FUN_00879240()
host.vtbl[+0x448]()
host.vtbl[+0x34c]()
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00879ea0_FUN_00879ea0.md`
- Annotated: `docs/reconstruction/raw/aa_00879ea0_FUN_00879ea0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/UI_ArenaAdvHost_CreateChildWidgets_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_00879ea0.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_00879ea0_FUN_00879ea0.md`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-00879ea0-r13-report.md`

## Callers / callees

| Direction | VA | Name / role |
|---|---|---|
| Dispatch | `0x00a59500` | vtbl DATA → this |
| Callee | `0x00792600` | residual host prep |
| Callee | `operator_new` | heap alloc |
| Callee | `0x007b5dd0` | CNDUIWindow base ctor (0x488) |
| Callee | `0x00864f20` | FX/special pane ctor (0x4bc) |
| Callee | `0x0079c860` | button ctor (0x4cc) |
| Callee | `0x00795f20` | edit ctor (0x4a4) |
| Callee | `0x008230b0` | tab window ctor (0x81c) |
| Callee | `0x00822cb0` | `UI_TabChrome_SetSelected_Inferred` [dualed] |
| Callee | `0x00756c90` | `UI_Widget_MoveToFrontInParentGroup_Inferred` [dualed; partition parent] |
| Callee | `0x0078e2f0` | combo ctor (0x938) |
| Callee | `0x00879240` | residual post-build |
| Related | `0x008747e0` | dualed `CDlgArenaPrefs_CreateChildWidgets` (prefs family) |
| Related | `0x008e6b50` | dualed craft CreateChildWidgets family |

## Confidence

| Claim | Level |
|---|---|
| Control flow + thiscall RET 0 | **High** |
| Virtual DATA dispatch @ `0x00a59500` | **High** |
| XML family arena_adv + 56 slots | **High** |
| Tab pairing console/tournament collapse vs advanced select | **High** |
| Product class demangle | **Open** |
| Runtime / differential | **Open** |
