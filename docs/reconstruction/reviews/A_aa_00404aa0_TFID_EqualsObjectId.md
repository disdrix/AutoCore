# Review A (reconstruction fidelity): `aa_00404aa0` TFID_EqualsObjectId

| Field | Value |
|---|---|
| **Stable ID** | `aa_00404aa0` |
| **VA** | `0x00404aa0`–`0x00404ac6` |
| **Canonical name** | `TFID_EqualsObjectId` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (leaf equality helper) |
| **Counterpart** | `reviews/B_aa_00404aa0_TFID_EqualsObjectId.md` |
| **System** | identity / TFID (cross-cutting) |
| **Verdict** | **accept** (body sealed; field product names inferred) |

---

## 1. Purpose

Leaf **TFID / ObjectId equality** predicate. Two pointers into 9+ byte id blocks are compared field-wise; returns **1** if equal, **0** otherwise. No side effects, no callees, no globals.

Widely used as the client-side “is this the same object id?” / “is invalid TFID?” gate (vs `g_abTfidInvalid_A15870` and peer TFIDs).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00404aa0_TFID_EqualsObjectId.md` |
| Annotated | `docs/reconstruction/raw/aa_00404aa0_TFID_EqualsObjectId.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/TFID_EqualsObjectId.cpp` |
| Function record | `docs/reconstruction/functions/aa_00404aa0_TFID_EqualsObjectId.md` |
| Sibling (inverse) | `TFID_NotEquals` `0x0040b150` |
| Invalid sentinel | `g_abTfidInvalid_A15870` @ `0x00a15870` (`read_memory` 16 B) |
| Live Ghidra | `decompile_function` `0x00404aa0`; `analyze_function_complete`; `get_function_callers`; `get_function_by_address`; `read_memory` body + invalid sentinel |
| Layout context | `TFID_16` in `Client_InteractClickPickTarget.cpp` (`dwCoidLo`, `dwCoidHi`, `bGlobal`, pad) |

---

## 3. Signature

```c
// __cdecl — plain RET (no RET n); caller cleans stack
int __cdecl TFID_EqualsObjectId(void *pA, void *pB);
// Stack: [esp+4]=pA, [esp+8]=pB
// Return: EAX = 1 equal, 0 unequal
```

| Item | Evidence |
|---|---|
| Convention | `RET` @ `0x00404ac3` / `0x00404ac6` — **not** `RET 8` → **`__cdecl`** |
| Args | `Stack[0x4]:4` pA, `Stack[0x8]:4` pB (`analyze_function_complete`) |
| Leaf | `callees: []`; body loads only through pA/pB |
| Body range | Entry `00404aa0`, last insn `00404ac6` (`get_function_by_address`) |

---

## 4. Control flow (sealed)

```
load pA, pB
if *(int32*)pA != *(int32*)pB:        return 0
if *(int32*)(pA+4) != *(int32*)(pB+4): return 0
if *(int8*)(pA+8)  != *(int8*)(pB+8):  return 0
return 1
```

Short-circuit on first mismatch. **No NULL checks.**

---

## 5. Machine bytes (`read_memory` @ `0x00404aa0`, 40 B)

```
8B 44 24 04    MOV  EAX, [ESP+4]     ; pA
8B 10          MOV  EDX, [EAX]       ; lo
8B 4C 24 08    MOV  ECX, [ESP+8]     ; pB
3B 11          CMP  EDX, [ECX]
75 16          JNZ  fail
8B 50 04       MOV  EDX, [EAX+4]     ; hi
3B 51 04       CMP  EDX, [ECX+4]
75 0E          JNZ  fail
8A 40 08       MOV  AL,  [EAX+8]     ; byte @ +8
3A 41 08       CMP  AL,  [ECX+8]
75 06          JNZ  fail
B8 01 00 00 00 MOV  EAX, 1
C3             RET
33 C0          XOR  EAX, EAX         ; fail
C3             RET
CC             INT3                  ; pad (not executed)
```

Hex: `8b4424048b108b4c24083b1175168b50043b5104750e8a40083a41087506b801000000c333c0c3cc`

Decompile ≡ bytes. **No conflict.**

---

## 6. Compared fields vs TFID_16 footprint

| Offset | Width | Compare? | Inferred field (repo layout) |
|---|---|---|---|
| `+0` | `int32` | **Yes** | `dwCoidLo` |
| `+4` | `int32` | **Yes** | `dwCoidHi` |
| `+8` | `int8` | **Yes** | `bGlobal` |
| `+9..+15` | 7 B | **No** | pad / unused for equality |

Equality is **not** a 16-byte `memcmp`. Only **9 addressable bytes** participate (8 + 1).

Invalid sentinel `g_abTfidInvalid_A15870` (`read_memory`):

```
FF FF FF FF | FF FF FF FF | 00 00 00 00 | 00 00 00 00
```

→ `dwCoidLo=dwCoidHi=0xFFFFFFFF`, `bGlobal=0`, rest zero. Equals-invalid path matches this unit’s three fields.

---

## 7. Sibling inverse

`TFID_NotEquals` (`0x0040b150`) uses the **same three compares**, returns **0** if all match else **1**. Boolean complement of this unit.

---

## 8. Call surface (owned unit only — list, no parent ownership)

Ghidra reports **38** xrefs; **22** named callers (non-exhaustive use domains):

| Caller (Ghidra name) | VA |
|---|---|
| `Client_RequestCastSkill` | `0x00941590` |
| `Client_Skill_ResolveCastTarget` | `0x0093b3a0` |
| `Client_StanceOrGadgetActivatePath` | `0x0093a3d0` |
| `Skill_ApplyStatusEffectLocal` | `0x0051aa00` |
| `Skill_FilterTargetForResolveList_Inferred` | `0x0054ff00` |
| `NPC_TryCastSkillFromSet` | `0x005d1280` |
| `VehicleNet_ReconcilePrediction` | `0x005f9f10` |
| `FUN_005d9290` (drive collision path) | `0x005d9290` |
| + 14 other `FUN_*` / client helpers | (see complete analysis) |

Typical call patterns in reconstructed parents: compare resolved TFID vs invalid sentinel, or vs another object’s TFID block (`obj+0x160` class).

---

## 9. Confidence

| Claim | Level |
|---|---|
| CF + return 0/1 | **High** (decompile + bytes) |
| `__cdecl`, 2 pointer args | **High** |
| Compares +0/+4/+8 only | **High** |
| Leaf / no side effects | **High** |
| Field names `dwCoidLo`/`dwCoidHi`/`bGlobal` | **Probable** (repo TFID_16; not named in this body) |
| Full 16-byte identity | **Falsified** by body |

---

## 10. Gaps (fidelity residual)

1. Product symbol / PDB for `TFID_EqualsObjectId` (Ghidra custom name present).
2. Whether any caller relies on pad bytes `+9..+15` for identity elsewhere (outside this unit).
3. Runtime / bit-exact / image diff not run.

---

## Verdict

**accept** — sealed leaf equality of three ObjectId/TFID fields. Residual is naming/layout product labels only, not control flow.
