# Review A (reconstruction fidelity): `aa_00943340` Client_CycleHostileTarget_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00943340` |
| **VA** | `0x00943340`–`0x009434fc` (**0x1BD** B) |
| **Canonical name** | `Client_CycleHostileTarget_Inferred` |
| **Ghidra name** | `FUN_00943340` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY WQ9R-C) |
| **Counterpart** | `reviews/B_aa_00943340_Client_CycleHostileTarget_Inferred.md` |
| **System** | skills-abilities / client-input / target selection |
| **Evidence pass** | Live `decompile_function` + `read_memory` + `analyze_function_complete` + callers + assembly_context |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Cycle hostile target** within a float range on the client shell:

1. Early-out if local player `+0x4f1`.
2. Gather hostiles via `Skill_GatherTargetsInArea` **mode 2**, max **50**, score **−1.0f**.
3. Reorder list with `FUN_00930360` (view-angle sort).
4. Find current selection `client+0x3048` by TFID; step **next** (`stepDir==0`) or **prev** (`stepDir!=0`) with wrap.
5. Resolve TFID → `FUN_0093e120` apply selection (updates `+0x3048`, highlight).

Sole caller: `Client_Input_PollBoundActions` with range **110.0f** (`0x42dc0000`), when `DAT_00d1d888 != 0`; else sibling first-pick `FUN_00943520`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00943340_FUN_00943340.md` (+ WQ9R-C append) |
| Annotated | `docs/reconstruction/raw/aa_00943340_FUN_00943340.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/Client_CycleHostileTarget_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00943340.cpp` |
| Live | decompile ≡ raw; tail `C2 08 00` |
| Call sites | `0x00927c5e` PUSH 0 / 110.f; `0x00927cc7` PUSH 1 / 110.f; EAX=client |

---

## 3. Signature

```c
// EAX = ClientShell* (custom register convention)
// stdcall stack: float range, char stepDir; RET 8; void
void Client_CycleHostileTarget_Inferred(float range, char stepDir);
```

| Item | Evidence | Conf |
|---|---|---|
| EAX = client | entry `8B F0`; call sites load client into EAX | **High** |
| `RET 8` | tail `C2 08 00` | **High** |
| range float | gather arg; call immediate `0x42dc0000` = 110.0f | **High** |
| stepDir 0=+1 / nonzero=−1 | `(stepDir==0)*2 + (-1) + idx` | **High** |
| gather mode 2 hostile | immediate `PUSH 2`; sealed in Skill_Gather dual | **High** |

---

## 4. Control flow (sealed)

| Stage | Match | Conf |
|---|---|---|
| +0x4f1 early out | **Yes** | **High** |
| origin via vtbl+0x1a0 | **Yes** | **High** |
| Gather mode2 max50 score−1 | **Yes** (push chain + `ADD ESP,0x3c`) | **High** |
| FUN_00930360 sort | **Yes** | **High** (nested English Probable) |
| TFID match +0x160/164/168 | **Yes** | **High** |
| step wrap | **Yes** (neg via +count; high via −count) | **High** |
| invalid TFID skip | `coidLo & coidHi == −1` and global==0 | **High** |
| FUN_0093e120 apply | **Yes** | **High** (selection apply dualed elsewhere) |
| Live ≡ raw | **Yes** | **High** |

---

## 5. Call surface

| Caller | Site | Args |
|---|---|---|
| `Client_Input_PollBoundActions` | `0x00927c5e` | `(110.0f, 0)` next |
| `Client_Input_PollBoundActions` | `0x00927cc7` | `(110.0f, 1)` prev |

Condition: `DAT_00d1d888 != 0`; else `FUN_00943520(110.0f)` only.

Callees: `Skill_GatherTargetsInArea`, `FUN_00930360`, `Object_ResolveFromTFID`, `FUN_0093e120`.

---

## 6. Confidence

| Claim | Level |
|---|---|
| ABI / CF / gather mode / step math | **High** |
| Role: hostile target cycle | **High** |
| Product keybinding English | **Inferred** |
| `FUN_00930360` sort metric English | **Probable** |
| player `+0x4f1` English | **Probable** |
| Runtime / bit-exact | **Open** |

**Verdict:** **accept-with-gaps** — hostile cycle CF/ABI sealed; nested helper English + product key names open.

---

## Checklist

| Check | Result |
|---|---|
| Live decompile ≡ raw | **Pass** |
| RET 8 + EAX client | **Pass** |
| Mode 2 + 110.f call sites | **Pass** |
| No disassemble_bytes | **Pass** |
