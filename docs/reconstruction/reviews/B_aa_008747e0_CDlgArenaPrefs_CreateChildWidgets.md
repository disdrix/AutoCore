# Review B (skeptical / adversarial): `CDlgArenaPrefs_CreateChildWidgets` @ `0x008747e0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_008747e0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_008747e0_CDlgArenaPrefs_CreateChildWidgets.md` |
| **Live tools** | Same Ghidra decompile + globals audit + string list + ctor spot-checks as A |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Authoritative **arena match rules engine** or server config writer | **Falsified** — body only allocates NDUI children and loads XML; no map/rules simulation |
| 2 | Sends arena create / host / prefs **C2S packet** during build | **Falsified** — no bitstream / sector send callees; host actions are button widgets only (handlers live elsewhere) |
| 3 | Finished bit-exact AutoCore port of full dialog | **Overstated** — clean is scaffold CF copy; ~100 XML↔slot pairings Tentative |
| 4 | Name proves class layout fully known | **Weak** — name + vtable DATA xref High; host sizeof / field names beyond child slots still open |
| 5 | Decompiler shows every XML path at call site | **Falsified** — only ~5 of ~100+ strings appear inline; rest recovered from `.rdata` xrefs via `audit_globals` / `list_strings` |
| 6 | `FUN_007b5dd0` is “label-only” | **Softened** — base window/widget ctor used for labels **and** textures/chrome; buttons/edits subclass it |
| 7 | Default title empty / locale string | **Falsified for empty** — `read_memory` @ `0x00a5c1b8` = **`"-------"`** (7 dashes + NUL); format `"%s's Arena"` when `DAT_00d1b6d8 != 0` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Function is CreateChildWidgets for Arena Prefs UI | **High** | Wrong system placement |
| Pure client construct (no net in body) | **High** | False C2S docs / bad intercept hooks |
| XML domain (match type, fees b/m/k/c, ranks, levels, factions, classes, victory, players 1–32) | **High** | Incomplete prefs UI port |
| Child ctor taxonomy (0x488 / 0x4cc / 0x4a4 / 0x4bc) | **High** | Wrong widget base classes |
| Per-slot offset → exact XML path for all 100+ children | **Tentative** | Cosmetic / layout bugs only if wrong |
| Full button command-id table | **Tentative** | Wrong click routing until handlers dual-reviewed |
| `DAT_00d1b6d8` = local player object | **Probable** | Title wrong until object typed |
| Host field `+0x4fc = 0xf` meaning | **Tentative** | Unknown flag semantics |

---

## 3. Cross-check against raw decompile

```
CDlgArenaPrefs_CreateChildWidgets(this):
  SEH enter;
  clear +0x518, +0xc5; +0x4fc = 0x0f;
  vtbl(+0x114); vtbl(+0x130); +0x510 = 0;
  FUN_00792600();                         // host prep
  // ~105×:
  //   p = new(size); p = p ? TypedCtor(p) : 0;
  //   this[slot] = p; this.vtbl+0xa8(p); p.vtbl+0x28(xml);
  //   optional: +0x74/+0xd4/+0x3b4/+0x3c8 (buttons),
  //             +0x3ac / flags (edits), +0x1d0/+0x1d8 (labels)
  title_widget = this+0x58c;
  if (DAT_00d1b6d8 == 0) text = "-------";
  else text = sprintf("%s's Arena", playerName_via_vtbl+0x160);
  title.vtbl+0x3ac(text); RTTI remeasure ×3 sites;
  // … mid-tree radios/checks/edits …
  this+0x504 = close button → i_d_arena_prefs_btn_close.xml;
  mini: +0x6d0 bg, +0x6d4 status, +0x6d8 cancel(+0x74, 0x9c61);
  hide a few children (+0xcc(0));
  this.vtbl+0x448(); this.vtbl+0x34c();
  SEH leave; return;
```

**CF clean ≡ raw:** Yes (scaffold preserves order; no modernization of control flow).

**Rep count:**
- `operator_new(0x488)` ×55 + `FUN_007b5dd0`
- `operator_new(0x4cc)` ×33 + `FUN_0079c860`
- `operator_new(0x4a4)` ×17 + `FUN_00795f20`
- `operator_new(0x4bc)` ×1 + `FUN_00864f20`
- parent-add `this+0xa8` ≈106; load `child+0x28` ≈106

---

## 4. What this is *not*

- Not arena match start, ladder scoring, or fee validation math.
- Not the click handlers that host/schedule/spectate (those are separate methods; this only **creates** the buttons).
- Not a complete type map of `CDlgArenaPrefs` — only child pointer band `+0x504`, `+0x524/528`, `+0x534…+0x6d8` and a few host flags sealed.
- Not proof that every radio is mutually exclusive at runtime (grouping is delegated to vtbl helpers; ids not fully recovered).

---

## 5. Surviving contract for AutoCore

```
// Client UI only — safe to call when opening Arena Prefs dialog.
// Do not treat as match-config commit.
void CDlgArenaPrefs_CreateChildWidgets(CDlgArenaPrefs* self);

// Required assets: i_d_arena/i_d_arena_prefs*.xml set
// (match type radios, player-count radios, victory points/timed,
//  entry fee + value max currency edits b/m/k/c, rank/level min/max,
//  faction+class filters, spectators, password/name/description,
//  host/schedule/leaderboard/archives/spectate/console/close,
//  mini status overlay).

// Title:
//   if (g_playerObj) SetText("%s's Arena", name);
//   else SetText("-------");

// Network: none in this function.
```

---

## 6. Open questions (must not silently “seal”)

1. Map **each** `self+offset` child to its XML (scripted call-site push analysis).
2. Recover **all** `+0x74` / check command immediates (beyond mini cancel `0x9c61`).
3. Name `DAT_00d1b6d8` and the `+0x160` name getter.
4. Dual-review host dialog ctor + button handlers that *use* this tree.
5. Confirm vtable index of this method at `0x00a5aef0` (slot ordinal).

---

## 7. Agreement with A

| Topic | A | B | Joint |
|---|---|---|---|
| Purpose | CreateChildWidgets UI | Same after attack | **High** |
| No C2S in body | High | High | **Sealed** |
| XML domain completeness | High | High | **Sealed** (paths); slot map Tentative |
| Verdict | accept-with-gaps | accept-with-gaps | **Joint: accept-with-gaps** |

**Verdict:** **accept-with-gaps**
