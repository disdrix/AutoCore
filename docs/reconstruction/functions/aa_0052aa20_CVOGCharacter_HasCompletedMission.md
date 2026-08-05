# Function record: CVOGCharacter_HasCompletedMission

| Field | Value |
|---|---|
| **Stable ID** | `aa_0052aa20` |
| **Canonical name** | `CVOGCharacter_HasCompletedMission` |
| **Address** | `0x0052aa20` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression |
| **Calling convention** | MSVC `__thiscall` |
| **Completion status** | **Human-refined clean** — CF sealed from raw; runtime/diff open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Return true if `missionId` is treated as completed: global completed hash (`char+0x538`) and/or instance-completed hash (`char+0x53c`), with continent-id match when the character is continent-attached.

## Signature (decompiler-derived)

```c
bool __thiscall CVOGCharacter_HasCompletedMission(void* this /*CVOGCharacter*/, unsigned missionId);
```

## Behavioral summary

1. If continent object at `*(*( *(this+4)+4 ) + this + 0xa8)` is null → lookup `+0x538` only (never `+0x53c`).
2. Else Path A: `(table null OR def miss OR +0xfc mismatch OR !mode) AND +0x538 hit` → true.
3. Else Path B: `mode AND +0x53c hit` → true.
4. **Critical:** attached + mode + def OK + `+0xfc` match → Path A dead; only Path B can true (538-only is false).

Mode gate body (`aa_004ce340`): `+0x100==0 && +0xac!=2` — not weapon math.

## Confidence by dimension

| Dimension | Level | Rationale |
|---|---|---|
| Function boundary | High | Ghidra symbol + plate; small body |
| Signature | High | thiscall + missionId clear from callers |
| Control flow / truth table | High | Raw + 2026-07-29 re-decompile; Path A/B sealed static |
| Hash offsets `+0x538` / `+0x53c` | High | Body + debug string + GiveMission |
| Continent match `+0xfc` | Probable | Def vs attach-object field; product name open |
| Mode gate fields | High body / open writers | `aa_004ce340` dual; producers of `+0x100`/`+0xac` open |
| `FUN_0053fff0` | Probable | Lazy mission-def holder `+0xf18`; shared with GiveMission |
| Overall | **High (static)** | Dual A/B tightened 2026-07-29; runtime still open |

## Open questions

- Product type of attach object at `+0xa8` and field `+0xfc`.
- Writers of mode fields that select instance-hash policy.
- Runtime observation of both hash paths under null vs attached continent.

## Related artifacts

| Kind | Path |
|---|---|
| Raw | `raw/aa_0052aa20_CVOGCharacter_HasCompletedMission.md` |
| Annotated | `raw/aa_0052aa20_CVOGCharacter_HasCompletedMission.annotated.md` |
| Clean | `reconstructed-exact/CVOGCharacter_HasCompletedMission.cpp` |
