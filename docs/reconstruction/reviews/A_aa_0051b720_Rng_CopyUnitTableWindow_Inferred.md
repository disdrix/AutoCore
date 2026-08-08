# Review A (reconstruction fidelity): `aa_0051b720` Rng_CopyUnitTableWindow_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051b720` |
| **VA** | `0x0051b720` |
| **Body end** | exclusive `0x0051b768` (72 B); `C2 08 00` |
| **Canonical name** | `Rng_CopyUnitTableWindow_Inferred` |
| **Ghidra name** | `FUN_0051b720` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (Path A) |
| **Counterpart** | `reviews/B_aa_0051b720_Rng_CopyUnitTableWindow_Inferred.md` |
| **System** | `skills-abilities` |
| **Agent** | WQ9R-A OWN-ONLY dual |
| **Verdict** | **accept-with-gaps** — CF/ABI/layout/callers sealed; product English open |

---

## 1. Purpose

**Caller-buffer copy of a ushort window from the global RNG unit table**, then `cursor++`, returning the **pre-increment cursor** as a dice-seed index.

```c
// __thiscall RET 8
uint32_t Rng_CopyUnitTableWindow_Inferred(RngHost* this, int nWords, void* dst);
```

Not a float unit draw (`FUN_007a4170`). Not a heap clone (`Rng_CloneSeededTable_Inferred`). Not MT twist/seed.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0051b720_FUN_0051b720.md` (+ re-verify append) |
| Annotated | `docs/reconstruction/raw/aa_0051b720_FUN_0051b720.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Rng_CopyUnitTableWindow_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_0051b720.cpp` |
| Live Ghidra | `decompile_function 0x0051b720`; `analyze_function_complete`; `read_memory`; callers |
| Sibling dual | `A\|B_aa_0058ab60_Rng_CloneSeededTable_Inferred` |
| RNG getter | `CVOGReaction_RandomUnitScalar` @ `0x007a4330` → `&DAT_00d20c1c` |
| Caller | `Skill_ApplyStatusEffectLocal` dice path (`lDiceSeed` @ packet `+0x3C`) |

**Live re-decompile + call-site bytes performed (2026-08-04).** No `disassemble_bytes`; constants from `read_memory` on body.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body `0x0051b720`–`0x0051b768` excl. | **Confirmed** | `get_function_by_address` + pad `CC` |
| `__thiscall` + `RET 8` | **Confirmed** | `C2 08 00` |
| Wrap `cursor+nWords > 0xFFFFF` → 0 | **Confirmed** | `cmp ecx,0x100000` / `jl` / store 0 |
| Source `table+cursor*2` | **Confirmed** | `lea esi,[esi+eax*2]` |
| Copy `nWords*2` bytes (movsd+movsb) | **Confirmed** | `shr ecx,2` / `rep movsd` / `and 3` / `rep movsb` |
| `cursor += 1` (not += nWords) | **Confirmed** | `lea ecx,[eax+1]` |
| EAX = old cursor return | **Confirmed** | `mov eax,[edx+0xC]` before store; caller `mov [edi+0x3C],eax` |
| Decompiler `void` wrong | **Confirmed** | return-type warning + call site |
| `this` = RNG singleton | **Confirmed** | both sites: getter → `mov ecx,eax` → call |
| Callers exactly 2 | **Confirmed** | `get_function_callers` |
| nWords literal **600** at skill sites | **Confirmed** | `push 0x258` |
| Product C++ name | **Inferred** | no string/RTTI |

---

## 4. Control flow vs sibling

| Stage | This unit | `Rng_CloneSeededTable` (`0x0058ab60`) |
|---|---|---|
| Alloc | none (caller buf) | `new[](0x4B0)` |
| Force seed | no | `cursor = seedIndex` |
| Window size | **param** `nWords` | fixed **600** |
| Wrap / copy / ++ | same algorithm | same algorithm (inlined) |
| Return | old cursor | heap pointer |

ApplyStatusEffectLocal uses return as **`lDiceSeed`** when `world+0x7e != 0` (sim re-roll). `FUN_0061fdf0` discards return; buffer later reused for TFID list (window payload not consumed there).

---

## 5. Gaps (acceptable)

1. Product / PDB name of RNG host method.
2. Whether ApplyStatusEffectLocal stack buffer is ever read after the call (only seed store sealed).
3. Runtime / bit-exact / differential (Terminal false; no Launcher).

**Verdict:** **accept-with-gaps** under `_Inferred` name.

---

## Checklist

| Check | Result |
|---|---|
| Live decompile ≡ raw CF | **Pass** |
| ABI / epilogue sealed | **Pass** |
| Return value sealed | **Pass** |
| Callers sealed | **Pass** |
| Clean uses meaningful names (not iVar paste) | **Pass** |
| Verdict | **accept-with-gaps** |
