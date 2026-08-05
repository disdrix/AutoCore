# Annotated low-level: EnsureQuestCreditsLookupLoaded

| Field | Value |
|---|---|
| Stable ID | `aa_00512830` |
| VA | `0x00512830` |
| System | missions-progression |
| Date | 2026-07-29 (dual A/B refresh) |

## Machine-level notes

- Source: raw capture for `aa_00512830` + 2026-07-29 `read_memory` seal.
- Prefer assembly when decompiler conflicts (ECX plumbing; plate early-out).
- Enter/leave helpers are **DB connection refcount** (`ctx+0x20`), not a critical section.
- Ready-flag gate is on **callers** (`Mission_ComputeObjectiveCredits` reads `0x00b04260`), not this body.
- Sibling `EnsureQuestBaseCreditsLoaded` @ `0x00512870` is byte-isomorphic with map imm `0x00b04264`.

## Pseudocode (asm-corrected)

```c
// NOTE: plate "if already loaded / sets flag" is aspirational — not in body.
void EnsureQuestCreditsLookupLoaded(void)
{
  void *pCtx;
  int nStatus;

  pCtx = g_pDbReaderCtx_Inferred;           // *[0x00b0469c]
  FUN_007e1d80(pCtx);                       // enter

  pCtx = g_pDbReaderCtx_Inferred;
  nStatus = LoadQuestCreditsLookupFromWad(
      pCtx,
      &g_pQuestCreditsLookupMap_Inferred); // push 0x00b04258; call 0x007cc470

  pCtx = g_pDbReaderCtx_Inferred;
  FUN_007b7df0(pCtx);                       // leave

  if (nStatus < 0) {
    FUN_007a4480(0, "VOG_DEBUG_STOP");      // str @ 0x00a15844
  }
}
```

## Original decompiler view (for diff)

```c
void EnsureQuestCreditsLookupLoaded(void)
{
  int iVar1;
  FUN_007e1d80();
  iVar1 = LoadQuestCreditsLookupFromWad(&g_pQuestCreditsLookupMap_Inferred);
  FUN_007b7df0();
  if (iVar1 < 0) {
    FUN_007a4480(0,"VOG_DEBUG_STOP");
  }
  return;
}
```

## Open questions

- Writer of `g_nQuestCreditsLookupLoaded_Inferred` (`0x00b04260`).
- Product names for `FUN_007e1d80` / `FUN_007b7df0`.
- Idempotency of `LoadQuestCreditsLookupFromWad` on re-entry.
