# Review A (reconstruction fidelity): `aa_007fef20` Client_OpenDialogByIndex

| Field | Value |
|---|---|
| **Stable ID** | `aa_007fef20` |
| **VA** | `0x007fef20` |
| **Canonical name** | `Client_OpenDialogByIndex` |
| **Ghidra name** | `FUN_007fef20` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual) |
| **Counterpart** | `reviews/B_aa_007fef20_Client_OpenDialogByIndex.md` |
| **System** | client UI / dialog table |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Primary client dialog-table open** on `this` (client):

```c
void __thiscall Client_OpenDialogByIndex(Client* this, int dialogIndex, char forceCloseIfOpen, char allowWhileDriving);
```

- Index range: **`0 .. 0x3a`** inclusive upper reject (`> 0x3a` return).
- Slot pointer: `*(this + 0x1030 + dialogIndex*4)`.
- Null slot → log `"Attempting to open null dialog %i."` via `FUN_007a4480` and return.

### High-level CF

1. `FUN_007fbfb0(dialogIndex)` — pre-open hook.
2. Load dialog from table `+0x1030`.
3. If **already visible** (`vtbl+0x3d8`) and `forceCloseIfOpen == 0`:
   - Call `FUN_007fca10` (close/flush current).
   - Scan table for another exclusive (`+0x500` / `pi[0x140]==1`) still open; if none, restore host `+0xf38` flag via `vtbl+0x3c4`; return.
4. If still visible after that path → return (already open / toggle done).
5. Drive / world gates: block open when driving (except index `0x29`) if `param_4==0` and drive probe `vtbl+0x194` true.
6. Modal conflict with `this+0x1084` exclusive dialog → close + recursive open `0x1d`.
7. Special blocks: indices `0x16`/`0x22` when client flag `+0xe04+0xf6==1`; index `0x34` may force close if state `+0xe98+0xd6c != 1`.
8. Optional sibling exclusive close via `FUN_007fcaf0` when `DAT_00afa140==0` and dialog `+0x4fc` (`pi[0x13f]`) set.
9. **Show path**: host `+0xf40` `vtbl+0xa8(dialog)`; dialog `vtbl+0x174(this+0xf48+index*4)`; dialog `vtbl+0x43c` (show/reset); ensure `vtbl+0xd0` then maybe `vtbl+0xcc(1)`.
10. Index-specific post: `0x15`, `0x1d`, `0x1e` touch string blob at `e04+0xe4f8+0x124` / `FUN_00857ee0` / `FUN_00899710`.
11. Optional `+0x10b0+0x664` `vtbl+0x47c`; host focus `+0xf40` `vtbl+0x3bc` unless `+0x1138` visible; `+0xf38` `vtbl+0x3c4(1)`; `FUN_0092f000`.

Known indices from input duals / mission duals:

| Index | Observed use |
|---|---|
| 0,1,2,3,4,5,… | Menu / inventory / map toggles (`PollBoundActions`) |
| `0x12` | vehicle switch failure reopen |
| `0x13` | mission journal-style reopen (`008af020`) |
| `0x1d` | exclusive modal swap target |
| `0x29` | special (OnKeyDown; bypass some drive gate) |
| `0x16`, `0x22`, `0x34` | gated specials |

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean | `raw/aa_007fef20_*`, `reconstructed-exact/FUN_007fef20.cpp` |
| Function record | `functions/aa_007fef20_FUN_007fef20.md` |
| Fresh decompile | Ghidra `batch_decompile` @ `0x007fef20` (2026-07-29) |
| Close sibling dual | `A_aa_007fca10_FUN_007fca10.md` |
| Mission close dual | `A_aa_008af020_*` (reopen index 0x13) |
| Callers | Input poll/keydown, mission UI, inventory, many `FUN_009*` |
| String | `"Attempting to open null dialog %i."` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Dialog table base `this+0x1030`, count 0..0x3a | **Confirmed** | body + close duals |
| Null log string | **Confirmed** | literal |
| Open uses `+0x43c` / attach `+0xa8` / pos `+0x174` | **Confirmed** | decompile |
| Toggle/close path via `007fca10` when visible & !force | **Confirmed** | |
| Drive gate except 0x29 | **High** | body |
| Full product name map for all 0x3b slots | **Open** | partial from callers |
| clean ≡ raw ≡ live CF | **High** | large but matches scaffold |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Bounds + null log | Yes |
| Visible + !force → close/scan | Yes |
| Drive / exclusive / special gates | Yes |
| Show attach + 0x43c | Yes |
| Index specials 0x15/1d/1e | Yes |
| Host restore + 0092f000 | Yes |

---

## 5. Callers / callees

| Direction | Symbol | Role |
|---|---|---|
| Caller | `Client_Input_PollBoundActions`, `OnKeyDown_MatchAction` | keybinds open menus |
| Caller | Mission UI (`008aec40` family, `008af020`) | reopen slots |
| Caller | Many UI residual `FUN_009*` | generic open |
| Callee | `FUN_007fbfb0` | pre-open |
| Callee | `FUN_007fca10` | close/flush visible |
| Callee | `FUN_007fcaf0` | exclusive sibling |
| Callee | dialog vtbls `+0x3d8/+0x43c/+0x174/+0xcc/+0xd0` | lifecycle |
| Self | recursive `FUN_007fef20(0x1d,1,0)` | modal swap |

---

## 6. Gaps / open

1. Full English enum for indices 0..0x3a.
2. Exact semantics of `forceCloseIfOpen` vs toggle (param_3 naming).
3. Drive probe object chain (`e98+0x250` … `+0x194`).
4. Runtime / bit-exact deferred.

**Verdict:** **accept-with-gaps** — open-dialog CF sealed; index lexicon Open.
