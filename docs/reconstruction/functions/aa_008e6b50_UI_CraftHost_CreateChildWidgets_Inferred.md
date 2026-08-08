# Function record: UI_CraftHost_CreateChildWidgets_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008e6b50` |
| **Canonical name** | `UI_CraftHost_CreateChildWidgets_Inferred` |
| **Ghidra name** | `FUN_008e6b50` |
| **Address** | `0x008e6b50` |
| **Body range** | `0x008e6b50`–`0x008e811f` inclusive (**5584 B** / `0x15D0`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | inventory-transfer — craft 2d host CreateChildWidgets* |
| **Completion status** | **partial** — dual A/B **accept-with-gaps**; CF/ABI/vtbl/XML/slots/loop/tail sealed; product demangle + residual helpers + runtime open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_008e6b50_UI_CraftHost_CreateChildWidgets_Inferred.md`, `reviews/B_aa_008e6b50_UI_CraftHost_CreateChildWidgets_Inferred.md` (2026-08-05 R11-036) |
| **Last reviewed** | `2026-08-05` |

## Alias

- `FUN_008e6b50`
- Virtual slot @ `0x00a3aca8` (product ordinal open)

## Purpose

Virtual CreateChildWidgets for the craft 2d host: prep host, build full `i_d_craft_2d_*` child tree (including five material component rows and crafting/disciplines tabs), rebind current object via dualed `UI_CraftHost_BindResolvedObject_Inferred`, write gate byte `host+0x7e2`, refresh host.

## Signature

```c
void __thiscall UI_CraftHost_CreateChildWidgets_Inferred(void *host); // ECX=host; RET 0
```

## Algorithm

```
FUN_00792600(host)
for each chrome child:
  p = new(size); p = p ? Ctor(p) : 0
  host.attach(p); p.load_xml(path); optional show/alpha; host[slot]=p
5x component rows at +0x568 bank
tabs +0x784 / +0x788
optional DAT_00d1b8b4 path
UI_CraftHost_BindResolvedObject_Inferred(host, host[+0x7cc])
host[+0x7e2] = FUN_0052eb90(DAT_00d1b6d8, host[+0x7cc])
host.vtbl[+0x34c]()
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_008e6b50_FUN_008e6b50.md`
- Annotated: `docs/reconstruction/raw/aa_008e6b50_FUN_008e6b50.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/UI_CraftHost_CreateChildWidgets_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_008e6b50.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_008e6b50_FUN_008e6b50.md`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-008e6b50-r11-report.md`

## Callers / callees

| Direction | VA | Name / role |
|---|---|---|
| Dispatch | `0x00a3aca8` | vtbl DATA -> this |
| Callee | `0x00792600` | residual host prep |
| Callee | `0x00489892` | `operator_new` |
| Callee | `0x007b5dd0` | CNDUIWindow base ctor |
| Callee | `0x0078caf0` | `CNDUIWndBuffered_Ctor_Inferred` |
| Callee | `0x008e5990` | `UI_CraftHost_BindResolvedObject_Inferred` |
| Callee | `0x0052eb90` | residual object gate -> `+0x7e2` |
| Callee | `0x008230b0` / `0x00822cb0` | tab ctor / tab helper |
| Related | `0x008847f0` | dualed trade CreateChildWidgets family |

## Confidence

| Claim | Level |
|---|---|
| Control flow + thiscall RET 0 | **High** |
| Virtual DATA dispatch | **High** |
| XML family craft 2d + slot banks | **High** |
| 5-slot +0x568 loop | **High** |
| Tail bind + gate byte | **High** |
| Product class demangle | **Open** |
| Runtime / differential | **Open** |
