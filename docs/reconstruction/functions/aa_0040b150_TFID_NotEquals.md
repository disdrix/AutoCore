# Function record: TFID_NotEquals

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040b150` |
| **Canonical name** | `TFID_NotEquals` |
| **Address** | `0x0040b150` |
| **Body range** | `0x0040b150` – `0x0040b188` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `tfid-identity` |
| **Completion status** | **Sealed (dual A/B 2026-07-29)** — CF, polarity, compare width |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

ObjectId-key **inequality** of two TFID-like buffers: return **1** if not equal, **0** if equal. Compares only `i32@+0`, `i32@+4`, `i8@+8` — **not** full 16-byte TFID.

## Signature (sealed)

```c
int __cdecl TFID_NotEquals(void *pA, void *pB);
// effective: returns 0/1 in AL
```

## Twin

| Name | VA | Relation |
|---|---|---|
| `TFID_EqualsObjectId` | `0x00404aa0` | same compare width; inverted polarity |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0040b150_TFID_NotEquals.md`
- Annotated: `docs/reconstruction/raw/aa_0040b150_TFID_NotEquals.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/TFID_NotEquals.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_0040b150_TFID_NotEquals.md`
- Review B: `docs/reconstruction/reviews/B_aa_0040b150_TFID_NotEquals.md`

## Callers / callees

- **Callees:** none (leaf)
- **Callers (24):** see Review A / Ghidra `get_function_callers` — includes `Skill_LocalCastValidate`, `Client_Skill_ResolveCastTarget`, `Client_RecvSkillStatusEffect`, `Client_RecvGroupReactionCall`, `NPC_TryCastSkillFromSet`, `CVOGCreature_PostCreateFromPacket`, `VehicleNet_ReconcilePrediction`, …

## Sealed facts

| Fact | Level |
|---|---|
| Equal → 0, unequal → 1 | **Sealed** |
| Compare width 4+4+1 @ +0/+4/+8 | **Sealed** |
| Bytes +9…+15 not compared | **Sealed** |
| `__cdecl` two pointer args | **Sealed** |
| Leaf (no callees) | **Sealed** |

## Gaps

| Gap | Status |
|---|---|
| Product field names for +0/+4/+8 | Open (layout sibling) |
| Caller invalid-sentinel catalog | Open (per-caller) |
| Runtime / differential harness | Open / deferred |
| Formal `TFID_16*` type in Ghidra | Tentative (consumers) |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler + body bytes | **Sealed / High** |
| Parameter semantic names (`pA`/`pB` TFID buffers) | **High** (callers) |
| Full TFID_16 type product layout | Tentative (outside unit) |
