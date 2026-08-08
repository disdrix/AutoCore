# Review A (reconstruction fidelity): `aa_00879ea0` UI_ArenaAdvHost_CreateChildWidgets_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00879ea0` |
| **VA** | `0x00879ea0`–`0x0087b38a` inclusive (**5355 B** / `0x14EB`) |
| **Canonical name** | `UI_ArenaAdvHost_CreateChildWidgets_Inferred` |
| **Ghidra name** | `FUN_00879ea0` |
| **Review date** | `2026-08-05` (R13-011 dual seal) |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY R13-011) |
| **Counterpart** | `reviews/B_aa_00879ea0_UI_ArenaAdvHost_CreateChildWidgets_Inferred.md` |
| **System** | inventory-transfer — arena advanced host CreateChildWidgets* (UI chrome; no inventory wire) |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` + callers/xrefs + `get_function_by_address`. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

**Tools:** decompile + analyze + read_memory + xrefs. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Virtual **CreateChildWidgets** for the client **Arena Advanced** host UI: clear a host flag byte, run residual host prep (`FUN_00792600`), allocate/skin/attach the full `i_d_arena/i_d_arena_adv_*` chrome tree (backgrounds, join/spectate/host buttons, level/match edits, ladder/practice radios, entry-fee and value-max currency edits, close + instruction labels, dividers, three tabs, match size/type combos), configure control ids and edit defaults, collapse inactive tabs via dualed tab helpers, then fire residual post-build `FUN_00879240` and host `vtbl+0x448` / `vtbl+0x34c`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ R13-011 append) | `docs/reconstruction/raw/aa_00879ea0_FUN_00879ea0.md` |
| Annotated | `docs/reconstruction/raw/aa_00879ea0_FUN_00879ea0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/UI_ArenaAdvHost_CreateChildWidgets_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_00879ea0.cpp` |
| Function record | `docs/reconstruction/functions/aa_00879ea0_UI_ArenaAdvHost_CreateChildWidgets_Inferred.md` |
| Live | decompile full body; entry/exit hex; vtbl DATA `0x00a59500`; body range Ghidra |

---

## 3. Signature (sealed)

```c
// ECX = arena-adv UI host*; no stack args; void; RET 0
void __thiscall UI_ArenaAdvHost_CreateChildWidgets_Inferred(void *host);
```

| Formal | Source | Conf |
|---|---|---|
| host | **ECX** (`MOV EBP,ECX` @ entry after SEH pushes) | **High** |
| return | void (no EAX contract; `RET`/`C3`) | **High** |
| cleanup | **`RET`** (`C3`) — not stdcall | **High** |

Ghidra may display `__fastcall` / `int *param_1`; product ABI is **thiscall ECX-only**.

---

## 4. Control flow (authority)

| Stage | Evidence | Conf |
|---|---|---|
| SEH + thiscall | prologue `6A FF 68 CD 92 9B 00 … 8B E9`; handler `LAB_009b92cd` | **High** |
| Flag clear | `MOV [EBP+0x524], BL` with `BL=0` → host byte **`+0x524`** | **High** |
| Prep | `CALL 0x00792600` with ECX=host | **High** |
| Child pattern | `new` / ctor / `CALL [vtbl+0xa8]` attach / `CALL [vtbl+0x28]` load XML / store host slot | **High** |
| Window base | `new(0x488)` + `FUN_007b5dd0` (×33) | **High** |
| FX pane | `new(0x4bc)` + `FUN_00864f20` → **`host+0x564`** | **High** |
| Buttons | `new(0x4cc)` + `FUN_0079c860` (×6); ids via `vtbl+0x74` | **High** |
| Edits | `new(0x4a4)` + `FUN_00795f20` (×11); numeric/password flags | **High** |
| Combos | `new(0x938)` + `FUN_0078e2f0` (×2) → **`+0x598` / `+0x594`** | **High** |
| Tabs | `new(0x81c)` + `FUN_008230b0` (×3); dualed `FUN_00822cb0` / `FUN_00756c90` | **High** |
| Tail | `FUN_00879240`; host `vtbl+0x448`; host `vtbl+0x34c`; SEH restore; `RET` | **High** |
| Exit | `… 83 C4 10 C3` at `0x0087b38a` | **High** |

---

## 5. Machine bytes (entry / exit)

| Item | Hex / notes |
|---|---|
| Body | `0x00879ea0`–`0x0087b38a` (**5355 B** / `0x14EB`) |
| Entry | `6A FF 68 CD 92 9B 00 64 A1 00 00 00 00 50 64 89 25 00 00 00 00 51 53 55 56 8B E9 33 DB 57 88 9D 24 05 00 00` |
| Exit | `… 5F 5E 5D 5B 64 89 0D 00 00 00 00 83 C4 10 C3` |
| Vtbl | DATA dword @ `0x00a59500` = `0x00879ea0` (LE `A0 9E 87 00`) |

---

## 6. Slot / XML map (sealed representative)

| Host offset | Slot dword | XML / role | Ctor size |
|---|---|---|---|
| `+0x560` | `0x158` | `…wnd_bg_fill.xml` | 0x488 |
| `+0x564` | `0x159` | `…wnd_fx.xml` | 0x4bc |
| `+0x568`–`+0x57c` | `0x15a`–`0x15f` | bg texture / logo / ladder / combo_boxes / values / name | 0x488 |
| `+0x580` | `0x160` | `…btn_join_now.xml` id **0x9c41** | 0x4cc |
| `+0x584` | `0x161` | `…btn_spectate_now.xml` id **0x9c42** | 0x4cc |
| `+0x588` | `0x162` | `…btn_host_now.xml` id **0x9c43** | 0x4cc |
| `+0x59c` | `0x167` | level max edit; max len 3; charset `DAT_00a59fd0` | 0x4a4 |
| `+0x5a4`/`+0x5a8` | `0x169`/`0x16a` | match name / password edits (pw charset `DAT_00a1419b`, len 8, flag `+0x48c`) | 0x4a4 |
| `+0x5b8`/`+0x5bc` | `0x16e`/`0x16f` | ladder / practice radios ids **0x9c44**/**0x9c45**; group setup | 0x4cc |
| `+0x5dc`–`+0x5e8` | `0x177`–`0x17a` | entry fee b/m/k/c edits (len 3; charset `DAT_00a32460`) | 0x4a4 |
| `+0x600`–`+0x60c` | `0x180`–`0x183` | value max b/m/k/c edits (len 3; charset `DAT_00a59fd0`) | 0x4a4 |
| `+0x504` | `0x141` | `…btn_close.xml` id **40000** (`0x9C40`) | 0x4cc |
| `+0x630` | `0x18c` | tab console id **0x9c48** → `00822cb0` + `00756c90` | 0x81c |
| `+0x634` | `0x18d` | tab tournament id **0x9c49** → `00822cb0` + `00756c90` | 0x81c |
| `+0x638` | `0x18e` | tab advanced id **0x9c4a** → `00822cb0` + `vtbl+0x94` (selected path) | 0x81c |
| `+0x594`/`+0x598` | `0x165`/`0x166` | match size / type combos ids **0x9c46**/**0x9c47** | 0x938 |

**56** XML paths under `i_d_arena/i_d_arena_adv_*` (full list in raw/clean).

---

## 7. Callers / classification

| Item | Value |
|---|---|
| Classification | worker (virtual) |
| Callers | none direct CALL; **vtbl DATA** `0x00a59500` |
| Callees | `00792600`, `operator_new`, `007b5dd0`, `00864f20`, `0079c860`, `00795f20`, `008230b0`, `00822cb0`, `00756c90`, `0078e2f0`, `00879240`, vtbls |

---

## 8. Gaps

1. Product demangle for arena-adv host class (no RTTI sealed in-unit).
2. Residual helper English (`00792600`, `00879240`, ctors, charset DAT_* product names).
3. Full per-slot English for every instruction/divider label (XML path is sealed; product title strings open).
4. Exact BL register value at each `FUN_00822cb0` call site (force stack arg sealed as 1; dualed helper ABI uses ESI+BL).
5. Runtime / bit-exact / differential (Terminal false).

---

## 9. Verdict

**accept-with-gaps** — ABI/body/vtbl dispatch/XML family/56-slot tree/tab pairing/tail sealed; product class demangle + residual helper English + runtime open.
