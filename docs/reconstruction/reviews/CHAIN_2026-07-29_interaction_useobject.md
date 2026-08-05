# Chain seal: Interaction â†’ UseObject C2S (2026-07-29)

| Field | Value |
|---|---|
| System | interaction-activation (`SYS-INTERACT`) |
| Status | **Sealed (static) for primary send paths** â€” runtime / wire dump open |
| Primary residual closed | IfInteractable objective field â€œunsetâ€ â†’ **stack overlay** with `FUN_00524520` return |
| Dual reviews | A/B refresh for `aa_00916740`, `aa_00930d70`, **`aa_009247b0`** (pick hub 2026-07-29) |
| Map | `docs/reconstruction/systems/interaction-activation.md` |

---

## End-to-end (client)

```
â”Œâ”€ Producers â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”
â”‚ A. Client_InteractClickPickTarget (0x009247b0)                    â”‚
â”‚    ray / gather / resolve â†’ select slots [0x349],[0x1d6]          â”‚
â”‚    if FUN_005245d0|FUN_00524520: IfInteractable()                 â”‚
â”‚    if obj+0x11c && dist â‰¤ DAT_00aaa6fc (25.0f): SendUseObject()   â”‚
â”‚                                                                   â”‚
â”‚ B. Client_Input_PollBoundActions (0x00925d60) interact edge      â”‚
â”‚    if interact flag +0x11c path: SendUseObject()                  â”‚
â”‚    else if FUN_00524520(target): IfInteractable()                 â”‚
â”‚                                                                   â”‚
â”‚ C. Client_RecvCompleteDynamicObjective (0x0080ff00) optional      â”‚
â”‚    may call SendUseObject after S2C 0x2070 force-complete         â”‚
â””â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”¬â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”˜
                                â”‚
        â”Œâ”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”´â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”
        â-¼                                               â-¼
â”Œâ”€ Client_SendUseObject â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”  â”Œâ”€ Client_SendUseObject_IfInteractable â”€â”
â”‚ 0x00916740                              â”‚  â”‚ 0x00930d70                             â”‚
â”‚ client+0xd28 = target                   â”‚  â”‚ gate: *(client+0xe04)+0xf6 == 0        â”‚
â”‚ TFID â† target+0x160..                   â”‚  â”‚ id = FUN_00524520(target)              â”‚
â”‚ id = FindObjectiveMatchingTarget(       â”‚  â”‚ allow if id!=0 OR type==4              â”‚
â”‚        *( *(target+0xa8)+0x34 ) )       â”‚  â”‚ TFID â† target+0x160..                  â”‚
â”‚        â†’ def+0x10 or âˆ’1                 â”‚  â”‚ packet+0x18 = id (overlay; 0 if type4) â”‚
â”‚ opcode 0x2072 size 0x20                 â”‚  â”‚ opcode 0x2072 size 0x20                â”‚
â”‚ send g_pSectorNetConnection vtbl+0x18   â”‚  â”‚ send *(client+0xc78) vtbl+0x18         â”‚
â”‚ void                                    â”‚  â”‚ return 1 / 0                           â”‚
â””â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”¬â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”˜  â””â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”¬â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”˜
                    â”‚                                           â”‚
                    â””â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”¬â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”˜
                                        â”‚ C2S 0x2072
â”Œâ”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â-¼â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”
â”‚ Server (out of client RE scope) â€” ObjectUseManager.Handle                     â”‚
â”‚   UseItem / mission dialog / deliver / store / facility / reactions           â”‚
â”‚   range authority ~30f (product); often S2C 0x206D dialog                     â”‚
â””â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”˜
```

Chrome only (no UseObject send):

```
Client_UpdateNpcInteractIcons (0x0091b8d0)
  â†’ eval offerable/active interact state â†’ entry+0x10
  â†’ SpecialFX attach/clear
```

---

## Key evidence

| Claim | Evidence | Confidence |
|---|---|---|
| Opcode `0x2072` size `0x20` both paths | Live decompile both units | **High** |
| TFID from `obj+0x160` | Both bodies | **High** |
| SendUseObject objective âˆ’1 fallback | Explicit `0xffffffff` branch | **High** |
| SendUseObject stash `+0xd28` | First store | **High** |
| IfInteractable multi-gate | Block + match/type | **High** |
| IfInteractable `@+0x18` = `FUN_00524520` | Same `local_8`; no rewrite | **High** static |
| Type-4 no-match â†’ objective **0** | Assignment path | **High** static |
| `FUN_00524520` returns objective id | Callee return `def+0x10` | **High** |
| Match helpers differ (+0x38 vs +0x40) | FindObjective vs `FUN_0059d9c0` | **High** |
| Client range 25.0f | `read_memory` `0x00aaa6fc` = `00 00 c8 41` | **High** |
| Pick hub → both senders | Live decompile stage 5+7; sole caller `FUN_009251d0` | **High** |
| Pick type-4 secondary = `0x205D` | Imm bits `0x205d` ≠ UseObject | **High** |
| Callers of both senders | Ghidra `get_function_callers` | **High** |
| Runtime wire dump | Not run | **Open** |

---

## Dual-review verdicts

| Unit | Stable ID | A | B |
|---|---|---|---|
| `Client_SendUseObject` | `aa_00916740` | accept-with-gaps | accept-with-gaps |
| `Client_SendUseObject_IfInteractable` | `aa_00930d70` | accept-with-gaps (overlay closed) | accept-with-gaps + needs-more-evidence (wire) |
| `Client_FindObjectiveMatchingTarget` | `aa_00525bd0` | prior accept-with-gaps | prior |
| `Client_InteractClickPickTarget` | `aa_009247b0` | **accept-with-gaps** (2026-07-29 human refine; UseObject gate High) | **accept-with-gaps** + needs-more-evidence (pick taxonomy / dual-send) |
| `Client_UpdateNpcInteractIcons` | `aa_0091b8d0` | prior (chrome) | prior |

---

## Contradictions / doc debt

| # | Conflict | Resolution for RE |
|---|---|---|
| 1 | Prior dual: IfInteractable â€œobjective field unset / garbageâ€ | **Closed static:** `local_8` overlay; value is id or **0** |
| 2 | Prior â€œFUN_00524520 = interactable boolâ€ | **Falsified:** returns **objective id** from active hash |
| 3 | Alias `Named_VOG_DEBUG_STOP` for `00524520` | Misleading assert string; prefer `CVOGCharacter_FindActiveObjectiveIdForInteract` |
| 4 | Client 25f vs server ~30f | Different authorities; do not merge constants |
| 5 | SendUseObject âˆ’1 vs IfInteractable 0 | **Do not unify** sentinels in ports |
| 6 | Two net connection expressions | Global vs `client+0xc78` â€” residual identity |
| 7 | MatchTarget `+0x38` vs interact match `+0x40` | Different evaluator slots; different producers |

---

## Residual (still open)

1. Wire capture of type-4 IfInteractable objective dword (confirm 0).
2. Character ECX provenance into `FUN_00524520` / FindObjectiveMatchingTarget at each call site.
3. Full dual promote of `FUN_00524520` / `FUN_0059d9c0`.
4. `g_pSectorNetConnection_INFERRED` â‰¡? `client+0xc78`.
5. Runtime NPC deliver / use-item / facility e2e.
6. Large pick-hub residual: gather-mask product names; dual IfInteractable+SendUseObject same click (CF allows; wire open).
7. Server product treatment of objective 0 vs -1 vs real id.
8. Soft vs commit (`param_3` 0/1) product UX naming.

---

## Artifact index

| Path |
|------|
| `docs/reconstruction/systems/interaction-activation.md` |
| `docs/reconstruction/functions/aa_00916740_Client_SendUseObject.md` |
| `docs/reconstruction/functions/aa_00930d70_Client_SendUseObject_IfInteractable.md` |
| `docs/reconstruction/raw/aa_00916740_Client_SendUseObject.md` (+ 2026-07-29 version) |
| `docs/reconstruction/raw/aa_00930d70_Client_SendUseObject_IfInteractable.md` (+ 2026-07-29 version) |
| `docs/reconstruction/raw/aa_00916740_Client_SendUseObject.annotated.md` |
| `docs/reconstruction/raw/aa_00930d70_Client_SendUseObject_IfInteractable.annotated.md` |
| `docs/reconstruction/reconstructed-exact/Client_SendUseObject.cpp` |
| `docs/reconstruction/reconstructed-exact/Client_SendUseObject_IfInteractable.cpp` |
| `docs/reconstruction/reviews/A|B_aa_00916740_Client_SendUseObject.md` |
| `docs/reconstruction/reviews/A|B_aa_00930d70_Client_SendUseObject_IfInteractable.md` |
| `docs/reconstruction/functions/aa_009247b0_Client_InteractClickPickTarget.md` |
| `docs/reconstruction/raw/aa_009247b0_Client_InteractClickPickTarget.md` (+ annotated) |
| `docs/reconstruction/reconstructed-exact/Client_InteractClickPickTarget.cpp` |
| `docs/reconstruction/reviews/A|B_aa_009247b0_Client_InteractClickPickTarget.md` |
| `tmp/a_009247b0.md` (scratch) |

## FindActiveObjectiveIdForInteract (2026-07-29)

- aa_00524520 CVOGCharacter_FindActiveObjectiveIdForInteract - walks char+0x548; returns objective id
- aa_0059d9c0 MatchTargetEvaluators - vtbl+0x40 over +0x158..+0x15c
- Dual A/B present for both
