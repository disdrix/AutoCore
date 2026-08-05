# Function record: CVOGCharacter_SearchAutoMissions

| Field | Value |
|---|---|
| **Stable ID** | `aa_00532b60` |
| **Canonical name** | `CVOGCharacter_SearchAutoMissions` |
| **Address** | `0x00532b60` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression |
| **Calling convention** | MSVC character `this` in `ECX` (body uses `EBP`); void, no stack formals |
| **Completion status** | **Human-refined clean** — residual-2 (2026-07-29): multi-grant + table getter + local-gate path sealed |
| **Bit-for-bit / runtime / diff** | Open |
| **Dual A/B** | **accept-with-gaps** (strengthened residual pass 2) |

## Purpose

Iterate global mission-definition hash; for auto-flagged missions not already active/completed, run `CheckMissionRequirements` and `GiveMission` on pass (return 0). **May grant multiple missions in one call** (loop continues after GiveMission).

## Signature

```c
void /* thiscall */ CVOGCharacter_SearchAutoMissions(CVOGCharacter* thisCharacter);
```

### Callee framings sealed at this call site

```c
// ECX = missionDef*, stack0 = character*  (no third arg)
int  CheckMissionRequirements(MissionDef* def, CVOGCharacter* character);

// ECX = character*, stack0 = missionId
// Return ignored by Search
void GiveMission(CVOGCharacter* character, unsigned missionId);

// ECX = DAT_00b041fc owner; returns wrapper* at owner+0xf18 (lazy 0x10 ctor)
// Search uses hash = *wrapper
void* FUN_0053fff0(/* this owner */);
```

## Behavioral summary

- Profile enter `"CVOGCharacter::SearchAutoMissions"` (string `@0x009cff4c`).
- Table via `FUN_0053fff0` (`ECX = DAT_00b041fc` → `*(owner+0xf18)` wrapper); null → return.
- Hash = `*wrapper`; lock `hash+0x1d`; walk nodes via `+0x14` / value `+0x8`.
- Candidate if **`u16(def+0xF8) != 0`** (decompiler dword index `0x3e`).
- Skip active (`character+0x540`) and completed (`character+0x538`) via manual chain walk (payload `@+0x8` required to skip).
- Hash probe: mask `+0x8`, buckets `+0x10`, node key `+0x10` / payload `+0x8` / next `+0xc`.
- Requirements == 0 → `GiveMission(*def)` → **JMP continue** (multi-grant).
- Unlock + profile leave.

## Confidence by dimension

| Dimension | Level | Rationale |
|---|---|---|
| Function boundary | High | Named string in body |
| Hash lock/traverse pattern | High | Shared with other hash walkers + assembly |
| Active/completed `+0x540`/`+0x538` | High | Live loads |
| Auto flag `u16 @ +0xF8` | High | Live `CMP word [ESI+0xF8]` |
| Requirements / GiveMission ABI | High | Live call sites; ESI residual falsified |
| Multi-grant continue | High (static) | `JMP LAB_00532c00` after Give |
| Table getter `owner+0xf18` | High | Live `FUN_0053fff0` body + deref |
| Local-only callers (`…+0xa8`→`+0x7e`) | High | Four xrefs; MI path sealed |
| English name of `+0xF8` | Probable | Auto/silent-assign vs toast |
| Overall | **High (static)** | |

## Callers

| Caller | Site | Gate | Notes |
|---|---|---|---|
| `CVOGCharacter_LevelUp` | `0x0053303a` | `*(*( *(this+4)+4 ) + this + 0xa8 ) + 0x7e` | |
| `CVOGCharacter_LevelDown` | `0x00533213` | same | |
| `CVOGReaction_CompleteObjective` | `0x00534851` | same | then dirty `char+0x634 \|= 0x10` |
| `FUN_00533220` | `0x00533586` | same | level-set / stat-recalc then Search |

## Sealed facts (dual residual)

1. **No third Requirements arg** — `unaff_ESI` is missionDef in ESI.
2. **Auto ↔ toast field** — same `u16 +0xF8`: auto when !=0; GiveMission toast when ==0.
3. **Multi-grant** — scan continues after each successful GiveMission.
4. **Table path** — `DAT_00b041fc` → `FUN_0053fff0` → wrapper `@owner+0xf18` → hash `*wrapper`.
5. **Exactly four static callers**, all local-gated; no bare `character+0x7e` load in callers.
6. **GiveMission return ignored**.

## Open questions

- Retail name for def `+0xF8`.
- Product names for table accessor / profile helpers / `FUN_00533220` / owner type.
- Product type of object behind relative `+0xa8`.
- Runtime auto-grant capture; bit-exact / differential.
- Whether any non-xref schedule exists (login/zone).

## Related artifacts

| Kind | Path |
|---|---|
| Raw | `raw/aa_00532b60_CVOGCharacter_SearchAutoMissions.md` |
| Annotated | `raw/aa_00532b60_CVOGCharacter_SearchAutoMissions.annotated.md` |
| Clean | `reconstructed-exact/CVOGCharacter_SearchAutoMissions.cpp` |
| Dual A | `reviews/A_aa_00532b60_CVOGCharacter_SearchAutoMissions.md` |
| Dual B | `reviews/B_aa_00532b60_CVOGCharacter_SearchAutoMissions.md` |
| Scratch | `tmp/a_00532b60.md` |
