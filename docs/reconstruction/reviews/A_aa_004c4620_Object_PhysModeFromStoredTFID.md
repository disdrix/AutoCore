# Review A (reconstruction fidelity): `aa_004c4620` Object_PhysModeFromStoredTFID

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c4620` |
| **VA** | `0x004c4620`–`0x004c4658` |
| **Canonical name** | `Object_PhysModeFromStoredTFID` |
| **Ghidra name** | `FUN_004c4620` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W27-G) |
| **Counterpart** | `reviews/B_aa_004c4620_Object_PhysModeFromStoredTFID.md` |
| **System** | object / TFID / phys mode |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` + `analyze_function_complete`; DATA xrefs; sibling mode writer |
| **Verdict** | **accept** |

---

## 1. Purpose

Map stored **TFID_16** validity to phys mode constant: **0xB** if invalid/unassigned, **10** if assigned. Pure leaf used as the mode oracle for the TFID family (writer sibling `FUN_004c4880`).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004c4620_FUN_004c4620.md` (+ 2026-07-29 W27-G append) |
| Annotated | `docs/reconstruction/raw/aa_004c4620_FUN_004c4620.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_PhysModeFromStoredTFID.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004c4620.cpp` |
| Function | `docs/reconstruction/functions/aa_004c4620_FUN_004c4620.md` |
| Named record | `docs/reconstruction/functions/aa_004c4620_Object_PhysModeFromStoredTFID.md` |
| Live | decompile ≡ raw; `read_memory` 57 B; dual `MOV EAX,imm; ADD ESP,0x10; RET` |
| Sibling | `FUN_004c4880` writes same modes to phys+0x28; `FUN_004c4440` inverse gate |

---

## 3. Signature (sealed)

```c
// thiscall; 0 stack formals; EAX = mode; RET 0
uint32_t Object_PhysModeFromStoredTFID(int this);
```

| Formal | Source | Conf |
|---|---|---|
| this | ECX (`ADD ECX,0x108` in prologue) | **High** |
| cleanup | `RET` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
tfid = this+0x108
if (tfid.lo & tfid.hi) == ~0 && (char)tfid.w2 == 0:
  return 0xB
else:
  return 10
```

| Stage | Match | Conf |
|---|---|---|
| thiscall + TFID base | **Yes** | **High** |
| Invalid → 0xB | **Yes** | **High** |
| Else → 10 | **Yes** | **High** |
| Leaf (no CALL) | **Yes** | **High** |
| Predicate ≡ 004c4880 | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

Hex body (57 B):
```
83ec105681c1080100008bf18b068b4e048b56088b760c23c183f8ff897424105e750484d27409b80a00000083c410c3b80b00000083c410c3
```

Return sites: `B8 0A 00 00 00 83 C4 10 C3` (10) and `B8 0B 00 00 00 83 C4 10 C3` (0xB).

---

## 6. Gaps

- Product enum names for modes **10** / **0xB**.
- Owning class of DATA vtable slot `0x009cbe8c`.
- Runtime / bit-exact — open.

---

## 7. Verdict

CF, ABI, and mode constants are fully sealed against live decompile and full-body bytes; predicate family shared with dual-sealed writer. → **accept**.
