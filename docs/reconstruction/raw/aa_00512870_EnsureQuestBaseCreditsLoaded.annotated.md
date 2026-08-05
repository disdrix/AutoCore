# Annotated low-level: EnsureQuestBaseCreditsLoaded

| Field | Value |
|---|---|
| Stable ID | `aa_00512870` |
| VA | `0x00512870` |
| Body | `0x00512870`–`0x005128ad` (62 bytes → `ret`) |
| System | missions-progression |
| Date | 2026-07-23; dual seal 2026-07-29 |

## Machine-level notes

- Source: raw capture for `aa_00512870` + 2026-07-29 `read_memory` seal.
- Prefer assembly when decompiler conflicts (decompiler hides ECX this-passing).
- Plate “if already loaded: return” / “sets g_nQuestBaseCreditsLoaded” is **caller / loader** behavior — **not** this body.
- Sibling `EnsureQuestCreditsLookupLoaded` @ `0x00512830` is byte-isomorphic with map imm `0x00b04258` / Load `0x007cc470`.

## Asm-sealed control flow

```text
00512870  8B0D9C46B000      mov  ecx, dword ptr [0x00b0469c]   ; g_pDbReaderCtx*
00512876  56                push esi
00512877  E804F52C00        call FUN_007e1d80                   ; enter / refcount++
0051287C  8B0D9C46B000      mov  ecx, dword ptr [0x00b0469c]
00512882  686442B000        push 0x00b04264                     ; &g_pQuestBaseCreditsMap
00512887  E8849F2B00        call LoadQuestBaseCreditsFromWad    ; 0x007cc810
0051288C  8B0D9C46B000      mov  ecx, dword ptr [0x00b0469c]
00512892  8BF0              mov  esi, eax                       ; load status
00512894  E857552A00        call FUN_007b7df0                   ; leave / refcount--
00512899  85F6              test esi, esi
0051289B  5E                pop  esi
0051289C  7D0F              jge  005128ad                       ; status >= 0 → ret
0051289E  684458A100        push 0x00a15844                     ; "VOG_DEBUG_STOP"
005128A3  6A00              push 0
005128A5  E8D61B2900        call FUN_007a4480
005128AA  83C408            add  esp, 8
005128AD  C3                ret
```

## Pseudocode (annotated — decompiler shape + ECX)

```c
/* EnsureQuestBaseCreditsLoaded — ensure-load wrapper for tQuestBaseCredits.

   Body always runs enter → LoadQuestBaseCreditsFromWad → leave.
   Callers (Mission_ComputeObjectiveCredits) gate on g_nQuestBaseCreditsLoaded @ 0x00b0426c.
   Columns (loader plate): IDTargetLevel → intBaseCredits (int @ record+0x10). */

void EnsureQuestBaseCreditsLoaded(void)
{
  int nStatus;
  void *pCtx;

  pCtx = g_pDbReaderCtx_Inferred;              /* *[0x00b0469c] */
  FUN_007e1d80(pCtx);                          /* ECX = ctx */
  pCtx = g_pDbReaderCtx_Inferred;
  nStatus = LoadQuestBaseCreditsFromWad(pCtx, &g_pQuestBaseCreditsMap_Inferred);
                                               /* ECX=ctx; stack push 0x00b04264; VA 0x007cc810 */
  pCtx = g_pDbReaderCtx_Inferred;
  FUN_007b7df0(pCtx);
  if (nStatus < 0) {
    FUN_007a4480(0, "VOG_DEBUG_STOP");         /* str @ 0x00a15844 */
  }
}
```

## Globals

| VA | Name | Role |
|---|---|---|
| `0x00b0469c` | `DAT_00b0469c` / `g_pDbReaderCtx_Inferred` | DB reader this for enter/load/leave |
| `0x00b04264` | `g_pQuestBaseCreditsMap_Inferred` | map root (pushed to Load) |
| `0x00b04268` | `g_pQuestBaseCreditsEndSentinel_Inferred` | end sentinel (consumer; not touched here) |
| `0x00b0426c` | `g_nQuestBaseCreditsLoaded_Inferred` | ready dword — **READ** only from `Mission_ComputeObjectiveCredits`; **no write in this body** |
| `0x00a15844` | string | `"VOG_DEBUG_STOP"` |

## Callers / callees

**Callees:** `FUN_007e1d80` `0x007e1d80`, `LoadQuestBaseCreditsFromWad` `0x007cc810`, `FUN_007b7df0` `0x007b7df0`, `FUN_007a4480` `0x007a4480`.

**Callers:**

| Site | Function | Notes |
|---|---|---|
| `0x0059df41`, `0x0059df65` | `Mission_ComputeObjectiveCredits` | Lazy path after `cmp [0x00b0426c],0` |
| `0x0094afbd` | `FUN_0094a6a0` | Boot / clonebase table bring-up |

## Open questions

1. Static write site for `g_nQuestBaseCreditsLoaded_Inferred` (`0x00b0426c`) — loader residual.
2. Product names for enter/leave helpers and exact type of `DAT_00b0469c`.
3. Whether Load is idempotent if Ensure re-enters while flag still 0.
