# Function record: Client_FindObjectiveMatchingTarget

| Field | Value |
|---|---|
| **Stable ID** | `aa_00525bd0` |
| **Canonical name** | `Client_FindObjectiveMatchingTarget` |
| **Address** | `0x00525bd0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression (UseObject consumer in interaction-activation) |
| **Completion status** | **Human-refined clean** + dual A/B residual refresh `2026-07-29` |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Walk character **active objectives** hash (`+0x548`) and return the first objective definition whose evaluators accept the target **key** via MatchTarget (`vtable+0x38`). Used by `Client_SendUseObject` (C2S `0x2072`) to fill `IDObjective` (def`+0x10` or −1).

## Signature

```c
int __thiscall Client_FindObjectiveMatchingTarget(int thisCharacter, uint32_t targetKey);
// returns objective def* or 0
```

## Behavioral notes

- Early-out if pending container count at `*(char+0x55c)+0xc < 1`.
- Hash lock byte at hash`+0x1d`.
- First match wins; unlock on match or exhaust.
- **Not** the interact id-finder: contrast `0x00524520` (returns id; eval `+0x40`; no pending gate).

## Confidence by dimension

| Dimension | Level | Rationale |
|---|---|---|
| Active hash walk + lock | High | CF sealed; live ≡ raw 2026-07-29 |
| Pending count gate | High | First branch; gate-only on `+0x55c` |
| MatchTarget vtable +0x38 (key, char) | High | Explicit call |
| Returns def* not id | High | node+8 payload; caller `+0x10` |
| Distinct from `00524520` / `+0x40` | High | Dual residual contrast |
| UseItem MatchTarget body as key match | Tentative | `0060d7f0`→`0060d460` object ABI |
| Overall | **High (static walker)** | implementer catalog / runtime open |

## Related artifacts

| Kind | Path |
|---|---|
| Raw | `raw/aa_00525bd0_Client_FindObjectiveMatchingTarget.md` |
| Annotated | `raw/aa_00525bd0_Client_FindObjectiveMatchingTarget.annotated.md` |
| Clean | `reconstructed-exact/Client_FindObjectiveMatchingTarget.cpp` |
| Dual A | `reviews/A_aa_00525bd0_Client_FindObjectiveMatchingTarget.md` |
| Dual B | `reviews/B_aa_00525bd0_Client_FindObjectiveMatchingTarget.md` |
| Dual residual scratch | `reviews/a_00525bd0.md` |
| Caller duals | `reviews/A|B_aa_00916740_Client_SendUseObject.md` |
| Contrast | `aa_00524520` FindActiveObjectiveIdForInteract; `aa_0059d9c0` MatchTargetEvaluators |
| Chain | `reviews/CHAIN_2026-07-29_interaction_useobject.md` |
