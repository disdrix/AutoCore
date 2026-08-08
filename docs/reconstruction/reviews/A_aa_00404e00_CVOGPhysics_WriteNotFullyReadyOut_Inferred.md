# Review A (reconstruction fidelity): `aa_00404e00` CVOGPhysics_WriteNotFullyReadyOut_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00404e00` |
| **VA** | `0x00404e00`–`0x00404e22` inclusive (**35 B** / `0x23`) |
| **Canonical name** | `CVOGPhysics_WriteNotFullyReadyOut_Inferred` |
| **Ghidra name** | `FUN_00404e00` |
| **Review date** | `2026-08-05` (MEGA-049 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_00404e00_CVOGPhysics_WriteNotFullyReadyOut_Inferred.md` |
| **System** | physics (CVOGPhysics fully-ready out-byte) |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `disassemble_function` + `analyze_function_complete` + `read_memory` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

CVOGPhysics **leaf** that materializes the shared **fully-ready** dual-field gate into a caller out-byte:

```text
if byte(phys+0x40) != 0 AND dword(phys+0x08) != 0:
    *out = 0   // fully ready → soft path blocked
else:
    *out = 1   // not fully ready → soft path allowed
return out     // EAX
```

Used by skill bound-status motion heading fixup (`FUN_005d0d60`) and AI DoLogic state branch (`FUN_005d7f70`). Same fields as dualed `CVOGPhysics_SetRotation` fully-ready skip.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00404e00_FUN_00404e00.md` (+ MEGA-049 append) |
| Annotated | `docs/reconstruction/raw/aa_00404e00_FUN_00404e00.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGPhysics_WriteNotFullyReadyOut_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00404e00.cpp` |
| Function record | `docs/reconstruction/functions/aa_00404e00_FUN_00404e00.md` |
| Named record | `docs/reconstruction/functions/aa_00404e00_CVOGPhysics_WriteNotFullyReadyOut_Inferred.md` |
| Live | decompile ≡ CF; body hex; RET 4 ×2; 2 CALL xrefs; call-site ECX/PUSH |
| Family | dualed `CVOGPhysics_SetRotation` `0x00404dc0` fully-ready gate |

---

## 3. Signature (sealed)

```c
// ECX = CVOGPhysics*; stack out*; RET 4; EAX = out
uint8_t *__thiscall CVOGPhysics_WriteNotFullyReadyOut_Inferred(void *phys, uint8_t *out);
```

| Slot | Source | Conf |
|---|---|---|
| phys | **ECX** | **High** |
| out | stack `[ESP+4]` after entry | **High** |
| cleanup | **`RET 4`** ×2 exits | **High** |
| EAX | = out pointer | **High** |
| fields | `+0x40` byte, `+0x08` dword | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

| Stage | Match | Conf |
|---|---|---|
| Load / test `byte[ECX+0x40]` | **Yes** | **High** |
| If zero → write 1 path | **Yes** | **High** |
| Else CMP `dword[ECX+8],0`; if zero → write 1 | **Yes** | **High** |
| Both nonzero → `*out=0`, RET 4 | **Yes** | **High** |
| Else path → `*out=1`, RET 4 | **Yes** | **High** |
| Leaf (no callees) | **Yes** | **High** |
| Product English field names | open | **Inferred** |

### Instruction seal (`read_memory` + `disassemble_function`)

```text
8A 41 40       mov al,[ecx+0x40]
84 C0          test al,al
74 11          jz write1
83 79 08 00    cmp dword [ecx+8],0
74 0B          jz write1
8B 44 24 04    mov eax,[esp+4]
32 C9          xor cl,cl
88 08          mov [eax],cl
C2 04 00       ret 4
8B 44 24 04    mov eax,[esp+4]     ; write1
B1 01          mov cl,1
88 08          mov [eax],cl
C2 04 00       ret 4
```

Body hex: `8A414084C0741183790800740B8B44240432C98808C204008B442404B1018808C20400` (35 B).

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | leaf |
| External callers | `FUN_005d0d60` (1), `FUN_005d7f70` (1); **xref_count=2** |
| Site roles | soft heading when bound-status motion; AI state branch when not fully ready |
| Call-site this | **ECX = `*(entity+0x08)`** (phys) both sites |
| Callees | none |
| Family twin gate | SetRotation / setPosition fully-ready skip |

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| Out-byte writer CF + RET 4 | **Yes** |
| Fields match dualed CVOGPhysics fully-ready | **Yes** |
| Call-site phys = entity+8 | **Yes** |
| Distinct from ready-probe `005070b0` (+0x44) | **Yes** |
| Product/PDB English | **No** |
| Skill-packet decoder | **No** — nested under RecvSkillStatusEffect only via caller |

**Decision:** promote **`CVOGPhysics_WriteNotFullyReadyOut_Inferred`**. Retire Named_CalleeOf scaffold. Reject skill-status-effect decoder / ready-probe merge / polarity flip.

---

## 7. Gaps / open

1. Product English for `phys+0x40` / `phys+0x08` beyond behavioral fully-ready.
2. Runtime / bit-exact / differential.
3. Parent ledger lockstep (OWN-ONLY excluded).

**Verdict:** **accept-with-gaps**
