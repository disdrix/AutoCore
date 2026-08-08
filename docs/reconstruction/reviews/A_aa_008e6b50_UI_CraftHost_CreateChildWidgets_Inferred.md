# Review A (reconstruction fidelity): `aa_008e6b50` UI_CraftHost_CreateChildWidgets_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008e6b50` |
| **VA** | `0x008e6b50`–`0x008e811f` inclusive (**5584 B** / `0x15D0`) |
| **Canonical name** | `UI_CraftHost_CreateChildWidgets_Inferred` |
| **Ghidra name** | `FUN_008e6b50` |
| **Review date** | `2026-08-05` (R11-036 dual seal) |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY R11-036) |
| **Counterpart** | `reviews/B_aa_008e6b50_UI_CraftHost_CreateChildWidgets_Inferred.md` |
| **System** | inventory-transfer — craft 2d host CreateChildWidgets* |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

**Tools:** decompile + analyze + read_memory + disassemble_function + xrefs. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Virtual **CreateChildWidgets** for the craft / reverse-engineering 2d host UI: after residual host prep (`FUN_00792600`), allocate/skin/attach the full `i_d_craft_2d_*` chrome tree (backgrounds, geo pane, item labels, object preview stack, five material component rows, lists/buttons, crafting + disciplines tabs), optionally apply a global player path, rebind the current object via dualed `UI_CraftHost_BindResolvedObject_Inferred`, store a gate byte at `host+0x7e2`, and fire host `vtbl+0x34c`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ R11-036 append) | `docs/reconstruction/raw/aa_008e6b50_FUN_008e6b50.md` |
| Annotated | `docs/reconstruction/raw/aa_008e6b50_FUN_008e6b50.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/UI_CraftHost_CreateChildWidgets_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_008e6b50.cpp` |
| Function record | `docs/reconstruction/functions/aa_008e6b50_UI_CraftHost_CreateChildWidgets_Inferred.md` |
| Live | full disasm (1525 lines); entry/exit hex; XML `.rdata` strings; vtbl DATA `0x00a3aca8` |

---

## 3. Signature (sealed)

```c
// ECX = craft/UI host*; no stack args; void; RET 0
void __thiscall UI_CraftHost_CreateChildWidgets_Inferred(void *host);
```

| Formal | Source | Conf |
|---|---|---|
| host | **ECX** (`MOV EBP,ECX` @ `0x008e6b72`) | **High** |
| return | void (no EAX contract; `RET`/`C3`) | **High** |
| cleanup | **`RET`** (`C3`) — not stdcall | **High** |

---

## 4. Control flow (authority)

| Stage | Evidence | Conf |
|---|---|---|
| SEH + thiscall | prologue `55 8B EC … 8B E9`; handler `0x009ba671` | **High** |
| Prep | `CALL 0x00792600` with ECX=host | **High** |
| Child pattern | `new` / ctor / `CALL [vtbl+0xa8]` / `CALL [vtbl+0x28]` / store `[EBP+slot]` | **High** |
| Geo buffered | `PUSH 0x4FC; CALL new; PUSH 1; PUSH 0; PUSH p; CALL 0x0078caf0` -> `+0x520` | **High** |
| Material loop | `LEA ESI,[EBP+0x5b8]`; `ADD EBX,1`; `ADD ESI,4`; `CMP EBX,5` | **High** |
| Slot +0x568 | first store `MOV [ESI-0x50],EDX` with ESI base +0x5b8 | **High** |
| Tabs | `new 0x81C` + `008230b0`; XML tab_crafting / tab_disciplines; ids `0x9c43`/`0x9c44` | **High** |
| Tail bind | `PUSH [EBP+0x7cc]; MOV ECX,EBP; CALL 0x008e5990` | **High** |
| Gate byte | `CALL 0x0052eb90`; `MOV [EBP+0x7e2],AL` | **High** |
| Exit | `8B E5 5D C3` | **High** |

---

## 5. Machine bytes (entry / exit)

| Item | Hex / notes |
|---|---|
| Body | `0x008e6b50`–`0x008e811f` (**5584 B** / `0x15D0`) |
| Entry | `55 8B EC 83 E4 F8 6A FF 68 71 A6 9B 00 … 8B E9` |
| Exit | `8B E5 5D C3` |
| Vtbl | DATA dword @ `0x00a3aca8` = `0x008e6b50` |

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker (virtual) |
| Callers | none direct CALL; **vtbl DATA** `0x00a3aca8` |
| Callees | `00792600`, `operator_new`, `007b5dd0`, `0078caf0`, `0079c860`, `0078b6e0`, `0078f890`, `008230b0`, `00822cb0`, `00756c90`, `007fbe50`, `007fca10`, `008e5990`, `0052eb90`, vtbls |

---

## 7. Gaps

1. Product demangle for craft host class (no RTTI sealed in-unit).
2. Residual helper English (`00792600`, `0052eb90`, tab/list ctors).
3. Full per-slot English for secondary component widgets / every divider/button.
4. Runtime / bit-exact / differential (Terminal false).

---

## 8. Verdict

**accept-with-gaps** — ABI/body/vtbl dispatch/XML family/slot banks/5-loop/tail bind+gate sealed; product class demangle + residual helper English + runtime open.
