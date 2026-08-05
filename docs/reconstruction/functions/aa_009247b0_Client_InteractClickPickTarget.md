# Function record: Client_InteractClickPickTarget

| Field | Value |
|---|---|
| **Stable ID** | `aa_009247b0` |
| **Canonical name** | `Client_InteractClickPickTarget` |
| **Address** | `0x009247b0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `interaction-activation` |
| **Completion status** | **Human-refined clean** + dual A/B + **dual residual strengthen 2026-07-29** (25f/0.015f, matcher ECX, gather modes); residual helper English / runtime |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Click/pick interact hub: resolve a world object under the cursor (primary helper, then optional ray + `Skill_GatherTargetsInArea`), store selection on the client controller, then:

1. **Gated UseObject** — if `CVOGCharacter_FindActiveObjectiveIdForPick` (`FUN_005245d0`) or `CVOGCharacter_FindActiveObjectiveIdForInteract` (`FUN_00524520`) is non-zero → `Client_SendUseObject_IfInteractable` (C2S **0x2072**). Matcher **this** = `DAT_00d1b6d8` (character); stack arg = world object (**asm Confirmed**).
2. **Unconditional UseObject** — if selected object has interact flag `+0x11c` and Euclidean distance to player body ≤ **`DAT_00aaa6fc` (25.0f)** → `Client_SendUseObject` (C2S **0x2072**). FPU: `FSQRT` + `FCOMIP` vs 25.0f @ `0x00924ed1`.
3. **Secondary type switch** on clone type `*( *(obj+0xa8)+0x38 )` — type **4** sends QuestItemPickup **0x205D** size `0x10` (not UseObject).

Server must re-validate range (~**30f** product / `NpcInteractHandler`); client click gate is **25.0f** only.

Soft gather radii use post-ray scale **`DAT_00aaacbc` = 0.015f**, then ×10 / ×5 / ×25 with caps 25 / 25 / 40.

## Signature (decompiler-derived)

```c
// Residuals resolved:
//   unaff_EBX = client/input controller* (this residual; SendUseObject thiscall ECX)
//   param_1   = forwarded to vtbl+0x380 alt path
//   param_2   = packed screen coords (lo16 x, hi16 y)
//   param_3   = 0 soft / 1 commit (caller FUN_009251d0; DAT_00d1a860 → 0)
//   param_4   = filter flag (low char 0 → drop self/vehicle picks; caller DAT_00d1b205)
undefined4 Client_InteractClickPickTarget(
    undefined4 param_1, undefined4 param_2, char param_3, undefined4 param_4);
// returns 0 = blocked early; 1 = handled (including no-op / filtered)
// RET 0x10 (stdcall 4 args) — asm epilogue at 0x00924df3
```

## Constants (Ghidra `read_memory` + asm — dual residual sealed)

| Symbol | VA | Bytes | Float | Uses in this unit |
|--------|-----|-------|------:|-------------------|
| `DAT_00aaa6fc` | `0x00aaa6fc` | `00 00 c8 41` | **25.0** | UseObject gate; soft A/A2 radius **cap**; soft B radius **scale** |
| `_DAT_00aaacbc` | `0x00aaacbc` | `8f c2 75 3c` | **0.015** | Post-`FUN_0040d020` scale → gather base |
| `DAT_00a110d8` | `0x00a110d8` | `00 00 20 41` | **10.0** | Soft A: `radius = scale * 10` |
| `DAT_00aaa688` | `0x00aaa688` | `00 00 a0 40` | **5.0** | Soft A2: `radius = scale * 5` |
| `DAT_00a1109c` | `0x00a1109c` | `00 00 20 42` | **40.0** | Soft B radius **cap** |

Named product constant: `CLIENT_USEOBJECT_RANGE` = 25.0f (`NAMING_REGISTRY`).

## Behavioral stages

| # | Stage | Effect |
|---|-------|--------|
| 0 | Early-out | Modal flag `DAT_00d1b6d8+0x4f1` or vtbl`+0x3d8` false → 0 |
| 1 | Special `DAT_00d1a8da` | Camera pick → `FUN_0093e120` select only (no UseObject) |
| 2 | Primary | `FUN_00490070` |
| 3 | Soft ray/gather | `param_3==0`: ray 400 → scale×0.015 → mode **3** (max 1, cap 25); empty → `FUN_0058cd60` (…,1,5); still null / any param_3: mode **2** (max 1, ×25 cap 40) |
| 4 | Self filter | `(char)param_4==0` drops self & vehicle body |
| 5 | Store + IfInteractable | slots `+0xd24`/`+0x758`; matchers with ECX=`DAT_00d1b6d8` |
| 6 | Alt mode | `DAT_00d1bdfa` → vtbl`+0x380` |
| 7 | **UseObject gate** | `+0x11c` && dist ≤ **25.0f** → `Client_SendUseObject` |
| 8 | Type switch | 3 / **4→0x205D** / 0xe,0x12,0x14 / 0x16 |
| 9 | Vehicle flag | `FUN_004f3640`; commit byte `+0xa32` |

### Soft gather args (`Skill_GatherTargetsInArea` ABI via `aa_0058d330`)

| Path | maxTargets | gatherMode | radius | Notes |
|------|----------:|-----------:|--------|-------|
| Soft A | 1 | **3** living interact | scale×10 cap 25 | Prefer type 0x12 if helpers allow |
| Soft A2 | — | sibling `FUN_0058cd60` mode-like **5** | scale×5 cap 25 | Product name open |
| Soft B | 1 | **2** hostile | scale×25 cap 40 | Falls through when still null |

## Dual-send (static)

CF allows **both** C2S 0x2072 producers on one click:

1. Stage 5 IfInteractable if either matcher ≠ 0  
2. Stage 7 SendUseObject if `+0x11c` and dist ≤ 25f (and intermediate gates pass)

Not exclusive. Wire capture open.

## Callers / callees

| Direction | Address | Name |
|-----------|---------|------|
| Caller | `0x009251d0` | `FUN_009251d0` (sole xref; soft @ `0x0092538f` param_3=0 / commit @ `0x009253a9` param_3=1) |
| Callee | `0x00930d70` | `Client_SendUseObject_IfInteractable` @ `0x00924db6` |
| Callee | `0x00916740` | `Client_SendUseObject` @ `0x00924ee5` |
| Callee | `0x00524520` | `CVOGCharacter_FindActiveObjectiveIdForInteract` @ `0x00924da2` |
| Callee | `0x005245d0` | `CVOGCharacter_FindActiveObjectiveIdForPick` @ `0x00924d8c` |
| Callee | `0x0058d330` | `Skill_GatherTargetsInArea` |
| Callee | `0x004bb950` | `Object_ResolveFromTFID` |
| Callee | `0x00807460` | `Client_SendSectorPacket` (type-4 `0x205D`) |

## Related artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_009247b0_Client_InteractClickPickTarget.md` |
| Annotated | `docs/reconstruction/raw/aa_009247b0_Client_InteractClickPickTarget.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_InteractClickPickTarget.cpp` |
| Dual A | `docs/reconstruction/reviews/A_aa_009247b0_Client_InteractClickPickTarget.md` |
| Dual B | `docs/reconstruction/reviews/B_aa_009247b0_Client_InteractClickPickTarget.md` |
| Residual | `docs/reconstruction/reviews/a_009247b0.md` |
| Chain | `docs/reconstruction/reviews/CHAIN_2026-07-29_interaction_useobject.md` |
| System map | `docs/reconstruction/systems/interaction-activation.md` |
| Scratch | `tmp/a_009247b0.md` |

## Confidence by dimension

| Dimension | Level | Rationale |
|---|---|---|
| Role: click pick → UseObject | **High** | Plate + dual paths explicit |
| Distance gate **25.0f** | **Confirmed** | `read_memory` + FCOMIP |
| Scale **0.015f** | **Confirmed** | `read_memory` + FMUL |
| Interact flag `+0x11c` | **High** | Explicit before SendUseObject |
| Matcher ECX character | **Confirmed** | asm both CALL sites |
| IfInteractable objective gate | **High** | Calls sealed `005245d0`/`00524520` |
| Type-4 → opcode `0x205D` | **High** | Imm bits + product enum |
| Gather mode numbers 3 / 2 | **High** | literals + `aa_0058d330` table |
| Gather / helper **English** | **Tentative** | INFERRED / FUN_* residual |
| Soft vs commit `param_3` | **Probable** | Caller 0/1 only |
| Dual-send wire | **Open** | CF High static |
| Full pick taxonomy sealed | **Partial** | Large; secondary FUN_* open |
| Overall (static UseObject contract) | **High** | |
| Runtime / bit-exact | **Open** | |
