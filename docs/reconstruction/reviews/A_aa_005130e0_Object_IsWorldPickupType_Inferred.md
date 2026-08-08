# Review A (reconstruction fidelity): `aa_005130e0` Object_IsWorldPickupType_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005130e0` |
| **VA** | `0x005130e0`–`0x0051314d` (code); switch tables `@0x00513150` / `@0x00513160` |
| **Canonical name** | `Object_IsWorldPickupType_Inferred` |
| **Ghidra name** | `FUN_005130e0` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY WQ9R-C) |
| **Counterpart** | `reviews/B_aa_005130e0_Object_IsWorldPickupType_Inferred.md` |
| **System** | skills-abilities / client-interact / object-type filter |
| **Evidence pass** | Live `decompile_function` + `read_memory` + `analyze_function_complete` + callers + assembly_context |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Boolean **soft type / world-pickup eligibility** for a `CVOGClonedObjectBase`:

1. Optional “loose object” gate: if `requireLoose!=0`, require `this+0xac==0`.
2. Switch on clone type at `*(this+0xa8)+0x38`.
3. Accept fixed loot/equipment-ish types; Object type-1 via blob `+0x3f2` bit7; Vehicle only when RTTI→`CVOGVehicle` and `+0x2ac!=0`.

Primary skill use: `Skill_GatherTargetPairFilter` when `filterA==-1`. Interact path builds “Press … to pick up” when this returns true.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005130e0_FUN_005130e0.md` (+ WQ9R-C append) |
| Annotated | `docs/reconstruction/raw/aa_005130e0_FUN_005130e0.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/Object_IsWorldPickupType_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005130e0.cpp` |
| Live | decompile ≡ raw; entry `80 7C 24 04 00`; tail `C2 04 00` |
| Call-site | `PUSH 1`/`PUSH 0` + `MOV ECX,ESI` before CALL |

---

## 3. Signature

```c
// thiscall; RET 4; AL bool
uint8_t __thiscall Object_IsWorldPickupType_Inferred(void *this, char requireLoose);
```

| Item | Evidence | Conf |
|---|---|---|
| thiscall ECX=this | callers `MOV ECX,ESI` / LEA MI | **High** |
| `RET 4` | tail `C2 04 00` | **High** |
| AL bool | `TEST AL,AL` after call | **High** |
| requireLoose semantics | `CMP [esp+4],0` then optional `CMP [ecx+0xac],0` | **High** CF / **Probable** English |

---

## 4. Control flow (sealed)

| Stage | Match | Conf |
|---|---|---|
| Dual gate requireLoose / +0xac | **Yes** | **High** |
| Switch on clone `+0x38` | **Yes** (jump table bytes) | **High** |
| Type1 bit7 of `+0x3f2` | **Yes** `SHR 7; AND 1` | **High** |
| Fixed accept set {4,6,8,10,0xc,0x10,0x1a,0x1c,0x32,0x34,0x42} | **Yes** | **High** |
| Vehicle RTTI + `+0x2ac` | **Yes** | **High** CF |
| Reject Creature/Character (0x12/0x14) | **Yes** (default 0) | **High** |
| Live ≡ 2026-07-23 raw | **Yes** | **High** |

Type IDs cross-checked with `CloneBaseObjectType` enum in AutoCore.

---

## 5. Call surface

| Caller | Site | requireLoose |
|---|---|---:|
| `FUN_0058a810` (Gather pair filter) | `0x0058a8fb` | **1** (when filterA==-1) |
| `Skill_FilterTargetForResolveList_Inferred` | `0x00550038` | **0** |
| `FUN_008a81a0` (interact prompt) | `0x008a82b0` | **1** → “to pick up” |
| `FUN_00585e00` (graphics post-load) | `0x00585e22` | **1** |
| + list/register / radius-map paths | various | 1 typical |

Callee: `__RTDynamicCast` only.

---

## 6. Confidence

| Claim | Level |
|---|---|
| ABI / CF / type table | **High** |
| Role as soft filter + pickup gate | **High** |
| Product C++ name | **Inferred** (no string/PDB) |
| `this+0xac` / vehicle `+0x2ac` English | **Probable** |
| Runtime / bit-exact | **Open** |

**Verdict:** **accept-with-gaps** — CF/ABI/type table sealed; `_Inferred` name; residual English on two flags.

---

## Checklist

| Check | Result |
|---|---|
| Live decompile ≡ raw | **Pass** |
| RET 4 + thiscall | **Pass** |
| Type table vs enum | **Pass** |
| No disassemble_bytes | **Pass** |
