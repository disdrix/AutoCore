# Annotated low-level: Combat_ComputeBaseCritChance_FromHost (FUN_004c4dd0)

| Field | Value |
|---|---|
| Stable ID | `aa_004c4dd0` |
| VA | `0x004c4dd0`–`0x004c4e1d` (77 B) |
| Canonical name | `Combat_ComputeBaseCritChance_FromHost` |
| Ghidra name | `FUN_004c4dd0` |
| System | combat-crit |
| Date | 2026-07-29 W23-K dual seal |

## Machine-level notes

- Live decompile ≡ raw; 77 B body hex sealed; **no** stack formals; return **ST0**.
- ECX = host from attacker skill-bind path (`vtbl+0x214`) or character-sheet host.
- FPU order seals: both level (vcall `+0x27c`) and perception score (`FUN_004c41c0`) multiplied by **0.001**, summed, × **0.125**, + **0.02**.
- Constants at `0x00a0f72c` / `0x00a110c0` / `0x00aaa7b8` verified via `read_memory`.
- UI caller `FUN_008f97c0` labels result **"Base Critical Hit Chance"** (Perception section).
- Parent `Combat_ComputeCritChance_Inferred` uses this when bind non-null; no-bind path is `level*0.001*0.25+0.05`.

## Pseudocode (annotated)

```c
// ECX = host (skill bind / GO with vbtable @ +4)
// return chance fraction in ST0
float Combat_ComputeBaseCritChance_FromHost(void *host)
{
  // MI this = host + *(vbtable+4) + 4
  int level = vcall(host_mi, 0x27c);          // level-like
  // ST0 = (float)level * 0.001f   [g_flMsToSeconds_Inferred @ 0x00a0f72c]
  int score = FUN_004c41c0(host);             // perception-capped short→int
  // ST0 = (score * 0.001f) + (level * 0.001f)
  // ST0 = ST0 * 0.125f + 0.02f
  return ((float)score + (float)level) * 0.001f * 0.125f + 0.02f;
}
```

## Open questions

- Product English for vcall `+0x27c` (level vs other rating).
- Full semantics of `FUN_004c41c0` gate (`+0x1dc`) — not owned.
- Exact type of host from `vtbl+0x214` (bind object vs character self).
