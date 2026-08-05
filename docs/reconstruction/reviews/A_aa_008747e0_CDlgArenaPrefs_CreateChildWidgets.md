# Review A (reconstruction fidelity): `aa_008747e0` CDlgArenaPrefs_CreateChildWidgets

| Field | Value |
|---|---|
| **Stable ID** | `aa_008747e0` |
| **VA** | `0x008747e0` |
| **Canonical name** | `CDlgArenaPrefs_CreateChildWidgets` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_008747e0_CDlgArenaPrefs_CreateChildWidgets.md` |
| **System tag** | `client-ui` / arena prefs |
| **Live tools** | Ghidra `decompile_function` + `audit_globals_in_function` + `list_strings` + `read_memory` + `get_function_xrefs` + batch ctor decompiles (no `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**High.** Host-dialog virtual that **constructs and XML-loads the entire Arena Preferences child widget tree** under `i_d_arena/i_d_arena_prefs_*.xml`. This is pure client UI scaffolding: allocate NDUI children, parent them onto the dialog (`this` vtbl `+0xa8`), load each child’s skin/XML (`child` vtbl `+0x28`), then apply type-specific setup (button command ids, radio grouping, edit defaults, title text). **No sector/auth packet send** in this body.

Plate (Ghidra): *Arena prefs host UI: construct/load child widgets from i_d_arena/i_d_arena_prefs_\*.xml (match type, fees, ranks, factions, victory). thiscall on arena prefs window. Vtable DATA xref 0x00a5aef0.*

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_008747e0_CDlgArenaPrefs_CreateChildWidgets.md` |
| Annotated | `docs/reconstruction/raw/aa_008747e0_CDlgArenaPrefs_CreateChildWidgets.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CDlgArenaPrefs_CreateChildWidgets.cpp` |
| Function record | `docs/reconstruction/functions/aa_008747e0_CDlgArenaPrefs_CreateChildWidgets.md` |
| Counterpart dual | `docs/reconstruction/reviews/B_aa_008747e0_CDlgArenaPrefs_CreateChildWidgets.md` |

---

## 3. Signature / calling convention

| Claim | Confidence | Evidence |
|---|---|---|
| `__thiscall` / decompiler `__fastcall` with **ECX = `CDlgArenaPrefs*` host** | **High** | Single `this` param; all child stores relative to `this` |
| Return `void` | **High** | Falls through to SEH restore + `return` |
| Virtual slot on dialog vtable | **High** | Sole xref is **DATA** from `0x00a5aef0` (vtable entry), not a direct CALL site |
| MSVC SEH frame | **High** | `ExceptionList` chain; unwind `LAB_009b52e7` |

---

## 4. Control-flow stages (clean ≡ raw)

| Stage | Match | Notes |
|---|---|---|
| 1. Host pre-init flags + vtbl prep | Yes | `this+0x518=0`, `this+0xc5=0`, `this+0x4fc=0xf`; vtbl `+0x114`, `+0x130`; `this+0x510=0`; `FUN_00792600()` |
| 2. Repeated child factory | Yes | `operator_new` → ctor-or-null → store at host slot → parent add (`this` vtbl `+0xa8`) → load XML (`child` vtbl `+0x28`) |
| 3. Type-specific post-setup | Yes | Buttons: vtbl `+0x74` / `+0xd4` / `+0x3b4` / `+0x3c8`; edits: `+0x3ac` + flags `@+0x48b/+0x489/+0x48c`; labels: occasional `+0x1d8` / `+0x1d0` |
| 4. Dynamic title | Yes | If `DAT_00d1b6d8==0` use default string at `DAT_00a5c1b8` (`"-------"`); else vtbl chain `+0x160` name + `sprintf("%s's Arena")` into edit/label at `this+0x58c` |
| 5. RTTI parent remeasure (×3) | Yes | `__RTDynamicCast` CNDUIDialog↔CNDUIWindow; if parent window owns widget, vtbl `+0x1c8` / `+0x3c0` |
| 6. Mini-panel + close | Yes | Close btn at `this+0x504` loads `…btn_close.xml`; mini bg/status/cancel at `+0x6d0/+0x6d4/+0x6d8` |
| 7. Host finalize | Yes | Host vtbl `+0x448`, `+0x34c`; restore `ExceptionList` |

**No invented modernizations** in clean plate: same CF / call order as raw decompile.

---

## 5. Child factory taxonomy (High)

| Ctor | `operator_new` size | Count in body | Role (from use + subclass shape) |
|---|---|---:|---|
| `FUN_007b5dd0` | `0x488` | ~55 | Base NDUI window/label/texture widget (vtbl `PTR_FUN_00a960ac`) |
| `FUN_0079c860` | `0x4cc` | 33 | Button subclass (extends base; vtbl `PTR_FUN_00a97c34`) — radios/checks/action buttons |
| `FUN_00795f20` | `0x4a4` | 17 | Edit / text-entry subclass (vtbl `PTR_FUN_00a98b1c`) |
| `FUN_00864f20` | `0x4bc` | 1 | Special FX/panel widget at `this+0x538` (vtbl `PTR_FUN_00a61504`) |
| `FUN_00792600` | n/a | 1 | Host prep (resolution / child-hash reparent) before tree build |

Null-safe pattern throughout: if `operator_new` fails, store **0** and still attempt parent/load calls (retail risk on OOM path).

**Host child-pointer span:** stores to `this+0x534` … `this+0x6d8`, plus close at **`this+0x504`**. Also writes mini-bg size pair to **`this+0x524` / `this+0x528`**. ~**105** child pointer stores.

---

## 6. XML inventory (High — string table + `audit_globals`)

All paths live under `i_d_arena/`. Representative sealed groups:

| Domain | Example paths (complete set in `.rdata` `0x00a5af38`–`0x00a5c638`) |
|---|---|
| Shell | `i_d_arena_prefs.xml`, `…wnd_bg_fill.xml`, `…wnd_bg_texture.xml`, `…wnd_fx.xml`, `…btn_close.xml` |
| Nav / host actions | `…btn_host_now.xml`, `…btn_event_schedule.xml`, `…btn_leaderboard.xml`, `…btn_archives.xml`, `…btn_spectate.xml`, `…btn_console.xml` |
| Match meta | labels/edits: match **name / description / password / password_size**; **allow_spectators** check |
| Ranks / levels | `…label/edit_rank_minimum|maximum`, `…label/edit_level_minimum|maximum`, `…label_value_maximum` |
| Entry fee & value max | currency lanes **b/m/k/c** for `entry_fee_*` and `value_maximum_*` |
| Match type radios | deathmatch, gauntlet, tournament; ladder variants: assault, conquest, trifaction, faction, clan, deathmatch |
| Player count radios | 1 / 2 / 4 / 8 / 16 / 32 + max-participants label |
| Victory | points vs timed radios + matching edits/labels |
| Faction / class filters | human / mutant / biomek checks; ranger / officer / engineer / commando checks |
| Season chrome | `…label_current_date|season|team` |
| Mini overlay | `…mini_wnd_bg_texture.xml`, `…mini_wnd_label_status.xml`, `…mini_btn_cancel.xml` |

**Recovered inline in decompiler (subset):**
- `"i_d_arena/i_d_arena_prefs_wnd_label_rank_minimum.xml"` → widget at `this+0x57c`
- `"%s's Arena"` + default `"-------"` @ `0x00a5c1b8` → title widget `this+0x58c`
- `"i_d_arena/i_d_arena_prefs_btn_close.xml"` → `this+0x504`
- mini trio → `this+0x6d0 / 0x6d4 / 0x6d8`

Decompiler drops most XML string args (stack/register ABI); **string inventory is authoritative via data xrefs**, not the truncated pseudocode alone.

---

## 7. Notable host / child field writes

| Site | Value | Conf | Role |
|---|---|---|---|
| `this+0x4fc` | `0xf` | High | Host mode / flags dword (arena-prefs specific) |
| `this+0x518`, `+0xc5`, `+0x510` | `0` | High | Boolean/state clears before build |
| Edit flag `child+0x48b = 1` | many edits | High | NDUI edit “active/enabled” style bit (same pattern as other dialogs) |
| Title widget `+0x489 = 1` | `this+0x58c`, `+0x5f4`, `+0x5f8` | High | Text layout / autosize flag before RTTI remeasure |
| Victory edit `child+0x48c = 1` | `this+0x594` | Probable | Related edit flag |
| Mini bg `child+0xc4 = 1` | `+0x6d0`, `+0x6d4` | High | Visibility / layer bit |
| Mini cancel `+0x74(0x9c61)` | `this+0x6d8` | High | Button command/action id **0x9c61** |
| `this+0x524/0x528` | size from mini bg `+0x120` | High | Cached dimensions |

---

## 8. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Purpose = arena prefs **CreateChildWidgets** only | **High** | Name, plate, XML set, vtable slot |
| UI construct; **no C2S** in this function | **High** | No net helpers; only NDUI + sprintf + RTTI |
| Child type split by ctor size / FUN | **High** | Counts match new×ctor pairs |
| XML domain covers match type, fees, ranks, factions, victory | **High** | Full string list |
| Dynamic `"%s's Arena"` title when player object present | **High** | CF + format + `DAT_00d1b6d8` gate; default `"-------"` via `read_memory` |
| Exact host offset ↔ every XML path | **Tentative** | Most path args lost in decompile; only a few pairings sealed |
| Semantics of every vtbl slot (`+0x74`, `+0x3b4`, …) | **Probable** | Pattern-shared across UI; not re-proven per slot here |
| `FUN_00792600` host prep details | **Probable** | Own-VA scope; decompile shows resolution/hash reparent |
| Button action ids beyond mini cancel `0x9c61` | **Tentative** | Decompiler drops most imm args |

---

## 9. Gaps / open questions

1. **Full slot map:** pair every `this+0xNNN` child pointer to its exact XML path (needs stack-arg recovery or CE/scripted xref-at-callsite).
2. **Radio group ids / check command ids** passed to vtbl `+0x74` / `+0x3b4` — only mini cancel `0x9c61` sealed in decompile tail.
3. **Identity of `DAT_00d1b6d8`** (player/char host for name) — heavily used global; not renamed in this pass.
4. **When this virtual fires** relative to dialog show / arena net open (caller is vtable only).
5. Clean plate still scaffold-level (generic `FUN_*`); fidelity of CF is High, readability not sealed.

---

## 10. Surviving contract for AutoCore

```
CDlgArenaPrefs::CreateChildWidgets(this):
  // client-only UI tree build for Arena Preferences
  clear host flags; prep host (FUN_00792600);
  for each child in i_d_arena/i_d_arena_prefs_*.xml set:
    new + typed ctor (window 0x488 / button 0x4cc / edit 0x4a4 / fx 0x4bc);
    parent(this); loadXml(path); type-specific setup;
  title = playerName ? sprintf("%s's Arena") : "-------";
  build mini overlay + close button;
  host finalize vtbl +0x448 / +0x34c;
  // no network
```

**Verdict:** **accept-with-gaps**
