# Annotated low-level: FUN_0071ffc0 / CSoundManager_EraseNamedRecordByName_Inferred

| Field | Value |
|---|---|
| Stable ID | `aa_0071ffc0` |
| VA | `0x0071ffc0` |
| System | client audio / `CSoundManager` |
| Date | 2026-07-29 (OWN-ONLY dual W16-L) |
| Structural name | `CSoundManager_EraseNamedRecordByName_Inferred` |

---

## Machine-level notes

- Source: raw capture for `aa_0071ffc0` reconfirmed live 2026-07-29.
- **ABI (sealed):** stack `char* name` only; **`ret 4`**. Object pointer is **ESI** (not ECX thiscall at entry) — callers keep manager in ESI (parent `FUN_007203b0` is `__thiscall` and preserves ESI as `this`).
- **Lock:** `EnterCriticalSection(manager+0x170)` / Leave on every path. Distinct from MarkStopByName CS at **`+0x158`**.
- **Two dense arrays of 200-byte records** (stride `0xC8`):
  - Range A: `[*(+0x44), *(+0x48))` — begin/end pointers
  - Range B: `[*(+0x54), *(+0x58))`
- **Name key:** C-string at **start of each record** (`_stricmp(record, name)`).
- **Erase:** `FUN_00480970(match+200, end, match)` — block-move of **0x32 dwords (200 B)** chunks, shifting tail down onto match; then `end -= 200`.
- **First-match only:** match in range A → erase, unlock, **return** (does not scan B). Match in B after A miss → erase once. No match → unlock return.
- **Not** the channel-slot stop mark at `slot+0x48` (that is `FUN_007203b0`). This unit erases **queue/record tables** at manager `+0x44` / `+0x54`.

## Pseudocode (annotated)

```c
// void CSoundManager_EraseNamedRecordByName(CSoundManager* mgr /*ESI*/, const char* name)
// ret 4 (stdcall-style stack cleanup of name)
void FUN_0071ffc0(char *name)
{
  LPCRITICAL_SECTION cs = (LPCRITICAL_SECTION)(esi + 0x170);  // esi = manager
  char *it;
  int cmp;

  EnterCriticalSection(cs);

  // --- range A: [+0x44, +0x48) stride 200 ---
  it = *(char **)(esi + 0x44);
  if (it != *(char **)(esi + 0x48)) {
    do {
      cmp = _stricmp(it, name);
      if (cmp == 0) {
        // erase it: move [it+200, end) → it; end -= 200
        FUN_00480970(it + 200, *(void **)(esi + 0x48), it /*, name unused 4th push */);
        *(int *)(esi + 0x48) = *(int *)(esi + 0x48) - 200;
        LeaveCriticalSection(cs);
        return;
      }
      it = it + 200;
    } while (it != *(char **)(esi + 0x48));
  }

  // --- range B: [+0x54, +0x58) stride 200 ---
  it = *(char **)(esi + 0x54);
  if (it != *(char **)(esi + 0x58)) {
    while ((cmp = _stricmp(it, name)) != 0) {
      it = it + 200;
      if (it == *(char **)(esi + 0x58)) {
        LeaveCriticalSection(cs);
        return;
      }
    }
    FUN_00480970(it + 200, *(void **)(esi + 0x58), it /*, name */);
    *(int *)(esi + 0x58) = *(int *)(esi + 0x58) - 200;
  }

  LeaveCriticalSection(cs);
}
```

## Call graph (this unit)

| Direction | Symbol | Role |
|---|---|---|
| Callee | `EnterCriticalSection` / `LeaveCriticalSection` | lock `+0x170` |
| Callee | `_stricmp` | case-insensitive name match |
| Callee | `FUN_00480970` | 200-byte element erase (shift) |
| Caller | `FUN_007203b0` | `CSoundManager_MarkStopByName` when `doExtra != 0` |
| Caller | `FUN_00721a80` | music play path after `CreateStreamingMusic` fail |

## Open questions

- Product English name of the two 200-byte record tables (pending music vs SFX queue?).
- Full record layout beyond name-at-`+0` (200 B blob).
- Whether ESI-this is intentional shared convention across CSoundManager methods or only these sites.
- Runtime not run.
