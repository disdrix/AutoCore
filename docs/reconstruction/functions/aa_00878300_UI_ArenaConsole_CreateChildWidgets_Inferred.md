# Function record: UI_ArenaConsole_CreateChildWidgets_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00878300` |
| **Canonical name** | `UI_ArenaConsole_CreateChildWidgets_Inferred` |
| **Ghidra name** | `FUN_00878300` |
| **Address** | `0x00878300` |
| **Body range** | `0x00878300`–`0x00878c14` inclusive (**2325 B** / `0x915`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | inventory-transfer — arena console CreateChildWidgets residual |
| **Completion status** | **partial** — dual A/B **accept-with-gaps** (R13-010); Terminal **false** |
| **Bit-for-bit / runtime / diff** | Open |
| **Dual A/B** | `A_aa_00878300_*` / `B_aa_00878300_*` |
| **Last reviewed** | `2026-08-05` |

## Alias

- `FUN_00878300`
- `UI_arena_console_tab_tournament` (plate; **not** canonical — full tree, not tournament-only)
- Vtbl DATA `0x00a5a640`

## Purpose

Build the Arena Console dialog child widget tree from `i_d_arena/i_d_arena_console_*.xml`: fill/fx/textures/title/logos/help/news, action buttons (instant action, my stats, close), three tabs (console selected; tournament + advanced collapsed + move-to-front), mini status overlay, optional player-gated post-step, host finalize. **Client UI only — no sector/auth packets.**

## Signature

```c
void __thiscall UI_ArenaConsole_CreateChildWidgets_Inferred(void *host);
// ECX = host; no stack args; plain RET; void
```

## Algorithm

```
SEH enter (LAB_009b902f)
host[+0x524]=0; host[+0xc5]=0; host[+0x4fc]=0xf; host[+0x500]=1
host.vtbl[+0x110](); host.vtbl[+0x130](); FUN_00792600(host)
// ~19 children:
//   p = new(size); p = p ? Ctor(p) : 0
//   host[slot]=p; host.attach(+0xa8); p.load_xml(+0x28)
//   optional show/cmd/hide/select/front
// tabs: console selected; tournament+advanced unselected + MoveToFront
// mini-bg: if size slots ≤ -99998.f, normalize via 1200/1600 / display dims
FUN_008778e0(host)
if DAT_00d1b6d8 && player[+0x4fc]: FUN_00877c50(host)
host.vtbl[+0x34c]()
SEH leave; RET
```

## Artifacts

- Raw / annotated / clean / twin / FUN record / A/B / report — see `aa_00878300_FUN_00878300.md`

## Confidence

| Claim | Level |
|---|---|
| CreateChildWidgets role + full console XML domain | **High** |
| thiscall ECX host + plain RET | **High** |
| Slot/XML/cmd table from disasm | **High** |
| Default tab = console | **High** |
| Product RTTI name | **Open** (`_Inferred`) |
| Residual helper semantics | **Tentative / Open** |
| Runtime Confirmed | **never claimed** |
