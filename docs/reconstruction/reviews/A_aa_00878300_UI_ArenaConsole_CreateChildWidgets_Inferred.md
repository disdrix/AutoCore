# Review A (reconstruction fidelity): `aa_00878300` UI_ArenaConsole_CreateChildWidgets_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00878300` |
| **VA** | `0x00878300` |
| **Canonical name** | `UI_ArenaConsole_CreateChildWidgets_Inferred` |
| **Review date** | `2026-08-05` (R13-010 dual seal) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_00878300_UI_ArenaConsole_CreateChildWidgets_Inferred.md` |
| **System** | inventory-transfer (partition assignment; pure client UI construct residual) |
| **Live tools** | Ghidra `decompile_function`, `analyze_function_complete`, `disassemble_function`, `get_function_by_address`, callers/xrefs, `list_strings`, `read_memory` (no `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Virtual **CreateChildWidgets** for the client **Arena Console** host dialog:

1. Pre-init host flags and virtual prep (`+0x110`/`+0x130`, `FUN_00792600`).
2. Allocate ~19 NDUI children (`operator_new` + typed ctors), attach via host vtbl `+0xa8`, load `i_d_arena/i_d_arena_console_*.xml` via child vtbl `+0x28`.
3. Wire buttons/tabs with command ids **0x9c40–0x9c47**.
4. Default-select **console** tab; collapse **tournament** + **advanced** tabs and move them to front of parent group via dualed helpers.
5. Build mini status overlay; optionally normalize size against **-99998.0f** sentinel.
6. Residual post helpers + host vtbl `+0x34c` finalize.

**No sector/auth C2S packet send** in this body — pure client UI scaffolding (same family as dualed `CDlgArenaPrefs_CreateChildWidgets` / `UI_CraftHost_CreateChildWidgets_Inferred`).

Partition parent residual: dualed `UI_Widget_MoveToFrontInParentGroup_Inferred` (`0x00756c90`) called after collapsed tournament/advanced chrome.

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | Ghidra `decompile_function(0x00878300)` 2026-08-05 ≡ frozen raw CF (2026-07-23) |
| Body / epilogue | `get_function_by_address` + `disassemble_function` + `read_memory`; body `00878300`–`00878c14`; plain `RET` (`C3`) |
| ABI | entry `MOV EBP,ECX`; no stack formals; void |
| Vtbl | DATA xref `0x00a5a640`; host vtbl base `PTR_FUN_00a5a204` (+**0x43C**) |
| Strings | `list_strings` filter `i_d_arena_console` → full path inventory |
| Floats | `read_memory` `DAT_00aaac10`=-99998.0f; `DAT_00aaa670`=1200.0f; `DAT_00aaa674`=1600.0f |
| Dualed callees | `UI_TabChrome_SetSelected_Inferred` (`00822cb0`); `UI_Widget_MoveToFrontInParentGroup_Inferred` (`00756c90`); `NDUIFxPanel_Ctor_Inferred` (`00864f20`) |
| Raw / annotated / clean / records | R13-010 trio refresh |

**Not performed:** `disassemble_bytes`; Launcher; parent ledgers; dual of residual helpers / other VAs.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Live decompile ≡ frozen raw CF | **High** | stage order preserved |
| `__thiscall` ECX = host; plain `RET`; void | **High** | disasm prologue/epilogue |
| Virtual DATA dispatch @ `0x00a5a640` (+0x43C) | **High** | sole xref type DATA |
| Purpose = Arena Console CreateChildWidgets | **High** | XML domain + factory pattern + peer dialogs |
| Full slot↔XML map (19 children) | **High** | disasm `PUSH path; CALL [vtbl+0x28]` + host stores |
| Command ids 0x9c40–0x9c47 | **High** | disasm `PUSH imm; CALL [vtbl+0x74]` |
| Default tab = console (selected) | **High** | `MOV BL,1` before `00822cb0` on `+0x580` |
| Tournament/advanced collapsed + MoveToFront | **High** | `XOR BL,BL` + `CALL 00756c90` with EDI=tab |
| Mini size sentinel -99998.0f + 1200/1600 scale | **High** | `read_memory` + disasm COMISS/MULSS/DIVSS |
| No C2S / inventory wire in body | **High** | callee list is UI-only |
| Product RTTI / English class name | **Open** | keep `_Inferred` |
| Residual `FUN_00877790` / `008778e0` / `00877c50` / `00792600` semantics | **Tentative** | not OWN |
| Player global `DAT_00d1b6d8` identity | **Probable** | shared host object pattern |
| Runtime / bit-exact | **Open** | no Launcher — **never** Runtime Confirmed |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| SEH enter + host flag pre-init | **Yes** |
| Host vtbl prep + `FUN_00792600` | **Yes** |
| Repeated child factory (new→ctor-or-null→store→attach→load) | **Yes** |
| Buttons with command ids | **Yes** (disasm seals ids decompiler drops) |
| Three tabs + select/front policy | **Yes** |
| Mini overlay + optional size normalize | **Yes** |
| Post helpers + player gate + host `+0x34c` | **Yes** |
| No inventory C2S packets | **Yes** |

### Sealed CF sketch

```
UI_ArenaConsole_CreateChildWidgets_Inferred(host@ECX):
  SEH; clear +0x524/+0xc5; +0x4fc=0xf; +0x500=1
  host[+0x110]; host[+0x130]; FUN_00792600(host)
  build chrome/news/buttons/tabs/mini from i_d_arena_console_*.xml
  tab_console: SetSelected(1); tab[+0x94]
  tab_tournament: SetSelected(0); MoveToFront
  tab_advanced: SetSelected(0); MoveToFront
  mini-bg size normalize if host[+0x530|+0x534] ≤ -99998.f
  FUN_008778e0(host)
  if player && player[+0x4fc]: FUN_00877c50(host)
  host[+0x34c](); SEH leave; return
```

---

## 5. Naming

| Proposed | Status |
|---|---|
| `UI_ArenaConsole_CreateChildWidgets_Inferred` | **Accept INFERRED** — full console XML domain + factory + vtbl CreateChildWidgets family |
| `UI_arena_console_tab_tournament` | **Reject as canonical** — tournament is one tab of many |
| `Client_SendInventory*` / arena net host | **Reject** — no wire |
| `FUN_00878300` | Keep Ghidra residual synonym |

---

## 6. Gaps

1. Product / RTTI demangle of host class (`CDlgArenaConsole*` or similar).
2. Residual duals: `FUN_00792600`, `FUN_00877790`, `FUN_008778e0`, `FUN_00877c50`, tab ctor `FUN_008230b0`, base ctors.
3. Exact product meaning of host `+0x4fc=0xf` / player `+0x4fc` gate.
4. When virtual fires vs dialog show / arena net open.
5. Runtime capture; bit-exact image; differential.

**Verdict:** **accept-with-gaps** — ABI, body bounds, vtbl slot, full XML/slot/cmd table, tab policy, mini normalize sealed statically; product labels + residual helpers open. Terminal **false**.
