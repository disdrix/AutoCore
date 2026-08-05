# Annotated low-level: FUN_008aaf60 → Client_MissionDialog_SetHeaderCaption_Inferred

| Field | Value |
|---|---|
| Stable ID | `aa_008aaf60` |
| VA | `0x008aaf60`–`0x008ab098` (312 B) |
| System | `missions-progression` |
| Date | 2026-08-04 (WQ7R-A residual seal; supersedes 2026-07-23 scaffold) |
| Ghidra | `FUN_008aaf60` |
| Inferred name | `Client_MissionDialog_SetHeaderCaption_Inferred` |

## Machine-level notes

- **Role:** Apply or clear the mission/NPC dialog **header caption widget** at `dialog+0x6e0`.
- **EDI == 0:** clear/reset text path (vtbl `+0x1d8` + refresh `+0x34c`).
- **EDI != 0:** resolve caption string (`007a69d0`/`007a6de0`), optional mission-name format via `FUN_005465c0`, push processed text through `FUN_008aab00`, layout/refresh vcalls, optional show (`+0x1fc`) when global flag off or dialog state ∈ {2,3}.
- **Always (if widget non-null):** vtbl `+0x214(0)` then `FUN_008aa610`.
- Nested callees `005465c0` / `008aab00` / `008aa610` are **other agents' residual OWN** — document call order only; do not dual their bodies here.

## ABI

| Slot | Role | Evidence |
|------|------|----------|
| ECX | Dialog context (`param_1`) | `mov esi, ecx`; uses `+0x6e0`, `+0x648` |
| EDI | Caption key / name id (0 = clear) | `test edi`; `push edi` → `007a6de0` |
| Return | void; plain `C3` | epilogue |

## Offsets / vtable slots (body-backed)

| Site | Offset | Use |
|------|--------|-----|
| Dialog | `+0x6e0` | Header widget pointer (null → no-op entire body) |
| Dialog | `+0x648` | Dialog state; `2` or `3` forces show-path with `+0x1fc` |
| Widget vtbl | `+0x1d8` | Text clear/set entry (args **0,1,1** — decompiler lag) |
| Widget vtbl | `+0x1f0` | Post-set layout helper |
| Widget vtbl | `+0x34c` | Refresh |
| Widget vtbl | `+0x1fc` | Conditional show |
| Widget vtbl | `+0x214` | Common tail (arg 0) |
| Global | `DAT_00d1b21c` | When non-zero, skip `+0x1fc` unless state 2/3 |
| Global | `DAT_00d1b6d8` | Gates optional `FUN_005465c0` format |

## Pseudocode (annotated; lag fixed)

```c
// Client_MissionDialog_SetHeaderCaption_Inferred @ 0x008aaf60
// ECX = dialogCtx, EDI = captionKeyOrNull
void Client_MissionDialog_SetHeaderCaption_Inferred(int dialogCtx /*ecx*/, int captionKey /*edi*/)
{
  void* widget = *(void**)(dialogCtx + 0x6e0);
  if (widget == 0) return;

  // SEH setup omitted
  if (captionKey == 0) {
    // clear path
    (*(fn)(*(int*)widget + 0x1d8))(widget, 0, 1, 1);  // bytes push 1,1,0
    (*(fn)(*(int*)widget + 0x34c))(widget);
  } else {
    FUN_007a69d0();
    char* text = (char*)FUN_007a6de0(captionKey, 0xffffffff);
    std::string local(text);
    if (DAT_00d1b6d8 != 0) {
      FUN_005465c0(DAT_00d1b6d8, &local); // mission string format residual
    }
    (*(fn)(*(int*)widget + 0x1d8))(widget, 0, 1, 1);
    FUN_008aab00(widget);                 // chrome / [$] expand residual
    (*(fn)(*(int*)widget + 0x1f0))(widget);
    (*(fn)(*(int*)widget + 0x34c))(widget);
    if (DAT_00d1b21c == 0 ||
        *(int*)(dialogCtx + 0x648) == 2 ||
        *(int*)(dialogCtx + 0x648) == 3) {
      (*(fn)(*(int*)widget + 0x1fc))(widget);
    }
    // ~string
  }
  (*(fn)(*(int*)widget + 0x214))(widget, 0);
  FUN_008aa610(); // post header helper residual
}
```

## Call graph

```
Client_ShowNpcMissionDialogUI  ──×3──┐
Client_UpdateMissionJournal     ──×2──┼→ Client_MissionDialog_SetHeaderCaption_Inferred
FUN_0093e450 (choice dlg case0) ──×1──┘
         │
         ├─ FUN_005465c0   (WQ7R-D)
         ├─ FUN_008aab00   (WQ7R-C)
         └─ FUN_008aa610   (WQ7R-B)
```

## Open questions

- Product English for widget class and vtable slots.
- Exact type of EDI key (string id vs pointer) — body treats as `007a6de0` input.
- `DAT_00d1b21c` product meaning.
- Nested callee duals (owned elsewhere).
- Runtime / bit-exact.
