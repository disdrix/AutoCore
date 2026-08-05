# Review A (reconstruction fidelity): `aa_0059d880` CVOGObjective_GetCompleteCount

| Field | Value |
|---|---|
| **Stable ID** | `aa_0059d880` |
| **VA** | `0x0059d880` |
| **Canonical name** | `CVOGObjective_GetCompleteCount` (proposed) |
| **Prior names** | `FUN_0059d880`; scaffold alias `Named_CalleeOf_CVOGReaction_CompleteObjective_0059d880` |
| **Review date** | `2026-07-29` (dual residual seal) |
| **Reviewer role** | Independent reconstruction review (fidelity / clean ≡ raw / dual residual) |
| **Counterpart** | `reviews/B_aa_0059d880_CVOGObjective_GetCompleteCount.md` |
| **System** | `missions-progression` |
| **Verdict** | **accept** (runtime/diff open; CF + field name sealed) |

---

## 1. Purpose

Trivial **objective field getter**: return `*(uint32_t*)(this + 0x164)`.

Product English for the field is **CompleteCount** — sealed by objective XML dump serializer `FUN_005468c0` @ `0x005468c0`, which calls this unit then `fprintf(..., "<CompleteCount>%i</CompleteCount>", ret)`.

Used by both completion gates:

* `CVOGReaction_CompleteObjective` (`0x00533f90`) — min required pass count
* `CVOGCharacter_EvaluatePendingObjectives` (`0x00534920`) — same field as collect threshold

Sibling **setter** (out of unit body, ownership note only): `FUN_0059d890` @ `0x0059d890` writes the same offset.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0059d880_FUN_0059d880.md` |
| Annotated | `docs/reconstruction/raw/aa_0059d880_FUN_0059d880.annotated.md` |
| Clean (scaffold) | `docs/reconstruction/reconstructed-exact/FUN_0059d880.cpp` |
| Clean (named) | `docs/reconstruction/reconstructed-exact/CVOGObjective_GetCompleteCount.cpp` |
| Function record | `docs/reconstruction/functions/aa_0059d880_CVOGObjective_GetCompleteCount.md` |
| Parent duals | `A/B_aa_00533f90_*`, `A/B_aa_00534920_*` |
| Live decompile | Ghidra `decompile_function` / `analyze_function_complete` `0x0059d880` (2026-07-29) |
| Live asm | Ghidra `disassemble_function` `0x0059d880` |
| Live memory | Ghidra `read_memory` body @ `0x0059d880` (8 B); format string @ `0x009d0638` |
| Call sites | Ghidra `get_assembly_context` on 5 xref sources |
| Xrefs | **5** UNCONDITIONAL_CALL across **3** callers |
| Setter sibling | `decompile` + `read_memory` `0x0059d890` |
| XML dump | `decompile` `FUN_005468c0` @ `0x005468c0` |

---

## 3. Body (authoritative asm / memory)

```text
0059d880  MOV  EAX, dword ptr [ECX + 0x164]
0059d886  RET
```

Body hex (live `read_memory` 2026-07-29):

```text
8b 81 64 01 00 00 c3 cc
```

| Bytes | Decode |
|---|---|
| `8b 81 64 01 00 00` | `mov eax, [ecx+0x164]` |
| `c3` | `ret` |
| `cc` | int3 pad (not in function body end `0059d886`) |

Ghidra function span: **`0059d880`–`0059d886`**. Classification: **stub**.

Decompile (CF-identical):

```c
undefined4 __fastcall FUN_0059d880(int param_1)
{
  return *(undefined4 *)(param_1 + 0x164);
}
```

No callees. No stack formals. No branches.

---

## 4. ABI seal (High)

| Claim | Evidence | Conf |
|---|---|---|
| **ECX = this** (objective) | Body reads `[ECX+0x164]`; every call site `MOV ECX, <obj>` | **High** |
| No stack args | Bare `RET` (`c3`); no `RET n` | **High** |
| Return in **EAX** (full dword) | `MOV EAX,[ECX+0x164]` | **High** |
| Convention | `__thiscall` / `__fastcall` equivalent for single-reg this | **High** |
| Return type | `uint32_t` / `int` presentation both OK | **High** (width sealed; signedness at call sites differs) |

Canonical signature:

```c
std::uint32_t __thiscall CVOGObjective_GetCompleteCount(void* objective /* ECX */);
// equivalently: __fastcall with ECX = this
```

---

## 5. Product field name seal — CompleteCount

| Evidence | Detail | Conf |
|---|---|---|
| Format string @ `0x009d0638` | `\t\t<CompleteCount>%i</CompleteCount>\r\n` | **High** |
| Dump path | `FUN_005468c0`: `uVar2 = FUN_0059d880(); fprintf(f, fmt, uVar2);` | **High** |
| Call site asm | `00546950 MOV ECX,ESI` → `CALL 0x0059d880` → `PUSH EAX` → `PUSH 0x9d0638` → `fprintf` | **High** |
| Objective dump context | Same function emits `<Objective name=… ID=… sequence=…>` then text fields then CompleteCount then requirement vtbl `+0x54` serialize | **High** |

**Conclusion:** field English = **CompleteCount**. Role in gates = minimum required success / action count against requirement walk counters. Not a progress counter on the character — it is a **template/objective definition** threshold stored at `obj+0x164`.

---

## 6. Caller inventory (complete static set)

| Caller | Call sites | ECX binding | Use |
|---|---|---|---|
| `CVOGReaction_CompleteObjective` `0x00533f90` | `0x00534122`, `0x0053412d` | `MOV ECX,EDI` (EDI = objective) | Dual CALL min-pass gate |
| `CVOGCharacter_EvaluatePendingObjectives` `0x00534920` | `0x00534ae2`, `0x00534aed` | `MOV ECX,[ESI]` (def from pending slot) | Dual CALL collect threshold |
| `FUN_005468c0` objective XML dump | `0x00546952` | `MOV ECX,ESI` (serializer this = objective) | fprintf CompleteCount |

Xref count **5** = callers above. No additional static CALL found (`get_function_xrefs` / `get_function_callers`).

### 6.1 CompleteObjective dual CALL (real, not decompiler noise)

```text
00534120  MOV  ECX, EDI
00534122  CALL 0x0059d880
00534127  TEST EAX, EAX
00534129  JLE  0x00534138          ; min <= 0 → fall to allOk/force check
0053412b  MOV  ECX, EDI
0053412d  CALL 0x0059d880
00534132  CMP  [ESP+0x14], EAX     ; nPassed vs CompleteCount
00534136  JGE  0x00534158          ; enough passes → ok
00534138  … allOk / forceComplete fail path …
```

Gate (forceComplete bypasses fail):

```
min = GetCompleteCount(obj)
if (min <= 0) {                // signed JLE
  if (!allReqsOk && !force) fail;
} else {
  if (nPassed < min && !allReqsOk && !force) fail;
}
```

### 6.2 EvaluatePending dual CALL

```text
00534ae0  MOV  ECX, [ESI]
00534ae2  CALL 0x0059d880
00534ae7  TEST EAX, EAX
00534ae9  JZ   0x00534af8          ; count == 0 → allTrue arm only
00534aeb  MOV  ECX, [ESI]
00534aed  CALL 0x0059d880
00534af2  CMP  [ESP+0x10], EAX     ; successCount vs CompleteCount
00534af6  JGE  0x00534b00          ; enough → continue collect
00534af8  TEST BL, BL              ; allTrue
…
```

Collect form sealed by parent dual:

```
(count != 0 && count <= successCount) || allTrue
// plus parent gate def+0x138 == 0 before retire
```

**Note (call-site residual, not this unit):** CompleteObjective uses **signed `JLE`** (≤0); EvaluatePending uses **`JZ`** (==0 only). Both read the same dword; negative CompleteCount behavior differs by caller.

---

## 7. Sibling setter (adjacent)

| VA | Body | Role |
|---|---|---|
| `0x0059d890` `FUN_0059d890` | `MOV EAX,[ESP+4]; MOV [ECX+0x164],EAX; RET 4` (hex start `8b 44 24 04 89 81 64 01 …`) | Write CompleteCount |

Sole static caller of setter (Ghidra): `FUN_00547050` @ `0x00547050` (large objective load/parse; decompile noisy — **not owned here**).

---

## 8. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body = load dword `[this+0x164]` into EAX; RET | **High** | asm + memory |
| Field offset `+0x164` | **High** | |
| Product tag **CompleteCount** | **High** | string + dump path |
| ECX = objective (def/instance layout with +0x164) | **High** | 5/5 call sites |
| No stack formals; bare RET | **High** | |
| Dual CALL real at CompleteObjective + EvaluatePending | **High** | asm |
| Complete static caller set = 3 functions / 5 sites | **High** | xrefs |
| Name `CVOGObjective_GetCompleteCount` | **Probable** | product field sealed; retail method spelling open |
| Signedness of stored value | **Tentative** | callers disagree on ≤0 vs ==0 |
| Writer path / XML load full CF | **Open** | setter owned by other unit |
| Runtime / bit-exact | **Open** | static only |

---

## 9. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Single load `[this+0x164]` | **Yes** |
| Return that dword | **Yes** |
| No extra gates / calls | **Yes** |
| Named clean documents CompleteCount | **Yes** (semantic; body identical) |

---

## 10. Gaps / open (residual of *this* unit)

1. Retail / PDB method spelling (`GetCompleteCount` vs alternate).
2. Whether live instances ever store negative CompleteCount (affects JLE path only).
3. Full XML load path through `FUN_00547050` → setter (out of ownership).
4. Runtime / image-diff verification.

**Verdict:** Unit is a pure getter. Field name, offset, ABI, and full caller inventory are **High / sealed**. Remaining residual is cosmetic naming + load-path + runtime. **accept.**
