# Function record: UI_MissionJournalRow_ApplySelection_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0082a050` |
| **Canonical name** | `UI_MissionJournalRow_ApplySelection_Inferred` |
| **Ghidra name** | `FUN_0082a050` |
| **Address** | `0x0082a050`–`0x0082a35d` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `missions-progression` / journal UI |
| **Calling convention** | Register: **ECX**=row widget, **EAX**=selection triple*; `ret` |
| **Completion status** | **Sealed** — dual A/B W24-K 2026-07-29; selection chrome + `(Complete)` High |
| **Bit-for-bit / runtime / diff** | Open |

## Alias

- `FUN_0082a050`
- `Named_CalleeOf_Named_VOG_DEBUG_STOP_0082a050` (legacy scaffold — misleading)

## Purpose

Apply journal-row selection into title / complete-label chrome. Kind 1 formats `"[level] name"` and uses `CVOGCharacter_IsMissionJournalReady` for `"(Complete)"`. Always layout via `FUN_00829fa0`.

## Signature

```c
void __fastcall UI_MissionJournalRow_ApplySelection_Inferred(
    void* row_widget /*ECX*/,
    SelectionTriple* sel /*EAX*/);
```

## Behavioral summary (sealed)

1. Null/kind0 → clear `+0x500..+0x508`, hide title, layout.
2. Kind1 → mission title sprintf; optional recolor; journal-ready label.
3. Kind2 → title from `p2+0x10`.
4. Complete label widget: `"(Complete)"` iff local char + mission + IsMissionJournalReady.
5. `FUN_00829fa0` layout (both exits).

## Callers / callees

| Direction | Address / name | Role |
|---|---|---|
| Caller | `FUN_008a4900` `0x008a4b84` | journal family |
| Caller | `FUN_008a5240` `0x008a558f`, `0x008a59d8` | journal rebuild (active hash walk) |
| Callee | `FUN_0052b3b0` | `CVOGCharacter_IsMissionJournalReady` |
| Callee | `FUN_00829fa0` | row layout |
| Callee | `FUN_007a6de0` / `sprintf` | name + title format |

## Confidence by dimension

| Dimension | Level | Rationale |
|---|---|---|
| Function boundary | **High** | body end `ret` + `CC`; next @ `0x0082a360` |
| ECX/EAX ABI | **High** | entry movs + call-site `lea eax,[esp+…]` / `mov ecx,row` |
| Kind 1 title format | **High** | sprintf string + level@mission+0x11c |
| Complete via journal-ready | **High** | sole `"(Complete)"` xref; sealed callee dual |
| Product English name | **Probable** | inferred from journal callers |
| Overall static | **High** | dual W24-K |

## Related artifacts

| Kind | Path |
|---|---|
| Raw | `raw/aa_0082a050_FUN_0082a050.md` |
| Annotated | `raw/aa_0082a050_FUN_0082a050.annotated.md` |
| Clean | `reconstructed-exact/UI_MissionJournalRow_ApplySelection_Inferred.cpp` |
| Dual A | `reviews/A_aa_0082a050_UI_MissionJournalRow_ApplySelection_Inferred.md` |
| Dual B | `reviews/B_aa_0082a050_UI_MissionJournalRow_ApplySelection_Inferred.md` |
| Callee dual | `A/B_aa_0052b3b0_CVOGCharacter_IsMissionJournalReady.md` |

## Open questions

- Retail product symbol for the row widget class.
- Kind 2 payload product type (string-bearing object @ `p2+0x10`).
- Exact vtbl product names for set-text / show / color slots.
