# Review A (reconstruction fidelity): `aa_00845360` UI_AppendItemRequirements

| Field | Value |
|---|---|
| **Stable ID** | `aa_00845360` |
| **VA** | `0x00845360` |
| **Body span** | `00845360` – `00845871` (**~1298** bytes) |
| **Canonical name** | `FUN_00845360` (Ghidra) |
| **Proposed name** | `UI_AppendItemRequirements` (**High** role) |
| **Rejected alias** | `Named_Combat_00845360` — Combat is one line only |
| **Review date** | `2026-07-29` (OWN-ONLY dual A/B W23-J) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live decompile ≡ instructions) |
| **Counterpart** | `reviews/B_aa_00845360_UI_AppendItemRequirements.md` |
| **System** | UI / item tooltip requirements |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

UI helper that builds the item **requirements** text block:

1. Gate on show-flag, item category `0x1a`, and local player presence.
2. Early-out if no Level/race/class/stat requirements are active.
3. Append localized **`"Requires:"`** header (color `0xffbbbbbb`).
4. Optionally append Level, race, class, Combat, Tech, Theory, Perception lines — white if player meets, red (`0xffff2020`) if not.
5. Return **line count** (0 if nothing shown).

**ABI:** item/template in **EAX**; stack UI text object + enable char; plain `ret`.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00845360_FUN_00845360.md` |
| Annotated | `docs/reconstruction/raw/aa_00845360_FUN_00845360.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00845360.cpp` |
| Named clean | `docs/reconstruction/reconstructed-exact/UI_AppendItemRequirements.cpp` |
| Function record | `docs/reconstruction/functions/aa_00845360_FUN_00845360.md` |
| Stat getters (context) | Combat `004c4070`, Theory `004c4140`, Perception `004c41c0`, Tech `004c3ff0` |
| Race/class tables | `FUN_0051f8e0`, `FUN_0051f940` |
| Tech string | `DAT_00a2e4fc` = `"Tech"` (`read_memory`) |

**This pass (live):** `decompile_function` @ `0x00845360` + callees listed above; `read_memory` entry 128 B + epilogue family + `"Tech"` string; `get_function_by_address` / callees / callers / xrefs. **Not performed:** `disassemble_bytes`, Launcher, runtime, parent ledger edits.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body span / frame `sub esp,0x8c` / plain ret | **High** | entry + epilogue bytes |
| Item in **EAX→ESI** | **High** | `8b f0` at entry |
| Show flag stack; `0` → return 0 | **High** | `cmp [esp+0xa0],bl` + jz |
| Category `0x1a` suppresses | **High** | `cmp dword [ecx+0x38],0x1a` |
| `DAT_00d1b6d8` local player required | **High** | null → 0; later race/class/stat source |
| Header `"Requires:"` + color `0xffbbbbbb` | **High** | decomp + string |
| Level / Combat / Tech / Theory / Perception product names | **High** | `FUN_007a6de0` literals + `"Tech"` DAT |
| Fail color `0xffff2020`, met `0xffffffff` | **High** | immediates in decomp |
| Race table Human/Mutant/Biomek | **High** | live `FUN_0051f8e0` |
| Class name table via `FUN_0051f940` | **High** | live decompile |
| Item req shorts `+0xe8..+0xf2` map | **High** | exclusive use sites |
| Return = line count | **High** | init 1 after header; increments; Perception decomp `unaff_EBP+1` hazard |
| Callers ×3 functions / 4 sites | **High** | live xrefs |
| Product C++ method symbol | **Probable** | role High; symbol open |
| Category `0x1a` English | **Open** | constant only |
| Runtime tooltip golden | **Open** | not run |

---

## 4. Control flow: clean ≡ raw ≡ live ≡ instructions

| Stage | Match |
|---|---|
| Frame + save EBX/ESI/EDI; ESI=EAX item | **Yes** |
| String table singleton → EDI | **Yes** (`FUN_007a69d0`) |
| Triple early-out (flag / type 0x1a / no player) | **Yes** |
| Empty-req cascade → return 0 | **Yes** |
| Header append vfunc `+0x224` | **Yes** |
| Level / race / class / four stats | **Yes** |
| Multi exit `add esp,0x8c; ret` | **Yes** |

### 4.1 Requirement layout (item)

| Offset | Use |
|--------|-----|
| `+0xa8` → nested | def holder; nested `+0x38` type; nested `+0x3c` def* |
| def vfunc `+0x14` | race id (-1 none) |
| def `+0x3e0` | class id (-1 none) |
| `+0xe8`, `+0xea` | level shorts (sum; `FUN_0040f540` caps display/compare at 80) |
| `+0xec` | Combat req |
| `+0xee` | Perception req |
| `+0xf0` | Tech req |
| `+0xf2` | Theory req |

### 4.2 Player compare sources

| Line | Player source |
|------|----------------|
| Level | vfunc `+0x27c` on local player component chain |
| Race | byte `@ player_creature+0x532` vs item race |
| Class | byte `@+0x531` vs item class; name via race for table |
| Combat | `FUN_004c4070(player)` |
| Tech | `Character_GetTechForPoolCalcs(DAT_00d1b6d8)` |
| Theory | `FUN_004c4140(player)` |
| Perception | `FUN_004c41c0(player)` |

### 4.3 Pseudocode (sealed summary)

```c
// EAX=item, stack: UIText *text, char show
int UI_AppendItemRequirements(UIText *text, char show, Item *item /*EAX*/)
{
    FUN_007a69d0(); // string table
    if (!show || type(item) == 0x1a || g_localPlayer == NULL)
        return 0;
    if (reqs_all_empty(item))
        return 0;

    int lines = 1;
    text->vtbl[0x224/4](L("Requires:"), 0xffbbbbbb);

    // Level if active: sprintf "\n%s %i", color by playerLevel vs itemLevel
    // Race if raceId != -1: name via FUN_0051f8e0; met → vfunc+0x250 else red +0x224
    // Class if classId != -1: FUN_0051f940; bVar3 fail flag; color similarly
    // Combat/Tech/Theory/Perception if req short > 0: "\n%i %s", compare getters

    return lines;
}
```

---

## 5. Callers (live xrefs 2026-07-29)

| Function | Sites | Role (CF) |
|----------|-------|-----------|
| `FUN_00843a60` | `0x0084412d` | UI path (item detail) |
| `FUN_0084b890` | `0x0084c40e` | UI path |
| `FUN_0088d980` | `0x0088da8f`, `0x0088db44` | vehicle load UI next to `UI_BuildItemTooltipStats` |

**4** `UNCONDITIONAL_CALL` sites / **3** caller functions.

---

## 6. Gaps / open

1. Product C++ method / UI class owning text vfuncs `+0x224` / `+0x250`.
2. English meaning of category/type **`0x1a`**.
3. Level shorts: structural sum sealed; base-vs-bonus English open.
4. Class-line fail logic coupling race mismatch (`bVar3`) — sealed as coded; design English open.
5. Runtime tooltip capture / differential.
6. Deep dual of callers `00843a60` / `0084b890` (out of OWN scope).

**Verdict:** **accept-with-gaps** — ABI, gates, field map, product line strings, colors, getters, and caller inventory sealed static; package not complete (runtime / type 0x1a / product symbol).
