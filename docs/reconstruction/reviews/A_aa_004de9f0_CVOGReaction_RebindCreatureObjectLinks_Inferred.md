# Review A (reconstruction fidelity): `aa_004de9f0` CVOGReaction_RebindCreatureObjectLinks_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004de9f0` |
| **VA** | `0x004de9f0`–`0x004dea68` |
| **Canonical name** | `FUN_004de9f0` (proposed: `CVOGReaction_RebindCreatureObjectLinks_Inferred`) |
| **Prior names** | `Named_CalleeOf_CVOGReaction_CompleteObjective_004de9f0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004de9f0_CVOGReaction_RebindCreatureObjectLinks_Inferred.md` |
| **System** | `missions-progression` / client world object links |
| **Evidence pass** | Live Ghidra `batch_decompile` + `disassemble_function` + `analyze_function_complete` (2026-07-29); callers via `get_function_callers` |
| **Verdict** | **accept-with-gaps** (CF/ABI sealed; product English + host class name open) |

---

## 1. Purpose

Mission-complete / end-quest **creature vector walk** on large host `this` (same object family that owns `+0xe720` creature list used by `CVOGSectorMap_StepCreatures`):

1. Iterate dword pointers in half-open range `[*(this+0xe720), *(this+0xe724))`.
2. Per entry `ESI = *it`, recover MI-adjusted object base `adj = *(*(ESI+4)+4) + ESI`.
3. Gate: `(adj+0x3c) & (adj+0x40) != 0xFFFFFFFF` (valid dual-id / TFID halves) **and** `*(*(adj+0xac)+0x38) != 0x36` (skip clone type **0x36** repair-station path used elsewhere).
4. If `adj+0x134 != 0` (≡ object-this `+0x130` interact FX slot after `+4` MI adjust): `CVOGObject_SetInteractSpecialFX(adj+4, NULL)` — clear interact special FX.
5. Always (when gates pass): `FUN_004dbef0(this, adj+4, 0, *(adj+0x3c), *(adj+0x40), -1)` — re-insert/replace map object-hash entry (see dual `aa_004dbef0`).

**Does not** complete missions, grant medals, step physics, or free creatures. Side effect only: clear interact FX + rebind object-hash link descriptor.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004de9f0_FUN_004de9f0.md` |
| Annotated | `docs/reconstruction/raw/aa_004de9f0_FUN_004de9f0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_004de9f0.cpp` |
| Function record | `docs/reconstruction/functions/aa_004de9f0_FUN_004de9f0.md` |
| Live decompile | Ghidra `batch_decompile` `0x004de9f0` |
| Live listing | `disassemble_function` `0x004de9f0` (seals ECX this + `RET`) |
| Callers | `CVOGReaction_CompleteObjective` `0x0053469e`; `FUN_005307e0` (`Mission_Client_HandleEndQuest`) `0x00530d90` |
| Callees | `CVOGObject_SetInteractSpecialFX` `0x005179a0`; `FUN_004dbef0` `0x004dbef0` |
| Sibling list use | `A_aa_004d4da0_CVOGSectorMap_StepCreatures` (`+0xe720/+0xe724`) |

**Not performed:** `disassemble_bytes`, Launcher, live complete-objective capture, product PDB name.

---

## 3. Signature (assembly-sealed)

```c
// __thiscall  ECX = large reaction / sector-map host
// bare RET (0 stack args cleaned)
void CVOGReaction_RebindCreatureObjectLinks_Inferred(void *host);
```

Listing prolog/epilog:

```text
004de9f0  PUSH EBX / PUSH EDI
004de9f2  MOV EDI, ECX              ; host
004de9f4  MOV EBX, [EDI+0xe720]     ; begin
004de9fa  CMP EBX, [EDI+0xe724]     ; end
...
004dea53  MOV ECX, EDI
004dea55  CALL FUN_004dbef0         ; this = host; 5 stack args; callee RET 0x14
004dea5a  ADD EBX, 4
004dea68  RET
```

Decompiler labels `__fastcall` — **equivalent here** (single ECX arg); prefer **thiscall** naming for host methods.

---

## 4. Control flow

| Stage | Match raw/live |
|---|---|
| Empty range early out | **Yes** |
| Per-entry MI adjust via `*(entry+4)` chain | **Yes** |
| TFID AND gate vs `0xFFFFFFFF` | **Yes** |
| Type `0x36` skip | **Yes** |
| Optional clear interact FX | **Yes** |
| Unconditional `FUN_004dbef0` when gates pass | **Yes** |
| Advance `it += 4` (pointer vector) | **Yes** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `thiscall` host in ECX, bare RET | **High** | listing |
| Creature list `+0xe720/+0xe724` | **High** | same as StepCreatures |
| Type `0x36` skip | **High** | explicit CMP |
| Clear interact FX via `SetInteractSpecialFX(null)` | **High** | dualed callee; +0x134 on adj ≡ +0x130 object-this |
| Rebind via `FUN_004dbef0` with host this | **High** | `MOV ECX,EDI` before CALL |
| Link ids = adj `+0x3c/+0x40` (object dword `[0xe]/[0xf]`) | **High** | matches SpawnObject call shape |
| Host is product `CVOGSectorMap` vs `CVOGReaction` root | **Probable** | large shared offsets; PDB open |
| English “rebind on mission complete” | **Probable** | only CompleteObjective / HandleEndQuest callers |

---

## 6. Surviving contract

```
OnCompleteObjective / OnEndQuest (host):
  for objEntry in host.creaturePtrRange(+0xe720,+0xe724):
    adj = mi_adjust(objEntry)
    if (adj.tfidA & adj.tfidB) == -1: continue
    if defType(adj) == 0x36: continue
    clearInteractFxIfAny(adj)
    RegisterObjectHashEntry(host, objThis(adj), 0, adj.tfidA, adj.tfidB, -1)
```

---

## 7. Gaps / open

1. Product/PDB name for this unit and host class.
2. Why rebind is required after objective complete (server authority vs client link repair).
3. Full meaning of clone type `0x36` beyond repair-station peer paths.
4. Whether non-creature objects ever appear in the `+0xe720` vector.

**Verdict:** **accept-with-gaps**
