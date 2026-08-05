# Review A (reconstruction fidelity): `aa_0051e390` CVOGHBOKToCastAgain_OnStart

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051e390` |
| **VA** | `0x0051e390` |
| **Canonical name** | `CVOGHBOKToCastAgain_OnStart` |
| **Review date** | `2026-07-29` (dual residual seal; prior 2026-07-23) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0051e390_CVOGHBOKToCastAgain_OnStart.md` |
| **System** | `skills-abilities` |
| **Verdict** | **accept-with-gaps** |
| **Scratch** | `reviews/a_0051e390.md` |

---

## 1. Purpose

Type-8 cast-again HB **vtable OnStart** (activate): if owner object at **`HB+0x18`** non-null, set skill casting flag on **`HB+0x24`** to **1**; always **`CVOGHBBase_StampLastFireTime`** (`HB+0x14 ← g_dwClientTickMs`). Pairs with ctor duration and OnEnd clear.

```
if HB+0x18 != 0:
  Skill_SetIsCastingFlag(skill@HB+0x24, 1)  // byte +0x628; true → +0x170=0.f, +0x178=tick
// always (tail):
StampLastFireTime(HB)  // HB+0x14 = g_dwClientTickMs
```

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0051e390_CVOGHBOKToCastAgain_OnStart.md` |
| Annotated | `raw/aa_0051e390_CVOGHBOKToCastAgain_OnStart.annotated.md` |
| Clean | `reconstructed-exact/CVOGHBOKToCastAgain_OnStart.cpp` |
| Function record | `functions/aa_0051e390_CVOGHBOKToCastAgain_OnStart.md` |
| Ghidra re-decompile | `0x0051e390` (2026-07-29) |
| Bytes | `read_memory` OnStart `0x0051e390`, SetIsCasting `0x005502d0`, Stamp `0x00508270`, vtbl `0x009ce1c4` |
| Sibling dual residual | ctor `aa_0051e240` (owner vs skill attach) |
| Residual scratch | `reviews/a_0051e390.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| ECX = `pHeartbeat`; **no stack formals** | **High** | `mov esi,ecx`; no RET imm |
| Gate on **owner `HB+0x18`** | **High** | `cmp [esi+0x18],0` |
| **`+0x18` = owner entity**, not skill | **High** | AttachOwner(owner) sealed on ctor residual |
| Skill target **`HB+0x24`** | **High** | `mov ecx,[esi+0x24]` |
| `Skill_SetIsCastingFlag` **`__thiscall` + char + `RET 4`** | **High** | callee `C2 04 00` |
| Flag **byte** @ skill **`+0x628` = 1** | **High** | `mov [ecx+0x628],al` + `push 1` |
| True path: `+0x170` **float0** (`movss`), `+0x178` = tick | **High** | callee bytes |
| Stamp **always** after gate | **High** | je only skips flag block |
| Stamp = **`HB+0x14 ← g_dwClientTickMs`** | **High** | StampLastFireTime body |
| Tail-call to stamp | **High** | `jmp 0x00508270` |
| Vtbl OnStart @ `0x009ce1c8` | **High** | `read_memory` dword |
| `unaff_SI` third arg | **Falsified** | ESI = saved this |
| Plate “ResetStartTick” | **Misnomer** | real callee StampLastFireTime |
| Product English for flag/tick fields | **Open** | numeric sealed; sibling flag dual accept |
| Runtime / bit-exact | **Open** | matrix policy |

---

## 4. Control flow: clean ≡ raw ≡ asm

| Stage | Match |
|---|---|
| Owner gate + set flag + unconditional stamp | **Yes** |
| No invented duration / map / net | **Yes** |
| No third arg on flag call | **Yes** (clean 2026-07-29) |

---

## 5. Asm-sealed signature

```c
void __fastcall CVOGHBOKToCastAgain_OnStart(void* pHeartbeat /* ECX */);
// internal: if (*(pHeartbeat+0x18)) Skill_SetIsCastingFlag(*(pHeartbeat+0x24), 1);
// tail: CVOGHBBase_StampLastFireTime(pHeartbeat);
```

Callee as used:

```c
void __thiscall Skill_SetIsCastingFlag(void* thisSkill /* ECX */, char bIsCasting /* stack */);
// RET 4; thisSkill+0x628 = bIsCasting (byte)
```

---

## 6. Gaps / open

1. Product / PDB English for skill `+0x628` / `+0x170` / `+0x178` (CF sealed; `aa_005502d0` accepted).
2. Whether any path constructs HB without owner at `+0x18` (ctor well-formed path always attaches owner).
3. Runtime / bit-exact / image diff.

**Verdict:** **accept-with-gaps**
