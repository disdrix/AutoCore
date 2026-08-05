# Review A (reconstruction fidelity): `aa_004c9430` Object_EnsurePrimaryHBAI_FromAIProfile

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c9430` |
| **VA** | `0x004c9430`–`0x004c96a9` |
| **Canonical name** | `Object_EnsurePrimaryHBAI_FromAIProfile` |
| **Ghidra name** | `FUN_004c9430` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W27-I) |
| **Counterpart** | `reviews/B_aa_004c9430_Object_EnsurePrimaryHBAI_FromAIProfile.md` |
| **System** | npc-ai / host HB list / AI profile map |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` + `analyze_function_complete`; callees; sealed map duals (`00540890`, `004cbd50`); ctor vtbl installs |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Ensure a host object has a primary HBAI/HB installed at `+0x1fc` from the AI profile map, with type-specific construction, list enqueue, start/stop policy, optional secondary HB, and conditional skill-effect refresh.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004c9430_FUN_004c9430.md` (+ 2026-07-29 W27-I append) |
| Annotated | `docs/reconstruction/raw/aa_004c9430_FUN_004c9430.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_EnsurePrimaryHBAI_FromAIProfile.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004c9430.cpp` |
| Function | `docs/reconstruction/functions/aa_004c9430_FUN_004c9430.md` |
| Named record | `docs/reconstruction/functions/aa_004c9430_Object_EnsurePrimaryHBAI_FromAIProfile.md` |
| Live | decompile ≡ raw CF; `read_memory` body 634 B; epilogue `C2 08 00`; jump table `@0x004c96ac` |
| Sealed callees | `Host_AIProfileMap_GetOrReset`, `Map_LowerBoundFindByIntKey_Isnil65`, `CVOGHBList_Enqueue`, `CVOGHBBase_Start`/`Stop` |

---

## 3. Signature (sealed)

```c
// thiscall; 2 stack formals; RET 8; SEH
void *Object_EnsurePrimaryHBAI_FromAIProfile(void *self, char deferStopIfHostFlag, char profileKeyOrMinus1);
```

| Formal | Source | Conf |
|---|---|---|
| this | ECX (`MOV ESI,ECX`) | **High** |
| deferStopIfHostFlag | Stack after pushes | **High** |
| profileKeyOrMinus1 | Stack; `-1` → def+0x4dc | **High** |
| cleanup | `RET 8` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
if this+0x1fc != 0: early epilogue
key = (param_3==-1) ? def+0x4dc : param_3
map get → lower_bound(key) → map get
if it==end: return
this+0x200 = 1<<(node+0x10 & 0x1f)
switch node+0x10:
  2 → new 0xC0 + FUN_005d8330
  3 → new 0xB0 + FUN_005d7f50
  4 → new 0xC0 + FUN_005d7de0
  5 → new 0xC0 + FUN_005d7bb0
  default → new 0xB0 + FUN_005d6da0
if hb && !cStopped:
  this+0x1fc = hb
  CVOGHBList_Enqueue(host+0xe4ec, hb)
  if param_2==0 && host+0x7e: Stop else Start
elif hb && cStopped: vtbl dtor(1)
if def+0x4e8==1: new 0x28 + FUN_005d6b80; Enqueue; Start
ret = this+mi
if clone+0x38 != 0x14: Object_RefreshActiveSkillEffects(view,0)
return ret
```

| Stage | Match | Conf |
|---|---|---|
| Early +0x1fc gate | **Yes** | **High** |
| Profile key / map lower_bound | **Yes** | **High** |
| Type switch table 2..5 | **Yes** (bytes jump table) | **High** |
| Enqueue + Start/Stop | **Yes** | **High** |
| Secondary HB on +0x4e8 | **Yes** | **High** |
| thiscall RET 8 | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

| Addr | Bytes | Decode |
|---|---|---|
| `0x004c9430` | `6A FF 68 71 1C 9A 00 … 56 8B F1` | SEH prolog; ESI=this |
| host load | `8B 0D FC 41 B0 00` | `DAT_00b041fc` before map get |
| type remap | `0F B7 40 10 83 C0 FE 83 F8 03` | word-2, ja default |
| jmp table | `FF 24 85 AC 96 4C 00` | `jmp [4*eax+0x004c96ac]` |
| tail | `83 C4 10 C2 08 00` | `add esp,10; ret 8` |

Jump table dwords: `0x004c94e1`, `0x004c950f`, `0x004c9536`, `0x004c955d`.

---

## 6. Gaps

- Product English for profile type words 2/3/4/5/default.
- Exact RTTI/class names of each ctor target (type5 has nearby vehicle-disabled map string).
- Early-out return value under SEH (decompiler ExceptionList residual).
- Code call-sites (DATA-only xrefs today).
- Runtime / bit-exact — open.

---

## 7. Verdict

CF, ABI (`RET 8`), factory sizes/ctors, enqueue/start policy, secondary HB gate, and map linkage are sealed against live decompile + full-body bytes + sealed callee duals. Naming is evidence-backed structural inference (no plate string). Product type English and SEH early-return residual remain → **accept-with-gaps**.
