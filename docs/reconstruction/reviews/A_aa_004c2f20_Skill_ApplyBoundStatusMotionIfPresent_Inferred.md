# Review A (reconstruction fidelity): `aa_004c2f20` Skill_ApplyBoundStatusMotionIfPresent_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c2f20` |
| **VA** | `0x004c2f20`–`0x004c2f31` |
| **Canonical name** | `Skill_ApplyBoundStatusMotionIfPresent_Inferred` |
| **Ghidra symbol** | `FUN_004c2f20` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction fidelity |
| **Counterpart** | `reviews/B_aa_004c2f20_Skill_ApplyBoundStatusMotionIfPresent_Inferred.md` |
| **System** | `skills-abilities` |
| **Verdict** | **accept-with-gaps** — ABI + gate + tail JMP sealed; product type names open |

**Tools:** Ghidra `decompile_function` + `read_memory` + `analyze_function_complete` / `get_xrefs_to`. No `disassemble_bytes`. Own VA only. No ledgers. No Launcher.

---

## 1. Purpose

Leaf-scale **optional status/motion apply** helper on the skill apply-effects path:

1. `this` = object returned by **caster vtbl+0x214(skillId)**.
2. If **`this+0x1FC == 0`** → return (`RET 4`).
3. Else **tail JMP** to **`FUN_005d0d60`** with `ECX = *(this+0x1FC)` and the same stack **skillId**.

Does not itself walk tables, apply handbrake, or fire combat events — that lives in the tail callee (sibling residual).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004c2f20_FUN_004c2f20.md` (+ 2026-07-29 append) |
| Annotated | `docs/reconstruction/raw/aa_004c2f20_FUN_004c2f20.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Skill_ApplyBoundStatusMotionIfPresent_Inferred.cpp` |
| Alias clean | `docs/reconstruction/reconstructed-exact/FUN_004c2f20.cpp` |
| Function record | `docs/reconstruction/functions/aa_004c2f20_Skill_ApplyBoundStatusMotionIfPresent_Inferred.md` |
| Live decompile | Ghidra `0x004c2f20` — CF ≡ raw; ABI incomplete in decomp |
| Live bytes | `read_memory` len 32 @ entry |
| Caller context (not owned) | `Skill_ApplyEffectsOnTarget_Inferred` site bytes @ `0x00553920` |
| Tail callee context (not owned) | `FUN_005d0d60` decompile (role only) |

---

## 3. Sealed residuals

### 3.1 ABI — **SEALED**

| Fact | Evidence |
|---|---|
| Convention | **`__thiscall`**: bound object in **ECX** |
| Stack args | **1** dword: **skillId** |
| Epilogue | **`RET 4`** (`C2 04 00`) when gate fails; on success **JMP** (callee returns) |
| Return | void (no EAX product used at sole call site) |
| Body | `0x004c2f20`–`0x004c2f31` (18 bytes); `CC` pad after |

```c
void __thiscall Skill_ApplyBoundStatusMotionIfPresent_Inferred(
    void *boundObj, int skillId);
```

### 3.2 Machine body — **SEALED**

`read_memory` @ `0x004c2f20` length 32:

```
8b 89 fc 01 00 00    mov  ecx, [ecx+0x1fc]
85 c9                test ecx, ecx
74 05                jz   +5
e9 31 de 10 00       jmp  0x005d0d60
c2 04 00             ret  4
cc…                  pad
```

JMP displacement: `0x004c2f2c + 5 + 0x0010de31 = 0x005d0d60` ✓.

### 3.3 Control flow — **SEALED**

| Stage | Match raw / clean / bytes |
|---|---|
| Load +0x1FC into ECX | Yes |
| Null → ret 4 | Yes |
| Non-null → tail to FUN_005d0d60 | Yes (bytes = JMP; decomp = CALL cosmetic) |
| No other stores / callees | Yes |

### 3.4 Call graph — **SEALED**

| Direction | Target | Notes |
|---|---|---|
| Caller | `Skill_ApplyEffectsOnTarget_Inferred` @ `0x00553936` | Only xref |
| Callee | `FUN_005d0d60` | Tail; skillId match in table |

Caller contract (context): after combat event **4**, if `caster.vtbl+0x214()` non-null, push `skill+0x5FC`, call `vtbl+0x214(skillId)`, `ECX=EAX`, call this unit.

### 3.5 Three-rep — **SEALED**

| Rep | Status |
|---|---|
| Raw 2026-07-23 | ≡ live decompile CF |
| Live decompile 2026-07-29 | ≡ raw CF |
| Machine bytes | ≡ CF; **corrects** ABI / tail form |

---

## 4. Gaps (acceptable)

1. Product C++ name — keep `_Inferred` (no RTTI/string on this VA).
2. Exact type of `boundObj` and of `*(+0x1FC)` (status-motion controller / HB host).
3. Full sealed dual of `FUN_005d0d60` (out of ownership).
4. vtbl+0x214 stack-clean convention interaction with single push at call site.
5. Runtime / bit-exact / image diff.

**Verdict:** **accept-with-gaps** — dual seals machine ABI + gate + sole skill apply-effects integration.

---

## Checklist

| Check | Result |
|---|---|
| Exists as function | **Pass** |
| Raw + annotated + clean + record | **Pass** |
| Dual A/B present | **Pass** |
| No disassemble_bytes | **Pass** |
| Own VA only | **Pass** |
