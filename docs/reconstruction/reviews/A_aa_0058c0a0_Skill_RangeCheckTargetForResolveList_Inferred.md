# Review A (reconstruction fidelity): `aa_0058c0a0` Skill_RangeCheckTargetForResolveList_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0058c0a0` |
| **VA** | `0x0058c0a0` |
| **Canonical name** | `Skill_RangeCheckTargetForResolveList_Inferred` |
| **Review date** | `2026-07-29` (dual residual strengthen: return0→outFlags bit2) |
| **Reviewer role** | Reconstruction fidelity |
| **Counterpart** | `reviews/B_aa_0058c0a0_Skill_RangeCheckTargetForResolveList_Inferred.md` |
| **System** | `skills-abilities` |
| **Verdict** | **accept** — role + **return0→outFlags bit2** chain sealed (geometry of `FUN_004e9aa0` open) |

---

## 1. Purpose

Second-stage **range** check inside `Skill_ResolveTargetList`, after `Skill_FilterTargetForResolveList_Inferred`. Returns `float10`: **zero** = out-of-range / hard fail so the caller ORs `*outFlags |= 2`; **non-zero** = primary target range-legal (measured dist in band, or synthetic `g_flOne` auto-pass).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0058c0a0_FUN_0058c0a0.md` |
| Annotated | `docs/reconstruction/raw/aa_0058c0a0_Skill_RangeCheckTargetForResolveList_Inferred.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Skill_RangeCheckTargetForResolveList_Inferred.cpp` |
| Caller | `Skill_ResolveTargetList` @ `0x00550300` (sole; call site `0x00550416`) |
| Upstream filter | `Skill_FilterTargetForResolveList_Inferred` @ `0x0054ff00` |
| Downstream UX | CastSkillOnTarget maps bit2 → eSkillResponses `0x0D` |
| Scratch | `reviews/a_0058c0a0.md` |

**Live re-decompile + callers + xrefs + call-site asm + `g_flZero`/`g_flOne` `read_memory` (2026-07-29 residual).**

---

## 3. Dual residual seal: return0 → outFlags bit2

### Producer (this unit)

| Return path | Label / condition | Value |
|---|---|---|
| Auto-pass | `LAB_0058c127` — self, parent, same vehicle, no usable source phys | `g_flOne` |
| Band pass | `flRangeMin(+0x2c) <= dist <= flRangeMax(+0x28)` | measured `dist` |
| Fail | band miss **or** parent/hardpoint gate fail (`LAB_0058c187`) | `g_flZero` |

This body has **no** `outFlags` formal and never ORs any flag bit.

### Consumer (sole caller — asm Confirmed)

Call site `0x00550416` inside `Skill_ResolveTargetList`:

```text
00550416  CALL  Skill_RangeCheckTargetForResolveList_Inferred
0055041b  FLD   dword [g_flZero]          ; 0x00a0f518
00550421  ADD   ESP, 0x18
00550424  FUCOMIP ST0, ST1                ; return == 0.0?
00550426  FSTP  ST0
00550428  LAHF
00550429  TEST  AH, 0x44                  ; MSVC float-equal idiom
0055042c  JNP   0x005504ce                ; equal → fail
          ; fallthrough: write primary TFID (success)
005504ce  MOV   EAX, [EBP+0x28]           ; outFlags*
005504d1  OR    dword [EAX], 0x2          ; *outFlags |= 2
005504d7  …                               ; LAB_005504d7 no-primary fallthrough
```

| Claim | Evidence | Conf |
|---|---|---|
| Sole caller | `get_function_callers` → only `Skill_ResolveTargetList` | **Confirmed** |
| Single call xref | `get_function_xrefs` → `00550416` UNCONDITIONAL_CALL only | **Confirmed** |
| Compare is vs `g_flZero` | `FLD [0x00a0f518]`; `read_memory` → `00 00 00 00` | **Confirmed** |
| Equal branch ORs bit **2** only | `OR dword [EAX], 0x2` @ `005504d1` | **Confirmed** |
| Success path does **not** OR bit2 | fallthrough `00550432+` copies TFID | **Confirmed** |
| Decompile matches asm | `if ((float10)g_flZero == fVar7) { *param_10 \|= 2; goto LAB_005504d7; }` | **Confirmed** |
| `g_flOne` auto-pass constant | `0x00a0f2a0` → `00 00 80 3f` = 1.0f | **Confirmed** |

### Ownership map (resolve-list chain)

| Bit | Writer | Role of this unit |
|----:|--------|-------------------|
| 1 | ResolveTargetList body | **Not** this — no-target path at `LAB_005504d7` |
| **2** | ResolveTargetList after **this** returns 0 | **Zero-signal exclusive producer** on primary path |
| 4 / 8 / 0x10 | Filter `0x0054ff00` | **Not** this |

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Sole caller ResolveTargetList | **Confirmed** | callers + single xref |
| Return `g_flZero` → caller `*outFlags \|= 2` | **Confirmed** | decompile **and** asm `OR …, 0x2` |
| Band `skill+0x2c <= dist <= skill+0x28` | **Confirmed** | call site args + body compare |
| Auto-pass returns `g_flOne` without band | **Confirmed** | `LAB_0058c127` |
| Does not write outFlags itself | **Confirmed** | no formal; no OR in body |
| Product original name | Inferred | no string/RTTI → `_Inferred` |
| Distance geometry (`FUN_004e9aa0`) | Partial | sealed as measure helper, not product ABI |

---

## 5. Control flow vs ResolveTargetList

```
ResolveObjectTarget → Filter (0054ff00) → null?
  yes → maybe OR bit1
  no  → vehicle remap types 0x12/0x14
      → RangeCheck (this @ 0058c0a0)
           zero → OR bit2 @ 005504d1 → no-primary fallthrough
           nonzero → copy TFID → Gather...
```

Filter owns bits **4 / 8 / 0x10**. This unit is the **only** source of the zero that drives bit **2** on the primary path.

---

## 6. Gaps (acceptable — do not block bit2 seal)

1. Product English for skill `+0x28/+0x2c/+0x34/+0x5e7`.
2. Full semantics of `FUN_004e9aa0` (LOS / path vs Euclidean).
3. Vtbl slots `+0x1c8/+0x214/+0x1d4/+0x1d8/+0x210` product names.
4. Whether measured distance is consumed anywhere beyond zero/non-zero (ResolveTargetList only tests `== g_flZero`).

**Verdict:** **accept** for role + **return0→outFlags bit2** producer seal under `_Inferred` name.

---

## Checklist

| Check | Result |
|---|---|
| Sole caller | **Pass** |
| Bit2 driven by return==0 (decomp) | **Pass** |
| Bit2 driven by return==0 (asm `OR 2`) | **Pass** |
| `g_flZero`/`g_flOne` bytes | **Pass** |
| Clean matches band + auto-pass | **Pass** |
| Ghidra rename + plate | **Pass** |
| Verdict | **accept** |
